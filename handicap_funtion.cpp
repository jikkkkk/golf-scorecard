#include <iostream>
#include<cstdlib>
#include<unistd.h>
#include <algorithm>
#include "Accounts.h"
#include "Scorecard.h"
Accounts Account;
using namespace std;

// Functions
    void ScoreDiffential_cal(float gross[]);
        float Handicap(float a);
            void C_handicap(float a);
                void Smallest_sDiff(float mindiff[]);
                    void Threescrds(float threecards[]);
                        //   void FiveCards(float fvecards[]);

// Arrays
        float gross_Score[20] = { };
        //{80,82,92,92,76,83,100,75,78,100,120,113,87,78,98,84,87,94,71,88};
            float a_score_diff[20];
                float scorediff_three[3];

// Reagular Variables
    float CourseRating = 72.4 , PCC = 0;
        float slopeRating = 135 ; /* ( This is an interchangeable Value from 55 - 155 ) */
            int arr_size = 0; // This will have to refernce the scorecard values Aleks will sort this out.

int handicap_function(float net_array[], int size)
{
   // int a_size = sizeof(gross_Score)/sizeof(gross_Score[0]); // Test
    //cout << " Going to reference Scorecards Net scores " << endl;
    //cout << " Gonna use the pointers for this shizz  \n";
    //sleep(2);


/*
        TWO STATEMENTS !!!

    One for 3 scorecards = Provisional Handicap need to reference array of
                           handicaps using pointers.

    One for 20 scorecards = Full handicap.

*/

/* less than 3 Scorecards */
cout << "I work" << endl;

for (int i = 0; i < 20; i++){
    if (net_array[i] != 0){
    arr_size++;
    }
    else {
        break;
    }
}

float* net_arr = new float [arr_size];

for (int i = 0; i < arr_size; i++){
    net_arr[i] = net_array[i];
    cout << net_arr[i] << " ";
}

if (arr_size < 3)
{
    int handicapindex;
    handicapindex = 0;
    Account.Sethandicap(handicapindex);
}


/* 3 scorecards */
 else if (arr_size == 3)
 {
     for(int i = 0 ; i < 4; i++)
     {

         gross_Score[i]; // need to change to the net score class
     }
     // Runs value to function 2 for provisional handicap
     Threescrds(gross_Score);
 }


 /* 20 Scorecards */
else if (arr_size = 20){

    /*for(int i = 0; i<=19; i++)
    {
       cout << " Net Score  "<< i + 1  << " : ";
       cin >> gross_Score[i]; // asking for input of score differentials
    }*/

    // Running the values to the funtion
    //ScoreDiffential_cal(net_arr, arr_size);

                }

 // Score Differential Calculations

// Need to use pointers
    float scorediff[20]; //Applying the value to a different array
    for(int i = 1; i<=20; i++)
    {
     //   scorediff[i] = ((113/slopeRating)*(gross_f[i] - CourseRating - PCC));
        a_score_diff[i] = scorediff[i] ;// Changing the name off the variable
    }
    // Printing out the values of the score diff
        for(int i = 1; i<=20; i++)
        {
            cout <<" [ " << a_score_diff[i]<< " ]";
            cout << endl;
        }

    // Running it to the smallest values function
    Smallest_sDiff(a_score_diff); // Takes a_score_diff to the function

}
void Smallest_sDiff(float mindiff[]) // renames to mindiff
{
    /*
    provisional Handicap
    */
    if (arr_size = 3)
    {
        float sum;
        for(int i = 0;i<4;i++)
        {
            sum = mindiff[i] + sum;
        }

        Handicap(sum);
    }

    /*
        20 Scorecards
    */
    if(arr_size = 20)
{
            float minmum = mindiff[20],sum;
            for(int i=0; i<=8; i++)
            {
                if (minmum>mindiff[i])
            {
                sum = sum + mindiff[i];
               // cout<< mindiff[i] <<endl;
            }
        }
        cout << " The sum of the 8 lowest score differentials is : "<< sum << endl;
        // Running it to the handicap function to calculate
       Handicap(sum);
}
}



// Calculates the handicap of the use
float Handicap(float sum)
{

    float handicapindex;

    if(arr_size = 3)
    {
        handicapindex = sum/8;
    }
    // Calculations
    if (arr_size = 8)
    {
        handicapindex = sum/8;
    }

    cout << " \n  CALCULATING YOUR HANDICAP INDEX ...... \n "<< endl; sleep(2);
    cout << " Your Handicap is : "<< handicapindex << endl;
    C_handicap(handicapindex);
    return handicapindex;
}

// Calculates the course handicap of the user
void C_handicap(float handicapindex)
{
    float CourseH ;
    // Calculations
    CourseH = handicapindex*(slopeRating/113);
    cout << " \n CALCULATING YOUR COURSE HANDICAP ...... \n "<<  endl; sleep(2);
    cout << " Your course handicap is : " << CourseH << endl;
}




void Threescrds(float threecards[]) // If theres only 3 cards input
{
    float _arr_scorediff[3] ;
    // Need to read in the values
    for(int i = 0; i<4; i++)
    {
      scorediff_three[i] = ((113/slopeRating)*(threecards[i]-CourseRating-PCC) + 2);
      scorediff_three[i] = _arr_scorediff[i]; // changing the name
    }
     Smallest_sDiff(_arr_scorediff); // Running to the new function

}
