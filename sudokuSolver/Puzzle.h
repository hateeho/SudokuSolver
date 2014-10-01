//
//  Puzzle.h
//  sudokuSolver
//
//  Created by Nathan on 2014-09-07.
//  Copyright (c) 2014 Nathan. All rights reserved.
//

#ifndef __sudokuSolver__Puzzle__
#define __sudokuSolver__Puzzle__

#include <iostream>
#include <assert.h>
#include "Element.h"

#endif /* defined(__sudokuSolver__Puzzle__) */


class Puzzle
{
    Element table[9][9];

    int numSolved;
    int changed;
    
public:
    
    void setValue(int a[9][9]);
    void syncValue();
    void printTable();
    void printPossibility();
    void findOne(int y, int x, int i);
    
    int  verify();
    int  verifyRow(int row);
    int  verifyCol(int col);
    int  verifyBlk(int blk);
    
    void solvePuzzle();
    void solveRow(int row);
    void solveCol(int col);
    void solveBlk(int blk);
    
    void reduceRow(int row, int value);
    void reduceCol(int col, int value);
    void reduceBlk(int blk, int value);

    Puzzle()
    {
        numSolved = 0;
        changed = 0;
    }
    
    ~Puzzle()
    {
        int x,y;
        
        if(numSolved!=81)
        {
            for(y=0; y<9; y++)
            {
                for(x=0; x<9; x++)
                {
                    if(table[y][x].n == 0)
                    {
                        table[y][x].release();
                    }
                }
            }
        }
    }

};
