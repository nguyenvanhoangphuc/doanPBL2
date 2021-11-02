#include "danhsachsinhvien.h"
#include "sinhvien.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

//danh sach ban dau so luong sv la 0 va co vung nho la 1000 sinh vien
danhsachsinhvien::danhsachsinhvien() {   
    this->soLuongSV=0; 
    this->list=new SinhVien[1000]; 
}
danhsachsinhvien::~danhsachsinhvien() {
    delete list; 
}
void danhsachsinhvien::Nhaptufile() {
    string line,tempString;
    ifstream fileIn,fileIn1; 
    fileIn.open("txtsinhvien.txt",ios::in); 
    fileIn1.open("txtdiemso.txt",ios::in); 
    while (!fileIn.eof()) {
        getline(fileIn, line);
        cout<<line<<endl; 
        stringstream ss(line);
        getline(ss, list[soLuongSV].maSV, ',');
        if (list[soLuongSV].maSV.empty())
            break;
        getline(ss, list[soLuongSV].hoTen, ',');
        getline(ss, list[soLuongSV].ngaySinh, ',');
        //gioi tinh 
        getline(ss, tempString, ',');
        list[soLuongSV].gioiTinh=stod(tempString);
        getline(ss, list[soLuongSV].lop, ',');
        getline(ss, list[soLuongSV].sdt, ',');
        getline(ss, list[soLuongSV].maKhoa, ',');
        getline(ss, list[soLuongSV].queQuan, ',');
        cout<<list[soLuongSV].maSV<<endl; 
        
        getline(fileIn1, line);
        cout<<line<<endl;
        stringstream cc(line);
        getline(cc, tempString, ',');
        getline(cc, tempString, ',');
        list[soLuongSV].diem.toan = stod(tempString);
        getline(cc, tempString, ',');
        list[soLuongSV].diem.ly = stod(tempString);
        getline(cc, tempString, ',');
        list[soLuongSV].diem.tin = stod(tempString);
        getline(cc, tempString, ',');
        list[soLuongSV].diem.triet = stod(tempString);
        getline(cc, tempString, ',');
        list[soLuongSV].diem.anhVan = stod(tempString);
        soLuongSV++;
    }
    fileIn.close(); 
    fileIn1.close(); 
}
void danhsachsinhvien::Xuat() {
    // system("cls");
    cout << setw(4) << "STT" << setw(11) << "Ma SV" << setw(25) << "Ho va ten" << setw(16) << "Nam sinh" 
    << setw(8) << "Gtinh" << setw(8) << "Lop" << setw(16) << "SDT" << setw(13) << "Ma khoa" << setw(20) 
    << "Que quan" << setw(6) << "Toan" << setw(6) << "Ly" << setw(6) << "Tin" << setw(8) << "Triet" 
    << setw(6) << "AV" << setw(6) << "DTB" << setw(12) << "Hoc bong" << endl;
    for (int i = 0; i < soLuongSV; i++)
    {
        cout << setw(4) << i + 1;
        list[i].Xuat();
    }
    system("pause");
}
void danhsachsinhvien::themSV() {
    list[soLuongSV].Nhap();
    soLuongSV++; 
}