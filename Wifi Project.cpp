#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct User {
    string Name;
    string Address;
    string Password;
    string Confirm;
};

struct UserCredentials {
    string Name;
    string Password;
};

void Inicio(int& Opcion, int& Opcion2, User& UserSignUp, UserCredentials& UserLogin, bool& isRegistered);
void SignUp(User& UserSignUp, int& Opcion2, UserCredentials UserLogin, bool& isRegistered);
void Login(UserCredentials& UserLogin, User UserSignUp, bool isRegistered);

int main()
{
    int Opcion = 0, Opcion2 = 0;
    bool isRegistered = false;
    UserCredentials UserLogin;
    User UserSignUp;

    Inicio(Opcion, Opcion2, UserSignUp, UserLogin, isRegistered);

    return 0;
}

void Inicio(int& Opcion, int& Opcion2, User& UserSignUp, UserCredentials& UserLogin, bool& isRegistered) {
    cout << "\n\t\t==============================" << endl;
    cout << "\t\t|         WIFI NETWORK       |" << endl;
    cout << "\t\t==============================" << endl;
    cout << "\t\t|        1. Sign up          |" << endl;
    cout << "\t\t|        2. Login            |" << endl;
    cout << "\t\t|        3. Exit             |" << endl;
    cout << "\t\t==============================" << endl;
    cout << "\t\t Option: "; cin >> Opcion;
    cout << "\t\t==============================" << endl;

    switch (Opcion) {
    case 1:
        SignUp(UserSignUp, Opcion2, UserLogin, isRegistered);
        break;
    case 2:
        if (isRegistered) {
            Login(UserLogin, UserSignUp, isRegistered);
        }
        else {
            cout << "\n\t\tYou need to register first!" << endl;
            Inicio(Opcion, Opcion2, UserSignUp, UserLogin, isRegistered);  // Vuelve a mostrar el menú
        }
        break;
    case 3:
        cout << "\n\t\tUntil next time!" << endl;
        break;
    default:
        cout << "\n\t\tInvalid option. Please try again." << endl;
        Inicio(Opcion, Opcion2, UserSignUp, UserLogin, isRegistered);  // Vuelve a mostrar el menú
    }
}

void SignUp(User& UserSignUp, int& Opcion2, UserCredentials UserLogin, bool& isRegistered) {
    cout << "\n\t\tEnter your address : "; cin >> UserSignUp.Address;
    cout << "\t\tEnter new username : "; cin >> UserSignUp.Name;
    cout << "\t\tEnter new password : "; cin >> UserSignUp.Password;

    do {
        cout << "\t\tConfirm Password   : "; cin >> UserSignUp.Confirm;
        if (UserSignUp.Password != UserSignUp.Confirm) {
            cout << "\t\tPasswords do not match. Please try again." << endl;
            cout << "\n";
        }
    } while (UserSignUp.Password != UserSignUp.Confirm);

    isRegistered = true;

    cout << "\n\t\tRegistration completed! Now what?" << endl;
    cout << "\t\tLogin (1)    Exit (2)" << endl;
    cout << "\t\t: "; cin >> Opcion2;

    if (Opcion2 == 1) {
        Login(UserLogin, UserSignUp, isRegistered);
    }
    else {
        cout << "\n\t\tUntil next time!" << endl;
    }
}

void Login(UserCredentials& UserLogin, User UserSignUp, bool isRegistered) {
    if (!isRegistered) {
        cout << "\n\t\tYou need to register first!" << endl;
        return;
    }

    cout << "\n\t\t               LOGIN" << endl;
    cout << "\t\t==================================" << endl;

    cout << "\t\tEnter username: "; cin >> UserLogin.Name;
    while (UserSignUp.Name != UserLogin.Name) {
        cout << "\t\tUsers do not match. Please try again." << endl;
        cout << "\n\t\tEnter username: "; cin >> UserLogin.Name;
    }

    cout << "\t\tEnter password: "; cin >> UserLogin.Password;
    while (UserSignUp.Password != UserLogin.Password) {
        cout << "\t\tPasswords do not match. Please try again." << endl;
        cout << "\n\t\tEnter password: "; cin >> UserLogin.Password;
    }
    cout << "\t\t==================================" << endl;

    cout << "\n\t\tLogin successful!" << endl;
}