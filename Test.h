namespace Test
{
	class Test
	{
		private:
			int test_number;
		public:
			int const& test_number() const;
			void test_number(int const& newNumber);	
	}

	template<class T> bool equals(T,T);
	template<class T> bool less(T,T);
	template<class T> bool greater(T,T);
	template<class T> bool assert_function(T,T,int(*funct)(T,T));
	template<class T> bool same_type(T,T);
}
