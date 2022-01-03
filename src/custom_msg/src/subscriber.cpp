#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <custom_msg/msg/num.hpp>

using std::placeholders::_1;

class Subscriber : public rclcpp::Node{
    public:
        Subscriber() : Node("subscriber"){
            subscritption_ = this->create_subscription<custom_msg::msg::Num>(
                "topic", 10, std::bind(&Subscriber::topic_callback, this, _1)
            );
        }
    private:
        void topic_callback(const custom_msg::msg::Num::SharedPtr msg) const{
            RCLCPP_INFO(this->get_logger(), "Subscribed: %ld", msg->num);
        }
        rclcpp::Subscription<custom_msg::msg::Num>::SharedPtr subscritption_;
};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Subscriber>());
    rclcpp::shutdown();
    return 0;
}