int nCr(int n, int r)
{
    double res = 1;
    for (int i = 1; i <= r; i++)
        res = res * (n - r + i) / i;
    return (int)res;
}
int uniquePaths(int m, int n)
{
    int p = m + n - 2;

    return nCr(p, m - 1);
}