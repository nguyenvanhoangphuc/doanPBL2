#pragma once
#include <iostream>
#include "diemso.h"
using namespace std;

class SinhVien
{
    string maSV, hoTen, ngaySinh, lop, sdt, maKhoa, queQuan;
    bool  gioiTinh; 
    diemso diem; 
public:
    SinhVien(string = "No", string  = "No", string  = "No", bool =0, string  = "No",
                     string  = "No", string  = "No", string  = "No"); 
    ~SinhVien() {} 
    void Xuat(); 
    void Nhap(); 
    friend class danhsachsinhvien; 
};
