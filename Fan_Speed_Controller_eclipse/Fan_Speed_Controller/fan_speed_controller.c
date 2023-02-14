/*
 ============================================================================
 Name        : fan_speed_controller.c
 Author      : Esraa Mohamed
 Description : Fan Controlled System by ATmega32
 ============================================================================
 */

#include <avr/io.h>
#include "std_types.h"
#include"gpio.h"
#include"lcd.h"
#include"pwm.h"
#include"adc.h"
#include"dc_motor.h"
#include"lm35_sensor.h"

void Display_Temp(uint8 Temperature){
	if(Temperature <10){
		LCD_intgerToString(Temperature);
		LCD_displayString("  ");
	}
	else if((Temperature >=10)&& (Temperature <100) ){
		LCD_intgerToString(Temperature);
		LCD_displayString(" ");
	}
	else if(Temperature >=100 )
		LCD_intgerToString(Temperature);
	LCD_displayCharacter(0xDF);
}

int main(void){
	/* Create structure to initialize ADC driver */
	ADC_ConfigType ADC_Config ={INTERNAL ,FCPU_8};
	uint8 temp ;          /* variable to store temperature value */
	/* Initialize DC Motor & ADC & LCD drivers */
	ADC_init(& ADC_Config);
	LCD_init();
	DcMotor_Init();

	LCD_displayStringRowColumn(0,4,"FAN is");
	LCD_displayStringRowColumn(1,4,"Temp =     C");
	for(;;){

		temp= LM35_getTemperature();  /* Get Temp. value from Sensor and convert it by ADC*/
		/*
		 * Controlled Fan speed and state due to Temp. value
		 * Showing Fan state (ON/OFF) & Temperature value on LCD
		 */
		if(temp < 30){
			DcMotor_Rotate(stop,0);
			LCD_displayStringRowColumn(0,11,"OFF");

		}else if((temp>= 30) && (temp < 60)){
			DcMotor_Rotate(CW,25);
			LCD_displayStringRowColumn(0,11,"ON ");

		}else if((temp>= 60) && (temp < 90)){
			DcMotor_Rotate(CW,50);
			LCD_displayStringRowColumn(0,11,"ON ");

		}else if((temp>= 90) && (temp < 120)){
			DcMotor_Rotate(CW,75);
			LCD_displayStringRowColumn(0,11,"ON ");

		}else if(temp>= 120){
			DcMotor_Rotate(CW,100);
			LCD_displayStringRowColumn(0,11,"ON ");

		}

		LCD_moveCursor(1,11);
		Display_Temp(temp);
	}
}
