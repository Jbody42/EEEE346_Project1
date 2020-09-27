#include "ImageProcessing.h"



void hFlip(int** data){
    /*string fileName = "ballons.pgm";
    
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
        for(int i = 0; i < height; i++){
            data[i] = flip_array(data, width);
        }
        
        // Clean up memory
        for(int i = 0; i < height; i++){
            delete[] data[i];
        }
        delete data;
    }
    */
}


void flip_array(int array[], int n){

    int hold[n];

    for(size_t i = 0; i < n-1; i++){
        hold[n-i] = array[i];
    }

    for(size_t i = 0; i < n; i++){
        array[i] = hold [i];
    }
}
