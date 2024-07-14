#include "clsTArray.h"
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	srand(time(NULL));

	TArray arr, arr1;

	arr.Add(1);
	arr.Add(2);
	arr.Add(3);
	arr.Add(4);

	arr1.Add(1);
	arr1.Add(2);
	arr1.Add(3);

	for (int i = 0; i <= arr.GetUpperBound(); i++)
		cout << arr[i] << '\t';
	cout << endl << endl;

	for (int i = 0; i <= arr1.GetUpperBound(); i++)
		cout << arr1[i] << '\t';
	cout << endl << endl;

	arr.Append(arr1);

	for (int i = 0; i <= arr.GetUpperBound(); i++)
		cout << arr[i] << '\t';
	cout << endl << endl;

	arr.SetSize(10);

	for (int i = 0; i < arr.GetSize(); i++)
		arr[i] = rand() % 9 + 1;

	int* p;

	p = arr.GetData();

	for (int i = 0; i < arr.GetSize(); i++)
		cout << p[i] << '\t';
	cout << endl;

	cout << endl << p << endl;
	cout << arr.GetData() << endl;

	arr.RemoveAll();

	return 0;
}