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
		while(iter!=NULL){
			delete iter;
			iter = iter->get_next();
		}
		First=NULL;
		Last=NULL;
	}

	SList::SList(const SList& cp_this)
	{
		Node *iter_b,*iter;	
		for(SList_iterator it=cp_this.begin();
			it!=cp_this.end();it++)
		{
			iter = new Node((*it).get_stringi());

			if(it==cp_this.begin())
				First =iter;

			iter_b->set_next(iter);
			iter_b=iter;
		}
		
		Last=iter;
		iter_b=NULL;
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
		Node * new_last=First;
        while((new_last=new_last->get_next())!=Last)
			;
		delete Last;
		Last=new_last;		
		return ret;
    }
   	
    void SList::reverse()
    {
		Node * new_root=NULL;
		Node * root = this->First;
		Node * last= this->First; 
  		while (root!=NULL) 
		{
   			Node* next = root->get_next();
    		root->set_next(new_root);
    		new_root = root;
    		root = next;
  		} 

        First=new_root;
		Last=last; 
   	}
 
    void SList::swap(SList& other)
    {	
		Node *temp,*temp_;
		temp =this->First;
		temp_ = this->Last;
		
		this->First=other.First;
		this->Last=other.Last;
	
		other.First=temp;
		other.Last=temp_;	
    }

	int SList::len()
	{
		int len =0;
		Node* iter = First;
		while(iter!=NULL)
		{
			len++;
			iter=iter->get_next();
		}
		return len;
	}

    std::ostream& operator<<(std::ostream& out, const SList& cSList)
    {
		out<<"Node:";
		for(SList_iterator it = cSList.begin(); it!=cSList.end();it++)
		    out<<(*it).get_stringi()<<" ";
    	return out;
	}    
   
	SList_iterator SList::begin()const
	{
		return SList_iterator(First);
	}
	
	SList_iterator SList::end()const
	{
		return SList_iterator(Last->get_next());
	}

	std::istream& operator>>(std::istream& in, SList& cSList)
	{
			std::string temp;
			in>>temp;
			Node* new_node = new Node(temp);
			cSList.get_last()->set_next(new_node);
			cSList.set_last(new_node);
			return in;
	}	

	SList_iterator& SList_iterator::operator++()
	{
		p=p->get_next();
		return *this;		
	}

	const_SList_iterator const& const_SList_iterator::operator++()
	{
		p=p->get_next();
		return *this;		
	}

	
