vector<int> majorityElement(vector<int> &nums)
{
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    int life1 = 0;
    int life2 = 0;
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
            life1++;
        else if (nums[i] == el2)
            life2++;
        else if (life1 == 0)
        {
            el1 = nums[i];
            life1 = 1;
        }
        else if (life2 == 0)
        {
            el2 = nums[i];
            life2 = 1;
        }
        else
        {
            life1--;
            life2--;
        }
    }
    int c1 = 0, c2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
            c1++;
        if (nums[i] == el2)
            c2++;
    }
    if (c1 > n / 3)
        ans.push_back(el1);
    if (c2 > n / 3)
        ans.push_back(el2);
    return ans;
}