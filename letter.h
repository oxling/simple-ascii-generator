//
//  letter.h
//  AsciiGenerator
//
//  Created by Amy Dyer on 6/4/12.
//  Copyright (c) 2012 Amy Dyer. Do whatever you like with this.
//

#ifndef AsciiGenerator_letter_h
#define AsciiGenerator_letter_h

typedef struct letter {
    char * character;
    float darkness;
} letter_t;

typedef struct node {
    struct node * left;
    struct node * right;
    struct node * parent;
    struct letter * letter;
} node_t;

node_t * newNode(char * character, float darkness);

char * findLetter(node_t * root, float darkness);
int balanceFactor(node_t * root);
void insertLetter(node_t * root, char * character, float darkness);
void destroyTree(node_t * root);



#endif
