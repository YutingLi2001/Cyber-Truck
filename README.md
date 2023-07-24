# Cyber Truck

<img width="584" alt="Cyber Truck" src="https://github.com/YutingLi2001/Cyber-Truck/assets/90287593/36ea6874-eaa9-4770-af2f-8f82c477593a">

## Overview
The project is an autonomous robot car driven by the STM32F103RB microcontroller board. The car is equipped with two infrared sensors that detect obstacles in the front-left and front-right. When an upcoming obstacle is detected, the car maneuvers itself to avoid the obstacle by turning in the opposite direction. If both ways are blocked, the car signals via a buzzer.

The robot car is a Front-Wheel-Drive (FWD) four-wheel car with its speed and direction determined by the front two wheels. All behaviors are programmed into the microcontroller, making the car entirely self-driven.

## Features

- **Autonomous Navigation:** The robot car is programmed to detect and avoid obstacles using infrared sensors, ensuring autonomous navigation in a variety of driving situations.
- **Start/Reset Button:** The microcontroller's reset button is also used as a start button, which allows the car to move after the code is loaded. The button can also reset the car in case of unexpected bugs.
- **User Customization:** Although the car operates autonomously, users can adjust the car's behaviors by modifying the codes, including its driving speed.

## Connections and Electrical Components
The detailed connections of I/O components and properties of all electrical components are explained in the diagrams and tables in the sections 1.4.1 and 1.4.2.

## Testing 
The robot car underwent extensive testing, including the battery holder, portable charger, motor, motor driver, infrared sensors (both digital and analog), and buzzer. Each component was tested individually before being integrated into the whole system.

## Project Evolution & Improvements
The project underwent several revisions during its development process, including switching to a portable charger instead of batteries, using a motor driver for precise control, and opting for the IR sensor's analog input over an ultrasonic sensor for obstacle detection. 

Future enhancements may include the implementation of PWM control for the motors to adjust the speed, and an improved algorithm for handling obstacles more effectively.

## Usage
After loading the code onto the microcontroller, press the reset button to initiate the car's movements. If an unexpected bug arises, press the reset button to restart the car.

## Disclaimer
This project was designed as a learning exercise and may not be suitable for real-world applications without additional safety features and extensive testing.

Please refer to the 'Documentations' & 'src' section for a complete understanding of the design decisions, testing, and improvements made throughout the course of this project.
