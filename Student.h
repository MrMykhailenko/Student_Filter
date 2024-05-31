#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Faculty.h"
#include "LogFile.h"

using namespace std;

class Student {
private:
    string name;
    string surname;
    string phone_number;
    int birth_day;
    int birth_month;
    int birth_year;
    Faculty treba;
    LogFile Data;

    void add_name();
    void add_birth();
    void add_phone();

public:
    Student();
    Student(string name, string surname, int day, int month, int year, string phone, string fac, string group, unsigned int course);
    ~Student();

    void addData();
    void printInfo();

    bool check_faculty(string faculty);
    bool check_year(int year);
    bool check_course(unsigned int course);
    bool check_group(string group);

    Student& operator=(const Student& other);
    friend ostream& operator<<(ostream& os, const Student& obj);
};

#endif // STUDENT_H
