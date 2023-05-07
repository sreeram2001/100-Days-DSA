class MyCircularDeque:

    def __init__(self, k: int):
        self.size = 0
        self.dq = [None for i in range(k)]
        self.front = 0
        self.rear = 0
        self.full = k

    def insertFront(self, value: int) -> bool:
        #if queue is full
        if(self.isFull()):
            return False

        self.front = (self.front-1)%self.full
        self.dq[self.front] = value
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        #if queue is full
        if(self.isFull()):
            return False

        self.dq[self.rear] = value
        self.rear = (self.rear + 1)%self.full
        self.size += 1
        return True

    def deleteFront(self) -> bool:
        #if queue is empty
        if(self.isEmpty()):
            return False
        
        self.front = (1+self.front)%self.full
        self.size -=1 
        return True
        
    def deleteLast(self) -> bool:
        #if queue is empty
        if(self.isEmpty()):
            return False

        self.rear = (self.rear - 1)%self.full
        self.size -=1
        return True

    def getFront(self) -> int:
        #if queue is empty
        if(self.isEmpty()):
            return -1

        return self.dq[self.front]

    def getRear(self) -> int:
        #if queue is empty
        if(self.size == 0):
            return -1

        return self.dq[(self.rear-1)%self.full]

    def isEmpty(self) -> bool:
        #if queue is empty
        if(self.size == 0):
            return True
        return False

    def isFull(self) -> bool:
        if self.size == self.full:
            return True
        return False
        


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
