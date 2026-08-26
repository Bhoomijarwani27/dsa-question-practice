class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0;

        int bestStart = -1;
        int bestLen = INT_MAX;

        for (int right = 0; right < n; right++) {

            if (s[right] == '1')
                ones++;

            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            if (ones == k) {

                // Remove useless leading zeroes
                while (s[left] == '0')
                    left++;

                int len = right - left + 1;

                if (len < bestLen ||
                    (len == bestLen &&
                     (bestStart == -1 ||
                      s.compare(left, len, s, bestStart, bestLen) < 0))) {

                    bestStart = left;
                    bestLen = len;
                }
            }
        }

        return bestStart == -1 ? "" : s.substr(bestStart, bestLen);
    }
};