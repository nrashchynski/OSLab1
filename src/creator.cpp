#include "employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("Using of: Creator <name of file> <number of notes>\n");
		return 1;
	}

	const char* filename = argv[1];
	int count = atoi(argv[2]);

	std::ofstream outFile(filename, std::ios::binary);
	if (!outFile) {
		printf("Error of opening file!\n");
		return 1;
	}

	for (int i = 0; i < count; i++) {
		employee emp;
		printf("Enter ID, name(max 9 symbols), work hours: ");
		scanf("%d %9s %lf", &emp.num, emp.name, &emp.hours);
		outFile.write(reinterpret_cast<char*>(&emp), sizeof(employee));
	}


	outFile.close();
	return 0;
}