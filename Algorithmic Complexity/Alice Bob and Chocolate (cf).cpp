#include<bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
int a[100001], n;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = n, bob = 0, alice = 0;
    while(l <= r)
    {
        if(alice == bob){
           alice += a[l];
           bob += a[r];
           if(l == r){
               l++;
               break;
           }
           else{
               l++; r--;
           }
        }
        else if(alice < bob){
            alice += a[l];
            l++;
        }
        else if(alice > bob){
            bob += a[r];
            r--;
        }
    }
    l--; r++;
    cout << l << " " << n - r + 1;
    return 0;
}
