#define _CRT_SECURE_NO_WARNINGS
#include <iostream>   
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <sstream>
using namespace std;

struct Element3;
struct Element2;

struct Element1
{
public:

    char Name[50];
    int SredniBal;
    friend ostream& operator<< (ostream& out, const Element1& m)
    {
        out  << "Name: " << left << setw(30) << m.Name << "\tSredniy Ball: " << m.SredniBal;
        return out;
    }

    friend istream& operator>> (istream& in, Element1& m)
    {
        cout << "Napishite name: ";
        in.getline(m.Name, 50);
        cout << "Napishite Sredniy Ball: ";
        in >> m.SredniBal;
        in.ignore();
        return in;
    }

    Element1() : SredniBal(0) { Name[0] = '\0'; }
    Element1(int S) : SredniBal(S) { Name[0] = '\0'; }
    Element1(const char* N) : SredniBal(0) {
        strncpy(Name, N, 49);
        Name[49] = '\0';
    }
    Element1(const char* N, int S) : SredniBal(S) {
        strncpy(Name, N, 49);
        Name[49] = '\0';
    }
    Element1(const Element1& m) : SredniBal(m.SredniBal) {
        strncpy(Name, m.Name, 49);
        Name[49] = '\0';
    }
    Element1(const Element3& m);
    ~Element1() {}

    template <class T>
    Element1& operator=(const T& m) {
        try {
            strncpy(Name, m.Name, 49);
            Name[49] = '\0';
        }
        catch (...) {}
        try {
            SredniBal = m.SredniBal;
        }
        catch (...) {
            SredniBal = 0;
        }
        return *this;
    }

    template <class T>
    bool operator==(const T& other) const {
        try {
            if (strcmp(Name, other.Name) != 0) return false;
        }
        catch (...) {}
        try {
            if (SredniBal != other.SredniBal) return false;
        }
        catch (...) {
            return false;
        }
        return true;
    }

    bool operator==(const Element2& other) const;

    bool operator < (const Element1& m) const
    {
        return (SredniBal < m.SredniBal);
    }

    bool operator < (int m) const
    {
        return (SredniBal < m);
    }

    bool operator < (const Element3& m) const;
};

struct Element2
{
    char Name[50], Space[50];

    friend istream& operator>> (istream& in, Element2& m)
    {
        cout << "Napishite name: ";
        in.getline(m.Name, 50);
        cout << "Napishite activnost: ";
        in.getline(m.Space, 50);
        return in;
    }

    friend ostream& operator<< (ostream& out, const Element2& m)
    {
        out << "Name: " << left << setw(30) << m.Name << "\tSpace: " << m.Space;
        return out;
    }

    Element2() { Name[0] = '\0'; Space[0] = '\0'; }
    Element2(const char* N) { strncpy(Name, N, 49); Name[49] = '\0'; Space[0] = '\0'; }
    Element2(const char* N, const char* S) { strncpy(Name, N, 49); Name[49] = '\0'; strncpy(Space, S, 49); Space[49] = '\0'; }
    Element2(const Element2& m) { strncpy(Name, m.Name, 49); Name[49] = '\0'; strncpy(Space, m.Space, 49); Space[49] = '\0'; }
    ~Element2() {}

    template <class T>
    Element2& operator=(const T& m) {
        try {
            strncpy(Name, m.Name, 49);
            Name[49] = '\0';
        }
        catch (...) {}
        try {
            strncpy(Space, m.Space, 49);
            Space[49] = '\0';
        }
        catch (...) {}
        return *this;
    }

    /*template <class T>
    bool operator==(const T& other) const {
        try {
            if (strcmp(Name, other.Name) != 0) return false;
        }
        catch (...) {
            return false;
        }
        try {
            if (strcmp(Space, other.Space) != 0) return false;
        }
        catch (...) {
            return false;
        }
        return true;
    }*/

    template <class T1>
    bool operator==(T1 other) const {
        if (strcmp(Space, other) == 0) return true;
        else return false;
    }

};

struct Element3
{
    char Name[50];
    int SredniBal;

    friend istream& operator>> (istream& in, Element3& m)
    {
        cout << "Napishite name: ";
        in.getline(m.Name, 50);
        cout << "Napishite Sredniy Ball: ";
        in >> m.SredniBal;
        in.ignore();
        return in;
    }

    friend ostream& operator<< (ostream& out, const Element3& m)
    {
        out << "Name: " << left << setw(30) << m.Name << "\tSredniy Ball: " << m.SredniBal;
        return out;
    }

    Element3() : SredniBal(0) { Name[0] = '\0'; }
    Element3(int S) : SredniBal(S) { Name[0] = '\0'; }
    Element3(const char* N) : SredniBal(0) { strncpy(Name, N, 49); Name[49] = '\0'; }
    Element3(const char* N, int S) : SredniBal(S) { strncpy(Name, N, 49); Name[49] = '\0'; }
    Element3(const Element3& m) : SredniBal(m.SredniBal) { strncpy(Name, m.Name, 49); Name[49] = '\0'; }
    Element3(const Element1& m) : SredniBal(m.SredniBal) { strncpy(Name, m.Name, 49); Name[49] = '\0'; }
    ~Element3() {}

    template <class T>
    bool operator==(const T& other) const {
        try {
            if (strcmp(Name, other.Name) != 0) return false;
        }
        catch (...) {
            return false;
        }
        try {
            if (SredniBal != other.SredniBal) return false;
        }
        catch (...) {
            return false;
        }
        return true;
    }

    template <class T>
    Element3& operator=(const T& m) {
        try {
            strncpy(Name, m.Name, 49);
            Name[49] = '\0';
        }
        catch (...) {}
        try {
            SredniBal = m.SredniBal;
        }
        catch (...) {
            SredniBal = 0;
        }
        return *this;
    }

    bool operator < (const Element3& m) const
    {
        return (SredniBal < m.SredniBal);
    }

    bool operator < (const Element1& m) const
    {
        return (SredniBal < m.SredniBal);
    }
};

Element1::Element1(const Element3& m) : SredniBal(m.SredniBal) {
    strncpy(Name, m.Name, 49);
    Name[49] = '\0';
}

bool Element1::operator<(const Element3& m) const
{
    return (SredniBal < m.SredniBal);
}

bool Element1::operator==(const Element2& other) const{
    if (strcmp(Name, other.Name) == 0) return true;
    else return false;
}

int probel(const string& s, int start) {
    for (int i = start; i < s.size(); i++) {
        if (s[i] == ' ') return i;
    }
    return s.size() - 1;
}

template<class T>
class MASSIV
{
    T* mas;
    int razm;
    int count;

public:

    MASSIV() : razm(0), count(0), mas(nullptr) {}
    MASSIV(int n) : count(0), razm(n) {
        mas = new T[razm];
    }
    MASSIV(const MASSIV<T>& m) : count(m.count), razm(m.razm) {
        mas = new T[razm];
        for (int i = 0; i < razm; i++) {
            mas[i] = m.mas[i];
        }
    }
    ~MASSIV()
    {
        delete[] mas;
    }

    int GetCount() const
    {
        return count;
    }
    int GetRazm() const
    {
        return razm;
    }
    void yvelrazm(int k)
    {
        razm += k;
    }
    void yvelcount(int k)
    {
        count += k;
    }

    void WriteTextData(const char* s) const
    {
        ofstream out(s);
        if (!out.is_open())
        {
            cout << "Open file failed.\n";
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                out << mas[i];
            }
            out.close();
        }
    }

    void ReadTextData(const char* s) {
        ifstream in(s);
        if (!in.is_open()) {
            cout << "Ошибка открытия файла" << endl;
            return;
        }
        razm = 0;
        string line;
        while (getline(in, line)) {
            razm++;
        }
        in.clear();
        in.seekg(0, ios::beg);
        mas = new T[razm];
        int i = 0;

        while (getline(in, line) && i < razm) {
            strncpy(mas[i].Name, line.substr(0, probel(line, probel(line, 0) + 1)).c_str(), 49);
            mas[i].Name[49] = '\0';
            elemread(mas[i], line);
            count++;
            i++;
        }
        in.close();
    }

    void elemread(Element1& m, string line) {
        try {
            m.SredniBal = stoi(line.substr(probel(line, probel(line, 0) + 1) + 1));
        }
        catch (invalid_argument& e) {
            m.SredniBal = 0;
        }
    }

    void elemread(Element2& m, string line) {
        strncpy(m.Space, line.substr(probel(line, probel(line, 0) + 1) + 1).c_str(), 49);
        m.Space[49] = '\0';
    }

    friend ostream& operator<< (ostream& out, const MASSIV& m)
    {
        for (int i = 0; i < m.count; i++) {
            out << i + 1 << "->" << m.mas[i] << endl;
        }
        cout << endl;
        return out;
    }

    T& operator[] (int m)
    {
        return mas[m];
    }

    friend istream& operator>> (istream& in, MASSIV& m)
    {
        cout << "Vvedite " << m.razm << " elementov massiva\n";
        for (int i = 0; i < m.razm; i++) {
            in >> m.mas[i];
            m.count++;
        }
        in.ignore();
        return in;
    }

    void WriteData(const char* s) {
        ofstream out(s, ios::out | ios::binary);
        if (!out.is_open()) {
            cout << "Open file failed.\n";
            return;
        }
        out.write(reinterpret_cast<char*>(&count), sizeof(count));
        out.write(reinterpret_cast<char*>(mas), count * sizeof(T));
        out.close();
    }

    void ReadData(const char* s) {
        ifstream in(s, ios::in | ios::binary);
        if (!in.is_open()) {
            cout << "Open file failed.\n";
            return;
        }
        in.read(reinterpret_cast<char*>(&count), sizeof(count));
        mas = new T[count];
        in.read(reinterpret_cast<char*>(mas), count * sizeof(T));
        in.close();
    }

    void WriteElements(const char* filename, int k, int numElements) {
        if (k < 0 || k + numElements > count) {
            cout << "Invalid range.\n";
            return;
        }

        ofstream out(filename, ios::out | ios::binary);
        if (!out.is_open()) {
            cout << "Open file failed.\n";
            return;
        }
        out.write(reinterpret_cast<char*>(&numElements), sizeof(numElements));
        out.write(reinterpret_cast<char*>(&mas[k]), numElements * sizeof(T));
        out.close();
    }

    void ReadElements(const char* filename, int offset, int numElementsToRead) {
        ifstream in(filename, ios::in | ios::binary);
        if (!in.is_open()) {
            cout << "Open file failed.\n";
            return;
        }
        int k = offset * sizeof(T);
        in.seekg(k, ios::beg);
        razm = numElementsToRead;
        mas = new T[razm];
        in.read(reinterpret_cast<char*>(mas), numElementsToRead * sizeof(T));
        count = in.gcount() / sizeof(T);
        in.close();
    }

    
    template<class T1, class T2>
    void per(MASSIV<T1> &a, MASSIV<T2> &b) {
        razm = 0;
        for(int i = 0; i < a.GetRazm(); i++)
            for (int j = 0; j < b.GetRazm(); j++)
                if (a[i] == b[j]) razm++;
        count = 0;
        delete[] mas;
        mas = new T[razm];
        for (int i = 0; i < a.GetRazm(); i++)
            for (int j = 0; j < b.GetRazm(); j++)
                if (a[i] == b[j]) mas[count++] = a[i];
    }

    template<class T1,class T2>
    void poiskakt(MASSIV<T1> a, T2 b) {
        razm = 0;
        for (int i = 0; i < a.GetCount(); i++)
                if (a[i] == b) razm++;
        count = 0;
        delete[] mas;
        mas = new T[razm];
        for (int i = 0; i < a.GetCount(); i++)
            if (a[i] == b) mas[count++] = a[i];
    }

    void sortmas() {
        sort(mas, mas + count, [](const T& a, const T& b) {return a < b;});
    }

    friend void frfn();

    void metvneclass();

};

void MASSIV<Element1>::metvneclass() {
    cout << "Metod vne classa\n\n";
}

void frfn() {
    cout << "Friend function\n\n";
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    MASSIV<Element1> A1, bin, bin2, bin3;
    MASSIV<Element2> A2, B2;
    MASSIV<Element3> A3;
    A1.ReadData("Binar.bin");
    // A1.ReadTextData("Read1.txt");
    A2.ReadTextData("Read2.txt");
    cout << "Massiv element1:\n" << A1;
    cout << "Massiv element2:\n" << A2;
    A3.per(A1, A2);
    cout << "Massiv element3:\n" << A3;
    A1.sortmas();
    cout << "Massiv element1 sort:\n" << A1;
    B2.poiskakt(A2, A2[2].Space);
    cout << "Naidennie element2:\n" << B2;
    frfn();
    A1.metvneclass();
    //A1.WriteData("Binar.bin");
   // bin.ReadData("Binar.bin");
    cout << "Text from bin file\n" << bin;

    MASSIV<int> A4(3), B4(2), C4, D4;
    cin >> A4 >> B4;
    cout << "Massiv int A\n" << A4 << "Massiv int B\n" << B4;
    C4.per(A4, B4);
    cout << "Massiv int C:\n" << C4;
    A4.sortmas();
    cout << "Massiv int sort:\n" << A4;
    D4.poiskakt(A4, 2);
    cout << "Naiden:\n " << D4;
    A1.WriteElements("Binar2.bin", 3, 3);
    bin2.ReadData("Binar2.bin");
    cout << bin2;
    bin3.ReadElements("Binar.bin", 3, 3);
    cout << bin3;
    return 0;
}