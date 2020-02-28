// AnyType.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AnyType.h"

int main()
{
    AnyType anyType = 0.56;

    try
    {
        cout << anyType.GetType() << "\t :" << anyType.ToDouble() << endl;
    }
    catch (const std::exception & ex)
    {
        cout << ex.what();
    }

    anyType = 5;
    cout << anyType.GetType() << "\t :" << anyType.ToDouble() << endl;

    anyType = true;
    cout << anyType.GetType() << "\t :" << anyType.ToChar() << endl;

    anyType = 'h';
    cout << anyType.GetType() << "\t :" << anyType.ToDouble() << endl;

    try
    {
        cout << anyType.GetType() << "\t  :" << anyType.ToInt() << endl;
    }
    catch (const std::exception& ex)
    {
        cout << ex.what() << '\n';
    }

    AnyType b;
    swap(anyType, b);

    try
    {
        cout << b.GetType() << "\t :" << b.ToChar();
    }
    catch (const std::exception& ex)
    {
        cout << ex.what();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
