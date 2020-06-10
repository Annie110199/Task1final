#include<iostream>
#include"DynArray.h"

using namespace std;
using namespace N;


int main() {
	DynArray *ar = new DynArray(5, 17);
	(*ar)[1] = 3;
	cout << ar->arr[1]<<" "<<(*ar)[4]<<endl;
	cout<<ar->getLength() << endl;
	DynArray *ar1 = new DynArray(5, 17);
	(*ar1)[1] = 3;
	cout << (*ar==*ar1)<<endl;
	DynArray *ar2 = new DynArray(10);
	cout << (*ar1>*ar2)<<endl;
	cout << (*ar <= *ar1) << endl;
	cout << (*ar1 < *ar2) << endl;
	cout << *ar1;

	DynArray ar3;
	cin >> ar3;
	cout << ar3 << endl;

	DynArray ar4 = (*ar1)+(*ar2);
	cout << ar4;
	return 0;
}