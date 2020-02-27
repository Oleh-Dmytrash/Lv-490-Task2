#pragma once

#include <typeinfo>
#include <string.h>
#include <string>
#include "Element.h"
#include "TypeUnion.h"

using namespace std;

class AnyType
{
public:
	AnyType();	
	template<typename T>
	AnyType(T input);
	~AnyType();	
	
	template<typename T>
	AnyType& operator=(T input);

	AnyType& operator=(const AnyType& anyType);
	
	void swap(AnyType& anyType);//swap two element

	//converting functions
	bool ToBool();
	int ToInt();	
	char ToChar();
	double ToDouble();

	//getting element type
	std::string GetType();

private:
	Element m_element;//struct with element type and element value
	bool TypeSafeConvert(std::string type_for_converting);//checking if convert is type-save
};


template<typename T>
inline AnyType::AnyType(T input)
{
	if (strcmp(typeid(input).name(), "bool") == 0)
	{
		m_element.value.boolean = input;
		m_element.type = const_cast<type_info*>(&typeid(input));		
	}
	else if (strcmp(typeid(input).name(), "char") == 0)
	{
		m_element.value.character = input;
		m_element.type = const_cast<type_info*>(&typeid(input));	
	}
	else if (strcmp(typeid(input).name(), "int") == 0)
	{
		m_element.value.integer = input;
		m_element.type = const_cast<type_info*>(&typeid(input));		
	}
	else if (strcmp(typeid(input).name(), "double") == 0)
	{
		m_element.value.llf = input;
		m_element.type = const_cast<type_info*>(&typeid(input));		
	}
}

template<typename T>
inline AnyType& AnyType::operator=(T input)
{
	if (strcmp(typeid(input).name(), "bool") == 0)
	{
		m_element.value.boolean = input;
		m_element.type = const_cast<type_info*>(&typeid(input));
		return *this;
	}
	else if (strcmp(typeid(input).name(), "char") == 0)
	{
		m_element.value.character = input;
		m_element.type = const_cast<type_info*>(&typeid(input));
		return *this;
	}
	else if (strcmp(typeid(input).name(), "int") == 0)
	{
		m_element.value.integer = input;
		m_element.type = const_cast<type_info*>(&typeid(input));
		return *this;
	}
	else if (strcmp(typeid(input).name(), "double") == 0)
	{
		m_element.value.llf = input;
		m_element.type = const_cast<type_info*>(&typeid(input));
		return *this;
	}
}