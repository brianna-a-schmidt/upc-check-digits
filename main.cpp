#include <iostream>

//prototypes
long long generateCheckBit(long long input_upc);

//driver
int main(){
	
	long long input_upc;			//use of long long so can read 11 digit number

	std::cout << "Please enter your UPC code: ";

	while(!(std::cin >> input_upc)){	//checks if input failed
		std::cin.clear();		//clears error flags for good future input
		std::cin.ignore(1000, '/n');	//ignores the characters up to a newline character

		std::cout << "\nBad input! UPC codes are a series of integers, please try again: ";
	}					//input validation loop from https://study.com/academy/lesson/validating-input-data-in-c-plus-plus-programming.html

	std::cout << "Generating check bit..." << std::endl;

	long long final_upc = generateCheckBit(input_upc);

	std::cout << "Final UPC is " << final_upc << std::endl;

	return 0;

}

//preconditions: a valid UPC 11 digit code
//postconditions: the generated checkbit gets appended to

long long generateCheckBit(long long input_upc){

	return 0;

}
