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
        while(!lBlue.empty() && !lGreen.empty()){
            int turns = min(B,min((int) lBlue.size(),(int) lGreen.size()));
            int addEndSet[2][turns];
            int indEndSet = 0;
            
            while(turns > 0){
                if( lBlue.empty() || lGreen.empty() )
                    break;
                
                //for (itr = lBlue.begin(); itr != lBlue.end(); ++itr)
				//	cout << *itr << endl;
					

                int blue = *(lBlue.begin());
                int green = *(lGreen.begin());
                //cout << "round: " << turns << " green: " << green << " vs blue:" << blue << endl;
                turns--;
                
                //blue wins
                if(blue > green){
                    //we delete green that died, blue that won, and the remaining blue
                    int tempBlue = blue - green;
                    //lBlue.erase(blue);
                    //lBlue.insert(tempBlue);
                    //lGreen.erase(green);

                    //only later I found we can use pop, but the following method is to
                    //remove only one copy even if it has duplicates
                    multiset <int, greater <int> > :: iterator hit(lBlue.find(blue));
                    if (hit== lBlue.begin())
                        lBlue.erase(hit);
                    hit = (lGreen.find(green));
                    if (hit== lGreen.begin())
                        lGreen.erase(hit);

                    //we can't directly insert surviving lemming or it will give wrong order results
                    //so we store the values in a matrix(the first dimension for knowing if it is blue or green)
                    //and then at the end of the turns we add all values
                    addEndSet[1][indEndSet] = tempBlue;
                    addEndSet[0][indEndSet] = 0;
                    indEndSet++;
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

                    addEndSet[0][indEndSet] = tempGreen;
                    addEndSet[1][indEndSet] = 0;
                    indEndSet++;
                    continue;
                }
                if(green == blue){
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
            
            //adding surviver lemmings
            for(int i1=0;i1<indEndSet;i1++){
                if(addEndSet[1][i1] != 0)
                    lBlue.insert(addEndSet[1][i1]);
                if(addEndSet[0][i1] != 0)
                    lGreen.insert(addEndSet[0][i1]);
            }
            
        }

        //cout << "G size:" << lGreen.size() << " B size:" << lBlue.size() << endl;
        if(lBlue.empty() && lGreen.empty()){
            cout << "green and blue died" << endl;    
           if( N )
		cout << endl;   
	continue;
        }	

        if(lBlue.empty() && !lGreen.empty()){
            cout << "green wins" << endl;
            for (itr = lGreen.begin(); itr!= lGreen.end(); itr++)
                cout << *itr << endl;
        }
        if(lGreen.empty() && !lBlue.empty()){
            cout << "blue wins" << endl;
            for (itr = lBlue.begin(); itr!= lBlue.end(); itr++)
                cout << *itr << endl;
        }
        
	if( N )
		cout << endl;
    }
	
	return 0;
}
