#include <iostream>
#include <variant>
using namespace std;
template<class T>
double get_value(T& variant_);

class AnyType
{
	string typeName;
	std::variant
		<bool
		, char
		, int
		, double>
		value;
public:
	AnyType() {}

	template<class T>
	AnyType(const T value_) : value(value_), typeName(typeid(value_).name()) {}

	AnyType(const AnyType& ob)
	{
		value = ob.value;
		typeName = ob.typeName;
	}



	template<class T>
	AnyType& operator = (T value_) {
		value = value_;
		typeName = typeid(value_).name();
		return *this;
	}


	AnyType& operator=(const AnyType& ob) {
		value = ob.value;
		typeName = ob.typeName;
		return *this;
	}

	double getValue()
	{
		if (!typeName.empty())
			return get_value(value);
		throw exception("Variable is empty.");
	}

	void swap(AnyType& ob)
	{
		value.swap(ob.value);
		std::swap(typeName, ob.typeName);
	}

	template<class T> T toType()
	{
		if (typeName.empty())
		{
			throw exception("Variable is empty.");
		}
		T typeValue = get_value(value);
		if (!typeName.empty() && typeValue == get_value(value))
		{
			return (T)(get_value(value));
		}
		string except = "Bad cast " + typeName;
		except += " to ";
		except += typeid(T).name();
		except += "!!!";
		throw exception(except.c_str());
	}

	string getType()
	{
		if (!typeName.empty())
		{
			return typeName;
		}
		return "empty";
	}

	~AnyType()
	{
		typeName.clear();
	}


};

template <class T>
double get_value(T& variant_) {
	if (auto res = get_if<bool>(&variant_)) {
		return *res;
	}
	else if (auto res = get_if<char>(&variant_)) {
		return *res;
	}
	else if (auto res = get_if<int>(&variant_)) {
		return *res;
	}
	return *(get_if<double>(&variant_));
}