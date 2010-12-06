
class Node
{
    private:
        std::string stringi;
        Node* next;
    public:
        Node(std::string stringi="",Node * next = NULL);
        ~Node();

        const std::string stringi() const;
        void stringi(std::string const& stringi):stringi(stringi){};
        Node* next();
        void next(Node * next=NULL);
}

class SList
{
    private:        
        Node * First,
        Node * Last;
    public:
        SĹist(Node first=NULL,Node Last=NULL);
        ~SList();

        Node * first();
        void first(Node * first);
        Node * last();
        void last(Node * last);
        
        std::string const& front()const;
        void push_front(std::string const&);
        void push_back(std::string const&);
        std::string const& pop_front()const;
        std::string const& pop_back()const;
        void reverse();
        void swap(int index, int other_index);
        SList& Slist::operator=(const ListCP& rhs);
}

class Slist_iterator:public iterator<input_iterator_tag,int>
{
    private:
        int *p;
    public:
        SList_iterator(int* x):p(x){};
        SList_iterator(const SList_iterator& mit): p(mit.p){}
        SList_iterator& operator++(){++p; return *this;}
        SList_iterator& (int){SList_iterator tmp(*this); operator()++;return tmp;}
        bool operator==(const SList_iterator& rhs){return p==rhs.p;}
        bool operator!=(const SList_iterator& rhs){return p!=rhs.p;}
        int& operator*() {return *p;} 
}
