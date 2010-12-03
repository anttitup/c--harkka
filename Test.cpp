#include<iostream>
#include <typeinfo>
using namespace std;
	
	Test:Test::template <class T> 
		bool equals(T& expected, T& answer)
	{	
		++test_number;

		if(expected != answer)
		{
			cout<<"problem at test: "<<test_number<<endl;
		} 

		return (this_ == that_);
	}

	Test:Test::template<class T>
		bool less(T& expected, T& answer)
	{	
		++test_number;

		if(expected != answer)
		{
			cout<<"problem at test: "<<test_number<<endl;
		} 


		return (less_<that_);
	}	

	Test:Test::template<class T>
		bool greater(T& expected, T& answer)
	{
		++test_number;

		if(expected != answer)
		{
			cout<<"problem at test: "<<test_number<<endl;
		} 

		return(greater_>that_);
	}

	Test:Test::template<class T> 
		bool  assert_function(T& expected,T& answer,int(*funct)(T,T))
	{
		++test_number;

		if(funct(expected,answer))
		{
			cout<<"problem at test: "<<test_number<<endl;
		} 

		return funct(expected,answer);
	}
	
	Test:Test::template <class T, class A> 
		bool same_type(T& this_, A& that_)
	{
		
		++test_number;

		if(typeid(this_)==typeid(that_))
		{
			cout<<"problem at test: "<<test_number<<endl;
		}
		
		return (typeid(this_)==typeid(that_));
	}

	Test:Test::template<class T> 
		bool is_a_Null (T this_)
	{
		++test_number;

		if(this_ != NULL )
		{
			cout<<"problem at test: "<<test_number<<endl;
		}

		return (this_==NULL);
	}
	



