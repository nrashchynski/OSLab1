#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include "../src/employee.h"

void test_reporter_reads_file() {
	const char* test_file = "test_reporter.dat";
	const char* hourly_rate = "10.0";

	employee emp1 = { 1, "Alice", 20.0 };
	employee emp2 = { 2, "Bob", 25.0 };

	std::ofstream outFile(test_file, std::ios::binary);
	assert(outFile);
	outFile.write(reinterpret_cast<char*>(&emp1), sizeof(employee));
	outFile.write(reinterpret_cast<char*>(&emp2), sizeof(employee));
	outFile.close();

	std::string command = "./reporter " + std::string(test_file) + " " + std::string(hourly_rate);
	int result = system(command.c_str());
	assert(result == 0);
}

int main() {
	test_reporter_reads_file();
	std::cout << "All reporter tests passed!\n";
	return 0;
}