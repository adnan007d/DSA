#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class BinaryTreeNode
{

public:
    int data;
    static int size;
    BinaryTreeNode *left = nullptr;
    BinaryTreeNode *right = nullptr;
    BinaryTreeNode(int);
    ~BinaryTreeNode();
};

BinaryTreeNode::BinaryTreeNode(int d)
{
    data = d;
    ++size;
}

BinaryTreeNode::~BinaryTreeNode()
{
}

void inorder(BinaryTreeNode *node)
{
    if (node)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}
int BinaryTreeNode ::size = 0;

// Converting Binary Tree to a Array and preserving the formula
// Negative infinity to store null values
vector<int> binaryToArray(BinaryTreeNode *node)
{
    vector<int> a;
    vector<BinaryTreeNode *> nodeList;
    nodeList.push_back(node);

    while (nodeList.size())
    {
        BinaryTreeNode *temp = nodeList[0];
        nodeList.erase(nodeList.begin());
        if (temp)
        {
            a.push_back(temp->data);
            nodeList.push_back(temp->left);
            nodeList.push_back(temp->right);
        }
        else
        {
            a.push_back(int(-INFINITY));
        }
    }

    // Removing extra null values from the array
    while (*--a.end() == int(-INFINITY))
        a.pop_back();
    return a;
}

int main()
{
    BinaryTreeNode *T = new BinaryTreeNode(20);
    T->left = new BinaryTreeNode(10);
    T->right = new BinaryTreeNode(30);
    T->left->left = new BinaryTreeNode(40);
    T->left->right = new BinaryTreeNode(5);
    // inorder(T);
    // cout << endl;
    vector<int> v = binaryToArray(T);
    for (auto x : v)
    {
        // Displaying '-' if value is negative infinity
        if (x == int(-INFINITY))
            cout << "-"
                 << " ";
        else
            cout << x << " ";
    }
    cout << endl;
    return 0;
}
// Formula for representing Binary Tree into Array
// if a node is at index: i
// its left child is at: 2 * i
// its right child is at: 2 * i + 1
// its parent is at: int (i/2)