//
//  main.c
//  AsciiGenerator
//
//  Created by Amy Dyer on 6/4/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#import "letter.h"
#import "bitmap.h"

static void calculateGrid(unsigned char * bmpData, int width, int height, node_t * root)
{
    int rowSize = (BITS_PER_PIXEL * width)/32 * 4;
        
    for (int row=0; row<abs(height); row++) {
        for (int col=0; col<width; col++) {
            float val = darkness(locatePixel(bmpData, rowSize, row, col));
            char letter = findLetter(root, val);
            printf("%c", letter);
        }
        printf("\n");
    }
    
    destroyTree(root);

}

static char * readFileData(const char * definitionsFilePath, size_t * length)
{
    size_t fileSize = 1024;
    size_t buffSize = 256;
    
    FILE * file = fopen(definitionsFilePath, "r");
    
    if (file == NULL) {
        printf("Definitions file could not be opened.\n");
        exit(EXIT_FAILURE);
    }
    
    char * fileData = malloc(sizeof(char) * fileSize);
    char * buff = malloc(sizeof(char) * buffSize);
    
    size_t len = 0;
    size_t bytesRead = 0;
    
    while ((len = fread(buff, sizeof(char), buffSize, file))) {
        size_t newSize = bytesRead+len;
       
        if (newSize > fileSize) {
            fileSize = newSize;
            fileData = realloc(fileData, newSize);
        }
        
        memcpy(fileData+bytesRead, buff, len);
        bytesRead=newSize;
    }
    
    free(buff);
    
    *length = bytesRead;
    return fileData;
}

static node_t * createTreeFromFile(const char * definitionsFilePath)
{
    size_t length = 0;
    char * data = readFileData(definitionsFilePath, &length);
    char * buff = malloc(sizeof(char) * 32);
    
    int bytesRead = 0;
    
    float darkness = 0;
    char letter = 0;
    node_t * root = NULL;
    
    for (int i=0; i<length; i++) {
        char c = data[i];
        
        if (bytesRead > 32) {
            printf("Definitions file contains value that is longer than 32 bytes");
            exit(EXIT_FAILURE);
        }
        
        memcpy(buff+bytesRead, &c, 1);
        
        bytesRead++;
        
        
        if (c == ' ' || c == '\n' || c == ';') {
            
            char * str = malloc(bytesRead * sizeof(char));
            memset(str, 0, bytesRead);
            memcpy(str, buff, bytesRead-1);
            
            bytesRead = 0;
            
            if (c == ' ') {
                //First section - a letter
                letter = str[0];
            } else {
                //Second section - a float
                darkness = atof(str);
                
                if (root == NULL) {
                    root = newNode(letter, darkness);
                } else {
                    insertLetter(root, letter, darkness);
                }
            }
            
            free(str);
        }
    }
    
    free(buff);
    free(data);
    
    return root;
}

int main (int argc, const char * argv[])
{
    const char * filepath = 0;
    
    if (argc > 1) {
        filepath = argv[1];
    } else {
        printf("Need a filepath argument");
        exit(EXIT_FAILURE);
    }
    
    node_t * root = createTreeFromFile("/Users/amy/Desktop/test.txt");
   
    int width = 0;
    int height = 0;
    int rowSize = 0;
     
    unsigned char * bmpData = createBitmapData(filepath, &width, &height, &rowSize);
   
    calculateGrid(bmpData, width, height, root);
    printf("Overall darkness: %.3f\n", overallDarkness(bmpData, width, height));
    
    free(bmpData);
    destroyTree(root);
    
    return 0;
}
