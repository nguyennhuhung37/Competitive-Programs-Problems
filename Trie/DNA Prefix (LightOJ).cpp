#include<bits/stdc++.h>
using namespace std;

vector<char> dna = {'A', 'C', 'G', 'T'};
int res = 0;

struct Node{
    struct Node *child[4];
    int cnt;
};

Node *newNode(){
    Node *new_Node = new struct Node;
    new_Node->cnt = 0;
    for(int i = 0; i < 4; i++){
        new_Node->child[i] = nullptr;
    }
    return new_Node;
};

void addWord(Node *root, string s){
    Node *tmp = root;
    for(int i = 0; i < s.size(); i++){
        int ch = find(dna.begin(), dna.end(), s[i]) - dna.begin();
        int level = i + 1;
        if(!tmp->child[ch]){
            tmp->child[ch] = newNode();
        }
        tmp = tmp->child[ch];
        tmp->cnt++;
        res = max(res, tmp->cnt * level);
    }
}

int main(){
    int t; cin >> t;
    for(int id = 1; id <= t; id++)
    {
        res = 0;
        Node *root = newNode();
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            string s; cin >> s;
            addWord(root, s);
        }
        cout << "Case " << id << ": " << res << endl;
    }
    return 0;
}
