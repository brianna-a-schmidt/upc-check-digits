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
	
	int working_num [12];			//hold digits
	int odd_sum = 0;			//holds the sum of the odd digits
	int even_sum = 0;			//holds the sum of the even digits
	int final_digit;			//holds the final digit

	for(int i = 11; i >=1; i--){
		working_num[i] = input_upc % 10;
		input_upc = input_upc / 10;

	}					//puts digits into array so index can be used to calculate things

						//Step 1: add up all odd digits (even indices)
	
	for(int i = 0; i < 11; i++){
		if(i%2 == 0)	
			odd_sum += working_num[i];
	}

						//Step 2: Multiply the result by 3
	odd_sum = odd_sum * 3;

						//Step 3: add up all even digits (odd indices), then add to odd_sum
	for(int i = 0; i < 11; i++){
		if(!(i%2 == 0))
			even_sum += working_num[i];
	}

	final_digit = odd_sum + even_sum;

						//Step 4: Result of step 3 modulo 10
	final_digit = final_digit % 10;


						//Step 5: If final_digit = 0, then return 0, otherwise return 10 - final_digit
	if(final_digit != 0)
		final_digit  = 10 - final_digit;

	return final_digit;

}
