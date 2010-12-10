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

    Node::Node(std::string stringi, Node* next)
    {
        this->stringi = stringi;
        this->next= next;        
    }
    
    Node::~Node()
    {
        delete(&stringi);
        this->next = NULL;
        delete(this);
    }

    void Node::set_stringi(std::string const& new_string)
    {
       this->stringi=new_string; 
    }   
    
    void Node::set_next(Node* next)
    {
        this->next=next;
    }
 
    Node * Node::get_next() 
    {
        return this->next;        
    }
    
    std::string const& Node::get_stringi()const
    {
        return stringi;
    }

    //SList
    //
    //
    
    SList::SList(Node * first,Node * last) 
    {
        this->First=first;
        this->Last=last;
    }

    SList::~SList()
    {

    }

    Node * SList::get_first()
    {
        return First;        
    }

    Node * SList::get_last()
    {
        return Last;
    }

    void SList::set_first(Node *first)
    {
        First = first;
    }


    void SList::set_last(Node *last)
    {
        Last=last;
    }
    std::string const& SList::front() const
    {
        return this->First->get_stringi();
    }
    
    void SList::push_front(std::string const& ref)
    {
       this->First = new Node(ref,this->First->get_next());
    } 
     
    void SList::push_back(std::string const& ref)
    {
        Node* first = &Node(ref, NULL);
        //this->Last->next(first); iterator first
    }

    std::string const& SList::pop_front()const
    {
	std::string ret = First->get_stringi();
        Node new_first = First.get_next;
    	delete(First);
        set_first(new_first)
	return ret;
    }
    

    
    std::string const& SList::pop_back const
    {
        string ret = last()->stringi();
        //iter len-1 Last this;
        return ret;
    }
    
    void SList::reverse()
    {
        
    }

    void SList::swap()
    {
    }

    friend ostream& SList::operator<<(ostream &out, Node &cNode)
    {
        // iter
    }    
    friend ostream& SList::operator>>(ostream &in, Node cNode)
    {
        //do something
    }
}
