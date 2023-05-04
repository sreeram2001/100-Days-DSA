
class Node:
    def __init__(self,val):
        self.val = val
        self.next = None
        
class Queue:
    def __init__(self):
        self.front = self.rear = None
        
    #enqueue
    def enqueue(self,val):
        node = Node(val)
        
        if self.rear == None:
            self.front = self.rear = node
            return
        self.rear.next = node
        self.rear = node
    
    #dequeue
    def dequeue(self):
        if self.front == None:
            return
        node = self.front
        self.front = node.next
        
        if self.front == None:
            self.rear = None
        
    #isEmpty
    def isEmpty(self):
        if self.front == None:
            print("Empty")
    
    #isFront
    def Front(self):
        print(self.front.val)
        
q = Queue()
q.enqueue(5)
q.enqueue(4)
q.enqueue(3)    #[5,4,3]
q.Front()
q.dequeue()     #[4,3]
q.Front()
q.dequeue()
q.dequeue()     #[]
q.isEmpty()
