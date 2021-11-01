#include "danhsachsinhvien.h"
#include "sinhvien.h"


danhsachsinhvien::danhsachsinhvien() {
    this->soLuongSV=0; 
    this->list=nullptr; 
}
danhsachsinhvien::danhsachsinhvien(int soLuongSV) {
    this->soLuongSV=soLuongSV; 
    this->list=new SinhVien[soLuongSV]; 
}