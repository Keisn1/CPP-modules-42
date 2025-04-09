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
	return 0;
}
