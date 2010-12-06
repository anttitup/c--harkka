/*
 * =====================================================================================
 *
 *       Filename:  SList.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/12/10 18:19:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  
 *        Company:  
 *
 * =====================================================================================
 */


#include "SList.h"
using namespace std;
class Node
{
    Node(string stringi, Node * next)
    {
        this->stringi = stringi;
        this->next= next;
        
    }
    
    ~Node()
    {
        delete this->stringi;
        this->next = NULL;
        delete this;
    }

    string const& stringi() const  
    {
        return stringi;
    }
    
    Node* next()
    {
        return this->next;        
    }

    void next(Node* next)
    {
        return this->next=next;
    }
}

class SList
{
    SList(Node first,Node Last) 
    {
        this->First=first;
        this->Last=last;
    }

    ~Slist()
    {
    }

    Node* first()
    {
        return this->First;
    }
    void first(Node *first)
    {
        this->First = first;
    }

    Node* Last()
    {
        return this->Last;
    }

    void last(Node *last)
    {
        this->Last=last;
    }

   string const& front() const
    {
        return this->First->stringi();
    }
    
   void push_front(string const& ref)
    {
        Node * first= &Node(ref,this->first->next());
        Slist->First = first;
    } 
     
    void push_back(string const& ref)
    {
        Node *first = & Node(ref, NULL);
        this->Last->next(first);
    }
}

