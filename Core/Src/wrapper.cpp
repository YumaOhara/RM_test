#include <main.h>

//PA8 TIM1
extern TIM_HandleTypeDef htim1;

volatile int32_t duty = 500;


void main_cpp(){
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

	//パルス幅maxにする
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 999);
	//キャリブレーションを待つ（３秒以内）
	HAL_Delay(1000);
	//パルス幅minにする
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 500);
	//なんとなく待つ
	HAL_Delay(1000);

	while(1){

		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, duty);

	}
}
