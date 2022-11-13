#include <iostream>
#include <string>
#include <sstream>

using namespace std;

    string formatangka(int nilai, string a = "."){
    stringstream ss; ss << nilai;
    string out = ss.str();
    int in = out.length() - 3;
    while(in > 0){
        out.insert(in, a);
        in -= 3;
    }
    return out;

}

void Peringatan(int harga){
    int pajak;
    if(harga >= 400000){
        pajak = harga * 0.15;
        harga += pajak;
        cout<<"Karena Penggunaan Listrik anda melebihi Rp 400.000, maka kami terpaksa memberikan pajak 15% yaitu Rp. "<<formatangka(pajak)<<endl;
        cout<<"Karena itu harga yang harus anda bayarkan adalah Rp. "<<formatangka(harga);

    }else if(harga < 400000){
        cout<<"Karena Penggunaan Listrik anda kurang dari Rp 400.000, maka kamitidak memberikan pajak"<<endl;
        cout<<"Karena itu harga yang harus anda bayarkan adalah Rp. "<<formatangka(harga);
    }

}


int main(){
    string nama;
    int watt, kwh, harga;
    int r;

    cout<<"Nama Pelanggan : ";
    cin>>nama; cout<<endl;

    cout<<"Berapa Watt yang digunakan : ";
    cin>>watt; cout<<endl;

    cout<<"Berapa Penggunaan KWH-nya : ";
    cin>>kwh; cout<<endl;

    if(watt <= 450){
        r = 169;
        harga = kwh * r;
    }else if(watt > 450 && watt <= 2200){
        r = 1352;
        harga = kwh * r;

    }else if(watt > 900 && watt <= 2200){
        r = 1467;
        harga = kwh * r;
    }
    cout<<"Yang Terhormat Pelanggan Pak "<<nama<<endl;
    cout<<"Rumah Anda dipasang listrik sebesar "<<watt<<" Watt"<<endl;
    cout<<"Bulan ini menggunakan "<<kwh<<" Kwh"<<endl;
    cout<<"Berarti biaya PLN nya adalah "<<kwh<<" KWH x Rp. "<<formatangka(r)<<" yaitu Rp. "<<formatangka(harga)<<endl;

    Peringatan(harga);
}