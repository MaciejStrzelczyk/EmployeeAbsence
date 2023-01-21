#include "../include/loadAndSendFiles.h"
#include "../include/absence.h"

LoadAndSendFiles::LoadAndSendFiles() {

}

void LoadAndSendFiles::readFile(string fileName) {

    EmployeeRepository *employeeRepository = new EmployeeRepository();
    fstream absenceFile;
    absenceFile.open(fileName, ios::in);
    string details;
    while(getline(absenceFile, details)) {
        stringstream tempStream(details);
        vector<string> row;
        string singleValue;
        while (tempStream.good())
        {
            getline(tempStream, singleValue, ';');
            row.push_back(singleValue);
        }

        employeeRepository->add(row);
    }

    reportGeneration(employeeRepository);

}

void LoadAndSendFiles::reportGeneration(EmployeeRepository* employees) {

    ofstream output;
    output.open ("../outputs/output.csv");
    int i = 0;
    while(i < employees->getEmployees().size()){
        output << *employees->getEmployees()[i] << ";";
        output << employees->getEmployees()[i].get()->getAbsence().get()->calculateAbsenceDaysForReport(employees->getEmployees()[i]->getAge())[0] << ";";
        output << employees->getEmployees()[i].get()->getAbsence().get()->calculateAbsenceDaysForReport(employees->getEmployees()[i]->getAge())[1] << ";";
        output << employees->getEmployees()[i].get()->getAbsence().get()->calculateAbsenceDaysForReport(employees->getEmployees()[i]->getAge())[2] << endl;
        i++;
    }
    output.close();


}