#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

template <typename T>
void WriteTextData(const char* s, T t)
{
    ofstream out(s, ios::app);
    if (!out.is_open())
    {
        cout << "Open file failed.\n";
    }
    else
    {
        out << t;
        out.close();
    }
}

void ReadTextData(const char* s, string* &A, int &a) {
    ifstream in(s);
    if (!in.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return;
    }
    a = 0;
    string line;
    while (getline(in, line)) {
        a++;
    }
    in.clear();
    in.seekg(0, ios::beg);
    A = new string[a];
    int i = 0;

    while (getline(in, line) && i < a) {
        A[i] = line;
        i++;
    }
    in.close();
}

bool prov(string line) {
    const regex adr(R"(^г\. [А-Яа-яЁё-]+, (ул|пр|пер)\. [А-Яа-яЁё-]+, д.\d+(, кв\.\d+)?$)");
    return regex_match(line, adr);
}

void printmas(string* A, int a) {
    for (size_t i = 0; i < a; i++)
        if(prov(A[i])) {
            cout << A[i] << endl;
            WriteTextData("Write.txt", A[i]);
            WriteTextData("Write.txt", '\n');
        }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "russian");
    int a;
    string* A;
    ReadTextData("Read1.txt", A, a);
    for (size_t i = 0; i < a; i++)
    {
        cout << A[i] << endl;
    }
    cout << endl << endl;
    printmas(A, a);

    return 0;
}
