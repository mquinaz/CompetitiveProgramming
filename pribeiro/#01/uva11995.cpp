#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    while(cin >> N)
    {
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		bool flag[] = {true,true,true};

		for(int i=0;i<N;i++)
		{
			int op,num;
			cin >> op >> num;
			if( op == 1)
			{
				if( flag[0] )
					s.push(num);
				if( flag[1] )
					q.push(num);
				if( flag[2] )
					pq.push(num);
			}
			if( op == 2)
			{
				if( flag[0] ){
					if( s.empty() || s.top() != num)
						flag[0] = false;
					else
						s.pop();
				}
				if( flag[1] ){
					if( q.empty() || q.front() != num)
						flag[1] = false;
					else
						q.pop();
				}
				if( flag[2] ){
					if( pq.empty() || pq.top() != num)
						flag[2] = false;
					else
						pq.pop();
				}
			}
		}
		int count = 0;
		for(int i=0;i<3;i++)
			if( flag[i] )
				count++;
		if( count > 1 )
		{
			cout << "not sure" << endl;
			continue;
		}
		if(flag[0]){
			cout << "stack" << endl;
			continue;
		}
		if(flag[1]){
			cout << "queue" << endl;
			continue;
		}
		if(flag[2]){
			cout << "priority queue" << endl;
			continue;
		}
		
		cout << "impossible" << endl;
	}
	return 0;
}
