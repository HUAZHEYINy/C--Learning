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

    myTest(const myTest &old) {
        cout << "Copy constructor is called" << endl;
    }

    // myTest(const myTest &) = delete;
    // This will create compilation error!

};

int main()
{
    myTest a;
    myTest b = a;
    return 0;
}
