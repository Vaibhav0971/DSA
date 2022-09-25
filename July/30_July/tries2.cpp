#include<iostream>
#include<vector>

using namespace std;

class TrieNode {
    public:
        char data;
        bool isTerminal;
        TrieNode* children[26];

        TrieNode(char d) {
            this->data = d;

            isTerminal = false;

            for(int i=0; i<26; i++) {
                children[i] = NULL;
            } 
        }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');
        }

        void insertHelper(TrieNode* root, string word) {
            //base case
            if(word.length() == 0) {
                root->isTerminal = true;
                return ;
            }

            //current character fetch = 
            char ch = word[0];
            //mapping character to an index integer
            int index = ch - 'a';

            TrieNode* child;

            //2 cases exists
            //the alphabet is already present
            // alphabet is absent

            if(root->children[index] != NULL) {
                //present case-> child pr pohoch jao
                child = root->children[index];
            }
            else {
                //absent case-> child create and link
                child = new TrieNode(ch);
                root->children[index] = child;
            }

            //Recursion will take care of insertion of remaining string
            insertHelper(child, word.substr(1));
        }

        void insert(string word) {
            insertHelper(root, word);
            cout << word << " -> Insert successful " << endl;
        }

        void getNames(TrieNode* curr, string prefix, vector<string>& temp) {
            //base case
            if(curr->isTerminal) {
                temp.push_back(prefix);
                
            }
            for(char ch = 'a'; ch<='z'; ch++) {
                TrieNode* next = curr->children[ch-'a'];

                //found
                if(next != NULL) {
                    prefix.push_back(ch);
                    //recursion sambhal lega 
                    getNames(next, prefix, temp);
                    //backtrack
                    prefix.pop_back();
                }
            }
        }

        vector<vector<string> > getAnswer(string word) {

            TrieNode* prev = root;
            vector<vector<string> > answer;
            string prefix = "";

            for(int i=0; i<word.length(); i++) {
                char lastCh = word[i];

                prefix.push_back(lastCh);

                TrieNode* curr = prev->children[lastCh-'a'];

                //not found
                if(curr == NULL) {
                    break;
                }
                else {
                    //found
                    vector<string> tempAns;
                    getNames(curr, prefix, tempAns);

                    answer.push_back(tempAns);
                 
                    prev = curr;
                }
            }
            return answer;
        }
};


vector<vector<string> > solve(vector<string> &contactList, string query) {
    //step1: create trie
    Trie* t = new Trie();

    //step2:insert all contact in trie
    for(int i=0; i<contactList.size(); i++) {
        string str = contactList[i];
        t->insert(str);
    }

    //step3: getAnswer call
    return t->getAnswer(query);

}


int main() {

    vector<string> contacts;
    contacts.push_back("geeks");
    contacts.push_back("gee");
    
    string query = "geeku";

    vector<vector<string> > answer = solve(contacts, query);

    cout<< endl << "Printing the answer " << endl << endl;

    for( int i=0; i<answer.size() ; i++) {
        for(int j =0; j<answer[i].size(); j++) {
            cout << answer[i][j] << ", ";
        }cout << endl << endl ;
    }


    return 0;
}
