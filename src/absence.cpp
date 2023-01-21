#include "../include/absence.h"

using namespace std;

Absence::Absence(string absenceFrom, string absenceTo) {
    this->add(absenceFrom, absenceTo);

}


void Absence::add(string absenceFrom, string absenceTo) {
    this->dates.push_back({absenceFrom, absenceTo});
}

unsigned int Absence::getAbsenceDays() {
    string date_time_format = "%d.%m.%Y";
    unsigned int totalDays = 0;
    for(int i = 0; i < this->dates.size(); i++){
        chrono::year_month_day dateFrom;
        istringstream  ssFrom{this->dates[i][0]};
        ssFrom >> chrono::parse(date_time_format, dateFrom);

        chrono::year_month_day dateTo;
        istringstream  ssTo{this->dates[i][1]};
        ssTo >> chrono::parse(date_time_format, dateTo);

        chrono::days days = chrono::sys_days{dateTo} - chrono::sys_days{dateFrom};
        totalDays += days.count();
    }
    return totalDays;
}

vector<int> Absence::calculateAbsenceDaysForReport(int age) {
    vector<int> absenceDaysForReport;
    int totalDays = getAbsenceDays();
    int sicknessBenefit = 0;
    int sickLeave = 0;

    if(age < 51) {
        if (totalDays <= 33) {
            sickLeave = totalDays;
        } else {
            sickLeave = 33;
            sicknessBenefit = totalDays - 33;
        }
    }
    else{
        if(totalDays <= 14){
            sickLeave = totalDays;
        }
        else{
            sickLeave = 14;
            sicknessBenefit = totalDays - 14;
        }

    }
    absenceDaysForReport = {totalDays, sickLeave, sicknessBenefit};

    return absenceDaysForReport;


}