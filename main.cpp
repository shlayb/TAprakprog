#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int jamKerjaWajib = 170;
const float gajiPokokPerJamKaryawan = 20000;
const float gajiLemburPerJamKaryawan = 30000;
const float gajiPokokPerJamManager = 30000;
const float gajiLemburPerJamManager = 40000;
const float gajiPokokPerJamDirektur = 40000;
const float gajiLemburPerJamDirektur = 50000;

struct DataKaryawan {
    string nama;
    string jabatan;
    float jamKerjaPokok;
    float jamLembur;
    int jamMasuk;
    int jamKeluar;
    string tanggalLahir;
    string bulanLahir;
    string tahunDaftar;
    float gajiPokok(){
      if(jabatan == "karyawan"){
        return gajiPokokPerJamKaryawan * jamKerjaPokok;
      } else if(jabatan == "manager"){
        return gajiPokokPerJamManager * jamKerjaPokok;
      } else if(jabatan == "direktur"){
        return gajiPokokPerJamDirektur * jamKerjaPokok;
      }
    };
    float gajiLembur(){
      if(jabatan == "karyawan"){
        return gajiLemburPerJamKaryawan * jamLembur;
      } else if(jabatan == "manager"){
        return gajiLemburPerJamManager * jamLembur;
      } else if(jabatan == "direktur"){
        return gajiLemburPerJamDirektur * jamLembur;
      }
    };
    float gajiTotal(){
      return gajiPokok() + gajiLembur();
    }
    string IdAnggota(){
      if(jabatan == "karyawan"){
        return "01" + string(1, tahunDaftar[2]) + string(1, tahunDaftar[3]) + bulanLahir + tanggalLahir;
      } else if(jabatan == "manager"){
        return "02" + string(1, tahunDaftar[2]) + string(1, tahunDaftar[3]) + bulanLahir + tanggalLahir;
      } else if(jabatan == "direktur"){
        return "03" + string(1, tahunDaftar[2]) + string(1, tahunDaftar[3]) + bulanLahir + tanggalLahir;
      }
    };
};

void LihatKaryawan(DataKaryawan karyawan[], int jumlahKaryawan){
    system("cls");
    cout << "==================================Daftar Karyawan====================================" << endl;
    cout << "| No. | Nama           | Id Anggota       | Jam Pokok | Jam Lembur | Total Gaji     |" << endl;
    cout << "=====================================================================================" << endl;
      for(int i = 0; i < jumlahKaryawan; i++){
        if(karyawan[i].nama != ""){
            cout << left << "| " << setw(3) << i+1 << " | " << setw(14) << karyawan[i].nama << " | " << setw(16) << karyawan[i].IdAnggota() << " | " << setw(10) << karyawan[i].jamKerjaPokok << " | " << setw(9) << karyawan[i].jamLembur << " | " << setw(14) << "Rp." << karyawan[i].gajiTotal() << "|" << endl;
      }
    }
    cout << "=====================================================================================" << endl;
    string temp; cin >> temp; cin.ignore();
}


int main(){
  const int maxKaryawan = 100;
  bool isRunning = true;
  int jumlahKaryawan = 0;
  DataKaryawan karyawan[maxKaryawan];

  while(isRunning){
    system("cls");
    int pilihan = 0;
    string temp; 
    cout << "============Selamat Datang di PT.Doa Ibu============" << endl;
    cout << "1. Tambah Karyawan" << endl;
    cout << "2. Lihat Karyawan" << endl;
    cout << "3. Presensi" << endl;
    cout << "4. Tarik Gaji" << endl;
    cout << "5. Keluar" << endl;
    cout << "====================================================" << endl;
    cout << "Pilih Menu : "; cin >> pilihan;
    if(pilihan == 1){
      system("cls");
      cout << "============Tambah Karyawan============" << endl;
      cout << "Nama : "; cin >> karyawan[jumlahKaryawan].nama;
      cout << "Jabatan : "; cin >> karyawan[jumlahKaryawan].jabatan;
      cout << "Tanggal Lahir : "; cin >> karyawan[jumlahKaryawan].tanggalLahir;
      cout << "Bulan Lahir : "; cin >> karyawan[jumlahKaryawan].bulanLahir;
      cout << "Tahun Daftar : "; cin >> karyawan[jumlahKaryawan].tahunDaftar;
      cout << "IdAnggota Karyawan : " << karyawan[jumlahKaryawan].IdAnggota() << endl;
      cout << "======================================" << endl;
      cout << "Karyawan Berhasil Ditambahkan" << endl;
      cin >> temp; cin.ignore();
      jumlahKaryawan++;
    } else if(pilihan == 2){
      LihatKaryawan(karyawan, jumlahKaryawan);
    }else if(pilihan == 3){
      system("cls");
      string idKaryawan;
      cout << "============Presensi Karyawan============" << endl;
      cout << "1. Masuk" << endl;
      cout << "2. Keluar" << endl;
      cout << "Pilih Menu : "; cin >> pilihan;
      if(pilihan == 1){
        cout << "=========================================" << endl;
        cout << "Id Karyawan : "; cin >> idKaryawan;
        for(int i = 0; i < jumlahKaryawan; i++){
          if(karyawan[i].IdAnggota() == idKaryawan){
            cout << "Jam Masuk : "; cin >> karyawan[i].jamMasuk;
            cout << "=========================================" << endl;
            cout << "Presensi Berhasil" << endl;
            cin >> temp; cin.ignore();
          }}
        }else if (pilihan == 2){
          cout << "=========================================" << endl;
          cout << "Id Karyawan : "; cin >> idKaryawan;
          for(int i = 0; i < jumlahKaryawan; i++){
            if(karyawan[i].IdAnggota() == idKaryawan){
              cout << "Jam Keluar : "; cin >> karyawan[i].jamKeluar;
              cout << "=========================================" << endl;
              cout << "Presensi Berhasil" << endl;
              int jam_temp = karyawan[0].jamKeluar - karyawan[0].jamMasuk;
              if(jam_temp <= 8){
                karyawan[i].jamKerjaPokok += jam_temp;
              } else{
                karyawan[i].jamKerjaPokok += 8;
                karyawan[i].jamLembur += jam_temp - 8;
              }
              }
            }
          }
        } else if(pilihan == 4){
          system("cls");
          cout << "============Tarik Gaji Karyawan============" << endl;
       }
    }
} 