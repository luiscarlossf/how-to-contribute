#include <iostream>
#include <vector>

void multiplyarraywith(std::vector<int> &arr, int num)
{
	int mult = 0;
	int len = ( int )arr.size();

	for( int i = 0; i < len; ++i ) {
		mult = mult + arr[i] * num;
		arr[ i ] = mult % 10 ;
		mult /= 10;
	}
	while( mult > 0 ) {
		arr.push_back( mult % 10 );
		mult /= 10;
	}
}

int main()
{
	std::cout << "Calculate factorial of: ";
	int num;
	std::cin >> num;

	std::vector<int> arr = { 1 };

	for( int i = 2; i <= num; ++i )
		multiplyarraywith( arr, i );

	for( auto it = arr.rbegin(); it != arr.rend(); it++ )
		std::cout << * it;

	std::cout << "\n";
	return 0;
}
