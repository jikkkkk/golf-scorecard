#include "main.h"

#include "Club.h"
#include <iomanip>
#include <fstream>

Club::Club()
{
        name = "No name";
        location = "Dublin";
        capacity = 0;
        cout << "Your club has been created!\n";
        //ctor
}

Club::Club(string name_m){
        name = name_m;
        int n = 0, s = 0, r = 0;
        int c_r, pcc1, s_r;
        cout << "Enter the location of your club: ";
        cin >> location; cout << "\n";
        cout << "Enter the club capacity: ";
        cin >> capacity; cout << "\n";
        while(n < 1){
        cout << "Enter the course rating for this club (average par): ";
        cin >> c_r; cout << "\n";
        if(c_r >= 68 && c_r <= 74){
        course_rating = c_r;
        n++;
        }
        else{
        cout << "You must enter a value from 68 to 74 for the course rating" << endl;
        }
        }
        while( s < 1){
        cout << "Enter the playing course conditions for today (between -1 and 3): ";
        cin >> pcc1; cout << "\n";
        if(pcc1 >= -1 && pcc1 <= 3){
        pcc = pcc1;
        s++;
        }
        else{
        cout << "You must enter a value from -1 to 3" << endl;
        }
        }
        while(r < 1){
        cout << "Enter the slope rating for this club (between 55 and 160): ";
        cin >> s_r; cout << "\n";
        if(s_r >= 55 && s_r <= 160){
        slope_rating = s_r;
        r++;
        }
        else{
        cout << "You must enter a value from 55 to 160" << endl;
        }
        }
}

void Club::display_info(){
    cout << "The name of your golf club is: " << name << " Golf Club" << endl;
    cout << "The location of your golf club is: " << location << endl;
    cout << "Your club has " << capacity <<  " members" << endl;
    cout << "The course rating for this club is " << course_rating << endl;
    cout << "The playing course conditions for today is: " << pcc << endl;
    cout << "The slope rating for this club is: " << slope_rating << "\n\n";
}

void Club::par_and_index_input(){
    int p, i, n = 0, r = 0;
    while(n < 18){
        cout << "Enter a par value for hole " << n+1 << " (must be a value from 3 to 5): ";
        cin >> p;
        if( p == 3 || p == 4 || p == 5 ){
        par[n] = p;
        n++;
        }
        else{
        cout << "Par value should be between 3 and 5" << endl;
        }
    }
    while(r < 18){
        cout << "Enter an index value for hole " << r+1 << " (must be a value from 1 to 18): ";
        cin >> i;
        if( i > 0 && i <= 18){
        index[r] = i;
        r++;
        }
        else{
        cout << "All index values must be from 1 to 18" << endl;
        }
    }
    cout << "\n";
}

void Club::distances_input(){
     int x = 0, y = 0, z = 0;
     int b,d,g;
     while(x < 18){
        cout << "Enter a blue distance value for hole " << x+1 << ": ";
        cin >> b;
        if(b >= 100 && b <= 1000){
        blue[x] = b;
        x++;
        }
        else{
        cout << "Please enter a value between 100 and 1000" << endl;
        }
     }
     while(y < 18){
        cout << "Enter a dark green distance value for hole " << y+1 << ": ";
        cin >> d;
        if(d >= 100 && d <= 1000){
        dark_green[y] = d;
        y++;
        }
        else{
        cout << "Please enter a value between 100 and 1000" << endl;
        }
     }
     while(z < 18){
        cout << "Enter a grey distance value for hole " << z+1 << ": ";
        cin >> g;
        if(g >= 100 && g <= 1000){
        grey[z] = g;
        z++;
        }
        else{
        cout << "Please enter a value between 100 and 1000" << endl;
        }
     }

}

void Club::display_values(){

    int num1 = 122, num2 = 128, num3 = 128;
    cout << setw(60) << setfill(' ') << " " << "*** CLUB INFORMATION ***" << endl;
    cout << setw(144) << setfill('_') << "_" << endl;
    cout << setw(144) << setfill('*') << "*" << endl;

    cout << "CLUB NAME: " << name << " golf club" << endl;
    cout << "CLUB LOCATION: " << location << endl;
    cout << "CLUB CAPACITY: " << capacity << endl;
    cout << "COURSE RATING: " << course_rating << "\n";
    cout << "PLAYING COURSE CONDITIONS: ";
    if( pcc < 0){
    cout << pcc << "  shots" << endl;
    }
    else if( pcc > 0){
    cout << " +" << pcc << " shots" << endl;
    }
    else{
    cout << "  " << pcc << " shots" << endl;
    }
    cout << "SLOPE RATING: " << slope_rating << endl;

    cout << "BLUE           ";
    for(int l = 0; l < 18; l++){
        cout << blue[l] << "    ";
    }
    cout << "  \n";

    cout << "DARK GREEN     ";
    for(int w = 0; w < 18; w++){
        cout << dark_green[w] << "    ";
    }
    cout << "  \n";

    cout << "GREY           ";
    for(int x = 0; x < 18; x++){
        cout << grey[x] << "    ";
    }
    cout << "  \n";

    cout << "HOLE             ";
    for(int m = 0; m < 18; m++){
    cout << hole[m];
    if(m < 8){
    cout << "      ";
    }
    else{
    cout << "     ";
    }
    }
    cout << " \n";

    cout << "INDEX           ";
    if(index[0] < 10 && index[1] > 9  ){
    cout << " " << index[0] << "     ";
    }
    else if(index[0] > 9 && index[1] > 9){
    cout << index[0] << "     ";
    }
    else if(index[0] > 9 && index[1] < 10){
    cout << index[0] << "      ";
    }
    else{
    cout << " " << index[0] << "      ";
    }
    for(int z = 1; z < 18; z++){
    cout << index[z];
    if( (index[z] < 10) && (index[z+1] > 9)  ){
    cout << "     ";
    }
    else if( (index[z] > 10) && (index[z+1] < 10)){
    cout << "      ";
    }
    else if( (index[z] > 9) && (index[z+1] > 9)  ){
    cout << "     ";
    }
    else{
    cout << "      ";
    }
    }
    cout << " \n";

    cout << "PAR              ";
    for(int y = 0; y < 18; y++){
        cout << par[y] << "      ";
    }
    cout << "\n";

    cout << setw(144) << setfill('_') << "_" << endl;
    cout << setw(144) << setfill('*') << "*" << endl;


    ofstream clubs_file;
    clubs_file.open("clubs/" + name + ".txt", ios::app);
    if (!clubs_file){
        cout << "Unable to open file!" << endl;
        exit(1);
    }

    clubs_file << setw(60) << setfill(' ') << " " << "*** CLUB INFORMATION ***" << endl;
    clubs_file << setw(144) << setfill('_') << "_" << endl;
    clubs_file << setw(144) << setfill('*') << "*" << endl;

    clubs_file << "CLUB NAME: " << name << " golf club";
    for(int num = 0; num < name.length(); num++){
    num1 = num1 - 1;
    }
    clubs_file << setw(num1) << setfill(' ') << " " << "\n";
    clubs_file << "CLUB LOCATION: " << location;
    for(int numm = 0; numm < location.length(); numm++){
    num2 = num2 - 1;
    }
    clubs_file << setw(num2) << setfill(' ') << " " << "\n";
    clubs_file << "CLUB CAPACITY: " << capacity;
    if(capacity < 100){
    clubs_file << " members" << setw(118) << setfill(' ') << " " << "\n";
    }
    else if(capacity < 1000){
    clubs_file << " members" << setw(117) << setfill(' ') << " " << "\n";
    }
    else{
    clubs_file << " members" << setw(116) << setfill(' ') << " " << "\n";
    }
    clubs_file << "COURSE RATING: " << course_rating << setw(126) << setfill(' ') << " " << "\n";
    clubs_file << "PLAYING COURSE CONDITIONS: ";
    if( pcc < 0){
    clubs_file << pcc << "  shots";
    }
    else if( pcc > 0){
    clubs_file << " +" << pcc << " shots";
    }
    else{
    clubs_file << "  " << pcc << " shots";
    }
    clubs_file << setw(107) << setfill(' ') << " " << "\n";

    clubs_file << "SLOPE RATING: " << slope_rating;
    if(slope_rating < 100){
    clubs_file << setw(127) << setfill(' ') << " " << "\n";
    }
    else{
    clubs_file << setw(126) << setfill(' ') << " " << "\n";
    }

    clubs_file << "BLUE           ";
    for(int l = 0; l < 18; l++){
        clubs_file << blue[l] << "    ";
    }
    clubs_file << "  \n";

    clubs_file << "DARK GREEN     ";
    for(int w = 0; w < 18; w++){
        clubs_file << dark_green[w] << "    ";
    }
    clubs_file << "  \n";

    clubs_file << "GREY           ";
    for(int x = 0; x < 18; x++){
        clubs_file << grey[x] << "    ";
    }
    clubs_file << "  \n";

    clubs_file << "HOLE             ";
    for(int m = 0; m < 18; m++){
    clubs_file << hole[m];
    if(m < 8){
    clubs_file << "      ";
    }
    else{
    clubs_file << "     ";
    }
    }
    clubs_file << " \n";

    clubs_file << "INDEX           ";
    if(index[0] < 10 && index[1] > 9  ){
    clubs_file << " " << index[0] << "     ";
    }
    else if(index[0] > 9 && index[1] > 9){
    clubs_file << index[0] << "     ";
    }
    else if(index[0] > 9 && index[1] < 10){
    clubs_file << index[0] << "      ";
    }
    else{
    clubs_file << " " << index[0] << "      ";
    }
    for(int z = 1; z < 18; z++){
    clubs_file << index[z];
    if( (index[z] < 10) && (index[z+1] > 9)  ){
    clubs_file << "     ";
    }
    else if( (index[z] > 10) && (index[z+1] < 10)){
    clubs_file << "      ";
    }
    else if( (index[z] > 9) && (index[z+1] > 9)  ){
    clubs_file << "     ";
    }
    else{
    clubs_file << "      ";
    }
    }
    clubs_file << " \n";

    clubs_file << "PAR              ";
    for(int y = 0; y < 18; y++){
        clubs_file << par[y] << "      ";
    }
    clubs_file << "\n";
    clubs_file << setw(144) << setfill('_') << "_" << endl;
    clubs_file << setw(144) << setfill('*') << "*" << endl;
    clubs_file.close();
}

Club::~Club()
{
    cout << "Your club has been destroyed!\n";
    //dtor
}
