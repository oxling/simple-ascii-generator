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
    if (node == NULL) return "";
    return node->letter->character;
}

static node_t * findNode(node_t * root, float darkness, float diff)
{
    
    if (!root) {
        return NULL;
    }
    
    float nodeDarkness = root->letter->darkness;
    float matchedDarkness = nodeDarkness > darkness ? nodeDarkness - darkness : darkness - nodeDarkness; //How close of a match it is

    if (diff < matchedDarkness) {
        //This node is actually less of a match than the previous node.
        return NULL;
    }
    
    if (darkness < nodeDarkness) {
        node_t * found = findNode(root->left, darkness, matchedDarkness);
        return found ? found : root;
    } else {
        node_t * found = findNode(root->right, darkness, matchedDarkness);
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
    node_t * node = findNode(root, darkness, 100000);
    return node->letter->character;
}

static void setLeftNode(node_t * parent, node_t * leaf)
{
    if (leaf != NULL) leaf->parent = parent;
    if (parent != NULL) parent->left = leaf;
}

static void setRightNode(node_t * parent, node_t * leaf)
{
    if (leaf != NULL) leaf->parent = parent;
    if (parent != NULL) parent->right = leaf;
}

void testNode(node_t * node)
{
    if (node == NULL) return;
    
    assert(node != node->parent);
    assert(node != node->left);
    assert(node != node->right);
    assert(node == treeRoot || 
           ((node->parent->left == node) || (node->parent->right == node)));
    assert(node->left != node->parent || (node->left == NULL && node->parent == NULL));
    assert(node->right != node->parent || (node->right == NULL && node->parent == NULL));
    assert((node->left != node->right) || (node->left == NULL && node->right == NULL));
}

static void printNode(node_t * node) {
    if (node == NULL) return;
    printNode(node->left);
    printNode(node->right);
    printf("<%s> parent: \"%s\" left: \"%s\" right: \"%s\"\n", characterAtNode(node), characterAtNode(node->parent), characterAtNode(node->left), characterAtNode(node->right));
}

void printTree()
{
    printf("\n");
    printNode(treeRoot);
    printf("\n");
}


static void rotateRight(node_t * node)
{    
    node_t * newRoot = node->left;
    node_t * oldRightChild= newRoot->right;
    node_t * parent = node->parent;
    
    if (node == treeRoot) {
        treeRoot = newRoot;
    }
    
    setRightNode(newRoot, node);
    setLeftNode(node, oldRightChild);
    
    if (parent) {
        if (parent->left == node) {
            setLeftNode(parent, newRoot);
        } else if (parent->right == node) {
            setRightNode(parent, newRoot);
        }
    } else {
        newRoot->parent = NULL;
    }
}

static void balanceNode(node_t * node)
{
    if (node == NULL)
        return;
    
    
    int diff = balanceFactor(node);
    
    if (abs(diff) > 1) {
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
                if (leftBal == 1) {
                    rotateRight(node);
                }
                else if (leftBal == -1) {
                    printf("left right case\n");
                //    rotateRight(node);
                }
                break;
            default:
                printf("Unbalanced: %i\n", diff);
        }
    }
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
            setLeftNode(root, n);
            balanceNode(root->parent);
            
        } else {
            insertLetter(root->left, character, darkness);
        }
    } else {
        if (root->right == NULL) {
            
            node_t * n = newNode(character, darkness);
            setRightNode(root, n);
            balanceNode(root->parent);

        } else {
            insertLetter(root->right, character, darkness);
        }
    }
    
}

static void destroyNode(node_t * node)
{
    if (node == NULL) return;
    
    free(node->letter->character);
    free(node->letter);
    free(node);
}

void destroyTree(node_t * root)
{
    if (root == NULL) return;
    
    destroyTree(root->left);
    root->left = NULL;
    destroyTree(root->right);
    root->right = NULL;
    destroyNode(root);
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


