#include "Dog.h"
#include "Cat.h"


int main() {
	Brain b;
	b.printIdeas(5);

	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;
		delete i;
	}

	{
		const Cat* c1= new Cat();
		const Cat* c2= new Cat(*c1);

		delete c1;
		delete c2;
	}

	{
		const Dog* d1 = new Dog();
		const Dog* d2 = new Dog(*d1);

		delete d1;
		delete d2;
	}

	{
		const Dog* d1 = new Dog();
		Dog d2;
		d2 = *d1;

		delete d1;
	}

	{
		Animal animals[10];
		for (int i = 0; i < 5; i++)
			animals[i] = Dog();
		for (int i = 5; i < 10; i++)
			animals[i] = Cat();
		for (int i = 0; i < 10; i++) {
			animals[i].printType();
			animals[i].makeSound();
		}
	}

	{
		Animal* animals[10];
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
	return 0;
}
