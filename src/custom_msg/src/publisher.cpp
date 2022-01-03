#include <chrono>
#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <custom_msg/msg/num.hpp>

using namespace std::chrono_literals;

class Publisher : public rclcpp::Node{
    public:
        Publisher() : Node("publisher"), count_(0){
            publisher_ = this->create_publisher<custom_msg::msg::Num>("topic", 10);
            timer_ = this->create_wall_timer(500ms, std::bind(&Publisher::timer_callback, this));
        }
    private:
        void timer_callback(){
            auto message = custom_msg::msg::Num();
            message.num = this->count_++;
            RCLCPP_INFO(this->get_logger(), "Publishing : %d", message.num);
            publisher_->publish(message);
        }
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<custom_msg::msg::Num>::SharedPtr publisher_;
        size_t count_;

};
int main(int argc, char **argv){

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Publisher>());
    rclcpp::shutdown();
    return 0;
}