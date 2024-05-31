#ifndef LOGFILE_H
#define LOGFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> // ��� ������������ SYSTEMTIME

using namespace std;

class LogFile {
private:
    string file = "log_file.txt";

public:
    LogFile();
    void write_log(string text);
    void write_all(string text);
};

#endif // LOGFILE_H
