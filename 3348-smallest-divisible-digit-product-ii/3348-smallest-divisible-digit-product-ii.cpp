class Solution {
private:
    // Digit prime factors for [1..9]: {count_2, count_3, count_5, count_7}
    const array<array<int, 4>, 10> digitPrimes = {{
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    }};

    // Greedily finds the minimal-length, lexicographically smallest digit string to satisfy (c2, c3, c5, c7)
    string smallestEquivalent(int c2, int c3, int c5, int c7) {
        c2 = max(0, c2);
        c3 = max(0, c3);
        c5 = max(0, c5);
        c7 = max(0, c7);

        string bestDigits = "";
        bool found = false;

        // Try using 0 or 1 six (num_6) to balance 2s and 3s
        for (int num_6 = 0; num_6 <= 1; ++num_6) {
            int rem_2 = max(0, c2 - num_6);
            int rem_3 = max(0, c3 - num_6);

            int num_9 = rem_3 / 2;
            rem_3 %= 2;

            int num_8 = rem_2 / 3;
            rem_2 %= 3;

            int num_4 = rem_2 / 2;
            rem_2 %= 2;

            int num_3 = rem_3;
            int num_2 = rem_2;

            string digits = "";
            digits.append(num_2, '2');
            digits.append(num_3, '3');
            digits.append(num_4, '4');
            digits.append(c5, '5');
            digits.append(num_6, '6');
            digits.append(c7, '7');
            digits.append(num_8, '8');
            digits.append(num_9, '9');

            sort(digits.begin(), digits.end());

            if (!found || digits.length() < bestDigits.length() || 
               (digits.length() == bestDigits.length() && digits < bestDigits)) {
                bestDigits = digits;
                found = true;
            }
        }

        return bestDigits;
    }

public:
    string smallestNumber(string num, long long t) {
        // Step 1: Prime factorize t
        array<int, 4> counts = {0, 0, 0, 0}; // {2, 3, 5, 7}
        const int primes[4] = {2, 3, 5, 7};
        
        for (int i = 0; i < 4; ++i) {
            while (t % primes[i] == 0) {
                counts[i]++;
                t /= primes[i];
            }
        }

        // If t has prime factors greater than 7
        if (t > 1) return "-1";

        int c2 = counts[0], c3 = counts[1], c5 = counts[2], c7 = counts[3];
        int n = num.length();

        // Step 2: Compute prefix prime contributions
        vector<array<int, 4>> prefPrimes;
        prefPrimes.push_back({0, 0, 0, 0});
        
        int firstZero = n;
        for (int i = 0; i < n; ++i) {
            int d = num[i] - '0';
            if (d == 0) {
                firstZero = i;
                break;
            }
            auto dp = digitPrimes[d];
            prefPrimes.push_back({
                prefPrimes.back()[0] + dp[0],
                prefPrimes.back()[1] + dp[1],
                prefPrimes.back()[2] + dp[2],
                prefPrimes.back()[3] + dp[3]
            });
        }

        // Check if original 'num' already satisfies the condition
        if (firstZero == n) {
            auto total = prefPrimes[n];
            if (total[0] >= c2 && total[1] >= c3 && total[2] >= c5 && total[3] >= c7) {
                return num;
            }
        }

        // Step 3: Backtrack from right to left to find the longest valid prefix
        for (int i = min(n - 1, firstZero); i >= 0; --i) {
            auto pref = prefPrimes[i];
            int curDigit = num[i] - '0';

            for (int d = curDigit + 1; d <= 9; ++d) {
                auto dp = digitPrimes[d];
                int rem_c2 = c2 - (pref[0] + dp[0]);
                int rem_c3 = c3 - (pref[1] + dp[1]);
                int rem_c5 = c5 - (pref[2] + dp[2]);
                int rem_c7 = c7 - (pref[3] + dp[3]);

                string suffix = smallestEquivalent(rem_c2, rem_c3, rem_c5, rem_c7);
                int remLen = n - 1 - i;

                if ((int)suffix.length() <= remLen) {
                    string fullSuffix = string(remLen - suffix.length(), '1') + suffix;
                    return num.substr(0, i) + to_string(d) + fullSuffix;
                }
            }
        }

        // Step 4: If no same-length number works, grow length to n + 1 (or min needed)
        string minSuffix = smallestEquivalent(c2, c3, c5, c7);
        int targetLen = max(n + 1, (int)minSuffix.length());
        return string(targetLen - minSuffix.length(), '1') + minSuffix;
    }
};