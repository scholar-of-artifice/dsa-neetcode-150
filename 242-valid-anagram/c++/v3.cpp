class Solution
{
    /*
    STL Functional Frequency Map
    This solution embraces a "modern C++" functional style, utilizing standard
    algorithms like std::for_each and std::all_of to manage control flow.

    It operates on a single std::unordered_map to track the net difference in
    character frequencies. After an initial length check (a crucial optimization),
    the algorithm increments counters for characters in string s and decrements them
    for string t. A distinct feature here is counts.reserve(s.length()), which
    attempts to pre-allocate bucket space to minimize expensive rehashing during
    insertion. Finally, std::all_of validates that every entry in the map has
    balanced out to exactly zero, confirming the strings are anagrams.

    Complexity Analysis

    Time Complexity: O(N) The algorithm performs linear passes over both strings (N)
    and a final constant-time pass over the map (limited by the alphabet size, e.g.,
    26).

    Space Complexity: O(1) Although a hash map is used, the space is bounded by the
    number of unique characters in the alphabet (constant K), not the length of the
    input string.
    */
public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        std::unordered_map<char, int> counts;
        counts.reserve(s.length());
        std::for_each(s.begin(), s.end(), [&](char c)
                      { counts[c]++; });
        std::for_each(t.begin(), t.end(), [&](char c)
                      { counts[c]--; });
        return std::all_of(counts.begin(), counts.end(),
                           [](const auto &pair)
                           { return pair.second == 0; });
    }
};