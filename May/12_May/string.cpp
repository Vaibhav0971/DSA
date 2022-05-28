#include<iostream>
#include<cstring>
#include<map>
#include<vector>
// #include<stdio.h>

using namespace std;

bool isAnagram(string a, string b){
    map <char, int> mp;
    int size1 = a.length();
    int size2 = b.length();

    if(size1 != size2) return false;

    for(int i=0; i<size1; i++){
        mp[a[i]]++;
        mp[b[i]]--;
    }

    for(char i='a'; i<='z'; i++){
        if(mp[i] != 0) return false;
    }

    return true;
}

char flip(char ch){
    if(ch == '1') return '0';
    else return '1';    
}

int numberOfFlips(string str, char expected){
    int count = 0;
    for(int i=0; i<str.length(); i++){
        if(str[i] != expected) count++;

        expected = flip(expected);
    }
    return count;
}

bool checkRotation(string str1, string str2){
    string cncat = str1+str1;

    if(cncat.find(str2) == string::npos) return false;

    return true;
}

void reverseString(vector<char>& s) {
    for(int i=0; i<s.size()/2; i++){
        char temp = s[s.size()-1-i];
        s[s.size()-1-i] = s[i];
        s[i] = temp;
    }       
    for(int i=0; i<s.size(); i++){
        cout<<s[i]<<" ";
    }       
    cout<<endl;
}

bool checkPalindrome(string s){
    string temp = "";
    
    for(int i=0; i<s.length(); i++){
        if((tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z') || (s[i] >= '0' && s[i]<= '9')){
            temp.push_back(tolower(s[i]));
        }
    }
    
    for(int i=0; i<temp.length()/2; i++){
        if(temp[i] != temp[temp.length()-1-i]){
            return false;
        }
    }
    return true;
}

string pushWords(string str, int start, int end){
    string ans = "";
    for(int i=start; i<=end; i++){
        ans.push_back(str[i]);
    }
    return ans;
}

string reverseWords(string str){
    string temp = "";

    for(int i=str.length()-1, j=str.length()-1; i>=0, j>=0; i--){
        if(str[i] == ' '){
            temp += pushWords(str, i+1, j) + " ";
            i--;
            j--;
            j=i;
        }
        if(i == 0){
            temp += pushWords(str, i, j) + " ";
            i--;
            j--;
            j=i;
        }
    }

    cout<<temp<<endl;
    return temp;
}

char getMaxOccuringChar(string str){
    map<char, int> mp;
    int maxi = INT_MIN;
    char ch;
    
    for(int i=0; i<str.length(); i++){
        mp[str[i]]++;
    }
    
    for(auto i=mp.begin(); i!=mp.end(); i++){
        if(maxi == i->second){
            if((int)ch > (int)i->first) ch = i->first;
        }
        else if(maxi < i->second){
            maxi = i->second;
            ch = i->first;
        }        
    }
    return ch;
}

string replaceSpaces(string &str){
	for(int i=0; i<str.length(); i++){
		if(str[i] == ' '){
			str.replace(i, 1, "@40");
		}
	}	
	return str;
}

string removeOccurrences(string s, string part) {        
    while (s.find(part) != string::npos) {
        s.replace(s.find(part), part.length(), "");
    }         
    return s;        
}

int compress(vector<char>& chars) {
    string str="";
    int n=chars.size();
    for(int i=0;i<n;i++){
        int count=1;
        while(i+1<n && chars[i]==chars[i+1]){
            i++;
            count++;
        }
        if(count>1){
            str+=chars[i];
            str+=to_string(count);
        }
        else{
            str+=chars[i];
        }
    }
    for(int i=0;i<str.size();i++){
        chars[i]=str[i];
    }
    return str.size();
}

bool checkEqual(int count1[26], int count2[26]){
    for(int i=0; i<26; i++){
        if(count1[i] != count2[i]) return false;
    }
    return true;
}

bool checkPermutation(string s1, string s2) {
    int count1[26] = {0};
    
    for(int i=0; i<s1.length(); i++){
        int index = s1[i] - 'a';
        count1[index]++;
    }
    
    int i=0, windowSize = s1.length(), count2[26] = {0};
    
    while(i<windowSize && i<s2.length()){
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    
    if(checkEqual(count1, count2)) return true;
    
    while(i<s2.length()){
        int index = s2[i] - 'a';
        count2[index]++;
        
        index = s2[i-windowSize] - 'a';
        count2[index]--;
        
        i++;
        
        if(checkEqual(count1, count2)) return true;
    }
    
    return false;
}

string removeDuplicates(string s) {
    int i=0;
    while(i<s.length()){
        if(s[i]==s[i+1]){
            s.erase(i,2);
            if(i==0){
                continue;
            }
            else{
                i--;
            }
        }
        else i++;
    }
    return s;    
}   

int main(){
    // system("cls");

    // string str;
    // getline(cin, str);
    // cout<<str;

    // string a = "babbar";
    // string b = "raabbb";
    // cout<<isAnagram(a,b)<<endl;

    // string str = "0001010111";
    // cout<<min(numberOfFlips(str, '0'), numberOfFlips(str, '1'));

    // string str1 = "bbarba";
    // string str2 = "babbar";
    // cout<<checkRotation(str1, str2);

    // vector<char> arr = {'h','e','l','l','o'};
    // reverseString(arr);

    // cout<<checkPalindrome("A9b22Ba");

    // string str3 = "My name is vaibhav";
    // reverseWords(str3);

    // string str4 = "testsample";
    // cout<<getMaxOccuringChar(str4);

    // string str5 = "i love coding";
    // cout<<replaceSpaces(str5);    

    // string str6 = "axxxxyyyyb", str7 = "xy";
    // cout<<removeOccurrences(str6, str7);

    // vector<char> chars = {'a','a','b','b','c','c','c'};
    // cout<<compress(chars);

    // cout<<checkPermutation("ab", "eidbaooo");

    // cout<<removeDuplicates("abbaca");
    
}