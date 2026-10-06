class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};

        int n=grid.size(),m=grid[0].size();

        vector<vector<int>>visit(n,vector<int>(m,0));

        queue<pair<int,int>>q;
        vector<vector<int>>dist(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    visit[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int a=dx[k]+it.first;
                int b=dy[k]+it.second;
                if(a>=0 && a<n && b>=0 && b<m && visit[a][b]==0 && grid[a][b]==1){
                     visit[a][b]=1;
                     dist[a][b]=1+dist[it.first][it.second];
                     q.push({a,b});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visit[i][j]==0) return -1;
                ans=max(ans, dist[i][j]);
            }
        }
        return ans; 
    }
};
