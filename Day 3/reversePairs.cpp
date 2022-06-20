int merge(vector<int> &v, int low, int mid, int high)
{
    vector<int> temp;
    int c = 0;
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (v[i] > 2LL * v[j])
        {
            c += mid + 1 - i;
            j++;
        }
        else
        {
            i++;
        }
    }
    i = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (v[i] <= v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(v[i]);
        i++;
    }
    while (j <= high)
    {
        temp.push_back(v[j]);
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        v[i] = temp[k++];
    }
    temp.clear();
    return c;
}
int mergeSort(vector<int> &v, int low, int high)
{
    int count = 0;
    if (low < high)
    {
        int mid = (low + high) / 2;
        count += mergeSort(v, low, mid);
        count += mergeSort(v, mid + 1, high);
        count += merge(v, low, mid, high);
        return count;
    }
    return 0;
}
int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}