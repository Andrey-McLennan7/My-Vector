#include "clsTArray.h"

TArray::TArray() :TArray(0) {}

TArray::TArray(int size) : size(size), arr(nullptr), upperBound(-1), grow(1)
{
    if (this->size > 0)
        this->arr = new int[this->size];
    for (int i = 0; i < this->size; i++)
        this->arr[i] = 0;
}

TArray::TArray(const TArray& val) :size(val.size), upperBound(val.upperBound), grow(val.grow)
{
    if (this->size == 0)
        this->arr == nullptr;
    else
    {
        this->arr = new int[this->size];
        for (int i = 0; i < this->size; i++)
            this->arr[i] = val.arr[i];
    }
}

TArray::~TArray()
{
    delete[] this->arr;
}

TArray& TArray::operator=(const TArray& val)
{
    if (this == &val)
        return *this;

    delete[] this->arr;
    this->arr = nullptr;
    this->size = val.size;
    this->upperBound = val.upperBound;
    this->grow = val.grow;

    if (this->size > 0)
    {
        this->arr = new int[this->size];
        for (int i = 0; i < this->size; i++)
            this->arr[i] = val.arr[i];
    }

    return *this;
}

int TArray::GetSize()
{
    return this->size;
}

void TArray::SetSize(int size, int grow)
{
    if (size >= 0)
    {
        int* tmp = new int[size];

        for (int i = 0; i < this->size && i < size; i++)
            tmp[i] = this->arr[i];

        delete[] this->arr;
        this->arr = tmp;

        this->size = size;

        if (this->size <= this->upperBound)
            this->upperBound = this->size - 1;

        this->grow = grow;
    }
}

int TArray::GetUpperBound()
{
    return this->upperBound;
}

bool TArray::IsEmpty()
{
    if (this->upperBound < 0)
        return true;
    return false;
}

void TArray::FreeExtra()
{
    if (this->upperBound < this->size - 1)
        this->SetSize(this->upperBound + 1, this->grow);
}

void TArray::RemoveAll()
{
    delete[] this->arr;
    this->arr = nullptr;
    this->size = 0;
    this->upperBound = -1;
}

int TArray::GetAt(int index)
{
    return arr[index];
}

void TArray::SetAt(int index, int val)
{
    this->arr[index] = val;
}

int& TArray::operator[](int index)
{
    return this->arr[index];
}

void TArray::Add(int val)
{
    this->upperBound++;

    if (this->upperBound == this->size)
    {
        this->size += this->grow;
        int* tmp = new int[this->size];

        for (int i = 0; i < this->upperBound; i++)
            tmp[i] = this->arr[i];

        delete[] this->arr;
        this->arr = tmp;
    }

    this->arr[this->upperBound] = val;
}

void TArray::Append(const TArray& obj)
{
    if (obj.size > 0)
    {
        if (this->upperBound + obj.upperBound + 2 > this->size)
        {
            this->size = this->upperBound + obj.upperBound + 2;
            int* tmp = new int[this->size];

            for (int i = 0; i <= this->upperBound; i++)
                tmp[i] = this->arr[i];

            for (int i = 0; i <= obj.upperBound; i++)
                tmp[++this->upperBound] = obj.arr[i];

            delete[] this->arr;
            this->arr = tmp;
        }
        else
            for (int i = 0; i <= obj.upperBound; i++)
                this->arr[++this->upperBound] = obj.arr[i];
    }
}

int* TArray::GetData()
{
    return this->arr;
}

void TArray::InsertAt(int index, int val)
{
    if (index > this->upperBound)
        this->Add(val);
    else
    {
        this->upperBound++;

        if (this->upperBound == this->size)
        {
            this->size += this->grow;
            int* tmp = new int[this->size];

            for (int i = 0; i < index; i++)
                tmp[i] = this->arr[i];

            for (int i = index; i < this->upperBound; i++)
                tmp[i + 1] = this->arr[i];

            delete[] this->arr;
            this->arr = tmp;
        }
        else
            for (int i = upperBound; i > index; i--)
                this->arr[i] = this->arr[i - 1];

        this->arr[index] = val;
    }
}

void TArray::InsertAt(int index, int* insArr, int count)
{
    if (index > this->upperBound)
        for (int i = 0; i < count; i++)
            this->Add(arr[i]);
    else
    {
        this->upperBound += count;
        if (this->upperBound < size)
        {
            for (int i = this->upperBound; i >= index + count; i--)
                this->arr[i] = this->arr[i - count];

            for (int i = 0; i < count; i++)
                this->arr[index + i] = insArr[i];
        }
        else
        {
            int* tmp = new int[this->upperBound + 1];

            for (int i = 0; i < index; i++)
                tmp[i] = this->arr[i];

            for (int i = 0; i < count; i++)
                tmp[index + i] = insArr[i];

            for (int i = index; i < this->upperBound - count; i++)
                tmp[i + count] = this->arr[i];

            delete[] this->arr;
            this->arr = tmp;

            this->size += count;
        }
    }
}

void TArray::RemoveAt(int index, int count)
{
    if (index <= this->upperBound)
    {
        this->upperBound -= count;

        for (int i = index; i <= upperBound; i++)
            this->arr[i] = this->arr[i + count];
    }
}