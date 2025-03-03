#include <iostream>
#include "../src/employee.h"
#include <fstream>
#include <cassert>

void test_employee_creation() {
    employee emp = { 1, "John Doe", 40.0 };
    assert(emp.num == 1);
    assert(std::string(emp.name) == "John Doe");
    assert(emp.hours == 40.0);
}

void test_employee_serialization() {
    employee emp = { 2, "Jane Doe", 35.0 };
    std::ofstream outFile("test_employee.dat", std::ios::binary);
    assert(outFile);
    outFile.write(reinterpret_cast<char*>(&emp), sizeof(employee));
    outFile.close();

    employee emp_read;
    std::ifstream inFile("test_employee.dat", std::ios::binary);
    assert(inFile);
    inFile.read(reinterpret_cast<char*>(&emp_read), sizeof(employee));
    inFile.close();

    assert(emp_read.num == emp.num);
    assert(std::string(emp_read.name) == std::string(emp.name));
    assert(emp_read.hours == emp.hours);
}

int main() {
    test_employee_creation();
    test_employee_serialization();
    std::cout << "All employee tests passed!\n";
    return 0;
}