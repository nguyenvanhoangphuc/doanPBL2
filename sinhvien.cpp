#include "sinhvien.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <string.h>
using namespace std;

bool check_float(string str)
{
    int count = 0;
    if (str[0] == '.')
        return false;
    if (str[str.length() - 1] == '.')
        return false;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
            count++;
        if (count > 1)
            return false;
    }

    for (int i = 0; i < str.length(); i++)
        if ((isdigit(str[i]) == false) && (str[i] != '.'))
            return false;
    return true;
}

bool check_number(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

bool check_char(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == true)
            return false;
    return true;
}

bool check_makhoa(string str)
{
    if ((str.compare("CND")) == 0)
        return true;
    if ((str.compare("CNT")) == 0)
        return true;
    if ((str.compare("CKH")) == 0)
        return true;
    if ((str.compare("DIE")) == 0)
        return true;
    if ((str.compare("DTV")) == 0)
        return true;
    if ((str.compare("HOA")) == 0)
        return true;
    if ((str.compare("KTR")) == 0)
        return true;
    if ((str.compare("QLD")) == 0)
        return true;
    if ((str.compare("XDC")) == 0)
        return true;
    return false;
}

bool check_lop(string str)
{
    if (str.length() < 4)
        return false;
    if (!isdigit(str[0]))
        return false;
    if (!isdigit(str[1]))
        return false;
    if (isdigit(str[2]))
        return false;
    return true;
}

SinhVien::SinhVien(string maSV, string hoTen, string ngaySinh, bool gioiTinh, string lop,
                   string sdt, string maKhoa, string queQuan)
{
    this->maSV = maSV;
    this->hoTen = hoTen;
    this->ngaySinh = ngaySinh;
    this->gioiTinh = gioiTinh;
    this->lop = lop;
    this->sdt = sdt;
    this->maKhoa = maKhoa;
    this->queQuan = queQuan;
}
void SinhVien::tinhDTBvaHB()
{
    diem.tinhDTBvaHB();
}

void SinhVien::Xuat()
{
    cout << setw(11) << maSV << setw(25) << hoTen << setw(16) << ngaySinh << setw(8)
         << (gioiTinh ? "Nam" : "Nu") << setw(8) << lop << setw(16) << sdt << setw(13) << maKhoa << setw(20) << queQuan;
    diem.Xuat();
}

void SinhVien::Nhap()
{

    string str_temp;

    do
    {
        cout << endl
             << "\t\t\tNhap ma sinh vien (9 chu so): ";
        getline(cin >> ws, maSV);
    } while (!check_number(maSV) || (maSV.length() != 9));

    do
    {
        cout << "\t\t\tNhap ho ten sinh vien: ";
        getline(cin >> ws, hoTen);
    } while (!check_char(hoTen));

    cout << "\t\t\tNhap ngay sinh: ";
    getline(cin >> ws, ngaySinh);

    do
    {
        cout << "\t\t\tNhap gioi tinh (Nam:1 ; Nu:0) : ";
        getline(cin >> ws, str_temp);
    } while (!check_number(str_temp) || (stoi(str_temp) != 1 && stoi(str_temp) != 0));
    gioiTinh = stoi(str_temp);

    do
    {
        cout << "\t\t\tNhap lop (vi du: 20T1, 20DCLC3): ";
        getline(cin >> ws, lop);
    } while (!check_lop(lop));

    do
    {
        cout << "\t\t\tNhap so dien thoai: ";
        getline(cin >> ws, sdt);
    } while (!check_number(sdt));

    do
    {
        cout << "\t\t\tNhap ma khoa (CND, CNT, CKH, DIE, DTV, HOA, KTR, QLD, XDC): ";
        getline(cin >> ws, maKhoa);
    } while (!check_makhoa(maKhoa));

    do
    {
        cout << "\t\t\tNhap que quan: ";
        getline(cin >> ws, queQuan);
    } while (!check_char(queQuan));

    do
    {
        cout << "\t\t\tNhap diem toan (max 10): ";
        getline(cin >> ws, str_temp);
    } while (!check_float(str_temp) || (stod(str_temp) > 10));
    diem.toan = stod(str_temp);

    do
    {
        cout << "\t\t\tNhap diem ly (max 10): ";
        getline(cin >> ws, str_temp);
    } while (!check_float(str_temp) || (stod(str_temp) > 10));
    diem.ly = stod(str_temp);

    do
    {
        cout << "\t\t\tNhap diem tin (max 10): ";
        getline(cin >> ws, str_temp);
    } while (!check_float(str_temp) || (stod(str_temp) > 10));
    diem.tin = stod(str_temp);

    do
    {
        cout << "\t\t\tNhap diem triet (max 10): ";
        getline(cin >> ws, str_temp);
    } while (!check_float(str_temp) || (stod(str_temp) > 10));
    diem.triet = stod(str_temp);

    do
    {
        cout << "\t\t\tNhap diem anh van (max 10): ";
        getline(cin >> ws, str_temp);
    } while (!check_float(str_temp) || (stod(str_temp) > 10));
    diem.anhVan = stod(str_temp);

    fstream fileOut, fileOut1;
    fileOut.open("txtsinhvien.txt", ios::app | ios::out);
    fileOut1.open("txtdiemso.txt", ios::app | ios::out);
    fileOut
        << maSV << "," << hoTen << "," << ngaySinh << "," << gioiTinh << "," << lop << ","
        << sdt << "," << maKhoa << "," << queQuan << endl;
    fileOut1
        << maSV << "," << diem.toan << "," << diem.ly << "," << diem.tin << ","
        << diem.triet << "," << diem.anhVan << endl;
    fileOut.close();
    fileOut1.close();
}
string SinhVien::xepLoai()
{
    if (diem.dtb >= 8.5)
        return "gioi";
    if (diem.dtb >= 7)
        return "kha";
    if (diem.dtb >= 5)
        return "tbinh";
    return "yeu";
}
SinhVien &SinhVien::operator=(const SinhVien &x)
{
    this->maSV = x.maSV;
    this->hoTen = x.hoTen;
    this->ngaySinh = x.ngaySinh;
    this->gioiTinh = x.gioiTinh;
    this->lop = x.lop;
    this->sdt = x.sdt;
    this->maKhoa = x.maKhoa;
    this->queQuan = x.queQuan;
    this->diem = x.diem;
    return *this;
}