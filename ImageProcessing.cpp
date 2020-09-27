#include "ImageProcessing.h"



void hFlip(string filename){
    string fileName = "ballons.pgm";
    
    //Open File set information
    if( openPGM(fileName) )
    {
        // Get Image Size Information
        int width = getPGMWidth();
        int height = getPGMHeight();
        // Declare and allocate memory for data
        int** data;
        data = new int*[ height];

        for(int i = 0; i < height; i++){
            data[i] = new int[width];
        }

        // Get the data
        getPGMData(data);
        
        // Write back out a horizontally-flipped image
        int hold;
        for(size_t i = 0; i < height; i++){
           for(size_t j = 0; j < width/2; j++){
                hold = data[i][j]; 
                data[i][j] = data[i][width-1-j];
                data[i][width-1-j] = hold;   
            } 
        }
        
        // Clean up memory
        for(int i = 0; i < height; i++){
            delete[] data[i];
        }
        delete data;
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