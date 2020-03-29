#pragma once

#include <cstdlib>
#include <stdlib.h>
//#include <time.h> used to prototype I used rand() to generate random values while building my linked list so I didn't have to keep entering values I could just have them randomly made.
#include <iostream>
#include "node.h"	//linking 
#include "linked_list.h"	//linking

using namespace std;
/**
 * @breif 	Creates a space in memory for the program to run in 
 */
int menu();
void clearScreen();
void pauseScreen();
//declaring forward declarations to initialize before calling in main

