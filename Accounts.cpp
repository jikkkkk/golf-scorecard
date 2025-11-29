#include "main.h"

Accounts::Accounts()
{
    // initialise data members
    name = "Name";
    surname = "Surname";
    gender = "Gender";
    date_of_birth = "01.01.1970";
    fees = 0;
    member_ID = "A0000";
}
Accounts::Accounts(string name_new, string surname_new){
 // Create a new account constructor
    int ans, randomNumber;
    char m;
    name = name_new;
    surname = surname_new;
    member_ID = "A0000";
    // creating the account
    cout << "\nPlease enter date of birth: ";
    cin >> date_of_birth;
    cout << "\nPlease specify gender: ";
    cin >> gender;
    cout << "\nEnter fees paid: ";
    cin >> fees;
    cout << endl;
    handicap = 0;
    srand((unsigned) time(0));
    for (int i = 1; i < 4; i ++){
       randomNumber = (rand() % 9) + 1;
       m = '0' + randomNumber;
       member_ID[i] = m;
    }
    // create new file for this account
    save_account(name, surname, gender, member_ID, date_of_birth, handicap, fees);
    cout << "Thank you for creating a new account! Your member ID is: " << member_ID << ". You need to use it to log in." << endl;
    }

void Accounts::existing_account(string ID, string club){
    int ans;
    open:
    ifstream accounts_file;
    accounts_file.open("accounts/" + ID + ".txt", ios::in);
    if (!accounts_file){
        cout << "Unable to find your account! Please try entering your membership ID again!" << endl;
        cin >> ID;
        goto open;
    }
    accounts_file.close();

    login_account:
    cout << "What would you like to do?"
    << "\n1. Check fees"
    << "\n2. Add new scorecard"
    << "\n3. Check last 3 net scores" << endl;
    cin >> ans;

    switch (ans){
    case 1:{
        find_fees_info(ID);
        cout << "You have paid: " << fees << " euro." << endl;
        break;}
    case 2:{
        find_handicap_info(ID);
        find_name_info(ID);
        find_net_info(ID);
        Scorecard newScorecard(handicap, club);
        newScorecard.Score();
        newScorecard.Scorecard_display(name, ID, handicap);
        new_handicap(ID);
        break;
        }
    case 3:{
        find_net_info(ID);
        for (int i = 0; i < 3; i++){
            cout << net_arr3[i] << " ";
        }
        cout << endl;
        break;
    }
    default:
        cout << "You've entered an invalid input. Try again!" << endl;
        break;
    }
    goto login_account;
}

void Accounts::display(string ID){

    cout << "Your account information, " << name << " " << surname << ":\n"
    << "Member ID: " << member_ID << endl
    << "Gender: " << gender << endl
    << "Date of birth: " << date_of_birth << endl
    << "Handicap: " << handicap << endl;
}

void Accounts::save_account(string name_n, string surname_n, string gender_n, string member_ID_n, string dob_n, int handicap_n, float fees_n){
    ofstream accounts_file;
    string club = "clubtest";
    accounts_file.open("accounts/" + member_ID_n + ".txt", ios::app);
    if (!accounts_file){
        cout << "Unable to open file!" << endl;
        exit(1);
    }
    accounts_file << "Account " << member_ID_n <<"\n";
    accounts_file << "Name: " << name_n << " " << surname_n << "\n";
    accounts_file << "Date of Birth: " << dob_n << "\n";
    accounts_file << "Gender: " << gender_n << "\n";
    accounts_file << "Provisional handicap: " << handicap_n << "\n";
    accounts_file << "Fees paid: " << fees_n << "\n";
    accounts_file << endl << endl;
    accounts_file.close();
}

void Accounts::admin(){
    int ans, status;
    string name_new, surname_new;
    char file_name[21];
    cout << "1. Add account"
    << "\n2. Remove account"
    << "\n3. Close program" << endl;
    cin >> ans;

    switch (ans){
    case 1:{
        cout << "\nPlease enter first name: ";
        cin >> name_new;
        cout << "\nPlease enter last name: ";
        cin >> surname_new;
        Accounts Account(name_new, surname_new);
        break;
    }
    case 2:{
        delete_f:
        cout << "Enter full name of the file: ";
        cin >> file_name;
        if(remove(file_name)==0)
            cout<<"\nAccount deleted successfully!" << endl;
        else
            cout<<"\nError occurred!" << endl;
            goto delete_f;
            break;
    }
    case 3:
        cout << "Thank you for using our program!" << endl;
        exit (0);
    }
}

float Accounts::find_fees_info(string ID){
    string temp = " ";
    float fees_s = 1.1;
    string search_fees = "Fees";
    bool isFound = 0;

    ifstream accounts_file;
    accounts_file.open("accounts/" + ID + ".txt", ios::in);
    if (!accounts_file){
        cout << "Unable to open file!" << endl;
        exit (1);
    }

    while (!accounts_file.eof()){
        getline(accounts_file,temp);
        for (int i = 0; i < search_fees.size(); i++){
            if (temp[i]==search_fees[i]){
                isFound = 1;
            }
            else{
                isFound = 0;
                break;
            }
        }
        if (isFound){
        temp.erase(0,11);
        stringstream geek(temp);
        geek >> fees_s;
        temp = " ";
        }
    }
    accounts_file.close();
    fees = fees_s;
    return fees;
}

string Accounts::find_name_info(string ID){
    string name_s = " ", temp = " ";
    string search_name = "Name";
    bool isFound = 0;

    ifstream accounts_file;
    accounts_file.open("accounts/" + ID + ".txt", ios::in);
    if (!accounts_file){
        cout << "Unable to open file!" << endl;
        exit (1);
    }
    while (!accounts_file.eof()){
        getline(accounts_file,temp);
        for (int i = 0; i < search_name.size(); i++){
            if (temp[i]==search_name[i]){
                isFound = 1;
            }
            else{
                isFound = 0;
                break;
            }
        }
        if (isFound){
        temp.erase(0,6);
        name = temp;
        }
    }
    accounts_file.close();
    return name;
}

float Accounts::find_handicap_info(string ID){
    string temp = " ";
    float handicap_s = 0;
    string search_h = "Provisional";
    bool isFound = 0;

    ifstream accounts_file;
    accounts_file.open("accounts/" + ID + ".txt", ios::in);
    if (!accounts_file){
        cout << "Unable to open file!" << endl;
        exit(1);
    }
    while (!accounts_file.eof()){
        getline(accounts_file,temp);
        for (int i = 0; i < search_h.size(); i++){
            if (temp[i]==search_h[i]){
                isFound = 1;
            }
            else{
                isFound = 0;
                break;
            }
        }
        if (isFound){
        temp.erase(0,22);
        stringstream geek(temp);
        geek >> handicap_s;
        temp = " ";
        }
    }
    handicap = handicap_s;
    accounts_file.close();
    return handicap;
}

float Accounts::find_net_info(string ID){
    string temp = " ";
    float net;
    int x = 100;
    float * net_array;
    net_array = new float [x];
    string search_net = "NET:    ";
    bool isFound = 0;
    int cnt = -1;

    ifstream accounts_file;
    accounts_file.open("accounts/" + ID + ".txt", ios::in);
    if (!accounts_file){
        cout << "Unable to open file!" << endl;
        exit(1);
    }
    while (!accounts_file.eof()){
        getline(accounts_file,temp);
        for (int i = 0; i < search_net.size(); i++){
            if (temp[i]==search_net[i] && temp[i+1] == search_net[i+1] && temp[i+2] == search_net[i+2]){
                temp.erase(0,5);
                stringstream geek(temp);
                geek >> net;
                cnt++;
                net_array[cnt] = net;
                temp = " ";
                net_arr3[cnt] = net_array[cnt];
            }
            else{
                net_array[cnt] = 0;
                break;
            }
        }
    }
    accounts_file.close();
    delete net_array;
    return * net_arr3;
}

void Accounts::new_handicap(string ID){
    Handicap myHandicap;
    myHandicap.handicap_func(ID, net_arr3, 3);
}

ostream& operator<< (ostream& ostr, const Accounts & d){
    ostr << "Your account information, " << d.name << " " << d.surname << ":\n"
    << "Gender: " << d.gender << endl
    << "Date of Birth: " << d.date_of_birth << endl
    << "Handicap: " << d.handicap << endl
    << "Member ID: " << d.member_ID << endl;
    return ostr;
}

Accounts::~Accounts()
{
    //cout << "\n" << name << " destroyed" << endl;
}
