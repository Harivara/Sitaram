#include<bits/stdc++.h>
using namespace std;

bool get_bit(int num, int i){
    //find whether i th bit of num is '1' or '0'
    return (num & (1<<i));
}

int set_bit(int num, int i){
    //sets the i th bit of num to 1
    return (num | (1<<i));
}

int clear_bit(int num,int i){
    //converts i th bit to 0
    int mask=~(1<<i);
    return num & mask;
}

int update_bit(int num,int i,int val){
    int mask=~(1<<i);
    return ((num &mask) | (val<<i));
}

int count_set_bits(int num){
    int count=0;
    while(num){
        num=(num & num-1);
        count++;
    }
    return count;
}

// def count_bits_lookup(n: int) -> int:
//     """Using lookup table"""
//     table = [0] * 256
//     for i in range(256):
//         table[i] = (i & 1) + table[i >> 1]
    
//     return (table[n & 0xff] +
//             table[(n >> 8) & 0xff] +
//             table[(n >> 16) & 0xff] +
//             table[n >> 24])
// ```


// ### 5. Bit Manipulation Tricks
// ```python
// def bit_tricks(n: int) -> dict:
//     return {
//         'is_even': (n & 1) == 0,
//         'multiply_by_2': n << 1,
//         'divide_by_2': n >> 1,
//         'clear_rightmost_set_bit': n & (n - 1),
//         'get_rightmost_set_bit': n & (-n),
//         'clear_all_bits_except_rightmost': n & (-n),
//         'clear_rightmost_bits': n & (n + 1),
//         'swap_values': lambda x, y: (x := x ^ y, y := x ^ y, x := x ^ y)
//     }
// ```

bool power_of_2(int num){
    return num>0 && (num & (num-1)==0);
}

int main(){

}