/*
 * Copyright (c) 2011, Willow Garage, Inc.
 * Copyright (c) 2017, Open Source Robotics Foundation, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "std_msgs/msg/string.hpp"

#include "rclcpp/rclcpp.hpp"
#include "diagnostic_updater/diagnostic_updater.hpp"

class Chatter : public rclcpp::Node
{
public:
  Chatter();
  diagnostic_updater::Updater updater_;
};

Chatter::Chatter()
    : Node("chatter"),
      updater_(this)
{
  // rclcpp::Rate loop_rate(1);
  // size_t count_ = 1;
  // std::unique_ptr<std_msgs::msg::String> msg_;
  // rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  // rclcpp::QoS qos(rclcpp::KeepLast(7));
  // pub_ = this->create_publisher<std_msgs::msg::String>("chatter", qos);

  // while (rclcpp::ok())
  // {
  //   msg_ = std::make_unique<std_msgs::msg::String>();
  //   msg_->data = "Hello World: " + std::to_string(count_++);
  //   RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg_->data.c_str());
  //   pub_->publish(std::move(msg_));

  //   rclcpp::spin_some(this->get_node_base_interface());
  //   loop_rate.sleep();
  // }
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto chatter_node = std::make_shared<Chatter>();
  auto executor = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
  executor->add_node(chatter_node);
  executor->spin();
  rclcpp::shutdown();

  // rclcpp::spin(std::make_shared<Chatter>());
  // rclcpp::shutdown();
}
