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

    Faculty(){
        name_fac = "Missing";
        grope_index = "Missing";
        course_number = 0;
    }

    Faculty(string name, string grope, unsigned int course) {
        name_fac = name;
        grope_index = grope;
        course_number = course;
    }

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

    Faculty& operator=(const Faculty& other) {
        if (this == &other) {
            return *this;
        }
        name_fac = other.name_fac;
        grope_index = other.grope_index;
        course_number = other.course_number;
        

        return *this;
    }

    friend ostream& operator<<(ostream& os, const Faculty& obj);

};

ostream& operator<<(ostream& os, const Faculty& obj) {
    os << "Faculty: " << obj.name_fac << " Grope: " << obj.grope_index << " Course: " << obj.course_number << endl;
    return os;
}


class Student {

private:
    string name;
    string surname;
    string phone_number;
    int birth_day;
    int birth_mounth;
    int birth_year;
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
            birth_day = day;

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
            birth_mounth = mounth;
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
            birth_year = year;
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
        birth_day = 1;
        birth_mounth = 1;
        birth_year = 1999;
    }

    Student(string name, string surname, int day, int mounth, int year, string phone, string fac, string grope, unsigned int course) {
        this->name = name;
        this->surname = surname;
        
        birth_day = day;
        birth_mounth = mounth;
        birth_year = year;
        phone_number = phone;
        treba.initial_fast(fac, grope, course);

    }

    ~Student() {
       
    }


    void addData() {
        add_name();
        add_birth();
        add_phone();
        treba.add_name();
        treba.add_grope();
        treba.add_course();

    }

    void printInfo() {
        if (name != "John" && surname != "Doe" && birth_day != 1 && birth_mounth != 1 && birth_year != 1999) {
            cout << "Student name: " << name << endl;
            cout << "Student surname: " << surname << endl;
            cout << "Date of birth: " << birth_day << " " << mounth(birth_mounth) << " " << birth_year << endl;
            cout << "Phone number: " << phone_number << endl;
            cout << "Faculty: " << treba.show_name() << " Grope: " << treba.show_grope() << " Course: " << treba.show_course() << endl << endl;
        }
        else {
            cout << "You didnt initialise this student" << endl << endl;
        }
       
    }

    bool check_faculty(string faculty) {
        if (faculty == treba.show_name()) return true;
        else return false;
    }

    bool check_year(int year) {
        if (year < birth_year) return true;
        else return false;
    }

    bool check_course(unsigned int course) {
        if (course == treba.show_course()) return true;
        else return false;
    }

    bool check_grope(string grope) {
        if (grope == treba.show_grope()) return true;
        else return false;
    }

    Student& operator=(const Student& other) {
        if (this == &other) {
            return *this;
        }

        name = other.name;
        surname = other.surname;
        phone_number = other.surname;
        birth_day = other.birth_day;
        birth_mounth = other.birth_mounth;
        birth_year = other.birth_year;
        treba = other.treba;

        return *this;
    }

    friend ostream& operator<<(ostream& os, const Student& obj);

};

ostream& operator<<(ostream& os, const Student& obj) {
    if (obj.name != "John" && obj.surname != "Doe" && obj.birth_day != 1 && obj.birth_mounth != 1 && obj.birth_year != 1999) {
        os << "Student name: " << obj.name << endl;
        os << "Student surname: " << obj.surname << endl;
        os << "Date of birth: " << obj.birth_day << " " << mounth(obj.birth_mounth) << " " << obj.birth_year << endl;
        os << "Phone number: " << obj.phone_number << endl;
        os << obj.treba << endl;
    }
    else {
        os << "You didnt initialise this student" << endl << endl;
    }
    return os;
}



void sort_by_faculty(Student* array, string faculty, int size) {
    for(int i = 0; i< size; i++){
        if (array[i].check_faculty(faculty)) array[i].printInfo();
    }
}

void sort_by_year(Student* array, int year, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i].check_year(year)) array[i].printInfo();
    }
}

void sort_by_course(Student* array, unsigned int course, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i].check_course(course)) array[i].printInfo();
    }
}

void sort_by_grope(Student* array, string grope, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i].check_grope(grope)) array[i].printInfo();
    }
}



int main()
{
    int size = 5;
    Student* array = new Student[size];
    

    //Student Billy, Tony;

    //Student Sadie("Sadie", "Loran",18,3,2003, "2547868791" , "Gay", "rg",2);

    array[0] = Student("Sadie", "Loran",18,3,2003, "2547868791", "Gay", "rg",2);

    //Student Mike("Mike", "Masterson", 13, 7, 1998, "1457896320", "Gay", "rg", 3);
   array[1] = Student("Mike", "Masterson",13,7,1998, "1457896320", "May", "rg",3);

   // Student Lira("Lira", "Loran", 18, 3, 2003, "2365897402", "Gay", "rsr", 1);
    array[2] = Student("Lira", "Loran",18,3,2022, "2365897402", "Gay", "rsr",1);

    array[3] = Student("Mike", "Masterson", 13, 7, 1996, "1457896320", "Ray", "rg", 3);

    // Student Lira("Lira", "Loran", 18, 3, 2003, "2365897402", "Gay", "rsr", 1);
    array[4] = Student("Lira", "Doren", 11, 7, 2021, "2365897402", "May", "rsr", 1);

    //Billy.addData();
    //Billy.printInfo();
    //Tony.printInfo();
    //Sadie.printInfo();
    //Mike.printInfo();
    //Lira.printInfo();
    
    //array[0].printInfo();
    //array[1].printInfo();
    //array[2].printInfo();

    //sort_by_faculty(array, "Ray", size);

    //sort_by_year(array,2000, size);

    //sort_by_course(array,2, size);

    //sort_by_grope(array, "rsr", size);

   Student Antony;
   Antony.printInfo();
   Antony = array[2];
   cout << Antony;
    
    delete[] array;
    
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
