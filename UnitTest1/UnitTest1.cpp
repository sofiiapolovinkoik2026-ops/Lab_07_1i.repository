#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_1interative/Lab_07_1interative.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest711
{
    TEST_CLASS(UnitTest711)
    {
    public:
        TEST_METHOD(TestCalcIterative)
        {
            const int rows = 3;
            const int cols = 3;
            int** a = new int* [rows];
            for (int i = 0; i < rows; i++)
                a[i] = new int[cols];

            // Підходять під критерій (парне число + парні індекси [0][0], [0][2], [2][0], [2][2]):
            // a[0][0] = 4 (підходить)
            // a[0][1] = 6 (ні, j=1 непарний)
            // a[0][2] = 5 (ні, непарне число)
            // a[2][2] = 10 (підходить)
            a[0][0] = 4;  a[0][1] = 6;  a[0][2] = 5;
            a[1][0] = 8;  a[1][1] = 2;  a[1][2] = 12;
            a[2][0] = 7;  a[2][1] = 14; a[2][2] = 10;

            int S = 0, k = 0;
            Calc(a, rows, cols, S, k);

            Assert::AreEqual(14, S); // 4 + 10 = 14
            Assert::AreEqual(2, k);  // 2 елементи
            Assert::AreEqual(0, a[0][0]); // замінено на 0
            Assert::AreEqual(0, a[2][2]); // замінено на 0

            for (int i = 0; i < rows; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}