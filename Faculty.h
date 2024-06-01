#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>
#include "LogFile.h" 

using namespace std;

class Faculty {
private:
    string name_fac;
    string grope_index;
    unsigned int course_number;
    LogFile Data;

public:
    Faculty();
    Faculty(string name, string grope, unsigned int course);
    void add_name();
    void add_grope();
    void add_course();
    string show_name();
    string show_grope();
    unsigned int show_course();
    void initial_fast(string name, string grope, unsigned int course);
    Faculty& operator=(const Faculty& other);
    friend ostream& operator<<(ostream& os, const Faculty& obj);
};

#endif /* FACULTY_H */
