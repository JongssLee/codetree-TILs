#include <iostream>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    // Write your code here!
    for (int i=0; i<N-2;i++){
        for(int j=0;j<N-2;j++){
            int temp=0;
            temp+=
                grid[i][j]+grid[i][j+1]+grid[i][j+2] +
                grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2] +
                grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]
                ;
            ans = (ans<temp) ? temp : ans;
        }
    }
    cout<<ans;


    return 0;
}
