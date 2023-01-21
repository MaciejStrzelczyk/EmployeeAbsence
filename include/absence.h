#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>
#include <ctime>

using namespace std;

#ifndef ABSENCE_APP_ABSENCE_H
#define ABSENCE_APP_ABSENCE_H

class Absence{

private:
    vector<vector<string>> dates;
    unsigned int getAbsenceDays();

public:
    Absence(string absenceFrom, string absenceTo);
    void add(string absenceFrom, string absenceTo);
    vector<int> calculateAbsenceDaysForReport(int age);

};


#endif //ABSENCE_APP_ABSENCE_H
