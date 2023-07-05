#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

class String {
    public:
        String() = default;
        String(const char* p) {
            cout << "String constructor\n";
            size = std::strlen(p);
            data = new char[size];
            std::memcpy(data, p, size);
        }

        ~String() {
            cout << "destructor\n";
            delete data;
        }

        String(const String& that) {
            cout << "copy constructor\n";
            size = std::strlen(that.data);
            data = new char[size];
            std::memcpy(data, that.data, size);
        }

        String(String&& that) {
            cout << "move constructor\n";
            data = that.data;   // stole the pointer
            size = that.size;
            that.data = nullptr;    // release the original storage the pointer.
            that.size = 0;
        }

        String& operator=(String& that) {
            cout << "assignment operator\n";
            delete[] data; // remove ourselves data to avoid mem leak.
            size = that.size;
            data = that.data;
        }

        String& operator=(String&& that) {
            cout << "move assignment operator\n";
            if (this != &that) {    // no move itself.
                delete[] data; // remove ourselves data to avoid mem leak.
                size = that.size;
                data = that.data;

                that.data = nullptr;    // release the original storage the pointer.
                that.size = 0;
            }

            return *this;
            
        }

        void print() {
            for (int32_t i = 0; i < size; i++) {
                cout << data[i];
            }
            cout << "\n";
        }

        private:
            char* data;
            int32_t size;
};

class Entity {
    public: 
        Entity(const String& name) : name(name) {
            cout << "entity constructor\n";
        }

        Entity(String&& name) : name(std::move(name)) {
            cout << "entity move constructor \n";
        }

        void printName() {
            name.print();
        }

    private:
        String name;
};

int main() {
    {
        /**
         * the following ops are done. 
         * 1. String constructor; - create object with data Ttest
         * 2. String copy constructor; - Entity member initialization list constructor copies String.
         * 3. Entity constructor body. 
        */
        Entity entity("Ttest"); 
        entity.printName();
        // Since Ttest is a temporary but we actually allocate memory twice (once in String constructor and copy constructor), why do we even need the copy?
        // Move come into play!!!!
    }
    cout << "----\n";
    {
        /**
         * move constructor is used as similar to copy constructor(deal with lvalue - copy lvalue to a new object), 
         * move constructor is used when we copy a rvalue to a new object.
        */
        String string = "hello";
        String dest = std::move(string); 
        string.print();
        dest.print();
    }
    cout << "----\n";
    {
        /**
         * move assignment operator is similar as copy assignment operator.
         * copy assignment operator deals with the assigning the lvalue object to an existing object.
         * move assignment operator deals with the assigning the rvalue to an existing object.
        */
       String string = "hello2";
       String dest = "hello3";
       dest = std::move(string);
       string.print();
       dest.print();
    }
}