#include <iostream>

using namespace std;

int main()
{
    int arr[7] = {4, 5, 3, 2, 7, 1, 6};
    int arrSize = sizeof(arr) / sizeof arr[0];

    for(int i  = 0; i < arrSize - 1; i++)
    {
        int indexOfSmallestElement = i;

        for(int j = i + 1; j < arrSize; j++)
        {
            if(arr[j] < arr[indexOfSmallestElement])
            {
                indexOfSmallestElement = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[indexOfSmallestElement];
        arr[indexOfSmallestElement] = temp;
    }

    for(int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}