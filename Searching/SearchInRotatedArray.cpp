//https://leetcode.com/problems/search-in-rotated-sorted-array/
//My solution
class Solution {
public:
    int binarySearch(vector<int> a, int start, int end, int n, int t)
    {
        int mid,f=0;
        
        while(start<=end&&start>=0&&end<n)
        {
            mid=(start+end)/2;
            
            if(a[mid]>t)
                end=mid-1;
            else if(a[mid]<t)
                start=mid+1;
            else if(a[mid]==t)
            {
                f=1;
                break;
            }
        }
        
        if(f==1)
            return mid;
        else
             return -1;
        
    }
    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1,mid=0;
        int n=nums.size(),index=0;
        if(nums[0]>nums[n-1]){
        while(start<=end&&start>=0&&end<nums.size())
        {
            mid=(start+end)/2;
            
            if((((mid-1>=0)&&nums[mid]<nums[mid-1])||mid-1<0)&&((mid+1<n&&nums[mid]<nums[mid+1])||mid+1>=n))
                break;
            if(nums[mid]>nums[0])
                start=mid+1;
            else if(nums[mid]<nums[0])
                end=mid-1;
            else
            {
                if(mid+1<n)
                    mid++;
                break;
            }
        }
        }
        
        
        if(target>=nums[0]&&mid!=0)
            index=binarySearch(nums,0,mid-1,n,target);
        else
            index=binarySearch(nums,mid,n-1,n,target);
        
        return index;
        
    }
};

//solution from editorial
class Solution {
public:
    
    int binarySearch(vector<int> a, int start, int end, int target)
    {
        int mid=(start+end)/2;
        
        while(start<=end)
        {
            mid=(start+end)/2;
            
            if(a[mid]>target)
                end=mid-1;
            else if(a[mid]<target)
                start=mid+1;
            else
                break;
        }
        
        if(a[mid]==target)
            return mid;
        else 
            return -1;
    }

    int search(vector<int>& nums, int target) {
           int n=nums.size(),start=0,end=n-1,mid;
        
           while(start<end)
           {
               mid=(start+end)/2;
               
               if(nums[mid]>nums[end])
                   start=mid+1;
               else if(nums[mid]<=nums[end])
                   end=mid;
               else break;
           }
        
           mid=end;
           mid--;
        
           end=n-1,start=0;
        
           int ans=0;
        
           if(mid>=0&&target<=nums[mid]&&target>=nums[start])
               ans=binarySearch(nums,start,mid,target);
           else if(target<=nums[end]&&(mid+1)<n&&target>=nums[mid+1])
               ans=binarySearch(nums,mid+1,end,target);
           else
               ans=-1;
        
        return ans;
        
    }
};