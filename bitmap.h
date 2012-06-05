//
//  bitmap.h
//  AsciiGenerator
//
//  Created by Amy Dyer on 6/5/12.
//  Copyright (c) 2012 Amy Dyer. Do whatever you like with this.
//

#ifndef AsciiGenerator_bitmap_h
#define AsciiGenerator_bitmap_h
#endif

#define BITS_PER_PIXEL 32

typedef struct pixel {
    unsigned char        :3,
                    alpha:5;
    unsigned char   green;
    unsigned char   red;
    unsigned char   blue;
} pixel_t;

float darkness(pixel_t pixel);
float overallDarkness(unsigned char * bmpData, int width, int height);
pixel_t * pixelAtRow(unsigned char * bmpData, int rowSize, int row);
pixel_t locatePixel(unsigned char * bmpData, int rowSize, int row, int column);
unsigned char * createBitmapData(const char * fileLocation, int * width, int * height, int * rowSize);
