#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void print(list <int> l)
{
    for(int x : l)
        cout << x << " ";
    puts("");
}

int main()
{
    list <int> even;
    list <int> odd;

    // push_back() and push_front()
    for(int i=2; i<=10; i+=2)
        even.push_back(i);
    for(int i=9; i>=1; i-=2)
        odd.push_front(i);
    // print init value
    cout << "even : ", print(even);
    cout << "odd : ", print(odd);
    // front() and back()
    cout << "even's first element : " << even.front() << endl;
    cout << "odd's last element : " << odd.back() << endl;
    // pop_front() and pop_back()
    even.pop_back();
    odd.pop_front();
    cout << "after popping even's rearmost element : \n";
    print(even);
    cout << "after popping odd's frontmost element : \n";
    print(odd);
    // size()
    cout << "even's size : " << even.size();
    // max_size()
    cout << "list's max size : " << odd.max_size();
    // resize() and assign()
    even.resize(3);
    cout << "after resizing even to 3 : \n";
    print(even);
    // assign()
    odd.assign(3,1);
    cout << "after assigning odd to 3 with 1 : \n";
    print(odd);
    // using insert() to add two 0s before 2 into even
    even.insert(even.begin(), 2, 0);
    cout << "after inserting two 0s to even : \n";
    print(even);
    // using emplace() to add another 1s into odd at second index
    odd.emplace(++odd.begin(), 1);
    cout << "after adding another 1 into odd at second index : \n";
    print(odd);
    // emplace_back() and emplace_front()
    odd.emplace_back(5);
    even.emplace_front(8);
    cout << "after adding 5 into odd at last index : \n";
    print(odd);
    cout << "after adding 8 into even at first index : \n";
    print(even);
    // unique()
    odd.unique();
    cout << "after deleting any duplicated values in odd : \n";
    print(odd);
    // remove()
    even.remove(0);
    cout << "after removing all 0s from even : \n";
    print(even);
    // list's iterator
    list <int>::iterator it;
    // init it to point even.begin then shift it 2 times to the right using advance() 
    it = even.begin();
    advance(it,2);
    // erase()
    even.erase(even.begin(), it);
    cout << "after erasing even's first two elements : \n";
    print(even);
    // swap()
    even.swap(odd);
    cout << "after swapping : \n";
    cout << "even : " , print(even);
    cout << "odd : " , print(odd);
    // using splice() to move even's first element to odd
    even.splice(even.begin(), odd, it);
    cout << "after moving even's first element to odd : \n";
    cout << "even : " , print(even);
    cout << "odd : " , print(odd);
    // merge()
    odd.merge(even);
    cout << "after merging : \n";
    cout << "even : " , print(even);
    cout << "odd : " , print(odd);
    // sort()
    odd.sort();
    cout << "after sorting odd : \n";
    print(odd);
    // reverse()
    odd.reverse();
    cout << "reversed odd's order : \n";
    print(odd);

    return 0;
}