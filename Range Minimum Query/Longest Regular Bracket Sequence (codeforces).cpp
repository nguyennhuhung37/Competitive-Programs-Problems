#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005

string s;
int c[MAX], d[MAX], n;
//d[j] = position of corresponding open bracket, or -1 if closing bracket doesn't belong to any regular bracket sequence.
//c[j] = position of earliest opening bracket, such that substring s(c[j], j) (both boundaries are inclusive) is a regular bracket sequence.
stack<int> st;

int main(){
    cin >> s;
    n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            if(st.empty()){
                d[i] = -1;
                c[i] = -1;
            }
            else{
                int u = st.top(); st.pop();
                d[i] = u;
                if(s[d[i]-1] == ')' && c[d[i]-1] != -1){
                    c[i] = c[d[i]-1];
                }
                else{
                    c[i] = d[i];
                }
            }
        }
    }
    int ans = 0, cnt = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '('){
            continue;
        }
        if(c[i] == -1){
            continue;
        }
        else{
            int leng = i - c[i] + 1;
            if(leng > ans){
                ans = leng;
                cnt = 1;
            }
            else if(leng == ans){
                cnt++;
            }
            i = c[i];
        }
    }
    if(ans == 0) cout << "0 1";
    else cout << ans << " " << cnt;
    return 0;
}
