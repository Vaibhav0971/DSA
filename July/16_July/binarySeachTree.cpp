#include<iostream>
#include<queue>
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

int main(){
    Node* root = NULL;
    createBST(root);
    // deleteBST(root, 5);
    // cout<<searchBST(root, 100);
    lvlOrderTraversal(root);
}
// 20 5 10 30 40 50 1 15 -1