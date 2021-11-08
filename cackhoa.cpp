#include "cackhoa.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

cackhoa::cackhoa() {
    soLuongKhoa=0; 
    const int MAX_KHOA=20; 
    listKhoa=new khoa[20]; 
}

cackhoa::~cackhoa() {
    delete [] listKhoa; 
}

void cackhoa::enterFromFile() {
    string line,tempString; 
    ifstream fileIn; 
    fileIn.open("txtcackhoa.txt",ios_base::in); 
    while (!fileIn.eof()) {
        getline(fileIn, line);
        stringstream ss(line);
        getline(ss, listKhoa[soLuongKhoa].maKhoa, ',');
        if (listKhoa[soLuongKhoa].maKhoa.empty())
            break;
        getline(ss, listKhoa[soLuongKhoa].tenKhoa, ',');
        getline(ss, listKhoa[soLuongKhoa].nguoiQuanLi, ',');
        //gioi tinh 
        getline(ss, tempString, ',');
        listKhoa[soLuongKhoa].soCanBo=stod(tempString);
        getline(ss, tempString, ',');
        listKhoa[soLuongKhoa].namThanhLap=stod(tempString);
        soLuongKhoa++;
    }
    fileIn.close(); 
}
void cackhoa::Xuat() {
    cout<<setw(10)<<"ma khoa"<<setw(30)<<"ten khoa quan li"<<setw(20)<<"Ten nguoi quan li"
    <<setw(10)<<"so can bo"<<setw(10)<<"so Svien"<<setw(10)<<"nam TL"<<endl;
    for (int i=0; i<soLuongKhoa; i++) {
        cout<<setw(10)<<listKhoa[i].maKhoa<<setw(30)<<listKhoa[i].tenKhoa<<setw(20)<<listKhoa[i].nguoiQuanLi
        <<setw(10)<<listKhoa[i].soCanBo<<setw(10)<<listKhoa[i].soSinhVien<<setw(10)<<listKhoa[i].namThanhLap<<endl;
    }
    system("pause");
}
int cackhoa::getsoLuongKHoa() {
    return soLuongKhoa;
} 
string cackhoa::getmaKhoa(int k) {
    return listKhoa[k].maKhoa; 
}
string cackhoa::gettenKhoa(int k) {
    return listKhoa[k].tenKhoa; 
}