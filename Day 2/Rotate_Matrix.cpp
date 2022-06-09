#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ll long long int
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int p = 0, q = n-1;
    int k = 0, l = m-1;
    int i,j, temp;
    while(p<q && k<l){
        i = p;j = l;
        temp = mat[i][j];
        while(j>k){
            mat[i][j] = mat[i][j-1];
            j--;
        }
        while(i<q){
            mat[i][j] = mat[i+1][j];
            i++;
        }
        while(j<l){
            mat[i][j] = mat[i][j+1];
            j++;
        }
        while(i>p+1){
            mat[i][j] = mat[i-1][j];
            i--;
        }
        mat[i][j] = temp;
        p++;q--;
        k++;l--;
    }
}
void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>> v[i][j];
        }
    }
    rotateMatrix(v, n, m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--)
        solve();
   return 0;
}