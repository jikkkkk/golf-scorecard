#ifndef CLUB_H
#define CLUB_H
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Club
{
    public:
        Club();
        Club(string);
        virtual ~Club();

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Getlocation() { return location; }
        void Setlocation(string val) { location = val; }
        int Getcapacity() { return capacity; }
        void Setcapacity(int val) { capacity = val; }
        int Getcourse_rating() { return course_rating; }
        void Setcourse_rating(int val) { course_rating = val; }
        int Getpcc() { return pcc; }
        void Setpcc(int val) { pcc = val; }
        int Getslope_rating() { return slope_rating; }
        void Setslope_rating(int val) { slope_rating = val; }

        void display_info();
        void par_and_index_input();
        void distances_input();
        void display_values();

        //Club *ptr = new Club();

    protected:

    private:
        string name;
        string location;
        int course_rating; // average par;
        int pcc; // from -1 to 3
        int slope_rating; // from 55 to 160. average of 130
        int capacity;
        int par[18] = { };
        int index[18] = { };
        int blue[18] = { };
        int dark_green[18] = { };
        int grey[18] = { };
        int hole[18] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
};

#endif // CLUB_H
