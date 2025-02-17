#include "employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Using: Reporter <binary file> <report file> <salary per hour>\n");
        return 1;
    }

    const char* binFile = argv[1];
    const char* reportFile = argv[2];
    double rate = atof(argv[3]);

    std::ifstream inFile(binFile, std::ios::binary);
    if (!inFile) {
        printf("Error of opening binary file\n");
        return 1;
    }

    std::ofstream outFile(reportFile);
    if (!outFile) {
            printf("Error of opening report file\n");
            return 1;
    }

    outFile << "Report by file \"" << binFile << "\"\n";
    outFile << "-------------------------------------------\n";
    outFile << "ID\tName\tHours\tSalary\n";
    outFile << "-------------------------------------------\n";

    employee emp;
    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(employee))) {
        double salary = emp.hours * rate;
        outFile << emp.num << "\t" << emp.name << "\t" << emp.hours << "\t" << salary << "\n";
    }

    inFile.close();
    outFile.close();
    return 0;
}