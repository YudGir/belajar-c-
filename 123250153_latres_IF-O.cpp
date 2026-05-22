#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Data {
    string nama_ujian;
    int nilai;
};

void inputData (Data d[], int &banyakData, int banyak) {
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
            banyakData ++;
            cout << endl;
        }
    }
}

void viewData (Data d[], int totalData) {
    cout << "\n=====================\n";
    cout << "   List Data Ujian\n";
    cout << "=====================\n";

    if (totalData == 0) {
        cout << "Data kosong!\n";
    }

    for (int i = 0; i < totalData; i++) {
        cout << "Data ke- " << i + 1 << endl;
        cout << "Nama ujian : " << d[i].nama_ujian << endl;
        cout << "Nilai      : " << d[i].nilai << endl;
        cout << "---------------------\n";
    }
}

void editData (Data d[], int totalData) {
    cout << "\n=====================\n";
    cout << "   Edit Data Ujian\n";
    cout << "=====================\n";

    if (totalData == 0) {
        cout << "Data kosong!\n";
        return;
    } 

    bool ketemu = false;
    string cariNama;
    cout << "Masukkan nama ujian yang ingin diedit: "; getline(cin >> ws, cariNama);

    for (int i = 0; i < totalData; i++) {
        if (cariNama == d[i].nama_ujian) {
            int nilaiBaru;
            cout << "Nilai baru: "; cin >> nilaiBaru;
            d[i].nilai = nilaiBaru;
            cout << "---------------------\n";
            cout << "\nNilai dengan nama ujian " << d[i].nama_ujian << " berhasil diubah!\n";
            ketemu = true;
            break;
        }
    } 
    
    if (!ketemu) {
        cout << "Data tidak ditemukan!\n";
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

int nonSentinelSearch(Data d[], int totalData, string cariNama) {
    for (int i = 0; i < totalData; i++) {
        if (d[i].nama_ujian == cariNama) {
            return i; 
        }
    }
    return -1; 
}

int sentinelSearch(Data d[], int totalData, string cariNama) {
    d[totalData].nama_ujian = cariNama; 
    int i = 0;

    while (d[i].nama_ujian != cariNama) {
        i++;
    }

    if (i < totalData) {
        return i;
    }
    return -1;
}

int binarySearch(Data d[], int totalData, string cariNama) {
    int low = 0;
    int high = totalData - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (d[mid].nama_ujian == cariNama) {
            return mid;
        }
        if (d[mid].nama_ujian < cariNama) {
            low = mid + 1;
        } else {
            high = mid - 1; 
        }
    }
    return -1;
}

void sortNamaUjian(Data d[], int totalData) {
    for (int i = 0; i < totalData - 1; i++) {
        for (int j = 0; j < totalData - i - 1; j++) {
            if (d[j].nama_ujian > d[j+1].nama_ujian) {
                swap(d[j], d[j+1]);
            }
        }
    }
}

void bubbleSort (Data d[], int totalData) {
    cout << "=== SEBELUM DISORTING ===\n";
    for(int i = 0; i < totalData; i++) {
        cout << "Data ke- " << i + 1 << endl;
        cout << "Nama ujian : " << d[i].nama_ujian << endl;
        cout << "Nilai      : " << d[i].nilai << endl;
        cout << "---------------------\n";
    }

    for (int i = 0; i < totalData - 1; i++) {
        for (int j = 0; j < totalData - i - 1; j++) {
            if (d[j].nilai > d[j+1].nilai) {
                swap(d[j], d[j+1]);
            }
        }
    }

    cout << "\n=== SETELAH DISORTING ===\n";
    for(int i = 0; i < totalData; i++) {
        cout << "Data ke- " << i + 1 << endl;
        cout << "Nama ujian : " << d[i].nama_ujian << endl;
        cout << "Nilai      : " << d[i].nilai << endl;
        cout << "---------------------\n";
    }

    cout << "Data berhasil diurutkan! (Bubble Sort)\n";
}

void selectionSort(Data d[], int totalData) {
    cout << "=== SEBELUM DISORTING ===\n";
    for(int i = 0; i < totalData; i++) {
        cout << "Data ke- " << i + 1 << endl;
        cout << "Nama ujian : " << d[i].nama_ujian << endl;
        cout << "Nilai      : " << d[i].nilai << endl;
        cout << "---------------------\n";
    }

    for (int i = 0; i < totalData - 1; i++) {
        int idxMin = i;
        for (int j = i + 1; j < totalData; j++) {
            if (d[j].nilai < d[idxMin].nilai) {
                idxMin = j;
            }
        }
        swap(d[i], d[idxMin]);
    }

    cout << "\n=== SETELAH DISORTING ===\n";
    for(int i = 0; i < totalData; i++) {
        cout << "Data ke- " << i + 1 << endl;
        cout << "Nama ujian : " << d[i].nama_ujian << endl;
        cout << "Nilai      : " << d[i].nilai << endl;
        cout << "---------------------\n";
    }

    cout << "Data berhasil diurutkan! (Selection Sort)\n";
}


void insertionSort(Data d[], int totalData) {
    cout << "\n=== SEBELUM DISORTING ===\n";
    for(int i = 0; i < totalData; i++) {
        cout << "Data ke- " << i + 1 << endl;
        cout << "Nama ujian : " << d[i].nama_ujian << endl;
        cout << "Nilai      : " << d[i].nilai << endl;
        cout << "---------------------\n";
    }

    for (int i = 1; i < totalData; i++) {
        auto key = d[i];
        int j = i - 1;
        while (j >= 0 && d[j].nilai > key.nilai) {
            d[j + 1] = d[j];
            j--;
        }
        d[j + 1] = key;
    }

    cout << "\n=== SETELAH DISORTING ===\n";
    for(int i = 0; i < totalData; i++) {
        cout << "Data ke- " << i + 1 << endl;
        cout << "Nama ujian : " << d[i].nama_ujian << endl;
        cout << "Nilai      : " << d[i].nilai << endl;
        cout << "---------------------\n";
    }

    cout << "Data berhasil diurutkan! (Insertion Sort)\n";
}

void shellSort(Data d[], int totalData) {
    cout << "\n=== SEBELUM DISORTING ===\n";
    for(int i = 0; i < totalData; i++) {
        cout << "Data ke- " << i + 1 << endl;
        cout << "Nama ujian : " << d[i].nama_ujian << endl;
        cout << "Nilai      : " << d[i].nilai << endl;
        cout << "---------------------\n";
    }

    for (int gap = totalData / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < totalData; i++) {
            auto temp = d[i];
            int j;
            for (j = i; j >= gap && d[j - gap].nilai > temp.nilai; j -= gap) {
                d[j] = d[j - gap];
            }
            d[j] = temp;
        }
    }

    cout << "\n=== SETELAH DISORTING ===\n";
    for(int i = 0; i < totalData; i++) {
        cout << "Data ke- " << i + 1 << endl;
        cout << "Nama ujian : " << d[i].nama_ujian << endl;
        cout << "Nilai      : " << d[i].nilai << endl;
        cout << "---------------------\n";
    }

    cout << "Data berhasil diurutkan! (Shell Sort)\n";
}

int partition(Data d[], int low, int high) {
    int pivot = d[high].nilai; 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (d[j].nilai < pivot) {
            i++;
            swap(d[i], d[j]);
        }
    }
    swap(d[i + 1], d[high]);
    return (i + 1);
}

void quickSort(Data d[], int low, int high) {
    if (low < high) {
        int pi = partition(d, low, high);
        
        quickSort(d, low, pi - 1);
        quickSort(d, pi + 1, high);
    }
}

void quickSortMenu(Data d[], int totalData) {
    cout << "\n=== SEBELUM DISORTING ===\n";
    for(int i = 0; i < totalData; i++) {
        cout << "Data ke- " << i + 1 << endl;
        cout << "Nama ujian : " << d[i].nama_ujian << endl;
        cout << "Nilai      : " << d[i].nilai << endl;
        cout << "---------------------\n";
    }

    quickSort(d, 0, totalData - 1);

    cout << "\n=== SETELAH DISORTING ===\n";
    for(int i = 0; i < totalData; i++) {
        cout << "Data ke- " << i + 1 << endl;
        cout << "Nama ujian : " << d[i].nama_ujian << endl;
        cout << "Nilai      : " << d[i].nilai << endl;
        cout << "---------------------\n";
    }

    cout << "Data berhasil diurutkan! (Quick Sort)\n";
}

void exportData(Data d[], int totalData) {
    if (totalData == 0) {
        cout << "Tidak ada data yang bisa diexport!\n";
        return;
    }

    ofstream fileTersimpan("data_ujian.txt");

    if (fileTersimpan.is_open()) {
        for (int i = 0; i < totalData; i++) {
            fileTersimpan << d[i].nama_ujian << endl;
            fileTersimpan << d[i].nilai << endl;
        }
        fileTersimpan.close();
        cout << "Data berhasil diexport ke 'data_ujian.txt'!\n";
    } else {
        cout << "Gagal membuka file untuk export!\n";
    }
}

void importData() {
    ifstream fileMasuk("data_ujian.txt");

    if (!fileMasuk.is_open()) {
        cout << "File 'data_ujian.txt' tidak ditemukan!\n";
        return;
    }

    cout << "=========================================\n";
    cout << "     Preview Data dari File (Import)\n";
    cout << "=========================================\n";

    string namaUjian[20];
    int nilaiUjian[20];
    int hitungData = 0;

    while (hitungData < 20 && getline(fileMasuk >> ws, namaUjian[hitungData])) {
        fileMasuk >> nilaiUjian[hitungData]; 
        hitungData++;
    }

    fileMasuk.close();

    cout << "\nTotal data di dalam file: " << hitungData << " data.\n\n";

    for (int i = 0; i < hitungData; i++) {
        cout << "Data File ke-" << i + 1 << endl;
        cout << "Nama Ujian : " << namaUjian[i] << endl;
        cout << "Nilai      : " << nilaiUjian[i] << endl;
        cout << "---------------------\n";
    }
}

int main () {
    Data d[21];
    int banyakData = 0;
    int choice, respon;

    do {
    cout << "\n==========================\n";
    cout << "    TAMPILAN MENU UTAMA\n";
    cout << "==========================\n";
    cout << "1. Input data\n";
    cout << "2. View data\n";
    cout << "3. Edit data\n";
    cout << "4. Recursive\n";
    cout << "5. Search data\n";
    cout << "6. Sorting data\n";
    cout << "7. Export and import data\n";
    cout << "0. Keluar\n";
    cout << "===========================\n";
    cout << "Pilih: "; cin >> choice;


    switch (choice) {
        case 1: {
            int banyakBaru;
            cout << "Berapa banyak data yang Anda ingin input? "; cin >> banyakBaru;
                if (banyakBaru + banyakData > 20) {
                    cout << "\nMaaf, array telah kami batasi hingga maksimal 20 data saja.";
                    break;
                } else {
                    inputData(d, banyakData, banyakBaru);
                }
            cout << "\nPress any key to continue . . .\n";
            cin.ignore();
            cin.get();
            break;
        } case 2: {
            viewData(d, banyakData);
            cout << "\nPress any key to continue . . .\n";
            cin.ignore();
            cin.get();
            break;
        } case 3: {
            editData(d, banyakData);
            cout << "\nPress any key to continue . . .\n";
            cin.ignore();
            cin.get();
            break;
        } case 4: {
            int pilih;
            bool valid = false;
            
            do {
                cout << "==================\n";
                cout << "     Rekursif\n";
                cout << "==================\n";
                cout << "Pilih Fibonacci (0) atau Faktorial (1)\n"; 
                cout << "Pilih: "; cin >> pilih;
                
                if (pilih != 0 && pilih != 1) {
                    cout << "Input Anda tidak valid!\n";
                } else {
                    int hasil, angkaUser;;
                    valid = true;

                    if (pilih == 0) {
                        cout << "Masukkan angka Anda di sini: "; cin >> angkaUser;
                        hasil = fibonacci(angkaUser);
                        cout << "Hasil rekursif (fibonacci): " << hasil << endl;
                    } else {
                        cout << "Masukkan angka Anda di sini: "; cin >> angkaUser;
                        hasil = factorial(angkaUser);
                        cout << "Hasil rekursif (factorial): " << hasil << endl;
                    }
                }
            } while (!valid); 

            cout << "\nPress any key to continue . . .\n";
            cin.ignore();
            cin.get();
            break;
        } case 5: {
            string cari;
            cout << "\n==================\n";
            cout << "   Search Ujian\n";
            cout << "==================\n";

            if (banyakData == 0) {
                cout << "Data masih kosong!\n";
            } else {
                cout << " [1] Sequential non-sentinel\n"; 
                cout << " [2] Sequential sentinel\n";
                cout << " [3] Binary search\n";
                cout << "Pilih: "; cin >> respon;
                cout << "Masukkan nama ujian: "; getline(cin >> ws, cari);

                if (respon < 1 || respon > 3) {cout << "Mohon input nomor dari 1-3 saja!";}
                else { 
                    int hasilIndex = -1;
                    if (respon == 1) {hasilIndex = nonSentinelSearch(d, banyakData, cari);}
                    else if (respon == 2) {hasilIndex = sentinelSearch(d, banyakData, cari);}
                    else if (respon == 3) {sortNamaUjian(d, banyakData); hasilIndex = binarySearch(d, banyakData, cari);}
                    
                    if (hasilIndex != -1) {
                        cout << "\nData ditemukan pada indeks ke-" << hasilIndex << "!\n";
                        cout << "Nama Ujian : " << d[hasilIndex].nama_ujian << endl;
                        cout << "Nilai      : " << d[hasilIndex].nilai << endl;
                    } else {
                        cout << "\nData tidak ditemukan.\n";
                    }
                }
            }
            cout << "\nPress any key to continue . . .\n";
            cin.ignore();
            cin.get();
            break;
        } case 6: {
            cout << "\n==================\n";
            cout << "    Sort Ujian\n";
            cout << "==================\n";

            if (banyakData == 0) {
                cout << "Data masih kosong!\n";
            } else {
                cout << " [1] Bubble sort\n"; 
                cout << " [2] Selection sort\n";
                cout << " [3] Insertion sort\n";
                cout << " [4] Shell sort\n";
                cout << " [5] Quick sort\n";
                cout << "Pilih: "; cin >> respon;

                if (respon == 1) {bubbleSort(d, banyakData);}
                else if (respon == 2) {selectionSort(d, banyakData);}
                else if (respon == 3) {insertionSort(d, banyakData);}
                else if (respon == 4) {shellSort(d, banyakData);}
                else if (respon == 5) {quickSortMenu(d, banyakData);}
                else {cout << "Mohon input nomor dari 1-5 saja!";}
            }
            
            cout << "\nPress any key to continue . . .\n";
            cin.ignore();
            cin.get();
            break;
        } case 7: {
            cout << "==================\n";
            cout << "   Operasi File\n";
            cout << "==================\n";

            if (banyakData == 0) {
                cout << "Data masih kosong!\n";
            } else {
                cout << "1. Export Data\n";
                cout << "2. Import Data\n";
                cout << "Pilih: "; cin >> respon;
                if (respon == 1) {exportData(d, banyakData);}
                else if (respon == 2) {importData();}
                else {cout << "Mohon input nomor dari 1 dan 2 saja!";}
            }
            
            cout << "\nPress any key to continue . . .\n";
            cin.ignore();
            cin.get();
            break;
        } case 0: {
            cout << "Program berakhir.\n\n";
            cout << "====================\n";
            cout << "Press any key to continue . . .\n";
            cin.ignore();
            cin.get();
            return 0;
        } default: {
            cout << "Mohon pilih menu dari 0-7 saja!\n";

            cout << "\nPress any key to continue . . .\n";
            cin.ignore();
            cin.get();
            break;
        }
    }
    } while (choice > 0);
    return 0;
}