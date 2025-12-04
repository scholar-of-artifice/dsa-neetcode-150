class Solution
{
    /*
    Frequency Map Comparison
    This modular solution determines if two strings are anagrams by comparing their
    character counts. It isolates the counting logic into a helper function,
    create_freq_map.

    For each input string, the algorithm iterates through the characters, populating
    a std::unordered_map that tracks the frequency of every unique character. The
    main function then compares these two generated maps using the == operator. If
    the maps are identical—meaning both strings contain the exact same characters
    with the exact same frequencies—the function returns true.

    Complexity Analysis

    Time Complexity: O(S+T) The algorithm must iterate through both string s (length
    S) and string t (length T) once to build the maps. The map comparison takes time
    proportional to the number of unique characters, which is negligible compared to
    the string iteration.

    Space Complexity: O(1) (or O(K)) Although the input grows, the space required
    for the maps is bounded by the size of the character set (e.g., 26 for English
    letters, 128 for ASCII). It does not grow indefinitely with the string length.
    */
public:
    std::unordered_map<char, size_t>
    create_freq_map(const std::string &s) const
    {
        std::unordered_map<char, size_t> fc_map;
        for (const auto &c : s)
        {
            if (fc_map.find(c) != fc_map.end())
            {
                fc_map[c] += 1;
            }
            else
            {
                fc_map.insert({c, 1});
            }
        }
        return fc_map;
    }

    bool isAnagram(string s, string t)
    {
        return this->create_freq_map(s) == this->create_freq_map(t);
    }
};