#pragma once
#include <iostream>
#include "khoa.h"
#include "danhsachsinhvien.h"
using namespace std;

class danhsachsinhvien;
class cackhoa   
{
private:
    int soLuongKhoa;
    khoa *listKhoa;
public:
    cackhoa();
    ~cackhoa();
    void enterFromFile();
    void tinhSoSV(danhsachsinhvien &);
    void Xuat();
    int getsoLuongKHoa();
    int getsoSinhVien(int);
    string getmaKhoa(int);
    string gettenKhoa(int);
    khoa &tkKhoa(string);
};