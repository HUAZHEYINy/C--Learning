#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

class string {
    char* data;

    public:
        string(const char* p) {
            cout << "default constructor\n";
            size_t size = std::strlen(p) + 1;
            data = new char[size];
            std::memcpy(data, p, size);
        }

        ~string() {}

        string(const string& that) {
            cout << "copy constructor\n";
            size_t size = std::strlen(that.data) + 1;
            data = new char[size];
            std::memcpy(data, that.data, size);
        }

        // move constructor
        string(string&& that) {
            data = that.data;   // stole the pointer
            that.data = nullptr;    // release the original storage the pointer.
        }

        // 
};

int main() {
    char* charOne = "this is a string";

    // NOTE: 
    // charOne is lvalue;
    // deep copy is needed!
    ::string a (charOne);  

    // NOTE:
    // the input is rvalue so deep copy is not needed.
    // move is helping steal the data to avoid unnecessary copy.
    ::string b ("this is a string"); // "input is rvalue"
}