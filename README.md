# Attiny85_neoPixel_led_termometer
Arduino IDE project aimed to control Led stripe with WS2812b driver.
For the project was used neoPixel library.

## Brightnes sensor
Leds change color base on photoresistor 10k ohm.
There are 3 colour of leds:
* green
* white
* white-orange

## Termometer
Integral part of project is termometer DS18B20. Controller gets temperature and base on color scale indicate temperature.
Last two Leds change color depends on temperature.
