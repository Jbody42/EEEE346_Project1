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
        std::cin >> newFilename;
       
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
        std::cin >> newFilename;
       
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

        for(int i = 0; i<height; i++){
            original[i] = new int[width];
        }

	    getPGMData(original);

        

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
                            
                            //for(windex = 0; windex <= 80; windex++){
                                for(int i=0; i<79; i++){
                                    for(int j=(i+1); j<80; j++){
                                        if(window[i]>window[j]){
                                            int hold = 0;

                                            hold = window[i];
                                            window[i]=window[j];
                                            window[j]=hold;
                                        }
                                    }
                                }
                                
                                



                                /*if((window[windex] > window[windex+1]) && windex != 80){  //IF we finished populating the window, then we begin sorting the array.
                                    bucket = window[windex];                            //If the first element is larger than the segwaying element, we swap em.
                                    window[windex] = window[windex+1];                   //Then we reset the counter to see if a new greater thand condition has...
                                    window[windex+1] = bucket;                          //...been met. We do this only until the last index is met, which can only...
                                    windex = 0;                                         //...happen if the elements are in order, therefore the median is in 40.
                                }*/

                                //else if(windex == 80){                                  //Have we reached the last element? Then swap original...
                                original[imRow][imCol] = window[40];   
                                windex = 0;             //...pixel we're currently centered on with the window median
                                //}

                            //} 

                        }

                        windex++;                                                       //This is to line up populating the next element in window Array.

                    }

                }

            }

        }

        string newFilename;
        std::cin >> newFilename;
       
        writePGM(newFilename, original);
        
        for(int i = 0; i < height; i++){
            delete[] original[i];
        }
        delete original;

    }

}



