#include "Serializer.hpp"

int main()
{
	Data *old;
	Data *current;

	old = new Data;
	old->num = 42;
	uintptr_t t;
	std::cout << old << std::endl;
	t = Serializer::serialize(old);
	std::cout << t << std::endl;
	current = Serializer::deserialize(t);
	std::cout << current << std::endl;
	std::cout << current->num << std::endl;
	delete old;
}