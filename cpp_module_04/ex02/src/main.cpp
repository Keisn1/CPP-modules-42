#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include <iostream>

#define DEEPSKYBLUE "\033[38;2;0;191;255m"
#define RESET "\033[0m"

int main() {
  {

    Brain b;
    b.printIdeas(5);
  }
  {
    std::cout << DEEPSKYBLUE << "Test default constructor" << RESET
              << std::endl;
    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();

    delete j;
    delete i;
  }

  {
    std::cout << DEEPSKYBLUE << "Test copy-constructor with pointer" << RESET
              << std::endl;
    const Cat *c1 = new Cat();
    const Cat *c2 = new Cat(*c1);

    delete c1;
    delete c2;
  }

  {
    std::cout << DEEPSKYBLUE << "Test copy-constructor with pointer 2" << RESET
              << std::endl;
    const Dog *d1 = new Dog();
    const Dog *d2 = new Dog(*d1);

    delete d1;
    delete d2;
  }

  {
    std::cout << DEEPSKYBLUE << "Test copy-assignment operator" << RESET
              << std::endl;
    const Dog *d1 = new Dog();
    Dog d2;
    d2 = *d1;

    delete d1;
  }

  // {
  // 	std::cout << DEEPSKYBLUE <<  "Test animals array" << RESET << std::endl;
  // 	AAnimal animals[10];
  // 	for (int i = 0; i < 5; i++)
  // 		animals[i] = Dog();
  // 	for (int i = 5; i < 10; i++)
  // 		animals[i] = Cat();
  // 	for (int i = 0; i < 10; i++) {
  // 		animals[i].printType();
  // 		animals[i].makeSound();
  // 	}
  // }

  {
    std::cout << DEEPSKYBLUE << "Test animals array with pointer" << RESET
              << std::endl;
    AAnimal *animals[10];
    for (int i = 0; i < 5; i++)
      animals[i] = new Dog();
    for (int i = 5; i < 10; i++)
      animals[i] = new Cat();
    for (int i = 0; i < 10; i++) {
      animals[i]->printType();
      animals[i]->makeSound();
    }

    for (int i = 0; i < 10; i++)
      delete animals[i];
  }
  {
    std::cout << DEEPSKYBLUE << "Test deep copy" << RESET << std::endl;
    Dog basic;
    std::cout << DEEPSKYBLUE << "Before basic" << RESET << std::endl;
    {
      Dog tmp = basic;
    }
    std::cout << DEEPSKYBLUE << "After basic" << RESET << std::endl;
  }
  {
    std::cout << DEEPSKYBLUE << "Test deep copy with copy-assignment" << RESET
              << std::endl;
    Dog basic;
    std::cout << DEEPSKYBLUE << "Before basic" << RESET << std::endl;
    {
      Dog tmp;
      tmp = basic;
    }
    std::cout << DEEPSKYBLUE << "After basic" << RESET << std::endl;
  }
  // {
  // 	AAnimal test;
  // }
  return 0;
}
