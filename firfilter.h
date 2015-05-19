//
// firfilter.h
// Sean Otis Wells-Rutherford
//

#pragma once

namespace FILT {
	
    class FIRFilter
    {
		
    public:
		FIRFilter(int* coefficients, int length);
        int* convolution(const int* input, const int& in_len, int& out_len) const;
		
        inline int  getLength() const { return _length; } 
        inline int* getCoefficients() const { return _coefficients; } 
		
    private:
        int _length;
        int* _coefficients;
		
    };
	
}