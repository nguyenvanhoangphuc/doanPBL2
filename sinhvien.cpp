#include "sinhvien.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
SinhVien::SinhVien(string maSV, string hoTen, string ngaySinh, bool gioiTinh, string lop,
                    string sdt, string maKhoa, string queQuan) {
    this->maSV=maSV;
    this->hoTen=hoTen;
    this->ngaySinh=ngaySinh; 
    this->gioiTinh=gioiTinh; 
    this->lop=lop;      
    this->sdt=sdt; 
    this->maKhoa=maKhoa; 
    this->queQuan=queQuan; 
}

void SinhVien::Xuat()
{
    cout<<setw(11)<<maSV<<setw(25)<<hoTen<<setw(16)<<ngaySinh<<setw(8)
    <<(gioiTinh?"Nam":"Nu")<<setw(8)<<lop<<setw(16)<<sdt<<setw(13)<<maKhoa<<setw(20)<<queQuan; 
    diem.Xuat(); 
}

void SinhVien::Nhap() {
    cout << "\t\t\tNhap ma sinh vien: ";
    getline(cin>>ws, maSV);
    cout << "\t\t\tNhap ho ten sinh vien: ";
    getline(cin>>ws, hoTen);
    cout << "\t\t\tNhap nam sinh: ";
    getline(cin>>ws, ngaySinh);
    cout << "\t\t\tNhap gioi tinh (Nam:1 ; Nu:0) : ";
    cin >> gioiTinh;
    cout << "\t\t\tNhap lop: ";
    getline(cin>>ws, lop);
    cout << "\t\t\tNhap so dien thoai: ";
    getline(cin>>ws, sdt);
    cout << "\t\t\tNhap ma khoa: ";
    getline(cin>>ws, maKhoa);
    cout << "\t\t\tNhap que quan: ";
    getline(cin>>ws, queQuan);
    cout<<"Sinh vien hien chua co diem. Ban co muon nhap diem khong? (Y,N)"; 
    char choice; cin>>choice; 
    if (choice=='Y'||choice=='y') {
        cout << "\t\t\tNhap diem toan: ";
        cin >> diem.toan;
        cout << "\t\t\tNhap diem ly: ";
        cin >> diem.ly;
        cout << "\t\t\tNhap diem tin: ";
        cin >> diem.tin;
        cout << "\t\t\tNhap diem triet: ";
        cin >> diem.triet;
        cout << "\t\t\tNhap diem anh van: ";
        cin >> diem.anhVan;
    }
    fstream fileOut, fileOut1;
    fileOut.open("txtsinhvien.txt", ios::app | ios::out);
    fileOut1.open("txtdiemso.txt", ios::app | ios::out);
    fileOut << maSV << "," << hoTen << "," << ngaySinh << "," << gioiTinh << "," << lop << "," 
    << sdt << "," << maKhoa << "," << queQuan << endl;
    fileOut1 << maSV << "," << diem.toan << "," << diem.ly << "," << diem.tin << "," 
    << diem.triet << "," << diem.anhVan << endl;
    fileOut.close();
    fileOut1.close();
}
string SinhVien::xepLoai() {
    if (diem.dtb>=8.5) return "gioi";
    if (diem.dtb>=7) return "kha";
    if (diem.dtb>=5) return "tbinh";
    return "yeu"; 
}