#include <iostream>
#include <string.h>
#include "PGM.h"
using namespace std;
#include "ImageProcessing.h"

int main(){
    string filename, answer, newname;
    int x;
    cin >> filename;

    cout << "Select Operation:";
    cout << "       (0) Copy Image";
    cout << "       (1) Flip Vertical";
    cout << "       (2) Flip Horizontal";
    cout << "       (3) Median Filter";
    cout << "Enter Selection:  ";
    cin >> x;
    if (x == 0){
        cout << "Enter Save File Name: ";
        cin >> newname;
        copyImage(filename, newname);

    }

    else if (x == 1){
        cout << "Enter Save File Name: ";
        cin >> newname;

    }

    else if (x == 2){
        cout << "Enter Save File Name: ";
        cin >> newname;

    }

    else if (x == 3){
        cout << "Enter Save File Name: ";
        cin >> newname;

    }

    else{


    }

    cout << "Perform another operation [y/n]?";
    cin >> answer;

    if (answer.compare("y") == 0){
        main();
    }

    else return 0;

    return 1;
}