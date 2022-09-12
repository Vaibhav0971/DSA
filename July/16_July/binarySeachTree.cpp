#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildBST(Node* root, int data){
    if(root == NULL){
        Node* temp = new Node(data);
        return temp;
    }

    if(data < root -> data)
        root -> left = buildBST(root -> left, data);
    else
        root -> right = buildBST(root -> right, data);

    return root;
}

void createBST(Node*& root){
    cout<<"Enter the value of root node\n";
    int data;
    cin>>data;
    while(data != -1){
        root = buildBST(root, data);
        cout<<"Enter the data for node\n";
        cin>>data;
    }
}

bool searchBST(Node* root, int target){
    if(root == NULL) return false;

    if(root -> data == target) return true;

    if(target < root -> data) 
        return searchBST(root -> left, target);
    else 
        return searchBST(root -> right, target);
}

Node* findPredecessor(Node* root){
    while(root -> right){
        root = root -> right;
    }
    return root;
}

Node* deleteBST(Node* root, int target){
    if(root == NULL) return NULL;

    if(root -> data == target){
        // 0 child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        else if (root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        else if(root -> left == NULL && root -> right != NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        // 2 child
        else if(root -> left != NULL && root -> right != NULL){
            Node* temp = findPredecessor(root -> left);
            root -> data = temp -> data;
            root -> left = deleteBST(root -> left, temp -> data);
            return root;
        }
    }
    else{
        if(target < root -> data)
            root -> left = deleteBST(root -> left, target);
        else
            root -> right = deleteBST(root -> right, target);
    }
    return root;
}

void lvlOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            Node* temp = q.front();
            q.pop();
            cout<<temp -> data<<" ";
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
        cout<<endl;
    }
}

bool solveIsBST(Node* root, int min, int max){
    if(root == NULL) return true;
    
    bool left = solveIsBST(root -> left, min, root -> data);
    bool right = solveIsBST(root -> right, root -> data, max);
    
    return (root -> data >= min) && (root -> data <= max) && left && right;
}

bool isBST(Node* root) {
    if(root == NULL) return true;
    
    int min = INT_MIN, max = INT_MAX;
    
    return solveIsBST(root, min, max);
}

class Info{
    public:
    int min;
    int max;
    int size;
    bool isBST;
    
    Info(){}
    
    Info(int min, int max, int size, bool isBST){
        this -> min = min;
        this -> max = max;
        this -> size = size;
        this -> isBST = isBST;
    }
};

Info solveLargestBST(Node* root, int& ans){
    if(root == NULL){
        return {INT_MAX, INT_MIN, 0, true};
    }
    
    Info left = solveLargestBST(root -> left, ans);
    Info right = solveLargestBST(root -> right, ans);
    
    Info curr;
    curr.min = min(left.min, root -> data);
    curr.max = max(right.max, root -> data);
    curr.size = left.size + right.size + 1;
    curr.isBST = (left.isBST && right.isBST && left.max < root -> data && right.min > root -> data);
    
    if(curr.isBST) ans = max(curr.size, ans);
    
    return curr;
}

int largestBST(Node *root){
    int ans = 0;
    solveLargestBST(root, ans);
    return ans;
}

// MERGE 2 BST's

void helper(Node* root, stack<Node*> &s){
    if(root == NULL) return;
    
    while(root != NULL){
        s.push(root);
        root = root->left;
    }
}

void solve(stack<Node*>& s1, stack<Node*>& s2, vector<int>& ans){
    Node* temp1 = s1.top();
    Node* temp2 = s2.top();
    
    while(!s1.empty() && !s2.empty()){
        temp1 = s1.top();
        temp2 = s2.top();
        
        if(temp1 -> data < temp2 -> data){
            ans.push_back(temp1 -> data);
            s1.pop();
            
            helper(temp1 -> right, s1);
        }
        else if(temp1 -> data > temp2 -> data){
            ans.push_back(temp2 -> data);
            s2.pop();
            
            helper(temp2 -> right, s2);
        }
        else if(temp1 -> data == temp2 -> data){
            ans.push_back(temp1 -> data);
            s1.pop();
            ans.push_back(temp2 -> data);
            s2.pop();
            
            helper(temp1 -> right, s1);
            helper(temp2 -> right, s2);
        }
        
    }
    
    while(!s1.empty()){
        temp1 = s1.top();
        
        ans.push_back(temp1 -> data);
        s1.pop();
        
        helper(temp1 -> right, s1);
    }
    
    while(!s2.empty()){
        temp2 = s2.top();
        
        ans.push_back(temp2 -> data);
        s2.pop();
        
        helper(temp2 -> right, s2);
    }
}

vector<int> merge(Node *root1, Node *root2) {
    vector<int> ans;
    stack<Node*> s1;
    stack<Node*> s2;
    
    helper(root1, s1);
    helper(root2, s2);
    
    solve(s1, s2, ans);
    
    return ans;
}


int main(){
    Node* root = NULL;
    createBST(root);
    // deleteBST(root, 5);
    // cout<<searchBST(root, 100);
    // isBST(root);
    lvlOrderTraversal(root);
    cout<<endl;
    cout<<largestBST(root);
}
// 20 5 10 30 40 50 1 15 -1