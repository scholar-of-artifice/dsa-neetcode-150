class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /*
        Brute Force Iteration
        This solution implements the straightforward "brute force" approach to
        the Two Sum problem. It exhaustively checks every unique pair of numbers
        to see if they add up to the target.

        The algorithm utilizes nested loops with iterators. The outer loop
        (iter_a) selects a number, and the inner loop (iter_b) scans all
        subsequent numbers. If the sum *iter_a + *iter_b matches the target, the
        algorithm uses std::distance to convert the iterators back into integer
        indices and returns them immediately. This method guarantees finding a
        solution if one exists, but performs redundant work by recalculating
        sums.

        Complexity Analysis

        Time Complexity: O(n^2)
        The nested loops result in a triangular number of comparisons
        ( (n(n−1))) / 2 ). As the input size n grows, the execution
        time increases quadratically, making this inefficient for large
        datasets.

        Space Complexity: O(1) This approach is memory efficient. It
        operates entirely in-place using only a few loop variables and
        iterators, requiring no auxiliary data structures.
        */
        for (auto iter_a = nums.cbegin(); iter_a < nums.cend(); iter_a++)
        {

            for (auto iter_b = iter_a + 1; iter_b < nums.cend(); iter_b++)
            {
                const auto total = *iter_a + *iter_b;

                if (total == target)
                {
                    const size_t i = std::distance(nums.cbegin(), iter_a);
                    const size_t j = std::distance(nums.cbegin(), iter_b);

                    return {static_cast<int>(i), static_cast<int>(j)};
                }
            }
        }
        return {}; // assume there is always a solution... according to problem
    }
};