#include <iostream>

using namespace std;

void gandakanSkor(int *a) {
    *a *= 2;
}

int main() {
    int* skor = new int;
    cout << "Enter your score here: "; cin >> *skor;
    gandakanSkor(skor);

    cout << "Now, your doubled-score is: " << *skor << endl;
    delete skor;
    // int a = 10;
    // int b = 20;

    // int* ptrA = &a;
    // int* ptrB = &b;

    // swap(*ptrA, *ptrB); // this works for simpliest method to swap, ever!
    // int temp = *ptrA;
    // *ptrA = *ptrB;
    // *ptrB = temp; // this works as well, manually :)

    // cout << "value of a right now: " << a << endl;
    // cout << "value of b right now: " << b << endl;

    // int* nilaiUjian = new int[3];
    // cout << "enter the first grade here : "; cin >> nilaiUjian[0]; 
    // cout << "enter the second here      : "; cin >> nilaiUjian[1];
    // cout << "enter the third here       : "; cin >> nilaiUjian[2];

    // double expectation = (nilaiUjian[0] + nilaiUjian[1] + nilaiUjian[2]) / 3.0;
    // cout << "the expectation of three grades is " << expectation << endl;
    // delete[] nilaiUjian;
}