import java.util.ArrayList;

class BinaryTreeNode {
    int data;
    BinaryTreeNode left;
    BinaryTreeNode right;
    static int size = 0;

    BinaryTreeNode(int data) {
        this.data = data;
        ++size;
    }
}

public class BinaryTree {
    @SuppressWarnings("unused")
    private static void inorder(BinaryTreeNode node) {
        if (node != null) {
            inorder(node.left);
            System.out.print(node.data + " ");
            inorder(node.right);
        }
    }

    // Converting Binary Tree to a Array and preserving the formula
    private static ArrayList<Integer> binaryToArray(BinaryTreeNode node) {
        ArrayList<Integer> a = new ArrayList<Integer>();
        ArrayList<BinaryTreeNode> nodeList = new ArrayList<BinaryTreeNode>();
        nodeList.add(node);
        while (nodeList.size() > 0) {
            BinaryTreeNode temp = nodeList.get(0);
            nodeList.remove(0);

            if (temp != null) {
                a.add(temp.data);
                nodeList.add(temp.left);
                nodeList.add(temp.right);
            } else {
                a.add(null);
            }

        }
        // Removing extra null values from the array
        while (a.get(a.size() - 1) == null)
            a.remove(a.size() - 1);
        return a;
    }

    public static void main(String[] args) {
        BinaryTreeNode T = new BinaryTreeNode(20);
        T.left = new BinaryTreeNode(10);
        T.right = new BinaryTreeNode(30);
        T.right.left = new BinaryTreeNode(40);
        T.right.right = new BinaryTreeNode(5);
        // inorder(T);
        System.out.println();
        ArrayList<Integer> a = binaryToArray(T);
        for (Integer x : a) {
            System.out.print(x + " ");
        }
        System.out.println();

    }
}
// Formula for representing Binary Tree into Array
// if a node is at index: i
// its left child is at: 2 * i
// its right child is at: 2 * i + 1
// its parent is at: int (i/2)