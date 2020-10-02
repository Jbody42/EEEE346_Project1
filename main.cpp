/**
 *	FileName:	ImageProcessing.cpp
 *	Author:		Jayson Body, Will Wright, Peter Cardona
 *	Date:		9/20/2020
 *	Revised:	10/2/2020
 *
 *	Description:	Main fucntion that utilizes the Imageprocessing functions with user inputs and ouputs the files.
 */


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
    while(1){

        if(answer.compare("y") == 0){
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
            
            }

            else if (x == 1){
                cout << "Enter Save File Name: ";
                cin >> newname;
                vFlip(file, newname);
                cout << "Perform another operation [y/n]? ";
               
            }

            else if (x == 2){
                cout << "Enter Save File Name: ";
                cin >> newname;
                hFlip(file, newname);
                cout << "Perform another operation [y/n]? ";
                
            }

            else if (x == 3){
                cout << "Enter Save File Name: ";
                cin >> newname;
                medianFilter(file, newname);
                cout << "Perform another operation [y/n]? ";
                

            }

            else{
                cout << "Please enter a valid number next time" << endl;
                cout << "Perform another operation [y/n]? ";

            }
        }

        else if (answer.compare("n") == 0){
            break;
        }

        else{
            cout << "Please use y or n in order to perform another operation: ";
        }
        cin >> answer;
    }
    return 1;
}