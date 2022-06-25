#include "iostream";
#include "memory.h";

using namespace std;

// Explicit pointers (can be used with &targetedVar too on function call)
void division(int a, int b, int *res, int *rest) {
    *res = a / b;
    *rest = a % b;
}

// Reference
void division2(int a, int b, int &res, int &rest) {
    res = a / b;
    rest = a % b;
}

int main() {
    // Basic syntax
    int value = 32;
    int *ptr_value = &value;
    if (ptr_value != nullptr) {
        cout << "Value of targeted variable : " << *ptr_value << " or " << value << endl;
        cout << "Address of targeted variable : " << ptr_value << " or " << &value << endl;
    }
    cout << endl;

    // Function args by reference (allow direct update of source args)
    int a = 5;
    int b = 2;
    int res = 0;
    int rest = 0;
    int *ptr_res = &res;
    int *ptr_rest = &rest;

    // Explicit pointers as argument
    division(a, b, ptr_res, ptr_rest);

    cout << a << " / " << b << " division() :" << endl;
    cout << "res = " << res << endl;
    cout << "rest = " << rest << endl;
    cout << endl;
    
    // Without explicit pointer (direct REFERENCE to targetedVar --> syntaxic sugar)
    a = 10;
    b = 4;
    division2(a, b, res, rest);

    cout << a << " / " << b << " division2() :" << endl;
    cout << "res = " << res << endl;
    cout << "rest = " << rest << endl;

    // ADVANCED (smart pointers)
    // UNIQUE_PTR
    auto uPtr = make_unique<int>(new int(5));
    
}
