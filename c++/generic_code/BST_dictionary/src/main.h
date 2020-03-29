#ifndef MAIN_H
#define MAIN_H

#include <cstdlib>
#include <iostream>

#include "BST.h"
/**
 * @brief      clears user screen
 */
void clearScreen(void);
/**
 * Binary Search Tree
 *
 * Creates an enviornemnt for the main code to run in 
 */
int main(void);
/**
 * @brief      stop screen so user can read text
 */
void pauseScreen(void);
/**
 * @brief      Creates user selectable menu
 *
 * @return     choice for program to operate off of 
 */
int menu(void);
/**
 * statically created object my tree for use with menu
 */
BST myTree = BST();

#endif
