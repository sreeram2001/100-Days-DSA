class Node:
    def __init__(self,k,v):
        self.key = k
        self.val = v
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.cache = {}
        self.cap = capacity 

        #update head and tail of list
        self.head = Node(0,0)
        self.tail = Node(0,0)
        self.head.next = self.tail
        self.tail.prev = self.head


    def get(self, key: int) -> int:
        #check if key exists in map
        if key in self.cache:
            node = self.cache[key]

            #now update this to latest
            self.remove(node)   #first remove it from doubly linkedlist
            self.add(node)      #add it to first/head of linkedlist
            return node.val
        else:
            return -1
        

    def put(self, key: int, value: int) -> None:

        #check if key exists in map
        if key in self.cache:
            self.remove(self.cache[key])        #remove it from hashmap
        
        #add new key to map
        node = Node(key, value)
        self.add(node)              #updates to head
        self.cache[key] = node

        #if capacity is exceeded remove least recently used one
        if len(self.cache) > self.cap:

            removal_node = self.tail.prev
            self.remove(removal_node)              #remove it from linkedlist
            del self.cache[removal_node.key]       #remove it from map/cache


    #adds the new node to doubly linkedlist
    def add(self, node):
        nextnode = self.head.next
        prevnode = self.head

        nextnode.prev = node    
        prevnode.next = node

        node.prev = prevnode
        node.next = nextnode

    #to remove a node fmor doubly linkedlist
    def remove(self, node):
        nextnode = node.next
        prevnode = node.prev

        #skips in between node (remove)
        prevnode.next = nextnode
        nextnode.prev = prevnode

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
