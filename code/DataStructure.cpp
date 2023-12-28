#include <vector>
#include <iostream>
#include <array>
#include <cassert>

using namespace std;


void testArray() {
    array<int, 4> a = {1, 2, 3};
    assert(a.at(1) == 2);
    assert(a[0] == 1);
    assert(a.front() == 1);
    assert(a.back() != 3);
    assert(a.max_size() == 4);

    a.fill(5);
    assert(a.front() == 5);
    assert(a.back() == 5);
    assert(a.size() == 4);

    array<int, 4> b;
    b.fill(6);
    a.swap(b);
    assert(a.front() == 6);
    assert(a.back() == 6);
    assert(a.size() == 4);
    assert(b.front() == 5);
    assert(b.back() == 5);
    assert(b.size() == 4);
}

void testVector() {
    vector<int> a;
    for (int i = 0; i < 6; i++) {
        a.push_back(i);
    }
    auto it = a.begin();
    it++;
    a.insert(it, 8, 9);
    for (const auto& ele : a) {
        cout << ele << endl;
    }
}

int main() {

    testVector();
}