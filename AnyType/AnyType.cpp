#include "AnyType.h"

AnyType::AnyType()
{
	m_element.type = nullptr;
}

AnyType::~AnyType()
{
	m_element.type = nullptr;
}

AnyType& AnyType::operator=(const AnyType& anyType)
{
	if (this == &anyType)
	{
		return *this;
	}
	m_element.value = anyType.m_element.value;
	m_element.type = anyType.m_element.type;
	return *this;
}

void AnyType::swap(AnyType& anyType)
{
	if (this == &anyType)
	{
		return;
	}
	m_element.value = anyType.m_element.value;
	m_element.type = anyType.m_element.type;
}

bool AnyType::ToBool()
{
	if (!TypeSafeConvert("bool"))
	{
		throw std::exception("Can't convert to bool");
	}	
	return m_element.value.boolean;
}

int AnyType::ToInt()
{
	if (!TypeSafeConvert("int"))
	{
		throw std::exception("Can't convert to int");
	}

	if (GetType() == "bool") return m_element.value.boolean;
	if(GetType() == "char") return m_element.value.character;
	return m_element.value.integer;
}

char AnyType::ToChar()
{
	if (!TypeSafeConvert("char"))
	{
		throw std::exception("Can't convert to char");
	}

	if (GetType() == "bool") return m_element.value.boolean;
	return m_element.value.character;
}

double AnyType::ToDouble()
{
	if (!TypeSafeConvert("double"))
	{
		throw std::exception("Can't convert to double");
	}

	if (GetType() == "bool") return m_element.value.boolean;
	if (GetType() == "char") return m_element.value.character;
	if (GetType() == "int") return m_element.value.integer;	
	return m_element.value.llf;
}

std::string AnyType::GetType()
{
	return m_element.type->name();
}

bool AnyType::TypeSafeConvert(std::string type_for_converting)
{
	if (type_for_converting == "double") return true;
	
	std::string current_type_name(this->GetType());

	if (current_type_name == type_for_converting) return true;

	if (current_type_name == "bool") return true;

	if (current_type_name != "double" && type_for_converting == "double") return false;
	
	if (current_type_name == "bool" && type_for_converting != "bool") return false;

	if (current_type_name == "int" && type_for_converting == "double")
	{
		return true;
	}
	else
	{
		return false;
	}
}
