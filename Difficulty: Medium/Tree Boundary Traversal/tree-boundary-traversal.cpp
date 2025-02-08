//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
void printLeafNodes(Node* root, vector<Node*> &leafNodes)
{
    if(root == nullptr)
        return;
        
    if(root->left==NULL && root->right==NULL)
    {
        leafNodes.push_back(root);
    }
    
    printLeafNodes(root->left, leafNodes);
    printLeafNodes(root->right, leafNodes);
}

void printLeftNodes(Node* root, vector<Node*> &leftNodes)
{
    if(root==nullptr)
        return;
    
    if(root->left!=NULL)
    {
        leftNodes.push_back(root);
        printLeftNodes(root->left, leftNodes);
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        leftNodes.push_back(root);
        printLeftNodes(root->right, leftNodes);
    }
    else
    {
        return;    
    }
}

void printRightNodes(Node* root, stack<Node*> &rightNodes)
{
    if(root == nullptr)
        return;
        
    if(root->right!=NULL)
    {
        rightNodes.push(root);
        printRightNodes(root->right, rightNodes);
    }
    else if(root->right==NULL && root->left!=NULL)
    {
        rightNodes.push(root);
        printRightNodes(root->left, rightNodes);
    }
    else
    {
        return;
    }
}

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<Node*> leafNodes;
        vector<Node*> leftNodes;
        stack<Node*> rightNodes;
        vector<Node*> rNodes;
        vector<int> res;
        
        if(root->left == NULL && root->right == NULL)
        {
            res.push_back(root->data);
            return res;
        }
        
        printLeafNodes(root, leafNodes);
        printLeftNodes(root->left, leftNodes);
        printRightNodes(root->right, rightNodes);
        while(!rightNodes.empty())
        {
            rNodes.push_back(rightNodes.top());
            rightNodes.pop();
        }
        
        res.push_back(root->data);
        
        for(auto itr : leftNodes)
        {
            res.push_back(itr->data);
        }
       
        for(auto itr : leafNodes)
        {
            res.push_back(itr->data);
        }
        
        for(auto itr : rNodes)
        {
            res.push_back(itr->data);
        }
       
        return res;
    }
};



//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends