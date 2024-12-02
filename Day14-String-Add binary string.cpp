/* Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
   Note: The input strings may contain leading zeros but the output string should not have any leading zeros. */
#include <iostream>
#include <string>
using namespace std;

string addString(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry) {
        int bita = (i >= 0) ? a[i--] - '0' : 0;
        int bitb = (j >= 0) ? b[j--] - '0' : 0;
        
        int sum = bita ^ bitb ^ carry;
        carry = (bita & bitb) + (carry & (bita ^ bitb));
        
        result = char(sum + '0') + result;
    }

    // Remove leading zeros using a simple loop
    int start = 0;
    while (start < result.size() && result[start] == '0') {
        ++start;
    }

    return start == result.size() ? "0" : result.substr(start);
}

int main() {
    string binary1 = "1010";
    string binary2 = "110";

    cout << "Sum: " << addString(binary1, binary2) << endl;

    return 0;
}
// output= Sum: 10000
