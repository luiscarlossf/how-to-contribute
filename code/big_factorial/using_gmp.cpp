#include <iostream>
#include <gmpxx.h>

int main()
{
	int num_i;
	std::cout << "Enter an arbitrary number: ";
	std::cin >> num_i;

	mpz_class fact( "1" );
	mpz_class num( num_i );
	while( num > 1 ) {
		fact *= num;
		num -= 1;
	}
	std::cout << "Factorial: " << fact << "\n";
	return 0;
}
