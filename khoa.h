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
    string getmaKhoa(); 
    string gettenKhoa(); 
    string getnguoiQuanLi(); 
    int getsoCanBo(); 
    int getsoSinhVien(); 
    int getnamThanhLap();    
    void setmaKhoa(string); 
    void settenKhoa(string ); 
    void setnguoiQuanLi(string); 
    void setsoCanBo(int); 
    void setsoSinhVien(int); 
    void setnamThanhLap(int);        
};
