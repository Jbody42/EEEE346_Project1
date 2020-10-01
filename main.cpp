#include <iostream>
#include "ImageProcessing.h"
#include "PGM.h"
using namespace std;

int main(){
    string filename;

    filename = "lena.pgm";
    copyImage(filename);

    return 0;

}