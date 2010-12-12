#include<iostream>
#include <typeinfo>
class Test
{
	private:
	    int test_number;
	public:
	    int const& get_test_number() const;
		void set_test_number(int const& newNumber);
		template<class T> bool equals(T&,T&);
		template<class T> bool less(T&,T&);
		template<class T> bool greater(T&,T&);
		template<class T> 
		bool assert_function(T&,T&,int(*funct)(T,T));
		template<class T,class A> bool same_type(T&,A&);
		template<class T> bool is_a_null(T&);
};

