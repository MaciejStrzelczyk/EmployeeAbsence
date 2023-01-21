#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>
#include <ctime>
#include "../include/absence.h"

using namespace std;
typedef chrono::system_clock Clock;
typedef shared_ptr<Absence> Absence_ptr;

#ifndef ABSENCE_APP_EMPLOYEE_H
#define ABSENCE_APP_EMPLOYEE_H

class Employee
{
private:
    string name;
    string surname;
    string pesel;
    string dateOfBirth;
    string gender;
    Absence_ptr absence;
public:
    Employee(vector<string> data);

    const string &getName() const;

    void setName(string name);

    const string &getSurname() const;

    void setSurname(string surname);

    const string &getPesel() const;

    const string &getDateOfBirth() const;

    void setDateOfBirth(string dateOfBirth);

    const string &getGender() const;

    void setGender(string gender);

    Absence_ptr getAbsence() const;

    void addAbsenceDates();

    const int &getAge() const;

//    const int &getAge2() const;

    friend ostream& operator << ( ostream & output, const Employee& employee );

};
#endif //ABSENCE_APP_EMPLOYEE_H
