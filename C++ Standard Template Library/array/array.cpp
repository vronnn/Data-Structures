#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
    array <int, 5> even = {2,4,6,8,10};
    array <int, 5> odd = {1,3,5,7,9};

    // operator[]
    cout << "even's second element : " << even[1] << endl;
    // at()
    cout << "even's element in even : " << even.at(2) << endl;
    // front()
    cout <<  "odd's first element : " << odd.front() << endl;
    // back()
    cout << "last element in odd : " << odd.back() << endl;

    puts("");
    // size()
    cout << "even's size : " << even.size() << endl;
    cout << "odd's size : " << odd.size() << endl;

    puts("");
    // begin() and end() to print
    cout << "even : ";
    for(auto i = even.begin(); i != even.end(); i++){
        cout << *i << " ";
    }
    puts("");

    // empty()
    even.empty()? cout << "even is empty\n" : cout << "even isn't empty\n";

    puts("");
    // swap()
    cout << "after swaping : \n";
    even.swap(odd);

    cout << "even : ";
    for(int x : even)
        cout << x << " ";
    puts("");

    cout << "odd : ";
    for(int x : odd)
        cout << x << " ";
    puts("");

    puts("");
    // fill()
    even.fill(0);
    cout << "even after filled with 0 : \n"; 
    for(int x : even)
        cout << x << " ";
    puts("");

    return 0;
}