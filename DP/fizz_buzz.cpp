#include <iostream>

std::string fizz_buzz(int number, int iterations){
	std::string output;
	int fizz_number = 3;
	int buzz_number = 5;
	
	for(number;number <= iterations;number++){
		if (number % fizz_number == 0){
			output += "Fizz";
		}
		if (number % buzz_number == 0){
			output += "Buzz";
		}
		if (number % fizz_number != 0 && number % buzz_number != 0){
			output += std::to_string(number);
		}
		output += " ";
	}
	return output;
	
}

int main(int argv, char* argsz[]){
	std::cout << fizz_buzz(1,100);
	return 0;
}
