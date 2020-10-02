/**
 *	FileName:	ImageProcessing.cpp
 *	Author:		Jayson Body, Will Wright, Peter Cardona
 *	Date:		9/20/2020
 *	Revised:	10/2/2020
 *
 *	Description:	functions to flip, copy and fliter pgm files.
 */


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

