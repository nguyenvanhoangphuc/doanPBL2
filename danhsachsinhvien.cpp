#include "danhsachsinhvien.h"
#include "sinhvien.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;
bool isdigit(char x) {
    return (x>=48&&x<=57); 
}
long long int Stoi (string str) {
    long long int tong=0; 
    const int ASCII_0 = 48; 
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i])==false) break; 
        tong=tong*10+(str[i]-ASCII_0); 
    }
    return tong; 
}
bool check_float1(string str)  //đã viết thuật toán
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

bool check_number1(string str) //đã viết thuật toán
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

bool check_char1(string str)  //đã viết thuật toán
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == true)
            return false;
    return true;
}

bool check_makhoa1(string str)   //đã viết thuật toán
{
    char xau[][5]= {"CND","CNT","CKH","DIE","DTV","HOA","KTR","QLD","XDC"};
    for (int i=0; i<9; i++) {
        if ((str.compare(xau[i])) == 0)
        return true;
    }
    return false;
}

bool check_lop1(string str)  //đã viết thuật toán
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

string get_last_word(const string &s)
{
    auto index = s.find_last_of(' ');
    return s.substr(++index);
}

//danh sach ban dau so luong sv la 0 va co vung nho la 100 sinh vien
danhsachsinhvien::danhsachsinhvien()
{
    this->soLuongSV = 0;
    const int MAX_SINHVIEN = 100;
    this->list = new SinhVien[MAX_SINHVIEN];
}

danhsachsinhvien::danhsachsinhvien(const danhsachsinhvien &x)
{
    this->soLuongSV = x.soLuongSV;
    this->list = new SinhVien[100];
    for (int i = 0; i < soLuongSV; i++)
    {
        this->list[i] = x.list[i];  
    }
}
danhsachsinhvien::~danhsachsinhvien()
{
    delete[] list;
}
void danhsachsinhvien::tinhDTBvaHB()
{
    for (int i = 0; i < soLuongSV; i++)
    {
        list[i].tinhDTBvaHB();
    }
}
int danhsachsinhvien::getsoLuongSV()
{
    return this->soLuongSV;
}
void danhsachsinhvien::Nhaptufile()
{
    string line, tempString;
    ifstream fileIn, fileIn1;
    fileIn.open("txtsinhvien.txt", ios::in);
    fileIn1.open("txtdiemso.txt", ios::in);
    while (!fileIn.eof())
    {
        getline(fileIn, line);
        stringstream ss(line);
        getline(ss, tempString, ',');
        list[soLuongSV].setmaSV(tempString);
        if (list[soLuongSV].getmaSV().empty())
            break;
        getline(ss, tempString, ',');
        list[soLuongSV].sethoTen(tempString);
        getline(ss, tempString, ',');
        list[soLuongSV].setngaySinh(tempString);
        //gioi tinh
        getline(ss, tempString, ',');
        list[soLuongSV].setgioiTinh(stod(tempString));
        getline(ss, tempString, ',');
        list[soLuongSV].setlop(tempString);
        getline(ss, tempString, ',');
        list[soLuongSV].setsdt(tempString);
        getline(ss, tempString, ',');
        list[soLuongSV].setmaKhoa(tempString);
        getline(ss, tempString, ',');
        list[soLuongSV].setqueQuan(tempString);
        //file diem so
        getline(fileIn1, line);
        stringstream cc(line);
        getline(cc, tempString, ',');
        getline(cc, tempString, ',');
        list[soLuongSV].setdiemtoan(stod(tempString));
        getline(cc, tempString, ',');
        list[soLuongSV].setdiemly (stod(tempString));
        getline(cc, tempString, ',');
        list[soLuongSV].setdiemtin ( stod(tempString));
        getline(cc, tempString, ',');
        list[soLuongSV].setdiemtriet ( stod(tempString));
        getline(cc, tempString, ',');
        list[soLuongSV].setdiemanhVan (stod(tempString));
        soLuongSV++;
    }
    fileIn.close();
    fileIn1.close();
}
void danhsachsinhvien::Xuat()
{
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
void danhsachsinhvien::themSV()
{
    list[soLuongSV].Nhap();
    list[soLuongSV].tinhDTBvaHB();
    cout<<"\nDa them sinh vien vao danh sach."<<endl<<endl; 
    cout<<"Thong tin sinh vien vua nhap: "<<endl; 
    cout << setw(11) << "Ma SV" << setw(25) << "Ho va ten" << setw(16) << "Ngay sinh"
        << setw(8) << "Gtinh" << setw(8) << "Lop" << setw(16) << "SDT" << setw(13) << "Ma khoa" << setw(20)
        << "Que quan" << setw(6) << "Toan" << setw(6) << "Ly" << setw(6) << "Tin" << setw(8) << "Triet"
        << setw(6) << "AV" << setw(6) << "DTB" << setw(12) << "Hoc bong" << endl;
    list[soLuongSV].Xuat(); 
    soLuongSV++;
}
void danhsachsinhvien::timKiemSV()
{
    do
    {
        int chon, tt;
        char choice;
        cout << endl
             << "----------Menu tim kiem-----------" << endl;
        cout << "1. Theo ma so sinh vien.\n";
        cout << "2. Theo ho ten sinh vien.\n";
        cout << "3. Danh sach sinh vien theo lop.\n";
        cout << "4. Danh sach sinh vien co hoc bong.\n";
        cout << "5. Theo gioi tinh.\n";
        cout << "6. Diem trung binh lon hon.\n";
        cout << "7. Diem trung binh nho hon.\n";
        cout << "0. Khong tim kiem nua.\n";
        cout << endl
             << "Lua chon cua ban la : ";
        do
        {
            cin >> chon;
            if (chon >= 0 && chon <= 7)
                break;
        } while (1);
        string masv, hoten, lopp;
        bool b;
        string str_temp;
        string c;
        switch (chon)
        {
        case 1:
            cout << "Nhap ma sinh vien: ";
            cin >> masv;
            tt = tktheomaSV(masv);
            cout << endl
                 << setw(11) << "Ma SV" << setw(25) << "Ho va ten" << setw(16) << "Nam sinh"
                 << setw(8) << "Gtinh" << setw(8) << "Lop" << setw(16) << "SDT" << setw(13) << "Ma khoa" << setw(20)
                 << "Que quan" << setw(6) << "Toan" << setw(6) << "Ly" << setw(6) << "Tin" << setw(8) << "Triet"
                 << setw(6) << "AV" << setw(6) << "DTB" << setw(12) << "Hoc bong" << endl;
            if (tt!=-1) list[tt].Xuat();
            break;
        case 2:
            cout << "Nhap ho ten sinh vien: ";
            getline(cin >> ws, hoten);
            cout << endl;
            tktheohoTen(hoten).Xuat();
            break;
        case 3:
            cout << "Nhap lop cua sinh vien: ";
            getline(cin >> ws, lopp);
            cout << endl;
            tktheolop(lopp).Xuat();
            break;
        case 4:
            cout << "Danh sach co hoc bong hay khong? (Y/N) ";
            getline(cin >> ws, c);
            cout << endl;
            if (c.compare("y") == 0 || c.compare("Y") == 0)
                tktheohocBong(1).Xuat();
            else if (c.compare("N") == 0 || c.compare("n") == 0)
                tktheohocBong(0).Xuat();
            break;
        case 5:
            do
            {
                cout << "Nhap gioi tinh (Nam:1 ; Nu:0) : ";
                getline(cin >> ws, str_temp);
            } while (!check_number1(str_temp) || (stoi(str_temp) != 1 && stoi(str_temp) != 0));
            b = stoi(str_temp);
            tktheogioiTinh(b).Xuat();
            break;
        case 6:
            float dtbb1;
            do
            {
                cout << "Nhap muc diem trung binh: ";
                getline(cin >> ws, str_temp);
            } while (!check_float1(str_temp));

            dtbb1 = stod(str_temp);
            tklonhondtb(dtbb1).Xuat();
            break;
        case 7:
            float dtbb2;
            do
            {
                cout << "Nhap muc diem trung binh: ";
                getline(cin >> ws, str_temp);
            } while (!check_float1(str_temp));

            dtbb2 = stod(str_temp);
            tknhohondtb(dtbb2).Xuat();
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le.";
            break;
        }
        cout << endl
             << "Ban co muon tim kiem tiep ko? (Y,N) ";
        cin >> choice;
        if (choice == 'N' || choice == 'n')
            break;
    } while (1);
}
int danhsachsinhvien::tktheomaSV(string masv)
{
    int i;
    for (i = 0; i < soLuongSV; i++)
    {
        if (list[i].getmaSV() == masv)
            return i;
    }
    return -1;
}
danhsachsinhvien &danhsachsinhvien::tktheohoTen(string hoten)
{
    static danhsachsinhvien temp1;
    temp1.soLuongSV = 0;
    int i;
    for (i = 0; i < soLuongSV; i++)
    {
        if (list[i].gethoTen() == hoten)
        {
            temp1.list[temp1.soLuongSV] = list[i]; //ham gan mat dinh
            temp1.soLuongSV++;
        }
    }
    return temp1;
}
danhsachsinhvien &danhsachsinhvien::tktheolop(string lopp)
{
    static danhsachsinhvien temp2;
    temp2.soLuongSV = 0;
    int i;
    for (i = 0; i < soLuongSV; i++)
    {
        if (list[i].getlop() == lopp)
        {
            temp2.list[temp2.soLuongSV] = list[i];
            temp2.soLuongSV++;
        }
    }
    return temp2;
}
danhsachsinhvien &danhsachsinhvien::tktheomaKhoa(string makhoa)
{
    static danhsachsinhvien temp3;
    temp3.soLuongSV = 0;
    int i;
    for (i = 0; i < soLuongSV; i++)
    {
        if (list[i].getmaKhoa() == makhoa)
        {
            temp3.list[temp3.soLuongSV] = list[i]; 
            temp3.soLuongSV++;
        }
    }
    return temp3;
}
danhsachsinhvien &danhsachsinhvien::tktheohocBong(bool kt)
{
    static danhsachsinhvien temp4;
    temp4.soLuongSV = 0;
    int i;
    for (i = 0; i < soLuongSV; i++)
    {
        if (list[i].getdiem().tinhDTBvaHB() == kt)
        {
            temp4.list[temp4.soLuongSV] = list[i]; 
            temp4.soLuongSV++;
        }
    }
    return temp4;
}
danhsachsinhvien &danhsachsinhvien::tktheogioiTinh(bool b)
{
    static danhsachsinhvien temp5;
    temp5.soLuongSV = 0;
    int i;
    for (i = 0; i < soLuongSV; i++)
    {
        if (list[i].getgioiTinh() == b)
        {
            temp5.list[temp5.soLuongSV] = list[i]; 
            temp5.soLuongSV++;
        }
    }
    return temp5;
}
danhsachsinhvien &danhsachsinhvien::tklonhondtb(float dtbb)
{
    static danhsachsinhvien temp6;
    temp6.soLuongSV = 0;
    int i;
    for (i = 0; i < soLuongSV; i++)
    {
        if (list[i].getdiem().getdtb() >= dtbb)
        {
            temp6.list[temp6.soLuongSV] = list[i]; 
            temp6.soLuongSV++;
        }
    }
    return temp6;
}

danhsachsinhvien &danhsachsinhvien::tknhohondtb(float dtbb)
{
    static danhsachsinhvien temp6;
    temp6.soLuongSV = 0;
    int i;
    for (i = 0; i < soLuongSV; i++)
    {
        if (list[i].getdiem().getdtb() <= dtbb)
        {
            temp6.list[temp6.soLuongSV] = list[i]; 
            temp6.soLuongSV++;
        }
    }
    return temp6;
}
void danhsachsinhvien::sapXepSV()
{
    do
    {
        int chon;
        char choice;
        cout << "----------Menu sap xep-----------" << endl;
        cout << "1. Theo ma so sinh vien.\n";
        cout << "2. Theo ho ten sinh vien (alphabet).\n";
        cout << "3. Theo lop.\n";
        cout << "4. Theo muc diem trung binh.\n";
        cout << "0. Khong sap xep nua.\n";
        cout << "Lua chon cua ban la? ";
        do
        {
            cin >> chon;
            if (chon >= 0 && chon <= 4)
                break;
        } while (1);
        switch (chon)
        {
        case 1:
            sxtheomaSV();
            cout << "Danh sach da sap xep theo ma sinh vien. \n";
            Xuat();
            break;
        case 2:
            sxtheohoTen();
            cout << "Danh sach da sap xep theo ho ten sinh vien. \n";
            Xuat();
            break;
        case 3:
            sxtheolop();
            cout << "Danh sach da sap xep theo lop. \n";
            Xuat();
            break;
        case 4:
            sxtheodtb();
            cout << "Danh sach da sap xep theo diem trung binh. \n";
            Xuat();
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le.";
            break;
        }
        cout << endl
             << "Ban co muon sap xep tiep ko? (Y,N) ";
        cin >> choice;
        if (choice == 'N' || choice == 'n')
            break;
    } while (1);
}
void danhsachsinhvien::sxtheomaSV()
{
    for (int i = 1; i < soLuongSV; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (list[j].getmaSV() > list[j + 1].getmaSV())
            {
                SinhVien temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void danhsachsinhvien::sxtheohoTen()
{
    for (int i = 1; i < soLuongSV; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (get_last_word(list[j].gethoTen()) > get_last_word(list[j + 1].gethoTen()))
            {
                SinhVien temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void danhsachsinhvien::sxtheolop()
{
    for (int i = 1; i < soLuongSV; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (list[j].getlop() > list[j + 1].getlop())
            {
                SinhVien temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void danhsachsinhvien::sxtheoqueQuan()
{
    for (int i = 1; i < soLuongSV; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (list[j].getqueQuan() > list[j + 1].getqueQuan())
            {
                SinhVien temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void danhsachsinhvien::sxtheodtb()
{
    for (int i = 1; i < soLuongSV; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (list[j].getdiem().getdtb() > list[j + 1].getdiem().getdtb())
            {
                SinhVien temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void danhsachsinhvien::suaSV()
{
    do
    {
        int chon;
        string masv = " ";
        cout << endl
             << "Chon sinh vien ban muon sua theo ma so sinh vien: " << endl;
        cout << "1. Nhap       2. Tim kiem.       0. khong sua nua.\n";
        cout << endl
             << "Lua chon cua ban? ";
        do
        {
            cin >> chon;
            if (chon >= 0 && chon <= 2)
                break;
        } while (1);
        switch (chon)
        {
        case 1:
            cout << "Ma sinh vien : ";
            getline(cin >> ws, masv);
            break;
        case 2:
            //tìm kiếm và hiển thị danh sách tìm kiếm (có mã sinh viên).
            timKiemSV();
            cout << "Ma sinh vien : ";
            getline(cin >> ws, masv);
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le.";
            break;
        }
        //hàm sửa theo mã sinh viên
        if (masv != " ")
        {
            cout << endl;
            int tt = tktheomaSV(masv);
            if (tt == -1)
            {
                cout << "Khong co sinh vien nay" << endl;
            }
            else
            {
                cout << setw(11) << "Ma SV" << setw(25) << "Ho va ten" << setw(16) << "Ngay sinh"
                     << setw(8) << "Gtinh" << setw(8) << "Lop" << setw(16) << "SDT" 
                     << setw(13) << "Ma khoa" << setw(20)<< "Que quan" << setw(6) << "Toan" 
                     << setw(6) << "Ly" << setw(6) << "Tin" << setw(8) << "Triet"
                     << setw(6) << "AV" << setw(6) << "DTB" << setw(12) << "Hoc bong" << endl;

                list[tt].Xuat();
                SinhVien &sv1 = list[tt];
                cout << endl
                     << "Ban muon thay doi hang muc nao? \n";
                cout << "1.Ma sinh vien \n";
                cout << "2.Ho va ten \n";
                cout << "3.Ngay sinh \n";
                cout << "4.Gioi tinh \n";
                cout << "5.Lop \n";
                cout << "6.So dien thoai \n";
                cout << "7.Ma khoa \n";
                cout << "8.Que quan \n";
                cout << "9.Diem\n";
                cout << "0.Khong thay doi nua.\n";
                cout << "Lua chon so: ";
                int chon[10];
                int i=0; int ci;
                char t; 
                do {
                    do {
                    cin>>chon[i]; 
                    t=getchar(); 
                    if (chon[i] >= 0 && chon[i] <= 9)
                        break;
                    else
                        cout << "Khong hop le. Nhap lai: ";
                    } while (1); 
                    i++; 
                } while (t!='\n');    
                string data;
                string diemm;
                char c[10]; 
                for (int j=0; j<i; j++) {
                    switch (chon[j])
                    {
                    case 1:
                        do
                        {
                            cout << endl
                                << "Nhap ma sinh vien (9 chu so): ";
                            getline(cin >> ws, data);
                        } while (!check_number1(data) || (data.length() != 9));
                        sv1.setmaSV (data);
                        break;
                    case 2:
                        do
                        {
                            cout << "Nhap ho ten sinh vien: ";
                            getline(cin >> ws, data);
                        } while (!check_char1(data));
                        sv1.sethoTen (data);
                        break;

                    case 3:
                        cout << "Nhap ngay sinh: ";
                        getline(cin >> ws, data);
                        sv1.setngaySinh (data);
                        break;

                    case 4:
                        do
                        {
                            cout << "Nhap gioi tinh (Nam:1 ; Nu:0) : ";
                            getline(cin >> ws, data);
                        } while (!check_number1(data) || (stoi(data) != 1 && stoi(data) != 0));
                        sv1.setgioiTinh (stoi(data));
                        break;

                    case 5:
                        do
                        {
                            cout << "Nhap lop (vi du: 20T1, 20DCLC3): ";
                            getline(cin >> ws, data);
                        } while (!check_lop1(data));
                        sv1.setlop (data);
                        break;

                    case 6:
                        do
                        {
                            cout << "Nhap so dien thoai: ";
                            getline(cin >> ws, data);
                        } while (!check_number1(data));
                        sv1.setsdt (data);
                        break;

                    case 7:
                        do
                        {
                            cout << "Nhap ma khoa (CND, CNT, CKH, DIE, DTV, HOA, KTR, QLD, XDC): ";
                            getline(cin >> ws, data);
                        } while (!check_makhoa1(data));
                        sv1.setmaKhoa (data);
                        break;

                    case 8:
                        do
                        {
                            cout << "Nhap que quan: ";
                            getline(cin >> ws, data);
                        } while (!check_char1(data));

                        sv1.setqueQuan (data);
                        break;

                    case 9:
                        cout << "Ban muon thay doi diem mon nao? (T: toan, L: ly, I: tin, R: triet, A: anh van) ";
                        t=0; ci=0;
                        do {
                            cin>>c[ci]; 
                            t=getchar(); 
                            c[ci] = toupper(c[ci]); ci++;
                        } while (t!='\n'); 
                        for (int i_c=0; i_c<ci; i_c++) {
                        do
                        {
                            cout<<"Mon thu "<<(i_c+1)<<":"<<endl;
                            cout << "Ban muon thay doi thanh: ";
                            getline(cin >> ws, diemm);
                        } while (!check_float1(diemm) || (stod(diemm) > 10));

                        switch (c[i_c])
                        {
                        case 'T':
                            sv1.setdiemtoan (stod(diemm));
                            break;
                        case 'L':
                            sv1.setdiemly (stod(diemm));
                            break;
                        case 'I':
                            sv1.setdiemtin (stod(diemm));
                            break;
                        case 'R':
                            sv1.setdiemtriet (stod(diemm));
                            break;
                        case 'A':
                            sv1.setdiemanhVan (stod(diemm));
                            break;
                        default:
                            cout << "Du lieu nhap khong hop le.";
                            break;
                        }
                        }
                        // tính lại điểm trung bình và học bổng sau khi thay đổi điểm.
                        sv1.getdiem().tinhDTBvaHB();
                        break;
                    default: {
                        cout << "\n\t\t\tLua chon khong ton tai...";
                        break;}
                    }
                }
                fstream fileOut, fileOut1;
                fileOut.open("txtsinhvien.txt", ios::out);
                fileOut1.open("txtdiemso.txt", ios::out);

                for (int i = 0; i < soLuongSV; i++)
                {
                    fileOut << list[i].getmaSV() << "," << list[i].gethoTen() << "," << list[i].getngaySinh() << "," << list[i].getgioiTinh() << "," << list[i].getlop() << ","
                            << list[i].getsdt() << "," << list[i].getmaKhoa() << "," << list[i].getqueQuan() << endl;

                    fileOut1 << list[i].getmaSV() << "," << list[i].getdiem().gettoan() << "," << list[i].getdiem().getly() << "," << list[i].getdiem().gettin() << ","
                             << list[i].getdiem().gettriet() << "," << list[i].getdiem().getanhVan() << endl;
                }
                fileOut.close();
                fileOut1.close();

                cout << endl
                     << "Ket qua thay doi: \n";
                cout << endl
                     << setw(11) << "Ma SV" << setw(25) << "Ho va ten" << setw(16) << "Ngay sinh"
                     << setw(8) << "Gtinh" << setw(8) << "Lop" << setw(16) << "SDT" << setw(13) << "Ma khoa" << setw(20)
                     << "Que quan" << setw(6) << "Toan" << setw(6) << "Ly" << setw(6) << "Tin" << setw(8) << "Triet"
                     << setw(6) << "AV" << setw(6) << "DTB" << setw(12) << "Hoc bong" << endl;
                sv1.Xuat();
            }
        }

        char choice;
        cout << endl
             << "Ban co muon sua tiep ko? (Y,N) ";
        cin >> choice;  
        if (choice == 'N' || choice == 'n')
            break;
    } while (1);    
}
void danhsachsinhvien::xoaSV()
{
    do
    {
        int chon;
        string masv = "NO";
        cout << "Chon sinh vien ban muon xoa theo ma so sinh vien: " << endl;
        cout << "1. Nhap       2. Tim kiem.       0. khong sua nua.\n";
        cout << endl
             << "Lua chon cua ban? ";
        do
        {
            cin >> chon;
            if (chon >= 0 && chon <= 2)
                break;
        } while (1);
        switch (chon)
        {
        case 1:
            cout << "Ma sinh vien : ";
            getline(cin >> ws, masv);
            break;
        case 2:
            //tìm kiếm và hiển thị danh sách tìm kiếm (có mã sinh viên).
            timKiemSV(); 
            cout << "Ma sinh vien : ";
            getline(cin >> ws, masv);
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le.";
            break;
        }
        if (masv != "NO")
        {
            int tt = tktheomaSV(masv);
            if (tt == -1)
            {
                cout << "Khong co sinh vien nay" << endl;
            }
            else
            {
                cout << setw(11) << "Ma SV" << setw(25) << "Ho va ten" << setw(16) << "Ngay sinh"
                     << setw(8) << "Gtinh" << setw(8) << "Lop" << setw(16) << "SDT" << setw(13) << "Ma khoa" << setw(20)
                     << "Que quan" << setw(6) << "Toan" << setw(6) << "Ly" << setw(6) << "Tin" << setw(8) << "Triet"
                     << setw(6) << "AV" << setw(6) << "DTB" << setw(12) << "Hoc bong" << endl;

                list[tt].Xuat();
                //hàm xoá theo mã sinh viên
                char c;
                cout << "Ban co chac muon xoa sinh vien ra khoi danh sach? (Y/N) ";
                cin >> c;
                toupper(c);
                if (c == 'Y' || c == 'y')
                {
                    xoaSVtheomaSV(masv);
                }

                fstream fileOut, fileOut1;
                fileOut.open("txtsinhvien.txt", ios::out);
                fileOut1.open("txtdiemso.txt", ios::out);

                for (int i = 0; i < soLuongSV; i++)
                {
                    fileOut << list[i].getmaSV() << "," << list[i].gethoTen() << "," << list[i].getngaySinh() << "," << list[i].getgioiTinh() << "," << list[i].getlop() << ","
                            << list[i].getsdt() << "," << list[i].getmaKhoa() << "," << list[i].getqueQuan() << endl;

                    fileOut1 << list[i].getmaSV() << "," << list[i].getdiem().gettoan() << "," << list[i].getdiem().getly() << "," << list[i].getdiem().gettin() << ","
                             << list[i].getdiem().gettriet() << "," << list[i].getdiem().getanhVan() << endl;
                }
                fileOut.close();
                fileOut1.close();
            }
        }

        char choice;
        cout << "Ban co muon xoa tiep ko? (Y,N) ";
        cin >> choice;
        if (choice == 'N' || choice == 'n')
            break;
    } while (1);
}
void danhsachsinhvien::xoaSVtheomaSV(string masv)
{
    for (int i = 0; i < soLuongSV; i++)
    {
        if (list[i].getmaSV() == masv)
        {
            for (int j = i; j < soLuongSV - 1; j++)
            {
                list[j] = list[j + 1];
            }
            soLuongSV--;
            break;
        }
    }
    cout << "Da xoa." << endl;
}
void danhsachsinhvien::thongKeSV(cackhoa &CK)
{
    fstream fileOut; 
    fileOut.open("txtthongke.txt",ios::app|ios::out);
    fileOut<<left; 
    do
    {
        int chon;
        char choice;
        cout << endl
             << "----------Menu thong ke-----------" << endl;
        cout << "1. Ve quy mo.\n";
        cout << "2. Ve xep loai sinh vien.\n";
        cout << "3. Ve hoc bong.\n";
        cout << "0. Khong thong ke nua.\n";
        cout << "Lua chon cua ban la? ";
        do
        {
            cin >> chon;
            if (chon >= 0 && chon <= 3)
                break;
            else
                cout << "Khong hop le. Nhap lai: ";
        } while (1);
        switch (chon)
        {
        case 1:
            int choose;
            cout << endl
                 << "Thong ke ve quy mo: \n";
            cout << "1. Cua toan truong.\n";
            cout << "2. Cua moi khoa.\n";
            cout << "3. Cua moi khoa, nam vao truong.\n";
            cout << "4. Cua moi lop.\n";
            cout << "5. Cua moi tinh, thanh pho.\n";
            cout << "0. Dung thong ke.\n";
            cout << "Lua chon cua ban la? ";
            do
            {
                cin >> choose;
                if (choose >= 0 && choose <= 5)
                    break;
                else
                    cout << "Khong hop le. Nhap lai: ";
            } while (1);
            switch (choose)
            {
            case 1:
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut << endl
                     << "Thong ke quy mo toan truong.\n\n";
                fileOut << setw(15) << "Tong so sv" << setw(15) << "so sv nam" << setw(15) << "so sv nu" << endl;
                fileOut << setw(15) << soLuongSV << setw(15) << demgioiTinh(1) << setw(15) << demgioiTinh(0) << endl;
                cout << endl
                     << "Thong ke quy mo toan truong.\n";
                cout << setw(15) << "Tong so sv" << setw(15) << "so sv nam" << setw(15) << "so sv nu" << endl;
                cout << setw(15) << soLuongSV << setw(15) << demgioiTinh(1) << setw(15) << demgioiTinh(0) << endl;
                break;
            case 2:
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut<<"\nThong ke ve quy mo cua moi khoa.\n";
                // CK.Xuat();
                fileOut << endl
                     << "Co tat ca " << CK.getsoLuongKHoa() << " khoa." << endl;
                cout << endl
                     << "Co tat ca " << CK.getsoLuongKHoa() << " khoa." << endl;
                //thong ke so nam nu moi khoa
                fileOut << setw(28) << "Ten khoa" << setw(15) << "Tong so sv" << setw(15) << "So sv nam" << setw(15) << "So sv nu" << endl;
                cout << setw(28) << "Ten khoa" << setw(15) << "Tong so sv" << setw(15) << "So sv nam" << setw(15) << "So sv nu" << endl;
                for (int i = 0; i < CK.getsoLuongKHoa(); i++)
                {
                    fileOut << setw(28) << CK.gettenKhoa(i) << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).soLuongSV << setw(15)
                         << tktheomaKhoa(CK.getmaKhoa(i)).demgioiTinh(1) << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demgioiTinh(0) << endl;
                    cout << setw(28) << CK.gettenKhoa(i) << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).soLuongSV << setw(15)
                         << tktheomaKhoa(CK.getmaKhoa(i)).demgioiTinh(1) << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demgioiTinh(0) << endl;
                }
                break;
            case 3:
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut<<"\nThong ke ve quy mo cua moi khoa, nam vao truong.\n";
                static danhsachsinhvien tmpkhoa;
                sxtheolop();
                fileOut << endl
                     << setw(15) << "Khoa thu" << setw(15) << "Tong so sv" << setw(15) << "So sv nam" << setw(15) << "So sv nu" << endl;
                cout << endl
                     << setw(15) << "Khoa thu" << setw(15) << "Tong so sv" << setw(15) << "So sv nam" << setw(15) << "So sv nu" << endl;
                for (int i = 0; i < soLuongSV; i++)
                {
                    int dem = 1;
                    while (list[i].getlop().compare(0, 2, list[i + 1].getlop(), 0, 2) == 0 && i < soLuongSV - 1)
                    {
                        dem++;
                        i++;
                    }
                    fileOut << setw(15) << list[i].getlop().substr(0, 2) << setw(15) << dem;
                    cout << setw(15) << list[i].getlop().substr(0, 2) << setw(15) << dem;
                    tmpkhoa.soLuongSV = dem;
                    for (int j = i; dem > 0; j--)
                    {
                        tmpkhoa.list[dem - 1] = list[j];
                        dem--;
                    }
                    fileOut << setw(15) << tmpkhoa.demgioiTinh(1) << setw(15) << tmpkhoa.demgioiTinh(0) << endl;
                    cout << setw(15) << tmpkhoa.demgioiTinh(1) << setw(15) << tmpkhoa.demgioiTinh(0) << endl;
                }
                break;
            case 4:
            {
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut<<"\nThong ke ve quy mo cua moi lop.\n";
                static danhsachsinhvien tmp;
                sxtheolop();
                fileOut << endl
                     << setw(15) << "Lop" << setw(15) << "Tong so sv" << setw(15) << "So sv nam" << setw(15) << "So sv nu" << endl;
                cout << endl
                     << setw(15) << "Lop" << setw(15) << "Tong so sv" << setw(15) << "So sv nam" << setw(15) << "So sv nu" << endl;
                for (int i = 0; i < soLuongSV; i++)
                {
                    int dem = 1;
                    while (list[i].getlop() == list[i + 1].getlop() && i < soLuongSV - 1)
                    {
                        dem++;
                        i++;
                    }
                    fileOut << setw(15) << list[i].getlop() << setw(15) << dem;
                    cout << setw(15) << list[i].getlop() << setw(15) << dem;
                    tmp.soLuongSV = dem;
                    for (int j = i; dem > 0; j--)
                    {
                        tmp.list[dem - 1] = list[j];
                        dem--;
                    }
                    fileOut << setw(15) << tmp.demgioiTinh(1) << setw(15) << tmp.demgioiTinh(0) << endl;
                    cout << setw(15) << tmp.demgioiTinh(1) << setw(15) << tmp.demgioiTinh(0) << endl;
                }
                break;
            }
            case 5:
            {
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut<<"\nThong ke ve quy mo cua moi tinh, thanh pho.\n";
                static danhsachsinhvien tmptinh;
                sxtheoqueQuan();
                fileOut << endl
                     << setw(25) << "Tinh" << setw(15) << "Tong so sv" << setw(15) << "So sv nam" << setw(15) << "So sv nu" << endl;
                cout << endl
                     << setw(25) << "Tinh" << setw(15) << "Tong so sv" << setw(15) << "So sv nam" << setw(15) << "So sv nu" << endl;
                for (int i = 0; i < soLuongSV; i++)
                {
                    int dem = 1;
                    while (list[i].getqueQuan() == list[i + 1].getqueQuan() && i < soLuongSV - 1)
                    {
                        dem++;
                        i++;
                    }
                    fileOut << setw(25) << list[i].getqueQuan() << setw(15) << dem;
                    cout << setw(25) << list[i].getqueQuan() << setw(15) << dem;
                    tmptinh.soLuongSV = dem;
                    for (int j = i; dem > 0; j--)
                    {
                        tmptinh.list[dem - 1] = list[j];
                        dem--;
                    }
                    fileOut << setw(15) << tmptinh.demgioiTinh(1) << setw(15) << tmptinh.demgioiTinh(0) << endl;
                    cout << setw(15) << tmptinh.demgioiTinh(1) << setw(15) << tmptinh.demgioiTinh(0) << endl;
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.";
                break;
            }
            break;
        case 2:
            cout << endl
                 << "Thong ke ve xep loai sinh vien: \n";
            cout << "1. Cua toan truong.\n";
            cout << "2. Cua moi khoa.\n";
            cout << "3. Cua moi khoa, nam vao truong.\n";
            cout << "4. Cua moi lop.\n";
            cout << "5. Cua moi tinh, thanh pho.\n";
            cout << "0. Dung thong ke.\n";
            cout << "Lua chon cua ban la? ";
            do
            {
                cin >> choose;
                if (choose >= 0 && choose <= 5)
                    break;
                else
                    cout << "khong hop le. Nhap lai: ";
            } while (1);
            switch (choose)
            {
            case 1:
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut << endl
                     << "Thong ke ve xep loai sinh vien toan truong.\n\n";
                fileOut << "Tong so sinh vien : ";
                fileOut << soLuongSV << '\n';
                fileOut << "So sinh vien gioi : ";
                fileOut << demxepLoai("gioi") << '\n';
                fileOut << "So sinh vien kha : ";
                fileOut << demxepLoai("kha") << '\n';
                fileOut << "So sinh vien trung binh : ";
                fileOut << demxepLoai("tbinh") << '\n';
                fileOut << "So sinh vien yeu : ";
                fileOut << demxepLoai("yeu") << '\n';
                cout << endl
                     << "Thong ke xep loai sinh vien toan truong.\n";
                cout << "Tong so sinh vien : ";
                cout << soLuongSV << '\n';
                cout << "So sinh vien gioi : ";
                cout << demxepLoai("gioi") << '\n';
                cout << "So sinh vien kha : ";
                cout << demxepLoai("kha") << '\n';
                cout << "So sinh vien trung binh : ";
                cout << demxepLoai("tbinh") << '\n';
                cout << "So sinh vien yeu : ";
                cout << demxepLoai("yeu") << '\n';
                break;
            case 2:
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut<<"\nThong ke ve xep loai sinh vien moi khoa.\n"; 
                fileOut << endl
                     << setw(30) << "Khoa" << setw(15) << "Tong so sv" << setw(15) << "Gioi" << setw(15)
                     << "Kha" << setw(15) << "Tbinh" << setw(15) << "Yeu" << endl;
                cout << endl
                     << setw(30) << "Khoa" << setw(15) << "Tong so sv" << setw(15) << "Gioi" << setw(15)
                     << "Kha" << setw(15) << "Tbinh" << setw(15) << "Yeu" << endl;
                for (int i = 0; i < CK.getsoLuongKHoa(); i++)
                {
                    fileOut << setw(30) << CK.gettenKhoa(i) << setw(15) << CK.getsoSinhVien(i)
                         << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demxepLoai("gioi")
                         << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demxepLoai("kha")
                         << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demxepLoai("tbinh")
                         << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demxepLoai("yeu") << endl;
                    cout << setw(30) << CK.gettenKhoa(i) << setw(15) << CK.getsoSinhVien(i)
                         << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demxepLoai("gioi")
                         << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demxepLoai("kha")
                         << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demxepLoai("tbinh")
                         << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demxepLoai("yeu") << endl;
                }
                break;
            case 3:
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut<<"\nThong ke ve xep loai sinh vien moi khoa, nam vao truong.\n"; 
                static danhsachsinhvien tmpkhoa;
                sxtheolop();
                fileOut << endl
                     << setw(15) << "Khoa thu" << setw(15) << "Tong so sv" << setw(15) << "Gioi" << setw(15)
                     << "Kha" << setw(15) << "Tbinh" << setw(15) << "Yeu" << endl;
                cout << endl
                     << setw(15) << "Khoa thu" << setw(15) << "Tong so sv" << setw(15) << "Gioi" << setw(15)
                     << "Kha" << setw(15) << "Tbinh" << setw(15) << "Yeu" << endl;
                for (int i = 0; i < soLuongSV; i++)
                {
                    int dem = 1;
                    while (list[i].getlop().compare(0, 2, list[i + 1].getlop(), 0, 2) == 0 && i < soLuongSV - 1)
                    {
                        dem++;
                        i++;
                    }
                    fileOut << setw(15) << list[i].getlop().substr(0, 2) << setw(15) << dem;
                    cout << setw(15) << list[i].getlop().substr(0, 2) << setw(15) << dem;
                    tmpkhoa.soLuongSV = dem;
                    for (int j = i; dem > 0; j--)
                    {
                        tmpkhoa.list[dem - 1] = list[j];
                        dem--;
                    }
                    fileOut << setw(15) << tmpkhoa.demxepLoai("gioi") << setw(15)
                         << tmpkhoa.demxepLoai("kha") << setw(15) << tmpkhoa.demxepLoai("tbinh") << setw(15) << tmpkhoa.demxepLoai("yeu") << endl;
                    cout << setw(15) << tmpkhoa.demxepLoai("gioi") << setw(15)
                         << tmpkhoa.demxepLoai("kha") << setw(15) << tmpkhoa.demxepLoai("tbinh") << setw(15) << tmpkhoa.demxepLoai("yeu") << endl;
                }
                break;
            case 4:
            {
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut<<"\nThong ke ve xep loai sinh vien moi lop.\n"; 
                static danhsachsinhvien tmp;
                sxtheolop();
                
                fileOut << endl
                     << setw(15) << "Lop" << setw(15) << "Tong so sv" << setw(15) << "Gioi" << setw(15)
                     << "Kha" << setw(15) << "Tbinh" << setw(15) << "Yeu" << endl;
                cout << endl
                     << setw(15) << "Lop" << setw(15) << "Tong so sv" << setw(15) << "Gioi" << setw(15)
                     << "Kha" << setw(15) << "Tbinh" << setw(15) << "Yeu" << endl;
                for (int i = 0; i < soLuongSV; i++)
                {
                    int dem = 1;
                    while (list[i].getlop() == list[i + 1].getlop() && i < soLuongSV - 1)
                    {
                        dem++;
                        i++;
                    }
                    fileOut << setw(15) << list[i].getlop() << setw(15) << dem ;
                    cout << setw(15) << list[i].getlop() << setw(15) << dem ;
                    tmp.soLuongSV = dem;
                    for (int j = i; dem > 0; j--)
                    {
                        tmp.list[dem - 1] = list[j];
                        dem--;
                    }
                    fileOut << setw(15) << tmp.demxepLoai("gioi") << setw(15)
                         << tmp.demxepLoai("kha") << setw(15) << tmp.demxepLoai("tbinh") << setw(15) << tmp.demxepLoai("yeu") << endl;
                    cout << setw(15) << tmp.demxepLoai("gioi") << setw(15)
                         << tmp.demxepLoai("kha") << setw(15) << tmp.demxepLoai("tbinh") << setw(15) << tmp.demxepLoai("yeu") << endl;
                }
                break;
            }
            case 5:
            {
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut<<"\nThong ke ve xep loai sinh vien moi tinh, thanh pho.\n"; 
                static danhsachsinhvien 
                tmptinh;
                sxtheoqueQuan();
                fileOut << endl
                     << setw(25) << "Tinh" << setw(15) << "Tong so sv" << setw(15) << "Gioi" << setw(15)
                     << "Kha" << setw(15) << "Tbinh" << setw(15) << "Yeu" << endl;
                cout << endl
                     << setw(25) << "Tinh" << setw(15) << "Tong so sv" << setw(15) << "Gioi" << setw(15)
                     << "Kha" << setw(15) << "Tbinh" << setw(15) << "Yeu" << endl;
                for (int i = 0; i < soLuongSV; i++)
                {
                    int dem = 1;
                    while (list[i].getqueQuan() == list[i + 1].getqueQuan() && i < soLuongSV - 1)
                    {
                        dem++;
                        i++;
                    }
                    fileOut << setw(25) << list[i].getqueQuan() << setw(15) << dem;
                    cout << setw(25) << list[i].getqueQuan() << setw(15) << dem;
                    tmptinh.soLuongSV = dem;
                    for (int j = i; dem > 0; j--)
                    {
                        tmptinh.list[dem - 1] = list[j];
                        dem--;
                    }
                    fileOut << setw(15) << tmptinh.demxepLoai("gioi") << setw(15)
                         << tmptinh.demxepLoai("kha") << setw(15) << tmptinh.demxepLoai("tbinh") << setw(15) << tmptinh.demxepLoai("yeu") << endl;
                    cout << setw(15) << tmptinh.demxepLoai("gioi") << setw(15)
                         << tmptinh.demxepLoai("kha") << setw(15) << tmptinh.demxepLoai("tbinh") << setw(15) << tmptinh.demxepLoai("yeu") << endl;
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.";
                break;
            }
            break;
        case 3:
            cout << endl
                 << "Thong ke ve hoc bong: \n";
            cout << "1. Cua toan truong.\n";
            cout << "2. Cua moi khoa.\n";
            cout << "3. Cua moi khoa, nam vao truong.\n";
            cout << "4. Cua moi lop.\n";
            cout << "5. Cua moi tinh, thanh pho.\n";
            cout << "0. Dung thong ke.\n";
            cout << "Lua chon cua ban la? ";
            do
            {
                cin >> choose;
                if (choose >= 0 && choose <= 5)
                    break;
                else
                    cout << "Khong hop le. Nhap lai: ";
            } while (1);
            switch (choose)
            {
            case 1:
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut << endl
                     << "Thong ke hoc bong toan truong.\n\n";
                fileOut << "Tong so sinh vien : ";
                fileOut << soLuongSV << '\n';
                fileOut << "So sinh vien dat hoc bong 200% : ";
                fileOut << demhocBong(200) << '\n';
                fileOut << "So sinh vien dat hoc bong 100% : ";
                fileOut << demhocBong(100) << '\n';
                fileOut << "So sinh vien khong dat hoc bong: ";
                fileOut << demhocBong(0) << '\n';
                cout << endl
                     << "Thong ke hoc bong toan truong.\n";
                cout << "Tong so sinh vien : ";
                cout << soLuongSV << '\n';
                cout << "So sinh vien dat hoc bong 200% : ";
                cout << demhocBong(200) << '\n';
                cout << "So sinh vien dat hoc bong 100% : ";
                cout << demhocBong(100) << '\n';
                cout << "So sinh vien khong dat hoc bong: ";
                cout << demhocBong(0) << '\n';
                break;
            case 2:
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut<<"\nThong ke ve hoc bong moi khoa.\n";
                fileOut << endl
                     << setw(30) << "Khoa" << setw(15) << "Tong so sv" << setw(15) << "200%" << setw(15)
                     << "100%" << setw(15) << "khong" << endl;
                cout << endl
                     << setw(30) << "Khoa" << setw(15) << "Tong so sv" << setw(15) << "200%" << setw(15)
                     << "100%" << setw(15) << "khong" << endl;
                for (int i = 0; i < CK.getsoLuongKHoa(); i++)
                {
                    fileOut << setw(30) << CK.gettenKhoa(i) << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).soLuongSV
                         << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demhocBong(200) << setw(15)
                         << tktheomaKhoa(CK.getmaKhoa(i)).demhocBong(100) << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demhocBong(0) << endl;
                    cout << setw(30) << CK.gettenKhoa(i) << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).soLuongSV
                         << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demhocBong(200) << setw(15)
                         << tktheomaKhoa(CK.getmaKhoa(i)).demhocBong(100) << setw(15) << tktheomaKhoa(CK.getmaKhoa(i)).demhocBong(0) << endl;
                }
                break;
            case 3:
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut<<"\nThong ke ve hoc bong moi khoa, nam vao truong.\n";
                static danhsachsinhvien tmpkhoa;
                sxtheolop();
                fileOut << endl
                     << setw(15) << "Khoa thu" << setw(15) << "Tong so sv" << setw(15) << "200%" << setw(15)
                     << "100%" << setw(15) << "khong" << endl;
                cout << endl
                     << setw(15) << "Khoa thu" << setw(15) << "Tong so sv" << setw(15) << "200%" << setw(15)
                     << "100%" << setw(15) << "khong" << endl;
                for (int i = 0; i < soLuongSV; i++)
                {
                    int dem = 1;
                    while (list[i].getlop().compare(0, 2, list[i + 1].getlop(), 0, 2) == 0 && i < soLuongSV - 1)
                    {
                        dem++;
                        i++;
                    }
                    fileOut << setw(15) << list[i].getlop().substr(0, 2) << setw(15) << dem;
                    cout << setw(15) << list[i].getlop().substr(0, 2) << setw(15) << dem;
                    tmpkhoa.soLuongSV = dem;
                    for (int j = i; dem > 0; j--)
                    {
                        tmpkhoa.list[dem - 1] = list[j];
                        dem--;
                    }
                    fileOut << setw(15) << tmpkhoa.demhocBong(200) << setw(15)
                         << tmpkhoa.demhocBong(100) << setw(15) << tmpkhoa.demhocBong(0) << endl;
                    cout << setw(15) << tmpkhoa.demhocBong(200) << setw(15)
                         << tmpkhoa.demhocBong(100) << setw(15) << tmpkhoa.demhocBong(0) << endl;
                }
                break;
            case 4:
            {
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut<<"\nThong ke ve hoc bong moi lop.\n";
                static danhsachsinhvien tmp;
                sxtheolop();
                fileOut << endl
                     << setw(20) << "Lop" << setw(15) << "Tong so sv" << setw(15) << "200%" << setw(15)
                     << "100%" << setw(15) << "Khong" << endl;
                cout << endl
                     << setw(20) << "Lop" << setw(15) << "Tong so sv" << setw(15) << "200%" << setw(15)
                     << "100%" << setw(15) << "Khong" << endl;
                for (int i = 0; i < soLuongSV; i++)
                {
                    int dem = 1;
                    while (list[i].getlop() == list[i + 1].getlop() && i < soLuongSV - 1)
                    {
                        dem++;
                        i++;
                    }
                    fileOut << setw(20) << list[i].getlop() << setw(15) << dem;
                    cout << setw(20) << list[i].getlop() << setw(15) << dem;
                    tmp.soLuongSV = dem;
                    for (int j = i; dem > 0; j--)
                    {
                        tmp.list[dem - 1] = list[j];
                        dem--;
                    }
                    fileOut << setw(15) << tmp.demhocBong(200) << setw(15)
                         << tmp.demhocBong(100) << setw(15) << tmp.demhocBong(0) << endl;
                    cout << setw(15) << tmp.demhocBong(200) << setw(15)
                         << tmp.demhocBong(100) << setw(15) << tmp.demhocBong(0) << endl;
                }
                break;
            }
            case 5:
            {
                fileOut<<"-------------------------------------------------------------------------------------------\n"; 
                fileOut<<"\nThong ke ve hoc bong moi tinh, thanh pho.\n";
                static danhsachsinhvien tmptinh;
                sxtheoqueQuan();
                fileOut << endl
                     << setw(25) << "Tinh" << setw(15) << "Tong so sv" << setw(15) << "200%" << setw(15)
                     << "100%" << setw(15) << "khong" << endl;
                cout << endl
                     << setw(25) << "Tinh" << setw(15) << "Tong so sv" << setw(15) << "200%" << setw(15)
                     << "100%" << setw(15) << "khong" << endl;
                for (int i = 0; i < soLuongSV; i++)
                {
                    int dem = 1;
                    while (list[i].getqueQuan() == list[i + 1].getqueQuan() && i < soLuongSV - 1)
                    {
                        dem++;
                        i++;
                    }
                    fileOut << setw(25) << list[i].getqueQuan() << setw(15) << dem;
                    cout << setw(25) << list[i].getqueQuan() << setw(15) << dem;
                    tmptinh.soLuongSV = dem;
                    for (int j = i; dem > 0; j--)
                    {
                        tmptinh.list[dem - 1] = list[j];
                        dem--;
                    }
                    fileOut << setw(15) << tmptinh.demhocBong(200) << setw(15)
                         << tmptinh.demhocBong(100) << setw(15) << tmptinh.demhocBong(0) << endl;
                    cout << setw(15) << tmptinh.demhocBong(200) << setw(15)
                         << tmptinh.demhocBong(100) << setw(15) << tmptinh.demhocBong(0) << endl;
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.";
                break;
            }
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le.";
            break;
        }
        cout << "Ban co muon thong ke tiep ko? (Y,N) ";
        cin >> choice;
        if (choice == 'N' || choice == 'n')
            break;
    } while (1);
    fileOut.close();
}
int danhsachsinhvien::demgioiTinh(bool b)
{
    int dem = 0;
    for (int i = 0; i < soLuongSV; i++)
    {
        if (list[i].getgioiTinh() == b)
            dem++;
    }
    return dem;
}
int danhsachsinhvien::demxepLoai(string b)
{
    int dem = 0;
    for (int i = 0; i < soLuongSV; i++)
    {
        if (list[i].xepLoai() == b)
            dem++;
    }
    return dem;
}
int danhsachsinhvien::demhocBong(int b)
{
    int dem = 0;
    for (int i = 0; i < soLuongSV; i++)
    {
        if (list[i].getdiem().gethocBong() == b)
            dem++;
    }
    return dem;
}
