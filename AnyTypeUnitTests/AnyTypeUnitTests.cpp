#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/src/AnyType.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AnyTypeUnitTests
{
	TEST_CLASS(AnyTypeUnitTests)
	{
	public:
		
		TEST_METHOD(CtorTest)
		{
			AnyType t1(1);
			AnyType t2(true);
			AnyType t3('k');
			AnyType t4(2.5);

			Assert::IsTrue(t1.Type() == "int" &&
				t2.Type() == "bool" &&
				t3.Type() == "char" &&
				t4.Type() == "double", L"The types of elements must coincide types in the constructors");
		}
		TEST_METHOD(CopyCtorTest)
		{
			AnyType t1(1);
			AnyType t2(t1);
			t2 = 22;
			Assert::IsTrue(t2.ToInt() == 22 && t1.ToInt() == 1, 
				L"The copy ctor must create new copy of the element, not point to the same one");
		}
		
		TEST_METHOD(AssignmentOperatorTest)
		{
			AnyType t1 = 22;
			Assert::IsTrue(t1.ToInt() == 22, L"t1 must be 22");
		}

		TEST_METHOD(AssignmentCopyOperatorTest)
		{
			AnyType t1 = 22;
			AnyType t2 = t1;
			Assert::IsTrue(t2.ToInt() == 22, L"t2 must be 22");
		}

		TEST_METHOD(SwapTest)
		{
			AnyType t1 = 22;
			AnyType t2 = 'O';
			t1.Swap(t2);
			Assert::IsTrue(t1.Type() == "char" && t2.Type() == "int" &&
				t1.ToChar() == 'O' && t2.ToInt() == 22,
				L"Types and values of t1 and t2 must be swapped");
		}

		TEST_METHOD(ToBoolPositiveTest)
		{
			AnyType t = true;
			Assert::IsTrue(t.ToBool() == true, L"t.ToBool() must return true");
		}
		
		TEST_METHOD(ToBoolNegativeTest)
		{
			AnyType t = 22;
			try
			{
				t.ToBool();
				Assert::Fail(L"t.ToBool() must throw std::runtime_error");
			}
			catch(...)
			{
				
			}
		}
		
		TEST_METHOD(ToCharPositiveTest)
		{
			AnyType t = 'c';
			Assert::IsTrue(t.ToChar() == 'c', L"t.ToChar() must return \'c\'");
		}
		
		TEST_METHOD(ToCharNegativeTest)
		{
			AnyType t = 22;
			try
			{
				t.ToChar();
				Assert::Fail(L"t.ToChar() must throw std::runtime_error");
			}
			catch (...)
			{

			}
		}
		
		TEST_METHOD(ToIntPositiveTest)
		{
			AnyType t = 1000;
			Assert::IsTrue(t.ToInt() == 1000, L"t.ToInt() must return 1000");
		}
		
		TEST_METHOD(ToIntNegativeTest)
		{
			AnyType t = 22.5;
			try
			{
				t.ToInt();
				Assert::Fail(L"t.ToInt() must throw std::runtime_error");
			}
			catch (...)
			{

			}
		}

		TEST_METHOD(ToFloatPositiveTest)
		{
			AnyType t = 1000.f;
			Assert::IsTrue(t.ToFloat() == 1000.f, L"t.ToFloat() must return 1000.f");
		}
		TEST_METHOD(ToFloatNegativeTest)
		{
			AnyType t = 22.5;
			try
			{
				t.ToFloat();
				
				Assert::Fail(L"t.ToFloat() must throw std::runtime_error");
			}
			catch (...)
			{

			}
		}

		TEST_METHOD(ToDoublePositiveTest)
		{
			AnyType t = 1000.0;
			Assert::IsTrue(t.ToDouble() == 1000.0, L"t.ToDouble() must return 1000.0");
		}
		
		
	};
}
