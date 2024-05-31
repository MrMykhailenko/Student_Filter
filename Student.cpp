#include "Student.h"
#include "LogFile.h"

void Student::add_name() {
    cout << "Enter the student name: ";
    cin >> name;
    cout << endl;

    cout << "Enter the student surname: ";
    cin >> surname;
    cout << endl;
}

void Student::add_birth() {
    int day;
    do {
        cout << "Enter the day of birthday(number): ";
        cin >> day;
    } while (day <= 0 || day > 31);
    birth_day = day;

    int month;
    do {
        cout << "Enter the month of birthday(number): ";
        cin >> month;
    } while (month <= 0 || month > 12);
    birth_month = month;

    cout << "Enter the year of birthday: ";
    cin >> birth_year;
    cout << endl;

    Data.write_log("Important data was added to " + name);
}

void Student::add_phone() {
    cout << "Enter the phone number (in format like 0502397481):";
    cin >> phone_number;
    Data.write_log("Phone number was added to " + name);
}

Student::Student() {
    name = "John";
    surname = "Doe";
    birth_day = 1;
    birth_month = 1;
    birth_year = 1999;
    Data.write_log("Empty Student was created");
}

Student::Student(string name, string surname, int day, int month, int year, string phone, string fac, string group, unsigned int course) {
    this->name = name;
    this->surname = surname;
    birth_day = day;
    birth_month = month;
    birth_year = year;
    phone_number = phone;
    treba.initial_fast(fac, group, course);
    Data.write_log("Student was created with name " + name);
}

Student::~Student() {
    // Destructor implementation
}

void Student::addData() {
    add_name();
    add_birth();
    add_phone();
    treba.add_name();
    treba.add_grope();
    treba.add_course();
    Data.write_log("Student was created with name " + name);
}

void Student::printInfo() {
    if (name != "John" && surname != "Doe" && birth_day != 1 && birth_month != 1 && birth_year != 1999) {
        cout << "Student name: " << name << endl;
        cout << "Student surname: " << surname << endl;
        cout << "Date of birth: " << birth_day << " " << birth_month << " " << birth_year << endl;
        cout << "Phone number: " << phone_number << endl;
        cout << "Faculty: " << treba.show_name() << " Group: " << treba.show_grope() << " Course: " << treba.show_course() << endl << endl;
    }
    else {
        cout << "You didn't initialize this student" << endl << endl;
    }
}

bool Student::check_faculty(string faculty) {
    return faculty == treba.show_name();
}

bool Student::check_year(int year) {
    return year < birth_year;
}

bool Student::check_course(unsigned int course) {
    return course == treba.show_course();
}

bool Student::check_group(string group) {
    return group == treba.show_grope();
}

Student& Student::operator=(const Student& other) {
    if (this == &other) {
        return *this;
    }

    name = other.name;
    surname = other.surname;
    phone_number = other.phone_number;
    birth_day = other.birth_day;
    birth_month = other.birth_month;
    birth_year = other.birth_year;
    treba = other.treba;
    Data.write_log("Student was copied");

    return *this;
}

ostream& operator<<(ostream& os, const Student& obj) {
    if (obj.name != "John" && obj.surname != "Doe" && obj.birth_day != 1 && obj.birth_month != 1 && obj.birth_year != 1999) {
        os << "Student name: " << obj.name << endl;
        os << "Student surname: " << obj.surname << endl;
        os << "Date of birth: " << obj.birth_day << " " << obj.birth_month << " " << obj.birth_year << endl;
        os << "Phone number: " << obj.phone_number << endl;
        os << obj.treba << endl;
    }
    else {
        os << "You didn't initialize this student" << endl << endl;
    }
    return os;
}
