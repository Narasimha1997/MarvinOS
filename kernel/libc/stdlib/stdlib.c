#include "stdlib.h"
#include "timer.h"


void sleep(uint32_t seconds) {
    timer_wait(seconds);
}