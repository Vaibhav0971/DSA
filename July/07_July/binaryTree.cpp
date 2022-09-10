#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    cout<<"Enter the value of data"<<endl;
    int data;
    cin>>data;
    if(data == -1) return NULL;

    Node* newNode = new Node(data);

    cout<<"Enter the data for left child of - "<<data<<endl;
    newNode -> left = buildTree();
    
    cout<<"Enter the data for right child of - "<<data<<endl;
    newNode -> right = buildTree();

    return newNode;
}

void preOrder(Node* &root){
    if(root == NULL) return;

    cout<<root->data<<", ";

    preOrder(root -> left);

    preOrder(root -> right);
}

void inOrder(Node* &root){
    if(root == NULL) return;

    inOrder(root -> left);

    cout<<root->data<<", ";

    inOrder(root -> right);
}

void postOrder(Node* &root){
    if(root == NULL) return;

    postOrder(root -> left);

    postOrder(root -> right);

    cout<<root->data<<", ";
}

void levelOrder(Node* &root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        // tu nikal
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<front -> data<<", ";

            // bache chod jaeo
            if(front -> left != NULL) q.push(front -> left);
            if(front -> right != NULL) q.push(front -> right);
        }
    }
}

void reverseLevelOrder(Node* &root){
    queue<Node*> q;
    stack<int> st;

    q.push(root);

    while(!q.empty()){
        Node* front = q.front();
        st.push(front -> data);
        q.pop();

        if(front -> right != NULL) q.push(front -> right);
        if(front -> left != NULL) q.push(front -> left);
    }
    
    while(!st.empty()){
        cout<<st.top()<<", ";
        st.pop();
    }
}

int height(Node* &root){
    if(root == NULL) return 0;
    // if(root -> left == NULL && root -> right == NULL) return 0;

    int left = height(root -> left);
    int right = height(root -> right);

    return 1 + max(left, right);
}
 
int diameter(Node* &root){
    if(root == NULL) return 0;

    int opt1 = diameter(root -> left);
    int opt2 = diameter(root -> right);
    int opt3 = height(root -> left) + 1 + height(root -> right);

    return max(opt1, max(opt2, opt3));
}

pair<int, int> diameterFast(Node* &root){
    if(root == NULL){
        pair<int, int> p = make_pair(0,0);
        return p;
    }
    
    pair<int, int> opt1 = diameterFast(root -> left);
    pair<int, int> opt2 = diameterFast(root -> right);
    
    int opt3 = opt1.second + opt2.second + 1;
    
    pair<int, int> ans = make_pair(max(opt1.first, max(opt2.first, opt3)), max(opt1.second, opt2.second) + 1);
    return ans;
}

bool isBalanced(Node *root){
    if(root == NULL) return true;
    
    bool left = isBalanced(root -> left);
    bool right = isBalanced(root -> right);
    bool diff = abs(height(root -> left) - height(root -> right)) <= 1;
    
    return left && right && diff;
}

pair<bool, int> isBalancedFast(Node* &root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    
    pair<bool, int> left = isBalancedFast(root -> left);
    pair<bool, int> right = isBalancedFast(root -> right);
    
    bool diff = abs(left.second - right.second) <= 1;
    
    pair<bool, int> ans = make_pair((left.first && right.first && diff), max(left.second, right.second) + 1);
    return ans;
}

bool isIdentical(Node *r1, Node *r2){
    if(r1 == NULL && r2 == NULL) return true;
    if((r1 != NULL && r2 == NULL) || (r1 == NULL && r2 != NULL)) return false;
    
    bool value = r1->data == r2->data;
    
    bool left = isIdentical(r1 -> left, r2 -> left);
    bool right = isIdentical(r1 -> right, r2 -> right);
    
    return left && right && value;
}

pair<bool, int>isSumTreeFast(Node* &root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    
    if(root -> left == NULL && root -> right == NULL){
        pair<bool, int> p = make_pair(true, root -> data);
        return p;
    }
    
    pair<bool, int> left = isSumTreeFast(root -> left);
    pair<bool, int> right = isSumTreeFast(root -> right);
    
    pair<bool, int> ans;
    ans.first = left.first && right.first && (left.second + right.second == root -> data);
    ans.second = 2 * root -> data;
    
    return ans;
}

// DIFFERENT TREE TRAVERSALS 👇 👇 👇

vector <int> zigZagTraversal(Node* root){
    vector<int> result;
    if(root == NULL) return result;
    
    queue<Node*> q;
    q.push(root);
    
    bool leftToRight = true;
    
    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);
        
        for(int i=0; i<size; i++){
            Node* front = q.front();
            q.pop();
            
            int index = leftToRight ? i : size - i - 1;
            ans[index] = front -> data;
            
            if(front -> left) q.push(front -> left);
            if(front -> right) q.push(front -> right);
        }
        
        leftToRight = !leftToRight;
        
        for(auto i : ans)
            result.push_back(i);
    }
    
    return result;
}

void traverseLeft(Node* &root, vector<int>& ans){
    if(root == NULL || (root -> left == NULL && root -> right == NULL)) return; 
    
    ans.push_back(root -> data);
    
    if(root -> left) 
        traverseLeft(root -> left, ans);
    else
        traverseLeft(root -> right, ans);
}

void traverseLeaf(Node* &root, vector<int>& ans){
    if(root == NULL) return;
    
    if(root -> left == NULL && root -> right == NULL){
        ans.push_back(root -> data);
        return;
    } 
    
    traverseLeaf(root -> left, ans);
    traverseLeaf(root -> right, ans);
}

void traverseRight(Node* &root, vector<int>& ans){
    if(root == NULL || (root -> left == NULL && root -> right == NULL)) return; 
    
    if(root -> right) 
        traverseRight(root -> right, ans);
    else
        traverseRight(root -> left, ans);
    
    ans.push_back(root -> data);
}

vector <int> boundary(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    
    ans.push_back(root -> data);
    // Left side boundary except leaf element
    traverseLeft(root -> left, ans);
    // Leaf elements
    traverseLeaf(root -> left, ans);
    traverseLeaf(root -> right, ans);
    // Right side boundary except leaf element
    traverseRight(root -> right, ans);
    
    return ans;
}

vector<int> verticalOrder(Node *root){
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node*, pair<int, int>>> q;
    vector<int> ans;
    
    if(root == NULL) return ans;
    
    q.push(make_pair(root, make_pair(0, 0)));
    
    while(!q.empty()){
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int horzDist = temp.second.first;
        int level = temp.second.second;
        
        nodes[horzDist][level].push_back(frontNode -> data);
        
        if(frontNode -> left) 
            q.push(make_pair(frontNode -> left, make_pair(horzDist - 1, level + 1)));
        if(frontNode -> right) 
            q.push(make_pair(frontNode -> right, make_pair(horzDist + 1, level + 1)));
    }
    
    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                ans.push_back(k);
            }
        }
    }
    
    return ans;
}

vector<int> topView(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    
    map<int, int> nodes;
    queue<pair<Node*, int>> q;
    
    q.push(make_pair(root, 0));
    
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int horzDist = temp.second;
        
        if(nodes.find(horzDist) == nodes.end()){
            nodes[horzDist] = frontNode -> data;
        }  
        
        if(frontNode -> left) 
            q.push(make_pair(frontNode -> left, horzDist - 1));
        if(frontNode -> right) 
            q.push(make_pair(frontNode -> right, horzDist + 1));
    }
    
    for(auto i : nodes){
        ans.push_back(i.second);
    }
    
    return ans;
}

vector<int> bottomView(Node *root) {
    vector<int> ans;
    if(root == NULL) return ans;
    
    map<int, int> nodes;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int horzDist = temp.second;
        
        nodes[horzDist] = frontNode -> data;
        
        if(frontNode -> left) 
            q.push(make_pair(frontNode -> left, horzDist - 1));
        if(frontNode -> right) 
            q.push(make_pair(frontNode -> right, horzDist + 1));
    }
    
    for(auto i : nodes){
        ans.push_back(i.second);
    }
    
    return ans;
}

vector<int> rightView(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    
    map<int, int> nodes;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int level = temp.second;
        
        if(nodes.find(level) == nodes.end())
            nodes[level] = frontNode -> data;
        
        if(frontNode -> right)
            q.push(make_pair(frontNode -> right, level + 1));
        if(frontNode -> left)
            q.push(make_pair(frontNode -> left, level + 1));
    }
    
    for(auto i : nodes)
        ans.push_back(i.second);
        
    return ans;
}

vector<int> leftView(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    
    map<int, int> nodes;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int level = temp.second;
        
        if(nodes.find(level) == nodes.end())
            nodes[level] = frontNode -> data;
            
        if(frontNode -> left)
            q.push(make_pair(frontNode -> left, level + 1));
        if(frontNode -> right)
            q.push(make_pair(frontNode -> right, level + 1));
    }
    
    for(auto i : nodes)
        ans.push_back(i.second);
}

void solve(Node* root, int level, vector<int>& arr){
    if(root == NULL) return;
    
    if(level >= arr.size())
        arr.push_back(root -> data);
    
    if(root -> left) solve(root -> left, level + 1, arr);
    if(root -> right) solve(root -> right, level + 1, arr);
}

vector<int> leftViewRec(Node *root){
    vector<int> ans;
    
    solve(root, 0, ans);
    
    return ans;
}

void solveDiagonal(Node* root, int diagonal, map<int, vector<int>>& mp){
    if(root == NULL) return;

    mp[diagonal].push_back(root->data);

    solveDiagonal(root->left, diagonal + 1, mp);

    solveDiagonal(root->right, diagonal, mp);
}

vector<int> diagonal(Node *root){
    map<int, vector<int>> mp;

    int diagonal = 0;

    solveDiagonal(root, diagonal, mp);

    vector<int> ans;
    
    for(auto i : mp)
        for(auto j : i.second)
            ans.push_back(j);

    return ans;
}

Node* lca(Node* root ,int n1 ,int n2 ){
    if(root == NULL) return NULL;
    
    if(root -> data == n1 || root -> data == n2) return root;
    
    Node* left = lca(root -> left, n1, n2);
    Node* right = lca(root -> right, n1, n2);
    
    if(left != NULL && right != NULL) return root;
    if(left != NULL && right == NULL) return left;
    if(left == NULL && right != NULL) return right;
    return NULL;
}

// Burn Tree
void createParentMapping(Node* root, int& target, map<Node*, Node*>& nodeToParent, Node*& targetNode){
    if(root == NULL) return;
    
    if(target == root -> data){
        targetNode = root;
    }
    if(root -> left != NULL) {
        nodeToParent[root -> left] = root;
    }
    if(root -> right != NULL) {
        nodeToParent[root -> right] = root;
    }
    
    createParentMapping(root -> left, target, nodeToParent, targetNode);
    createParentMapping(root -> right, target, nodeToParent, targetNode);
    
}

void burnTree(Node* targetNode, map<Node*, Node*> nodeToParent, int& count){
    map<Node*, bool> visited;
    
    queue<Node*> q;
    q.push(targetNode);
    visited[targetNode] = true;
    
    while(!q.empty()){
        
        int size = q.size();
        
        for(int i=0; i<size; i++){
            Node* front = q.front();
            q.pop();
            
            Node* parent = nodeToParent[front];
            Node* left = front -> left;
            Node* right = front -> right;
            
            if(parent != NULL && visited[parent] != true){
                q.push(parent);
                visited[parent] = true;
            }
            if(left != NULL && visited[left] != true){
                q.push(left);
                visited[left] = true;
            }
            if(right != NULL && visited[right] != true){
                q.push(right);
                visited[right] = true;
            }
        }
        
        if(!q.empty()) count++;
    }
}

int minTime(Node* root, int target){
    int count = 0;
    map<Node*, Node*> nodeToParent;
    
    Node* targetNode = NULL;
    createParentMapping(root, target, nodeToParent, targetNode);
    
    burnTree(targetNode, nodeToParent, count);
    
    return count;
}

// Flatten binary tree to linked list -- using Morris Traversal
void flatten(Node *root) {
    Node* curr = root;
    
    while(curr != NULL){
        if(curr -> left){
            Node* predecessor = curr -> left;
            
            while(predecessor -> right)
                predecessor = predecessor -> right;
            
            predecessor -> right = curr -> right;
            curr -> right = curr -> left;
            curr -> left = NULL;
        }
        else{
            curr = curr -> right;
        }
    }
}

int main(){
    Node* root = NULL;

    root = buildTree();
    // 10 3 5 -1 -1 7 6 -1 -1 -1 11 -1 -1

    // cout<<"\nPrinting preOrder tree traversal\n";
    // preOrder(root);
    // cout<<"\nPrinting inOrder tree traversal\n";
    // inOrder(root);
    // cout<<"\nPrinting postOrder tree traversal\n";
    // postOrder(root);
    // cout<<"\nPrinting levelOrder tree traversal\n";
    // levelOrder(root);
    // cout<<"\nPrinting reverseLevelOrder tree traversal\n";
    // reverseLevelOrder(root);

    // cout<<"\nDiameter of tree is "<<diameter(root)<<"\n";
    // cout<<"\nDiameter of tree in O(n) is "<<diameterFast(root).first<<"\n";

    // cout<<"\nCheck if tree is balanced "<<isBalanced(root)<<"\n";
    // cout<<"\nCheck if tree is balanced in O(n) "<<isBalancedFast(root).first<<"\n";
    
    // cout<<"\nCheck if tree is sumTree in O(n) "<<isSumTreeFast(root).first<<"\n";

    // cout<<"Height of tree is - "<<height(root)<<endl;

}