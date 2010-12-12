#include "Test.h"
using namespace std;
template <class T> bool Test::equals(T& expected, T& answer)
{	
	++test_number;

	if(expected != answer)
	{
		cout<<"problem at test: "<<test_number<<endl;
	} 

	return (expected == answer);
}

template<class T> bool Test::less(T& expected, T& answer)
{	
	++test_number;

	if(expected != answer)
	{
		cout<<"problem at test: "<<test_number<<endl;
	} 


	return (expected<answer);
}	

template<class T> bool Test::greater(T& expected, T& answer)
{
	++test_number;

	if(expected != answer)
	{
		cout<<"problem at test: "<<test_number<<endl;
	} 

	return(expected>answer);
}

template<class T> bool  Test::assert_function
	(T& expected,T& answer,int(*funct)(T,T))
{
	++test_number;

	if(funct(expected,answer))
	{
		cout<<"problem at test: "<<test_number<<endl;
	} 

	return funct(expected,answer);
}

template <class T, class A> bool Test::same_type(T& this_, A& that_)
{
	
	++test_number;

	if(typeid(this_)==typeid(that_))
	{
		cout<<"problem at test: "<<test_number<<endl;
	}
	
	return (typeid(this_)==typeid(that_));
}

template<class T> 
	bool Test::is_a_null (T& this_)
{
	++test_number;

	if(this_ != NULL )
	{
		cout<<"problem at test: "<<test_number<<endl;
	}

	return (this_==NULL);
}




