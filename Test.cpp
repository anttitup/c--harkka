#include<iostream>
#include <typeinfo>

using namespace std;

class Test
{
	private:
	    int test_number;
	public:
	    inline Test();
		inline ~Test();
		int const& get_test_number() const;
		void set_test_number(int const& newNumber);
		template<class T> bool equals(T&,T&);
		template<class T> bool less(T&,T&);
		template<class T> bool greater(T&,T&);
		template<class T> 
		bool assert_function(T&,T&,int(*funct)(T,T));
		template<class T,class A> bool same_type(T&,A&);
		template<class T>bool is_a_null(T&);
};

Test::Test()
{
	test_number=0;
}

Test::~Test()
{
	delete this;
}

template <class T> bool Test::equals(T& expected, T& answer)
{	
	++test_number;

	if(expected != answer)
	{
		cout<<"problem at test: "<<test_number<<endl;
	} 
	else
		cout<<"it works: "<<test_number<<endl;
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
 
template <class T> bool Test::is_a_null (T& this_)
{
	++test_number;

	if(this_ != NULL )
	{
		cout<<"problem at test: "<<test_number<<endl;
	}
	else
		cout<<"test works:"<<test_number<<endl;
	return (this_==NULL);
}




