#include "../include/employee.h"
#include "../include/absence.h"


Employee::Employee(vector<string> data){
    this->name = data[0];
    this->surname = data[1];
    this->pesel = data[2];
    this->dateOfBirth = data[3];
    this->gender = data[4];
    this->absence = shared_ptr<Absence>(new Absence(data[5], data[6]));
}

Absence_ptr Employee::getAbsence() const {
    return absence;
}

const string &Employee::getName() const  {
    return this->name;
}

void Employee::setName(string name) {
    Employee::name = name;
}

const string &Employee::getSurname() const {
    return this->surname;
}

void Employee::setSurname(string surname) {
    Employee::surname = surname;
}

const string &Employee::getPesel() const {
    return this->pesel;
}

const string &Employee::getDateOfBirth() const {
    return this->dateOfBirth;
}

void Employee::setDateOfBirth(string dateOfBirth) {
    Employee::dateOfBirth = dateOfBirth;
}

const string &Employee::getGender() const {
    return this->gender;
}

void Employee::setGender(string gender) {
    Employee::gender = gender;
}

//const int &Employee::getAge2() const {
//    Employee::age = getAge();
//
//    return this->age;
//}

const int &Employee::getAge() const {
     /////////// actual date ///////////

     auto now = Clock::now();
     chrono::year_month_day date;
     time_t now_c = Clock::to_time_t(now);
     struct tm *parts = std::localtime(&now_c);

     int currentYear = 1900 + parts->tm_year;
     int currentMonth = 1 + parts->tm_mon;
     int currentDay = parts->tm_mday;

     ///// processing of the employee's date of birth //////

     string date_time_format = "%d.%m.%Y";
     istringstream  ss{this->dateOfBirth};

     ss >> chrono::parse(date_time_format, date);
     int employeeYear = int(date.year());
     int employeeDay = date.day().operator unsigned int();
     int employeeMonth = date.month().operator unsigned int();

     int employeeAge = currentYear - employeeYear;

     if(currentMonth > employeeMonth){
         return employeeAge;

     }
     else if (currentDay > employeeDay){
         return employeeAge;
     }
     return employeeAge - 1;
}

ostream& operator<< ( ostream& output, const Employee& employee )
{
    int age = employee.getAge();
    return output <<  employee.getName() << ";" << employee.getSurname() << ";" << employee.getPesel() << ";" << employee.getDateOfBirth() << ";" << employee.getGender()
    << ";" << age;
}
