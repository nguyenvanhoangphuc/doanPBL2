#include <iostream>
using namespace std;
#ifndef SINHVIEN_H
#define SINHVIEN_H
class SinhVien
{
    string maSV, hoTen, ngaySinh, lop, sdt, maKhoa, queQuan;
    bool  gioiTinh; 
public:
    SinhVien(string = "No", string  = "No", string  = "No", bool =0, string  = "No",
                     string  = "No", string  = "No", string  = "No");
    ~SinhVien() {}
    void Xuat();
    void Nhap(); 
};
#endif