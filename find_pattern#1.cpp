//DIAMOND PATTERN
#include <iostream>

using namespace std;

void cetakDiamond (int inputUser) {
    for(int a = 0; a < inputUser; a++) {
        cout << endl;
        for (int b = 0; b < inputUser - a; b++) {
            cout << " ";
        }
        for (int c = 0; c < 2*a - inputUser; c++) {
            cout << "*"; 
        }
    }
    for (int i = 0; i < inputUser; i++) {
        cout << endl;
        for (int k = 0; k < i; k++) {
            cout << " ";
        }
        for (int j = 0; j < inputUser - 2*i; j++) {
            cout << "*"; 
        }
    }
}

int main() {
    int angkaUser;
    do {
    cout << "Input angka Anda di sini (harus ganjil): ";
    cin >> angkaUser;
    } while (angkaUser % 2 == 0); //user input must be an odd number, not even
    
    cetakDiamond(angkaUser);
    
}