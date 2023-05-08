
#include <iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    stack<int> stac;    //use to reverse the queue
    
    cout<<"Before reversal : ";
    while(q.size() > 0)
    {
        stac.push(q.front());
        cout<<q.front()<<" ";
        q.pop();
    }
    
    while(stac.size() > 0)
    {
        //pop elements from stack ( back ) and push it to stack
        q.push(stac.top());
        stac.pop();
    }
    
    //print the elements from reversed queue
    cout<<"After reversal : ";
    while(q.size() > 0)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}
