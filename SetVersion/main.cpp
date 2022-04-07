#include <iostream>
#include <math.h> 

#include "CalculateSqrtConfig.h"

int main(int argc, char* argv[])
{ 
    if(argc<2)
	{ 
        std::cout << "错误：输入应大于2" << std::endl;
        return 1; 
    } 
    double inputValue = atof(argv[1]); 
    double outputValue = sqrt(inputValue); 
    std::cout << "The square root of "<< inputValue << " is :" << outputValue << std::endl; 
	
	std::cout << "The version of CalculateSqrt is:" << CalculateSqrt_VERSION_MAJOR << std::endl;
    return 0; 
} 