class Solution {
public:
    string result = "";

    bool solve(string &curr, vector<int>& count, string& target,
               int i, bool greater, int n, char middle) {

        int half = n / 2;

        if (i == half) {

            string left = curr;
            string rev = left;
            reverse(rev.begin(), rev.end());

            string palindrome = left;

            if (n % 2)
                palindrome += middle;

            palindrome += rev;

            if (palindrome > target) {
                result = palindrome;
                return true;
            }

            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {

            if (count[ch - 'a'] == 0)
                continue;

            if (!greater && ch < target[i])
                continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if (solve(curr, count, target, i + 1,
                      isGreater, n, middle))
                return true;

            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        vector<int> count(26, 0);

        for (char ch : s)
            count[ch - 'a']++;

        // Check whether a palindrome is possible
        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (count[i] % 2) {
                odd++;
                middle = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        // Build only the left half
        vector<int> halfCount(26);

        for (int i = 0; i < 26; i++)
            halfCount[i] = count[i] / 2;

        string curr;

        solve(curr, halfCount, target, 0, false, n, middle);

        return result;
    }
};