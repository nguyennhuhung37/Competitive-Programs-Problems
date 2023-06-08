#include<bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE 26

int P, S;

struct Node{
    Node *child[ALPHABET_SIZE];
    set<char> save;
    int n_common;
};

Node *newMode(){
    Node *new_Node = new Node;
    for(int i = 0; i < 26; i++){
        new_Node->child[i] = nullptr;
    }
    new_Node->n_common = 0;
}

void addWord(Node *root, string s){
    Node *tmp = root;
    for(int i = 0; i < s.size(); i++){
        int ch = s[i] - 'a';
        if(!tmp->child[ch]){
            tmp->child[ch] = newMode();
            tmp->save.insert(s[i]);
        }
        tmp = tmp->child[i];
        tmp->n_common++;
    }
}

int main(){
    while(cin >> P >> S)
    {
        if(!P) break;
        Node *root_P = newMode();
        for(int i = 1; i <= P; i++){
            string s; cin >> s;
            addWord(root_P, s);
        }
        Node *root_S = newMode();
        for(int i = 1; i <= S; i++){
            string s; cin >> s;
            addWord(root_P, s);
        }
    }
    return 0;
}
