#include <iostream>
#include <vector>
using namespace std;

int partition(vector <int> &arr, int l, int r)
{
	int pivot = arr[r];

	int i = (l - 1);

	for (int j = l; j <= r; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	return i;
}

void quick_sort(vector <int> &arr, int l, int r)
{
	if (l < r)
	{
		int p = partition(arr, l, r);

		quick_sort(arr, l, p - 1);
		quick_sort(arr, p + 1, r);
	}
}

int main()
{
	cout << "Enter number of elements: ";
	int n;	cin >> n;

	cout << "Array: ";
	vector <int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	quick_sort(arr, 0, n - 1);

	cout << "Sorted: ";

	for (auto u : arr)
		cout << u << " ";
	cout << "\n";

	return 0;
}