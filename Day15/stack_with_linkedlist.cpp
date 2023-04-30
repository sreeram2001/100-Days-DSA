
#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

Node *top = NULL;

bool isEmpty()
{
    if(top == NULL)
    {
        return true;
    }
    
    return false;
}

//push elements into stack ( FIFO )
void push (int val)
{
  Node *item = new Node();
  item->val= val;
  item->next = top;
  top = item;
}

//pop out elements from back as stack follows FIFO
void pop()
{
    if(isEmpty())
    {
        cout<<"stack Empty"<<std::endl;
    }
    else
    {
        Node *item = top;
        top = top->next;
        delete(item);
    }
}

//top elements
void topitem()
{
    if(isEmpty())
    {
        cout<<"Stack Empty"<<std::endl;
    }
    else
    {
        cout<<"top Element :"<<top->val<<std::endl;
    }
}

void show()
{
    if(isEmpty())
    {
        cout<<"Stack Empty"<<std::endl;
    }
    else
    {
        Node *temp = top;
        while(temp)
        {
            cout<<temp->val;
            temp = temp->next;
        }
    }
}


int main()
{
    //perform operations
    push(1);
    push(2);
    push(3);
    topitem();
    pop();
    show();

    return 0;
}
