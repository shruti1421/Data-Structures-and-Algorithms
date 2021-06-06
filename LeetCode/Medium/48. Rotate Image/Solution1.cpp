class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        vector<vector<bool>> f(matrix.size(),vector<bool>(matrix.size(),false));
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(f[i][j]==false){
                swap(matrix[i][j],matrix[j][i]);
                f[i][j]=true;
                f[j][i]=true;
                }
            }
        }
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size()/2;j++)
            {
                swap(matrix[i][j],matrix[i][matrix[i].size()-1-j]);
            }
        }
        
    }
};
