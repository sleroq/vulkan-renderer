#include "inexor/vulkan-renderer/wrapper/semaphore.hpp"

#include "inexor/vulkan-renderer/exception.hpp"
#include "inexor/vulkan-renderer/wrapper/device.hpp"
#include "inexor/vulkan-renderer/wrapper/make_info.hpp"

#include <spdlog/spdlog.h>

#include <cassert>
#include <utility>

namespace inexor::vulkan_renderer::wrapper {

Semaphore::Semaphore(const Device &device, const std::string &name) : m_device(device), m_name(name) {
    assert(device.device());
    assert(!name.empty());
    device.create_semaphore(make_info<VkSemaphoreCreateInfo>(), &m_semaphore, m_name);
}

Semaphore::Semaphore(Semaphore &&other) noexcept : m_device(other.m_device) {
    m_semaphore = std::exchange(other.m_semaphore, nullptr);
    m_name = std::move(other.m_name);
}

Semaphore::~Semaphore() {
    vkDestroySemaphore(m_device.device(), m_semaphore, nullptr);
}

} // namespace inexor::vulkan_renderer::wrapper
