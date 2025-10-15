// KMP (Knuth–Morris–Pratt) is a pattern searching algorithm that finds all occurrences of a pattern in a text in O(N + M) time,
// where N = length of text and M = length of pattern.

// It avoids re-checking characters that are already known to match using a preprocessed array called the LPS (Longest Prefix Suffix) array.

vector<int> computeLPS(string pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0; 
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMPsearch(string text, string pat) {
    int n = text.size();
    int m = pat.size();
    vector<int> lps = computeLPS(pat);
    vector<int> result;

    int i = 0, j = 0; // i for text, j for pattern

    while (i < n) {
        if (text[i] == pat[j]) {
            i++; j++;
        }

        if (j == m) {
            result.push_back(i - j); 
            j = lps[j - 1];
        } 
        else if (i < n && text[i] != pat[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return result;
}
