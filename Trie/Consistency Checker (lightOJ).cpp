#include<bits/stdc++.h>
using namespace std;

bool check = true;

struct Node{
    Node *child[10];
    bool is_leafnode;
};

Node *newNode(){
    Node *new_Node = new Node;
    for(int i = 0; i < 10; i++){
        new_Node->child[i] = nullptr;
    }
    new_Node->is_leafnode = false;
    return new_Node;
}

void addWord(Node *root, string s){
    Node *tmp = root;
    for(int i = 0; i < s.size(); i++){
        int ch = s[i] - '0';
        if(!tmp->child[ch]){
            tmp->child[ch] = newNode();
        }
        tmp = tmp->child[ch];
        if(tmp->is_leafnode){
            check = false;
        }
        if(i == s.size() - 1){
            tmp->is_leafnode = true;
        }
    }
}

int main(){
    int t; cin >> t;
    vector<string> save;
    for(int id = 1; id <= t; id++)
    {
        check = true;
        save.clear();
        Node *root = newNode();
        int n; cin >> n;
        while(n--){
            string s; cin >> s;
            save.push_back(s);
        }
        sort(save.begin(), save.end());
        for(auto x : save){
            addWord(root, x);
        }
        if(check) cout << "Case " << id << ": YES" << endl;
        else cout << "Case " << id << ": NO" << endl;
    }
    return 0;
}
