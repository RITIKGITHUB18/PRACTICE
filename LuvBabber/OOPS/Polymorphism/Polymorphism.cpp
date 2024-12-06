#include <bits/stdc++.h>
using namespace std;

// without virtual early binding, static binding
// with virtual late binding, dynamic binding

class Animal
{
public:
    // virtual
    virtual void makeSound()
    {
        std::cout << "Animal makes a sound" << std::endl;
    }

    virtual ~Animal()
    {
        cout << "~Animal Dtor" << endl;
    }
};

class Dog : public Animal
{
public:
    // here writing the override increases the readability nothing more then this
    void makeSound() override
    {
        std::cout << "Dog barks" << std::endl;
    }

    ~Dog()
    {
        cout << "~Dog Dtor" << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        std::cout << "Cat meows" << std::endl;
    }

    ~Cat()
    {
        cout << "~Cat Dtor" << endl;
    }
};

// let's call a function for making the sound
void sound(Animal *animal)
{
    animal->makeSound(); // Polymorphic
    // animal->makeSound is behaving as per required object allcated at runtime
}

int main()
{
    // Animal *animalPtr;
    // Dog dogObj;
    // Cat catObj;

    // animalPtr = &dogObj;
    // sound(animalPtr);
    // animalPtr = &catObj;
    // sound(animalPtr);
    // animalPtr->makeSound(); // Output: "Dog barks"

    // animalPtr = &catObj;
    // animalPtr->makeSound(); // Output: "Cat meows"

    // ! dynamic allocation of memory in heap
    string type;
    cin >> type;
    Animal *animalPtr;
    if (type == "Dog")
    {
        animalPtr = new Dog();
    }
    else if (type == "Cat")
    {
        animalPtr = new Cat();
    }
    sound(animalPtr);
    delete animalPtr;
    return 0;
}
