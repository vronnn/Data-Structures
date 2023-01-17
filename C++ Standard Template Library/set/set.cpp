#include <iostream>
#include <set>
using namespace std;

int main()
{
    set <int> nums;
    // testing set's unique behavior using insert()
    for (int i=1; i<=10; i++)
    {
        for (int j=1; j<=10; j++)
            nums.insert(i);
    }
    puts("");

    // size()
    cout << "num's current size : " << nums.size() << endl;

    // print value using iterator
    cout << "num's elements : \n";
    for (set<int>::iterator it = nums.begin() ; it != nums.end() ; ++it)
        cout << *it << " ";
    puts("\n");

    // erase()
    nums.erase(2);
    cout << "num's elements after erasing key = 2 : \n";
    for (set<int>::iterator it = nums.begin() ; it != nums.end() ; ++it)
        cout << *it << " ";
    puts("\n");

    // count()
    for (int i=7; i<=12; i++)
    {
        if (nums.count(i))
            cout << i << " is inside the set" << endl;
        else
            cout << i << " is not inside the set" << endl;
    }

    // lower_bound() and upper_bound()
    set <int> ::iterator lo,hi;
    nums.erase(5);                 //1 2 3 4 6 7 8 9 10
    lo = nums.lower_bound(4);      //      ^
    hi = nums.upper_bound(4);      //        ^
    cout << "lo : " << *lo << endl;
    cout << "hi : " << *hi << endl;
    puts("");

    // clear() and empty()
    nums.clear();
    cout << "after clearing : ";
    nums.empty()? cout << "nums is empty\n" : cout << "nums is not empty\n";
}