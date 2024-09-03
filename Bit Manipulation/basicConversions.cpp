/*
converting decimal to binary

tc: o(logn)
sc: o(logn)
*/
string convert2Binary(int n){
    string res = "";
    while(n != 1){
        if(n%2 == 1) res += '1';
        else res += '0';
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

/*
converting binary to decimal

tc: o(n)
sc: o(1)
*/
int convert2Decimal(string s){
    int len = s.length(), p2 = 1, num = 0;
    for(int i=len-1; i>=0; i--){
        if(s[i] == '1') num += p2;
        p2 *= 2;
    }
    return num;
}