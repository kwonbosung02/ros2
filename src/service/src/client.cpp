#include <cstdlib>
#include <chrono>
#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/srv/add_two_ints.hpp>

using namespace std::chrono_literals;

int main(int argc, char **argv){
    rclcpp::init(argc, argv);

    if(argc != 3){
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "client X Y");
        return 1;
    }

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("client:");
}

