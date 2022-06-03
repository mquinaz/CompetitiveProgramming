#include <iostream>
#include<math.h>
#include<vector>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
		int n;
		cin >> n;
		vector<int> value(n),cost(n);

		for(int j=0;j<n;j++)
		{
			int h;
			cin >> h;
			value.push_back(h);
		}
		for(int j=0;j<n;j++)
		{
			int c;
			cin >> c;
			cost.push_back(c);
		}
		
    }
	
	cout << "finished " << endl;
    return 0;
}
