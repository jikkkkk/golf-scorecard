#include "main.h"

int main()
{
    string uname, password, club;
    int ans;
    Accounts Account;

    club_menu:
    cout << "Hello!" << endl << "What would you like to do?" << endl << endl;
    cout<<"        ============================"<< endl
    << "       | 1.  Create a new club" << endl
    << "       | 2.  Login into existing club" << endl;
    cout<<"        ============================"<< endl;
    cin >> ans;
    switch(ans){
    case 1:{
        cout << "Enter name of the club: ";
        cin >> club;
        Club newClub(club);
        newClub.par_and_index_input();
        newClub.distances_input();
        newClub.display_values();
        cout << "Thank you! Club " << club << " has been created!" << endl;
        goto club_menu;
    }
    case 2:{
        cout << "Please enter the name of the club: ";
        cin >> club;
        open:
        ifstream clubs_file;
        clubs_file.open("clubs/" + club + ".txt", ios::in);
        if (!clubs_file){
        cout << "Unable to find your club! Please try entering the name of the club again!" << endl;
        cin >> club;
        goto open;
        }
        clubs_file.close();
    }
    }

    cout << "   Welcome! Please choose an option: " << endl;
    menu:
    cout<<"        ============================"<<endl;
    cout << "       | 1.  Log in as Admin        |\n"
    << "       | 2.  Log into your account  |\n"
    << "       | 3.  Close the program      |\n"
    << "        ============================"<< endl;
    cin >> ans;

    switch(ans){
    case 1:{
        admin:
        cout << "Enter your username: " << endl;
        cin >> uname;
        cout << "Enter password: " << endl;
        cin >> password;
        if (uname == "admin" && password == "admin"){
            Account.admin();
            goto menu;
        }
        else{
            cout << "Username or password wrong. Please try again" << endl;
            goto admin;
        }
        break;
    }
    case 2: {
        login:
        cout << "Enter your member ID to log in: ";
        cin >> uname;
        Account.existing_account(uname, club);
        break;
    }
    case 3: {
        cout << "Thank you for using our program!" << endl;
        exit(0);
        break;
    }
    default:{
        cout << "You've entered an invalid input. Try again!" << endl;
        goto menu;
        break;
    }
    }
    return 0;
}
