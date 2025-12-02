class Solution
{
    /*
    Iterative Early Exit
    This implementation refines the previous hash set approach by utilizing an early
    exit strategy.

    Instead of constructing the entire set upfront, the algorithm iterates through
    the input vector one element at a time. For each number, it performs a lookup in
    the obs_set. If the number is already present, the function immediately returns
    true, halting execution without processing the remaining elements. If the number
    is not found, it is added to the set, and the loop continues. This offers a
    performance advantage in cases where duplicates appear early in the vector.

    Complexity Analysis

    Time Complexity: O(n) In the worst case (no duplicates or duplicate at the very
    end), it iterates through all n elements. Operations find and insert on an
    unordered_set are O(1) on average.

    Space Complexity: O(n) The hash set grows linearly with the input size, storing
    up to n distinct integers in the worst case (no duplicates).
    */
public:
    bool containsDuplicate(vector<int> &nums)
    {
        std::unordered_set<int> obs_set;
        for (const auto &n : nums)
        {
            if (obs_set.find(n) == obs_set.end())
            {
                obs_set.insert(n);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};