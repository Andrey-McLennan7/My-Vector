#pragma once
#include <iostream>

//template <typename T>

class TArray
{
private:
	int size;
	int* arr;
	int upperBound;
	int grow;
public:
	TArray();
	TArray(int);
	TArray(const TArray&);
	~TArray();

	TArray& operator=(const TArray&);

	int GetSize();
	void SetSize(int size, int grow = 1);
	int GetUpperBound();
	bool IsEmpty();
	void FreeExtra();
	void RemoveAll();
	int GetAt(int);
	void SetAt(int, int);
	int& operator[](int);
	void Add(int);
	void Append(const TArray&);
	int* GetData();
	void InsertAt(int, int);
	void InsertAt(int, int*, int count = 1);
	void RemoveAt(int, int count = 1);
};