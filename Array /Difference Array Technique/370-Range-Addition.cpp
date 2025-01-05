void rangeAddition(vector<int>& arr, vector<vector>& queries){
    int n = arr.size();

    for(auto& query: queries){
        int start = query[0];
        int end = query[1];
        int x = query[2];

        arr[start] += x;

        if(end+1 < n){
            arr[end+1] += x;
        }
    }


    for(int i=1; i<n; i++){
        arr[i] += arr[i-1];
    }

}