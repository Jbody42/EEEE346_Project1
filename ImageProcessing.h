#include <iostream>
#include "PGM.h"
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

/*
* Function to copy an image
* and output the image file
*/
void copyImage(string filename);

/*
* Function to horizontally flip an image
* and output the image file
*/
void hFlip(string filename);

/*
* Function to vertically flip an image
* and output the image file
*/
void vFlip(string filename);

/*
* Function that filters an image
* and outputs the image file
*/
void medianFilter(string fileName);


/*
* Function to flip an array
*/
//int flip_array(int array[], int n);