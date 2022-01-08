#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long k;
	cin >> k;
	long long i=0;
	
	string n = "2";
	while(pow(2,i) <= k){
		i++;
		n += "0";
	}
	n.pop_back();
	
	//calculating nr
	long long res = 0	;
	for(long long j=0;j<i;j++){
		long long aux = pow(2, (i-j) - 1);
		if( k - aux >= 0){
			res += aux;
			k -= aux;
			n[j] = '2';
		}
	}
	
	cout << n << endl;
	return 0;
}

/*
2 20 22					
200 202 220 222			
2000 2002 2020 2022 2200 2202 2220 2222
20000 20002 20020 20022 20200 20202 20220 20222 22000 22002 22020 22022 22200 22202 22220 22222

3 - 4(7) - 8(15) 16(31)

2^1+1 2^2-1 2^3-1 2^4-1

2022

1+2+8 = 11
*/
