/*
 * Author: Ivan De Cesaris <ivan.de.cesaris@intel.com>
 * Copyright (c) 2015 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "mraa.hpp"

#include <iostream>
#include <unistd.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string>
#include "DriveCar.hpp"
#include "PinConsts.h"

/*
 * Digital output example
 *
 * Demonstrate how to write a digital value to an output pin using the MRAA
 * library.
 * A suitable part to use this example with in the Grove Starter Kit is the LED.
 *
 * - digital out: output connected to digital pin 8 (Grove Base Shield Port D8)
 *
 * Additional linker flags: none
 */

std::string data;

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{ //callback must have this declaration
    //buf is a pointer to the data that curl has for us
    //size*nmemb is the size of the buffer
	data = "";
    for (size_t c = 0; c<size*nmemb; c++)
    {
        data.push_back(buf[c]);
    }
    return size*nmemb; //tell curl how many bytes we handled
}

int main()
{

	DriveCar car = DriveCar(GP48,GP49,GP14,GP15);


	CURL* curl;
	curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
	curl = curl_easy_init();


	curl_easy_setopt(curl, CURLOPT_URL, "http://www.carltonjester.com/edison/controlRCCar.txt");
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress

	/*
	0=stop
	1=forward
	2=reverse
	3=right
	4=left
	5=forward right
	6=forward left
	7=reverse right
	8=reverse left
	*/
	// loop forever toggling the digital output every second
	for(;;) {

		curl_easy_perform(curl);
		int num = atoi(data.c_str());
		switch (num) {
			case 0:
				car.stop();
				break;
			case 1:
				car.forward();
				break;
			case 2:
				car.reverse();
				break;
			case 3:
				car.right();
				break;
			case 4:
				car.left();
				break;
			case 5:
				car.rightForward();
				break;
			case 6:
				car.leftForward();
				break;
			case 7:
				car.rightReverse();
				break;
			case 8:
				car.leftReverse();
				break;
		}
	}

	return MRAA_SUCCESS;
}
