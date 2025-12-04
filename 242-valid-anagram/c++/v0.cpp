class Solution
{
    /*
    Sort and Compare
    This concise solution leverages the property that valid anagrams share the same
    canonical form when sorted. By arranging the characters of both strings s and t
    in lexicographical (alphabetical) order, the algorithm normalizes the input
    data.

    Once sorted, if the original strings were anagrams, they will become identical
    sequences (e.g., "rat" and "tar" both become "art"). The function then performs
    a direct element-by-element equality check using the == operator to return the
    result.

    Complexity Analysis

    Time Complexity: O(NlogN) The dominant cost is sorting. Assuming N is the length
    of the strings, std::sort typically runs in O(NlogN). The subsequent string
    comparison is linear, O(N), but this is overshadowed by the sorting cost.

    Space Complexity: O(logN) Unlike the hash map approach, this sorts the strings
    in-place. The space complexity is driven by the stack space required for the
    sorting algorithm's recursion (typically Introsort).
    */
public:
    bool isAnagram(string s, string t)
    {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};