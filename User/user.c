#include <stdint.h>
#include "main.h"
#include "user.h"

void delay_us(uint16_t us){
    uint16_t start_cnt = __HAL_TIM_GET_COUNTER(&htim2);
    uint16_t elapsed_cnt = 0;
    while(elapsed_cnt < us){
        uint16_t current_cnt = __HAL_TIM_GET_COUNTER(&htim2);
        if(current_cnt >= start_cnt){
            elapsed_cnt = current_cnt - start_cnt;
        } else {
            elapsed_cnt = (65535 - start_cnt) + current_cnt + 1;
        }
    }
}