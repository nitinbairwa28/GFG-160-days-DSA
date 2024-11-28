// Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.
// 1.Cases for atoi() conversion:
// 2.Skip any leading whitespaces.
// 3.Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
// 4.Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
// 5.If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.
#include <iostream>
#include <cstring> 
#include <climits>  
using namespace std;

    int myAtoi(char* s) {
        int i = 0;          
        int sign = 1;       
        long result = 0;   
        
        while (s[i] == ' ') {
            ++i;
        }

        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

        while (isdigit(s[i])) {
            int digit = s[i] - '0';
            result = result * 10 + digit;

            if (result > INT_MAX) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ++i;
        }

        return static_cast<int>(result) * sign;
    }


int main() {
         
    char input[] = "   -2147abcd";     
  
    cout << myAtoi(input) << endl;  

    return 0;
}
// output= -2147
