class TreeNode(): 
    def __init__(self, x):
        self.val = x 
        self.left = None 
        self. right  = None 
def isValidBST(root, root_val):
    if root is None: 
        return True 
    if root.left is not None:  
        if root.left.val >= root.val or root.left.val >= root_val:
            return False
    if root.right is not None: 
        if root.right.val <= root.val or root.right.val <= root_val:
            return  False
    return isValidBST(root.left, root_val) and isValidBST(root.right, root_val)

def print_tree(tree):
    if tree is None : 
        print("null")
        return
    print(tree.val)
    print_tree(tree.left)
    print_tree(tree.right)

if __name__ == "__main__":
    a = TreeNode(6)
    b = TreeNode(20)
    c = TreeNode(15)
    c.left = a 
    c.right = b 
    d = TreeNode(10)
    e = TreeNode(5)
    d.left = e 
    d.right = c 
    # print(isValidBST(d, d.val))
    print_tree(d)