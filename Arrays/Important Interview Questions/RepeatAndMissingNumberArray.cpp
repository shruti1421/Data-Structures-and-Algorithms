//https://www.interviewbit.com/problems/repeat-and-missing-number-array/
//O(N) time O(1) space
vector<int> Solution::repeatedNumber(const vector<int> &V) {
       long long sum = 0;
       long long squareSum = 0;
       long long temp;
       for (int i = 0; i < V.size(); i++) {
           temp = V[i];
           sum += temp;
           sum -= (i + 1);
           squareSum += (temp * temp);
           squareSum -= ((long long)(i + 1) * (long long)(i + 1));
       }
       // sum = A - B
       // squareSum = A^2 - B^2 = (A - B)(A + B)
       // squareSum / sum = A + B
       squareSum /= sum;

       // Now we have A + B and A - B. Lets figure out A and B now. 
       int A = (int) ((sum + squareSum) / 2);
       int B = squareSum - A;

       vector<int> ret;
       ret.push_back(A);
       ret.push_back(B);
       return ret;
    }