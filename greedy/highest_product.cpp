#include <bits/stdc++.h>
using namespace std ;
/*
Problem Name : Highest Product
Problem Statement : Given an array of integers, return the highest product possible by multiplying 3 numbers from the array
Input : array of integers e.g {1, 2, 3}
Output : 3*2*1 = 6

Input : [0,-1,3,100,70,50]
Output : 100*70*50 = 350000


Approach : find the first three maximum  elements of the vector and first two minimum elements
suppose mx1 ,mx2,mx3 are first three maximum elements respectively and
mn1 and mn2 are the first 2 minimum elements
return max(mx1*mx2*mx3,mn1*mn2*mx1)
*/
/*class Solution{
public :
    int maxp3(vector<int>&);
};*
int Solution :: maxp3(vector <int> &A)
{
    int n = A.size();
  //  sort(A.begin(),A.end()); //sort the vector in non-decreasing order
    if(n < 3) return -1 ;
   // return max(A[n-1]*A[n-2]*A[n-3],A[0]*A[1]*A[n-1]);

    int mx1 = INT_MIN;
    int mx2 = INT_MIN;
    int mx3 = INT_MIN;
    int mn1 = INT_MAX ;
    int mn2 = INT_MAX ;

    for(int i = 0 ; i < n ; i++)
    {
        if(A[i] >mx1)
        {
            mx3 = mx2;
            mx2 = mx1 ;
            mx1 = A[i];
        }
        else if(A[i] > mx2)
        {
            mx3 = mx2 ;
            mx2 = A[i] ;
        }
        else if(A[i] > mx3)
        {
            mx3 = A[i];
        }

        if(A[i] < mn1)
        {
            mn2 = mn1 ;
            mn1 = A[i] ;
        }
        else if(A[i] < mn2)
        {
            mn2 = A[i] ;
        }
    }
   // cout << mx1 <<" " << mx2 << " " << mx3 <<" " << mn1 <<" " << mn2 << endl;
    return max(mx1*mx2*mx3,mn1*mn2*mx1) ;
}
/*int main()
{
    int t ;
    cin >> t ;
    Solution sol ;
    while(t--)
    {
        int n ;
        cin >> n ;
        vector <int> V(n);
        for(int i = 0 ; i < n ; i++)
        {
            cin >> V[i];
        }
        cout << sol.maxp3(V) << endl;
    }
    return 0;
}
*/
