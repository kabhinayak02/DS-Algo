/*
using sort 

tc: o(nlogn)
sc: o(1)

*/
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());

        int i = 0;
        int j = n-1;
        int sum = skill[i] + skill[j];
        long long chem = 0;
        while(i < j){   
            int currSum = skill[i] + skill[j];
            if(currSum != sum) return -1;

            chem += ((long long)skill[i] * (long long)skill[j]);
            i++;
            j--;

        }
        return chem;

    }
};

/*
1 -> 0
2 -> 1
3 -> 1
4 -> 0
5 -> 0

team = n / 2 -> 6 / 2 = [3]
sum = 18
target = sum / team = 18/3 => 6

it = 3, target - it = 6 - 3 = 3 is this present in map, if not return -1 if yes decrement count or freq;
(3, 3) -> (it, target - it)

it = 2, target - it = 6-2 = 4
(2, 4)

it = 5, target - it = 6 - 5 = 1
(5, 1)

it = 1, target - it = 6 - 1 = 5
(1, 5)

similarly 
(4, 2)

(3, 3)

*/
/*

tc: o(n)
sc: o(n)
*/
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        vector<int> temp(1001, 0);
        int sum = 0;
        for(int it: skill){
            sum += it;
            temp[it]++;
        }
        int team = n / 2;
        if(sum % team != 0) return -1;
        int targetEachTeam = sum / team;

        long long ans = 0;

        for(int i=0; i<n; i++){
            int currSkill = skill[i];
            int remianSkill = targetEachTeam - skill[i];
            if(temp[remianSkill] == 0) return -1;
            temp[remianSkill]--;
            ans += (currSkill * remianSkill);
        }
        return ans/2;
    }
};
