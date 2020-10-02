#include <iostream>
#include <stdio.h>
#include <string>
#include "PGM.h"
using namespace std;
#include "ImageProcessing.h"

int main(){
    string file, answer, newname;
    int x;
    answer = 'y';
    while(answer.compare("y") == 0){
        cout << "Enter Original File Name: ";
        cin >> file;
        cout << "Select Operation:" << endl;
        cout << "       (0) Copy Image" << endl;
        cout << "       (1) Flip Vertical" << endl;
        cout << "       (2) Flip Horizontal" << endl;
        cout << "       (3) Median Filter" << endl;
        cout << "Enter Selection: ";
        cin >> x;

   
        if (x == 0){
            cout << "Enter Save File Name: ";
            cin >> newname;
            copyImage(file, newname);
            cout << "Perform another operation [y/n]? ";
            cin >> answer;
        }

        else if (x == 1){
            cout << "Enter Save File Name:";
            cin >> newname;

            cout << "Perform another operation [y/n]?";
            cin >> answer;
        }

        else if (x == 2){
            cout << "Enter Save File Name:";
            cin >> newname;

            cout << "Perform another operation [y/n]?";
            cin >> answer;
        }

        else if (x == 3){
            cout << "Enter Save File Name:";
            cin >> newname;
                
            cout << "Perform another operation [y/n]?";
            cin >> answer;

        }

        else{
            cout << "Please enter a valid number";

        }


    }

    return 1;
}