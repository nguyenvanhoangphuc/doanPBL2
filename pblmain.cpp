#include "danhsachsinhvien.h"
#include "sinhvien.h"
#include "diemso.h"
#include "cackhoa.h"
#include "sinhvien.cpp"
#include "danhsachsinhvien.cpp"
#include "cackhoa.cpp"
#include "diemso.cpp"
#include <iostream>
#include <iomanip>
using namespace std; 
void menu(); 
int main() {
    cout<<left; 
    danhsachsinhvien DS;
    DS.Nhaptufile(); 
    DS.Xuat(); 
    do { 
        menu(); 
        int choice;
        char x;
        cout << "Enter Your Choose: ";    
        do {cin >> choice; if (choice>=0&&choice<=7) break;
        else cout<<"Khong hop le. Nhap lai: "; } while (1); 
        switch (choice)
        {
        case 0:exit(0);
        case 1:
            do {
                DS.themSV(); 
                cout << "\n\t\t\tThem sinh vien khac (Y,N): ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            break;
        case 2:DS.Xuat(); break;
        case 3:DS.timKiemSV(); break; 
        case 4:DS.sapXepSV(); break; 
        case 5:DS.suaSV(); break; 
        case 6:DS.xoaSV(); break; 
        case 7:DS.thongKeSV(); break; 
        default:
            cout << "\n\t\t\tLua chon khong ton tai...";
            system("pause");
        }
    } while(1); 
}
void menu() {
    // system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| HE THONG QUAN LY SINH VIEN |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Nhap sinh vien" << endl;
    cout << "\t\t\t 2. Hien thi sinh vien" << endl;
    cout << "\t\t\t 3. Tim kiem sinh vien" << endl;
    cout << "\t\t\t 4. Sap xep sinh vien" << endl;
    cout << "\t\t\t 5. Sua danh sach sinh vien" << endl;
    cout << "\t\t\t 6. Xoa sinh vien" << endl;
    cout << "\t\t\t 7. Thong ke sinh vien" << endl;
    cout << "\t\t\t 0. Thoat chuong trinh" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChon chuc nang:" << endl;
    cout << "\t\t\t---------------------------" << endl;
}   
    
