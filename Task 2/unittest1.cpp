#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\Dell\source\repos\Task2\Task2\AnyType.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AnyTypeUnitTests
{
	TEST_CLASS(AnyTypeTest)
	{
	public:

		TEST_METHOD(Constructor)
		{
			AnyType a(false);
			AnyType b('l');
			AnyType c(10LL);
			AnyType d(2.5);

			Assert::IsTrue(a.GetType() == "bool" &&
				b.GetType() == "char" &&
				c.GetType() == "__int64" &&
				d.GetType() == "double");
		}
		TEST_METHOD(CopyCtor)
		{
			AnyType a(10123LL);
			AnyType b(a);
			b = 98123986LL;
			Assert::IsTrue(a.ToLongLong() == 10123LL && b.ToLongLong() == 98123986LL);
		}

		TEST_METHOD(AssigOperTest)
		{
			AnyType a = 31LL;
			a = 32LL;
			Assert::IsTrue(a.ToLongLong() == 32LL,L"why???");
		}		

		TEST_METHOD(SwapTest)
		{
			AnyType a = 31LL;
			AnyType b = 'l';
			a.swap_type(b);
			Assert::IsTrue(a.GetType() == "char" && b.GetType() == "__int64" &&
				a.ToChar() == 'l' && b.ToLongLong() == 31LL);
		}

		TEST_METHOD(ToBoolValid)
		{
			AnyType a = true;
			Assert::IsTrue(a.ToBool() == true);
		}

		TEST_METHOD(ToBoolInvalid)
		{
			AnyType a = 31;
			try
			{
				a.ToBool();
				Assert::Fail(L"must throw std::runtime_error");
			}
			catch (...)
			{

			}
		}

		TEST_METHOD(ToCharValid)
		{
			AnyType a = 'l';
			Assert::IsTrue(a.ToChar() == 'l');
		}

		TEST_METHOD(ToCharInvalid)
		{
			AnyType t = 22;
			try
			{
				t.ToChar();
				Assert::Fail(L"must throw std::runtime_error");
			}
			catch (...)
			{

			}
		}

		TEST_METHOD(ToLongLongValid)
		{
			AnyType a = 1000LL;
			Assert::IsTrue(a.ToLongLong() == 1000LL);
		}

		TEST_METHOD(ToLongLongInvalid)
		{
			AnyType a = 2.5;
			try
			{
				a.ToLongLong();
				Assert::Fail(L"must throw std::runtime_error");
			}
			catch (...)
			{

			}
		}

		TEST_METHOD(ToDoubleValid)
		{
			AnyType a = 10.0;
			Assert::IsTrue(a.ToDouble() == 10.0);
		}
		TEST_METHOD(ToDoubleInvalid)
		{
			AnyType t = 22.5f;
			try
			{
				t.ToDouble();
				Assert::Fail(L"must throw std::runtime_error");
			}
			catch (...)
			{

			}
		}

	};
}