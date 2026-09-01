class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
       int m = classroom.size();
       int n = classroom[0].size();

       int startR = 0;
       int startC = 0;

       vector<pair<int , int>> litter;

       for(int i = 0; i<m; i++){
         for(int j = 0; j < n; j++){
            if(classroom[i][j] == 'S'){
                startR = i;
                startC = j;
            }
            if(classroom[i][j] == 'L'){
                 litter.push_back({i, j});
             }
          }
        }
        int k = litter.size();

        if (k == 0) {
            return 0;
        }

        map<pair<int , int>, int> id;

        for(int i = 0; i < k; i++){
            id[litter[i]] = i;
        }
        int initialMask = (1 << k)-1;

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << k, false)
                )
            )
        );

        queue<tuple<int, int, int, int>> q;

        q.push({startR, startC, energy, initialMask});

        visited[startR][startC][energy][initialMask] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

             while (size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                if (mask == 0) {
                    return moves;
                }
                
                if (currEnergy == 0) {
                    continue;
                }

                 for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;
                   int newEnergy = currEnergy - 1;

                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    int newMask = mask;

                    if (classroom[nr][nc] == 'L') {

                        int bit = id[{nr, nc}];

                        newMask = newMask & ~(1 << bit);
                    }
                    
                     if (visited[nr][nc][newEnergy][newMask])
                        continue;

                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask
                    });
                }
            }

             moves++;


        }   
        return -1;
    }
};