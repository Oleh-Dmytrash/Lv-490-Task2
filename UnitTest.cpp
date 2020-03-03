#include "pch.h"
#include "CppUnitTest.h"
#include "../boost_run/AnyType.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{


	public:

		TEST_METHOD(Constructors)
		{
			AnyType temp;
			Assert::IsTrue(temp.getType() == "empty");
			AnyType temp1(23.22);
			Assert::IsTrue(temp1.getValue() == 23.22);
			AnyType temp2(true);
			Assert::IsTrue(temp2.getValue() == 1);
			AnyType temp3('a');
			Assert::IsTrue(temp3.getValue() == 'a');
			AnyType temp4(1234);
			Assert::IsTrue(temp4.getValue() == 1234);
			AnyType temp5(temp4);
			Assert::IsTrue(temp5.getValue() == 1234);
		}

		TEST_METHOD(AssigmentOperators)
		{
			AnyType temp;
			temp = 123;
			Assert::IsTrue(temp.getValue() == 123);
			temp = 'a';
			Assert::IsTrue(temp.getValue() == 'a');
			temp = 23.433;
			Assert::IsTrue(temp.getValue() == 23.433);
		}
		TEST_METHOD(GetType)
		{
			AnyType temp;
			Assert::IsTrue(temp.getType() == "empty");
			temp = false;
			Assert::IsTrue(temp.getType() == "bool");
			temp = 2;
			Assert::IsTrue(temp.getType() == "int");
			temp = 'a';
			Assert::IsTrue(temp.getType() == "char");
			temp = 43.233;
			Assert::IsTrue(temp.getType() == "double");
		}
		TEST_METHOD(Swap)
		{
			AnyType temp = true, temp1 = 34.999;
			Assert::IsTrue(temp.getType() == "bool");
			Assert::IsTrue(temp1.getType() == "double");
			temp.swap(temp1);
			Assert::IsTrue(temp1.getType() == "bool");
			Assert::IsTrue(temp.getType() == "double");
		}
		TEST_METHOD(ToType)
		{
			AnyType temp = true;
			Assert::IsTrue(temp.toType<int>() == 1);
			temp = 122444;
			Assert::IsTrue(temp.toType<double>() == 122444);
			try
			{
				temp.toType<char>();
			}
			catch (...)
			{
				Assert::IsTrue(temp.toType<int>() == 122444);
			}



		}

	};
}
