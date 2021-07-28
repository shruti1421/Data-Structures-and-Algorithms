//https://leetcode.com/problems/maximum-compatibility-score-sum/
class Solution {
public:
    int cal(vector<vector<int>> &mentors, vector<vector<int>> &students)
    {
      int n=students.size(),m=students[0].size(),sum=0;
        
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              sum+=(students[i][j]==mentors[i][j])?1:0;
          }
      }
        
      return sum;
    }
    
    int permutation(vector<vector<int>>&mentors, vector<vector<int>>&students, int index, int maxSum)
    {
        if(index==mentors.size())
        {
            maxSum=max(maxSum,cal(mentors,students));
            return maxSum;
        }
        
        for(int i=index;i<mentors.size();i++)
        {
            swap(mentors[i],mentors[index]);
            
            maxSum=max(maxSum,permutation(mentors,students,index+1,maxSum));
            
            swap(mentors[i],mentors[index]);
        }
        
        return maxSum;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n=students.size(),maxSum=INT_MIN;
        
        maxSum=permutation(mentors,students,0,maxSum);
        
        return maxSum;
    }
};