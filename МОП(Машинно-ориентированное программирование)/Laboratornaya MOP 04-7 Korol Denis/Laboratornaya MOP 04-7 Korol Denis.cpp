#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

extern "C" bool __cdecl  asm_cmp(const char* str1, int num1, const char* str2, int num2);

extern "C" void __cdecl  asm_copy(const char* str1, int num1, const char* str2, int num2);

extern "C" int __cdecl  asm_repl(const char* str1, int num1, const char* str2, int num2);

extern "C" bool __cdecl  asm_search(const char* str1, int num1, const char* str2, int num2);

// Функция для записи данных в файл
template<typename x>
void fwrite(const string& path, const x& text) {
    ofstream fout;
    fout.open(path, ofstream::app);

    if (!fout.is_open()) {
        cout << "Ошибка записи в файл" << endl;
    }
    else {
        fout << text;
    }
    fout.close();
}

// Функция для чтения из файла
string fread(const string& path) {
    ifstream fin;
    fin.open(path, ifstream::in);
    string A;
    if (!fin.is_open()) {
        cout << "Ошибка открытия файла" << endl;
    }
    else {
        cout << "Успешное открытие файла!" << endl;
        char ch;
        while (fin.get(ch)) {
            if (ch == '\n') ch = '|';
            A += ch;
        }
    }
    fin.close();
    return A;
}

// Функция перевода строки до | в char
char* perstringvchar(const string& str, int& len) {
    len = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '|') break;
        len++;
    }
    char* ch = new char[len + 1];
    for (int i = 0; i < len; i++) {
        ch[i] = str[i];
    }
    ch[len] = '\0';
    return ch;
}

// Функция удаления до |
string ymensh(const string& str) {
    int len = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '|') break;
        len++;
    }
    return str.substr(len + 1);
}

// Функция поиска лексем 
char** findleks(char* str, const char* razd, int& kol) {
    char* copy = _strdup(str);
    char* leks = strtok(copy, razd);
    kol = 0;
    while (leks != nullptr) {
        kol++;
        leks = strtok(nullptr, razd);
    }
    free(copy);

    if (kol != 0) {
        char** leksems = new char* [kol];
        char* copy2 = _strdup(str);
        leks = strtok(copy2, razd);

        for (int i = 0; i < kol; i++) {
            if (leks == nullptr) break;
            leksems[i] = new char[strlen(leks) + 1];
            strcpy(leksems[i], leks);
            leks = strtok(nullptr, razd);
        }
        free(copy2);
        return leksems;
    }
    return nullptr;
}

// Функция для проверки наличия лексем в первой строке 
bool sovpad(const char* str, const char* leks) {
    char* copystr = new char[strlen(str) + 3];
    char* copylen = new char[strlen(leks) + 3];
    strcpy(copystr, ">");
    strcat(copystr, str);
    strcat(copystr, "<\0");
    strcpy(copylen, ">");
    strcat(copylen, leks);
    strcat(copylen, "<\0");
    bool t = strstr(copystr, copylen) != nullptr;
    delete[] copystr;
    delete[] copylen;
    return t;
}

// Функция для проверки на палиндром
bool palindrom(const char* str) {
    char* reversed = new char[strlen(str) + 1]; strcpy(reversed, str);
    reverse(reversed, reversed + strlen(str));
    bool t = asm_cmp(str, strlen(str), reversed, strlen(reversed));
    delete[] reversed;
    return t;
}

// Функция для проверки на 8cc
bool ss8(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] < '0' || str[i] > '7') {
            return false;
        }
    }
    return true;
}

bool ss8(const char* str) {
    char* end;
    long int number = strtol(str, &end, 8);
    if (*end != '\0') return false;
    return true;
}

//Функция перевода char* в int*
int* percharvint(char** str, int kol) {
    int* numbers = new int[kol];
    for (int i = 0; i < kol; i++) {
        numbers[i] = atoi(str[i]);
    }
    return numbers;
}

// Функция для сортировки выбором 
void selectionSort(int* numbers, int kol, char** str) {
    for (int i = 0; i < kol - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < kol; ++j) {
            if (numbers[j] < numbers[min]) {
                min = j;
            }
        }
        swap(numbers[i], numbers[min]);
        swap(str[i], str[min]);
    }
}


int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));
    string path1 = "myFile.txt";
    string path2 = "OutPut.txt";
    string str = fread(path1);
    fwrite(path2, '\n');
    int la, lb, lc, Akol, Bkol, sp = 0, s8 = 0;
    char* razd = perstringvchar(ymensh(ymensh(str)), lc);
    char* A = perstringvchar(str, la);
    str = ymensh(str);
    char* B = perstringvchar(str, lb);
    cout << A << '\n' << B << '\n' << razd << '\n';

    // Какие из лексем встречаются в первой строке
    char** Bleksems = findleks(B, razd, Bkol);
    cout << "\nОбщие лексемы: ";
    fwrite(path2, "Общие лексемы: ");
    for (int i = 0; i < Bkol; i++) {
        if (asm_search(A, strlen(A), Bleksems[i], strlen(Bleksems[i]))) {
            cout << Bleksems[i] << " ";
            fwrite(path2, Bleksems[i]);
            fwrite(path2, ' ');
        }
    }
    fwrite(path2, '\n');

    // Нахождение длин строк
    for (int i = 0; i < Bkol; ++i) {
        if (palindrom(Bleksems[i])) {
            sp += strlen(Bleksems[i]) + strlen(razd);
        }
    }
    for (int i = 0; i < Bkol; ++i) {
        if (ss8(Bleksems[i])) {
            s8 += strlen(Bleksems[i]) + strlen(razd);
        }
    }

    // Создание строки с палиндромами и 8-сс
    if (sp != 0) {
        char* pal = new char[sp + 1];
        char* ch8 = new char[s8 + 1];
        pal[0] = '\0';
        ch8[0] = '\0';
        for (int i = 0; i < Bkol; ++i) {
            if (palindrom(Bleksems[i])) {
                strcat(pal, Bleksems[i]);
                strcat(pal, razd);
            }
        }
        for (int i = 0; i < Bkol; ++i) {
            if (ss8(Bleksems[i])) {
                strcat(ch8, Bleksems[i]);
                strcat(ch8, razd);
            }
        }
        ch8[s8 - strlen(razd)] = '\0';
        pal[sp - strlen(razd)] = '\0';
        cout << "\nПалиндромы : " << pal;
        cout << "\n8 - сс: " << ch8 << '\n';
        fwrite(path2, "Палиндромы: ");
        fwrite(path2, pal);
        fwrite(path2, '\n');
        fwrite(path2, "8 - сс: ");
        fwrite(path2, ch8);
        fwrite(path2, '\n');

        delete[] pal;
        delete[] ch8;
    }

    // Сортировка массива A
    char** Aleksems = findleks(A, razd, Akol);
    int* Aint = percharvint(Aleksems, Akol);
    int As = 0;
    selectionSort(Aint, Akol, Aleksems);
    for (int i = 0; i < Akol; i++)
        As += strlen(Aleksems[i]) + strlen(razd);
    delete[] A;
    A = new char[As + 1];
    A[0] = '\0';
    for (int i = 0; i < Akol; i++) {
        strcat(A, Aleksems[i]);
        strcat(A, razd);
    }
    A[As - strlen(razd)] = '\0';
    cout << "Отсортированная 1ая строка: " << A << '\n';
    fwrite(path2, "Отсортированная 1ая строка: ");
    fwrite(path2, A);
    fwrite(path2, '\n');

    //Создание string из первой строки
    string Astr = A;
    cout << "Первая строка string: " << Astr << '\n';
    fwrite(path2, "Первая строка string: ");
    fwrite(path2, Astr);
    fwrite(path2, '\n');
    Astr.insert(0, (to_string(rand() % 1000) + razd));
    cout << "Рандомное число в начало: " << Astr << '\n';
    fwrite(path2, "Рандомное число в начало: ");
    fwrite(path2, Astr);
    fwrite(path2, '\n');

    //Удаление 8сс
    int Alenstr = 0;
    for (int i = Astr.size() - 1; i >= 0; i--) {
        if (Astr[i] == '>') {
            if (ss8(Astr.substr(i + 1, Alenstr))) {
                Astr = Astr.erase(i - 2, Alenstr + 3);
                break;
            }
        }
        if (i == 0) {
            if (ss8(Astr.substr(i, Alenstr))) {
                Astr = Astr.erase(i, Alenstr + 3);
            }
        }
        if (Astr[i] >= '0' && Astr[i] <= '9') Alenstr++;
        if (Astr[i] == '<' || Astr[i] == ',') Alenstr = 0;
    }
    cout << "Удаление последнего числа 8сс: " << Astr << '\n';
    fwrite(path2, "Удаление последнего числа 8сс: ");
    fwrite(path2, Astr);
    fwrite(path2, '\n');

    //Функция для string в char*
    char* D = new char[Astr.size()];
    strcpy(D, Astr.c_str());
    cout << "String в char* : " << D << '\n';

    //127, 192

    // Очистка памяти
    for (int i = 0; i < Bkol; i++) {
        delete[] Bleksems[i];
    }
    for (int i = 0; i < Akol; i++) {
        delete[] Aleksems[i];
    }
    delete[] Bleksems;
    delete[] Aleksems;
    delete[] Aint;
    delete[] A;
    delete[] B;
    delete[] razd;

    return 0;
}
