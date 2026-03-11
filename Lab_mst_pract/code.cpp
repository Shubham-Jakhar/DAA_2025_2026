class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        if(k==1) return arr;
        vector<int> ans;
        
        for(int i=0;i<=arr.size()-k;i++){
            int maxE = arr[i];
            for(int j=i;j<i+k;j++){
                maxE = max(arr[j],maxE);
            }
            ans.push_back(maxE);
        }
        return ans;
    }
};