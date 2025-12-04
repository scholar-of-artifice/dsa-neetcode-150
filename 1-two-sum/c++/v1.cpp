class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /*
        One-Pass Hash Map
        This efficient algorithm solves the "Two Sum" problem in a single pass by
        trading space for speed. It uses an std::unordered_map to remember the values
        and indices of the numbers it has already processed.

        For each element nums[i], the algorithm calculates the necessary complement
        (c=target−nums[i]). It then queries the map to see if c was seen previously.

        If found: The pair is complete. The function returns the stored index of the
        complement and the current index i.

        If not found: The current number and its index are added to the map, becoming a
        potential complement for future elements.

        Complexity Analysis

        Time Complexity: O(N) The algorithm iterates through the vector exactly once.
        Hash map lookups and insertions operate in O(1) time on average.

        Space Complexity: O(N) In the worst-case scenario (where the pair is found at
        the very end), the auxiliary map must store N−1 distinct elements.
        */
        std::unordered_map<int, int> obs_map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto c = target - nums[i];
            if (obs_map.find(c) == obs_map.end())
            {
                obs_map.insert(std::pair<int, int>(nums[i], i));
            }
            else
            {
                return {obs_map[c], i};
            }
        }
        return {}; // assume there is always a solution... according to problem
    }
};