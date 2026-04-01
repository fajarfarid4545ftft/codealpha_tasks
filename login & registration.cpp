#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void registerUser();
bool loginUser();
bool userExists(string username);

int main() {
    int choice;
    
    
    while (true) {
        cout << "\n--- Welcome to the System ---" << endl;
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                
                if (loginUser()) {
                    cout << "\n[SUCCESS] Login successful! Welcome back." << endl;
                } 
                else {
                    cout << "\n[ERROR] Invalid username or password." << endl;
                }
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;  
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    
    return 0;  
}

bool userExists(string username) {
    ifstream file("database.txt");
    string u, p;
    
 
    while (file >> u >> p) {
        if (u == username) {
            file.close(); 
            return true;
        }
    }
    
    file.close();
    return false;
}


void registerUser() {
    string user, pass;
    
    cout << "\n--- Registration ---" << endl;
    cout << "Enter username: ";
    cin >> user;

  
    if (userExists(user)) {
        cout << "[ERROR] Username already exists! Try a different one." << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> pass;

 
    ofstream file("database.txt", ios::app);
    
    if (file.is_open()) {
        file << user << " " << pass << endl;
        file.close();
        cout << "[SUCCESS] Registration complete!" << endl;
    } 
    else {
        cout << "[ERROR] Could not open database file." << endl;
    }
}

bool loginUser() {
    string user, pass;
    string u, p; 
    
    cout << "\n--- Login ---" << endl;
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    ifstream file("database.txt");
    
    
    while (file >> u >> p) {
        if (u == user && p == pass) {
            file.close();
            return true;  
        }
    }
    
    file.close();
    return false;  
}
