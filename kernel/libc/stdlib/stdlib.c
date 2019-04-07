#include "stdlib.h"
#include "timer.h"
#include<memory/kmemory.h>


void sleep(uint32_t seconds) {
    timer_wait(seconds);
}

