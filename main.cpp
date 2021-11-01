#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "sinhvien.h"
#include <iomanip>
void themsv(SinhVien *DSSV[], int &n);
void hienthisv(SinhVien *DSSV[], int n);
int main()
{
    string masv, hoten, namsinh, gioitinh, lop, sdt, makhoa, quequan, tempString;
    float toan, ly, tin, triet, av, dtb;
    int hb;
    string line;
    SinhVien *DSSV[1000];
    int n = 0;
    fstream file, file1;
    file.open("sinhvien.txt", ios::in);
    file1.open("diem.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        stringstream ss(line);
        getline(ss, masv, ',');
        if (masv.empty())
            break;
        getline(ss, hoten, ',');
        getline(ss, namsinh, ',');
        getline(ss, gioitinh, ',');
        getline(ss, lop, ',');
        getline(ss, sdt, ',');
        getline(ss, makhoa, ',');
        getline(ss, quequan, ',');
        getline(file1, line);
        stringstream cc(line);
        getline(cc, tempString, ',');
        getline(cc, tempString, ',');
        toan = stod(tempString);
        getline(cc, tempString, ',');
        ly = stod(tempString);
        getline(cc, tempString, ',');
        tin = stod(tempString);
        getline(cc, tempString, ',');
        triet = stod(tempString);
        getline(cc, tempString, ',');
        av = stod(tempString);
        DSSV[n++] = new SinhVien(masv, hoten, namsinh, gioitinh, lop, sdt, makhoa, quequan, toan, ly, tin, triet, av);
    }
    file.close();
    file1.close();

menustart:
    int choice;
    char x;

    system("cls");

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| HE THONG QUAN LY SINH VIEN |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Nhap sinh vien" << endl;
    cout << "\t\t\t 2. Hien thi sinh vien" << endl;
    cout << "\t\t\t 0. Thoat chuong trinh" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChon chuc nang:" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;

    switch (choice)
    {
    case 0:
        exit(0);
    case 1:
        do
        {
            themsv(DSSV, n);
            cout << "\n\t\t\t Them sinh vien khac (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        hienthisv(DSSV, n);
        break;
    default:
        cout << "\n\t\t\tLua chon khong ton tai...";
        system("pause");
    }
    goto menustart;
}

void themsv(SinhVien *DSSV[], int &n)
{
    string masv, hoten, namsinh, gioitinh, lop, sdt, makhoa, quequan, tempString;
    float toan, ly, tin, triet, av;
    fstream file, file1;

    system("cls");
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- THEM SINH VIEN ---------------------------------------------" << endl;
    getline(cin, tempString);
    cout << "\t\t\tNhap ma sinh vien: ";
    getline(cin, masv);
    cout << "\t\t\tNhap ho ten sinh vien: ";
    getline(cin, hoten);
    cout << "\t\t\tNhap nam sinh: ";
    getline(cin, namsinh);
    cout << "\t\t\tNhap gioi tinh: ";
    getline(cin, gioitinh);
    cout << "\t\t\tNhap lop: ";
    getline(cin, lop);
    cout << "\t\t\tNhap so dien thoai: ";
    getline(cin, sdt);
    cout << "\t\t\tNhap ma khoa: ";
    getline(cin, makhoa);
    cout << "\t\t\tNhap que quan: ";
    getline(cin, quequan);
    cout << "\t\t\tNhap diem toan: ";
    cin >> toan;
    cout << "\t\t\tNhap diem ly: ";
    cin >> ly;
    cout << "\t\t\tNhap diem tin: ";
    cin >> tin;
    cout << "\t\t\tNhap diem triet: ";
    cin >> triet;
    cout << "\t\t\tNhap diem anh van: ";
    cin >> av;
    DSSV[n++] = new SinhVien(masv, hoten, namsinh, gioitinh, lop, sdt, makhoa, quequan, toan, ly, tin, triet, av);
    file.open("sinhvien.txt", ios::app | ios::out);
    file1.open("diem.txt", ios::app | ios::out);
    file << masv << "," << hoten << "," << namsinh << "," << gioitinh << "," << lop << "," << sdt << "," << makhoa << "," << quequan << endl;
    file1 << masv << "," << toan << "," << ly << "," << tin << "," << triet << "," << av << endl;
    file.close();
    file1.close();
}

void hienthisv(SinhVien *DSSV[], int n)
{
    system("cls");
    cout << setw(3) << "STT" << setw(11) << "Ma SV" << setw(25) << "Ho va ten" << setw(16) << "Nam sinh" << setw(8) << "Gtinh" << setw(8) << "Lop" << setw(16) << "SDT" << setw(13) << "Ma khoa" << setw(15) << "Que quan" << setw(6) << "Toan" << setw(6) << "Ly" << setw(6) << "Tin" << setw(8) << "Triet" << setw(6) << "AV" << setw(6) << "DTB" << setw(12) << "Hoc bong" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << i + 1;
        DSSV[i]->Xuat();
    }

    system("pause");
}
