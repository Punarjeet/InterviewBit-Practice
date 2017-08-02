
int Solution::longestSubsequenceLength(const vector<int> &A) {
   int n = A.size();
   int dp1[n];
   int i,j ;
   for(i = 0 ; i < n ; i++)
   {
       dp1[i] = 1 ; 
   }
   
   for(i = 1 ; i < n ; i++)
   {
       for(j = 0 ; j < i ; j++)
       {
           if(A[i] > A[j] && dp1[i] < dp1[j]+1)
           {
               dp1[i] = dp1[j] + 1 ;
           }
       }
   }
   int dp2[n];
   for(i = 0 ; i < n ; i++)
   {
       dp2[i] = 1 ;
   }
   for(i = n-2 ; i >= 0 ; i--)
   {
       for(j = n-1 ; j > i ; j--)
       {
           if(A[i] > A[j] && dp2[i] < dp2[j] + 1)
           {
               dp2[i] = dp2[j] + 1 ;
           }
       }
   }
   int mx = dp1[0] + dp2[0]-1;
   for(i = 1 ; i < n ; i++)
   {
       int tmp = dp1[i] + dp2[i] -  1 ;
       if(tmp > mx)
       {
           mx = tmp ;
       }
   }
   return (mx > 0) ? mx : 0 ;
}
