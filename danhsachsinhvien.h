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
    void timKiemSV(); 
    SinhVien &tktheomaSV(string); 
    danhsachsinhvien &tktheohoTen(string); 
    danhsachsinhvien &tktheolop(string); 
    danhsachsinhvien &tktheohocBong(bool);
    danhsachsinhvien &tktheogioiTinh(bool); 
    danhsachsinhvien &tktheodtb(float); 
    void sapXepSV(); 
    void suaSV(); 
    void xoaSV(); 
    void thongKeSV(); 
}; 