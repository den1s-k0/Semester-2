#include <iostream>
extern "C" int main_asm(long long a1, long long b1, long long c1, long long x1, long long* prov1);
extern "C" int mainprov(long long a1, long long b1, long long c1, long long x1, long long* prov1);

using namespace std;

void Dop() {
    long long a, b, c, x, perem, prov = 1;
    long long resultASM = 0, resultC = 0;
    cout << "\n4 Байта\nВведите a, b, c, x: ";
    cin >> a >> b >> c >> x;
    //Y=(12x*c+b3 +4/c +ax3 /2x)/ (3x2 –b/a )
    resultASM = main_asm(a, b, c, x, &prov);
    prov = mainprov(a, b, c, x, &prov);
    if (prov == 1) {
        resultC = ((12 * x * c) + (b * b * b) + (4 / c) + ((a * x * x * x) / (2 * x))) / ((3 * x * x) - (b / a));
        cout << "C++ = " << resultC << "\nASM = " << resultASM << '\n';
    }
    if (prov == 0) cout << "Деление на ноль\n";
    if (prov == 2) cout << "Переполнение\n";
}

int main()
{
    setlocale(LC_ALL, "rus");
    Dop();
}
