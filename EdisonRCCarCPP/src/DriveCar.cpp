/*
 * DriveCar.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: carltonjester
 */

#include "DriveCar.hpp"
#include <iostream>

DriveCar::DriveCar(int fwdPin, int revPin, int rPin, int lPin) {
	std::cout<<fwdPin<<revPin<<rPin<<lPin<<std::endl;
	forwardPin = new mraa::Gpio(fwdPin);
	forwardPin->dir(mraa::DIR_OUT);

	reversePin = new mraa::Gpio(revPin);
	reversePin->dir(mraa::DIR_OUT);

	rightPin = new mraa::Gpio(rPin);
	rightPin->dir(mraa::DIR_OUT);

	leftPin = new mraa::Gpio(lPin);
	leftPin->dir(mraa::DIR_OUT);
	stop();
}

DriveCar::~DriveCar() {
}

void DriveCar::stop() {
	//This is a coast stop
	forwardPin->write(1);
	reversePin->write(1);
	rightPin->write(1);
	leftPin->write(1);
	std::cout<<"Stop"<<std::endl;
}

void DriveCar::forward() {
	stop();
	forwardPin->write(0);
	std::cout<<"Forward"<<std::endl;
}

void DriveCar::reverse() {
	stop();
	reversePin->write(0);
	std::cout<<"Reverse"<<std::endl;
}

void DriveCar::right() {
	stop();
	rightPin->write(0);
	std::cout<<"Right"<<std::endl;
}

void DriveCar::left() {
	stop();
	leftPin->write(0);
	std::cout<<"Left"<<std::endl;
}

void DriveCar::rightForward() {
	stop();
	rightPin->write(0);
	forwardPin->write(0);
	std::cout<<"Right Forward"<<std::endl;
}

void DriveCar::leftForward() {
	stop();
	leftPin->write(0);
	forwardPin->write(0);
	std::cout<<"Left Forward"<<std::endl;
}

void DriveCar::rightReverse() {
	stop();
	rightPin->write(0);
	reversePin->write(0);
	std::cout<<"Right Reverse"<<std::endl;
}

void DriveCar::leftReverse() {
	stop();
	leftPin->write(0);
	reversePin->write(0);
	std::cout<<"Left Reverse"<<std::endl;
}
