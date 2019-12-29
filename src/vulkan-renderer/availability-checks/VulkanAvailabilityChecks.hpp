#pragma once

#include <string>
#include <vector>

#include <vulkan/vulkan.h>

#include "../error-handling/VulkanErrorHandling.hpp"


namespace inexor {
namespace vulkan_renderer {

	// 
	class VulkanAvailabilityChecks
	{
		public:

			VulkanAvailabilityChecks();

			~VulkanAvailabilityChecks();

		protected:
		
			// 
			bool CheckInstanceExtensionAvailability(const std::string& instance_extension_name);

			// 
			bool CheckInstanceLayerAvailability(const std::string& instance_layer_name);

	};

};
};
