#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#define DATA_SIZE 1000
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <array>
#include <fstream>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <ctime>

using namespace std;

class Accounts
{
    public:
        Accounts();
        Accounts(string, string);
        virtual ~Accounts();

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Getsurname() { return surname; }
        void Setsurname(string val) { surname = val; }
        string Getgender() { return gender; }
        void Setgender(string val) { gender = val; }
        string Getmember_ID() { return member_ID; }
        void Setmember_ID(string val) { member_ID = val; }
        string Getdate_of_birth() { return date_of_birth; }
        void Setdate_of_birth(string val) { date_of_birth = val; }
        float Gethandicap() { return handicap; }
        void Sethandicap(float val) { handicap = val; }
        float Getfees() { return fees; }
        void Setfees(float val) { fees = val; }

        friend ostream& operator<< (ostream&, const Accounts &);
        void existing_account(string, string);
        void display(string);
        void save_account(string, string, string, string, string, int, float);
        void admin();
        float find_fees_info(string);
        float find_handicap_info(string);
        string find_name_info(string);
        float find_net_info(string);
        void new_handicap(string);

    private:
        string name;
        string surname;
        string gender;
        string member_ID;
        string date_of_birth;
        int net_arr3[3] = {0, 0, 0};
        float handicap;
        float fees;
};

#endif // ACCOUNTS_H
