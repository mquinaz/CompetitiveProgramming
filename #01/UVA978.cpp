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
        
        multiset <int, greater <int> > :: iterator itr;
        while(lBlue.size() && lGreen.size()){
            int turns = min(B,min((int) lBlue.size(),(int) lGreen.size()));
            /*for(int i=0;i<turns;i++){
                itr = lBlue.begin() + i;
                int blue = *(lBlue.begin()+i);
                int green = *(lGreen.begin()+i);
                
                if(blue > green){
                    *(lBlue.begin()+i) -= *(lGreen.begin()+i);
                    lBlue.erase(lBlue.find());
                }
                else{
                    lGreen.erase(lGreen.find());
                    lGreen.erase(lGreen.find());
                }
            }
            //for (itr = lBlue.begin(); itr!= lBlue.end(); itr++)
        }*/
        
        
        if(!lBlue.size() && !lGreen.size()){
            cout << "green and blue died" << endl;
        }
        if(!lBlue.size()){
            cout << "blue wins" << endl;
            for (itr = lBlue.begin(); itr!= lBlue.end(); itr++)
                cout << *itr << endl;
        }
        if(!lGreen.size()){
            cout << "green wins" << endl;
            for (itr = lGreen.begin(); itr!= lGreen.end(); itr++)
                cout << *itr << endl;
        }
    }
	
	return 0;
}
