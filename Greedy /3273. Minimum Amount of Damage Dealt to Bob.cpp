/*
Greedy Approach 

tc: o(n)
sc: o(n)
*/

class Solution {
public:
    typedef long long ll;
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();

        priority_queue<pair<double, pair<int,int>>> pq;

        int totalDamage = 0;
        for(int i = 0; i < n; i++) {
            totalDamage += damage[i];

            double timeToKill = ceil(1.0 * health[i] / power);  // time to kill the enemy 

            // damage to kill time ratio, greater the ratio means damage is more, kill that enemy first. 
            double ratio = (double)damage[i] / timeToKill; 

            pq.push({ratio, {health[i], damage[i]}});
                        
        }
        
        ll totalDamageTaken = 0; 
        while(!pq.empty()) {
            int hp = pq.top().second.first;
            int dmg = pq.top().second.second;
            pq.pop();
        
            int timeToKill = (hp + power - 1) / power; 

            ll damageDealt = (ll)timeToKill * totalDamage;

            totalDamageTaken += damageDealt;
            
            totalDamage -= dmg; // remove the damage as the enemy is killed 
        }

        return totalDamageTaken;
    }
};