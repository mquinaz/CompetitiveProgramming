#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int count_digit(int number) {
   int count = 0;
   while(number != 0) {
      number = number / 10;
      count++;
   }
   return count;
}

int main()
{
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
			long long n;
			cin >>n;
			
			int steps = -1,nAux=0,nAux2=0; 
			while(true){
				if( n % 25 == 0){
					steps++;
					cout << steps << endl;
					break;
				}
				int digitNum = count_digit(n);
				string numberS = to_string(n);
				steps++;
				//if last-2 and last-1 are good remove last digit, else remove last-1 digit
				if(digitNum > 2){
					string lastDigits2 = string(1,numberS[digitNum-3])+numberS[digitNum-2];   
					lastDigits2.erase(0, min(lastDigits2.find_first_not_of('0'), lastDigits2.size()-1));
					nAux2 = stoi( lastDigits2 );
				}
				string lastDigits = string(1,numberS[digitNum-2])+numberS[digitNum-1];   
				lastDigits.erase(0, min(lastDigits.find_first_not_of('0'), lastDigits.size()-1));
				nAux = stoi( lastDigits );
				//cout << n << " " << nAux << " " << nAux2 << endl;
				if((numberS[digitNum-1] == '0' || numberS[digitNum-1] == '5' )){
					if( (numberS[digitNum-2] == '2' || numberS[digitNum-2] == '5' || numberS[digitNum-2] == '7' || numberS[digitNum-2	] == '0') && (nAux % 25 == 0) ){
							if( nAux2 % 25 == 0){
								string newStr = numberS.substr(0,numberS.size()-1);
								n = stoi(newStr);		
								continue;
							}
							else{
								string newStr = numberS.substr(0,numberS.size()-2) + numberS[digitNum-1];
								n = stoi(newStr);
								continue;
							}
					}
					else{
							if( nAux2 % 25 == 0){
								string newStr = numberS.substr(0,numberS.size()-1);
								n = stoi(newStr);		
								continue;
							}
							else{
								string newStr = numberS.substr(0,numberS.size()-2) + numberS[digitNum-1];
								n = stoi(newStr);
								continue;
							}
					}
				}
				else{
					string newStr = numberS.substr(0,numberS.size()-1);
					n = stoi(newStr);
				}

			}	
	}
    return 0;
}

