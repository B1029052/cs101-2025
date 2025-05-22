#include <iostream>
using namespace std;

// 基底類別 Animal
class Animal {
public:
    virtual void eat() {
        cout << "I am animal and I eat food" << endl;
    }
    virtual ~Animal() {} // 虛擬解構子
};

// 派生類別 Dog
class Dog : public Animal {
public:
    void eat() override {
        cout << "I am dog and I eat meat" << endl;
    }
};

// 派生類別 Cat
class Cat : public Animal {
public:
    void eat() override {
        cout << "I am cat and I eat fish" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->eat(); // 執行 Dog 的 eat()
    a2->eat(); // 執行 Cat 的 eat()

    delete a1;
    delete a2;

    return 0;
}
