#include "Faculty.h"
#include "LogFile.h"

Faculty::Faculty() {
    name_fac = "Missing";
    grope_index = "Missing";
    course_number = 0;
    Data.write_log("Was created empty Faculty");
}

Faculty::Faculty(string name, string grope, unsigned int course) {
    name_fac = name;
    grope_index = grope;
    course_number = course;
    Data.write_log("Was created faculty with name " + name_fac);
}

void Faculty::add_name() {
    string name_fac;
    cout << "Enter the name of faculty: ";
    cin >> name_fac;
    this->name_fac = name_fac;
    cout << endl;
}

void Faculty::add_grope() {
    string gri;
    cout << "Enter the group index: ";
    cin >> gri;
    grope_index = gri;
    cout << endl;
}

void Faculty::add_course() {
    unsigned int crs;
    cout << "Enter the number of course: ";
marker_crs:

    cin >> crs;
    if (crs <= 0) {
        cout << "Error" << endl;
        goto marker_crs;
    }
    course_number = crs;
    cout << endl;
}

string Faculty::show_name() {
    return name_fac;
}

string Faculty::show_grope() {
    return grope_index;
}

unsigned int Faculty::show_course() {
    return course_number;
}

void Faculty::initial_fast(string name, string grope, unsigned int course) {
    name_fac = name;
    grope_index = grope;
    course_number = course;
    Data.write_log("Was created faculty with name " + name_fac);
}

Faculty& Faculty::operator=(const Faculty& other) {
    if (this == &other) {
        return *this;
    }
    name_fac = other.name_fac;
    grope_index = other.grope_index;
    course_number = other.course_number;
    Data.write_log("Faculty was copied");

    return *this;
}

ostream& operator<<(ostream& os, const Faculty& obj) {
    os << "Faculty: " << obj.name_fac << " Group: " << obj.grope_index << " Course: " << obj.course_number << endl;
    return os;
}
