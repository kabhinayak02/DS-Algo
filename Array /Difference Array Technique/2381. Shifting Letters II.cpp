/*
Brute force

tc: o(n.shifts.size())
sc: o(1)
*/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];

            // Apply the shift on the substring [start, end]
            for (int i = start; i <= end; i++) {
                if (dir == 1) {
                    // Right shift (increment character)
                    s[i] = 'a' + (s[i] - 'a' + 1) % 26;
                } else {
                    // Left shift (decrement character)
                    s[i] = 'a' + (s[i] - 'a' - 1 + 26) % 26;
                }
            }
        }
        return s;
    }
};


/*
using difference array approach 

tc: o(n+shifts.size())
sc: o(n)
*/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> temp(n + 1, 0); // Use size n+1 to simplify edge handling.

        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];

            if (dir == 1) {
                temp[start]++;
                if (end + 1 < n) {
                    temp[end + 1]--;
                }
            } else {
                temp[start]--;
                if (end + 1 < n) {
                    temp[end + 1]++;
                }
            }
        }

        // Apply prefix sum to calculate the net shifts at each index.
        for (int i = 1; i < n; i++) {
            temp[i] += temp[i - 1];
        }

        // Shift characters and handle wrapping.
        for (int i = 0; i < n; i++) {
            int shift = temp[i] % 26; // Modulo to keep shifts within bounds.
            int newChar = s[i] - 'a' + shift; // Calculate new position.
            if (newChar < 0) {
                newChar += 26; // Handle negative wrapping.
            }
            s[i] = 'a' + (newChar % 26); // Convert back to character.
        }

        return s;
    }
};
