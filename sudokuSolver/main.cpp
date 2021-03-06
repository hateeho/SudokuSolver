//
//  main.cpp
//  sudokuSolver
//
//  Created by Nathan on 2014-09-07.
//  Copyright (c) 2014 Nathan. All rights reserved.
//

#include <iostream>
#include "Puzzle.h"

using namespace std;


int main(int argc, const char * argv[])
{
    Puzzle *p = new Puzzle();
    
    int a[9][9]={          //correct
        {1,0,3,4,5,6,7,8,9},
        {4,5,6,7,8,9,1,2,3},
        {7,8,9,1,2,3,4,5,6},
        {2,3,4,5,6,7,8,9,1},
        {5,6,7,8,9,1,2,3,4},
        {8,9,1,2,3,4,5,6,7},
        {3,4,5,6,7,8,9,1,2},
        {6,7,8,9,1,2,3,4,5},
        {9,1,2,3,4,5,6,7,8}};
    
    /*
     int a[9][9]={          //wrong!
     {1,2,3,4,5,6,7,8,9},
     {2,3,4,5,6,7,8,9,1},
     {3,4,5,6,7,8,9,1,2},
     {4,5,6,7,8,9,1,2,3},
     {5,6,7,8,9,1,2,3,4},
     {6,7,8,9,1,2,3,4,5},
     {7,8,9,1,2,3,4,5,6},
     {8,9,1,2,3,4,5,6,7},
     {9,1,2,3,4,5,6,7,8}};
     
     int a[9][9]={          //correct
     {1,2,3,4,5,6,7,8,9},
     {4,5,6,7,8,9,1,2,3},
     {7,8,9,1,2,3,4,5,6},
     {2,3,4,5,6,7,8,9,1},
     {5,6,7,8,9,1,2,3,4},
     {8,9,1,2,3,4,5,6,7},
     {3,4,5,6,7,8,9,1,2},
     {6,7,8,9,1,2,3,4,5},
     {9,1,2,3,4,5,6,7,8}};
     */

    
    p->setValue(a);
    p->printTable();
    
//    p.solvePuzzle();

    p->verify();
    
    
    
    return 0;
}

