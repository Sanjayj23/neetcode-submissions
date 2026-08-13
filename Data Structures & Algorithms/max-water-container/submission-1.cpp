class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n= heights.size();
        int start= 0;
        int end= n-1;
        int area= 0;
        while(start<end){
            int a;
            if(heights[start]<heights[end]){
                a= (end-start)*(heights[start]);
                start++;
            }
            else{
                a= (end-start)*(heights[end]);
                end--;
            }
            area= max(area, a);
        }
        return area;
    }
};
