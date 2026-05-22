#include <iostream>

using namespace std;

struct Data {
    string nama_ujian;
    int nilai;
} d[20];

int banyakData = 0;

void inputData (int banyak) {
    cout << "\n=====================\n";
    cout << "  Input Data Ujian\n";
    cout << "=====================\n";

    if (banyak + banyakData > 20) {
        cout << "Maaf, program telah menampung maksimal data. Silakan close dan coba lagi nanti!\n";
    } else {
        int batasAkhir = banyakData + banyak;
        for (int i = banyakData; i < batasAkhir; i++) {
            cout << "Nama ujian : "; getline(cin >> ws, d[i].nama_ujian);
            cout << "Nilai      : "; cin >> d[i].nilai;
            banyakData += 1;
            cout << endl;
        }
    }
}

void viewData (int banyak) {
    cout << "\n=====================\n";
    cout << "   List Data Ujian\n";
    cout << "=====================\n";

    if (banyakData == 0) {
        cout << "Data kosong!\n";
    } else {
        for(int i = 0; i < banyakData; i++) {
            cout << "Data ke- " << i + 1 << endl;
            cout << "Nama ujian : " << d[i].nama_ujian << endl;
            cout << "Nilai      : " << d[i].nilai << endl;
            cout << "---------------------\n";
        }
    }
}

void editData (int banyak) {
    cout << "\n=====================\n";
    cout << "   Edit Data Ujian\n";
    cout << "=====================\n";

    if (banyak + banyakData == 0) {
        cout << "Data kosong!\n";
    } else {
        for (int i = 0; i < banyak - 1; i++) {
            string cariNama;
            cout << "Masukkan nama ujian yang ingin diedit: "; getline(cin >> ws, cariNama);
                if (cariNama != d[i].nama_ujian) {
                    cout << "Data tidak ditemukan!\n";
                } else {
                    int nilaiBaru;
                    cout << "Nilai baru: "; cin >> nilaiBaru;
                    d[i].nilai = nilaiBaru;
                    cout << "\nNilai dengan nama ujian " << d[i].nama_ujian << " berhasil diubah!\n";
                    cout << "---------------------\n";
                }
        }
    }
}

int fibonacci (int angka) {
    if (angka == 0) return angka;
    else if (angka == 1) return angka;
    else return fibonacci(angka - 1) + fibonacci(angka - 2);
}

int factorial (int angka) {
    if (angka <= 1) return 1;
    else return angka * factorial(angka-1);
}

void bubbleSort (int banyak) {
    cout << "=== SEBELUM DISORTING ===\n";
    for(int i = 0; i < banyak - 1; i++) {
        cout << "Data ke- " << i + 1 << endl;
        cout << "Nama ujian : " << d[i].nama_ujian << endl;
        cout << "Nilai      : " << d[i].nilai << endl;
        cout << "---------------------\n";
    }

    for (int i = 0; i < banyak - 1; i++) {
        for (int j = 0; j < banyak - i - 1; j++) {
            if (d[j].nilai > d[j+1].nilai) {
                swap(d[j], d[j+1]);
            }
        }
    }

    cout << "\n=== SETELAH DISORTING ===\n";
    for(int i = 0; i < banyak - 1; i++) {
        cout << "Data ke- " << i + 1 << endl;
        cout << "Nama ujian : " << d[i].nama_ujian << endl;
        cout << "Nilai      : " << d[i].nilai << endl;
        cout << "---------------------\n";
    }

    cout << "Data berhasil diurutkan! (Bubble Sort)\n";
}

int main () {
    int choice, banyak;

    do {
    cout << "\n==========================\n";
    cout << "          MENU\n";
    cout << "==========================\n";
    cout << "1. Input data\n";
    cout << "2. View data\n";
    cout << "3. Edit data\n";
    cout << "4. Recursive\n";
    cout << "5. Search data\n";
    cout << "6. Sorting data\n";
    cout << "7. Export and import data\n";
    cout << "===========================\n";
    cout << "Choose: "; cin >> choice;


    switch (choice) {
        case 1: {
            cout << "Berapa banyak data yang Anda ingin input? "; cin >> banyak;
                if (banyak + banyakData > 20) {
                    cout << "\nMaaf, array telah kami batasi hingga maksimal 20 data saja.";
                    break;
                } else {
                    inputData(banyak);
                }
            cout << "\nPress any key to continue . . .\n";
            cin.ignore();
            cin.get();
            break;
        } case 2: {
            viewData(banyakData);
            cout << "\nPress any key to continue . . .\n";
            cin.ignore();
            cin.get();
            break;
        } case 3: {
            editData(banyakData);
            cout << "\nPress any key to continue . . .\n";
            cin.ignore();
            cin.get();
            break;
        } case 4: {
            int pilih;
            bool inputValid = false;
            int angkaUser;
            
            do {
                cout << "==================\n";
                cout << "     Rekursif\n";
                cout << "==================\n";
                cout << "Pilih Fibonacci (0) atau Faktorial (1)\n"; 
                cout << "Pilih: "; cin >> pilih;
                
                if (pilih != 0 && pilih != 1) {
                    cout << "Maaf, input Anda tidak valid. Coba lagi";
                } else {
                    int hasil;
                    inputValid = true;
                    if (pilih == 0) {
                        cout << "Masukkan angka Anda di sini: "; cin >> angkaUser;
                        hasil = fibonacci(angkaUser);
                        cout << "Hasil rekursif - fibonacci: " << hasil << endl;
                    } else {
                        cout << "Masukkan angka Anda di sini: "; cin >> angkaUser;
                        hasil = factorial(angkaUser);
                        cout << "Hasil rekursif - factorial: " << hasil << endl;
                    }
                }
            } while(!inputValid); 

            cout << "\nPress any key to continue . . .\n";
            cin.ignore();
            cin.get();
            break;
        } case 5: {
            break;
        } case 6: {
            int respon;
            cout << "==================\n";
            cout << "    Sort Ujian\n";
            cout << "==================\n";
            cout << " [1] Bubble sort\n"; 
            cout << " [2] Selection sort\n";
            cout << " [3] Insertion sort\n";
            cout << " [4] Shell sort\n";
            cout << " [5] Quick sort\n";
            cout << "Pilih: "; cin >> respon;
            if (respon == 1) {bubbleSort(banyakData);}
            else if (respon == 2) {}
            break;
        } case 7: {
            break;
        } case 0: {
            cout << "Anda telah keluar dari program.";
            return 0;
        } default: {
            cout << "Mohon pilih menu dari 0-7 saja!\n";
            break;
        }
    }
    } while (choice > 0);
}