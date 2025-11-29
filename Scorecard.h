#ifndef SCORECARD_H
#define SCORECARD_H
#include <string>
#include <iostream>
#include <array>
#include <fstream>
#include <iomanip>
#include "main.h"

using namespace std;

class Scorecard
{
    public:
        Scorecard();
        Scorecard(int, string);
        virtual ~Scorecard();

        string Getcourse_name() { return course_name; }
        void Setcourse_name(string val) { course_name = val; }
        string Getmember_ID() { return member_ID; }
        void Setmember_ID(string val) { member_ID = val; }

        void Display_Info();
        void Score(); // added overload values to use variables
        void Scorecard_display(string, string, int);
        void stableford(int[]); // Added new function for points
        friend ostream& operator << (ostream&, const Scorecard &);
        void find_bluedist(string);
        void find_greydist(string);
        void find_greendist(string);
        void find_index(string);
        void find_par(string);


    protected:

    private:
        string course_name;
        string member_ID;
        string date;
        int shots[18];
        int points;
        int blue[18];
        int grey[18];
        int green[18];
        int index[18];
        int par[18];
        int hole[18] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};


};

#endif // SCORECARD_H
