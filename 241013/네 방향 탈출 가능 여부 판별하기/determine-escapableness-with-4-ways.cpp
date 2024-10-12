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
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >>board[i][j];
        }
    }
    queue<pair<int, int>> Q;
    Q.push({0,0});
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();

        for(int dir =0;dir<4;dir++){
            int nx = cur.first+dx[dir];
            int ny = cur.second+dy[dir];

            if(nx<0||nx>=n||ny<0||ny>=m)
                continue;
            if(board[nx][ny]==1 && visited[nx][ny]==0){
                Q.push({nx,ny});
                visited[nx][ny]=1;
                if(nx==n-1 && ny==m-1){
                    cout<<'1';
                    return 0;
                }
            }
        }
    }
    cout<<'0';
    return 0;
}