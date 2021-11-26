#pragma once
class diemso {
private:
    float toan, ly, tin, triet, anhVan, dtb;
    int hocBong;
public: 
    diemso(float=0,float=0,float=0,float=0,float=0,float=0,int=0);
    bool tinhDTBvaHB(); 
    void Nhaptufile(); 
    void Xuat();  
    diemso &operator=(const diemso &); 
    friend class SinhVien;
    friend class danhsachsinhvien; 
}; 