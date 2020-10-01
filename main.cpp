#include <iostream>
#include "ImageProcessing.h"
#include "PGM.h"
using namespace std;

int main(){
    string filename;

    cin >> filename;
    copyImage(filename);

    return 0;

}