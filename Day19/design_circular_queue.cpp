class MyCircularQueue {

    int *q;
    int front, rear, size;

public:

    MyCircularQueue(int k) {
        size = k;
        q = new int[size];
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        
        //if queue is empty
        if(front == -1)
        {
            front = rear = 0;
            q[rear] = value;
            return true;
        }

        //if queueu is full
        else if((rear+1)%size == front)
        {
            return false;
        }

        //next pos of rear
        else
        {
            rear = (1+rear)%size;
            q[rear] = value;
            return true;
        }
    }
    
    bool deQueue() {
        
        //if queue is empty
        if(front == -1 && rear == -1)
        {
            return false;
        }

        //if only one element
        else if(front == rear)
        {
            int popp = q[front];
            front = rear = -1;
            return true;
        }

        //pop from front
        else
        {
            int popp = q[front];
            front = (1+front)%size;
            return true;
        }

    }
    
    int Front() {
        //if empty
        if(front == -1)
        {
            return -1;
        }
        return q[front];
    }
    
    int Rear() {
        if(rear == -1)
        {
            return -1;
        }
        return q[rear];
    }
    
    bool isEmpty() {
        if(front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if((1+rear)%size == front)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
