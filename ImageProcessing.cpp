#include <iostream>
#include "PGM.h"
#include <stdio.h>
#include <string.h>
#include "ImageProcessing.h"
using namespace std;


void hFlip(string filename){
    
    //filename = "";
    //Open File set information
    if( openPGM(filename) )
    {
        
        int width = getPGMWidth();
        int height = getPGMHeight();
       
        int** data;
        data = new int*[height];

        for(int i = 0; i < height; i++){
            data[i] = new int[width];
        }

        getPGMData(data);
        
        // Horizontally-flips an image
        int hold;
        for(size_t i = 0; i < height; i++){
           for(size_t j = 0; j < width/2; j++){
                hold = data[i][j]; 
                data[i][j] = data[i][width-1-j];
                data[i][width-1-j] = hold;   
            } 
        }
        string newFilename;
         cin >> newFilename;
        writePGM(newFilename, data);
        
        for(int i = 0; i < height; i++){
            delete[] data[i];
        }
        delete data;
        
    }
}

void copyImage(string filename){
    

    if (openPGM(filename)){
        int width = getPGMWidth();
        int height = getPGMHeight();

        int** original;
        original = new int*[height];
        
        for (int i = 0; i < height; i++){
            original[i] = new int [width];
        }

        getPGMData(original);
        
        writePGM("copy.pgm", original);

        for(int i = 0; i < height; i++){
            delete[] original[i];
        }
        delete original;
    }
}

/*
int flip_array(int array[], int n){

    int hold[n];

    for(size_t i = 0; i < n-1; i++){
        hold[n-i] = array[i];
    }

    for(size_t i = 0; i < n; i++){
        array[i] = hold [i];
    }
}

*/