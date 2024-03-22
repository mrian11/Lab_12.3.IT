#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.3/LAB.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab123
{
	TEST_CLASS(UnitTestLab123)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			Elem* first = nullptr;
			Elem* last = nullptr;

			enqueue(first, last, 1);
			enqueue(first, last, 2);
			enqueue(first, last, 3);

			insertBeforeLast(first, last, 3, 4); // Вставляємо перед останнім елементом зі значенням 3

			Assert::AreEqual(last->prev->info, 4);
		}
	};
}
