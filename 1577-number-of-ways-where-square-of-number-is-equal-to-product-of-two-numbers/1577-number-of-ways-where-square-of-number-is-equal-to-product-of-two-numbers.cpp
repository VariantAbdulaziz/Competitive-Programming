class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), ans = 0;
        map<long, int> type_one, type_two;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                type_one[1L*nums1[i]*nums1[j]]++;
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=i+1; j<m; j++) {
                type_two[1L*nums2[i]*nums2[j]]++;
            }
        }
        for(int i=0; i<n; i++) {
            if(type_two.find(1L*nums1[i]*nums1[i]) != type_two.end()) {
                ans += type_two[1L*nums1[i]*nums1[i]];
            }
        }
        for(int i=0; i<m; i++) {
            if(type_one.find(1L*nums2[i]*nums2[i]) != type_one.end()) {
                ans += type_one[1L*nums2[i]*nums2[i]];
            }
        }
        return ans;
    }
};