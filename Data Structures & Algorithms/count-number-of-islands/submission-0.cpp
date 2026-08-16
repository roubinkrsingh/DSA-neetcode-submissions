class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void dfs(vector<vector<char>>&grid,int i,int j,vector<vector<int>>&visit){
        visit[i][j]=1;
        for(int k=0;k<4;k++){
            int a=i+dx[k];
            int b=j+dy[k];
            if(a>=0 && a<grid.size() && b>=0 && b<grid[0].size() && visit[a][b]==0 && grid[a][b]=='1'){
                dfs(grid,a,b,visit);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visit[i][j]==0){
                    ans++;
                    dfs(grid,i,j,visit);
                }
            }
        }
        return ans; 
    }
};
