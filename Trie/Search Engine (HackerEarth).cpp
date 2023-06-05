#include<bits/stdc++.h>
#define ALPHABET_SIZE 26
using namespace std;

struct Node{
    struct Node *child[ALPHABET_SIZE];
    int maxValue;
};

struct Node *newNode(){
    struct Node *pNode = new struct Node;
    pNode->maxValue = -1;

    for(int i = 0; i < ALPHABET_SIZE; i++){
        pNode->child[i] = nullptr;
    }

    return pNode;
};

void addWord(struct Node *root, string s, int value){
    struct Node *tmp = root;

    for(auto x : s){
        int pos = x - 'a';
        if(!tmp->child[pos]){
            tmp->child[pos] = newNode();
        }

        tmp = tmp->child[pos];
        tmp->maxValue = max(tmp->maxValue, value);
    }
}

int getHighestMatching(struct Node *root, string s){
    struct Node *tmp = root;

    for(auto x : s){
        int pos = x - 'a';
        if(!tmp->child[pos]){
            return -1;
        }

        tmp = tmp->child[pos];
    }

    return tmp->maxValue;
}
int main(){
    int n, q, value;
    string s;
    cin >> n >> q;
    struct Node *root = newNode();
    while(n--)
    {
        cin >> s >> value;
        addWord(root, s, value);
    }
    while(q--)
    {
        cin >> s;
        cout << getHighestMatching(root, s) << endl;
    }
    return 0;
}
