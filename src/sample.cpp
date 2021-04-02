#include "std_msgs/msg/string.hpp"

#include "rclcpp/rclcpp.hpp"
#include "diagnostic_updater/diagnostic_updater.hpp"

class Chatter : public rclcpp::Node
{
public:
  Chatter();
  rclcpp::TimerBase::SharedPtr timer_;
  std::mutex lock_;

  void update();
};

Chatter::Chatter()
    : Node("chatter")
{
  timer_ = rclcpp::create_timer(
      this->get_node_base_interface(),
      this->get_node_timers_interface(),
      this->get_clock(),
      rclcpp::Duration::from_seconds(1.0),
      std::bind(&Chatter::update, this));

}

void Chatter::update()
{
  if (rclcpp::ok())
  {
    std::unique_lock<std::mutex> lock(lock_);
    // some process
    for (int i = 0; i < 10; ++i) {
      int j = 0;
      j ++;
    }
    RCLCPP_INFO(this->get_logger(),"update is called");
  }
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto chatter_node = std::make_shared<Chatter>();
  auto executor = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
  executor->add_node(chatter_node);
  executor->spin();
  rclcpp::shutdown();
}
