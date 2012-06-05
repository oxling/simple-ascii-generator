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
    newNode->parent = NULL;
    
    return newNode;
}

char * findLetter(node_t * root, float darkness)
{
    node_t * node = findNode(root, darkness);
    return node->letter->character;
}

static node_t * rotateRight(node_t * root)
{
    
}

static node_t * balanceNode(node_t * node)
{
    if (node == NULL)
        return NULL;
    
    node_t * rootNode = node;
    
    int diff = balanceFactor(node);
    
    if (abs(balanceFactor(node)) > 1) {
        switch (diff) {
            case -2:;
                int rightBal = balanceFactor(node->right);
                if (rightBal == -1)
                    printf("right right case\n");
                else if (rightBal == 1)
                    printf("right left case\n");
                break;
            case 2:;
                int leftBal = balanceFactor(node->left);
                if (leftBal == 1)
                    printf("left left case\n");
                else if (leftBal == -1)
                    printf("left right case\n");
                break;
            default:
                printf("Unbalanced: %i\n", diff);
        }
    }

    return rootNode;
}

void insertLetter(node_t * root, char * character, float darkness)
{
    float rootDarkness = root->letter->darkness;
    
    if (strcmp(root->letter->character, character) == 0) {
        return;
    }
    
    if (darkness < rootDarkness) {
        if (root->left == NULL) {
            
            node_t * n = newNode(character, darkness);
            root->left = n;
            n->parent = root;
            
            balanceNode(root->parent);
            
        } else {
            insertLetter(root->left, character, darkness);
        }
    } else {
        if (root->right == NULL) {
            
            node_t * n = newNode(character, darkness);
            root->right = n;
            n->parent = root;
            
            balanceNode(root->parent);

        } else {
            insertLetter(root->right, character, darkness);
        }
    }
    
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

static int maxChildHeight(node_t * root)
{   
    if (root == NULL)
        return 0;
    
    int leftHeight = maxChildHeight(root->left);
    int rightheight = maxChildHeight(root->right);
    
    return (leftHeight > rightheight? leftHeight : rightheight) + 1;
}

int balanceFactor(node_t * root)
{
    if (root == NULL) {
        return 0;
    }
    
    int rightHeight = maxChildHeight(root->right);
    int leftHeight = maxChildHeight(root->left);

    return (leftHeight - rightHeight);
}


