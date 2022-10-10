#include <iostream>

using namespace std;

class myTest {
private:
    int val;
    std::string valStr;
    
public:
    ~myTest() {
        cout << "Destructor is called!" << endl;
    }
    
    myTest(int val) {
        cout << "Constructor int is called" << endl;
        this->val = val;
    }
    
    myTest() {
        cout << "Default constructor is called" << endl;
    }
// same as Constructor int.
//    myTest(int val) : val(val) {
//        cout << "Member list constructor is called" << endl;
//    }
    myTest(int val, std::string valStr) : val(val), valStr(valStr) {
        cout << "Member list constructor is called!" << endl;
    };
    
};

int main()
{
    myTest* a = new myTest(); // only constructor is called;
    myTest a1; // both constructor and destructor is called;
    // diff?
    // with new, it will return a pointer of the object and the object is created in heap; must use delete to call destructor.
    // without new, the object will be created in stack and the destructor will be called when it's out of scope.
    myTest a2(1); // constructor int is called.
    myTest a3(1, "string"); // member list constructor is called.
    return 0;
}
