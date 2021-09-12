//VIMP
//https://www.interviewbit.com/problems/first-missing-integer/
//Do it in O(n) time and O(1) space
int Solution::firstMissingPositive(vector<int> &A) {
       int i=0,n1=A.size();  
   while(i<n1)
   {
          int correctPos=A[i]-1;
          while(A[i]>0&&A[i]<=n1&&A[i]!=A[correctPos])
          {
              swap(A[i],A[correctPos]);
              correctPos=A[i]-1;
          }      
          i++;
   }

   int ans=n1+1;

   for(int i=0;i<n1;i++)
   {
       if(A[i]!=(i+1))
       {
           ans=(i+1);
           break;
       }
   }

   
   return ans;
}
