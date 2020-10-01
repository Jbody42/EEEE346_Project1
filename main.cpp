#include <iostream>
#include <stdio.h>
#include <string.h>
#include "ImageProcessing.h"
#include "PGM.h"
using namespace std;

int main(){
    string filename;

    filename = "noisy.pgm";
    //copyImage(filename);
    //hFlip(filename);
    //vFlip(filename);
    medianFilter(filename);

    return 0;

}