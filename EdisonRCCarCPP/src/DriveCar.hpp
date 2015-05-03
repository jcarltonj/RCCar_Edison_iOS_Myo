/*
 * DriveCar.hpp
 *
 *  Created on: Apr 19, 2015
 *      Author: carltonjester
 */
#include "mraa.hpp"

#ifndef DRIVECAR_HPP_
#define DRIVECAR_HPP_

class DriveCar {
public:
	DriveCar(int fwdPin, int revPin, int rPin, int lPin);
	virtual ~DriveCar();
	void forward();
	void reverse();
	void right();
	void left();
	void rightForward();
	void leftForward();
	void rightReverse();
	void leftReverse();
	void stop();
private:
	mraa::Gpio* forwardPin;
	mraa::Gpio* reversePin;
	mraa::Gpio* rightPin;
	mraa::Gpio* leftPin;

};

#endif /* DRIVECAR_HPP_ */
