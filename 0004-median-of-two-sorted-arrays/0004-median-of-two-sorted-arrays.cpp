class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combined;
        combined.insert(combined.end(), nums1.begin(), nums1.end());
        combined.insert(combined.end(), nums2.begin(), nums2.end());
        
        sort(begin(combined), end(combined));
        int mod = combined.size() % 2;
        int x = (combined.size() - 1) / 2;
        int y = combined.size() / 2;
        return mod? combined[y]: (combined[x] + combined[y]) / 2.0;
    }
};