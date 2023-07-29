#include <iostream>
#include <tuple>
/*
Example that illustrate the use of structured binding in 

- introduced in c++17
- allows you to declare and initialize multiple variables froma a single
  expression or object
- it can be used with wide variety of data strucrued, such as pair, tuple ,struc etc

eg ; auto [var1,var2, ...] = expression;
*/

struct Person {
    std::string name;
    int age;
};

int main() {
    Person person{ "John Doe", 30 };

    auto [name, age] = person;
    std::cout << "Example used in struct ===============" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;

    std::cout << "Example used in tuple ===============" << std::endl;
    std::tuple<int, std::string, double> myTuple(42, "Hello", 3.14);
    auto [num, str, value] = myTuple;
    std::cout << num << ", " << str << ", " << value << std::endl;
   
    std::cout << "Example used in pair ===============" << std::endl;
    std::pair<int, int> myPair(2,4);
    std::pair<int, int> myPair2;
	auto [n1,n2] = myPair;

    myPair2 = std::make_pair(5,6);
    
    std::cout << n1 << ", " << str << ", " << n2 << std::endl;
    return 0;
}
