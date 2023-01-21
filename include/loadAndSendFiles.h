#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#include "../include/employeeRepository.h"

using namespace std;

#ifndef ABSENCE_APP_LOADANDSENDFILES_H
#define ABSENCE_APP_LOADANDSENDFILES_H

class LoadAndSendFiles
{
private:

public:
    LoadAndSendFiles();
    void readFile(string fileName);
    void reportGeneration (EmployeeRepository* employees);
};

#endif //ABSENCE_APP_LOADANDSENDFILES_H
