#include <iostream>

using namespace std;

class TempClass {
    public:
        TempClass () {
            cout << "TempClass constructor \n";
        }

        TempClass& operator= (const TempClass& tempClass) {
            cout << "tempClass = operator \n";
            return *this;
        }

        TempClass (const TempClass& tempClass) {
            cout << "tempClass copy constructor \n";
        }

        ~TempClass() {
            cout << "TempClass destructor \n";
        }
};

class ParentTest {
    public:
        ParentTest() {
            cout << "parent constructor \n";
        }

        ~ParentTest() {
            cout << "parent destructor! \n";
        }
};

class TestClass : public ParentTest {
    public:
        TestClass() {
            // default constuctor.
            cout << "default! \n";
        }

        // TestClass(int a, TempClass temp) {
        //     // parameterized constructor - member assigment;
        //     cout << "parameterized constuctor member assigment \n";
        //     a = a;
        //     temp = temp;
        // }

        TestClass(int val, TempClass temp) : temp(temp) , a(val) {
            // parameterized constructor - initializer lists;
            cout << "parameterized constructor - initializer lists; \n";
        }

        ~TestClass() {
            cout << "destructor! \n";
        }

    private:
        TempClass temp;
        int a;
};


int main() {
    TempClass tempClass;
    TestClass testClass1(1, tempClass);
}