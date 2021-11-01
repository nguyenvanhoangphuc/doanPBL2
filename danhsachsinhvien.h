#include "sinhvien.h"
class danhsachsinhvien
{
private:
    int soLuongSV; 
    SinhVien *list;
public:
    danhsachsinhvien();
    danhsachsinhvien(int);
    ~danhsachsinhvien(); 
    void Nhap(); 
    void Xuat(); 
}; 