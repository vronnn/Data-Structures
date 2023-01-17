#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void print (deque <int> d)
{
    for(int x : d)
        cout << x << " ";
    puts("");
}

int main()
{
    deque <int> even;
    deque <int> odd;

    // push_back() and push_front()
    for(int i=2; i<=10; i+=2)
        even.push_back(i);
    for(int i=9; i>=1; i-=2)
        odd.push_front(i);
    // print init value
    cout << "even : ", print(even);
    cout << "odd : ", print(odd);
    // operator[]
    cout << "even's fourth element : " << even[3] << endl;
    // at()
    cout << "odd's fourth element : " << odd.at(3) << endl;
    // front()
    cout << "even's first element : " << even.front() << endl;
    // back()
    cout << "odd's last element : " << odd.back() << endl;
    // empty()
    even.empty()? cout << "even is empty\n" : cout << "even isn't empty\n";
    // pop_front()
    odd.pop_front();
    cout << "odd after popping frontmost element : \n" , print(odd);
    // pop_back()
    even.pop_back();
    cout << "even after popping rearmost element : \n" , print(even);
    // size()
    cout << "even's current size : " << even.size() << endl;
    cout << "odd's current size : " << odd.size() << endl;
    // resize()
    even.resize(3);
    cout << "after resizing even to 3 : \n";
    print(even);
    // assign()
    odd.assign(3,1);
    cout << "after assigning odd to 3 with 1 : \n";
    print(odd);
    // using insert() to insert 20 in the second index
    even.insert(even.begin()+1, 20);
    cout << "even after inserting 20 at sec index : \n";
    print(even);
    // using insert() to insert 10 three times starting in the third index
    odd.insert(odd.begin()+2, 3, 11);
    cout << "even after inserting 10 3x starting in the third index : \n";
    print(odd);
    // using erase() to delete the third element
    odd.erase(odd.begin()+2);
    cout << "even after erasing third element : \n";
    print(odd);
    // using erase() to delete the first two elements
    odd.erase(odd.begin(), odd.begin()+2);
    cout << "even after erasing the first two elements : \n";
    print(odd);
    // swap()
    even.swap(odd);
    cout << "after swapping : \n";
    cout << "even : ", print(even);
    cout << "odd : ", print(odd);
    // sort()
    sort(odd.begin(), odd.end());
    print(odd);
    // deque iterators
    deque <int>::iterator lo, hi;
    // find lower_bound of odd with the value 4
    lo = lower_bound(odd.begin(), odd.end(), 4);
    hi = upper_bound(odd.begin(), odd.end(), 4);
    // print lower & upper bound
    cout << "odd's lower bound index : " << lo - odd.begin() << endl;
    cout << "odd's upper bound index : " << hi - odd.begin() << endl;
    // clear()
    odd.clear();
    odd.empty()? cout << "odd is empty\n" : cout << "odd isn't empty\n";

    return 0;
}