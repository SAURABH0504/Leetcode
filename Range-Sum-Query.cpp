QuestionLink -> https://leetcode.com/problems/range-sum-query-2d-immutable/
class NumMatrix {
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& ma) {
        matrix = ma;
        int n = matrix.size();
        int m = matrix[0].size();
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(i > 0 && j > 0){
                        matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1]; 
                    }else if(i > 0){
                        matrix[i][j] += matrix[i-1][j];
                    } else if(j > 0){
                        matrix[i][j] += matrix[i][j-1];
                    }
                }
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = matrix[row2][col2];
        if(col1 > 0 && row1 > 0){
           sum = sum - matrix[row2][col1-1] - matrix[row1-1][col2] + matrix[row1-1][col1-1];
        }else if(col1 > 0){
            sum -= matrix[row2][col1-1];
        } else if(row1 > 0){
            sum -= matrix[row1-1][col2];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */