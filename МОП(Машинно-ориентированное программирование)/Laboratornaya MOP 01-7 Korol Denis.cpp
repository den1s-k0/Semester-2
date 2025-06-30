#include <iostream>

using namespace std;

//((12 * x * c) + (b * b * b) + (4 / c) + ((a * x * x * x) / (2 * x))) / ((3 * x * x) - (b / a));
void CASE5() {
    unsigned  int  a, b;
    long long result1;
    cout << "\nВведите а и б\n";
    cin >> a >> b;

    _asm
    {
        mov  eax, a
        imul  b
        mov  dword ptr result1 + 4, edx
        mov dword ptr result1, eax
    };
    cout << "\nПроизведение int: " << result1;

}

void CASE6() {
    short  a, b;
    int result1;
    cout << "\nВведите а и б\n";
    cin >> a >> b;

    _asm
    {
        mov  ax, a
        imul  b
        mov  word ptr result1 + 2,dx
        mov word ptr result1, ax
    };
    cout << "\nПроизведение shrot: " << result1;

}

//void CASE4() {
//    long long a, b, c, x, perem, prov = 1;
//    long long resultASM, resultC;
//    cout << "\n4 Байта\nВведите a, b, c, x: ";
//    cin >> a >> b >> c >> x;
//    __asm {
//        mov rax, 12
//        imul x
//        jo per
//        imul c
//        jo per
//        mov resultASM, rax
//
//        mov rax, b
//        imul b
//        jo per
//        imul b
//        jo per
//        add resultASM, rax
//        jo per
//
//        cmp c, 0
//        jz flazok
//
//        mov rax, 4
//        mov rbx, c
//        cqo
//        idiv rbx
//        add resultASM, rax
//        jo per
//
//        mov rax, a
//        imul x
//        jo per
//        imul x
//        jo per
//        imul x
//        jo per
//        mov perem, rax
//
//        cmp x, 0
//        jz flazok
//
//        mov rax, 2
//        imul x
//        jo per
//        mov rbx, rax
//        mov rax, perem
//        cqo
//        idiv rbx
//        add resultASM, rax
//        jo per
//
//        mov rax, 3
//        imul x
//        jo per
//        imul x
//        jo per
//        mov perem, rax
//
//        cmp a, 0
//        jz flazok
//
//        mov rax, b
//        cqo
//        idiv a
//        mov rbx, rax
//        mov rax, perem
//        sub rax, rbx
//        jz flazok
//
//        mov rbx, rax
//        mov rax, resultASM
//        cqo
//        idiv rbx
//        mov resultASM, rax
//
//        jmp vihod
//        flazok :
//        mov prov, 0
//            jmp vihod
//            per :
//        mov prov, 2
//            vihod :
//    }
//    if (prov == 1) {
//        resultC = ((12 * x * c) + (b * b * b) + (4 / c) + ((a * x * x * x) / (2 * x))) / ((3 * x * x) - (b / a));
//        cout << "C++ = " << resultC << "\nASM = " << resultASM << '\n';
//    }
//    if (prov == 0) cout << "Деление на ноль\n";
//    if (prov == 2) cout << "Переполнение\n";
//}

void CASE3() {
    int a, b, c, x, perem, prov = 1;
    int resultASM, resultC;
    cout << "\n4 Байта\nВведите a, b, c, x: ";
    cin >> a >> b >> c >> x;
    __asm {
        mov eax, 12
        imul x
        jo per
        imul c
        jo per
        mov resultASM, eax

        mov eax, b
        imul b
        jo per
        imul b
        jo per
        add resultASM, eax
        jo per

        cmp c, 0
        jz flazok

        mov eax, 4
        mov ebx, c
        cdq
        idiv ebx
        add resultASM, eax
        jo per

        mov eax, a
        imul x
        jo per
        imul x
        jo per
        imul x
        jo per
        mov perem, eax

        cmp x, 0
        jz flazok

        mov eax, 2
        imul x
        jo per
        mov ebx, eax
        mov eax, perem
        cdq
        idiv ebx
        add resultASM, eax
        jo per

        mov eax, 3
        imul x
        jo per
        imul x
        jo per
        mov perem, eax

        cmp a, 0
        jz flazok

        mov eax, b
        cdq
        idiv a
        mov ebx, eax
        mov eax, perem
        sub eax, ebx
        jz flazok

        mov ebx, eax
        mov eax, resultASM
        cdq
        idiv ebx
        mov resultASM, eax

        jmp vihod
        flazok :
        mov prov, 0
        jmp vihod
        per:
        mov prov, 2
        vihod :
    }
    if (prov == 1) {
        resultC = ((12 * x * c) + (b * b * b) + (4 / c) + ((a * x * x * x) / (2 * x))) / ((3 * x * x) - (b / a));
        cout << "C++ = " << resultC << "\nASM = " << resultASM << '\n';
    }
    if (prov == 0) cout << "Деление на ноль\n";
    if (prov == 2) cout << "Переполнение\n";
}

void CASE2(){

    short a, b, c, x, resultASM, resultC, perem, prov = 1;
    cout << "\n2 Байта\nВведите a, b, c, x: ";
    cin >> a >> b >> c >> x;
    __asm {

        mov ax, 12
        imul x
        jo per
        imul c
        jo per
        mov resultASM, ax

        mov ax, b
        imul b
        jo per
        imul b
        jo per
        add resultASM, ax
        jo per

        mov ax, c
        sub ax, 1
        add ax, 1
        jz flazok

        mov ax, 4
        mov bx, c
        cwd
        idiv bx
        add resultASM, ax
        jo per

        mov ax, a
        imul x
        jo per
        imul x
        jo per
        imul x
        jo per
        mov perem, ax

        mov ax, x
        sub ax, 1
        add ax, 1
        jz flazok

        mov ax, 2
        imul x
        jo per
        mov bx, ax
        mov ax, perem
        cwd
        idiv bx
        add resultASM, ax
        jo per

        mov ax, 3
        imul x
        jo per
        imul x
        jo per
        mov perem, ax

        mov ax, a
        sub ax, 1
        add ax, 1
        jz flazok

        mov ax, b
        cwd
        idiv a
        mov bx, ax
        mov ax, perem
        sub ax, bx
        jz flazok

        mov bx, ax
        mov ax, resultASM
        cwd
        idiv bx
        mov resultASM, ax

        jmp vihod
        flazok :
        mov prov, 0
            jmp vihod
            per :
        mov prov, 2
            vihod :
    }
    if (prov == 1) {
        resultC = ((12 * x * c) + (b * b * b) + (4 / c) + ((a * x * x * x) / (2 * x))) / ((3 * x * x) - (b / a));
        cout << "C++ = " << resultC << "\nASM = " << resultASM << '\n';
    }
    if (prov == 0) cout << "Деление на ноль\n";
    if (prov == 2) cout << "Переполнение\n";
}

void CASE1(){
    short a1, b1, c1, x1;
    __int8 a, b, c, x, perem, resultASM;
    short res, resultC, prov = 1;
    cout << "\n1 Байт\nВведите a, b, c, x: ";
    cin >> a1 >> b1 >> c1 >> x1 ;
    a = a1;
    b = b1;
    c = c1;
    x = x1;
    __asm {

        mov al, 12
        imul x
        jo per
        imul c
        jo per
        mov resultASM, al

        mov al, b
        imul b
        jo per
        imul b
        jo per
        add resultASM, al
        jo per

        mov al, c
        sub al, 1
        add al, 1
        jz flazok

        mov al, 4
        mov bl, c
        cbw
        idiv bl
        add resultASM, al
        jo per

        mov al, a
        imul x
        jo per
        imul x
        jo per
        imul x
        jo per
        mov perem, al

        mov al, x
        sub al, 1
        add al, 1
        jz flazok

        mov al, 2
        imul x
        jo per
        mov bl, al
        mov al, perem
        cbw
        idiv bl
        add resultASM, al
        jo per

        mov al, 3
        imul x
        jo per
        imul x
        jo per
        mov perem, al

        mov al, a
        sub al, 1
        add al, 1
        jz flazok

        mov al, b
        cbw
        idiv a
        mov bl, al
        mov al, perem
        sub al, bl
        jz flazok

        mov bl, al
        mov al, resultASM
        cbw
        idiv bl
        mov resultASM, al
        mov res, ax

        jmp vihod
        flazok :
        mov prov, 0
        jmp vihod
        per :
        mov prov, 2
            vihod :
    }
    if (prov == 1) {
        int i = resultASM;
        resultC = ((12 * x * c) + (b * b * b) + (4 / c) + ((a * x * x * x) / (2 * x))) / ((3 * x * x) - (b / a));
        cout << "C++ = " << resultC << "\nASM = " << i;
    }
    if (prov == 0) cout << "Деление на ноль\n";
    if (prov == 2) cout << "Переполнение\n";
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    do{
        cout << "\n1: 1 байт\n"
        << "2: 2 байта\n"
        << "3: 4 байта\n"
        << "5: Использование переполнения int\n"
        << "6: Использование переполнения short\n"
        << "7: Завершение программы\n\nВведите номер: ";
        cin >> n;
        switch (n) {
        case 1:
            CASE1();
            break;
        case 2:
            CASE2();
            break;
        case 3:
            CASE3();
            break;
        //case 4:
        //    CASE4();
        //    break;
        case 5:
            CASE5();
            break;
        case 6:
            CASE6();
            break;
        case 7:
            cout << "Выход из программы " << endl;
            break;
        default:
            cout << "Нет такого типа данных " << endl;
        }
    } while (n != 7);
    return 0;
}
