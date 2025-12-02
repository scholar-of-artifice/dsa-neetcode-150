class Solution
{
    /*
    Sort and Scan
    This approach eliminates the need for auxiliary data structures by modifying the
    input vector directly.

    The algorithm first sorts the vector using std::sort, which guarantees that any
    identical elements are placed in consecutive positions. Once sorted, it iterates
    through the vector, comparing each element *iter with its immediate neighbor
    *(iter + 1). If an adjacent pair matches, the function returns true. This method
    is useful when memory is strictly constrained, as it avoids the allocation
    overhead of a hash set.

    Complexity Analysis

    Time Complexity: O(nlogn) The dominant operation is the sorting step, which
    typically runs in O(nlogn) time. The subsequent linear scan is O(n).

    Space Complexity: O(logn) While this solution avoids allocating O(n) space for a
    set, std::sort usually requires O(logn) stack space for recursion. Technically,
    no significant auxiliary data structures are created on the heap.
    */
public:
    bool containsDuplicate(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        for (auto iter = nums.begin(); iter != nums.end(); ++iter)
        {
            if (iter + 1 != nums.end())
            {
                if (*(iter) == *(iter + 1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};