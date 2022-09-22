#include<iostream>

using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d){
        data = d;
        isTerminal = false;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
    }    
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertHelper(TrieNode* root, string word){
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            child = new TrieNode(ch);
            root -> children[index] = child;
        }

        insertHelper(child, word.substr(1));
    }

    void insert(string word){
        insertHelper(root, word);
        cout<<word<<" -> Inserted Successfully.\n";
    }

    bool searchHelper(TrieNode* root, string word){
        if(word.length() == 0){
            return root -> isTerminal;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            return false;
        } 

        return searchHelper(child, word.substr(1));
    }

    bool search(string word){
        return searchHelper(root, word);
    }

    void deletionHelper(TrieNode* root, string word){
        if(word.length() == 0){
            root -> isTerminal = false;
            return;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            return;
        }

        return deletionHelper(child, word.substr(1));
    }

    void deletion(string word){
        deletionHelper(root, word);
    }

    TrieNode* completeDeletionHelper(TrieNode* root, string word){
        if(word.length() == 0){            
            root -> isTerminal = false;

            bool isEmpty = true;
            for(int i=0; i<26; i++){
                if(root -> children[i] != NULL){
                    isEmpty = false;
                    break;
                }
            }

            if(isEmpty){
                delete root;
                return NULL;
            }

            return root;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            return root;
        }

        child = completeDeletionHelper(child, word.substr(1));

        return root;
    }

    void completeDeletion(string word){
        completeDeletionHelper(root, word);
    }

    int getChildCount(TrieNode* temp)  {
        int count = 0;

        for(int i=0; i<26; i++) {
            if(temp->children[i] != NULL)   
                count++;
        }
        return count;
    }

    void longestCommonPrefix(string input, string &res) {
        TrieNode* temp = root;

        //traverse over input string
        for(int i=0; i<input.length(); i++) {
            
            //fetch current character
            char ch = input[i];

            if(getChildCount(temp) == 1 && temp->isTerminal == false) {
                //include character in answer string
                res.push_back(ch);

                //root ko aage badhao
                int index = ch - 'a';
                temp = temp->children[index];
            }
            else {
                break;
            }

            if(temp->isTerminal) 
                break;
        }
    }

};

int main(){
    Trie* trie = new Trie();
    trie -> insert("code");
    trie -> insert("coding");
    trie -> insert("codemonk");
    trie -> insert("coder");
    trie -> insert("codee");

    // trie -> deletion("code");
    // trie -> completeDeletion("code");

    // cout<<trie -> search("code")<<endl;

    // string str = "";
    // trie -> longestCommonPrefix("code", str);
    // cout<<str;

}