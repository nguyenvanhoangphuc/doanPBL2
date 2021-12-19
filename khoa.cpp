#include "khoa.h"

khoa::khoa():maKhoa("NO"),tenKhoa("NO"),nguoiQuanLi("NO"),soCanBo(0),soSinhVien(0),namThanhLap(0) {    
} 
string khoa::getmaKhoa() {
    return this->maKhoa; 
}
string khoa::gettenKhoa() {
    return this->tenKhoa; 
} 
string khoa::getnguoiQuanLi() {
    return this->nguoiQuanLi; 
} 
int khoa::getsoCanBo() {
    return this->soCanBo; 
}
int khoa::getsoSinhVien() {
    return this->soSinhVien; 
}
int khoa::getnamThanhLap() {
    return this->namThanhLap; 
}  
void khoa::setmaKhoa(string s) {
    this->maKhoa=s; 
}
void khoa::settenKhoa(string s) {
    this->tenKhoa=s; 
}
void khoa::setnguoiQuanLi(string s) {
    this->nguoiQuanLi=s; 
}
void khoa::setsoCanBo(int x) {
    this->soCanBo=x; 
}
void khoa::setsoSinhVien(int x) {
    this->soSinhVien=x; 
}
void khoa::setnamThanhLap(int x) {
    this->namThanhLap=x; 
}   