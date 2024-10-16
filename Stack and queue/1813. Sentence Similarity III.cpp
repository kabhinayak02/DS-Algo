/*
using vector and pointers

tc: o(n)
sc: o(n)
*/

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.length() < sentence2.length()){
            swap(sentence1, sentence2);
        }

        vector<string> vec1, vec2;
        stringstream ss1(sentence1);
        string token;
        while(ss1 >> token){
            vec1.push_back(token);
        }

        stringstream ss2(sentence2);
        while(ss2 >> token){
            vec2.push_back(token);
        }

        int i = 0, j = vec1.size() - 1;
        int k = 0, l = vec2.size() - 1;

        while(k < vec2.size() && i < vec1.size() && vec2[k] == vec1[i]){
            k++;
            i++;
        }

        while(l >= k && vec2[l] == vec1[j]){
            j--;
            l--;
        }

        return l < k;
    }
};

/*
using deque

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.length() < sentence2.length()){
            swap(sentence1, sentence2);
        }

        deque<string> deq1, deq2;
        stringstream ss1(sentence1);
        string token;
        while(ss1 >> token){
            deq1.push_back(token);
        }

        stringstream ss2(sentence2);
        while(ss2 >> token){
            deq2.push_back(token);
        }

        while(!deq1.empty() && !deq2.empty() && deq1.front() == deq2.front()){
            deq1.pop_front();
            deq2.pop_front();
        }

        while(!deq1.empty() && !deq2.empty() && deq1.back() == deq2.back()){
            deq1.pop_back();
            deq2.pop_back();
        }

        return deq2.empty();
    }
};