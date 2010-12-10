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
        void set_next(Node* next);
};

class SList
{
    private:        
        Node* First;
        Node* Last;
    public:
        SList(Node * first,Node * last);
        ~SList(); 
        Node* get_first();
        Node* get_last();
        void set_first(Node * first);
        void set_last(Node * last);
        std::string const& front()const;
        void push_front(std::string const&);
        void push_back(std::string const&);
        std::string const& pop_front()const;
        std::string const& pop_back()const;
        void reverse();
        void swap(int index, int other_index);
        friend std::ostream& operator<<(std::ostream &out, Node &cNode);
};

class SList_iterator:public std::iterator<std::string,int>
{
    private:
        int* p;
    public:
        SList_iterator(int* x):p(x){};
        SList_iterator(const SList_iterator& mit): p(mit.p){}
        SList_iterator& operator++(){++p; return *this;}
        SList_iterator& operator++(int){SList_iterator tmp(*this); operator++();return tmp;}
        bool operator==(const SList_iterator& rhs){return p==rhs.p;}
        bool operator!=(const SList_iterator& rhs){return p!=rhs.p;}
        int& operator*(){return *p;} 
};
