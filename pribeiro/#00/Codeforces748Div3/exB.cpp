#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;

const int INF = 10000;

//how many digits i have to remove to match goal to digit strings
int stepsDivisible(string goal, string digit){
    int steps = 0;
    while(true){
        //cout << goal[0] << goal[1] << " " << digit[digit.size()-2] << digit[digit.size()-1] << " " << steps << endl;
        if( digit.size() == 2){
            if( goal == digit)
                return steps;
            else
                return INF;
        }
        //if goal is the same as the last two digits of digit string
        if (!goal.compare(digit.substr(digit.size()-2,digit.size()-1)) )
            return steps;
        
	//digit.erase(0, min(digit.find_first_not_of('0'), digit.size()-1));
        if( goal[1] != digit[digit.size()-1]){
 			digit = digit.substr(0,digit.size()-1);
			steps++;
			continue;   
        }
        if( goal[0] != digit[digit.size()-2]){
			digit = digit.substr(0,digit.size()-2) + digit[digit.size()-1];
			steps++;
			continue;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
			long long n;
			cin >>n;
			string nStr = to_string(n);
		    //to be divisible by 25 last two digits must be 4 cases
			int a = stepsDivisible("00",nStr);
			int b = stepsDivisible("25",nStr);
			int c = stepsDivisible("50",nStr);
			int d = stepsDivisible("75",nStr);
			int result = min(a,min(b,min(c,d)));
            cout << result << endl;
	}
    return 0;
}
