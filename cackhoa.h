#pragma once
#include <iostream>
#include "khoa.h"
using namespace std;

class cackhoa{
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
    //xuất danh sach cac khoa hiện đang có trong trường
    void Xuat(); 
    //tim kiem khoa dua tren mã khoa được truyền vào.
    khoa &tkKhoa(string); 
};