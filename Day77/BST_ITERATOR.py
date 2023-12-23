# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        node = root
        self.nodes = []
        self.ind = -1
        self.inorder(root, self.nodes)

    def inorder(self, root, nodes):
        if root == None:
            return
        
        if root.left:
            self.inorder(root.left, nodes)
        nodes.append(root.val)
        if root.right:
            self.inorder(root.right, nodes)
        
    def next(self) -> int:
        self.ind += 1
        return self.nodes[self.ind]
        
    def hasNext(self) -> bool:
        if(self.ind < len(self.nodes)-1):
            return True
        return False
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
