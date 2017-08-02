int Solution::maxProduct(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more detai
    
        int mx_end = 1 ;
        int mn_end = 1 ;
        int cur_mx = 0 ;

        for(int i = 0 ; i < A.size() ; i++)
        {
            if(A[i] > 0)
            {
                mx_end *= A[i];
                mn_end = min(mn_end*A[i],1) ;
            }
            else if(A[i] == 0)
            {
                mx_end = 1 ;
                mn_end = 1 ;
            }
            else
            {
                int tmp  = mx_end ;
                mx_end = max(mn_end*A[i],1) ;
                mn_end = tmp*A[i];
            }
            if(cur_mx < mx_end)
            {
                cur_mx = mx_end ;
            }
        }
        if(cur_mx == 1) return 0 ;
        else
        return cur_mx ;
}
