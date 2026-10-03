class Solution {
public:
    int numIslands(vector<vector<char>>& grid){
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1'){
                    count++;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i, j));
                    grid[i][j] = '0';

                    while(!q.empty()){
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();

                        
                        int dx[] = {-1, 1, 0, 0};
                        int dy[] = {0, 0, -1, 1};

                        for(int k = 0; k < 4; k++){
                            int x = new_i + dx[k];
                            int y = new_j + dy[k];

                            if(x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == '1'){
                                q.push(make_pair(x, y));
                                grid[x][y] = '0';
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};