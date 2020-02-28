#include<iostream>
#include <typeinfo>
#include <string>
using namespace std;

class Exception : public std::exception
{
	std::string _msg;
public:
	Exception(const std::string& msg) : _msg(msg) {}

	virtual const char* what() const noexcept override
	{
		return _msg.c_str();
	}
};




class AnyType {
public:
	enum Type_name
	{
		TypeBool,
		TypeChar, 	
		TypeInt, 
		TypeDouble, 
		TypeFloat
	} type_name;

	union Type_data
	{
		bool type_bool;
		char type_char;
		int	 type_int;
		double type_double;
		float type_float;
	} *type_data = NULL;

	void init() {
		if (type_data == NULL)
			type_data = new Type_data;
		(*type_data).type_double = 0.0;
	}

	template <typename T>
	void init( T & value) {
		if (type_data == NULL)
			type_data = new Type_data;
		auto typeid_name = typeid(value).name();
		if (typeid_name == typeid(bool).name()) {
			(*type_data).type_bool = (bool)value;
			type_name = Type_name::TypeBool;
		}
		else if (typeid_name == typeid(char).name()) {
			(*type_data).type_char = (char)value;
			type_name = Type_name::TypeChar;
		} 
		else if (typeid_name == typeid(int).name()) { 
			(*type_data).type_int = (int)value;
			type_name = Type_name::TypeInt;
		} 
		else if (typeid_name == typeid(double).name()) {
			(*type_data).type_double = (double)value;
			type_name = Type_name::TypeDouble;
		}
		else if (typeid_name == typeid(float).name()) {
			(*type_data).type_float = (float)value;
			type_name = Type_name::TypeFloat;
		}
		else {
			cerr << "error  in cast" << endl;
		}
	}

	AnyType() {
		init();
	};

	template <typename Type>
	AnyType(Type &&value) {
		init(value);
	};

	template <typename Type>

	AnyType& operator=( Type  value) {
		init(value);
		return *this;
	};
	//AnyType(AnyType&&) = default;
	AnyType& operator=(const AnyType& a)
	{
		if (&a == this)
			return *this;
		type_data = a.type_data;
		type_name = a.type_name;
		
		return *this;
	}

	template <typename T>
	T get_type_data() {
		T return_val;
		switch (type_name) {
		case Type_name::TypeBool:
			return_val = type_data->type_bool;
			break;
		case Type_name::TypeChar:
			return_val = type_data->type_char;
			break;
		case Type_name::TypeInt:
			return_val = type_data->type_int;
			break;
		case Type_name::TypeDouble:
			return_val = type_data->type_double;
			break;
		case Type_name::TypeFloat:
			return_val = type_data->type_float;
			break;
		default:
			throw Exception("undefined cast to char");
			break;
		}
		return return_val;
	}

	string get_type_name() {
		string str;
		switch (type_name) {
		case Type_name::TypeBool:
			str = "bool";
			break;
		case Type_name::TypeChar:
			str = "char";
			break;
		case Type_name::TypeInt:
			str = "int";
			break;
		case Type_name::TypeDouble:
			str = "double";
			break;
		case Type_name::TypeFloat:
			str = "float";
			break;
		default:
			str = "undefined";
			break;
		}
		return str;
	}
	
	string type_name_to_str(Type_name s) {
		string str;
		switch (s) {
		case Type_name::TypeBool:
			str = "bool";
			break;
		case Type_name::TypeChar:
			str = "char";
			break;
		case Type_name::TypeInt:
			str = "int";
			break;
		case Type_name::TypeDouble:
			str = "double";
			break;
		case Type_name::TypeFloat:
			str = "float";
			break;
		default:
			str = "undefined";
			break;
		}
		return str;
	}
	


	void show() {
		if (type_name == Type_name::TypeInt) {
			int type_int = (*type_data).type_int;
			cout << type_name_to_str(type_name) << "->" << type_int << endl;
		}
		else if (type_name == Type_name::TypeBool) {
			bool type_bool = (*type_data).type_bool;
			cout << type_name_to_str(type_name) << "->" << type_bool << endl;
		}
		else if (type_name == Type_name::TypeChar) {
			char type_char = (*type_data).type_char;
			cout << type_name_to_str(type_name) << "->" << type_char << endl;
		}
		else if (type_name == Type_name::TypeDouble) {
			double type_double = (*type_data).type_double;
			cout << type_name_to_str(type_name) << "->" << type_double << endl;
		}
		else if (type_name == Type_name::TypeFloat) {
			float type_float = (*type_data).type_float;
			cout << type_name_to_str(type_name) << "->" << type_float << endl;
		}
		else {
			cout << "err" << endl;
		}
	}

	double ToBool() {
		bool storedValue;
		switch (type_name) {
		case Type_name::TypeBool:
			storedValue = (bool)type_data->type_bool;
			break;
		case Type_name::TypeChar:
			if (type_data->type_char == '0' || type_data->type_char == '1') {
				storedValue = (bool)type_data->type_char;
			}
			else {
				throw Exception("undefined cast from char to bool");
			}
			break;
		case Type_name::TypeInt:
			if (type_data->type_int == 0 ||type_data->type_int == 1) {
				storedValue = (bool)type_data->type_char;
			}
			else {
				throw Exception("undefined cast from int to bool");
			}
			break;
		case Type_name::TypeDouble:
			if (type_data->type_double == 0.0 || type_data->type_double == 1.0) {
				storedValue = (bool)type_data->type_double;
			}
			else {
				throw Exception("undefined cast double int to bool");
			}
			break;
		case Type_name::TypeFloat:
			if (type_data->type_float == 0.0f || type_data->type_float == 1.0f) {
				storedValue = (bool)type_data->type_float;
			}
			else {
				throw Exception("undefined cast float int to bool");
			}
			break;
		default:
			throw Exception("undefined cast to bool");
			break;
		}
		return storedValue;
	}


	char ToChar() {
		char storedValue;
		switch (type_name) {
		case Type_name::TypeBool:
			storedValue = (char)type_data->type_bool;
			break;
		case Type_name::TypeChar:
			storedValue = (char)type_data->type_char;
			break;
		case Type_name::TypeInt:
			if (type_data->type_int >= 0 && type_data->type_int <= 9) {
				storedValue = (char)type_data->type_int;
			}
			else {
				throw Exception("undefined cast from int to char");
			}
			break;
		case Type_name::TypeDouble:
			if (type_data->type_double-(int)type_data->type_double ==0) {
				storedValue = (char)type_data->type_double;
			}
			else {
				throw Exception("undefined cast from double to char");
			}
			break;
		case Type_name::TypeFloat:
			if (type_data->type_float - (int)type_data->type_float == 0) {
				storedValue = (char)type_data->type_float;
			}
			else {
				throw Exception("undefined cast from float to char");
			}
			break;
		default:
			throw Exception("undefined cast to char");
			break;
		}
		return storedValue;
	}

	int ToInt() {
		int storedValue;
		switch (type_name) {
		case Type_name::TypeBool:
			storedValue = (int)type_data->type_bool;
			break;
		case Type_name::TypeChar:
			storedValue = (int)type_data->type_char;
			break;
		case Type_name::TypeInt:
			storedValue = (int)type_data->type_int;
			break;
		case Type_name::TypeDouble:
			if (type_data->type_double - (int)type_data->type_double == 0) {
				storedValue = (int)type_data->type_double;
			}
			else {
				throw Exception("undefined cast from double to int");
			}
			break;
		case Type_name::TypeFloat:
			if (type_data->type_float - (int)type_data->type_float == 0) {
				storedValue = (int)type_data->type_float;
			}
			else {
				throw Exception("undefined cast from float to int");
			}
			break;
		default:
			throw Exception("undefined cast to int");
			break;
		}
		return storedValue;
	}
	double ToDouble() {
		double storedValue;
		switch (type_name) {
		case Type_name::TypeBool:
			storedValue =(double)type_data->type_bool;
			break;
		case Type_name::TypeChar:
			storedValue = (double)type_data->type_char;
			break;
		case Type_name::TypeInt:
			storedValue = (double)type_data->type_int;
			break;
		case Type_name::TypeDouble:
			storedValue = (double)type_data->type_double;
			break;
		case Type_name::TypeFloat:
			storedValue = (double)type_data->type_float;
			break;
		default:
			throw Exception("undefined cast to double");
			break;
		}
		return storedValue;
	}

	void swap_s(AnyType &any_type1) {

		//T first=any_type1.get_type_data<T>();
		//T second = any_type2.get_type_data<T>();
		//AnyType buf = first;
		AnyType buf;
		*buf.type_data = *any_type1.type_data; //TODO this
		buf.type_name = any_type1.type_name;
		///AnyType buf();
		*any_type1.type_data = *(this->type_data);
		any_type1.type_name = (this->type_name);
		*type_data = *(buf.type_data);
		type_name = buf.type_name;
		//any_type2;
		//any_type2 = buf;*/
	}

	// overload operators

	~AnyType() {
		delete type_data;
	}

};





int main() {

	AnyType any_type = 2;
	any_type.show();
	any_type = true;
	any_type.show();
	any_type = 4.7; 
	any_type.show();
	any_type = 6.7f;
	any_type.show();
	int storedValue;
	try {  
		storedValue = any_type.ToInt();
		cout <<"here"<< storedValue << endl;
	}
	catch (Exception& e) { 
		cout<<e.what()<<'\n';/*Bad cast exception*/ 
	}
	any_type = 900;
	any_type.show();
	char storedValue_ch;
	try
	{
		storedValue_ch = any_type.ToChar();	
		cout << storedValue_ch << endl;
	}
	catch (Exception& e)
	{
		cout << e.what()<<'\n';
	}
	
	AnyType any_type_swap = 2.9;
	cout << "before swap:\n";
	any_type.show();
	any_type_swap.show();
	any_type.swap_s(any_type_swap);
	cout << "after swap:\n";
	any_type.show();
	any_type_swap.show();

	any_type = false;
	double storedValue_double;
	try
	{
		storedValue_double = any_type.ToDouble();
		cout << storedValue_double << endl;
	}
	catch (Exception& e)
	{
		cout << e.what() << '\n';
	}
	cout<<any_type.get_type_name()<<'\n';

	system("pause");
	return 0;
}
