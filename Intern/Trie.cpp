#include<bits/stdc++.h>
using namespace std;
struct Trienode{
    Trienode* childern[26];
    bool isEndofWord;
    Trienode(){
        isEndofWord = false;
        for(int i=0; i<26; i++){
            childern[i] = nullptr;
        }
    }
};

void insert(Trienode* root, const string &word){
    Trienode* node = root;
    int idx;
    for(char c : word){
        idx = c -'a';
        if(node->childern[idx] == nullptr){
            node->childern[idx] = new Trienode();
        }
        node = node->childern[idx];
    }
    node->isEndofWord = true;
}

bool search(Trienode* root, const string &word){
    Trienode* node = root;
    int idx;
    for(auto c : word){
        idx = c - 'a';
        if(node->childern[idx] == nullptr) return false;
        node = node->childern[idx];
    }
    return node->isEndofWord;
}
int main(){
    Trienode* root = new Trienode();
    vector<string> S ={"goldman", "jpmc", "graviton", "microsoft", "samsung", "zepto", "sprinklr", "meesho", "amazon"};
    for(auto s : S) insert(root,s);
    string k;
    cin>>k;
    if(search(root,k)) cout<<"YES\n";
    else cout<<"NO\n";
}