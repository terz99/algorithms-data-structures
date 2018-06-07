from rbt import *

if __name__ == "__main__":
    tree = RedBlackTree()
    while True:
        tmp = int(input())
        if tmp < 0:
            break
        tree.insert(tmp)
        tree.preorder()

    print(tree.getMinimum().val)
    print(tree.getMaximum().val)

    while True:
        tmp = int(input())
        if tmp < 0:
            break
        node = tree.search(tmp)
        if node != None:
            print(node.val)
            tree.delete(node.val)
        else:
            print(node)
        tree.preorder()