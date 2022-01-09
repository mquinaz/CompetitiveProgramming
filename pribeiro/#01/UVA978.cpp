#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    multiset<int,greater <int>> lBlue;
    multiset<int,greater <int>> lGreen;
    while(N--){
        lBlue.clear();
        lGreen.clear();
        int B,SG,SB,x;
        cin >> B >> SG >> SB;
        for(int i=0;i<SG;i++){
            cin >> x;
            lGreen.insert(x);
        }
        for(int i=0;i<SB;i++){
            cin >> x;
            lBlue.insert(x);
        }    
        
        multiset <int, greater <int> > :: iterator itr,itr2;
        while(lBlue.size() && lGreen.size()){
            int turns = min(B,min((int) lBlue.size(),(int) lGreen.size()));
            for(int i=0;i<turns;i++){
                int j=0;
                for (itr = lBlue.begin(); itr != lBlue.end(); ++itr){
                    if(j == i)
                        break;
                    j++;
                }
                cout << "asj" << endl;
                //itr = lBlue.begin() + i;
                int blue = *(itr);
                
                j=0;
                for (itr2 = lBlue.begin(); itr2 != lBlue.end(); ++itr2){
                    if(j == i)
                        break;
                    j++;
                }
                //int green = *(lGreen.begin()+i);
                int green = *(itr2);
                cout << blue << green << endl;
                //blue wins
                if(blue > green){
                    blue -= green;
                    lGreen.erase(lGreen.find(green));
                    if(blue <= 0)
                        lBlue.erase(lBlue.find(blue));
                }
                //green wins
                if(green > blue){
                    green -= blue;
                    lBlue.erase(lBlue.find(blue));
                    if(green <= 0)
                        lGreen.erase(lGreen.find(green));
                }
                if(green == blue){
                    lBlue.erase(lBlue.find(blue));
                    lGreen.erase(lGreen.find(green));
                }
            }
        }

        cout << lBlue.size() << lGreen.size() << endl;
        if(!lBlue.size() && !lGreen.size()){
            cout << "green and blue died" << endl;
        }
        if(!lBlue.size() && lGreen.size()){
            cout << "blue wins" << endl;
            for (itr = lBlue.begin(); itr!= lBlue.end(); itr++)
                cout << *itr << endl;
        }
        if(!lGreen.size() && lBlue.size()){
            cout << "green wins" << endl;
            for (itr = lGreen.begin(); itr!= lGreen.end(); itr++)
                cout << *itr << endl;
        }
    }
	
	return 0;
}
