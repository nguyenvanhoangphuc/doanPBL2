#include "danhsachsinhvien.h"
#include "sinhvien.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

//danh sach ban dau so luong sv la 0 va co vung nho la 1000 sinh vien
danhsachsinhvien::danhsachsinhvien() {   
    this->soLuongSV=0; 
    this->list=new SinhVien[100]; 
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
        //file diem so
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
void danhsachsinhvien::timKiemSV() {
    do {
        int chon; 
        char choice; 
        cout<<"----------menu tim kiem-----------"<<endl; 
        cout<<"1. Theo ma so sinh vien.\n"; 
        cout<<"2. Theo ho ten sinh vien.\n";
        cout<<"3. Danh sach sinh vien theo lop.\n";
        cout<<"4. Danh sach sinh vien có hoc bong.\n";
        cout<<"5. Theo gioi tinh.\n";
        cout<<"6. Theo muc diem trung binh.\n";
        cout<<"7. Theo muc diem toan, li , tin, triet, anh van.\n";
        cout<<"0. Khong tim kiem nua.\n"; 
        cout<<"Lua chon cua ban la? "; 
        do {cin>>chon; if (chon>=0&&chon<=7) break; } while(1);  
        string masv,hoten,lopp;
        bool b;
        switch (chon)
        {
        case 1:
            cout<<"Nhap ma sinh vien: "; cin>>masv; 
            cout <<setw(11) << "Ma SV" << setw(25) << "Ho va ten" << setw(16) << "Nam sinh" 
            << setw(8) << "Gtinh" << setw(8) << "Lop" << setw(16) << "SDT" << setw(13) << "Ma khoa" << setw(20) 
            << "Que quan" << setw(6) << "Toan" << setw(6) << "Ly" << setw(6) << "Tin" << setw(8) << "Triet" 
            << setw(6) << "AV" << setw(6) << "DTB" << setw(12) << "Hoc bong" << endl;
            tktheomaSV(masv).Xuat(); 
            break;
        case 2:
            cout<<"Nhap ho ten sinh vien: "; 
            getline(cin>>ws,hoten);  
            tktheohoTen(hoten).Xuat(); 
            break;
        case 3:
            cout<<"Nhap lop cua sinh vien: "; 
            getline(cin>>ws,lopp);  
            tktheolop(lopp).Xuat();
            break;
        case 4:
            char c; 
            cout<<"Danh sach co hoc bong hay khong? (Y/N) "; cin>>c; 
            if (c=='y'||c=='Y') tktheohocBong(1).Xuat();
            else tktheohocBong(0).Xuat();
            break;
        case 5:
            cout<<"Nhap gioi tinh cua sinh vien: (1.Nam | 0.Nu) "; cin>>b; 
            tktheogioiTinh(b).Xuat();
            break;
        case 6:
            float dtbb; 
            cout<<"Nhap muc diem trung binh? "; cin>>dtbb;
            tktheodtb(dtbb).Xuat();
            break;
        case 7:
            break;
        case 0:
            break;
        default:
            cout<<"Lua chon khong hop le."; 
            break;
        }
        cout<<"ban co muon tim kiem tiep ko? (Y,N) "; cin>>choice; 
        if (choice=='N'||choice=='n') break; 
    } while (1); 
}
SinhVien &danhsachsinhvien::tktheomaSV(string masv) {
    int i; 
    for (i=0;i<soLuongSV;i++) {
        if (list[i].maSV==masv) break; 
    }
    return list[i];
}
danhsachsinhvien &danhsachsinhvien::tktheohoTen(string hoten) {
    static danhsachsinhvien temp1; 
    temp1.soLuongSV=0; 
    int i;  
    for (i=0;i<soLuongSV;i++) {
        if (list[i].hoTen==hoten) {
            temp1.list[temp1.soLuongSV]=list[i]; //ham gan mat dinh
            temp1.soLuongSV++; 
        }
    }
    return temp1; 
}
danhsachsinhvien &danhsachsinhvien::tktheolop(string lopp) {
    static danhsachsinhvien temp2;
    temp2.soLuongSV=0; 
    int i;  
    for (i=0;i<soLuongSV;i++) {
        if (list[i].lop==lopp) {
            temp2.list[temp2.soLuongSV]=list[i]; //ham gan mat dinh
            temp2.soLuongSV++; 
        }
    }
    return temp2; 
}
danhsachsinhvien &danhsachsinhvien::tktheohocBong(bool kt) {
    static danhsachsinhvien temp3;
    temp3.soLuongSV=0; 
    int i;  
    for (i=0;i<soLuongSV;i++) {
        if (list[i].diem.tinhDTBvaHB()==kt) {
            temp3.list[temp3.soLuongSV]=list[i]; //ham gan mat dinh
            temp3.soLuongSV++; 
        }
    }
    return temp3; 
}
danhsachsinhvien &danhsachsinhvien::tktheogioiTinh(bool b) {
    static danhsachsinhvien temp4;
    temp4.soLuongSV=0; 
    int i;  
    for (i=0;i<soLuongSV;i++) {
        if (list[i].gioiTinh==b) {
            temp4.list[temp4.soLuongSV]=list[i]; //ham gan mat dinh
            temp4.soLuongSV++; 
        }
    }
    return temp4; 
}
danhsachsinhvien &danhsachsinhvien::tktheodtb(float dtbb) {
    static danhsachsinhvien temp5;
    temp5.soLuongSV=0; 
    int i;  
    for (i=0;i<soLuongSV;i++) {
        if (list[i].diem.dtb>=dtbb) {
            temp5.list[temp5.soLuongSV]=list[i]; //ham gan mat dinh
            temp5.soLuongSV++; 
        }
    }
    return temp5; 
}
void danhsachsinhvien::sapXepSV() {
    do {
        int chon; 
        char choice; 
        cout<<"----------menu sap xep-----------"<<endl; 
        cout<<"1. Theo ma so sinh vien.\n"; 
        cout<<"2. Theo ho ten sinh vien (alphabet).\n";
        cout<<"3. Theo lop.\n";
        cout<<"4. Theo muc diem trung binh.\n";
        cout<<"5. Theo muc diem toan, li , tin, triet, anh van.\n";
        cout<<"0. Khong sap xep nua.\n"; 
        cout<<"Lua chon cua ban la? "; 
        do {cin>>chon; if (chon>=0&&chon<=5) break; } while(1);  
        switch (chon)
        {
        case 1:

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            break;
        default:
            cout<<"Lua chon khong hop le."; 
            break;
        }
        cout<<"ban co muon sap xep tiep ko? (Y,N) "; cin>>choice; 
        if (choice=='N'||choice=='n') break; 
    } while (1); 
}
void danhsachsinhvien::suaSV() {
    do {
        int chon; 
        string masv; 
        cout<<"Chon sinh vien ban muon sua theo ma so sinh vien: "<<endl;
        cout<<"1. Nhap       2. Tim kiem.       0. khong sua nua.\n"; 
        cout<<"lua chon cua ban? ";  
        do {cin>>chon; if (chon>=0&&chon<=2) break;} while (1);   
        switch (chon)
        {
        case 1:cout<<"ma sinh vien :"; cin>>masv; break;
        case 2:
            timKiemSV(); //tìm kiếm và hiển thị danh sách tìm kiếm (có mã sinh viên).
            cout<<"ma sinh vien :"; cin>>masv; break;
        case 0:
            break;
        default:
            cout<<"Lua chon khong hop le."; 
            break;
        }
        //hàm sửa theo mã sinh viên 
        
        char choice;
        cout<<"ban co muon sua tiep ko? (Y,N) "; cin>>choice; 
        if (choice=='N'||choice=='n') break; 
    } while (1); 
}
void danhsachsinhvien::xoaSV() {
    do {
        int chon; 
        string masv="NO"; 
        cout<<"Chon sinh vien ban muon sua theo ma so sinh vien: "<<endl;
        cout<<"1. Nhap       2. Tim kiem.       0. khong sua nua.\n"; 
        cout<<"lua chon cua ban? ";  
        do {cin>>chon; if (chon>=0&&chon<=2) break;} while (1);   
        switch (chon)
        {
        case 1:cout<<"ma sinh vien :"; cin>>masv; break;
        case 2:
            timKiemSV(); //tìm kiếm và hiển thị danh sách tìm kiếm (có mã sinh viên).
            cout<<"ma sinh vien :"; cin>>masv; break;
        case 0:
            break;
        default:
            cout<<"Lua chon khong hop le."; 
            break;
        }
        if (masv!="NO") {
            //hàm xoá theo mã sinh viên 
            
        }
        char choice;
        cout<<"ban co muon xoa tiep ko? (Y,N) "; cin>>choice; 
        if (choice=='N'||choice=='n') break; 
    } while (1); 
}
void danhsachsinhvien::thongKeSV() {

}