/*
 *      Project 03-pwm
 *      Using a potentiometer connected to the A/D converter, changes LED brightness (PWM)
 *
 *      main.cpp
 */

#include <Arduino.h>

/*
 *     Definiciones
 */

/*
 *  Definitions in platformio.ini
 *  LED1        GPIO for LED
 *  ANAIN       A/D converter GPIO
 *  SERIAL_BAUD Serial port baud rate
 */


// setting PWM properties
#define FREQ            500
#define LED_CHANNEL     0
#define RESOLUTION      12      //  Same as ADC pote resolution !!

/*
 *  Public functions
 */




void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    pinMode(2, OUTPUT);
    ledcSetup(LED_CHANNEL, FREQ, RESOLUTION);
    ledcAttachPin(LED1, LED_CHANNEL);    // attach the channel to the GPIO to be controlled
} 
void
loop(void)
{
    int sensorValue;

    sensorValue = 512;
    ledcWrite(LED_CHANNEL, sensorValue);
    digitalWrite(2, HIGH);
    delay(4000);
    sensorValue = 0;
    ledcWrite(LED_CHANNEL, sensorValue);
    digitalWrite(2, LOW);
    delay(5000);
}
