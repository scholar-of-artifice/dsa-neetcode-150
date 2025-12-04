class Solution
{
    /*
    Fixed-Size Frequency Array
    This algorithm optimizes the frequency counting approach by replacing the hash
    map with a fixed-size std::array. This avoids the overhead of hashing and
    dynamic memory allocation.

    The algorithm assumes the input consists of ASCII characters (mapped to indices
    0-127). It iterates through string s, incrementing the count for each
    character's ASCII value, and then iterates through string t, decrementing the
    counts. Finally, it scans the array to ensure every counter has returned to
    exactly zero. If any value is non-zero, the strings are not anagrams.

    Complexity Analysis

    Time Complexity: O(N) where N is the length of the strings. The algorithm
    performs a linear pass over both strings and a constant-time pass over the
    128-element array.

    Space Complexity: O(1) The storage required is constant (128 integers),
    regardless of how large the input strings become.
    */
public:
    bool isAnagram(string s, string t)
    {
        std::array<unsigned int, 128> freq_count = {0};
        for (auto &c : s)
        {
            auto idx = static_cast<unsigned int>(c);
            freq_count[idx] += 1;
        }
        for (auto &c : t)
        {
            auto idx = static_cast<unsigned int>(c);
            freq_count[idx] -= 1;
        }
        for (const auto &v : freq_count)
        {
            if (v != 0)
            {
                return false;
            }
        }
        return true;
    }
};