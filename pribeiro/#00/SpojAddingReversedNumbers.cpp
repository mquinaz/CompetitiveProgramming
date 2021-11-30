#include <iostream>
#include<bits/stdc++.h> 
#include <sstream>
using namespace std;

string removeZero(string str)
{
    // Count trailing zeros
    int i = 0;
    while (str[i] == '0')
       i++;
  
    // The erase function removes i characters
    // from given index (0 here)
    str.erase(0, i);
  
    return str;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        string strA = to_string(a);
        string strB = to_string(b);
        //first int to string
        int len = strA.length();
        int n=len-1;
        for(int i=0;i<(len/2);i++){
            //Using the swap method to switch values at each index
            swap(strA[i],strA[n]);
            n = n-1;
        }
        //second int to string
        len = strB.length();
        n=len-1;
        for(int i=0;i<(len/2);i++){
            swap(strB[i],strB[n]);
            n = n-1;
        }
        
        strA = removeZero(strA);
        strB = removeZero(strB);
        
        //convert two reversed strings to int and sum them
        stringstream geek(strA);
        int numRevA;
        geek >> numRevA;
        stringstream geek2(strB);
        int numRevB;
        geek2 >> numRevB;
        int sum = numRevA + numRevB;
        stringstream geek3;
        geek3 << sum;
        //reverse final result
        string strFinal = geek3.str();
        len = strFinal.length();
        n=len-1;
        for(int i=0;i<(len/2);i++){
            swap(strFinal[i],strFinal[n]);
            n = n-1;
        }
        strFinal = removeZero(strFinal);
        cout <<strFinal << endl;
    }
    return 0;
}
