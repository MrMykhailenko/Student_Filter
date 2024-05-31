#include "Array.h"
#include "LogFile.h"

Array::Array() {
    size = 1;
    real_size = 1;
    array = new Student[size];
}

Array::~Array() {
    delete[] array;
}

Array Array::operator=(const Array& temporary) {
    if (this == &temporary) {
        return *this;
    }
    delete[] array;

    real_size = temporary.real_size;
    size = temporary.size;

    array = new Student[temporary.size];

    for (int i = 0; i < temporary.real_size; i++) {
        array[i] = temporary.array[i];
    }
    return *this;
}

void Array::expandArray(int delta) {
    Student* array_prom = new Student[size + delta];
    for (int i = 0; i < this->size; i++) {
        array_prom[i] = array[i];
    }
    delete[] array;
    array = array_prom;
    size = size + delta;
}

void Array::addNew(Student val) {
    if (size >= real_size) {
        expandArray(size + 1);
        array[real_size] = val;
        real_size++;
    }
    else {
        array[real_size] = val;
        real_size++;
    }
}

void Array::addNew() {
    Student Temporary;
    Temporary.addData();
    if (size >= real_size) {
        expandArray(size + 1);
        array[real_size] = Temporary;
        real_size++;
    }
    else {
        array[real_size] = Temporary;
        real_size++;
    }
}

Array::Array(const Array& temporary) {
    size = temporary.size;
    real_size = temporary.real_size;
    array = new Student[temporary.size];
    for (int i = 0; i < temporary.size; i++) {
        array[i] = temporary.array[i];
    }
}

void Array::sort_by_faculty(std::string faculty) {
    for (int i = 0; i < size; i++) {
        if (array[i].check_faculty(faculty)) array[i].printInfo();
    }
}

void Array::sort_by_year(int year) {
    for (int i = 0; i < size; i++) {
        if (array[i].check_year(year)) array[i].printInfo();
    }
}

void Array::sort_by_course(unsigned int course) {
    for (int i = 0; i < size; i++) {
        if (array[i].check_course(course)) array[i].printInfo();
    }
}

void Array::sort_by_group(std::string group) {
    for (int i = 0; i < size; i++) {
        if (array[i].check_group(group)) array[i].printInfo();
    }
}
