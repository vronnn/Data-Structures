#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print (vector <int> v)
{
    for(int x : v)
        cout << x << " ";
    puts("");
}

int main()
{
    vector <int> even;
    vector <int> odd = {1,3,5,7,9};
    vector <int> rand = {3,1,4,2,5};
    // push_back()
    for(int i = 2; i <= 10; i+=2)
        even.push_back(i);
    // size()
    cout << "even size : " << even.size() << endl;
    // print contents
    cout << "init value : \n";
    cout << "even : ", print(even);
    cout << "odd : ", print(odd);
    // operator[]
    cout << "even's second element : " << even[1] << endl;
    // at()
    cout << "odd's third element : " << odd.at(2) << endl;
    // front()
    cout << "even's first element : " << even.front() << endl;
    // back()
    cout << "odd's last element : " << odd.back() << endl;
    // empty()
    odd.empty()? cout << "odd is empty\n" : cout << "odd isn't empty\n";
    // pop_back()
    even.pop_back();
    cout << "even after pop_back : \n";
    print(even);
    // resize()
    odd.resize(3);
    cout << "after resizing odd to 3 : \n";
    print(odd);
    // assign()
    even.assign(3,0);
    cout << "after assigning even to 3 with 0 : \n";
    print(even);
    // using insert() to insert 20 in the second index
    even.insert(even.begin()+1, 20);
    cout << "even after inserting 20 at sec index : \n";
    print(even);
    // using insert() to insert 10 three times starting in the third index
    even.insert(even.begin()+2, 3, 10);
    cout << "even after inserting 10 3x starting in the third index : \n";
    print(even);
    // using erase() to delete the third element
    even.erase(even.begin()+2);
    cout << "even after erasing third element : \n";
    print(even);
    // using erase() to delete the first two elements
    even.erase(even.begin(), even.begin()+2);
    cout << "even after erasing the first two elements : \n";
    print(even);
    // swap()
    even.swap(odd);
    cout << "after swap : \n";
    print(even);
    print(odd);
    // clear()
    odd.clear();
    cout << "after clearing odd : \n";
    odd.empty()? cout << "odd is empty\n" : cout << "odd isn't empty\n";
    // sort()
    sort(rand.begin(),rand.end());
    cout << "after sorting rand : \n";
    print(rand);
    // vector iterators
    vector <int>::iterator lo, hi;
    // find lower_bound of rand with the value 3
    lo = lower_bound(rand.begin(), rand.end(), 3);
    hi = upper_bound(rand.begin(), rand.end(), 3);
    // print lower & upper bound
    cout << "rand's lower bound index : " << lo - rand.begin() << endl;
    cout << "rand's upper bound index : " << hi - rand.begin() << endl;

    return 0;
}