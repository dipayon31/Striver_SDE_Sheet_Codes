#include <bits/stdc++.h> 
#define ll long long
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	pair<int,int> p;
    ll m, r;
    ll xors = arr[0];ll s = arr[0]; ll sum;
    for(int i=1; i<n; i++){
        xors ^= arr[i];
        s += arr[i];
    }
    for(int i=1; i<= n; i++){
        xors ^= i;
        sum += i;
    }
    ll set_bit = xors & ~(xors-1);
    ll x= 0, y=0;
    for(int i=0; i<n; i++){
        if(arr[i] & set_bit)
            x = x^arr[i];
        else
            y = y^arr[i];
    }
    for(int i=1; i<=n; i++){
        if(i & set_bit)
            x = x^i;
        else
            y = y^i;
    }
        int x_count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i]==x)
            x_count++;
    }
    
    if (x_count==0)
        return {x, y};
    
    return {y, x};
}