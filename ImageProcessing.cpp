/**
 *	FileName:	ImageProcessing.cpp
 *	Author:		Jayson Body, Will Wright, Peter Cardona
 *	Date:		9/20/2020
 *	Revised:	10/2/2020
 *
 *	Description:	Source code for functions to flip, copy and fliter pgm files.
 */


#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include "PGM.h"
#include "ImageProcessing.h"
using namespace std;


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



void hFlip(string filename, string hFlip){
    
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
        
        writePGM(hFlip, original);
        
        for(int i = 0; i < height; i++){
            delete[] original[i];
        }
        delete original;
        
    }
}

void vFlip(string filename, string vFlip){
    
    
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
        
        // Horizontally-flips an image through array manipulation
        int hold;
        for(size_t j = 0; j < width; j++){
           for(size_t i = 0; i < height/2; i++){
                hold = original[i][j]; 
                original[i][j] = original[height-1-i][j];
                original[height-1-i][j] = hold;   
            } 
        }
        
       
        writePGM(vFlip, original);
        
        for(int i = 0; i < height; i++){
            delete[] original[i];
        }
        delete original;
        
    }
}

void medianFilter(string fileName, string medianFilter) {

    if (openPGM(fileName) ){

    
        int width = getPGMWidth();
	    int height = getPGMHeight();
	
	    //Declare and allocate memory for data int**original;
    	
        int** original;

        original = new int*[height];

        for(int i = 0; i<height; i++){
            original[i] = new int[width];
        }

        int** original1;

        original1 = new int*[height];

        for(int i = 0; i<height; i++){
            original1[i] = new int[width];
        }

	    getPGMData(original);

        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                    original1[i][j] = original[i][j]; 
            
            }
        }    



	        int imCol; //is image collumn counter
	        int imRow; //is image row counter
        int rowMod; //is row modulator for populating window
        int colMod; //is collum modulator for populating window
        int wRPop; //is counter for window row population
        int wCPop; //is counter for window col population
        int window[81]; //CA window 1x81
        int windex; //index for the window.... GET IT!?
        int bucket;

        for(imRow = 4; imRow < height -4; imRow++){
            for(imCol = 4; imCol < width -4; imCol++){

                                    // This nested for-loop structure is used
                rowMod = -4;        // to move the window over the image by it's center. 
                windex = 0;         // This is to ensure that the edges aren't processes 
                                    // hence starting at element 4 and not going past N-4 
                                    // for both dimensions

                for(wRPop = imRow -4; wRPop <= imRow + 4; wRPop++){

                    colMod = -4;                                                        //These nested for-loops populate the window elements...

                    for(wCPop = imCol -4; wCPop <= imCol + 4; wCPop++){          //...with those from the image according to a shifted index...

                        window[windex] = original[wRPop][wCPop];                        //...relative to the index of where the window is centered in the image

                        if(windex == 80){
                                for(int i=0; i<80; i++){
                                    for(int j=(i+1); j<81; j++){
                                        if(window[i]>window[j]){
                                            int hold = 0;

                                            hold = window[i];
                                            window[i]=window[j];
                                            window[j]=hold;
                                        }
                                    }
                                }
                               //Have we reached the last element? Then swap original...
                                original1[imRow][imCol] = window[40];   
                                windex = 0;             
                               

                           

                        }

                        windex++;      //This is to line up populating the next element in window Array.

                    }

                }

            }

        }

        
       
        writePGM(medianFilter, original1);
        
        for(int i = 0; i < height; i++){
            delete[] original[i];
        }
        delete original;

        for(int i = 0; i < height; i++){
            delete[] original1[i];
        }
        delete original1;

    }

}






