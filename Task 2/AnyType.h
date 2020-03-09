#include <iostream>
#include<string>
using namespace std;
class AnyType
{
public:
	template<class T>
	AnyType(T temp)
	{
		static_assert(is_fundamental<T>::value, "Only fundamental types");

		type_name = typeid(temp).name();
		value = make_shared<T>(temp);
	}
	~AnyType() {}

	template <typename T>
	AnyType operator=(T temp)
	{
		static_assert(is_fundamental<T>::value, "Only fundamental types");

		type_name = typeid(temp).name();
		value = make_shared<T>(temp);
		return *this;
	}

	AnyType swap_type(AnyType& a)
	{
		swap(*this, a);
		return *this;
	}

	string GetType() const { return type_name; }

	size_t GetTypeSize() const
	{
		if (type_name == "bool") return sizeof(bool);
		if (type_name == "char") return sizeof(char);
		if (type_name == "_int64") return sizeof(long long);
		if (type_name == "double") return sizeof(double);
	}

	bool ToBool()
	{
		if (type_name == "char" || type_name == "bool") return *(bool*)value.get();
		throw std::runtime_error("Can not convert to bool");
	}

	char ToChar()
	{
		if (type_name == "char"||type_name=="bool") return *(char*)value.get();
		throw std::runtime_error("Can not convert to char");
	}

	long long ToLongLong()
	{
		if (type_name == "__int64"||type_name == "char"
		 || type_name == "bool")
		return *(long long*)value.get();
		throw std::runtime_error("Can not convert to long long");
	}

	double ToDouble()
	{
		double res = 0.0;
		if (type_name == "double" || type_name == "__int64"
			|| type_name == "char" || type_name == "bool")
		{
			res= *(double*)value.get();
			return res;
		}
		throw std::runtime_error("Can not convert to double");
	}

private:
	string type_name;
	shared_ptr<void> value;
};