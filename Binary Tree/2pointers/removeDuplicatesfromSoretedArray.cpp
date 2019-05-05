#include <bits/stdc++.h>
using namespace std;
const int MX = (int)1e5+7;
int arr[MX];


int main()
{
    int n;
    cin >> n; 
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    int i = 0,j = 1;
    while(j < n) 
    {
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
        j++;
    }
    for(int k = 0 ; k < i+1; k++){
        cout << arr[k] <<" ";
    }
    return 0;
}