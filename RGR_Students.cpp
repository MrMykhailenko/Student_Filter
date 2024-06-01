#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "Array.h"
#include "Faculty.h"
#include "LogFile.h"
#include "Student.h"

using namespace std;

string mounth(int data);
int main()
{
    
    Student Sadie("Sadie", "Loran", 18, 3, 2003, "2547868791", "Ray", "rg", 2);
    Student Lilith("Lilith", "Morningstar", 16, 6, 2001, "2547868791", "Ray", "rt", 1);
    Student George("George", "Masterson", 18, 3, 2003, "2547868791", "May", "rg", 2);
    Student Billy("Billy", "Masterson", 11, 7, 2006, "2547868791", "Ray", "rg", 2); 

    Array Master;
    Master.addNew(Sadie);
    Master.addNew(Billy);
    Master.addNew(George);
    Master.addNew(Lilith);

    Master.sort_by_group("rt");

   Master.create_database();
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