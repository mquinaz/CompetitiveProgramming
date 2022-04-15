#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,C;
	cin >> N >> C;
	map<int,int> frequency;
	vector<int> order;
	string answer = "";
	
	for(int i=0;i<N;i++)
	{
		int num;
		cin >> num;
		if( frequency.find(num) == frequency.end() )
		{
			frequency[num] = 1;
			order.push_back(num);
		}
		else
		{
			frequency[num] += 1;
		}
	}
	
	while( frequency.size() > 0)
	{
		int max = 0;
		int nummax = 0;
		map<int, int>::iterator it;
		for(it = frequency.begin();it!=frequency.end();it++)
		{
			vector<int>::iterator itr = find(order.begin(), order.end(), nummax);
			vector<int>::iterator itr2 = find(order.begin(), order.end(), it->first);
			if(max < it->second || (max == it->second && distance(order.begin(), itr) > distance(order.begin(), itr2)))
			{
				nummax = it->first;
				max = it->second;
			}
		}

		for(int k=0;k<max;k++)
		{
			answer += to_string(nummax) + " ";
		}
		frequency.erase(frequency.find(nummax) );		
	}

	cout << answer << endl;

	return 0;
}
