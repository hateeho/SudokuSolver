//
//  Node.h
//  sudokuSolver
//
//  Created by Nathan on 2014-09-14.
//  Copyright (c) 2014 Nathan. All rights reserved.
//

#ifndef __sudokuSolver__Node__
#define __sudokuSolver__Node__

#include <iostream>

#endif /* defined(__sudokuSolver__Node__) */


class Node
{
public:
    
    int n;
    Node* next;
    
    Node()
    {
    }
    
    Node(int x)
    {
        n = x;
        next = nullptr;
    }
};