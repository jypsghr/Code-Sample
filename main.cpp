//
// main.cpp
// Sean Otis Wells-Rutherford
//

#include <iostream>
#include "firfilter.h"
#include "coeff.h"

#define TEST_SIGNAL_LEN 100

int main() {
    
    using namespace FILT;
	
	// generate test signal
    int testSignal[TEST_SIGNAL_LEN];
	
    testSignal[0] = 1;    
    for (int i = 1; i < TEST_SIGNAL_LEN; i++) {
        testSignal[i] = 0; // 0 for impulse response output, 1 for (pseudo) step response output
    }
    
    // construct filter object
	FIRFilter fir(coeffs, FILTER_LEN);
    
    // perform convolution
    int outputLength = 0;
	int* output = fir.convolution(testSignal, TEST_SIGNAL_LEN, outputLength);
    
    // print output
    for (int i = 0; i < outputLength; i++) {
        std::cout << output[i] << std::endl;
    }
	
	delete[] output;
	
	std::cout << "Press enter to exit..." << std::endl;
	std::cin.get();
    
    return 0;
}