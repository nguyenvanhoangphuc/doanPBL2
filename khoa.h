#pragma once
#include <iostream>
using namespace std; 
class khoa
{
private:
    string maKhoa, tenKhoa, nguoiQuanLi; 
    int soCanBo, soSinhVien, namThanhLap; 
public:
    khoa();                 //mặc định 
    khoa(const khoa &);     //sao chép     
    friend class cackhoa;           
};
