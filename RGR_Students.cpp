// RGR_Students.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string mounth(int data);

class Student {

private:
    string name;
    string surname;
    int* birth_date;


public:

    Student() {
        name = "John";
        surname = "Doe";
        birth_date = new int[3];
        birth_date[0] = 1;
        birth_date[1] = 1;
        birth_date[2] = 1999;

    }

    ~Student() {
        delete[] birth_date;
    }


    void addData() {
        cout << "Enter the student name: ";
        cin >> name;
        cout << endl;
        
        cout << "Enter the student surname: ";
        cin >> surname;
        cout << endl;

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

    void printInfo() {
        cout << "Student name: " << name << endl;
        cout << "Student surname: " << surname << endl;
        cout << "Date of birth: " << birth_date[0] << " " << mounth(birth_date[1]) << " " << birth_date[2] << endl;

    }

};

int main()
{
    Student Billy;
    Billy.addData();
    Billy.printInfo();
    
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
