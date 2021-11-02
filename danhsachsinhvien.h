#pragma once
#include "sinhvien.h"
class danhsachsinhvien
{
private:
    int soLuongSV; 
    SinhVien *list;
public:
    danhsachsinhvien();
    ~danhsachsinhvien(); 
    void Nhaptufile(); 
    void Xuat(); 
    void themSV(); 
}; 