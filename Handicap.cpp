#include "main.h"

float p_handicap;
float slopeRating = 135;
float CourseRating = 72.4, PCC = 0;
float scorediff_three[3];

int Handicap::handicap_func(string ID, int net_strokes[], int size)
{
float sum;

if(net_strokes[0] == 0 || net_strokes[1] == 0 || net_strokes[2] == 0 )
{
    cout << "You currently dont have enough score cards to acquire a handicap."<< endl;
    p_handicap = 0;
    cout<< ""<< endl;
    goto finale;
}
else
{
    goto calculation;
}
    calculation:
    // Score Differential Claculation
    for(int i = 0 ; i<3 ; i++)
    {
        scorediff_three[i] = ((113.0/slopeRating)*(net_strokes[i]-CourseRating-PCC));
        //cout <<"["<< scorediff_three[i]<<"]"<< endl;
    }

    float sum1;
    for(int i =0 ; i < 3; i++)
    {
    sum1 = sum1 + scorediff_three[i];
    cout << sum1 << endl;
    }

    //Then divided by for average.
    p_handicap = sum1/3;
    cout << "Your provisional handicap is : " << p_handicap <<endl;

    finale:
    ofstream accounts_file;
    accounts_file.open("accounts/" + ID + ".txt", ios::app);
    if (!accounts_file){
        cout << "Unable to open file!" << endl;
        exit(1);
    }
    accounts_file << "Provisional handicap: " << p_handicap << endl;
    accounts_file.close();
    return 0;
}
