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
            //int addEndSet[2][turns];
            //int indEndSet = 0;
            
            for(int i=0;i<turns;i++){
                if( (lBlue.size()==0) || (lGreen.size()==0) )
                    break;
                int j=0;
                for (itr = lBlue.begin(); itr != lBlue.end(); ++itr){
                    if(j == i)
                        break;
                    j++;
                }
                //itr = lBlue.begin() + i;
                int blue = *(itr);
                
                j=0;
                for (itr2 = lGreen.begin(); itr2 != lGreen.end(); ++itr2){
                    if(j == i)
                        break;
                    j++;
                }
                //int green = *(lGreen.begin()+i);
                int green = *(itr2);
                cout << "round: " << (i+1) << " green: " << green << " vs blue:" << blue << endl;
                //blue wins
                if(blue > green){
                    //we delete green that died, blue that won, and the remaining blue
                    int tempBlue = blue - green;
                    //lBlue.erase(blue);
                    //lBlue.insert(tempBlue);
                    //lGreen.erase(green);
                    i--;
                    multiset <int, greater <int> > :: iterator hit(lBlue.find(blue));
                    if (hit== lBlue.begin())
                        lBlue.erase(hit);
                    hit = (lGreen.find(green));
                    if (hit== lGreen.begin())
                        lGreen.erase(hit);
                    lBlue.insert(tempBlue);
                    //addEndSet[1][indEndSet] = tempBlue;
                    //addEndSet[0][indEndSet] = 0;
                    //indEndSet++;
                    continue;
                }
                //green wins
                if(green > blue){
                    //we delete blue that died, green that won, and the remaining green
                    int tempGreen = green - blue;
                    //lGreen.erase(green);
                    //lGreen.insert(tempGreen);
                    //lBlue.erase(blue);
                    multiset <int, greater <int> > :: iterator hit(lBlue.find(blue));
                    if (hit== lBlue.begin())
                        lBlue.erase(hit);
                    hit = (lGreen.find(green));
                    if (hit== lGreen.begin())
                        lGreen.erase(hit);
                    lGreen.insert(tempGreen);
                    //addEndSet[0][indEndSet] = tempGreen;
                    //addEndSet[1][indEndSet] = 0;
                    //indEndSet++;
                    i--;
                    continue;
                }
                if(green == blue){
                    i--;
                    //lBlue.erase(blue);
                    multiset <int, greater <int> > :: iterator hit(lBlue.find(blue));
                    if (hit== lBlue.begin())
                        lBlue.erase(hit);
                    hit = (lGreen.find(green));
                    if (hit== lGreen.begin())
                        lGreen.erase(hit);
                    //lGreen.erase(green);
                }
            }
            /*
            //adding surviver lemmings
            for(int i1=0;i1<indEndSet;i1++){
                if(addEndSet[1][i1] != 0)
                    lBlue.insert(addEndSet[1][i1]);
                if(addEndSet[0][i1] != 0)
                    lGreen.insert(addEndSet[0][i1]);
            }
            */
        }

        cout << "G size:" << lGreen.size() << " B size:" << lBlue.size() << endl;
        if(!lBlue.size() && !lGreen.size()){
            cout << "green and blue died" << endl;
        }

        if(!lBlue.size() && lGreen.size()){
            cout << "green wins" << endl;
            for (itr = lGreen.begin(); itr!= lGreen.end(); itr++)
                cout << *itr << endl;
        }
        if(!lGreen.size() && lBlue.size()){
            cout << "blue wins" << endl;
            for (itr = lBlue.begin(); itr!= lBlue.end(); itr++)
                cout << *itr << endl;
        }
        
        cout << endl;
    }
	
	return 0;
}

/*
3 3 3
10
20
30
30
100
30
*/
