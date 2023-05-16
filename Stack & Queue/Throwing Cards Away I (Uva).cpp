#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
int main(){
    while(cin >> n)
    {
        if(n == 0) break;
        if(n == 1){
            cout << "Discarded cards:" << endl;
            cout << "Remaining card: 1" << endl;
            continue;
        }
        queue<int > st;
        for(int i = 1; i <= n; i++) st.push(i);
        cout << "Discarded cards: ";
        while(st.size() >= 3){
            cout << st.front() << ", ";
            st.pop();
            int tmp = st.front();
            st.pop();
            st.push(tmp);
        }
        cout << st.front() << endl;
        st.pop();
        cout << "Remaining card: " << st.front() << endl;
    }
    return 0;
}
