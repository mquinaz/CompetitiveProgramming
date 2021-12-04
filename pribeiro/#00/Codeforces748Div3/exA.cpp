#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
			long long a,b,c;
			cin >> a >> b >> c;
			long long a2=0,b2=0,c2=0,aux1,aux2,aux3;
			aux1 = max(b,c);
			aux2 = max(a,c);
			aux3 = max(a,b);
			if( a <= aux1) 
				a2 = aux1 - a + 1;
			if( b <= aux2)
				b2 = aux2 - b + 1;
			if( c <= aux3)
				c2 = aux3 - c + 1;
			cout << a2 << " " << b2 << " " << c2 << endl; 
	}
    return 0;
}
