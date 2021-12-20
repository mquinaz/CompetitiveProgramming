#include<bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    while( getline(cin,n,'0') ){
		int nInt = stoi(n);
		vector<int> frosh[nInt];
		for( int i=0;i<nInt;i++){
			int c1,c2,c3,c4,c5;
			cin >> c1 >> c2 >> c3 >> c4 >> c5;
			frosh[i].push_back(c1);
			frosh[i].push_back(c2);
			frosh[i].push_back(c3);
			frosh[i].push_back(c4);
			frosh[i].push_back(c5);
		}
		
		for( int i=0;i<nInt;i++)
			for( int j=0;j<5;j++)
				cout << frosh[i][j] << endl;
	}
	
	return 0;
}
