//
//  node.h
//  sudokuSolver
//
//  Created by Nathan on 2014-09-14.
//  Copyright (c) 2014 Nathan. All rights reserved.
//

#ifndef __sudokuSolver__node__
#define __sudokuSolver__node__

#include <iostream>
#include "Node.h"

#endif /* defined(__sudokuSolver__node__) */



class Element
{
public:
    int n;
    Node * list;
    int changed;

    void initList();
    void findOne(int i);
    void reduce(int value);

    int ifDetermined();

    void release();
    
};
