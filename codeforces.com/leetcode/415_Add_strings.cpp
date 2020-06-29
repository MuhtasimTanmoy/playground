// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

// Note:

// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

// https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int num1_length = num1.size();
        int num2_length = num2.size();
        int carry = 0;
        string holder;
        if(num2_length>num1_length){
            holder = num1;
            num1 = num2;
            num2 = holder;
            carry = num1_length;
            num1_length = num2_length;
            num2_length = carry;
        }
        carry = 0;
        int sum_at_index = 0;
        while(num1_length>0){
            sum_at_index = num1[num1_length-1] - '0'  + carry;
            if(num2_length>0){
                sum_at_index += num2[num2_length-1] - '0';
            }
            if(sum_at_index>9){
                sum_at_index = sum_at_index % 10;
                carry = 1;
            }else{
                carry = 0;
            }
            num1[num1_length-1] = sum_at_index + '0';
            num1_length--;
            num2_length--;
        }
        
        if(carry){
            num1 = '1' + num1;
        }
        return num1;
    }
};