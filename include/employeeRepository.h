#include <iostream>
#include <string>
#include <vector>
#include "../include/employee.h"

using namespace std;

#ifndef ABSENCE_APP_EMPLOYEEREPOSITORY_H
#define ABSENCE_APP_EMPLOYEEREPOSITORY_H
typedef shared_ptr<Employee> Employee_ptr;

class EmployeeRepository{
private:
    vector<Employee_ptr> employees;

public:
    vector<Employee_ptr> getEmployees();
    void add(vector<string> employeeData);
};


#endif //ABSENCE_APP_EMPLOYEEREPOSITORY_H
