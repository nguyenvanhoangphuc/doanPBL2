#include "sinhvien.h"
#include <iostream>
#include <iomanip>
using namespace std;
SinhVien::SinhVien(string masv, string hoten, string namsinh, string gioitinh, string lop, string sdt, string makhoa, string quequan, float toan, float ly, float tin, float triet, float av) : masv(masv), hoten(hoten), namsinh(namsinh), gioitinh(gioitinh), lop(lop), sdt(sdt), makhoa(makhoa), quequan(quequan), toan(toan), ly(ly), tin(tin), triet(triet), av(av), dtb(dtb)
{
    dtb = (toan + ly + tin + triet + av) / 5;
    if (dtb >= 8)
        hb = 200;
    else if (dtb >= 7)
        hb = 100;
    else
        hb = 0;
}

void SinhVien::Xuat()
{
    cout << setw(11) << masv << setw(25) << hoten << setw(16) << namsinh << setw(8) << gioitinh << setw(8) << lop << setw(16) << sdt << setw(13) << makhoa << setw(15) << quequan << setw(6) << toan << setw(6) << ly << setw(6) << tin << setw(8) << triet << setw(6) << av << setw(6) << dtb << setw(12) << hb << endl;
}