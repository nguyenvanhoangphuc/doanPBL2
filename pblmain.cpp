#include "danhsachsinhvien.h"
#include "sinhvien.h"
#include "diemso.h"
#include "cackhoa.h"
#include "khoa.h"
#include "danhsachsinhvien.cpp"
#include "sinhvien.cpp"
#include "diemso.cpp"
#include "cackhoa.cpp"
#include "khoa.cpp"

#include <iostream>
#include <iomanip>
using namespace std;
void menu();
danhsachsinhvien DS;
cackhoa CK;
int main()
{
    cout << left;
    DS.Nhaptufile();
    DS.tinhDTBvaHB();
    CK.enterFromFile();
    CK.tinhSoSV(DS);
    do
    {
        menu();
        int choice;
        char x;
        cout << "\t\t\tNhap lua chon cua ban: ";
        do
        {
            cin >> choice;
            if (choice >= 0 && choice <= 8)
                break;
            else
                cout << "\t\t\tKhong hop le. Nhap lai: ";
        } while (1);
        switch (choice)
        {
        case 0:
            return (0);
        case 1:
            do
            {
                DS.themSV();
                cout << "\n\t\t\tThem sinh vien khac (Y,N): ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            break;
        case 2:
            DS.Xuat();
            break;
        case 3:
            DS.timKiemSV();
            break;
        case 4:
            DS.sapXepSV();
            break;
        case 5:
            DS.suaSV();
            break;
        case 6:
            DS.xoaSV();
            break;
        case 7:
            DS.thongKeSV(CK);
            break;
        case 8:
            CK.Xuat();
            break;
        default:
            cout << "\n\t\t\tLua chon khong ton tai...";
            system("pause");
        }
    } while (1);
}
void menu()
{
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| HE THONG QUAN LY SINH VIEN |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. NHAP" << endl;
    cout << "\t\t\t 2. HIEN THI" << endl;
    cout << "\t\t\t 3. TIM KIEM" << endl;
    cout << "\t\t\t 4. SAP XEP" << endl;
    cout << "\t\t\t 5. SUA" << endl;
    cout << "\t\t\t 6. XOA" << endl;
    cout << "\t\t\t 7. THONG KE" << endl;
    cout << "\t\t\t 8. HIEN THI CAC KHOA" << endl;
    cout << "\t\t\t 0. THOAT HE THONG" << endl;
    cout << "\t\t\t---------------------------" << endl;
}
