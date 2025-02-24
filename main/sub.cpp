#include "sub.hpp"

sub* sub::sub_ptr = 0;

sub::sub(qmd* qmd_ptr) : handler(qmd_ptr){
    sub_ptr = this;
};

void sub::init(){
    rclc_subscription_init_default(&subscription, node, type_support, topic_name);
    rclc_executor_add_subscription(&executor, &subscription, &msg, &subscription_callback, ON_NEW_DATA);
};

void sub::subscription_callback(const void * msgIn){
    const std_msgs__msg__Int32 *msg = (const std_msgs__msg__Int32 *)msgIn;
    // memcpy(def->handler->speeds, &msgIn, 2 * sizeof(float));

    //mapping 


    sub_ptr->handler->speeds[0] = msg->data;
    sub_ptr->handler->speeds[1] = msg->data;
    //handler->speeds[0] = 0.5f;

    sub_ptr->handler->update();
};