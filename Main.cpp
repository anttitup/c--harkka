#include"Main.h"

int main()
{
	Test* test =new Test();
	test_creating_empty_list(test);
	test_creating_full_list(test);
	test_front(test);
	test_push_front(test);
	test_push_back(test);
	test_pop_front(test);
	test_pop_back(test);
	test_iter(test);
	test_reverse(test);
	test_swap(test);
	test_input(test);	
}

void test_creating_empty_list(Test * test)
{
	SList * list= new SList();
	Node * f_node = list->get_first();
	Node * b_node = list->get_last();
	
	test->is_a_null(f_node);
	test->is_a_null(b_node);
	delete list;
}

void test_creating_full_list(Test * test)
{
	std::string s("hello");	
	SList* full_list =new SList("hello","hello");
	std::string f_node = full_list->get_first()->get_stringi();
	std::string b_node = full_list->get_last()->get_stringi();
	test->equals(b_node,s);
	delete full_list;	
}

void test_front(Test* test)
{
	SList* full_list = new SList("hello","word");
	std::string s("hello");
	std::string f_ = full_list->front();
	test->equals(f_,s);
	delete full_list;
}

void test_push_front(Test* test)
{
	std::string s("hello");
	SList* list = new SList("hello","word");
	list->push_front(s);
	std::string act=list->get_first()->get_stringi();
	test->equals(act,s);
	delete list;
}

void test_push_back(Test* test)
{
	std::string s("hello");
	SList* list= new SList("hello","word");
	list->push_back(s);
	std::string act = list->get_last()->get_stringi();
	test->equals(act,s);
	delete list;
}

void test_pop_front(Test* test)
{
	std::string s("hello");
	SList* list =new SList("hello","world");
	std::string act = list->pop_front();	
	test->equals(act,s);
	delete list;
}

void test_pop_back(Test* test)
{
	std::string s("world");
	SList* list = new SList("hello","world");
	std::cout<<(*list)<<std::endl;
	std::string act = list->pop_back();
	test->equals(act,s);
	delete list;		
}

void test_iter(Test* test)
{
	SList* list = new SList("hello","wordl");
	list->push_back("hi");
	list->push_back("why");
//	for(SList_iterator it = list->begin();it!=list->end();it++)
//		std::cout<<(*it).get_stringi()<<endl;
	delete list;
}

void test_reverse(Test* test)
{
	SList* list = new SList("hello","wordl");
	list->push_back("hi");
	list->push_back("why");
	
	(*list).reverse();
	delete list;
}

void test_swap(Test* test)
{
	SList *list = new SList("hello","world");
	SList *list_ = new SList("hei","maailma");
	
	list->swap((*list_));
	std::cout<<(*list)<<std::endl;
	std::cout<<(*list_)<<std::endl;
	delete list;
	delete list_;
}

void test_input(Test* test)
{
	SList *list = new SList("hello","world");
	cin>>(*list);
	std::cout<<(*list)<<std::endl;
	delete list;
}

void test_cp(Test* test)
{
	SList *list = new SList("hello","world");
	SList *list_ = new SList((*list));
	std::cout<<(*listi_)<<std::endl;
} 
