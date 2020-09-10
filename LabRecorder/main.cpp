#include "lsl_cpp.h"
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace lsl;

/**
 * This is an example of how a simple data stream can be offered on the network. 
 * Here, the stream is named SimpleStream, has content-type EEG, and 128 channels.
 * The transmitted samples contain random numbers (and the sampling rate is irregular 
 * and effectively bounded by the speed at which the program can push out samples).
 */

int main(int argc, char* argv[]) {

	// make a new stream_info (128ch) and open an outlet with it
	stream_info info("XSens","MoCap",4);
	stream_outlet outlet(info);

	// send data forever
	float sample[128];
	while(true) {
		// generate random data
		for (int c=0;c<128;c++)
            //TODO: MAKE THIS SEND DATA FROM XSENS
			sample[c] = (rand()%1500)/500.0-1.5;
		// send it
		outlet.push_sample(sample);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	return 0;
}