#ifndef ImageProcessing_H__
#define ImageProcessing_H__

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
void copyImage(string filename, string copyname);

/*
* Function to horizontally flip an image
* and output the image file
*/
void hFlip(string filename, string hFlip);

/*
* Function to vertically flip an image
* and output the image file
*/
void vFlip(string filename, string vFlip);

/*
* Function that filters an image
* and outputs the image file
*/
void medianFilter(string fileName, string medianFilter);


#endif

