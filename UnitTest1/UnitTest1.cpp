#include "pch.h"
#include "CppUnitTest.h"
#include "..\Truth\Truth.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(CheckFImpl)
		{
			bool p = 1, q = 0, r = 1;
			Truth truth = Truth(p, q, r);
			Assert::AreEqual((int)truth.getFirstImplication(), 0);
		}
		TEST_METHOD(CheckFImplErr)
		{
			bool p = 1, q = 0, r = 1;
			Truth truth = Truth(p, q, r);
			Assert::AreEqual((int)truth.getFirstImplication(), 1);
		}
		TEST_METHOD(CheckSImpl)
		{
			bool p = 1, q = 0, r = 1;
			Truth truth = Truth(p, q, r);
			Assert::AreEqual((int)truth.getSecondImplication(), 1);
		}
		TEST_METHOD(CheckImpDisjunction)
		{
			bool p = 1, q = 0, r = 1;
			Truth truth = Truth(p, q, r);
			Assert::AreEqual((int)truth.getImplicationsDisjunction(), 1);
		}
	};
}
