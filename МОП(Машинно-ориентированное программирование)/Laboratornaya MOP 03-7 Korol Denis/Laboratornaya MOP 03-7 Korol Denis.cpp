# include <iostream>
extern "C" int __cdecl  main_asm(int a1, int b1, int c1, int x1, int *prov1);

using namespace std;

extern "C" int __cdecl  xkub(int a){
    return a * a * a;
}

extern "C" int __cdecl  xkvadr(int a) {
    return a * a;
}

void MOP() {
    int a, b, c, x, prov = 1;
    int resultASM = 0, resultC;
    cout << "\n4 Байта\nВведите a, b, c, x: ";
    cin >> a >> b >> c >> x;
    resultASM = main_asm(a, b, c, x, &prov);

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
    MOP();
	return 0;
}
