/*
Approach 1: 
dublicate string and sort one, now compare both the string the first different element will be the element that we need to 
swap. Now traverse the unsorted string from back side and find the that elment and swap it.

eg: 9638
s1 = 9638
s2 = 9863
need to swap 6 and 8 
now find the indexes
swap them 

ans: 9836

tc: o(nlogn)
sc: o(1)
*/
class Solution {
public:
    int maximumSwap(int num) {
        string s1 = to_string(num);
        string s2 = s1;
        sort(s2.begin(), s2.end(), greater<char>());
        char tar;
        int idx;
        for(int i=0; i<s1.length(); i++){
            if(s1[i] != s2[i]){
                tar = s2[i];
                idx = i;
                break;
            }
        }
        for(int i=s2.length()-1; i>=0; i--){
            if(s1[i] == tar){
                swap(s1[i], s1[idx]);
                break;
            }
        }
        return stoi(s1);
    }
};

/*
Approach 2:
use vector array of size 10 to stores the freq. of each element. Traverse the string comparing it with that is it possible to 
find the bigger element in that index, traverse the array from back side whatever the first element which is greater than element is 
number which we need to swap. 

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int maximumSwap(int num) {
        string strNum = to_string(num);
        int n = strNum.length();
        vector<int> v(10, 0);
        for(int i=0; i<n; i++){
            v[strNum[i] - '0']++;
        }
        int idx;
        char tar;
        bool found = false;
        for(int i=0; i<n; i++){
            int tempNum = strNum[i] - '0';
            for(int j=9; j>=0; j--){
                if(v[j] > 0 && j == tempNum){
                    v[j]--;
                    break;
                }
                else if(v[j] > 0 && j > tempNum){
                    idx = i;
                    tar = j + '0';
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        for(int i=n-1; i>=0; i--){
            if(strNum[i] == tar){
                swap(strNum[idx], strNum[i]);
                break;
            }
        }
        return stoi(strNum);
    }
};


/*
Approach 3:
create an array with storing maximum element idx from its right.

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int maximumSwap(int num) {
        string strNum = to_string(num);
        int n = strNum.size();
        vector<int> maxRight(n);
        maxRight[n-1] = n-1;

        for(int i=n-2; i>=0; i--){
            int rightMaxId = maxRight[i+1];
            int rightMaxElement = strNum[rightMaxId];

            maxRight[i] = (strNum[i] > rightMaxElement) ? i : rightMaxId;
        }

        for(int i=0; i<n; i++){
            int maxRightIdx = maxRight[i];
            int maxRightElement = strNum[maxRightIdx];
            if(strNum[i] < maxRightElement){
                swap(strNum[i], strNum[maxRightIdx]);
                return stoi(strNum);
            }
        }
        return num;
    }
};


/*
Approach 4: modified of 2nd approach 
directly store the indexes in the vector instead of storing freq. 

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();

        vector<int> maxRight(10, -1);

        for(int i=0; i<n; i++){
            int idx = s[i] - '0';
            maxRight[idx] = i;
        }

        for(int i=0; i<n; i++){
            char currChar = s[i];
            int currDigit = currChar - '0';

            for(int d=9; d>currDigit; d--){
                if(maxRight[d] > i){
                    swap(s[i], s[maxRight[d]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};