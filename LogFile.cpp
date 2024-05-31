#include "LogFile.h"

LogFile::LogFile() {
}

void LogFile::write_log(string text) {
    ofstream outFile(file, ofstream::app);

    if (!outFile) {
        cout << "Помилка, шановний!" << endl;
    }

    SYSTEMTIME st;
    GetLocalTime(&st);

    outFile << st.wDay << "." << st.wMonth << "." << st.wYear << " " << "Time: " << st.wHour << ":" << st.wMinute << " " << text << endl;
    outFile.close();
}
