#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 0;

        // For 1 <= nums[i] <= 10, max possible lcm is 2520 and max gcd is 10,
        // so lcm * gcd is at most 25200. Once prod exceeds this, it can never equal l * g.
        const __int128 MAX_RHS = 25200;

        for (int i = 0; i < n; ++i) {
            __int128 prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long x = nums[j];
                prod *= x;
                g = (g == 0) ? x : std::gcd(g, x);
                l = (l / std::gcd(l, x)) * x;

                __int128 rhs = static_cast<__int128>(l) * g;
                if (prod == rhs) {
                    ans = max(ans, j - i + 1);
                }
                if (prod > MAX_RHS) {
                    break;
                }
            }
        }

        return ans;
    }
};