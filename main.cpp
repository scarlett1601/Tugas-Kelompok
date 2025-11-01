#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct nilai{
    float Mtk;
    float BIn;
    float Big;
    float IPA;
    float akhir;
};
struct siswa{
    string nama;
    string NISN;
    string jurusan;
    nilai Nilai; // struct in struct
};

void tambahDataSiswa() {
    int jumlahSiswa;
    cout << "Berapa banyak siswa yang ingin anda tambahkan? ";
    cin >> jumlahSiswa;
    cin.ignore();

    ofstream fileOutput("Datasiswa.txt",ios::app);

    for(int i=0;i<jumlahSiswa;i++) {
    siswa data;
    cout << "Masukkan Data Siswa ke-" << i+1 << endl;
    cout << "Nama : ";
    getline(cin,data.nama);
    cout << "Nisn : ";
    getline(cin,data.NISN);
    cout << "Jurusan : ";
    getline(cin,data.jurusan);
    cout << "Nilai dari "<<data.nama<<endl;
    cout << "Nilai Matematika : ";
    cin >> data.Nilai.Mtk;
    cout << "Nilai Bahasa Indonesia : ";
    cin >> data.Nilai.BIn;
    cout << "Nilai Bahasa Inggris : ";
    cin >> data.Nilai.Big;
    cout << "Nilai IPA : ";
    cin >> data.Nilai.IPA;
    cin.ignore();

    fileOutput << "Nama  : " << data.nama<< " - " << "NISN : " << data.NISN<< " - " << "Jurusan : "<< data.jurusan<<endl;
    fileOutput << "Nilai dari "<<data.nama<<" / "
               << "Matematika : "<<data.Nilai.Mtk<<", "
               << "Bahasa Indonesia : "<<data.Nilai.BIn<<", "
               << "Nilai Bahasa Inggris : "<<data.Nilai.Big<<", "
               << "Nilai IPA : "<<data.Nilai.IPA<<endl;

    
    }
    fileOutput.close();
    cout << "Data Tersimpan"<<endl;

}//menambahkan data pada file siswa.txt

void tampilDataSiswa(){
    ifstream fileOutput("Datasiswa.txt");
    string baris;

    while(getline(fileOutput,baris)){
        cout << baris << endl;
    }

    fileOutput.close();
}//membaca data dari file siswa.txt dan ditampilkan

void cariSiswa();// berdasarkan NISN

float nilaiAkhir(nilai n){
    return (n.Mtk*0.4)+(n.IPA*0.3)+(n.BIn*0.2)+(n.BIn*0.2);
    
};// nilai akhir = 40%matematika+30%IPA+20%B indonesia +20%B Inggris

void ranking(Siswa data[], int jumlahSiswa) { // menampilkan data siswa berdasarkan peringkatnya
    // bubble sort berdasarkan rata-rata nilai (descending)
    for (int i = 0; i < jumlahSiswa - 1; i++) {
        for (int j = 0; j < jumlahSiswa - i - 1; j++) {
            float rata1 = (data[j].nilai.mat + data[j].nilai.bind + data[j].nilai.bing + data[j].nilai.ipa) / 4;
            float rata2 = (data[j+1].nilai.mat + data[j+1].nilai.bind + data[j+1].nilai.bing + data[j+1].nilai.ipa) / 4;
            
            if (rata1 < rata2) {
                // tukar posisi
                Siswa temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    // tampilkan ranking
    cout << "\n=== PERINGKAT SISWA ===" << endl;
    for (int i = 0; i < jumlahSiswa; i++) {
        float rata = (data[i].nilai.mat + data[i].nilai.bind + data[i].nilai.bing + data[i].nilai.ipa) / 4;
        cout << i + 1 << ". " << data[i].nama << " (" << rata << ")" << endl;
    }
}

int main()
{
    int menu;
    cout << "Pilih Menu"<<endl;
    cout << "1. Tambah Data Siswa"<<endl;
    cout << "2. Tampil Data Siswa";
    cout << "Pilih Menu : ";
    cin >> menu;

    if(menu==1){
        tambahDataSiswa();
    }

    if(menu==2){
        tampilDataSiswa();
    }

  return 0;
}
