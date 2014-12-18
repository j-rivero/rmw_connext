
#ifndef __ros_middleware_interface__get_service_type_support_handle__h__
#define __ros_middleware_interface__get_service_type_support_handle__h__

#include "rosidl_typesupport_connext_cpp/ServiceTypeSupport.h"

namespace ros_middleware_interface
{
template<typename T>
const rosidl_generator_cpp::ServiceTypeSupportHandle& get_service_type_support_handle()
{
  return ros_middleware_connext_cpp::get_service_type_support_handle<T>();
}

}  // namespace ros_middleware_interface

#endif  // __ros_middleware_interface__get_service_type_support_handle__h__
