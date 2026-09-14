/* Thunk: SDL's own gpu/vulkan/SDL_gpu_vulkan.c reaches this exact path via
 * a relative #include ("../../video/khronos/vulkan/vulkan.h"), so it can't
 * simply be dropped in favor of libvulkan-headers's own <vulkan/vulkan.h>
 * search path. Redirect there instead of vendoring Khronos's own header.
 */
#include <vulkan/vulkan.h>
