#include "CalculateSqrtConfig.h"

#ifdef USE_MYMATH
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
	#ifdef USE_MYMATH
		const int outputValue = MySqrt(inputValue);
	#else
		const int outputValue = sqrt(inputValue);
	#endif
			
    std::cout << "The square root of "<< inputValue << " is :" << outputValue << std::endl; 
	
	std::cout << "The version of CalculateSqrt is:" << CalculateSqrt_VERSION_MAJOR << std::endl;
    
	return 0; 
} 