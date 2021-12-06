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
    //mặc định
    cackhoa();
    //ham huy
    ~cackhoa();
    //nhập tất cả từ file thongke.txt riêng số sinh viên phải được tính từ file sinhvien.txt
    void enterFromFile();
    //tính số sinh viên của các khoa
    void tinhSoSV(danhsachsinhvien &);
    //xuất danh sach cac khoa hiện đang có trong trường
    void Xuat();
    int getsoLuongKHoa();
    string getmaKhoa(int);
    int getsoSinhVien(int);
    string gettenKhoa(int);
    //tim kiem khoa dua tren mã khoa được truyền vào.
    khoa &tkKhoa(string);
};