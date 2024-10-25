/*

tc: o(n.m)
sc: o(n)
*/
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(folder.begin(), folder.end());
        vector<string> ans;

        for(string &currFolder: folder){
            bool isSubFolder = false;
            string tempFolder = currFolder;
            while(!currFolder.empty()){
                size_t position = currFolder.find_last_of('/');

                currFolder = currFolder.substr(0, position);

                if(st.find(currFolder) != st.end()){
                    isSubFolder = true;
                    break;
                }
            }

            if(!isSubFolder){
                ans.push_back(tempFolder);
            }
        }
        return ans;
    }
};

/*
using sorting

tc:
sc: 
*/
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> ans;
        ans.push_back(folder[0]);

        for(int i=1; i<folder.size(); i++){
            string currFolder = folder[i];
            string lastFolder = ans.back();
            lastFolder += '/';
            
            if(currFolder.find(lastFolder) != 0){
                ans.push_back(currFolder);
            }
        }
        return ans;
    }
};