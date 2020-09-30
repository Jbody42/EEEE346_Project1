#include <iostream>
#include <vector>
#include "PGM.h"
#include "ImageProcessing.h"

using namespace std;

void medianFilter() {

    if (openPGM(fileName) ){

    
        int width = getPGMWidth();
	    int height = getPGMHeight();
	
	    //Declare and allocate memory for data int**original;
    	
        int** original;

        original = new int*[height];
	    original = new int*[width];

        for(int i = 0; i<height; i++){
            original[i] new int [width];
        }

	    getPGMData(original);

    }    

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
                        original.at(imRow)(imCol) = average;
                    }

                }

            }

         }

    }

}
