//
// firfilter.cpp
// Sean Otis Wells-Rutherford
//

#include <iostream>
#include "firfilter.h"

namespace FILT {
	
	FIRFilter::FIRFilter(int* coefficients, int length)
	: _coefficients(coefficients), _length(length) {}
	
	int* FIRFilter::convolution(const int* input, const int& in_len, int& out_len) const
    {
        out_len = in_len + _length - 1;
        int* output = new int[out_len];
        
		int n, j, k;
        for (n = 0; n < out_len; n++) {
            int sum = 0;
            
            // multiply and accumulate
            for (k = 0; k <= n; k++) {
                j = n - k;
                
                if (j >= 0 && j < in_len && k < _length) {
                    sum += _coefficients[k] * input[j];
                }
            }
			
            output[n] = sum;
        }
		
        return output;
    }
	
}