/*

dfg link: https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

*/

// tc: o(n), sc: o(n)
void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
    vector<int> temp;
    d = d%n;
    for(int i=d; i<n; i++){
        temp.push_back(arr[i]);
    }
    for(int i=0; i<d; i++){
        temp.push_back(arr[i]);
    }
    arr = temp;
}

// tc: o(n), sc: o(1)
void rotateArr(vector<int>& arr, int d) {
    int n=arr.size();
    d=d%n;
    if(d==0)return;
    for(int i=0;i<d;i++){
        arr.push_back(arr[i]);
    }
    arr.erase(arr.begin()+0, arr.begin()+d);
}