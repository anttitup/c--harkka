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
    
    SList::SList(std::string first,std::string second) 
    { 
		First=NULL;
		Last=NULL;
		if(first!="")
			this->First= new Node(first);
		if(second!="")
		{
			this->Last = new Node(second);
        	this->First->set_next(Last);
		}
		else
			this->Last=First;

    }

    SList::~SList()
    { }

    Node * SList::get_first() const
    {
        return First;        
    }

    Node * SList::get_last() const 
    {
        return Last;
    }

    void SList::set_first(Node * first) 
    {
        First=first;
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
        Node* last = new Node(ref, NULL);
        Last->set_next(last);
		Last =last;
		    
	}

    std::string SList::pop_front()
    {
		std::string ret = First->get_stringi();
		Node * new_first = First->get_next();
    	delete(First);
		First=new_first;
		return ret;
    }
    
    std::string SList::pop_back() 
    {
        std::string ret = Last->get_stringi();
        //iter len-1 Last this;
        return ret;
    }
    
    void SList::reverse()
    {
    }

    void SList::swap(int index,int other_index)
    {
    }

	int SList::len()
	{
		int len =0;
		Node* iter = First;
		while((iter=iter->get_next())!=NULL)
			len++;
		return len;
	}

    std::ostream& operator<<(std::ostream& out, Node& cNode)
    {
        // iter
    }    
    std::ostream& operator>>(std::ostream& in, Node & cNode)
    {
        //do something
	}
	
	SList_iterator& SList_iterator::operator++()
	{
		p=p->get_next();
		return *this;		
	}




