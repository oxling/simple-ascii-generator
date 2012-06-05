//
//  letter.c
//  AsciiGenerator
//
//  Created by Amy Dyer on 6/4/12.
//  Copyright (c) 2012 Amy Dyer. Do whatever you like with this.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#import "letter.h"

static char * characterAtNode(node_t * node)
{
    return node->letter->character;
}

static node_t * findNode(node_t * root, float darkness)
{
    
    if (!root) {
        return NULL;
    }
    
    float nodeDarkness = root->letter->darkness;
        
    if (nodeDarkness == darkness) {
        return root;
    }
    
    if (darkness < nodeDarkness) {
        node_t * found = findNode(root->left, darkness);
        return found ? found : root;
    } else {
        node_t * found = findNode(root->right, darkness);
        return found ? found : root;
    }
}

node_t * newNode(char * character, float darkness)
{
    node_t * newNode = malloc(sizeof(node_t));
    letter_t * newLetter = malloc(sizeof(letter_t));
    
    
    
    newLetter->character = malloc(sizeof(character));
    strcpy(newLetter->character, character);
    newLetter->darkness = darkness;
    
    newNode->letter = newLetter;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

char * findLetter(node_t * root, float darkness)
{
    node_t * node = findNode(root, darkness);
    return node->letter->character;
}

void insertLetter(node_t * root, char * character, float darkness)
{
    float rootDarkness = root->letter->darkness;
    
    if (root->letter->character == character) {
        return;
    }
    
    if (darkness < rootDarkness) {
        if (root->left == NULL) {
            node_t * n = newNode(character, darkness);
            root->left = n;
        } else {
            insertLetter(root->left, character, darkness);
        }
    } else {
        if (root->right == NULL) {
            node_t * n = newNode(character, darkness);
            root->right = n;
        } else {
            insertLetter(root->right, character, darkness);
        }
    }
    
}

void deleteLetter(letter_t letter)
{
    
}

static void destroyNode(node_t * node)
{
    free(node->letter->character);
    free(node->letter);
    free(node);
}

void destroyTree(node_t * root)
{
    if (root->left) {
        destroyTree(root->left);
        root->left = NULL;
    } else if (root->right) {
        destroyTree(root->right);
        root->right = NULL;
    } else {
        destroyNode(root);
    }
}


