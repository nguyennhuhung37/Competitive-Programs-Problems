#include<bits/stdc++.h>
using namespace std;
#define MAX 26

bool check = false;

struct Node{
    Node *child[MAX];
    int type;
};

Node *newNode(){
    Node *new_Node = new Node;
    for(int i = 0; i < MAX; i++){
        new_Node->child[i] = nullptr;
    }
    new_Node->type = 0;
    return new_Node;
}

void addWord(Node *root, string s){
    Node *tmp = root;
    for(int i = 0; i < s.size(); i++){
        int pos = s[i] - 'a';
        if(!tmp->child[pos]){
            tmp->child[pos] = newNode();
        }
        tmp = tmp->child[pos];
        if(tmp->type == 2 && !check){
            check = true;
        }
        if(i < s.size() - 1){
            tmp->type = 1;
        }
        else{
            if(tmp->type == 1 && !check){
                check = true;
            }
            else{
                tmp->type = 2;
            }
        }
    }
}

int main(){
    int N; cin >> N;
    Node *root = newNode();
    for(int i = 1; i <= N; i++){
        string s; cin >> s;
        addWord(root, s);
    }
    if(!check) cout << "non vulnerable";
    else cout << "vulnerable";
    return 0;
}
