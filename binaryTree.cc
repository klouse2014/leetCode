#include "iostream"
#include "stack"
using namespace std;
struct binaryNode
{
    string data;
    binaryNode *left;
    binaryNode *right;
    binaryNode(string value = ""){
        data = value;
        left=NULL;
        right=NULL;
    }
};

void createBinaryTree(binaryNode* &root)
{
    string temp;
    getline(cin, temp);
    if(temp.empty())
        return;
    if(root == NULL)
        root = new binaryNode(temp);
    createBinaryTree(root->left);
    createBinaryTree(root->right);
}

void dispBinaryTree(binaryNode* &root)
{
    if(root == NULL)
        return;
    dispBinaryTree(root->left);
    dispBinaryTree(root->right);
    delete root;
}

void PreOrderRecur(const binaryNode *root)
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    PreOrderRecur(root->left);
    PreOrderRecur(root->right);
}

void PreOrderIter(binaryNode *root)
{
    if(root == NULL)
        return;
    stack<binaryNode*> stk;
    stk.push(root);
    while(!stk.empty())
    {
        binaryNode *tmp = stk.top();
        stk.pop();
        cout << tmp->data <<" ";
        if(tmp->right != NULL)
            stk.push(tmp->right);
        if(tmp->left != NULL)
            stk.push(tmp->left);
    }
    cout<<endl;
}

void InOrderIter(binaryNode *root)
{
    if(root == NULL)
        return;
    stack<binaryNode *> stk;
    binaryNode *p = root;
    while(!stk.empty() || p != NULL)
    {
        while(p != NULL)
        {
            stk.push(p);
            p = p->left;
        }
        if(!stk.empty())
        {
            p = stk.top();
            stk.pop();
            cout<< p->data << " ";
            p = p->right;
        }
    }
    cout<<endl;
}

int main()
{
    binaryNode *root = NULL;
    createBinaryTree(root);
    //PreOrderRecur(root);
    //PreOrderIter(root);
    InOrderIter(root);

    dispBinaryTree(root);

    return 0;
}
