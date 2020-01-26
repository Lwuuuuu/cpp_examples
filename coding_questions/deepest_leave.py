import collections
class TreeNode():
    def __init__(self, x):
        self.val = x 
        self.left =  None 
        self.right = None 
def deepest_leaf(root):
    if not root: return 0
    lst = [root.val] 
    while queue:
        curQueueLen = len(queue)
        curMax = 0
        for _ in range(curQueueLen):
            curNode = lst.popleft()
            curMax += curNode.val
            if curNode.left:
                lst.append(curNode.left)
            if curNode.right:
                lst.append(curNode.right)
    return curMax
if __name__ == '__main__':
    a = TreeNode(7)
    b = TreeNode(8)
    c = TreeNode(4)
    d = TreeNode(5)
    e = TreeNode(6)
    f = TreeNode(2)
    g = TreeNode(3)
    h = TreeNode(1)
    c.left = a 
    f.left = c 
    f.right = d 
    e.right = b 
    g.right = e 
    h.left = f 
    h.right = g 
    print(deepest_leaf(h))
