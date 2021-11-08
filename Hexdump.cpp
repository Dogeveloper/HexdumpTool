#include "Hexdump.h"

bool CheckAlpha(char c) {
	return !isalnum(c);
}

std::string Hexdump::HexToSingleString(std::string input) {
	std::string toRemove = "0x";
	std::transform(input.begin(), input.end(), input.begin(), ::tolower); // lower case the string
	input.erase(std::remove_if(input.begin(), input.end(), CheckAlpha));
	while (input.find("0x") != std::string::npos) {
		input.erase(input.find("0x"), 2);
	}
	return "0x" + input;
}
