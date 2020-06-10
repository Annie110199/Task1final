#include"DynArray.h"

using namespace std;
using namespace N;

DynArray::DynArray() {
	n = 0;
	arr = new int[0];
	capacity = 0;
}

DynArray::DynArray(int SIZE) {
	n = SIZE;
	arr = new int[n];
	capacity = n;
	for (int i = 0; i < n; ++i) {
		arr[i] = 0;
	}
}

DynArray::DynArray(int SIZE, int num) {
	n = SIZE;
	arr = new int[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = num;
	}
	capacity = n;
}

DynArray::DynArray(const DynArray & s){
		n = s.n;
		arr = new int[n];
		for (int i = 0; i < n; ++i) {
			arr[i] = s.arr[i];
		}
		capacity = s.capacity;
}

//DynArray::DynArray(DynArray & s) noexcept
//{
//	arr = new int[s.capacity];
//	for (int i = 0; i < s.n; ++i) {
//		arr[i] = s.arr[i];
//	}
//	n = s.n;
//	capacity = s.capacity;
//}

DynArray::~DynArray() {
	delete[] arr;
}

void N::DynArray::setI(int i, int value)
{
	arr[i] = value;
}

int N::DynArray::getI(int i)
{
	return arr[i];
}

int DynArray::getLength()
{
	return this->n;
}
void DynArray::resise(int newSize)
{
	int *t = new int[newSize];
	for (int i = 0; i < n; ++i) {
		t[i] = arr[i];
	}
	for (int i = n; i < newSize; ++i) {
		t[i] = 0;
	}
	arr = t;
	capacity = newSize;
	n = newSize;
}

DynArray & N::DynArray::operator=(const DynArray dar)
{
	return *(new DynArray(dar));
}
int& DynArray::operator[] (const int index)
{
	return arr[index];
}

bool N::operator==(DynArray &ar1, DynArray &ar2)
{
	if (ar1.getLength() != (ar2).getLength())
		return false;
	for (int i = 0; i < (ar1).getLength(); i++)
	{
		if (ar1[i] != ar2[i]) {
			return false;
		}
	}
	return true;
}

bool N::operator!=(const DynArray & ar1, const DynArray & ar2)
{
	return !((&ar1) == (&ar2));
}

bool N::operator>(DynArray &d1, DynArray &d2)
{
	int min = d1.getLength();
	if (min > d2.getLength())
		min = d2.getLength();
	for (int i = 0; i < min; ++i) {
		if (d1[i] > d2[i])
			return true;
	}
	return false;
}

bool N::operator<=(DynArray & d1, DynArray & d2)
{
	return !(d1>d2);
}

bool N::operator<(DynArray & d1, DynArray & d2)
{
	return !(d1>=d2); 
}

bool N::operator>=(DynArray & d1, DynArray & d2)
{
	int min = d1.getLength();
	if (min > d2.getLength())
		min = d2.getLength();
	for (int i = 0; i < min; ++i) {
		if (d1[i] >= d2[i])
			return true;
	}
	return false;
}

DynArray N::operator+(DynArray  &d1, DynArray  &d2)
{
	DynArray *ans = new DynArray(d1.getLength() + d2.getLength());
	for (int i = 0; i < d1.getLength(); ++i) {
		(*ans)[i] = (d1)[i];
	}	for (int i = 0; i < d2.getLength(); ++i) {
		(*ans)[i+d1.getLength()] = (d2)[i];
	}
	return *ans;
}

std::ostream & N::operator<<(std::ostream & out, DynArray & arr)
{
	for (int i = 0; i < (arr).getLength(); ++i)
		out << (arr)[i] << " ";
	return out;
}

std::istream & N::operator>>(std::istream & in, DynArray & arr)
{
	int temp;
	in >> temp;
	arr.capacity = temp;
	arr.n = temp;
	int *a = new int[temp];
	for (int i = 0; i < arr.getLength(); ++i) {
		in >> (a)[i];
	}
	arr.arr = a;
	return in;
}


