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

void LogFile::write_all(string text) {
    ofstream outFile("data_all.txt", ofstream::trunc);
    string encryptedText = "";
    if (!outFile) {
        cout << "Помилка, шановний!" << endl;
    }

    for (int i = 0; i < text.length(); i++) {
        // Додаємо до коду символа зсув, обмеживаючи його діапазон
        char encryptedChar = ' ';
        if (isalpha(text[i])) {
            if (islower(text[i])) {
                encryptedChar = 'a' + (text[i] - 'a' + 5) % 26;
            }
            else if (isupper(text[i])) {
                encryptedChar = 'A' + (text[i] - 'A' + 5) % 26;
            }
        }
        else {
            encryptedChar = text[i];
        }
        encryptedText += encryptedChar;
    }

    outFile << encryptedText << endl;
    outFile.close();
}