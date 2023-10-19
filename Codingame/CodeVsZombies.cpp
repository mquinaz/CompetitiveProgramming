#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <climits>
#include <set>

using namespace std;

//Monte Carlo algorithm
class Entity
{
public:
    struct Human
    {
        int id;
        int x;
        int y;
    };

    struct Zombie
    {
        int id;
        int x;
        int y;
        int x_next;
        int y_next;
    };

    vector<Human> humans;
    vector<Zombie> zombies;
    int x, y, human_count, zombie_count;

private:

public:
    Entity()
    {
        
    }

    vector<pair<int,int>> Generate_Strategy()
    {
        vector<pair<int,int>> strategy;
        /*int X = RandNum(0, 3);
        for(int i=0;i<X;i++)
        {
            int x = abs(x + RandNum(-1000, 1000));
            int y = abs(y + RandNum(-1000, 1000));
            strategy.push_back(make_pair(x,y));
        }*/

        set<int> chosen_zombies;
        while(chosen_zombies.size() < zombies.size())
        {
            int x = RandNum(0, zombies.size());
            if( chosen_zombies.find(x) == chosen_zombies.end())
            {
                chosen_zombies.insert(x);
                strategy.push_back(make_pair(zombies[x].x_next,zombies[x].y_next));
            }
        }
        return strategy;
    }

    double Simulate_Strategy(vector<pair<int,int>> strategy)
    {
        int simulation_hcount = human_count, simulation_zcount = zombie_count;
        vector<Human> simulation_humans = humans;
        vector<Zombie> simulation_zombies = zombies;
        int simulation_x = x, simulation_y = y;

        double score = 0;
        for(int i=0;i<strategy.size();i++)
        {
            //move all zombies
            MoveEntity(simulation_zombies, simulation_zcount);
            //move Ash
            MoveEntity(strategy[i],simulation_x,simulation_y);

            score += KillZombies(simulation_x, simulation_y, simulation_zombies, simulation_zcount, simulation_hcount);

            KillHumans(simulation_zombies, simulation_zcount, simulation_humans, simulation_hcount);

            if(simulation_hcount == 0)
                return 0;

            CalculateZombieTarget(simulation_zombies, simulation_zcount,simulation_humans, simulation_hcount);
        }
        return score;
    }

private:
    int RandNum(int min, int max)
    {
        return rand()%(max-min + 1) + min;
    }

    double Distance(int x, int y, int x2, int y2)
    {
        return sqrt( pow(x2 - x,2) + pow(y2 - y,2) );
    }

    pair<int,int> ClosestEntity(int x, int y, vector<Zombie> list)
    {
        double min = INT_MAX;
        int targetx,targety;
        for(int i=0;i<list.size();i++)
        {
            double d = Distance(x, y, list[i].x_next, list[i].y_next);
            if( min > d)
            {
                min = d;
                targety = list[i].y_next;
                targetx = list[i].x_next;
            }
        }
        return make_pair(targetx, targety);
    }

    pair<int,int> ClosestEntity(int x, int y, vector<Human> list)
    {
        double min = INT_MAX;
        int targetx,targety;
        for(int i=0;i<list.size();i++)
        {
            double d = Distance(x, y, list[i].x, list[i].y);
            if( min > d)
            {
                min = d;
                targety = list[i].y;
                targetx = list[i].x;
            }
        }
        return make_pair(targetx, targety);
    }

    void MoveEntity(vector<Zombie> &simulation_zombies, int simulation_zcount)
    {
        for(int i=0;i<simulation_zcount;i++)
        {
            simulation_zombies[i].x = simulation_zombies[i].x_next;
            simulation_zombies[i].y = simulation_zombies[i].y_next;        
        }
    }

    void MoveEntity(pair<int,int> strategy, int &simulation_x, int &simulation_y)
    {
        simulation_x = strategy.first;
        simulation_y = strategy.second;        
    }

    double KillZombies(int simulation_x, int simulation_y, vector<Zombie> &simulation_zombies, int &simulation_zcount, int simulation_hcount)
    {
        int kill1 = 1,kill2 = 1;
        double score = 0;
        for(int i=0;i<simulation_zcount;i++)
        {
            if( Distance(simulation_x, simulation_y, simulation_zombies[i].x, simulation_zombies[i].y) <= 2000)
            {
                score += pow(simulation_hcount,2) * 10 * kill2;
                int aux = kill2;
                kill2 += kill1;
                kill1 = aux;

                simulation_zombies.erase(simulation_zombies.begin()+i);
                simulation_zcount--;
                i--;
            }
        }
        return score;
    }

    void KillHumans(const vector<Zombie> simulation_zombies, const int simulation_zcount, vector<Human> &simulation_humans, int &simulation_hcount)
    {
        for(int i=0;i<simulation_hcount;i++)
        {
            for(int j=0;j<simulation_zcount;j++)
            {
                if( Distance(simulation_humans[i].x, simulation_humans[i].y, simulation_zombies[i].x, simulation_zombies[i].y) < 400)
                {
                    simulation_humans.erase(simulation_humans.begin()+i);
                    simulation_hcount--;
                    i--;
                    break;
                }
            }
        }
    }

    void CalculateZombieTarget(vector<Zombie> &simulation_zombies, const int simulation_zcount, vector<Human> simulation_humans, int simulation_hcount)
    {
        for(int i=0;i<simulation_zcount;i++)
        {
            pair<int,int> target = ClosestEntity(simulation_zombies[i].x, simulation_zombies[i].y, simulation_humans);
            simulation_zombies[i].x_next = target.first;
            simulation_zombies[i].y_next = target.second;
        }
    }
};

int main()
{
    while (1)
    {
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
        chrono::steady_clock::time_point end;
        Entity game;

        cin >> game.x >> game.y; cin.ignore();
        cin >> game.human_count; cin.ignore();

        for (int i = 0; i < game.human_count; i++)
        {
            Entity::Human human;
            cin >> human.id >> human.x >> human.y; cin.ignore();
            game.humans.push_back(human);
        }

        cin >> game.zombie_count; cin.ignore();
        for (int i = 0; i < game.zombie_count; i++)
        {
            Entity::Zombie zombie;
            cin >> zombie.id >> zombie.x >> zombie.y >> zombie.x_next >> zombie.y_next; cin.ignore();
            game.zombies.push_back(zombie);
        }

        double best = INT_MIN;
        pair<int,int> best_strategy;
        while( chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() < 100)
        {
            auto strategy = game.Generate_Strategy();
            double score = game.Simulate_Strategy(strategy);

            if(score > best)
            {
                cerr << "Score strategy x " << score << endl;
                best_strategy = strategy[0];
                best = score;
            }
            end = chrono::steady_clock::now();
        }

        cout << best_strategy.first << " " << best_strategy.second << endl;
        cerr << "Time difference = " << 
        chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << 
        "[µs]" << endl;

    }
}
