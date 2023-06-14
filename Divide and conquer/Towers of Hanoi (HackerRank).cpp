#include<bits/stdc++.h>
using namespace std;

int n;

void Move(int n, string sourceCol, string middleCol, string sinkCol){
    if(n == 1){
        cout << "MOVE " << sourceCol << " " << sinkCol << endl;
        return;
    }
    Move(n - 1, sourceCol, sinkCol, middleCol);
    Move(1, sourceCol, middleCol, sinkCol);
    Move(n - 1, middleCol, sourceCol, sinkCol);
}

int main(){
    cin >> n;
    string sourceCol = "T1", middleCol = "T2", sinkCol = "T3";
    Move(n, sourceCol, middleCol, sinkCol);
    return 0;
}
