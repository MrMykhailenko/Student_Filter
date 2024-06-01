#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include "Student.h" 

class Array {
private:
    Student* array;
    int size;
    int real_size;

public:
    Array();
    ~Array();
    Array operator=(const Array& temporary);
    void expandArray(int delta);
    void addNew(Student val);
    void addNew();
    Array(const Array& temporary);
    void sort_by_faculty(std::string faculty);
    void sort_by_year(int year);
    void sort_by_course(unsigned int course);
    void sort_by_group(std::string group);
    void create_database();
};

#endif 
