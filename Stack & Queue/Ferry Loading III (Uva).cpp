#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define fi first
#define se second
struct Car{
    int id, arriveTime;
};
int main()
{
    int c, n, t, m;
    int res[10005];
    cin >> c;
    while(c--)
    {
        cin >> n >> t >> m;
        queue<Car> q[2];
        for(int i = 1; i <= m; i++)
        {
            int x; string phia;
            cin >> x >> phia;
            if(phia == "left") q[0].push((Car) {i, x});
            else q[1].push((Car) {i, x});
        }
        int hien_tai = 0, bo = 0, lan_toi;
        int dang_doi = !q[0].empty() + !q[1].empty();
        while(dang_doi)
        {
            if(dang_doi == 1){
                lan_toi = (q[0].empty() ? q[1].front().arriveTime : q[0].front().arriveTime);
            }
            else{
                lan_toi = min(q[0].front().arriveTime, q[1].front().arriveTime);
            }
            hien_tai = max(hien_tai, lan_toi);
            int cnt = 0;
            while(!q[bo].empty()){
                Car car = q[bo].front();
                if(car.arriveTime <= hien_tai && cnt < n){
                    res[car.id] = hien_tai + t;
                    cnt++;
                    q[bo].pop();
                }
                else break;
            }
            hien_tai += t;
            bo = 1 - bo;
            dang_doi = !q[0].empty() + !q[1].empty();
        }
        for(int i = 1; i <= m; i++){
            cout << res[i] << endl;
        }
        if(c) cout << endl;
    }
    return 0;
}
