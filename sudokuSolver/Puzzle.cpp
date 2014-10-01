//
//  Puzzle.cpp
//  sudokuSolver
//
//  Created by Nathan on 2014-09-07.
//  Copyright (c) 2014 Nathan. All rights reserved.
//

#include "Puzzle.h"
using namespace std;

void Puzzle::findOne(int y, int x, int i)
{
    table[y][x].n=i;
    table[y][x].findOne(i);
    numSolved++;
    printTable();
}

void Puzzle::setValue(int a[9][9])
{
    int x,y;
    
    numSolved=0;
    
    for(y=0; y<9; y++)
        for(x=0; x<9; x++)
        {
            if(a[y][x]!=0)
            {
                table[y][x].n = a[y][x];
                table[y][x].list = nullptr;
                numSolved++;
            }
            else
            {
                table[y][x].n = 0;
                table[y][x].initList();
            }
        }
}


void Puzzle::printTable()
{
    int x, y;
    
    for(y=0; y<9; y++)
    {
        if(y%3 == 0)
            std::cout << "\n";
        
        for(x=0; x<9; x++)
        {
            if(x%3 == 0)
                std::cout << " ";
            
            if(table[y][x].n==0)
                std::cout << "_ " ;
            else
                std::cout << table[y][x].n << " " ;
        }
        std::cout << "\n" ;
    }
    std::cout << std::endl ;
    std::cout << "numSolved: " << numSolved << endl << endl;
}

void Puzzle::printPossibility()
{
    int x, y;
    Node *curr;
    
    for(y=0; y<9; y++)
    {
        for(x=0; x<9; x++)
        {
            if(table[y][x].n!=0)
                continue;
            
            cout << "(" << y << ", " << x << "): ";
            
            curr = table[y][x].list;
            while(curr != nullptr)
            {
                cout << curr->n;
            }
            
        }
        std::cout << "\n" ;
    }
    cout << endl ;
}



int Puzzle::verifyRow(int row)
{
    int match;
    int i,j;
    
    for(i=1; i<=9; i++)
    {
        match = 0;
        for(j=0;j<9;j++)
        {
            if(table[row][j].n==i)
            {
                match = 1;
                break;
            }
        }
        
        if(match==0)
            return 0;
    }
    
    return 1;
}

int Puzzle::verifyCol(int col)
{
    int match;
    int i,j;
    
    for(i=1; i<=9; i++)
    {
        match = 0;
        for(j=0;j<9;j++)
        {
            if(table[j][col].n==i)
            {
                match = 1;
                break;
            }
        }
        
        if(match==0)
            return 0;
    }
    
    return 1;
}

int Puzzle::verifyBlk(int n)
{
    int match;
    int i;
    int startX, startY, x, y;
    
    startX = n%3 * 3;
    startY = n/3 * 3;
    
    for(i=1; i<=9; i++)
    {
        match = 0;
        
        for(y=0;y<3;y++)
        {
            for(x=0;x<3;x++)
            {
                if(table[startY+y][startX+x].n == i)
                {
                    match = 1;
                    break;
                }
            }
        }
        
        if(match==0)
            return 0;
    }
    
    return 1;
}


int Puzzle::verify()
{
    int i,j;
    
    std::cout << "Verifying..." << std::endl;
    
    //check for blank
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(table[i][j].n==0)
            {
                std::cout << "Puzzle incompelete!" << std::endl;
                return 0;
            }
                
        }
    }
    
    //check row
    for(i=0;i<9;i++)
    {
        if(verifyRow(i)==0)
        {
            std::cout << "Row check fail, row: " << i+1 << endl;
            return 0;
        }
    }
    
    //check colum
    for(i=0;i<9;i++)
    {
        if(verifyCol(i)==0)
        {
            std::cout << "Col check fail, col: " << i+1 << endl;
            return 0;
        }
    }
    
    //check block
    for(i=0;i<9;i++)
    {
        if(verifyBlk(i)==0)
        {
            std::cout << "Block check fail, blk: " << i+1 << endl;
            return 0;
        }
    }
    
    std::cout << "Correct!" << endl;
    return 1;
}



void Puzzle::solvePuzzle()
{
    int x,y;
    
    for(y=0; y<9; y++)
        for(x=0; x<9; x++)
        {
            if(table[y][x].n == 0)
                continue;
        
            reduceRow(y, table[y][x].n);
//            solveCol(x);
//            solveBlk(x,y);
            
            
            if(numSolved==81)
                return;
        }
}

void Puzzle::reduceRow(int row, int value)
{
    int i;
    
    for(i=0; i<9; i++)
    {
        if(table[row][i].n == 0)
        {
            table[row][i].reduce(value);
        }
    }
}




/*
void Puzzle::solvePuzzle()
{
    int i;
    
    for(i=0; i<9; i++)
    {
        if(numSolved == 81)
            return;
        
        solveRow(i);
        solveCol(i);
        solveBlk(i);
    }
}

void Puzzle::solveRow(int row)
{
    int i,j,n=0,idx=-1;
    
    for(i=0;i<9;i++)
    {
        if(value[row][i]==0)
        {
            n++;
            idx=i;
            if(n>1)
                return;
        }
    }
    
    if(n==0)
        return;
    
    assert(idx!=-1);
    
    for(i=1;i<=9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(value[row][j]==i)
                break;
        }
        
        if(j==9)
        {
            findOne(row,idx, i);
            return;
        }
    }
}

void Puzzle::solveCol(int col)
{
    int i,j,n=0,idx=-1;
    
    for(i=0;i<9;i++)
    {
        if(value[i][col]==0)
        {
            n++;
            idx=i;
            if(n>1)
                return;
        }
    }
    
    if(n==0)
        return;
    
    assert(idx!=-1);
    
    for(i=1;i<=9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(value[j][col]==i)
                break;
        }
        
        if(j==9)
        {
            findOne(idx,col,i);
            return;
        }
    }
}

void Puzzle::solveBlk(int blk)
{
    int i,x=0,y=0,n=0,idx_x=-1, idx_y=-1;
    int startX, startY;
    
    startX = blk%3 * 3;
    startY = blk/3 * 3;
    
    for(y=0;y<3;y++)
    {
        for(x=0;x<3;x++)
        {
            if(value[startY+y][startX+x] == 0)
            {
                n++;

                if(n>1)
                    return;
                
                idx_x=x;
                idx_y=y;
            }
        }
    }
    
    if(n==0)
        return;
    
    assert(idx_x!=-1 && idx_y!=-1);
    
    for(i=1;i<=9;i++)
    {
        for(y=0;y<3;y++)
        {
            for(x=0;x<3;x++)
            {
                if(value[startY+y][startX+x]==i)
                    goto NEXT_NUM;
            }
        }
    NEXT_NUM:
        
        if(x==3 && y==3)
        {
            findOne(startY+idx_y, startX+idx_x, i);
            return;
        }
    }
    
}

*/


