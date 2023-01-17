#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void print(queue <int> q)
{
    if(q.empty()) return;

    int x = q.front();
    q.pop();
    cout << x << ' ';

    print(q);
    q.push(x);
}

int main()
{
    queue <int> even;
    queue <int> odd;

    // push()
    for(int i=2; i<=10; i+=2)
        even.push(i);
    for(int i=1; i<10; i+=2)
        odd.push(i);
    // front() and back()
    cout << "even's first elemnt : " << even.front() << endl;
    cout << "odd's last element : " << odd.back() << endl;
    // size()
    cout << "odd's size : " << odd.size() << endl;
    // pop()
    even.pop() , odd.pop();
    cout << "after popping first element : \n";
    cout << "even : " , print(even), puts("");
    cout << "odd : " , print(odd), puts("");
    // swap()
    even.swap(odd);
    cout << "after swapping : \n";
    cout << "even : " , print(even), puts("");
    cout << "odd : " , print(odd), puts("");
    // empty()
    odd.empty()? cout << "odd is empty\n" : cout << "odd isn't empty\n";

    return 0;
}