#include "../include/employee.h"
#include "../include/employeeRepository.h"

using namespace std;

void EmployeeRepository::add(vector<string> employeeData) {

    for(Employee_ptr employee : employees){
        if(employee->getPesel() == employeeData[2]){
           employee->getAbsence()->add(employeeData[5], employeeData[6]);
            return;
        }
    }
    // dodaj nowego pracownika
    EmployeeRepository::employees.push_back(static_cast<Employee_ptr>(new Employee(employeeData)));
}
vector<Employee_ptr> EmployeeRepository::getEmployees(){
    return employees;
}



