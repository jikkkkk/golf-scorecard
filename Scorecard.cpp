#include "main.h"


Scorecard::Scorecard()
{
    course_name = "no name";
    date = "no date";
}

Scorecard::Scorecard(int handicap_ss, string club){

    int r, s;
    find_bluedist(club);
    find_greydist(club);
    find_greendist(club);

    find_index(club);
    find_par(club);

  cout << "Enter the date: ";
  cin >> date; cout << "\n";

  if(handicap_ss <= 18){
      cout << "You have " << handicap_ss << " extra strokes\n";
      for( int n = 0; n <= 17; n++ ){
         if( index[n] <= handicap_ss ){
         cout << "You have one extra stroke on hole " << hole[n] << endl;
         cout << "Your shots for this hole is " << par[n] + 1 << endl;
         }
      }
  }

  else if(handicap_ss < 36){
      cout << "You have " << handicap_ss << " extra strokes\n";
      r = handicap_ss - 18;
      for(int n = 0; n <= 17; n++ ){
         if(index[n] <= r){
         cout << "You have two free strokes on hole " << hole[n] << "\n";
         }
      }
      cout << "You have one extra stroke on every other hole\n";
  }
  else if(handicap_ss == 36){
      cout << "You have two extra strokes on every hole" << endl;
  }
  else if(handicap_ss < 54){
       cout << "You have " << handicap_ss << " extra strokes overall\n";
       s = handicap_ss - 36;
       for( int n = 0; n <= 17; n++ ){
         if( index[n] <= s){
         cout << "You have three extra strokes on hole " << hole[n] << "\n";
         }
       }
      cout << "You have two extra strokes on every other hole" << endl;
  }
  else if(handicap_ss == 54){
       cout << "You have three extra strokes on every hole\n";
  }
  else{
       cout << "Sorry, your handicap must be 54 or lower" << endl;
  }
}

void Scorecard::Display_Info(){

    cout << "\nYour Scorecard has been created!\n\n";
    cout << "Your member ID is " << member_ID << "\n\n";
//    cout << "You will be playing " << course_size << " holes at " << course_name << " golf club\n\n";
    cout << "Good Luck!\n" << endl;

}

void Scorecard::Score(){

    int hole = 1, n = 0,s = 0, x = 0, sum = 0;

for( int r = 1; r <= 18; r++){

    while(n <= 17){
    cout << "Please enter the amount of shots for hole number "<< hole << ": ";
    cin >> shots[n]; // changed variable name.
    cout << "\n";
    hole++;
    n++;
    }
}

    cout << "Your shots for each hole is: \n\n";

while(s <= 17){

    cout << shots[s] << "  "; // Changed variable name
    s++;

}

while(x <= 17){
    sum = sum + shots[x]; // changed variable name
    x++;
}

cout << "\n\nYou took " << sum << " shots to complete this course. Congratulations!\n\n"<< endl;
     if(sum > 72){
     sum = sum - 72;
     cout << "You are now " << sum << " over";
     }
     else if(sum < 72){
     sum = 72 - sum;
     cout << "You are now " << sum << " under";
     }
     else{
     cout << "You took 72 shots to complete course and are now even" << endl;
     }
     // Sending all values to points function
    stableford(shots);
}

void Scorecard::Scorecard_display(string name_s,string member_ID_s, int handicap_s){
    ofstream sc_file;
    sc_file.open("accounts/" + member_ID_s + ".txt", ios::app);
    if (!sc_file){
        cout << "Unable to open file!" << endl;
        exit(1);
   }

    int sum = 0, sum1 = 0, n, h;

       sc_file << "\n";
       sc_file << setw(71) << setfill(' ') << " " << "*** GOLF SCORECARD ***" << endl;
       sc_file << setw(164) << setfill('_') << "_" << endl;
       sc_file << setw(164) << setfill('*') << "*" << endl;


    sc_file << "BLUE           ";
    for(int f = 0; f <=17; f++){
            if(f == 8)
                {
                sc_file << blue[f]
                << "    |    |    ";
                }
            else{

                sc_file << blue[f] << "    ";
            }
    }sc_file << "   |    |\n";

    sc_file << "DARK GREEN     ";
    for(int g = 0; g <=17; g++){
            if(g == 8){
                sc_file << green[g] << "    |    |    ";
            }
            else{
                sc_file << green[g] << "    ";
            }
    }sc_file << "   |    |\n";

    sc_file << "GREY           ";
    for(int h = 0; h <=17; h++){
            if(h == 8){
                sc_file << grey[h] << "    |    |    ";
            }
            else{
                sc_file << grey[h] << "    ";
            }
    }sc_file << "   |    |\n";


    sc_file << "HOLES            ";
    for(int m = 0; m < 8; m++){
    sc_file << hole[m];
    if(m < 8){
    sc_file << "      ";
    }
    else{
    sc_file << "     ";
    }
    }
    for(int m = 8; m <= 17; m++){
            if(hole[m] == 9 ){
                sc_file << hole[m] << "    |    |     ";
            }
            else{
                sc_file << hole[m] << "     ";
            }
    }  sc_file << "  |    |";


    sc_file << "\nINDEX           ";
    for(int q = 0; q <= 17; q++){
    sc_file << index[q];
    if(q == 8){
    sc_file << "    |    |     ";
    }
    else{
    sc_file << "      ";
    }
    }sc_file << "  |    |";


    sc_file << "\nPAR              ";
    for(int d = 0; d <= 17; d++){
            if(d == 8){
            sc_file << par[d] << "    | 36 |      ";
            }
            else{
            sc_file << par[d] << "      ";
            }
        } sc_file << " | 72 |";


    sc_file << "\nSHOTS            ";
    for(int s = 0; s <= 17; s++){
            if(s == 8){
            sc_file << shots[8];
            for( int x = 0; x <= 8; x++){
            sum = sum + shots[x];
            }
            sc_file << "    | " << sum << " |      ";
            }
            else{
            sc_file << shots[s] << "      ";
            }
    }
    for( int x = 9; x <= 17; x++){
            sum1 = sum1 + shots[x];
    }
    sc_file << " | " << sum+sum1 << " |";
    sc_file << "\nHANDICAP: " << handicap_s << endl;
    sc_file << "NET: " << sum+sum1 << endl;
    sc_file << "NAME: " << name_s << endl;
    sc_file << "DATE: " << date << endl;
    sc_file << "POINTS: " << points << endl;
    sc_file << setw(164) << setfill('_') << "_" << endl;
    sc_file << setw(164) << setfill('*') << "*" << endl;
    sc_file.close();

}

void Scorecard::stableford(int Shotsin[18])
{
    // Copy and paste'd variable, calling values didnt work
    int S_par[18],n = 0,sum2 = 0,points;

    while (n<=17)
    {
       S_par[n] = Shotsin[n] - par[n];
       sum2 = sum2+S_par[n];
       n++;
    }
    // Need to assign points
    n = 0;
    while(n<=17)
    {
        if(S_par[n]== 0)
        {
            points = points + 2;
            n++;
            cout << " points :" << points << endl;
        }
        else if(S_par[n] == -1)
        {
            points =  points + 3;
            n++;
            cout << " points :" << points << endl;
        }
        else if(S_par[n] == -2)
        {
            points = points + 4;
            n++;
            cout << " points :" << points << endl;
        }
        else if(S_par[n] == -3)
        {
            points = points + 5;
            n++;
            cout << " points :" << points << endl;
        }
        else if(S_par[n] == 1)
        {
            points = points + 1;
            n++;
            cout << " points :" << points << endl;
        }
        else
        {
            points = points + 0;
            n++;
            cout << " points :" << points << endl;
        }

    }
    //cout << " You Have finsihed with "<< sum2 << "!" <<endl;
    cout << "\nYou have : "<< points << endl; // add to end of scorecard
}

void Scorecard::find_bluedist(string club){
    string temp = " ";
    int b;
    string search_blue = "BLUE: ";
    bool isFound = 0;
    int cnt = -1;

    ifstream clubs_file;
    clubs_file.open("clubs/" + club + ".txt", ios::in);
    if (!clubs_file){
        cout << "Unable to open file!" << endl;
        exit(1);
    }
    while (!clubs_file.eof()){
        getline(clubs_file,temp);
        for (int i = 0; i < search_blue.size(); i++){
            if (temp[i]==search_blue[i]){
                isFound = 1;
                temp.erase(0,15);
                stringstream geek(temp);
                geek >> b;
                cnt++;
                blue[cnt] = b;
                for (int i = 0; i < 17; i++){
                    temp.erase(0, 7);
                    stringstream geek(temp);
                    geek >> b;
                    cnt++;
                    blue[cnt] = b;
            }}
            else{
                isFound = 0;
                break;
            }
        }
    }
    clubs_file.close();
}

void Scorecard::find_greydist(string club){
    string temp = " ";
    int d;
    string search_dist = "GREY: ";
    bool isFound = 0;
    int cnt = -1;

    ifstream clubs_file;
    clubs_file.open("clubs/" + club + ".txt", ios::in);
    if (!clubs_file){
        cout << "Unable to open file!" << endl;
        exit(1);
    }
    while (!clubs_file.eof()){
        getline(clubs_file,temp);
        for (int i = 0; i < search_dist.size(); i++){
            if (temp[i]==search_dist[i]){
                isFound = 1;
                temp.erase(0,15);
                stringstream geek(temp);
                geek >> d;
                cnt++;
                grey[cnt] = d;
                for (int i = 0; i < 17; i++){
                    temp.erase(0, 7);
                    stringstream geek(temp);
                    geek >> d;
                    cnt++;
                    grey[cnt] = d;
            }}
            else{
                isFound = 0;
                break;
            }
        }
    }
    clubs_file.close();
}

void Scorecard::find_greendist(string club){
    string temp = " ";
    int d;
    string search_dist = "DARK GREEN: ";
    bool isFound = 0;
    int cnt = -1;

    ifstream clubs_file;
    clubs_file.open("clubs/" + club + ".txt", ios::in);
    if (!clubs_file){
        cout << "Unable to open file!" << endl;
        exit(1);
    }
    while (!clubs_file.eof()){
        getline(clubs_file,temp);
        for (int i = 0; i < search_dist.size(); i++){
            if (temp[i]==search_dist[i]){
                isFound = 1;
                temp.erase(0,15);
                stringstream geek(temp);
                geek >> d;
                cnt++;
                green[cnt] = d;
                for (int i = 0; i < 17; i++){
                    temp.erase(0, 7);
                    stringstream geek(temp);
                    geek >> d;
                    cnt++;
                    green[cnt] = d;
            }}
            else{
                isFound = 0;
                break;
            }
        }
    }
    clubs_file.close();
}

void Scorecard::find_index(string club){
    string temp = " ";
    int d;
    string search_index = "INDEX";
    bool isFound = 0;
    int cnt = -1;

    ifstream clubs_file;
    clubs_file.open("clubs/" + club + ".txt", ios::in);
    if (!clubs_file){
        cout << "Unable to open file!" << endl;
        exit(1);
    }
    while (!clubs_file.eof()){
        getline(clubs_file,temp);
        for (int i = 0; i < search_index.size(); i++){
            if (temp[i]==search_index[i]){
                isFound = 1;
                temp.erase(0,17);
                stringstream geek(temp);
                geek >> d;
                cnt++;
                index[cnt] = d;
                for (int i = 0; i < 17; i++){
                    temp.erase(0, 7);
                    stringstream geek(temp);
                    geek >> d;
                    cnt++;
                    index[cnt] = d;
            }}
            else{
                isFound = 0;
                break;
            }
        }
    }
    clubs_file.close();
}

void Scorecard::find_par(string club){
    string temp = " ";
    int d;
    string search_par = "PAR";
    bool isFound = 0;
    int cnt = -1;

    ifstream clubs_file;
    clubs_file.open("clubs/" + club + ".txt", ios::in);
    if (!clubs_file){
        cout << "Unable to open file!" << endl;
        exit(1);
    }
    while (!clubs_file.eof()){
        getline(clubs_file,temp);
        for (int i = 0; i < search_par.size(); i++){
            if (temp[i]==search_par[i] && temp[i+1] == search_par[i+1]){
                isFound = 1;
                temp.erase(0,17);
                stringstream geek(temp);
                geek >> d;
                cnt++;
                par[cnt] = d;
                for (int i = 0; i < 17; i++){
                    temp.erase(0, 7);
                    stringstream geek(temp);
                    geek >> d;
                    cnt++;
                    par[cnt] = d;
            }}
            else{
                isFound = 0;
                break;
            }
        }
    }
    clubs_file.close();
}

Scorecard::~Scorecard()
{
    //cout << "\n\nYour Golf Scorecard has been destroyed" << endl;
    //dtor
}
