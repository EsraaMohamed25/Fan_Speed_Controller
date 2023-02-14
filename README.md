# Fan_Speed_Controller
## Desciption :
#### A temperature-controlled fan is automatically turned ON or OFF and regulates the its speed according to the temperature.
## Drivers:
> GPIO, ADC, LCD, PWM, Temperature Sensor and DC-Motor.
## Microcontroller:
> ATmega32

## Fan Speed Controller System Sequence when switch the power supply:
1. The analog value of temperature is given by the temperature sensor (LM35) is converted to the digital value by the microcontroller then Microcontroller starts reading the temperature of the surroundings through it.
2. Read the value from ADC register and assign value to port which has LCD interfaced and display the Temperature on the LCD screen and the state of the fan. 
3. The microcontroller will drive the fan on a particular speed as specified by the duty cycle of the PWM pulse like that:
- If the temperature is less than 30C turn off the fan.
- If the temperature is greater than or equal 30C turn on the fan with 25% of its 
maximum speed.
- If the temperature is greater than or equal 60C turn on the fan with 50% of its 
maximum speed.
- If the temperature is greater than or equal 90C turn on the fan with 75% of its 
maximum speed.
- If the temperature is greater than or equal 120C turn on the fan with 100% of its 
maximum speed.

#### Aim of the proect :
Electronic devices produce heat which should be reduced to protect the device. There are many ways to reduce this heat one of them is to switch ON the fan immediately. This project describes a circuit that automatically switches the fan when it detects the temperature inside the device greater than specific value. This project also deals with showing the current temperature when installed inside a room and control the speed of fan according to user’s comfort at that temperature eliminating human efforts.
