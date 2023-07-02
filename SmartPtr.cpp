#include <iostream>
#include <memory>

using namespace std;

class Object {
    public:
        Object() {
            a = 999;
            cout << "default constructor" << endl;
        }
        Object(int a) : a(a) {
            cout << "one argument constructor" << endl;
        }
        ~Object() {
            cout << "destructor\n";
        }

        int getA() {
            return a;
        }
    private:
        int a;
};

int main() {
    string temp;
    cout << "start\n";
    
    // {
    //     Object * ptr = new Object();
    //     delete ptr;
    // }

    // {
    //     std::unique_ptr<Object> smartPtr = std::make_unique<Object>();
    //     std::unique_ptr<Object> smartPtr2 = std::move(smartPtr);
    //     // cout << "smartPtr points to " << smartPtr->getA() << endl; - Segmentation fault
    //     cout << "smartPtr2 points to " << smartPtr2->getA() << endl;
    // }

    {
        std::shared_ptr<Object> sharedPtr = std::make_shared<Object>();
        cout << "use count " << sharedPtr.use_count() << endl;
        cout << "sharedPtr points to " << sharedPtr->getA() << endl;
        auto sharedPtr2 = sharedPtr;
        cout << "use count after sharedPtr2 " << sharedPtr.use_count() << endl;
        cout << "sharedPtr2 points to " << sharedPtr2->getA() << endl;
        auto sharedPtr3 = std::move(sharedPtr);
        cout << "use count after sharedPtr3 " << sharedPtr.use_count() << endl; 
        cout << "use count after sharedPtr3 " << sharedPtr3.use_count() << endl; 
        cout << "use count after sharedPtr3 " << sharedPtr2.use_count() << endl; 
        // cout << "sharedPtr points to " << sharedPtr->getA() << endl; - Segmentation fault
        cout << "sharedPtr3 points to " << sharedPtr3->getA() << endl;
        cout << "sharedPtr2 points to " << sharedPtr2->getA() << endl;
    }
    
    cin >> temp;
    cout << "end \n";
}