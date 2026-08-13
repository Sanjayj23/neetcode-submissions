class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1= m-1;
        int c= m+n-1;
        int p2= n-1;
        while(c>=0){
            if(p1==-1){
                while(p2>=0){
                    nums1[c]= nums2[p2];
                    c--;
                    p2--;
                }
            }
            if(p2==-1){
                break;
            }
            if(nums1[p1]>nums2[p2]){
                nums1[c]= nums1[p1];
                c--;
                p1--;
            }
            else{
                nums1[c]= nums2[p2];
                c--;
                p2--;
            }
        }
    }
};