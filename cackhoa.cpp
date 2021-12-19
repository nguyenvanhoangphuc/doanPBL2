#include "cackhoa.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

cackhoa::cackhoa()
{
    soLuongKhoa = 0;
    const int MAX_KHOA = 20;
    listKhoa = new khoa[20];
}

cackhoa::~cackhoa()
{
    delete[] listKhoa;
}

void cackhoa::enterFromFile()
{
    string line, tempString;
    ifstream fileIn;
    fileIn.open("txtcackhoa.txt", ios_base::in);
    while (!fileIn.eof())
    {
        getline(fileIn, line);
        stringstream ss(line);
        // getline(ss, listKhoa[soLuongKhoa].getmaKhoa(), ',');
        getline(ss, tempString, ',');
        listKhoa[soLuongKhoa].setmaKhoa(tempString); 
        if (listKhoa[soLuongKhoa].getmaKhoa().empty())
            break;
        getline(ss, tempString, ',');
        listKhoa[soLuongKhoa].settenKhoa(tempString); 
        getline(ss, tempString, ',');
        listKhoa[soLuongKhoa].setnguoiQuanLi(tempString); 
        //gioi tinh
        getline(ss, tempString, ',');
        listKhoa[soLuongKhoa].setsoCanBo(stod(tempString)); 
        getline(ss, tempString, ',');
        listKhoa[soLuongKhoa].setnamThanhLap(stod(tempString));
        soLuongKhoa++;
    }
    fileIn.close();
}
void cackhoa::tinhSoSV(danhsachsinhvien &DS)
{
    // thong ke so nam nu moi khoa
    for (int i = 0; i < getsoLuongKHoa(); i++)
    {
        listKhoa[i].setsoSinhVien(DS.tktheomaKhoa(getmaKhoa(i)).getsoLuongSV()); 
    }
}
void cackhoa::Xuat()
{
    cout << setw(10) << "Ma khoa" << setw(30) << "Ten khoa quan li" << setw(20) << "Ten nguoi quan li"
         << setw(10) << "So CB" << setw(10) << "So SV" << setw(10) << "Nam TL" << endl;
    for (int i = 0; i < soLuongKhoa; i++)
    {
        cout << setw(10) << listKhoa[i].getmaKhoa() << setw(30) << listKhoa[i].gettenKhoa() << setw(20) << listKhoa[i].getnguoiQuanLi()
             << setw(10) << listKhoa[i].getsoCanBo() << setw(10) << listKhoa[i].getsoSinhVien() << setw(10) << listKhoa[i].getnamThanhLap() << endl;
    }
    system("pause");
}
int cackhoa::getsoLuongKHoa()
{
    return soLuongKhoa;
}
string cackhoa::getmaKhoa(int k)
{
    return listKhoa[k].getmaKhoa();
}
string cackhoa::gettenKhoa(int k)
{
    return listKhoa[k].gettenKhoa();
}
int cackhoa::getsoSinhVien(int k)
{
    return listKhoa[k].getsoSinhVien();
}