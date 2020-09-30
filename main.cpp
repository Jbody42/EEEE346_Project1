#include <iostream>
#include "ImageProcessing.h"
#include "PGM.h"
using namespace std;

int main(){
    string filename, nFilename;

    cin >> filename;
    cin >> nFilename;
    hFlip(filename, nFilename);

    return 0;

}