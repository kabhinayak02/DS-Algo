/*

gfg link: https://www.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1

tc: O(n*(log(log(n))))
sc: o(n)
*/
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<int> ans;
        vector<int> prime(N+1, 1);
        for(int i =2;i*i<=N;i++){
            for(int j = i*i;j<=N;j+=i){
                prime[j] = 0;
            }
        }
        
        for(int i = 2;i<=N;i++){
            if(prime[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;

    }
};