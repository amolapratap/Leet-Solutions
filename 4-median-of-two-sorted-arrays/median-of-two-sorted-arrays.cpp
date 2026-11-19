class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total_length = m + n;
        int mid = (m + n) / 2;
        int prev=0, curr = 0;

        int i=0, j=0, k = 0;

        while (k <= mid) {
            prev = curr;
            if (i < m and (j >= n or nums1[i] <= nums2[j])) {
                curr = nums1[i];
                i += 1;
            }

            else {
                curr = nums2[j];
                j += 1;
            }

            k++;
        }

        if (total_length % 2 == 1) {
            return curr;
        } else {
            return (prev + curr) / 2.0;
        }
    }
};