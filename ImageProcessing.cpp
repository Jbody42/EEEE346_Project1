#include <iostream>
using namespace std;
#include "PGM.h"
#include "ImageProcessing.h"


void copyImage(string filename, string copyname){
    

    if (openPGM(filename)){
        int width = getPGMWidth();
        int height = getPGMHeight();

        int** original;
        original = new int*[height];
        
        for (int i = 0; i < height; i++){
            original[i] = new int [width];
        }

        getPGMData(original);

        writePGM(copyname, original);

        for(int i = 0; i < height; i++){
            delete[] original[i];
        }
        delete original;
    }
}






