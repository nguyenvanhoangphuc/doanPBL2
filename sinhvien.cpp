#include "sinhvien.h"
#include <iostream>
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
    cout<<setw(10)<<maSV<<setw(30)<<hoTen<<setw(15)<<ngaySinh<<setw(7)<<gioiTinh
    <<setw(10)<<lop<<setw(14)<<sdt<<setw(10)<<maKhoa<<setw(30)<<queQuan<<endl; 
}