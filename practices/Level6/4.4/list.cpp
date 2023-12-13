#include <list>
#include <iostream>

using namespace std;

int main() {
    list<int> l;

    // Add Data.
    l.push_back(2);
    l.push_back(3);
    l.push_back(1);

    // Use iterator for traversal.

    list<int>::iterator iter;
    const list<int>::iterator end = l.end();
    for (iter = l.begin(); iter != end; iter++)
    {
        cout << *iter << endl;
    }
    return 0;
}