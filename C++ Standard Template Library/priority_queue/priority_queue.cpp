#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void print(priority_queue <int> pq)
{
    if(pq.empty()) return;

    int x = pq.top();
    pq.pop();
    cout << x << ' ';

    print(pq);
    pq.push(x);
}

int main()
{
    priority_queue <int> randnum;
    priority_queue <int> temp;

    // create and push() random nums
    for(int i=0; i<5; i++)
        randnum.push(rand()%10);
    // fill temp using push()
    for(int i=1; i<=5; i++)
        temp.push(i);
    // print init value
    cout << "randnum : " , print(randnum), puts("");
    cout << "temp : " , print(temp), puts("");
    // size()
    cout << "randnum's size : " << randnum.size() << endl;
    // pop()
    randnum.pop();
    cout << "randnum after popping first element : \n";
    print(randnum), puts("");
    // swap()
    randnum.swap(temp);
    cout << "after swapping : \n";
    cout << "randnum : " , print(randnum), puts("");
    cout << "temp : " , print(temp), puts("");
    // empty()
    randnum.empty()? cout << "randnum is empty\n" : cout << "randnum isn't empty\n";

    return 0;
}