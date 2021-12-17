#pragma once
#include <iostream>
using namespace std; 
class khoa
{
private:
    string maKhoa, tenKhoa, nguoiQuanLi; 
    int soCanBo, soSinhVien, namThanhLap; 
public:
    khoa();                 
    khoa(const khoa &);         
    friend class cackhoa;           
};
