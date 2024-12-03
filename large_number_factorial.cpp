#include<iostream>
#include<string>
#include<vector>
using namespace std;

// function to multiply two strings
string multiplication(string num1, string num2){
    int len1 = num1.size();
    int len2 = num2.size();
    if(num1 == '0' or num2 == '0') return "0";
    
    vector<int> result(len1 + len2, 0);
    int num_1 = 0;
    int num_2 = 0;
    for(int i = len1 - 1; i >= 0; i--){
        int carry = 0;
        int n1 = num1[i] - '0';
        for(int j = len2 - 1; j >= 0; j--){
            int n2 = num2[j] - '0';
            int product = n1*n2 + result[num_1 + num_2] + carry;
            carry = product/10;
            result[num_1 + num_2] = product % 10;
            num_2++;
        }
        result[num_1 + num_2] += carry;
        num_1++;
    }

    int i = result.size() - 1;
    while(i >= 0 and result[i] == 0) i--;
    string result_string = "";
    while(i >= 0) result_string += to_string(result[i]);

    return result_string;
}

//Factorial of number
string factorial(int number){
    string result = to_string(1);
    for(int i = 2; i <= number; i++){
        result = multiplication(result, to_string(i));
    }
    return result;
}

int main(){
    int number;
    cin >> number;
    cout << "The factorial of " << number << " is " << factorial(number) << endl;
    return 0;
}