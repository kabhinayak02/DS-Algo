#include <iostream>
using namespace std;

/*
Swap 2 no. using bit manipulation or (without using any variable)
*/

int swap(int a, int b){
    a = a ^ b;
    b = a ^ b; // a = a^b^b = a
    a = a ^ b; // b = a^b^a = b
    return a;
}

/*
Check if the i'th bit is set or not

tc: o(1)
sc: o(1)
*/

bool usingLeftShift(int n, int i){
    return ((n & (1 << i)) != 0);
}

bool usingRightShit(int n, int i){
    return ((n >> i) & 1);
}

/*
Set the i'th bit to 1

tc: o(1)
sc: o(1)
*/

bool usingOR(int n, int i){
    return (n | (1 << i));
}

/*
Clear the i'th bit 

*/

bool usingAND(int n, int i){
    return (n & ~(1 << i));
}

/*
Toggle the i'th bit

*/

bool usingXOR(int n, int i){
    return (n ^ (1 << i));
}

/*
Remove the last set bit

*/

int removeLastSetBit(int n){
    return (n & (n-1));
}

/*
Check if the number is a power of 2

*/

bool isPowerOf2(int n){
    return (n & (n-1)) == 0;
}

/*
Count the numver if set bits

*/

int countSetBits(int n){
    int cnt = 0;
    while(n){
        if(n%2 == 1){
            cnt++;
        }
        n = n/2;
    }
    return cnt;
}

int countSetBits2(int n){
    int cnt = 0;
    while(n){
        cnt += (n & 1); // other way of adding the odd no.
        n = n >> 1; // other way of dividing the no. by 2
    }
    return cnt;
}

int countSetBits3(int n){
    int cnt = 0;
    while(n){ // we are making the loop till n is not zero 
        n = n & (n-1); // and everytime we are decreaing the 1's count by 1
        cnt++;
    }
    return cnt;
}

/*
Minimum bit filps to convert a number from a to b

*/

int minBitFlips(int a, int b){
    return __builtin_popcount(a^b); // using STL 
}

int minBitFlips2(int a, int b){
    int cnt = 0;
    while(a != b){
        if((a & 1) != (b & 1)){
            cnt++;
        }
        a = a >> 1;
        b = b >> 1;
    }
    return cnt;
}

int minBitFlips3(int a, int b){
    int cnt = 0;
    while(a != b){
        a = a >> 1;
        b = b >> 1;
        cnt++;
    }
    return cnt;
}

int main(){

    cout << minBitFlips3(3, 4) << endl;
}