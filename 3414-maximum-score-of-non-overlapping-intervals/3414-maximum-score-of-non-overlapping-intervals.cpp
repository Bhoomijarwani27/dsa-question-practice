class Solution {
public:
    int n; 
    vector<int>nextIdx;

        
    struct Node {
        long long score = 0;
        vector<int>idxs;
    };

    vector<vector<Node>> t;

    int findNext(const vector<vector<int>> & intervals, int r){
        int lo = 0, hi = n - 1;
        int result = n;
        while(lo <= hi){
            int mid = lo + (hi - lo) /2;
            if(intervals[mid][0] > r){
                result = mid;
                hi = mid - 1;
            }else {
                lo = mid + 1;
            }
        }
         return result;
    }

    bool isLexicographicallySmaller(const vector<int>& a, const vector<int>& b) {
        vector<int> sortedA = a;
        vector<int> sortedB = b;
        sort(sortedA.begin(), sortedA.end());
        sort(sortedB.begin(), sortedB.end());
        return sortedA < sortedB;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end());

         nextIdx.resize(n);
        for (int i = 0; i < n; i++) {
            int r = intervals[i][1];
            nextIdx[i] = findNext(intervals, r);
        }

         const int K = 4;
        t.assign(n + 1, vector<Node>(K + 1));

             for (int i = n - 1; i >= 0; i--) {
            int weight = intervals[i][2];
            int idx    = intervals[i][3];
            int j      = nextIdx[i];

            for (int k = 1; k <= K; k++) {
                Node skip = t[i + 1][k];
                Node temp = t[j][k - 1];

                Node take;
                take.score = temp.score + weight;
                take.idxs  = temp.idxs;
                take.idxs.push_back(idx); 


               Node result;
                if (skip.score > take.score) {
                    result = move(skip);
                } else if (skip.score < take.score) {
                    result = move(take);
                } else {
                    
                    if (isLexicographicallySmaller(skip.idxs, take.idxs)) {
                        result = move(skip);
                    } else {
                        result = move(take);
                    }
                }
                t[i][k] = move(result); 
            }
         }    
          vector<int> finalAns = t[0][K].idxs;
        sort(finalAns.begin(), finalAns.end());
        return finalAns;

    }
};