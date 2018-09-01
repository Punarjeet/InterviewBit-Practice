/*
Problem Name : majority Element
Problem Statement : Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.
Example : 
Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. 
*/
/*class Solution{
public :
    int majorityElement(const vector <int> &) ;//find majority element which appears more then n/3 times where n is the size of vector
};
*/
int Solution::majorityElement(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int cnt = 1 ;
    int idx = 0; 
    for(int i = 1;  i < A.size() ; i++)
    {
        if(A[i] == A[idx])
        {
            cnt++;
        }
        else 
           cnt-- ;
        if(cnt == 0)
        {
            cnt = 1 ;
            idx = i;
        }
    }
    return A[idx] ; 
}

