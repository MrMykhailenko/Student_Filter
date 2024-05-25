// RGR_Students.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string mounth(int data);

class Faculty{
private:
    string name_fac;
    string grope_index;
    unsigned int course_number;

public:
    void add_name() {
        string name_fac;
        cout << "Enter the name of faculty: ";
        cin >> name_fac;
        this->name_fac = name_fac;
        cout << endl;
    }

    void add_grope() {
        string gri;
        cout << "Enter the grope index: ";
        cin >> gri;
        grope_index = gri;
        cout << endl;
    }

    void add_course() {
        unsigned int crs;
        cout << "Enter the number of course: ";
    marker_crs:
        
        cin >> crs;
        if (cin.fail() || crs <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error" << endl;
            goto marker_crs;
        }
        course_number = crs;
        cout << endl;
    }

    string show_name(){
        return name_fac;
    }

    string show_grope() {
        return grope_index;
    }

    unsigned int show_course(){
        return course_number;
    }

    void initial_fast(string name, string grope, unsigned int course) {
        name_fac = name;
        grope_index = grope;
        course_number = course;
    }

};


class Student {

private:
    string name;
    string surname;
    int phone_number;
    int* birth_date;
    Faculty treba;

    void add_name() {
        cout << "Enter the student name: ";
        cin >> name;
        cout << endl;

        cout << "Enter the student surname: ";
        cin >> surname;
        cout << endl;
    }

    void add_birth() {
        marker_day:
            int day;
            cout << "Enter the day of birthday(number): ";
            cin >> day;
            if (cin.fail() || day <= 0 || day > 31) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error" << endl;
                goto marker_day;
            }
            birth_date[0] = day;

            cout << endl;

        marker_mounth:
            int mounth;
            cout << "Enter the mounth of birthday(number): ";
            cin >> mounth;
            if (cin.fail() || mounth <= 0 || mounth > 12) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error" << endl;
                goto marker_mounth;
            }
            birth_date[1] = mounth;
            cout << endl;

        marker_year:
            int year;
            cout << "Enter the year of birthday: ";
            cin >> year;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error" << endl;
                goto marker_year;
            }
            birth_date[2] = year;
            cout << endl;

    }

    void add_phone() {
        int phone;
        cout << "Enter the phone number (in format like 0502397481):";
        
        marker_phone:
        cin >> phone;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error, enter phone in format like 0502397481" << endl;
            goto marker_phone;
        }

        phone_number = phone;
    }

    

public:

    Student() {
        name = "John";
        surname = "Doe";
        birth_date = new int[3];
        birth_date[0] = 1;
        birth_date[1] = 1;
        birth_date[2] = 1999;
    }

    Student(string name, string surname, int day, int mounth, int year, int phone, string fac, string grope, unsigned int course) {
        this->name = name;
        this->surname = surname;
        birth_date[0] = day;
        birth_date[1] = mounth;
        birth_date[2] = year;
        phone_number = phone;
        treba.initial_fast(fac, grope, course);

    }

    ~Student() {
        delete[] birth_date;
    }


    void addData() {
        //add_name();
        //add_birth();
        add_phone();
        treba.add_name();
        treba.add_grope();
        treba.add_course();

    }

    void printInfo() {
        if (phone_number != NULL) {
            cout << "Student name: " << name << endl;
            cout << "Student surname: " << surname << endl;
            cout << "Date of birth: " << birth_date[0] << " " << mounth(birth_date[1]) << " " << birth_date[2] << endl;
            cout << "Phone number: " << phone_number << endl;
            cout << "Faculty: " << treba.show_name() << " Grope: " << treba.show_grope() << " Course: " << treba.show_course() << endl;
        }
        else {
            cout << "You didnt initialise this student" << endl;
        }
       
    }

};

int main()
{
    Student Billy, Tony;
    //Billy.addData();
    Billy.printInfo();
    Tony.printInfo();
    
}


string mounth(int data) {
    switch (data) {
    case 1:
        return "January";
        break;
    case 2:
        return "February";
        break;

    case 3:
        return "March";
        break;

    case 4:
        return "April";
        break;

    case 5:
        return "May";
        break;

    case 6:
        return "June";
        break;


    case 7:
        return "July";
        break;


    case 8:
        return "August";
        break;

    case 9:
        return "September";
        break;

    case 10:
        return "October";
        break;

    case 11:
        return "November";
        break;

    case 12:
        return "December";
        break;

    default:
        return "Error";
        break;
    }
}
