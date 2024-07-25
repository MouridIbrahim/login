#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void login();
void Register();
void Forgot();

int main (){
    int choice;
    cout << "****************************Welcome to login page****************************\n";
    cout << "Choose one of this options \n";
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "3. Forgot\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    system("cls");

    switch(choice){
        case 1:
            login();
            break;
        case 2:
            Register();
            break;
        case 3:
            Forgot();
            break;
        
        case 4:
            cout << "Thanks for visiting\n";
            break;
        default:
            cout << "Invalid Choice";    
        
}
}

void login(){
    int count;
    std ::string user,password,u,p;
    cout << "Enter your username\n " ;
    cin >> user;
    cout << "Enter your password\n ";
    cin >> password;
    
    ifstream input("database.txt");
    while(input >>u>>p){
        if(u==user && p==password){
            count =1;
            system("cls");
        }
        input.close();
        if(count==1){
            cout << "Hello "<< user <<" Login sucess\n";
            cout << "Thanks for login ";
            cin.get();
            cin.get();
            }
        else {
            cout << "Error Login ";
        }    
        
    }

};

void Register(){
    std :: string getuser,getpassword;
    cout << "Enter your Username \n";
    cin >> getuser;
    cout << "Enter your password";
    cin >> getpassword;
    ofstream get("database.txt",ios::app);
    get<<getuser<< ' ' <<getpassword<<'\n';
    system("cls");
    cout << "Thnaks for Register";

}

void Forgot() {
    int choice1;
    cout << "We are here to help you \n";
    cout << "Choose one of these options \n";
    cout << "1. Search your ID by username \n";
    cout << "2. Search your ID by password\n";
    cout << "3. Exit\n";
    cin >> choice1;

    switch (choice1) {
        case 1: {
            string searchuser, us, pass;
            int count = 0;
            ifstream searchid("database.txt");
            cout << "Enter your remembered username: ";
            cin >> searchuser;
            while (searchid >> us >> pass) {
                if (searchuser == us) {
                    count = 1;
                    break;
                }
            }
            searchid.close();
            if (count == 1) {
                cout << "Your password is " << pass << '\n';
            } else {
                cout << "Username not found\n";
            }
            cin.get(); // Wait for user input
            cin.get();
            system("cls");
            break;
        }
        case 2: {
            string searchpass, us, pass;
            int count = 0;
            ifstream searchid("database.txt");
            cout << "Enter your remembered password: ";
            cin >> searchpass;
            while (searchid >> us >> pass) {
                if (searchpass == pass) {
                    count = 1;
                    break;
                }
            }
            searchid.close();
            if (count == 1) {
                cout << "Your username is " << us << '\n';
            } else {
                cout << "Password not found\n";
            }
            cin.get(); // Wait for user input
            cin.get();
            system("cls");
            break;
        }
        case 3:
            system("cls");
            main();
            break;
        default:
            cout << "Invalid choice\n";
            Forgot();
            break;
    }
}