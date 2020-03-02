#pragma once
#include <typeinfo>
#include <string>
#include <memory>
#include <type_traits>
#include <stdexcept>

class AnyType
{
	std::string type;
	std::shared_ptr<void> data;
public:
	template<typename T>
	AnyType(T value)
	{
		static_assert(std::is_fundamental<T>::value, "The class only supports fundamental types");
		type = typeid(value).name(); 
		data = std::make_shared<T>(value);
	}


	template<typename T>
	AnyType operator=(T value) 
	{
		static_assert(std::is_fundamental<T>::value, "The class only supports fundamental types");
		type = typeid(value).name();
		data = std::make_shared<T>(value);
		return *this;
	}
	
	std::string Type()const { return type; }
	void Swap(AnyType& other)
	{
		std::swap(*this, other);
	}

	size_t GetTypeSize() const
	{
		if (type == "bool") return sizeof(bool);
		if (type == "char") return sizeof(char);
		if (type == "int") return sizeof(int);
		if (type == "float") return sizeof(float);
		if (type == "double") return sizeof(double);
	}
	
	bool ToBool()
	{
		if (type == "bool") return *(bool*)data.get();
		throw std::runtime_error("Can not convert to bool");
	}
	char ToChar()
	{
		if (type == "bool" || type == "char") return *(char*)data.get();
		throw std::runtime_error("Can not convert to char");
	}
	int ToInt()
	{
		if (type == "bool" || type == "char" || type == "int") return *(int*)data.get();
		throw std::runtime_error("Can not convert to int");
	}
	float ToFloat()
	{
		float return_value = 0;
		if (type == "float" ||
			type == "int" ||
			type == "char" ||
			type == "bool")
		{
			return_value = *(float*)data.get();
			return return_value;
		}
		throw std::runtime_error("Can not convert to float");
	}
	double ToDouble()
	{
		double return_value  = *(double*)data.get();
		return return_value;
	}

	~AnyType() {}
};
