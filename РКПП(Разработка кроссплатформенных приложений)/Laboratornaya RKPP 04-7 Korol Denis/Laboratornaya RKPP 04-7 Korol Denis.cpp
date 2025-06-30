#include "Header.h"

int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    Dlist<internet_service> lst;
    internet_service a1, a2, a3;

    do {
        system("cls");
        cout << "Menu:"
            "\n1: Push head "
            "\n2: Push back "
            "\n3: Push index "
            "\n4: Pop head "
            "\n5: Pop back "
            "\n6: Pop index "
            "\n7: Clear "
            "\n8: List sort "
            "\n9: Read from file "
            "\n10: Write in file " 
            "\n11: Exit \n\n";
        lst.print();
        cout << "\nChoose the number: ";
        cin >> n;
        switch (n)
        {
        case 1:
            try {
                cout << "Head:\n";
                cin >> a1;
                lst.push_head(a1);
            }
            catch(...){
                cout << "Error\n";
                system("pause");

            }
            break;
        case 2:
            try {
            cout << "Back:\n";
            cin >> a2;
            lst.push_back(a2);
            }
            catch (...) {
                cout << "Error\n";
                system("pause");

            }
            break;    
        case 3:
            try {
            int b3;
            cout << "Element:\n";
            cin >> a3;
            cout << "Index = ";
            cin >> b3;
            lst.push_ind(a3, b3 - 1);
            }
            catch (out_of_range) {
                cout << "Error\n";
                system("pause");
            }
            break;
        case 4:
            try {
            lst.pop_head();
            }
            catch (...) {
                cout << "Error\n";
                system("pause");
            }
            break;
        case 5:
            try {
            lst.pop_back();
            }
            catch (...) {
                cout << "Error\n";
                system("pause");
            }
            break;
        case 6:
            try {
            int b6;
            cout << "Index = ";
            cin >> b6;
            lst.pop_ind(b6 - 1);
            }
            catch (out_of_range) {
                cout << "Error\n";
                system("pause");
            }
            break;
        case 7:
            try {
            lst.clear();
            }
            catch (...) {
                cout << "Error\n";
                system("pause");
            }
            break;
        case 8:
            try {
            lst.list_sort();
            }
            catch (...) {
                cout << "Error\n";
                system("pause");
            }
            break;
        case 9:
            lst.fread("Read1.txt");
            break;
        case 10:
            for (int i = 0; i < lst.Get_Size(); i++) {
                try {
                fwrite("Write1.txt", i + 1);
                fwrite("Write1.txt", ": ");
                fwrite("Write1.txt", lst[i]);
                }
                catch (runtime_error) {
                    cout << "Error\n";
                    system("pause");
                }
            }
            break;
        case 11:
            break;
        default:
            cout << "Error\n";
            break;
        }
    } while (n != 11);
}
