//https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        
        int area=min(height[0],height[n-1])*(n-1);
        
        int left=0,right=n-1;
        
        while(left<right)
        {
            if(height[left]<height[right])
                left++;
            else if(height[right]<height[left])
                right--;
            else if(height[right-1]>height[left+1])
                right--;
            else
                left++;
            
            if(left<right)
            area=max(area,min(height[left],height[right])*(right-left));
        }
        
        return area;
    }
};