#include<bits/stdc++.h>
using namespace std;
#define MAX 10

int t, n;
bool check = true;

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

void addPhone(Node *root, string s){
    Node *tmp = root;
    for(int i = 0; i < s.size(); i++){
        int ch = s[i] - '0';
        if(!tmp->child[ch]){
            tmp->child[ch] = newNode();
        }
        tmp = tmp->child[ch];
        if(i != s.size()-1){
            if(tmp->type == 2) check = false;
            else tmp->type = 1;
        }
        else{
            if(tmp->type == 1) check = false;
            tmp->type = 2;
        }
    }
}

int main(){
    cin >> t;
    while(t--)
    {
        check = true;
        Node *root = newNode();
        cin >> n;
        while(n--){
            string s; cin >> s;
            addPhone(root, s);
        }
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
