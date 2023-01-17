#include <iostream>
#include <forward_list>
#include <algorithm>
using namespace std;

void print(forward_list <int> fl)
{
    for(int x : fl)
        cout << x << " ";
    puts("");
}

bool zero(const int &value) 
{
    return (value == 2);
}

int main()
{
    forward_list <int> even;
    forward_list <int> odd;
    
    // assign()
    even.assign({4,6,8,10});
    // emplace_after()
    even.emplace_after(even.before_begin(),2);
    // push_front()
    for(int i=9; i>=3; i-=2)
        odd.push_front(i);
    // emplace_front()
    odd.emplace_front(1);
    // print init value
    cout << "even : " , print(even);
    cout << "odd : " , print(odd);
    // max_size()
    cout << "foward_list's max size : " << even.max_size() << endl;
    // front()
    cout << "even's first element : " << even.front() << endl;
    // using insert_after() to insert another 2 after 2 in even
    cout << "inserting another 4 into even : \n";
    even.insert_after(even.begin()++, 4);
    print(even);
    // forward_list's iterator
    forward_list <int>::iterator it;
    // place it to after last element
    it = odd.begin();
    for(int i=1; i<5; i++)
        it++;
    // using insert_after() to insert two more 9s into odd's rearmost
    cout << "inserting two more 9s into odd from the back: \n";
    odd.insert_after(it,2,9);
    print(odd);
    // using remove() to erase all 9s from odd
    cout << "removing 9s from odd : \n";
    odd.remove(9);
    print(odd);
    // pop_front()
    cout << "popping even's frontmost element : \n";
    even.pop_front();
    print(even);
    // remove_if()
    cout << "removing 2 from even : \n";
    even.remove_if(zero);
    print(even);
    // unique()
    even.unique();
    cout << "removing duplicated 4 from even : \n";
    cout << "even : " , print(even);
    // resize()
    cout << "after resized into 3 : \n";
    cout << "even : " , even.resize(3) , print(even);
    cout << "odd : " , odd.resize(3) , print(odd);
    // swap()
    even.swap(odd);
    cout << "after swapping : \n";
    cout << "even : " , print(even);
    cout << "odd : " , print (odd);
    // merge()
    odd.merge(even);
    cout << "after merging : \n";
    cout << "even : " , print(even);
    cout << "odd : " , print (odd);
    // reverse()
    odd.reverse();
    cout << "reverse odd's order : \n";
    print(odd);
    // clear() and empty()
    odd.clear();
    cout << "odd's content after clearing : \n";
    odd.empty()? cout << "odd's now empty\n" : cout << "odd is not empty\n";

    return 0;
}