// Print the list contents.
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void Print(const T& ds)
{
	// Typedef for the iterator to simplify code.
	typedef typename T::const_iterator iterator;

	// Print the list elements.
	cout<<"Data: ";
	auto end=ds.end();
	for (iterator it=ds.begin(); it!=end; it++) cout<<*it<<", ";
	cout<<endl;
}

int main()
{
	vector<int> v(5);
	v[0]=10; v[1]=14; v[2]=9; v[3]=15; v[4]=8;
	Print(v);
}