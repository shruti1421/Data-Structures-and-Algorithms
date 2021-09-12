//https://www.youtube.com/watch?v=ERAHSoAk2Yo&t=5s
If there is an array of size n and query q
each query has a range from i to j and k value which we need to add to all the elements in the range i and j inclusive
at the end we need to print the final value of all elements in the array.

By naive method, in which we update all the values lying in the range one by one will require O(n*q) time.
But we can solve this problem by just updating ith element(increment by k) and j+1th element(decrement by k) 
at the end calculate the presum of array.