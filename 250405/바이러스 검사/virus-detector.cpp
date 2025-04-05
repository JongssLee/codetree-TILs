#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>p;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        p.push_back(temp);
    }

    int l, s;
    cin>>l>>s;

    long long int res = 0;

    for(auto pp:p){
        res+=1;
        pp -= l;
        if (pp>0){
            res+= pp/s;
            if (pp%s != 0){
                res+=1;
            }
        }
    }
    cout<<res;
    return 0;
}