#include<iostream>
#include<vector>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int ans = 1;

    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << "Length of LIS: " << lengthOfLIS(nums) << endl;
    return 0;
}