class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    visit[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int a=dx[i]+it.first;
                int b=dy[i]+it.second;
                if(a>=0 && a<n && b>=0 && b<m && visit[a][b]==0 && grid[a][b]!=-1){
                    q.push({a,b});
                    visit[a][b]=1;
                    grid[a][b]=1+grid[it.first][it.second];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cout<<grid[i][j]<<" ";
            cout<<"\n";
        }
    }
};
