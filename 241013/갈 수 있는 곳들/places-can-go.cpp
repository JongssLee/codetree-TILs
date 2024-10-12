#include <iostream>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

int board[109][109];
int visited[109][109];

int dx[4] = {1, 0,-1,0};
int dy[4] = {0,1,0,-1};
int main() {
    int n,k;
    cin>>n>>k;
    int res = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<k;i++){
        int x, y;
        cin>>x>>y;

        queue<pair<int, int>>Q;
        if(visited[x][y]==0){
            Q.push({x,y});
            visited[x][y]=1;
        }
        while(!Q.empty()){
            auto cur = Q.front();
            res++;
            Q.pop();

            for(int dir=0;dir<4;dir++){
                int nx = cur.first+dx[dir];
                int ny = cur.second+dy[dir];

                if(nx<=0||nx>n||ny<=0||ny>n) continue;

                if(board[nx][ny]==0&&visited[nx][ny]==0){
                    Q.push({nx,ny});
                    visited[nx][ny]=1;
                }
            }
        }
        // cout<<res<<'\n';
    }
    cout<<res;
    return 0;
}