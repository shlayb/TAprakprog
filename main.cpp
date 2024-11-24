#include <iostream>
#include <iomanip>
using namespace std;

const int jamKerjaWajib = 170;
const float gajiPokokPerJamKaryawan = 20000;
const float gajiLemburPerJamKaryawan = 30000;
const float gajiPokokPerJamManager = 30000;
const float gajiLemburPerJamManager = 40000;
const float gajiPokokPerJamDirektur = 40000;
const float gajiLemburPerJamDirektur = 50000;
string temp; 

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
  // sort by id anggota
  for(int i = 0; i < jumlahKaryawan; i++){
    for(int j = 0; j < jumlahKaryawan; j++){
      if(karyawan[i].IdAnggota() < karyawan[j].IdAnggota()){
        DataKaryawan temp = karyawan[i];
        karyawan[i] = karyawan[j];
        karyawan[j] = temp;
      }
    }
  }
  for(int i = 0; i < jumlahKaryawan; i++){
    if(karyawan[i].nama != ""){
      cout << left << "| " << setw(3) << i+1 << " | " << setw(14) << karyawan[i].nama << " | " << setw(16) << karyawan[i].IdAnggota() << " | " << setw(10) << karyawan[i].jamKerjaPokok << " | " << setw(9) << karyawan[i].jamLembur << " | " << setw(14) << "Rp." << karyawan[i].gajiTotal() << "|" << endl;
    }
  }
  cout << "=====================================================================================" << endl;
  cout << "Tekan Enter untuk melanjutkan..."; 
  cin.ignore(); 
  cin.get();
}

int main(){
  const int maxKaryawan = 100;
  bool isRunning = true;
  int jumlahKaryawan = 0;
  DataKaryawan* karyawan = new DataKaryawan[maxKaryawan];

  while(isRunning){
    system("cls");
    int pilihan = 0;
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
      cout << "1. Karyawan" << endl;
      cout << "2. Manager" << endl;
      cout << "3. Direktur" << endl;
      cout << "Pilih Jabatan : "; cin >> pilihan;
      if(pilihan == 1){
        karyawan[jumlahKaryawan].jabatan = "karyawan";
      } else if(pilihan == 2){
        karyawan[jumlahKaryawan].jabatan = "manager";
      } else if(pilihan == 3){
        karyawan[jumlahKaryawan].jabatan = "direktur";
      }
      cout << "======================================" << endl;
      cout << "Nama : "; cin >> karyawan[jumlahKaryawan].nama;
      cout << "Tanggal Lahir : "; cin >> karyawan[jumlahKaryawan].tanggalLahir;
      cout << "Bulan Lahir : "; cin >> karyawan[jumlahKaryawan].bulanLahir;
      cout << "Tahun Daftar : "; cin >> karyawan[jumlahKaryawan].tahunDaftar;
      cout << "IdAnggota Karyawan : " << karyawan[jumlahKaryawan].IdAnggota() << endl;
      cout << "======================================" << endl;
      cout << "Karyawan Berhasil Ditambahkan" << endl;
      cout << "Tekan Enter untuk melanjutkan..."; 
      cin.ignore(); 
      cin.get();
      jumlahKaryawan++;
    } else if(pilihan == 2){
      LihatKaryawan(karyawan, jumlahKaryawan);
    } else if(pilihan == 3){
      bool isPresensi = true;
      while(isPresensi){
        system("cls");
        string idKaryawan;
        cout << "============Presensi Karyawan============" << endl;
        cout << "1. Masuk" << endl;
        cout << "2. Keluar" << endl;
        cout << "Pilih Menu : "; cin >> pilihan;
        if(pilihan == 1){
          cout << "=========================================" << endl;
          cout << "Id Karyawan : "; cin >> idKaryawan;
          int index_temp = -1;
          for(int i = 0; i < jumlahKaryawan; i++){
            if(karyawan[i].IdAnggota() == idKaryawan){
              index_temp = i;
            }
          }
          if(index_temp == -1){
            cout << "Id Karyawan Tidak Ditemukan" << endl;
          } else{
            cout << "Jam Masuk : "; cin >> karyawan[index_temp].jamMasuk;
            cout << "=========================================" << endl;
            cout << "Presensi Berhasil" << endl;
          }
          cout << "Apakah Anda Ingin Melakukan Presensi Lagi? (y/n) : "; cin >> temp;
          if(temp == "n" || temp == "N"){
            isPresensi = false;
          }
        } else if (pilihan == 2){
          cout << "=========================================" << endl;
          cout << "Id Karyawan : "; cin >> idKaryawan;
          int index_temp = -1;
          for(int i = 0; i < jumlahKaryawan; i++){
            if(karyawan[i].IdAnggota() == idKaryawan){
              index_temp = i;
            }
          }
          if(index_temp == -1){
            cout << "Id Karyawan Tidak Ditemukan" << endl;
          } else{
            cout << "Jam Keluar : "; cin >> karyawan[index_temp].jamKeluar;
            cout << "=========================================" << endl;
              cout << "Presensi Berhasil" << endl;
              int jam_temp = karyawan[0].jamKeluar - karyawan[0].jamMasuk;
              if(jam_temp <= 8){
                karyawan[index_temp].jamKerjaPokok += jam_temp;
              } else{
                karyawan[index_temp].jamKerjaPokok += 8;
                karyawan[index_temp].jamLembur += jam_temp - 8;
              }
          }
          cout << "Apakah Anda Ingin Melakukan Presensi Lagi? (y/n) : "; cin >> temp;
          if(temp == "n" || temp == "N"){
            isPresensi = false;
          }
        }
      }
    } else if(pilihan == 4){
      system("cls");
      cout << "============Tarik Gaji Karyawan============" << endl;
      cout << "Id Karyawan : "; cin >> temp;
      int index_temp = -1;
      for(int i = 0; i < jumlahKaryawan; i++){
        if(karyawan[i].IdAnggota() == temp){
          index_temp = i;
        }
      }
      if(index_temp == -1){
        cout << "Id Karyawan Tidak Ditemukan" << endl;
      } else{
        cout << "=========================================" << endl;
        cout << "Nama : " << karyawan[index_temp].nama << endl;
        cout << "Jabatan : " << karyawan[index_temp].jabatan << endl;
        cout << "Gaji Pokok : Rp." << karyawan[index_temp].gajiPokok() << endl;
        cout << "Gaji Lembur : Rp." << karyawan[index_temp].gajiLembur() << endl;
        cout << "Total Gaji : Rp." << karyawan[index_temp].gajiTotal() << endl;
        cout << "=========================================" << endl;
        cout << "Gaji Berhasil Ditarik" << endl;
        karyawan[index_temp].jamKerjaPokok = 0;
        karyawan[index_temp].jamLembur = 0;

      }
      cout << "Tekan Enter untuk melanjutkan...";
      cin.ignore();
      cin.get();
    } else if(pilihan == 5){
      isRunning = false;
    }else{
      cout << "Menu Tidak Tersedia" << endl;
      cout << "Tekan Enter untuk melanjutkan..."; 
      cin.ignore(); 
      cin.get();
    }
  }
  cout << "Terima Kasih" << endl;
  delete[] karyawan;
  return 0;
}