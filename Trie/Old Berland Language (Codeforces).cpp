#include <iostream>
#include <bits/stdc++.h>
#define maxn 1000001
#define MAX 2
using namespace std;
struct node
{
    struct node *child[MAX];
    int isblock;
    struct node *pre;
};
struct node *newNode()
{
    struct node *Node = new struct node;
    Node->isblock = 0;
    Node->pre = NULL;
    for (int i = 0; i < MAX; i++)
    {
        Node->child[i] = NULL;
    }
    return Node;
}
string ans[10001],s;
node *root = newNode();
bool add(int l){
    node *tmp = root;
    if (root->isblock == 1) return false;
    s = "";
    for (int i = 0; i < l; i++){
        int check_1 = -1;
        bool canmove = false;
        for (int j = MAX-1; j >= 0; j--){
            if (tmp->child[j] != NULL) {
                    if (tmp->child[j]->isblock == 0) {
                        s = s + (char)('0' + j);
                        tmp = tmp->child[j];
                        canmove = true;
                        break;
                    }
            }
            if (tmp->child[j] == NULL)
                check_1 = j;
        }
        if (!canmove){
            if (check_1 == -1){
                return false;
            }
			else
			{
			s = s + char('0' + check_1);

			tmp->child[check_1] = newNode();
			tmp->child[check_1]->pre = tmp;
			tmp = tmp->child[check_1];
			}
        }
    }
    tmp->isblock = 1;
    while (tmp != NULL){
        if (tmp->child[0] != NULL && tmp->child[1] != NULL)
        if (tmp->child[0]->isblock * tmp->child[1]->isblock == 1)
            tmp->isblock = 1;
        tmp = tmp->pre;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    pair<int, int> a[10000];
    for (int i = 0; i < n ; i++){
           int l;
           cin >> l;
           a[i] = {l,i};
    }
    sort(a, a + n);
    for (int i = 0; i < n ; i++){
        int l = a[i].first;
        if (add(l)== false) {
                cout << "NO";
                return 0;
        } else
        {
            ans[a[i].second] = s;
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
    return 0;
}

