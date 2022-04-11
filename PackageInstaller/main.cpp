#include "CalculateSqrtConfig.h"

#ifndef HAVE_SQRT
#include "MySqrt.h"
#endif

#include <iostream>
#include <math.h> 


int main(int argc, char* argv[])
{ 
    if(argc<2)
	{ 
        std::cout << "错误：输入应大于2" << std::endl;
        return 1; 
    } 
	
	int inputValue = atof(argv[1]); 
	#ifndef HAVE_SQRT
		const int outputValue = MySqrt(inputValue);
	#else
		const int outputValue = sqrt(inputValue);
	#endif
			
    std::cout << "The square root of "<< inputValue << " is :" << outputValue << std::endl; 
    
	return 0; 
} 