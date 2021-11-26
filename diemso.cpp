#include "diemso.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
diemso::diemso(float toan,float ly,float tin,float triet,float anhVan,float dtb,int hocBong) {
    this->toan=toan; 
    this->ly=ly; 
    this->tin=tin; 
    this->triet=triet; 
    this->anhVan=anhVan; 
    this->dtb=dtb; 
    this->hocBong=hocBong; 
}
void diemso::Xuat() {
    // tinhDTBvaHB(); 
    cout<<setw(6)<<toan<<setw(6)<<ly<<setw(6)<<tin<<setw(8)<<triet<<setw(6)<<anhVan
    <<setw(6)<<dtb<<setw(12)<<hocBong<<endl; 
}
bool diemso::tinhDTBvaHB() {
    int i=0; 
    dtb=(toan + ly + tin + triet + anhVan) / 5;
    if (dtb >= 8)
        hocBong = 200,i=1;
    else if (dtb >= 7)
        hocBong = 100,i=1;
    else
        hocBong = 0;
    return i; 
}
diemso &diemso::operator=(const diemso &x) {
    this->toan=x.toan; 
    this->ly=x.ly; 
    this->tin=x.tin; 
    this->triet=x.triet; 
    this->anhVan=x.anhVan; 
    this->dtb=x.dtb; 
    this->hocBong=x.hocBong;
    return *this; 
}