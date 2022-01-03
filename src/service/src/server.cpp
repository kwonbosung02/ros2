#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/srv/add_two_ints.hpp>
/*
int64 a
int64 b
---
int64 sum
*/
#include <memory>

void add(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
        std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response){
    response-> sum = request->a + request->b;
    
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming req\n a : %ld, b : %ld ", request->a, request->b);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Response : %ld", (long int)response->sum);
}

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add two ints server");

    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service = 
        node-> create_service<example_interfaces::srv::AddTwoInts>("server", &add);

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "listen.");

    rclcpp::spin(node);
    rclcpp::shutdown();
    
}