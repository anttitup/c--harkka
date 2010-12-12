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
        this->next = NULL;
		stringi.clear();
    }

    void Node::set_stringi(std::string const& new_string)
    {
       this->stringi=new_string; 
    }   
    
    void Node::set_next(Node* next_)
    {
        this->next=next_;
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
    { 
		Node * iter = First;
		while((iter=iter->get_next())!=NULL)
			delete iter;
		delete Last;
		First=NULL;
		Last=NULL;
	}

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
    	if(this->len()<2)
			Last=this->First->get_next();
	} 
     
    void SList::push_back(std::string const& ref)
    {
        Node* last = new Node(ref, NULL);
		if(this->len()<2)
			First=Last;
		Last->set_next(last);
		Last =last;
	}

    std::string const SList::pop_front()
    {
		std::string ret = First->get_stringi();
		Node * new_first = First->get_next();
    	delete(First);
		First=new_first;
		return ret;
    }
    
    std::string const SList::pop_back() 
    {
        std::string ret = Last->get_stringi();
        //iter len-1 Last this;
        return ret;
    }
   	
    void SList::reverse()
    {
		Node * new_head = First; 
	   	Node * auxiliary_tail = Last;
		Node * help; 
		while ( new_head != auxiliary_tail ) 
	   	{ 
	   		Node * tmp = new_head ; 
	   		new_head = new_head->get_next(); 
			help=auxiliary_tail->get_next();
	   		tmp->set_next(help); 
	   		auxiliary_tail->set_next(tmp); 
		} 

        First=new_head;
		Last=auxiliary_tail; 
    }

    void SList::swap(int index,int other_index)
    {	
		int i=0;
		int j=0;
		Node * in;
		Node * se;
		while(i!=index)
		{
			in=in->get_next();
			i++;
		}

		std::string tmp =in->get_stringi();
		while(j!=other_index)
		{
			se=se->get_next();
			j++;
		}
		
		std::string tmp_ = se->get_stringi();
		in->set_stringi(tmp_);
		se->set_stringi(tmp);
    }

	int SList::len()
	{
		int len =0;
		Node* iter = First;
		while((iter=iter->get_next())!=NULL)
			len++;
		return len;
	}

    std::ostream& operator<<(std::ostream& out, SList& cSList)
    {
        SList_iterator begin(cSList.get_first());
		SList_iterator end(cSList.get_last());
		out<<"ehllo";
		for(SList_iterator it = begin; it!=end;it++)
		out<<(*it).get_stringi()<<"\n";
    	return out;
	}    
    
	
	SList_iterator& SList_iterator::operator++()
	{
		p=p->get_next();
		return *this;		
	}

		

