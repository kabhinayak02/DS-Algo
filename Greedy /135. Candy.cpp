/*
Using 2 vector

tc: o(n)
sc: o(n)

*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1), right(n, 1);
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                right[i] = right[i+1]+1;
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans+=max(left[i], right[i]);
        }
        return ans;
    }
};

/*
without using extra space 

tc: o(n)
sc: o(1)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1;
        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){ // up
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]){ // down 
                sum += down;
                down++;
                i++;
            }
        
            if(down > peak){
                sum += (down-peak);
            }
        }
        return sum;
    }
};