#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int maxHeight(Node* root){
        if(root==NULL) return 0;
        return max(1+maxHeight(root->left),1+maxHeight(root->right));
    }
    
    int findH(Node* root,int k){
        if(root==NULL) return 0;
        if(root->data == k) return 1;
        int left= findH(root->left,k);
        if(left >0) return left+1;
        int right = findH(root->right,k);
        if(right >0) return right+1;
        return -1;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(root==NULL) return 0;
        if(root->data == target){
            return maxHeight(root)-1;
        }
        
        int LT= minTime(root->left,target);
        int RT= minTime(root->right,target);
        
        int expAns= max(LT,RT);
        
        int LH= maxHeight(root->left);
        int RH= maxHeight(root->right);
    
        int inLeft = findH(root->left,target);
        if(inLeft > 0){
            return max(expAns,max(LH-inLeft,RH+inLeft));
        }
        
        int inRight= findH(root->right,target);
        if(inRight >0){
            return max(expAns,max(RH-inRight,LH+inRight));
        }
        return -1;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
