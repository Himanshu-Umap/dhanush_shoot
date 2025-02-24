#include <stdio.h>
#include "qmd.hpp"
#include "micro_ros_espidf_component"


int pwmPins[] = {12, 13};
int dirPins[] = {26, 25};

qmd* handler;

extern "C" void app_main(void)
{
    qmd = new qmd(2, pwmPins, dirPins);
}