//
//  node.cpp
//  sudokuSolver
//
//  Created by Nathan on 2014-09-14.
//  Copyright (c) 2014 Nathan. All rights reserved.
//

#include "Element.h"
#include "assert.h"

int Element::ifDetermined()
{
    if(n==0)
        return 0;
    else
        return 1;
}

void Element::findOne(int i)
{
    n = i;
    release();
}

void Element::initList()
{
    int i;
    Node* curr;
 
    list = new Node(1);
    curr = list;
    
    for(i=2; i<=9; i++)
    {
        curr->next = new Node(i);
        curr = curr->next;
    }
}


void Element::reduce(int value)
{
    Node *curr, *prev;
    
    assert(list != nullptr);
    
    if(list->n == value)
    {
        curr = list;
        list = list->next;
        delete curr;
        return;
    }
    
    prev = list;
    curr = prev->next;
    
    while(curr != nullptr)
    {
        if(curr->n == value)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }
    
        prev = curr;
        curr = curr->next;
    }

}


void Element::release()
{
    Node * tmp;
    
    while(list != nullptr)
    {
        tmp = list;
        list = list->next;
        delete tmp;
    }
}
