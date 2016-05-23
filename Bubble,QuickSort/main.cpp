#include"MySort.h"
#include<iostream>
using namespace std;

void main()
{
	MySort s;

	int arr[5] = { 2,4,1,6,3 };
	s.QuickSort(arr, 0, 4);
	
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int arr2[] = { 2,4,5,6,7,1,2,4,5,2,6,1 };
	s.BubbleSort(arr2, sizeof(arr2)/sizeof(int));
	for (int i = 0; i < sizeof(arr2) / sizeof(int); ++i)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
}