#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include "PGM.h"
#include "ImageProcessing.h"
using namespace std;


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


void hFlip(string filename){
    
    //filename = "";
    //Open File set information
    if( openPGM(filename) )
    {
        
        int width = getPGMWidth();
        int height = getPGMHeight();
       
        int** original;
        original = new int*[height];

        for(int i = 0; i < height; i++){
            original[i] = new int[width];
        }

        getPGMData(original);
        
        // Horizontally-flips an image
        int hold;
        for(size_t i = 0; i < height; i++){
           for(size_t j = 0; j < width/2; j++){
                hold = original[i][j]; 
                original[i][j] = original[i][width-1-j];
                original[i][width-1-j] = hold;   
            } 
        }
        
        string newFilename;
        cin >> newFilename;
       
        writePGM(newFilename, original);
        
        for(int i = 0; i < height; i++){
            delete[] original[i];
        }
        delete original;
        
    }
}

void vFlip(string filename){
    
    //filename = "";
    //Open File set information
    if( openPGM(filename) )
    {
        
        int width = getPGMWidth();
        int height = getPGMHeight();
       
        int** original;
        original = new int*[height];

        for(int i = 0; i < height; i++){
            original[i] = new int[width];
        }

        getPGMData(original);
        
        // Horizontally-flips an image
        int hold;
        for(size_t j = 0; j < width; j++){
           for(size_t i = 0; i < height/2; i++){
                hold = original[i][j]; 
                original[i][j] = original[height-1-i][j];
                original[height-1-i][j] = hold;   
            } 
        }
        
        string newFilename;
        cin >> newFilename;
       
        writePGM(newFilename, original);
        
        for(int i = 0; i < height; i++){
            delete[] original[i];
        }
        delete original;
        
    }
}

void medianFilter(string fileName) {

    if (openPGM(fileName) ){

    
        int width = getPGMWidth();
	    int height = getPGMHeight();
	
	    //Declare and allocate memory for data int**original;
    	
        int** original;

        original = new int*[height];
	    original = new int*[width];

        for(int i = 0; i<height; i++){
            original[i] = new int [width];
        }

	    getPGMData(original);

        

	    int imCol; //is image collumn counter
	    int imRow; //is image row counter
        int rowMod; //is row modulator for populating window
        int colMod; //is collum modulator for populating window
        int wRPop; //is counter for window row population
        int wCPop; //is counter for window col population
        int window [81] = {0}; //CA window 1x81
        int windex; //index for the window.... GET IT!?
        int sum;
        int average;

        for(imRow = 4; imRow <= height-4; imRow++){
            for(imCol = 4; imCol <= width-4; imCol++){
                                                            // This nested for-loop structure is used
                rowMod = -4;                                // to move the window over the image by it's center. 
                windex = 0;                                 // This is to ensure that the edges aren't processes 
                sum = 0;                                    // hence starting at element 4 and not going past N-4 
                average = 0;                                // for both dimensions

                for(wRPop = imRow + rowMod; wRPop <= imRow + 4; rowMod++){

                    colMod = -4;

                    for(wCPop = imCol + colMod; wCPop <= imCol + 4; colMod++){

                        window[windex] = original[wRPop][wCPop];
                        sum += window[windex];

                        if(windex == 80){
                            average = sum/81;
                            original[imRow][imCol] = average;
                        }

                    }

                }

            }

        }

        string newFilename;
        cin >> newFilename;
       
        writePGM(newFilename, original);
        
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