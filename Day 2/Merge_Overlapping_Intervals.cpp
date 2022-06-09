#include <bits/stdc++.h>
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    vector<int> curr = intervals[0];

    for (auto it : intervals)
    {
        if (it[0] <= curr[1])
        {
            curr[1] = max(curr[1], it[1]);
        }
        else
        {
            result.push_back(curr);
            curr = it;
        }
    }
    result.push_back(curr);
    return result;
}