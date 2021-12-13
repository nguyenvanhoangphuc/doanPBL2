#pragma once
#include "sinhvien.h"
#include "cackhoa.h"

class cackhoa;
class danhsachsinhvien
{
private:
    int soLuongSV;
    SinhVien *list;
public:
    danhsachsinhvien();
    danhsachsinhvien(const danhsachsinhvien &);
    ~danhsachsinhvien();
    void tinhDTBvaHB();
    void Nhaptufile();
    void Xuat();
    void themSV();
    void timKiemSV();
    int getsoLuongSV();
    int tktheomaSV(string);
    danhsachsinhvien &tktheohoTen(string);
    danhsachsinhvien &tktheolop(string);
    danhsachsinhvien &tktheomaKhoa(string);
    danhsachsinhvien &tktheohocBong(bool);
    danhsachsinhvien &tktheogioiTinh(bool);
    danhsachsinhvien &tklonhondtb(float);
    danhsachsinhvien &tknhohondtb(float);
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