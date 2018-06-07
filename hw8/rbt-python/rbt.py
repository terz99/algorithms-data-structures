RED = 1
BLACK = 0

class Node:

    def __init__(self, val, color, left=None, right=None, parent=None):
        self.val = val
        self.left = left
        self.right = right
        self.parent = parent
        self.color = color

class RedBlackTree:

    def __init__(self):
        self.root = None

    def leftRotate(self, x):
        if not x.right:
            return
        
        y = x.right
        x.right = y.left
        if y.left:
            y.left.parent = x
        
        y.parent = x.parent
        if not x.parent:
            self.root = y
        else:
            if x == x.parent.left:
                x.parent.left = y;
            else:
                x.parent.right = y
        y.left = x
        x.parent = y

    def rightRotate(self, x):
        if not x.left:
            return
        
        y = x.left
        x.left = y.right

        if y.right:
            y.right.parent = x
        
        y.parent = x.parent
        if not x.parent:
            self.root = y
        else:
            if x == x.parent.left:
                x.parent.left = y
            else:
                x.parent.right = y
        y.right = x
        x.parent = y

    def fixInsertViolations(self, x):
        while x != self.root and x.parent.color:
            if x.parent == x.parent.parent.left:
                y = x.parent.parent.right
                if y and y.color == RED:
                    x.parent.color = BLACK
                    y.color = BLACK
                    x.parent.parent.color = RED
                    x = x.parent.parent
                else:
                    if x == x.parent.right:
                        x = x.parent
                        self.leftRotate(x)
                    x.parent.color = BLACK
                    x.parent.parent.color = RED
                    self.rightRotate(x.parent.parent)
            else:
                y = x.parent.parent.left
                if y and y.color == RED:
                    x.parent.color = BLACK
                    y.color = BLACK
                    x.parent.parent.color = RED
                    x = x.parent.parent
                else:
                    if x == x.parent.left:
                        x = x.parent
                        self.rightRotate(x)
                    x.parent.color = BLACK
                    x.parent.parent.color = RED
                    self.leftRotate(x.parent.parent)
        self.root.color = BLACK

    def insert(self, val):
        node = Node(val, RED)
        self.root = self._insert(self.root, node)
        self.fixInsertViolations(node)

    def _insert(self, root, newNode):
        if root == None:
            return newNode

        if newNode.val < root.val:
            root.left = self._insert(root.left, newNode)
            root.left.parent = root
        elif newNode.val > root.val:
            root.right = self._insert(root.right, newNode)
            root.right.parent = root
        
        return root

    # def _delete(self, val, node):
    #     if not node:
    #         return node

    #     if val < node.val
    #         return self._delete(val, node.left)
    #     if val > node.val:
    #         return self._delete(val, node.right)
    #     if not node.left or not node.right
    #         return node
        
    #     tmp = self.getMinimum(node.right)
    #     node.val = tmp.val
    #     return self._delete(tmp.val, node.right)

    # def delete(self, val):
    #     node = self._delete(val, self.root)
    #     self.fixDeleteViolations(node)

    def preorder(self, node=None):
        if node == None:
            if self.root == None:
                return
            else:
                self.preorder(self.root)
                print()
                return
        print(node.val, end=" ")
        if node.left != None:
            self.preorder(node.left)
        if node.right != None:
            self.preorder(node.right)

    def search(self, val, node=None):
        if node == None:
            if self.root == None:
                return None
            else:
                return self.search(val, self.root)
        
        if val < node.val:
            if node.left != None:
                return self.search(val, node.left)
            else:
                return None
        elif val > node.val:
            if node.right != None:
                return self.search(val, node.right)
            else:
                return None
        else:
            return node

    def getMinimum(self, node=None):
        if node == None:
            if self.root == None:
                return None
            else:
                return self.getMinimum(self.root)
        
        if node.left != None:
            return self.getMinimum(node.left)
        else:
            return node

    def getMaximum(self, node=None):
        if node == None:
            if self.root == None:
                return None
            else:
                return self.getMaximum(self.root)
        
        if node.right != None:
            return self.getMaximum(node.right)
        else:
            return node

    