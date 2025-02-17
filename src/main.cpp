#include "employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>

void printBinaryFile(const char* filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        printf("Error of opening binary file!\n");
        return;
    }

    printf("The content of the binary file \"%s\":\n", filename);
    employee emp;
    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(employee))) {
        printf("%d\t%s\t%.2f\n", emp.num, emp.name, emp.hours);
    }
    inFile.close();
}

void printTextFile(const char* filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        printf("Error of opening text file\n");
        return;
    }

    printf("The content of the report file \"%s\": \n", filename);
    char line[256];
    while (inFile.getline(line, 256)) {
        printf("%s\n", line);
    }

    inFile.close();
}

int main() {
    char binFile[50], reportFile[50];
    int count;    // number of employees
    double rate;  // money per hour

    printf("Enter the name of binary file: ");
    scanf("%s", binFile);
    printf("Enter the number of employees: ");
    scanf("%d", &count);

    char creatorCmd[100];
    sprintf(creatorCmd, "creator.exe %s %d", binFile, count);


    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    if (CreateProcess(NULL, creatorCmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else {
        printf("Error of running creator!\n");
        return 1;
    }

    printBinaryFile(binFile);

    printf("Enter the name of report file: ");
    scanf("%s", reportFile);
    printf("Enter the salary per hour: ");
    scanf("%lf", &rate);

    char reporterCmd[100];
    sprintf(reporterCmd, "reporter.exe %s %s %.2f", binFile, reportFile, rate);

    if (CreateProcess(NULL, reporterCmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else {
        printf("Error of running reporter!\n");
        return 1;
    }

    printTextFile(reportFile);
    return 0;
}