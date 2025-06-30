#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;

void vivod(string name, int* A, int a) {
    cout << name << ": ";
    for (int i = 0; i < a; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));
    int* A, *B, *C;
    int a, b, c, n = 0, k = 0;
    cout << "Введите размер массива a и b:";
    cin >> a >> b;
    A = new int[a];
    for (int i = 0; i < a; i++) {
        A[i] = rand() % 100;
    }
    sort(A, A + a);
    B = new int[b];
    for (int i = 0; i < b; i++) {
        B[i] = rand() % 100;
    }
    sort(B, B + b);
    vivod("A", A, a);
    vivod("B", B, b);
    c = a + b;
    C = new int[c];
    __asm {
        mov ecx, c

        ckl1:
        mov esi, A
        add esi, n
        mov eax, [esi]
        mov esi, B
        add esi, k
        mov ebx, [esi]
        cmp eax, ebx
        jle pr1

        push ebx
        add k, 4
        sub b, 1
        mov ebx, b
        cmp ebx, 0
        jz konb
        jmp izb2

        pr1:
        push eax
        add n, 4
        sub a, 1
        mov eax, a
        cmp eax, 0
        jz kona

        izb2:
        loop ckl1

        konb:
        sub ecx, 1
        posl:
        mov esi, A
        add esi, n
        mov eax, [esi]
        push eax
        add n, 4
        loop posl
        jmp izba

        kona:
        sub ecx, 1
        posl1:
        mov esi, B
        add esi, k
        mov eax, [esi]
        push eax
        add k, 4
        loop posl1
        izba:

        mov esi, C
        mov ecx, c
        sub ecx, 1
        imul ecx, 4
        add esi, ecx
        mov ecx, c
        
        zapC:
        pop dword ptr[esi]
        sub esi, 4
        loop zapC
    }
    vivod("C", C, c);
    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
