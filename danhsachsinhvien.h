#pragma once
#include "sinhvien.h"
#include "cackhoa.h"
class danhsachsinhvien
{
private:
    int soLuongSV; 
    SinhVien *list;
public:
    danhsachsinhvien();
    // danhsachsinhvien(int);   
    danhsachsinhvien(const danhsachsinhvien &);
    ~danhsachsinhvien(); 
    void tinhDTBvaHB();
    int getsoLuongSV(); 
    void Nhaptufile(); 
    void Xuat(); 
    void themSV(); 
    void timKiemSV(); 
    SinhVien &tktheomaSV(string); 
    danhsachsinhvien &tktheohoTen(string); 
    danhsachsinhvien &tktheolop(string); 
    danhsachsinhvien &tktheomaKhoa(string);
    danhsachsinhvien &tktheohocBong(bool);
    danhsachsinhvien &tktheogioiTinh(bool); 
    danhsachsinhvien &tktheodtb(float); 
    void sapXepSV(); 
    void sxtheomaSV();
    void sxtheohoTen(); 
    void sxtheolop(); 
    void sxtheoqueQuan();
    void sxtheodtb();
    void suaSV(); 
    void xoaSV(); 
    void xoaSVtheomaSV(string);
    void thongKeSV(cackhoa &); 
    int demgioiTinh(bool);
    int demxepLoai(string);
    int demhocBong(int);
}; 