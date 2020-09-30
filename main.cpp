#include <iostream>
#include "ImageProcessing.h"
#include "PGM.h"
using namespace std;

int main(){
    string filename;

    cin >> filename;
    hFlip(filename);

    return 0;

}