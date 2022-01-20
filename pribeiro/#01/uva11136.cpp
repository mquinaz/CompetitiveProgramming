#include<bits/stdc++.h>
using namespace std;

int main()
{
	int days;
	
	while( (cin >> days) && days != 0)
	{
		multiset<int, greater<int> > maxSet;
		long long total = 0;
		for(int j=0;j<days;j++)
		{
			int k;
			cin >> k;
			for(int i=0;i<k;i++)
			{
				int bill;
				cin >> bill;	
				maxSet.insert(bill);		
			}

            int biggest = *maxSet.begin();
            maxSet.erase(maxSet.begin());

            int smallest = *maxSet.rbegin();
            maxSet.erase(--maxSet.end());	
            
            total += (biggest - smallest);		
		}
		cout << total << endl;
	}
	return 0;
}
