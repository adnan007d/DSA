#!/usr/bin/python3
class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def inorder(node):
    if node:
        inorder(node.left)
        print(node.data, end=" ")
        inorder(node.right)


# Converting Binary Tree to a Array and preserving the formula
def binarytoArray(node):
    a = []
    q = []
    q.append(node)
    while len(q):
        temp = q.pop(0)
        if temp:
            a.append(temp.data)
            q.append(temp.left)
            q.append(temp.right)
        else:
            a.append(None)

    # Removing extra None values from the array
    while a[-1] == None:
        a.pop()
    return a


if __name__ == '__main__':
    T = BinaryTreeNode(20)
    T.left = BinaryTreeNode(10)
    T.right = BinaryTreeNode(30)
    T.right.left = BinaryTreeNode(40)
    T.right.right = BinaryTreeNode(5)
    inorder(T)
    print()
    print(binarytoArray(T))
    print()
# Formula for representing Binary Tree into Array
# if a node is at index: i
# its left child is at: 2 * i
# its right child is at: 2 * i + 1
# its parent is at: int (i/2)
