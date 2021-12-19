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
    void tinhDTBvaHB();
    void Xuat(); 
    void Nhap(); 
    string xepLoai(); 
    SinhVien &operator=(const SinhVien &); 
    string getmaSV(); 
    string gethoTen(); 
    string getngaySinh();
    string getlop(); 
    string getsdt();
    string getmaKhoa(); 
    string getqueQuan();
    diemso getdiem(); 
    bool getgioiTinh(); 
    void setmaSV(string s); 
    void sethoTen(string s); 
    void setngaySinh(string s);
    void setlop(string s); 
    void setsdt(string s);
    void setmaKhoa(string s); 
    void setqueQuan(string s);
    void setgioiTinh(bool);
    void setdiemtoan(int x); 
    void setdiemly(int x); 
    void setdiemtin(int x); 
    void setdiemtriet(int x); 
    void setdiemanhVan(int x); 
};
