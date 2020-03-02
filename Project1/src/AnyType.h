#pragma once
#include <typeinfo>
#include <string>
#include <memory>
#include <type_traits>
#include <stdexcept>

class AnyType
{
	std::string m_type;
	std::shared_ptr<void> m_data;
public:
	template<typename T>
	AnyType(T value)
	{
		static_assert(std::is_fundamental<T>::value, "The class only supports fundamental types");
		m_type = typeid(value).name(); 
		m_data = std::make_shared<T>(value);
	}


	template<typename T>
	AnyType operator=(T value) 
	{
		static_assert(std::is_fundamental<T>::value, "The class only supports fundamental types");
		m_type = typeid(value).name();
		m_data = std::make_shared<T>(value);
		return *this;
	}
	
	std::string Type()const { return m_type; }
	void Swap(AnyType& other)
	{
		std::swap(*this, other);
	}

	size_t GetTypeSize() const
	{
		if (m_type == "bool") return sizeof(bool);
		if (m_type == "char") return sizeof(char);
		if (m_type == "int") return sizeof(int);
		if (m_type == "float") return sizeof(float);
		if (m_type == "double") return sizeof(double);
	}
	
	bool ToBool()
	{
		if (m_type == "bool") return *(bool*)m_data.get();
		throw std::runtime_error("Can not convert to bool");
	}
	char ToChar()
	{
		if (m_type == "bool" || m_type == "char") return *(char*)m_data.get();
		throw std::runtime_error("Can not convert to char");
	}
	int ToInt()
	{
		if (m_type == "bool" || m_type == "char" || m_type == "int") return *(int*)m_data.get();
		throw std::runtime_error("Can not convert to int");
	}
	float ToFloat()
	{
		float return_value = 0;
		if (m_type == "float" ||
			m_type == "int" ||
			m_type == "char" ||
			m_type == "bool")
		{
			return_value = *(float*)m_data.get();
			return return_value;
		}
		throw std::runtime_error("Can not convert to float");
	}
	double ToDouble()
	{
		double return_value  = *(double*)m_data.get();
		return return_value;
	}

	~AnyType() {}
};
