#include <iostream>
#include <stdio.h>
#include <string.h>
#include "ImageProcessing.h"
#include "PGM.h"
using namespace std;

int main(){
    string filename;

    filename = "new.pgm";
    copyImage(filename);
    hFlip(filename);

    return 0;

}