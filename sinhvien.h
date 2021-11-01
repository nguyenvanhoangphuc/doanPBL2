#include <iostream>
using namespace std;
#ifndef SINHVIEN_H
#define SINHVIEN_H
class SinhVien
{
    string masv, hoten, namsinh, gioitinh, lop, sdt, makhoa, quequan;
    float toan, ly, tin, triet, av, dtb;
    int hb;

public:
    SinhVien(string masv, string hoten, string namsinh, string gioitinh, string lop, string sdt, string makhoa, string quequan, float toan, float ly, float tin, float triet, float av);
    ~SinhVien() {}
    void Xuat();
};
#endif