#include "pch.h"
#include "CppUnitTest.h"
#include "../AnyType/AnyType.h"
#include "../AnyType/AnyType.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AnyTypeUnitTest
{
	TEST_CLASS(AnyTypeUnitTest)
	{
	public:
		
		TEST_METHOD(InitTest1)
		{
			AnyType anyType(5);
			Assert::AreEqual(anyType.GetType(), std::string("int"), L"Should be int");
		}

		TEST_METHOD(InitTest2)
		{
			AnyType anyType(5);
			AnyType anyType1 = anyType;
			Assert::AreEqual(anyType1.GetType(), std::string("int"), L"Should be int");
		}

		TEST_METHOD(InitTest3)
		{
			AnyType anyType(5);
			AnyType anyType1(anyType);
			Assert::AreEqual(anyType1.GetType(), std::string("int"), L"Should be int");
		}

		TEST_METHOD(InitTest4)
		{
			AnyType anyType;
			anyType = '\0';
			Assert::AreEqual(anyType.GetType(), std::string("char"), L"Should be int");
		}

		TEST_METHOD(InitTest5)
		{
			AnyType anyType = 5.6254;			
			Assert::AreEqual(anyType.GetType(), std::string("double"), L"Should be int");
		}

		TEST_METHOD(InitTest6)
		{
			AnyType anyType = false;
			Assert::AreEqual(anyType.ToBool(), false, L"Should be int");
		}

		TEST_METHOD(GetTypeTest1)
		{
			AnyType anyType = 5;			
			Assert::AreEqual(anyType.GetType(), std::string("int"), L"Should be int");
		}

		TEST_METHOD(GetTypeTest2)
		{
			AnyType anyType = 5;
			Assert::AreEqual(anyType.GetType(), std::string("bool"), L"Negative test");
		}

		TEST_METHOD(SafeCastTest1)
		{
			AnyType anyType = 5;
			bool exception_is_generated = false;
			try
			{
				double val_lf = anyType.ToDouble();
			}
			catch (const std::exception& ex)
			{
				exception_is_generated = true;
			}			
			Assert::IsFalse(exception_is_generated, L"Should be true");
		}

		TEST_METHOD(SafeCastTest2)
		{
			AnyType anyType = 5;
			bool exception_is_generated = false;
			try
			{
				bool val_lf = anyType.ToBool();
			}
			catch (const std::exception & ex)
			{
				exception_is_generated = true;
			}
			Assert::IsTrue(exception_is_generated, L"Should be true");
		}

		TEST_METHOD(SafeCastTest3)
		{
			AnyType anyType = 5.5;
			bool exception_is_generated = false;
			try
			{
				double val_lf = anyType.ToBool();
			}
			catch (const std::exception & ex)
			{
				exception_is_generated = true;
			}
			Assert::IsFalse(exception_is_generated, L"Negative test");
		}

		TEST_METHOD(SafeCastTest4)
		{
			AnyType anyType = true;
			bool exception_is_generated = false;
			try
			{
				bool val_lf = anyType.ToBool();
			}
			catch (const std::exception & ex)
			{
				exception_is_generated = true;
			}
			Assert::IsFalse(exception_is_generated, L"Should be true");
		}

		TEST_METHOD(SafeCastTest5)
		{
			AnyType anyType = true;
			bool exception_is_generated = false;
			try
			{
				bool val_lf = anyType.ToInt();
			}
			catch (const std::exception & ex)
			{
				exception_is_generated = true;
			}
			Assert::IsFalse(exception_is_generated, L"Should be int");
		}

		TEST_METHOD(SwapTest1)
		{
			AnyType anyType(5);
			AnyType anyType1(true);
			anyType.swap(anyType1);
			Assert::IsTrue((anyType1.ToInt() == 5 && anyType.ToBool() == true), L"Should be true");
		}

		TEST_METHOD(SwapTest2)
		{
			AnyType anyType(5);
			AnyType anyType1(true);
			anyType.swap(anyType1);
			//must be exeption
			Assert::IsTrue((anyType1.ToInt() == 5 && anyType1.ToBool() == true), L"Negative test");
		}
	};
}
