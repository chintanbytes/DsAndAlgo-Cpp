#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> v;
        int l1 = nums1.size();
        int l2 = nums2.size();
        
        int k=0;
        int i = 0;
        int j = 0;
        while(i<l1 && j<l2){
            if(nums1[i] <= nums2[j]){
                v.push_back(nums1[i++]);
            }
            else{
                v.push_back(nums2[j++]);
            }
        }

        while(i<=l1){
            v.push_back(nums1[i++]);
        }

        while(j<=l2){
            v.push_back(nums2[j++]);
        }
        
        auto length = v.size();
        return length%2 == 0 ? (double)(v[length/2] + v[length/2 - 1])/2 : v[length/2];

       
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    cout << s->findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
