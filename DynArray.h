#pragma once
#include<iostream>

namespace N {
	class DynArray {
	public:
		int n;
		int *arr;
		int capacity = 0;
	public:
		DynArray();
		DynArray(int size);
		DynArray(int size, int n);
		DynArray(const DynArray &s);
		//DynArray(DynArray & s)noexcept;
		~DynArray();

		int& operator[](const int index);

		void setI(int i, int value);
		int getI(int i);
		int getLength();
		void resise(int newSize);
		DynArray& operator=(const DynArray dar);
		friend bool operator==( DynArray &ar1,  DynArray &ar2);
		friend bool operator!=(const DynArray &ar1, const DynArray &ar2);
		friend bool operator> ( DynArray &d1, DynArray &d2);
		friend bool operator<= (DynArray &d1, DynArray &d2);

		friend bool operator< ( DynArray &d1,  DynArray &d2);
		friend bool operator>= ( DynArray &d1, DynArray &d2);
		friend DynArray operator+(DynArray &d1, DynArray &d2);
		friend std::ostream& operator<< (std::ostream &out, DynArray &arr);
		friend std::istream& operator>> (std::istream &in, DynArray &point);
	};
}