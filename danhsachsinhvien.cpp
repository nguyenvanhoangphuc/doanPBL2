#include "danhsachsinhvien.h"
#include "sinhvien.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std; 

//danh sach ban dau so luong sv la 0 va co vung nho la 1000 sinh vien
danhsachsinhvien::danhsachsinhvien() {   
    this->soLuongSV=0; 
    const int MAX_SINHVIEN =100; 
    this->list=new SinhVien[MAX_SINHVIEN]; 
}
// danhsachsinhvien::danhsachsinhvien(int a) {
//     this->soLuongSV=a; 
//     this->list=new SinhVien[a];
// }
danhsachsinhvien::danhsachsinhvien(const danhsachsinhvien &x) {
    this->soLuongSV=x.soLuongSV; 
    this->list=new SinhVien[100];
    for (int i=0; i<soLuongSV; i++) {
        this->list[i]=x.list[i]; 
    }
}
danhsachsinhvien::~danhsachsinhvien() {
    cout<<"goi ham huy.\n"; 
    delete [] list; 
}
void danhsachsinhvien::Nhaptufile() {
    string line,tempString;
    ifstream fileIn,fileIn1; 
    fileIn.open("txtsinhvien.txt",ios::in); 
    fileIn1.open("txtdiemso.txt",ios::in); 
    while (!fileIn.eof()) {
        getline(fileIn, line);
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
        //file diem so
        getline(fileIn1, line);
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
        cout<<"0. Khong tim kiem nua.\n"; 
        cout<<"Lua chon cua ban la? "; 
        do {cin>>chon; if (chon>=0&&chon<=6) break; } while(1);  
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
danhsachsinhvien &danhsachsinhvien::tktheomaKhoa(string makhoa) {
    static danhsachsinhvien temp3;
    temp3.soLuongSV=0; 
    int i;  
    for (i=0;i<soLuongSV;i++) {
        if (list[i].maKhoa==makhoa) {
            temp3.list[temp3.soLuongSV]=list[i]; //ham gan mat dinh
            temp3.soLuongSV++; 
        }
    }
    return temp3; 
}
danhsachsinhvien &danhsachsinhvien::tktheohocBong(bool kt) {
    static danhsachsinhvien temp4;
    temp4.soLuongSV=0; 
    int i;  
    for (i=0;i<soLuongSV;i++) {
        if (list[i].diem.tinhDTBvaHB()==kt) {
            temp4.list[temp4.soLuongSV]=list[i]; //ham gan mat dinh
            temp4.soLuongSV++; 
        }
    }
    return temp4; 
}
danhsachsinhvien &danhsachsinhvien::tktheogioiTinh(bool b) {
    static danhsachsinhvien temp5;
    temp5.soLuongSV=0; 
    int i;  
    for (i=0;i<soLuongSV;i++) {
        if (list[i].gioiTinh==b) {
            temp5.list[temp5.soLuongSV]=list[i]; //ham gan mat dinh
            temp5.soLuongSV++; 
        }
    }
    return temp5; 
}
danhsachsinhvien &danhsachsinhvien::tktheodtb(float dtbb) {
    static danhsachsinhvien temp6;
    temp6.soLuongSV=0; 
    int i;  
    for (i=0;i<soLuongSV;i++) {
        if (list[i].diem.dtb>=dtbb) {
            temp6.list[temp6.soLuongSV]=list[i]; //ham gan mat dinh
            temp6.soLuongSV++; 
        }
    }
    return temp6; 
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
        cout<<"0. Khong sap xep nua.\n"; 
        cout<<"Lua chon cua ban la? "; 
        do {cin>>chon; if (chon>=0&&chon<=4) break; } while(1);  
        switch (chon)
        {
        case 1:
            sxtheomaSV(); 
            cout<<"Danh sach da sap xep theo ma sinh vien. \n"; 
            Xuat();
            break;
        case 2:
            sxtheohoTen(); 
            cout<<"Danh sach da sap xep theo ho ten sinh vien. \n"; 
            Xuat();
            break;
        case 3:
            sxtheolop(); 
            cout<<"Danh sach da sap xep theo lop. \n"; 
            Xuat();
            break;
        case 4:
            sxtheodtb(); 
            cout<<"Danh sach da sap xep theo diem trung binh. \n"; 
            Xuat();
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
void danhsachsinhvien::sxtheomaSV() {
    for (int i=1; i<soLuongSV; i++) {
        for (int j=i-1; j>=0; j--) {
            if(list[j].maSV>list[j+1].maSV) {
                SinhVien temp=list[j]; 
                list[j]=list[j+1];
                list[j+1]=temp;  
            }
        }
    }
}
void danhsachsinhvien::sxtheohoTen() {
    for (int i=1; i<soLuongSV; i++) {
        for (int j=i-1; j>=0; j--) {
            if(list[j].hoTen>list[j+1].hoTen) {
                SinhVien temp=list[j]; 
                list[j]=list[j+1];
                list[j+1]=temp;  
            }
        }
    }
}
void danhsachsinhvien::sxtheolop() {
    for (int i=1; i<soLuongSV; i++) {
        for (int j=i-1; j>=0; j--) {
            if(list[j].lop>list[j+1].lop) {
                SinhVien temp=list[j]; 
                list[j]=list[j+1];
                list[j+1]=temp;  
            }
        }
    }
}
void danhsachsinhvien::sxtheoqueQuan() {
    for (int i=1; i<soLuongSV; i++) {
        for (int j=i-1; j>=0; j--) {
            if(list[j].queQuan>list[j+1].queQuan) {
                SinhVien temp=list[j]; 
                list[j]=list[j+1];
                list[j+1]=temp;  
            }
        }
    }
}
void danhsachsinhvien::sxtheodtb() {
    for (int i=1; i<soLuongSV; i++) {
        for (int j=i-1; j>=0; j--) {
            if(list[j].diem.dtb>list[j+1].diem.dtb) {
                SinhVien temp=list[j]; 
                list[j]=list[j+1];
                list[j+1]=temp;  
            }
        }
    }
}
void danhsachsinhvien::suaSV() {
    do {
        int chon; 
        string masv=" "; 
        cout<<"Chon sinh vien ban muon sua theo ma so sinh vien: "<<endl;
        cout<<"1. Nhap       2. Tim kiem.       0. khong sua nua.\n"; 
        cout<<"lua chon cua ban? ";  
        do {cin>>chon; if (chon>=0&&chon<=2) break;} while (1);   
        switch (chon)
        {
        case 1:cout<<"ma sinh vien : "; getline(cin>>ws,masv); break;
        case 2:
            timKiemSV(); //tìm kiếm và hiển thị danh sách tìm kiếm (có mã sinh viên).
            cout<<"ma sinh vien : "; getline(cin>>ws,masv); break;
        case 0:
            break;
        default:
            cout<<"Lua chon khong hop le."; 
            break;
        }
        //hàm sửa theo mã sinh viên 
        if (masv!=" ") {
            cout << setw(11) << "Ma SV" << setw(25) << "Ho va ten" << setw(16) << "Ngay sinh" 
            << setw(8) << "Gtinh" << setw(8) << "Lop" << setw(16) << "SDT" << setw(13) << "Ma khoa" << setw(20) 
            << "Que quan" << setw(6) << "Toan" << setw(6) << "Ly" << setw(6) << "Tin" << setw(8) << "Triet" 
            << setw(6) << "AV" << setw(6) << "DTB" << setw(12) << "Hoc bong" << endl;
            tktheomaSV(masv).Xuat(); 
            SinhVien &sv1= tktheomaSV(masv); 
            cout<<"Ban muon thay doi hang muc nao? \n"; 
            cout<<"1.Ho va ten \n";
            cout<<"2.Ngay sinh \n";
            cout<<"3.Gioi tinh \n";
            cout<<"4.Lop \n";
            cout<<"5.So dien thoai \n";
            cout<<"6.Ma khoa \n";
            cout<<"7.Que quan \n";
            cout<<"8.Diem\n"; 
            cout<<"0.Khong thay doi nua.\n"; 
            do {cin>>chon; if (chon>=0&&chon<=8) break;
            else cout<<"khoong hop le. Nhap lai: "; } while (1); 
            string data; 
            switch (chon)
            {
            case 1:
                cout<<"Ban muon thay doi thanh: "; getline(cin>>ws,data); 
                sv1.hoTen=data;
                break;
            case 2:
                cout<<"Ban muon thay doi thanh: "; getline(cin>>ws,data); 
                sv1.ngaySinh=data; 
                break;
            case 3:
                bool gtinh; 
                cout<<"Ban muon thay doi thanh: (1.Nam 0.Nu) "; cin>>gtinh; 
                sv1.gioiTinh=gtinh; 
                break;
            case 4:
                cout<<"Ban muon thay doi thanh: "; getline(cin>>ws,data); 
                sv1.lop=data;
                break;
            case 5:
                cout<<"Ban muon thay doi thanh: "; getline(cin>>ws,data); 
                sv1.sdt=data;
                break;
            case 6:
                cout<<"Ban muon thay doi thanh: "; getline(cin>>ws,data); 
                sv1.maKhoa=data; 
                break;
            case 7:
                cout<<"Ban muon thay doi thanh: "; getline(cin>>ws,data); 
                sv1.queQuan=data; 
                break;
            case 8:
                float diemm; 
                char c;
                cout<<"Ban muon thay doi diem mon nao? (T: toan, L: ly, I: tin, R: triet, A: anh van) ";
                cin>>c; 
                c=toupper(c); 
                cout<<"ban muon thay doi thanh: "; cin>>diemm; 
                switch (c)
                {
                case 'T':
                    sv1.diem.toan=diemm; 
                    break;
                case 'L':
                    sv1.diem.ly=diemm; 
                    break;
                case 'I':
                    sv1.diem.tin=diemm; 
                    break; 
                case 'R':
                    sv1.diem.triet=diemm; 
                    break;
                case 'A':
                    sv1.diem.anhVan=diemm; 
                    break;
                default:
                    cout<<"du lieu nhap khong hop le."; 
                    break;
                }
                // tính lại điểm trung bình và học bổng sau khi thay đổi điểm.
                sv1.diem.tinhDTBvaHB(); 
                break;
            default:
                break;
            }
            cout<<"ket qua thay doi: \n"; 
            cout << setw(11) << "Ma SV" << setw(25) << "Ho va ten" << setw(16) << "Ngay sinh" 
            << setw(8) << "Gtinh" << setw(8) << "Lop" << setw(16) << "SDT" << setw(13) << "Ma khoa" << setw(20) 
            << "Que quan" << setw(6) << "Toan" << setw(6) << "Ly" << setw(6) << "Tin" << setw(8) << "Triet" 
            << setw(6) << "AV" << setw(6) << "DTB" << setw(12) << "Hoc bong" << endl;
            sv1.Xuat();
        }
        char choice;
        cout<<"ban co muon sua tiep ko? (Y,N) "; cin>>choice; 
        if (choice=='N'||choice=='n') break; 
    } while (1); 
}
void danhsachsinhvien::xoaSV() {
    do {
        int chon; 
        string masv="NO"; 
        cout<<"Chon sinh vien ban muon xoa theo ma so sinh vien: "<<endl;
        cout<<"1. Nhap       2. Tim kiem.       0. khong sua nua.\n"; 
        cout<<"lua chon cua ban? ";  
        do {cin>>chon; if (chon>=0&&chon<=2) break;} while (1);   
        switch (chon)
        {
        case 1:cout<<"ma sinh vien : "; getline(cin>>ws,masv); break;
        case 2:
            timKiemSV(); //tìm kiếm và hiển thị danh sách tìm kiếm (có mã sinh viên).
            cout<<"ma sinh vien : "; getline(cin>>ws,masv); break;
        case 0:
            break;
        default:
            cout<<"Lua chon khong hop le."; 
            break;
        }
        if (masv!="NO") {
            //hàm xoá theo mã sinh viên 
            char c; 
            cout<<"Ban co chac muon xoa sinh vien ra khoi danh sach? (Y/N) "; cin>>c; 
            toupper(c); 
            if(c=='Y') {                
                xoaSVtheomaSV(masv); 
            }
        }
        char choice;
        cout<<"ban co muon xoa tiep ko? (Y,N) "; cin>>choice; 
        if (choice=='N'||choice=='n') break; 
    } while (1); 
}
void danhsachsinhvien::xoaSVtheomaSV(string masv) {
    for (int i=0; i<soLuongSV; i++) {
        if(list[i].maSV==masv) {
            for (int j=i; j<soLuongSV-1;j++) {
                list[j]=list[j+1]; 
            }
            soLuongSV--; 
            break; 
        }
    }
    cout<<"Da xoa."<<endl; 
}
void danhsachsinhvien::thongKeSV(cackhoa &CK) {
    do { 
        cout<<"da vao.\n"; 
        int chon; 
        char choice; 
        cout<<"----------menu thong ke-----------"<<endl; 
        cout<<"1. Ve quy mo.\n"; 
        cout<<"2. Ve xep loai sinh vien.\n";
        cout<<"3. Ve hoc bong.\n";
        cout<<"0. Khong thong ke nua.\n"; 
        cout<<"Lua chon cua ban la? "; 
        do {cin>>chon; if (chon>=0&&chon<=3) break;
        else cout<<"khong hop le. Nhap lai: "; } while(1);   
        switch (chon)
        {
        case 1:
            int choose; 
            cout<<"Thong ke ve quy mo: \n";
            cout<<"1. Cua toan truong.\n"; 
            cout<<"2. Cua moi khoa.\n"; 
            cout<<"3. Cua moi khoa, nam vao truong.\n";
            cout<<"4. Cua moi lop.\n"; 
            cout<<"5. Cua moi tinh, thanh pho.\n"; 
            cout<<"0. Dung thong ke.\n"; 
            cout<<"Lua chon cua ban la? "; 
            do {cin>>choose; if (choose>=0&&choose<=5) break;
            else cout<<"khong hop le. Nhap lai: "; } while(1);
            switch (choose)
            {
            case 1:
                //thong ke so nam nu toan truong
                cout<<"Thong ke quy mo toan truong.\n"; 
                cout<<"Tong so sinh vien : "; cout << soLuongSV <<'\n'; 
                cout <<"So sinh vien nam : "; cout << demgioiTinh(1)<<'\n';  
                cout <<"So sinh vien nu : "; cout << demgioiTinh(0)<<'\n'; 
                break;
            case 2:
                CK.Xuat(); 
                cout<<CK.getsoLuongKHoa(); 
                //thong ke so nam nu moi khoa
                for (int i=0; i<CK.getsoLuongKHoa(); i++) {
                    cout<<"+ Khoa: "<<CK.gettenKhoa(i)<<'\n'; 
                    tktheomaKhoa(CK.getmaKhoa(i)).Xuat(); 
                    cout<<"Tong so sinh vien : "; cout << tktheomaKhoa(CK.getmaKhoa(i)).soLuongSV<<'\n'; 
                    cout <<"So sinh vien nam : "; cout << tktheomaKhoa(CK.getmaKhoa(i)).demgioiTinh(1)<<'\n';  
                    cout <<"So sinh vien nu : "; cout << tktheomaKhoa(CK.getmaKhoa(i)).demgioiTinh(0)<<'\n';
                }
                break;
            case 3:
                static danhsachsinhvien tmpkhoa;
                sxtheolop();
                //thong ke so nam nu moi khoá năm vào trường.
                for (int i=0; i<soLuongSV; i++) {
                    cout<<"+ Khoa, nam vao truong : "<<list[i].lop.substr(0,2)<<'\n'; 
                    int dem=1; 
                    while (list[i].lop.compare(0,2,list[i+1].lop,0,2)==0 && i<soLuongSV-1) {
                        dem++; 
                        i++; 
                    }
                    cout<<"Tong so sinh vien : "; cout << dem <<'\n';
                    tmpkhoa.soLuongSV=dem; 
                    for (int j=i;dem>0; j-- ) {
                        tmpkhoa.list[dem-1]=list[j]; 
                        dem--; 
                    }
                    tmpkhoa.Xuat(); 
                    cout <<"\t+ So sinh vien nam : "; cout << tmpkhoa.demgioiTinh(1)<<'\n';  
                    cout <<"\t+ So sinh vien nu : "; cout << tmpkhoa.demgioiTinh(0)<<'\n'; 
                }
                break;
            case 4:{
                static danhsachsinhvien tmp;
                //thong ke so nam nu moi lop
                sxtheolop();
                for (int i=0; i<soLuongSV; i++) {
                    int dem=1; 
                    while (list[i].lop==list[i+1].lop&&i<soLuongSV-1)
                    {
                        dem++; 
                        i++; 
                    }
                    cout<<"- So sinh vien lop "<<list[i].lop<<" la: "<<dem<<endl; 
                    tmp.soLuongSV=dem; 
                    for (int j=i;dem>0; j-- ) {
                        tmp.list[dem-1]=list[j]; 
                        dem--; 
                    }
                    tmp.Xuat(); 
                    cout <<"\t+ So sinh vien nam : "; cout << tmp.demgioiTinh(1)<<'\n';  
                    cout <<"\t+ So sinh vien nu : "; cout << tmp.demgioiTinh(0)<<'\n'; 
                }
                break; }
            case 5:{
                static danhsachsinhvien tmptinh;
                //thong ke so nam nu moi lop
                sxtheoqueQuan();
                for (int i=0; i<soLuongSV; i++) {
                    int dem=1; 
                    while (list[i].queQuan==list[i+1].queQuan&&i<soLuongSV-1)
                    {
                        dem++; 
                        i++; 
                    }
                    cout<<"- So sinh vien tinh, thanh pho "<<list[i].queQuan<<" la: "<<dem<<endl; 
                    tmptinh.soLuongSV=dem; 
                    for (int j=i;dem>0; j-- ) {
                        tmptinh.list[dem-1]=list[j]; 
                        dem--; 
                    }
                    tmptinh.Xuat(); 
                    cout <<"\t+ So sinh vien nam : "; cout << tmptinh.demgioiTinh(1)<<'\n';  
                    cout <<"\t+ So sinh vien nu : "; cout << tmptinh.demgioiTinh(0)<<'\n'; 
                }
                break; }
            case 0: break; 
            default:
                cout<<"Lua chon khong hop le.";
                break;
            }
            break;
        case 2:
            cout<<"Thong ke ve xep loai sinh vien: \n";
            cout<<"1. Cua toan truong.\n"; 
            cout<<"2. Cua moi khoa.\n"; 
            cout<<"3. Cua moi khoa, nam vao truong.\n";
            cout<<"4. Cua moi lop.\n"; 
            cout<<"5. Cua moi tinh, thanh pho.\n"; 
            cout<<"0. Dung thong ke.\n"; 
            cout<<"Lua chon cua ban la? "; 
            do {cin>>choose; if (choose>=0&&choose<=5) break;
            else cout<<"khong hop le. Nhap lai: "; } while(1);
            switch (choose)
            {
            case 1:
                //thong ke so nam nu toan truong
                cout<<"Thong ke quy mo toan truong.\n"; 
                cout<<"Tong so sinh vien : "; cout << soLuongSV <<'\n'; 
                cout <<"So sinh vien gioi : "; cout << demxepLoai("gioi")<<'\n';  
                cout <<"So sinh vien kha : "; cout << demxepLoai("kha")<<'\n'; 
                cout <<"So sinh vien trung binh : "; cout <<demxepLoai("tbinh")<<'\n';  
                cout <<"So sinh vien yeu : "; cout << demxepLoai("yeu")<<'\n';
                break;
            case 2:
                CK.Xuat(); 
                cout<<CK.getsoLuongKHoa(); 
                //thong ke so nam nu moi khoa
                for (int i=0; i<CK.getsoLuongKHoa(); i++) {
                    cout<<"+ Khoa: "<<CK.gettenKhoa(i)<<'\n'; 
                    tktheomaKhoa(CK.getmaKhoa(i)).Xuat(); 
                    cout<<"Tong so sinh vien : "; cout << soLuongSV <<'\n'; 
                    cout <<"So sinh vien gioi : "; cout << tktheomaKhoa(CK.getmaKhoa(i)).demxepLoai("gioi")<<'\n';  
                    cout <<"So sinh vien kha : "; cout << tktheomaKhoa(CK.getmaKhoa(i)).demxepLoai("kha")<<'\n'; 
                    cout <<"So sinh vien trung binh : "; cout <<tktheomaKhoa(CK.getmaKhoa(i)).demxepLoai("tbinh")<<'\n';  
                    cout <<"So sinh vien yeu : "; cout << tktheomaKhoa(CK.getmaKhoa(i)).demxepLoai("yeu")<<'\n';
                }
                break;
            case 3:
                static danhsachsinhvien tmpkhoa;
                sxtheolop();
                //thong ke so nam nu moi khoá năm vào trường.
                for (int i=0; i<soLuongSV; i++) {
                    cout<<"+ Khoa, nam vao truong : "<<list[i].lop.substr(0,2)<<'\n'; 
                    int dem=1; 
                    while (list[i].lop.compare(0,2,list[i+1].lop,0,2)==0 && i<soLuongSV-1) {
                        dem++; 
                        i++; 
                    }
                    cout<<"Tong so sinh vien : "; cout << dem <<'\n';
                    tmpkhoa.soLuongSV=dem; 
                    for (int j=i;dem>0; j-- ) {
                        tmpkhoa.list[dem-1]=list[j]; 
                        dem--; 
                    }
                    tmpkhoa.Xuat(); 
                    cout <<"So sinh vien gioi : "; cout << tmpkhoa.demxepLoai("gioi")<<'\n';  
                    cout <<"So sinh vien kha : "; cout << tmpkhoa.demxepLoai("kha")<<'\n'; 
                    cout <<"So sinh vien trung binh : "; cout <<tmpkhoa.demxepLoai("tbinh")<<'\n';  
                    cout <<"So sinh vien yeu : "; cout << tmpkhoa.demxepLoai("yeu")<<'\n';
                }
                break;
            case 4:{
                static danhsachsinhvien tmp;
                //thong ke so nam nu moi lop
                sxtheolop();
                for (int i=0; i<soLuongSV; i++) {
                    int dem=1; 
                    while (list[i].lop==list[i+1].lop&&i<soLuongSV-1)
                    {
                        dem++; 
                        i++; 
                    }
                    cout<<"- So sinh vien lop "<<list[i].lop<<" la: "<<dem<<endl; 
                    tmp.soLuongSV=dem; 
                    for (int j=i;dem>0; j-- ) {
                        tmp.list[dem-1]=list[j]; 
                        dem--; 
                    }
                    tmp.Xuat(); 
                    cout <<"So sinh vien gioi : "; cout << tmp.demxepLoai("gioi")<<'\n';  
                    cout <<"So sinh vien kha : "; cout << tmp.demxepLoai("kha")<<'\n'; 
                    cout <<"So sinh vien trung binh : "; cout <<tmp.demxepLoai("tbinh")<<'\n';  
                    cout <<"So sinh vien yeu : "; cout << tmp.demxepLoai("yeu")<<'\n';
                }
                break; }
            case 5:{
                static danhsachsinhvien tmptinh;
                //thong ke so nam nu moi lop
                sxtheoqueQuan();
                for (int i=0; i<soLuongSV; i++) {
                    int dem=1; 
                    while (list[i].queQuan==list[i+1].queQuan&&i<soLuongSV-1)
                    {
                        dem++; 
                        i++; 
                    }
                    cout<<"- So sinh vien tinh, thanh pho "<<list[i].queQuan<<" la: "<<dem<<endl; 
                    tmptinh.soLuongSV=dem; 
                    for (int j=i;dem>0; j-- ) {
                        tmptinh.list[dem-1]=list[j]; 
                        dem--; 
                    }
                    tmptinh.Xuat();  
                    cout <<"So sinh vien gioi : "; cout << tmptinh.demxepLoai("gioi")<<'\n';  
                    cout <<"So sinh vien kha : "; cout << tmptinh.demxepLoai("kha")<<'\n'; 
                    cout <<"So sinh vien trung binh : "; cout <<tmptinh.demxepLoai("tbinh")<<'\n';  
                    cout <<"So sinh vien yeu : "; cout << tmptinh.demxepLoai("yeu")<<'\n';
                }
                break; }
            case 0: break; 
            default:
                cout<<"Lua chon khong hop le.";
                break;
            }
            break;
            //end case 2
        case 3:
            cout<<"Thong ke ve hoc bong: \n";
            cout<<"1. Cua toan truong.\n"; 
            cout<<"2. Cua moi khoa.\n"; 
            cout<<"3. Cua moi khoa, nam vao truong.\n";
            cout<<"4. Cua moi lop.\n"; 
            cout<<"5. Cua moi tinh, thanh pho.\n"; 
            cout<<"0. Dung thong ke.\n"; 
            cout<<"Lua chon cua ban la? "; 
            do {cin>>choose; if (choose>=0&&choose<=5) break;
            else cout<<"khong hop le. Nhap lai: "; } while(1);
            switch (choose)
            {
            case 1:
                //thong ke so nam nu toan truong
                cout<<"Thong ke quy mo toan truong.\n"; 
                cout<<"Tong so sinh vien : "; cout << soLuongSV <<'\n'; 
                cout <<"So sinh vien dat hoc bong 200% : "; cout << demhocBong(200)<<'\n';  
                cout <<"So sinh vien dat hoc bong 100% : "; cout << demhocBong(100)<<'\n'; 
                cout <<"So sinh vien khong dat hoc bong: "; cout << demhocBong(0)<<'\n';
                break;
            case 2:
                CK.Xuat(); 
                cout<<CK.getsoLuongKHoa(); 
                //thong ke so nam nu moi khoa
                for (int i=0; i<CK.getsoLuongKHoa(); i++) {
                    cout<<"+ Khoa: "<<CK.gettenKhoa(i)<<'\n'; 
                    tktheomaKhoa(CK.getmaKhoa(i)).Xuat(); 
                    cout<<"Tong so sinh vien : "; cout << tktheomaKhoa(CK.getmaKhoa(i)).soLuongSV <<'\n'; 
                    cout <<"So sinh vien dat hoc bong 200% : "; cout << tktheomaKhoa(CK.getmaKhoa(i)).demhocBong(200)<<'\n';  
                    cout <<"So sinh vien dat hoc bong 100% : "; cout << tktheomaKhoa(CK.getmaKhoa(i)).demhocBong(100)<<'\n'; 
                    cout <<"So sinh vien khong dat hoc bong: "; cout << tktheomaKhoa(CK.getmaKhoa(i)).demhocBong(0)<<'\n';
                }
                break;
            case 3:
                static danhsachsinhvien tmpkhoa;
                sxtheolop();
                //thong ke so nam nu moi khoá năm vào trường.
                for (int i=0; i<soLuongSV; i++) {
                    cout<<"+ Khoa, nam vao truong : "<<list[i].lop.substr(0,2)<<'\n'; 
                    int dem=1; 
                    while (list[i].lop.compare(0,2,list[i+1].lop,0,2)==0 && i<soLuongSV-1) {
                        dem++; 
                        i++; 
                    }
                    cout<<"Tong so sinh vien : "; cout << dem <<'\n';
                    tmpkhoa.soLuongSV=dem; 
                    for (int j=i;dem>0; j-- ) {
                        tmpkhoa.list[dem-1]=list[j]; 
                        dem--; 
                    }
                    tmpkhoa.Xuat(); 
                    cout <<"So sinh vien dat hoc bong 200% : "; cout << tmpkhoa.demhocBong(200)<<'\n';  
                    cout <<"So sinh vien dat hoc bong 100% : "; cout << tmpkhoa.demhocBong(100)<<'\n'; 
                    cout <<"So sinh vien khong dat hoc bong: "; cout << tmpkhoa.demhocBong(0)<<'\n';
                }
                break;
            case 4:{
                static danhsachsinhvien tmp;
                //thong ke so nam nu moi lop
                sxtheolop();
                for (int i=0; i<soLuongSV; i++) {
                    int dem=1; 
                    while (list[i].lop==list[i+1].lop&&i<soLuongSV-1)
                    {
                        dem++; 
                        i++; 
                    }
                    cout<<"- So sinh vien lop "<<list[i].lop<<" la: "<<dem<<endl; 
                    tmp.soLuongSV=dem; 
                    for (int j=i;dem>0; j-- ) {
                        tmp.list[dem-1]=list[j]; 
                        dem--; 
                    }
                    tmp.Xuat(); 
                    cout <<"So sinh vien dat hoc bong 200% : "; cout << tmp.demhocBong(200)<<'\n';  
                    cout <<"So sinh vien dat hoc bong 100% : "; cout << tmp.demhocBong(100)<<'\n'; 
                    cout <<"So sinh vien khong dat hoc bong: "; cout << tmp.demhocBong(0)<<'\n'; 
                }
                break; }
            case 5:{
                static danhsachsinhvien tmptinh;
                //thong ke so nam nu moi lop
                sxtheoqueQuan();
                for (int i=0; i<soLuongSV; i++) {
                    int dem=1; 
                    while (list[i].queQuan==list[i+1].queQuan&&i<soLuongSV-1)
                    {
                        dem++; 
                        i++; 
                    }
                    cout<<"- So sinh vien tinh, thanh pho "<<list[i].queQuan<<" la: "<<dem<<endl; 
                    tmptinh.soLuongSV=dem; 
                    for (int j=i;dem>0; j-- ) {
                        tmptinh.list[dem-1]=list[j]; 
                        dem--; 
                    }
                    tmptinh.Xuat(); 
                    cout <<"So sinh vien dat hoc bong 200% : "; cout << tmptinh.demhocBong(200)<<'\n';  
                    cout <<"So sinh vien dat hoc bong 100% : "; cout << tmptinh.demhocBong(100)<<'\n'; 
                    cout <<"So sinh vien khong dat hoc bong: "; cout << tmptinh.demhocBong(0)<<'\n';
                }
                break; }
            case 0: break; 
            default:
                cout<<"Lua chon khong hop le.";
                break;
            }
            break;
        case 0:
            break;
        default:
            cout<<"Lua chon khong hop le."; 
            break;
        }
        cout<<"ban co muon thong ke tiep ko? (Y,N) "; cin>>choice; 
        if (choice=='N'||choice=='n') break; 
    } while (1); 
}
int danhsachsinhvien::demgioiTinh(bool b) {
    int dem=0;
    for (int i=0; i<soLuongSV; i++) {
        if (list[i].gioiTinh==b) dem++;
    }
    return dem; 
}
int danhsachsinhvien::demxepLoai(string b) {
    int dem=0;
    for (int i=0; i<soLuongSV; i++) {
        if (list[i].xepLoai()==b) dem++;
    }
    return dem; 
}
int danhsachsinhvien::demhocBong(int b) {
    int dem=0;
    for (int i=0; i<soLuongSV; i++) {
        if (list[i].diem.hocBong==b) dem++;
    }
    return dem; 
}