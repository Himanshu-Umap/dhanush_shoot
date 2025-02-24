#include <stdio.h>
#include "pinMap.hpp"

#include <freertos/FreeRTOS.h>
#include "freertos/task.h"

#include "qmd.hpp"
#include "urosHandler.hpp"
#include "sub.hpp"


int pwmPins[] = {PWM_L, PWM_R};
int dirPins[] = {DIR_L, DIR_R};
int count = 2;

int max_PWM = 19990;
int min_PWM = 0;

//const char* node_name[] = {"throwingMechanism"};
qmd* handler = new qmd(pwmPins, dirPins, count);

// doubt node_name passed should be pointer
uros_master_node* node;

extern "C" void app_main(void)
{
    node = new uros_master_node("node_name");

    handler->setRange(max_PWM, min_PWM);

    node->add_urosElement({
        new sub(handler)
    });

    //handler->update();
}