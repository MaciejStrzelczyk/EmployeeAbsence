#include <iostream>
#include "include/loadAndSendFiles.h"
#include "include/employeeRepository.h"


int main() {
    std::cout << "Hello, World!" << std::endl;


    LoadAndSendFiles *file = new LoadAndSendFiles();
    file->readFile("../inputs/input.csv");
    cout << "ffffff" << endl;

    return 0;
}
