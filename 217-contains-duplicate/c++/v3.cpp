class Solution
{
    /*
    STL Sort and Adjacent Find
    This solution employs standard C++ library algorithms to achieve a concise and
    idiomatic implementation. It includes an initial guard clause to handle trivial
    cases where the vector size is less than 2.

    The algorithm sorts the input vector, ensuring that any duplicate values become
    neighbors. Instead of writing a raw loop, it utilizes std::adjacent_find. This
    specific STL algorithm scans the range for the first occurrence of two
    consecutive elements that satisfy the provided equality lambda. If the iterator
    returned corresponds to cend(), no adjacent duplicates were found.

    Complexity Analysis

    Time Complexity: O(NlogN) The sorting step is the bottleneck. While
    std::adjacent_find is linear (O(N)), it is overshadowed by the sorting cost.

    Space Complexity: O(logN) This approach is memory-efficient as it modifies the
    input vector in place. The space complexity arises solely from the stack frames
    required by std::sort (typically Introsort).
    */
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return false;
        }
        std::sort(nums.begin(), nums.end());
        auto duplicate_it = std::adjacent_find(
            nums.cbegin(), nums.cend(),
            [](const int &a, const int &b)
            { return a == b; });
        return duplicate_it != nums.cend();
    }
};