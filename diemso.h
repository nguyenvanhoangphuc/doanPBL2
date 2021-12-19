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
    float gettoan();
    float getly();
    float gettin();
    float gettriet();
    float getanhVan();
    float getdtb();
    int gethocBong();
    void settoan(float);
    void setly(float );
    void settin(float );
    void settriet(float );
    void setanhVan(float );
    void setdtb(float );
    void sethocBong(int );
}; 