#include<iostream>
#include<string.h>
#include<fstream>
#include<iterator>
class Node
{
    private:
        std::string stringi;
        Node* next;
    public:
        Node(std::string stringi="",Node * next = NULL);
        ~Node();
        //getter
        std::string const& get_stringi()const;
        Node * get_next();
        //setter
        void set_stringi(std::string const& new_string);
        void set_next(Node *);
};

class SList
{
    private:        
        Node* First;
        Node* Last;
    public:
        SList(std::string="",std::string="");
        ~SList(); 
        Node* get_first()const;
        Node* get_last()const;
        void set_first(Node*  first);
        void set_last(Node* last);
        std::string const& front()const;
        void push_front(std::string const&);
        void push_back(std::string const&);
        std::string const  pop_front();
        std::string const pop_back();
        void reverse();
        void swap(int index, int other_index);
       	friend std::ostream& operator<<(std::ostream&, const SList&);
		int len(); 
};

class SList_iterator:public 
	std::iterator<std::input_iterator_tag,Node>
{
    private:
        Node* p;
    public:
        SList_iterator(Node* x):p(x){};
        SList_iterator(const SList_iterator& mit): p(mit.p){}
        SList_iterator& operator++();
        bool operator==(const SList_iterator& rhs){return p==rhs.p;}
        bool operator!=(const SList_iterator& rhs){return p!=rhs.p;}
		SList_iterator& operator++(int) {SList_iterator tmp(*this); 
			operator++(); return tmp;}
        Node& operator*(){return *p;}
};

class const_SList_iterator:public 
	std::iterator<std::forward_iterator_tag,Node>
{
    private:
        Node* p;
    public:
        const_SList_iterator(Node* x):p(x){};
        const_SList_iterator(const const_SList_iterator& mit): p(mit.p){}
        const_SList_iterator const& operator++();
        bool operator==(const_SList_iterator& rhs){return p==rhs.p;}
        bool operator!=(const_SList_iterator& rhs){return p!=rhs.p;}
		const_SList_iterator const& operator++(int) {const_SList_iterator tmp(*this); 
			operator++(); return tmp;}
        Node const& operator*(){return *p;}
};
