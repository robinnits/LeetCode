class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int drow[] = {-1, +1, 0, 0, -1, +1, -1, +1};
        int dcol[] = {0, 0, -1, +1, -1, -1, +1, +1};
        queue<pair<pair<int, int>, int>> q;
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        q.push({{0, 0}, 1});
        vis[0][0] = 1;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int d = q.front().second;
            q.pop();
            if(row == n-1 && col == n-1) return d;
            for(int i= 0; i<8; i++) {
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow >=0 && nrow <n && ncol >=0 && ncol <n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, d+1});
                }
            }
        }
        return -1;
    }
};