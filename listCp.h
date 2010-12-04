class Node
{
    private:
        std::string stringi;
        Node* next;
        Node* prev
    public:
        std::string const& stringi() const;
        void stringi(std::string const& stringi):stringi(stringi){};
        Node* next(return this->next;);
        Node* prev(return this->prev;);
        void next(Node * next=NULL);
        void prev(Node * prev=NULL);
}

class ListCP
{
    private:        
        Node first,
        Node last;
    public:
        ListCP(Node first=NULL,Node Last=NULL);
        ~ListCP();

        std::string first const& first() consti;
        void first(std::string const&);
        std::string last const& last()const;
        void last(std::string const&);
        
        std::string front();
        void push_front(std::string const&);
        void push_back(std::string const&);
        std::string const& pop_front()const;
        std::string const& pop_back()const;
        void reverse();
        void swap(int index, int other_index);
        ListCP& ListCP::operator=(const ListCP& rhs);
}

class ListCP_iterator:public iterator<input_iterator_tag,int>
{
    private:
        int *p;
    public:
        ListCP_iterator(int* x):p(x){};
        ListCP_iterator(const ListCP_iterator& mit): p(mit.p){}
        ListCP_iterator& operator++(){++p; return *this;}
        ListCP_iterator& (int){ListCP_iterator tmp(*this); operator()++;return tmp;}
        bool operator==(const ListCP_iterator& rhs){return p==rhs.p;}
        bool operator!=(const ListCP_iterator& rhs){return p!=rhs.p;}
        int& operator*() {return *p;} 
}
