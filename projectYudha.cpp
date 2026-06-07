#include <iostream>
#include <string>

using namespace std;

struct Player {
    string name;
    int health;
};

int roleUser;
void mainUser() {
    cout << "[ CHOOSE USER YOU ARE ]\n";
    cout << "[1] Player or [2] Admin\n";
    cout << "Respond: "; cin >> roleUser;
}

void loginAdmin() {
    int attName = 0;
    int attPw = 0;

    string userAdmin;
    int userPassword, a = 0, temp = 0;
    string usernameAdmin[3] = {"Yudha", "Dhayu", "Yud"};
    int passwordAdmin[3] = {123, 321, 231};
    
    do {
        system("cls");
        if (a > 0) {cout << "[-" << a << "]\n";} 
        cout << "Hello, there!\n";
        cout << "Enter your username as admin: "; cin >> userAdmin;
        
        bool is_true = false; 
        
        for (int i = 0; i < 3; i++) {
            if (userAdmin == usernameAdmin[i]) {
                temp = i;
                is_true = true;
                break;
            }
        }

        if (is_true) {
            cout << "[PDA]: Username accepted! Welcome, " << usernameAdmin[temp] << ".\n";
            break;
        }
        
        a++;
        cout << "\n[PDA]: Unknown admin. Try again!\n";
        attName++;
        
        if (attName == 3) {
            cout << "[PDA]: Your attempt has been limited. Program immediately exits.\n"; 
            return;
        }
        
    } while (attName < 3);
    
    // do {
    //     system("cls");
    //     cout << "Enter your password as admin: "; cin >> userPassword;
    //     for (int i = 0; i < 3; i++) {
    //         for (int j = 0; j < 3; j++) {
    //             if (passwordAdmin[j] == userPassword && i == j) {
    //                 cout << "You're the one of admin, " << usernameAdmin << ". Welcome to the program!\n";
    //                 break;
    //             }
    //         }
    //     }
    //     attPw++;
    // } while (attPw < 3); 
    // if (attName == 3) {cout << "\n[PDA]: Your attempt has been limited. Program immediately exits."; return;}

}

void loginPlayer() {
    string UserName;
    cout << "Hi, there!\n"; 
    cout << "Your name: "; getline(cin >> ws, UserName);
    cout << "Welcome Back, " << UserName << "!\n"; 
}

int main () {
    Player p[10];
    mainUser();
    if (roleUser == 1) {loginPlayer();}
    else {loginAdmin();}
}