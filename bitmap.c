//
//  bitmap.c
//  AsciiGenerator
//
//  Created by Amy Dyer on 6/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#import "bitmap.h"

typedef struct BMPHeader {
    unsigned char head[2];
    unsigned char size[4];
    unsigned char reserved[4];
    unsigned char dataAddress[4];
} BMPHeader_t;

typedef struct DIBHeader {
    signed int size;
    signed int pxWidth;
    signed int pxHeight;
    unsigned char colorPlanes[2];
    unsigned char bitsPerPx[2];
    unsigned char compressionType[4];
    unsigned char imageDataSize[4];
    signed int horizontalResolution;
    signed int verticalResolution;
    signed int colorPaletteCount;
    signed int importantColors;
} DIBHeader_t;

/* Returns 0 for a black pixel, 1 for white */
float darkness(pixel_t pixel)
{
    return ((float)pixel.red + (float)pixel.blue + (float)pixel.green)/3/255;
}

pixel_t * pixelAtRow(unsigned char * bmpData, int rowSize, int row)
{
    void * pixRow = bmpData + (rowSize * row);
    return (pixel_t *)pixRow;
}

pixel_t locatePixel(unsigned char * bmpData, int rowSize, int row, int column)
{
    pixel_t * rowPix = pixelAtRow(bmpData, rowSize, row);
    return rowPix[column];
}

float overallDarkness(unsigned char * bmpData, int width, int height) {
    float darknessSum = 0;
    int rowSize = ((width * BITS_PER_PIXEL)/32)*4;
    for (int row=0; row<height; row++)
    {
        for (int col=0; col<width; col++)
        {
            darknessSum += darkness(locatePixel(bmpData, rowSize, row, col));
        }
    }
    
    return darknessSum/(width * height);
}

static unsigned char * createBitmapFromData(pixel_t * pxArray, int numPixels, int width, int height)
{
    int rowSize = ((width * BITS_PER_PIXEL)/32)*4;
    
    BMPHeader_t header;
    header.head[0] = 'B';
    header.head[1] = 'M';

}

unsigned char * createBitmapData(const char * fileLocation, int * width, int * height, int * rowSize)
{
    FILE * file = fopen(fileLocation, "r");
    
    BMPHeader_t header;
    size_t len = fread(&header, sizeof(header), 1, file);
    
    if (len < 1) {
        printf("Header should be %lu bytes long; only read %lu bytes\n", sizeof(header), len);
        exit(EXIT_FAILURE);
    }
    
    int bmpLength = 0;
    for (int i=0; i<4; i++) {
        bmpLength += (header.size[i] << i*8);
    }
    
    printf("Bitmap is %i bytes long\n", bmpLength);
    
    unsigned char * data = malloc(sizeof(unsigned char) * bmpLength);
    fseek(file, 0, SEEK_SET);
    
    if (fread(data, bmpLength, 1, file) != 1) {
        printf("Failed to read bitmap data");
        exit(EXIT_FAILURE);
    }
    
    int bmpAddr = 0;
    for (int i=0; i<4; i++) {
        bmpAddr += (header.dataAddress[i] << i*8);
    }
    
    printf("Data starts at address 0x%02X\n", bmpAddr);
    
    DIBHeader_t dibHeader = *((DIBHeader_t *)(data+sizeof(header)));
    
    printf("Pixel width: %i\n", dibHeader.pxWidth);
    printf("Pixel height: %i\n", dibHeader.pxHeight);
    printf("Bits per pixel: %i\n", dibHeader.bitsPerPx[0]);
    
    if (dibHeader.bitsPerPx[0] != 32) {
        printf("This application currently only supports 32-bit bitmaps. Sorry!");
        exit(EXIT_FAILURE);
    }
    
    
    int bmpDataLen = bmpLength - bmpAddr;
    unsigned char * bmpData = malloc(sizeof(unsigned char) * bmpDataLen); 
    
    memcpy(bmpData, data+bmpAddr-1, bmpDataLen);
    
    free(data);
    
    *width = abs(dibHeader.pxWidth);
    *height = abs(dibHeader.pxHeight);
    *rowSize = ((dibHeader.pxWidth * BITS_PER_PIXEL)/32)*4;
    
    return bmpData;
}
