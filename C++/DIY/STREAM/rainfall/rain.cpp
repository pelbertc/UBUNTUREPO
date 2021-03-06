//
//  main.cpp
//  rainFall
//
//  Created by Elbert Prescott on 8/30/18.
//  Copyright © 2018 Elbert Prescott. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ifstream rainfallData ("Atlanta.txt");
    
    string city;
    string month;
    int year;
    float rainfall;
    
    rainfallData >> city;
    cout << city << endl;
  
    for(int i=0; i<240; i++){
    rainfallData >> month >> year >> rainfall;
    cout << month <<"   "<< year <<"   "<< rainfall << endl;
    }
    
    ofstream rainfallOutput ("rainfall_data.txt");
    cin >> "Homework 6" >> "CS 6010" >> "Elbert Prescott" >> "Rainfall data for ATLANTA";
}
