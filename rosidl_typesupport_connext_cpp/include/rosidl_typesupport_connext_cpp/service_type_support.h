// Copyright 2014-2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ROSIDL_TYPESUPPORT_CONNEXT_CPP_ROSIDL_TYPESUPPORT_CONNEXT_CPP_SERVICE_TYPE_SUPPORT_H_
#define ROSIDL_TYPESUPPORT_CONNEXT_CPP_ROSIDL_TYPESUPPORT_CONNEXT_CPP_SERVICE_TYPE_SUPPORT_H_

#include <stdint.h>

#include "rosidl_generator_c/service_type_support.h"

typedef struct service_type_support_callbacks_t
{
  const char * package_name;
  const char * service_name;
  // Function to create a requester
  void * (*create_requester)(
    void * participant, const char * service_name,
    const void * datareader_qos, const void * datawriter_qos,
    void ** reader);
  // Function to create a replier
  void * (*create_replier)(
    void * participant, const char * service_name,
    const void * datareader_qos, const void * datawriter_qos,
    void ** reader);
  // Function to send ROS requests
  int64_t (* send_request)(void * requester, const void * ros_request);
  // Function to read a ROS request from the wire
  bool (* take_request)(void * replier, void * ros_request_header, void * ros_request);
  // Function to send ROS responses
  bool (* send_response)(
    void * replier, const void * ros_request_header,
    const void * ros_response);
  // Function to read a ROS response from the wire
  bool (* take_response)(void * requester, void * ros_request_header, void * ros_response);
} service_type_support_callbacks_t;

#endif  /* ROSIDL_TYPESUPPORT_CONNEXT_CPP_ROSIDL_TYPESUPPORT_CONNEXT_CPP_SERVICE_TYPE_SUPPORT_H_ */
