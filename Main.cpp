#include"Main.h"

int main()
{
	Test* test =new Test();
	test_creating_empty_list(test);
	test_creating_full_list(test);
	test_front(test);
	test_push_front(test);
}

void test_creating_empty_list(Test * test)
{
	SList * list= new SList();
	Node * f_node = list->get_first();
	Node * b_node = list->get_last();
	
	test->is_a_null(f_node);
	test->is_a_null(b_node);
}

void test_creating_full_list(Test * test)
{
	std::string s("hello");	
	SList* full_list = new SList("hello","hello");
	std::string f_node = full_list->get_first()->get_stringi();
	std::string b_node = full_list->get_last()->get_stringi();

	test->equals(f_node,s);
	test->equals(b_node,s);	
}

void test_front(Test* test)
{
	SList* full_list = new SList("hello","word");
	std::string s("hello");
	std::string f_ = full_list->front();
	test->equals(f_,s);
}

void test_push_front(Test* test)
{
	std::string s("hello");
	SList* list = new SList("hello","word");
	list->push_front(s);
	std::string act=list->get_first()->get_stringi();
	test->equals(act,s);
}

void_push_back(Test* test)
{

}
