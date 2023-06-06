#include<bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE 26

struct Node{
    Node *child[ALPHABET_SIZE];
    int n_common;
};

Node *newNode(){
    Node *new_Node = new Node;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        new_Node->child[i] = nullptr;
    }
    new_Node->n_common = 0;
    return new_Node;
}

void addWord(Node *root, string s){
    Node *tmp = root;
    for(int i = 0; i < s.size(); i++){
        int ch = s[i] - 'a';
        if(!tmp->child[ch]){
            tmp->child[ch] = newNode();
        }
        tmp = tmp->child[ch];
        tmp->n_common++;
    }
}

int findWord(Node * root, string s){
    Node *tmp = root;
    for(int i = 0; i < s.size(); i++){
        int ch = s[i] - 'a';
        if(!tmp->child[ch]){
            return 0;
        }
        tmp = tmp->child[ch];
    }
    return tmp->n_common;
}

int main(){
    Node *root = newNode();
    int n; cin >> n;
    while(n--)
    {
        string type, s; cin >> type >> s;
        if(type == "add"){
            addWord(root, s);
        }
        else{
            cout << findWord(root, s) << endl;
        }
    }
    return 0;
}
