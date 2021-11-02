#pragma once
class diemso {
private:
    float toan, ly, tin, triet, anhVan, dtb;
    int hocBong;
public: 
    diemso(float=0,float=0,float=0,float=0,float=0,float=0,int=0);
    void tinhDTBvaHB(); 
    void Nhaptufile(); 
    void Xuat();  
    friend class SinhVien;
    friend class danhsachsinhvien; 
}; 