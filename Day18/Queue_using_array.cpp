#include<vector>
#include <iostream>
using namespace std;

//Queue using vector/array
struct Queue
{
    vector<int> queue;
    
    //FIFO RULE - Enter element behind
    void Enqueue(int val)
    {
        queue.push_back(val);
    }
    //FIFO RULE - remove first element
    void Dequeue()
    {
        queue.erase(queue.begin());
    }
    void Front()
    {
        cout<<"Front : "<<queue[0]<<endl;
    }
};

int main()
{
    Queue q;
    q.Enqueue(5);
    q.Enqueue(4);
    q.Enqueue(2);   //[5,4,2]
    q.Front();      //->[5]
    q.Dequeue();    //[4,2]
    q.Front();      //->[4]

    return 0;
}
