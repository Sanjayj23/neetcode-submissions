class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size();
        int col= matrix[0].size();
        int low= 0;
        int m= row;
        int n= col;
        int high= (m*n)-1;
        while(low<=high){
            int mid= (high+low)/2;
            int row1=  mid/col;
            int col1= mid%col;
            if(matrix[row1][col1]>target){
                high= mid-1;
            }
            else if(matrix[row1][col1]<target){
                low= mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};