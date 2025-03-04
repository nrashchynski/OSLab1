#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>

void test_creator_creates_file() {
	const char* test_file = "test_creator.dat";
	const char* num_employees = "2";

	std::string command = "./creator.exe " + std::string(test_file) + " " + std::string(num_employees);
	int result = system(command.c_str());
	assert(result == 0);

	std::ifstream inFile(test_file, std::ios::binary);
	assert(inFile);
	inFile.close();
}

int main() {
	test_creator_creates_file();
	std::cout << "All creator tests passed!\n";
	return 0;
}