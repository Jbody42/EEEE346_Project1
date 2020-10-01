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

       

	int imCol; //is image collumn counter
	int imRow; //is image row counter
    int rowMod; //is row modulator for populating window
    int colMod; //is collum modulator for populating window
    int wRPop; //is counter for window row population
    int wCPop; //is counter for window col population
    int window [81] = {0}; //CA window 1x81
    int windex; //index for the window.... GET IT!?
    int bucket;

    for(imRow = 4; imRow <= height -4; imRow++){
        for(imCol = 4; imCol <= width -4; imCol++){

                                // This nested for-loop structure is used
            rowMod = -4;        // to move the window over the image by it's center. 
            windex = 0;         // This is to ensure that the edges aren't processes 
                                // hence starting at element 4 and not going past N-4 
                                // for both dimensions

            for(wRPop = imRow + rowMod; wRPop <= imRow + 4; rowMod++){

                colMod = -4;                                                        //These nested for-loops populate the window elements...

                for(wCPop = imCol + colMod; wCPop <= imCol + 4; colMod++){          //...with those from the image according to a shifted index...

                    window[windex] = original[wRPop][wCPop];                        //...relative to the index of where the window is centered in the image

                    if(windex == 80){
                        
                        for(windex = 0; windex <= 80; windex++){
                            
                            if(window[windex] > window[windex+1] && windex != 80){  //IF we finished populating the window, then we begin sorting the array.
                                bucket = window[windex];                            //If the first element is larger than the segwaying element, we swap em.
                                window[windex] = winow[windex+1];                   //Then we reset the counter to see if a new greater thand condition has...
                                window[windex+1] = bucket;                          //...been met. We do this only until the last index is met, which can only...
                                windex = 0;                                         //...happen if the elements are in order, therefore the median is in 40.
                            }

                            else if(windex == 80){                                  //Have we reached the last element? Then swap original...
                                original[imRow][imCol] = window[40];                //...pixel we're currently centered on with the window median
                            }

                        }

                    }

                    windex++;                                                       //This is to line up populating the next element in window Array.

                }

            }

         }

    }

    }

}
