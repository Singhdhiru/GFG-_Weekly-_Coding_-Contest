// Roman Number to Integer
// Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000
#include <iostream>
#include <string>
using namespace std;

int calculate(char c)
{
    if(c=='I'){
        return 1;
    }
    else if(c=='V'){
        return 5;
    }
    else if(c=='X'){
        return 10;
    }
    else if(c== 'L'){
        return 50;
    }
    else if(c== 'C'){
        return 100;
    }
    else if(c=='D'){
        return 500;
    }
    else if(c=='M'){
        return 1000;
    }
}
int romanToDecimal(string &str)
{
    int n = str.size();
    int v1, v2;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            v1 = calculate(str[i]);
            v2 = calculate(str[i + 1]);
            if (v1 < v2)
            {
                ans = ans - v1;
            }
            else
            {
                ans = ans + 1;
            }
        }
        else{
            ans = ans+calculate(str[i]);
        }
    }
    return ans;
}

int main()
{
    string roman ="III";
    int ans = romanToDecimal(roman);
    cout << ans << endl;

    return 0;
}
