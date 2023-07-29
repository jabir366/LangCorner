#include <iostream>
#include <set>

struct MyStruct {
    int value;

    MyStruct(int v) : value(v) {}
};

struct CompareStructPointers {
    bool operator()(const MyStruct* lhs, const MyStruct* rhs) const {
        return lhs->value < rhs->value;
    }
};

int main() {
    /* std::set<MyStruct*, CompareStructPointers> mySet; */
    std::set<MyStruct*> mySet;

    MyStruct s1(10);
    MyStruct s2(20);
    MyStruct s3(30);

    mySet.insert(&s1);
    mySet.insert(&s2);
    mySet.insert(&s3);

    MyStruct searchKey(20);
    auto it = mySet.find(&searchKey);

    if (it != mySet.end()) {
        std::cout << "Element found: " << (*it)->value << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}
