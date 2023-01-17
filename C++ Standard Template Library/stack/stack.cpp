#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

void printTopBottom(stack <int> s)
{
    if(s.empty()) return;

    int x = s.top();
    s.pop();
    cout << x << ' ';

    printTopBottom(s);
    s.push(x);
}

void printBottomTop(stack <int> s)
{
    if(s.empty()) return;
    
    int x = s.top();
    s.pop();
    printBottomTop(s);

    cout << x << ' ';
    s.push(x);
}

int main()
{
    stack <int> even;
    stack <int> odd;

    // push()
    for(int i=2; i<=10; i+=2)
        even.push(i);
    for(int i=1; i<10; i+=2)
        odd.push(i);
    // size()
    cout << "odd's current size : " << odd.size() << endl;
    // top()
    cout << "even's first element : " << even.top() << endl;
    // swap()
    even.swap(odd);
    cout << "after swapping : \n";
    cout << "even top to bottom : " , printTopBottom(even), puts("");
    cout << "odd bottom to top : " , printBottomTop(odd), puts("");
    // pop()
    even.pop() , odd.pop();
    cout << "after popping an element : \n";
    cout << "even bottom to top: " , printBottomTop(even), puts("");
    cout << "odd top to bottom : " , printTopBottom(odd), puts("");
    // empty()
    odd.empty()? cout << "odd is empty\n" : cout << "odd isn't empty\n";

    return 0;
}