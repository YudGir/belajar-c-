#include <iostream>
#include <string>

using namespace std;

struct Player {
    string name;
    int health;
};

void login () {
    string UserName;
    cout << "Hi, there! \n"; 
    cout << "Your name: "; getline(cin >> ws, UserName);
    
    cout << "Welcome Back, " << UserName << "!\n"; 
}

Player p[10];

int main () {
    login();
}