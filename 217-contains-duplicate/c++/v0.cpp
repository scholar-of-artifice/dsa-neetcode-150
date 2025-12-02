class Solution
{
    /*
    Hash Set Deduction
    This algorithm leverages the unique-element property of a hash set
    (std::unordered_set) to identify duplicates.

    It constructs a set directly from the input vector's iterator range. During this
    construction, any duplicate values found in the vector are implicitly discarded,
    as sets cannot contain repeated keys. Finally, the algorithm compares the size
    of the resulting set to the size of the original vector. If the set size is
    smaller, duplicates were present, and the function returns true.

    Complexity Analysis

    Time Complexity: O(n) Constructing the unordered_set requires iterating through
    the vector once. Inserting each element into the hash table takes O(1) on
    average. Note: In the rare worst-case scenario (many hash collisions), this
    could degrade to O(n^2).

    Space Complexity: O(n) In the worst case (no duplicates), the hash set must
    store all n elements from the input vector.
    */
public:
    bool containsDuplicate(vector<int> &nums)
    {
        std::unordered_set<int> nums_set(nums.begin(), nums.end());
        return nums_set.size() != nums.size();
    }
};