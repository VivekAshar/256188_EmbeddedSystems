# Essentials of Embedded Systems : Seat-heating application for cars

## Activity 1 

Controlling LED using a push-button and a switch

## Activity 2

Taking the analog output from an analog temperature sensor and performing ADC to store the 10-bit binary level in ADCH-ADCL registers when the push-button and the switch, are both on.

## Activity 3

Generating a PWM wave based on the output(analog-ADC-digital) of the temperature sensor and feding it to the heater(CRO).


## Activity 4

Sending the temperature data recorded by the MCU, to another MCU (car's dashboard) via USART, for display purpose.

### Simulation on SIMULIDE

![SIMULATION](https://github.com/VivekAshar/256188_EmbeddedSystems/blob/main/simulation/Activity%204/ACT%204%20SIMULATION.PNG)

### In Action

|ON|OFF STATE 1|OFFSTATE 2|
|:--:|:--:|:--:|
|![ON](https://github.com/VivekAshar/256188_EmbeddedSystems/blob/main/simulation/Activity%204/ACT%204%20ON%20STATE.PNG)|![OFF STATE 1](https://github.com/VivekAshar/256188_EmbeddedSystems/blob/main/simulation/Activity%204/ACT%204%20OFF%20STATE%201.PNG)|![OFF STATE 2](https://github.com/VivekAshar/256188_EmbeddedSystems/blob/main/simulation/Activity%204/ACT%204%20OFF%20STATE%202.PNG)|



|20ºC|25ºC|29ºC|33ºC|
|:--:|:--:|:--:|:--:|
|![20ºC](https://github.com/VivekAshar/256188_EmbeddedSystems/blob/main/simulation/Activity%204/Different%20PWMs/20%20degree%20C.PNG)|![25ºC](https://github.com/VivekAshar/256188_EmbeddedSystems/blob/main/simulation/Activity%204/Different%20PWMs/25%20degree%20C.PNG)|![29ºC](https://github.com/VivekAshar/256188_EmbeddedSystems/blob/main/simulation/Activity%204/Different%20PWMs/29%20degree%20C.PNG)|![33ºC](https://github.com/VivekAshar/256188_EmbeddedSystems/blob/main/simulation/Activity%204/Different%20PWMs/33%20degree%20C.PNG)|


#### CI and Code Quality

|Build|Cppcheck|
|:--:|:--:|
|[![Compile-Linux](https://github.com/VivekAshar/256188_EmbeddedSystems/actions/workflows/compile.yml/badge.svg)](https://github.com/VivekAshar/256188_EmbeddedSystems/actions/workflows/compile.yml)|[![Cppcheck](https://github.com/VivekAshar/256188_EmbeddedSystems/actions/workflows/CodeQuality.yml/badge.svg)](https://github.com/VivekAshar/256188_EmbeddedSystems/actions/workflows/CodeQuality.yml)|

## Wiki DocumentatioCompile-Linuxn
* System [SETUP](https://github.com/VivekAshar/256188_EmbeddedSystems/wiki)
