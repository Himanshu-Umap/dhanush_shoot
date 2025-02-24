#include "qmd.hpp"
#include "urosElement.hpp"

#include "std_msgs/msg/int32.h"


class sub : public urosElement{

public:
    const char * topic_name = "test_topic";
    const rosidl_message_type_support_t * type_support = ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32);
    static sub* sub_ptr;
    void init();
    sub(qmd* qmd_ptr);

    static void subscription_callback(const void* msgin);
    qmd* handler = 0;
private:
    rcl_subscription_t subscription;
    rclc_executor_t executor;
    std_msgs__msg__Int32 msg;
};