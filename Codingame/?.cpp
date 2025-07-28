#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono>
#include <map>

#pragma GCC optimize("-O3,inline,omit-frame-pointer,unroll-loops")

#define MAX_DEPTH 1

using namespace std;

class Utils 
{
public:
    static int distance(int x1, int y1, int x2, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }
};

class Game
{
    public:
        int id; //player id
        int initialNumAgent;
        int numAgent;
        int scoreTeam, scoreEnemy;
        int turns;
    
        struct Agent
        {
            int id;
            int player;
            int shootCD; // num of turns between each of this agents shots
            int optimalRange; // Maximum manhattan distance for greatest damage output
            int soakingPower; // Damage output within optimal conditions
            int initialNumBombs; // Number of splash bombs this can throw this game

            int x;
            int y;
            int cd; // Number of turns before this agent can shoot
            int numBombs;
            int wetness; // Damage (0-100) this agent has taken

            bool alive;
        };

        vector<Agent> agents;

        vector<int> idTeam;
        vector<int> idEnemy;
    
        int width;
        int height;

        vector<vector<int>> map;

    Game()
    {
        scoreTeam = scoreEnemy = 0;
        turns = -1;
        cin >> id; cin.ignore();       
        cin >> initialNumAgent; cin.ignore();

        agents.resize(initialNumAgent);
        cerr << "team id:: " << id << endl;
        for (int i = 0; i < initialNumAgent; i++)
        {
            int agentId;
            cin >> agentId;
            agentId--;
    
            cin >> agents[agentId].player >> agents[agentId].shootCD >> agents[agentId].optimalRange >>
            agents[agentId].soakingPower >> agents[agentId].initialNumBombs; cin.ignore();

            agents[agentId].alive = false;
            agents[agentId].id = agentId;
        }

        cin >> width >> height; cin.ignore();
        map = std::vector<std::vector<int>>(height, std::vector<int>(width));

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int x,y;
                cin >> x >> y >> map[y][x]; cin.ignore();
            }
        }

        //printMap();
    }

    void readAgents()
    {
        turns++;
        idTeam.clear();
        idEnemy.clear();  

        cin >> numAgent; cin.ignore();
        for (int i = 0; i < numAgent; i++)
        {
            int agentId;
            cin >> agentId;
            agentId--;

            cin >> agents[agentId].x >> agents[agentId].y >> agents[agentId].cd >> 
            agents[agentId].numBombs >> agents[agentId].wetness; cin.ignore();

            agents[agentId].alive = true;
            if(agents[agentId].player == id)
                idTeam.push_back(agentId);
            else
                idEnemy.push_back(agentId);
        }
        updateDeadAgents();
        if(turns > 0)
        {
            countPoints();
        }
    }

    bool safeBomb(int x, int y)
    {
        for(int i=0;i<agents.size();i++)
        {
            int dis = Utils::distance(agents[i].x, agents[i].y, x, y);
            if(dis <= 2 && agents[i].player == id)
                return false;
        }
        return true;
    }

    void choose(int agentNr)
    {
        int teamNr = 0;
        int teamInd = 0;

        for(int i=0;i<agents.size();i++)
        {
            if(agents[i].player == id && agents[i].wetness >= 0)
            {
                if(agentNr == teamNr)
                {
                    teamInd = agents[i].id;
                    break;
                }
                teamNr++;
            }
        }
        //cerr << agentNr << " -- " << teamNr << " :: " << teamInd << endl;
    
        int targetInd = 0;
        int m = INT_MAX;
        int w = 0;
        for(int i=0;i<agents.size();i++)
        {
            if(agents[i].player != id && agents[i].wetness > w)
            {
                w = agents[i].wetness;
                targetInd = agents[i].id;
            }
            else if(agents[i].player != id && agents[i].wetness >= 0)
            {
                int dis = Utils::distance(agents[teamInd].x, agents[teamInd].y, agents[targetInd].x, agents[targetInd].y);
                if(dis < m)
                {
                    dis = m;
                    targetInd = agents[i].id;
                }
            }
        }

        //printAgents();
        int dis = Utils::distance(agents[teamInd].x, agents[teamInd].y, agents[targetInd].x, agents[targetInd].y);
        if(dis <=  4 && agents[teamInd].numBombs > 0 && safeBomb(agents[targetInd].x, agents[targetInd].y))
        {
            cout << teamInd + 1 << "; MOVE " << agents[targetInd].x << " " << agents[targetInd].y <<
            "; THROW " << agents[targetInd].x << " " << agents[targetInd].y << endl;
        }
        else if(dis <  agents[teamInd].optimalRange * 2 && agents[teamInd].cd == 0)
        {
            cout << teamInd + 1 << "; MOVE " << agents[targetInd].x << " " << agents[targetInd].y <<
            "; SHOOT " << targetInd + 1 << endl;
        }
        else
        {
            cout << teamInd + 1 << "; MOVE " << agents[targetInd].x << " " << agents[targetInd].y << "; HUNKER_DOWN" << endl;
        }
    }

    bool isTeamDead(int team)
    {
        for(int i=0;i<agents.size();i++)
        {
            if(agents[i].player == team && agents[i].wetness != -1)
                return false;
        }
        return true;
    }

    bool isValidToMove(int x, int y)
    {
        if((x >= 0 && x < width) && (y >= 0 && y < height) && map[x][y] == 0)
        {
            for(int k=0;k<agents.size();k++)
                if(agents[k].wetness != -1 && agents[k].x == x && agents[k].y == y)
                    return false;
            return true;
        }

        return false;
    }

    bool isAgentInRange(int agentTeamID, int agentEnemyID, int x, int y)
    {
        int rangeAgent = agents[agentTeamID].optimalRange;

        int dis = Utils::distance(x, y, 
            agents[agentEnemyID].x, agents[agentEnemyID].y);
        if(rangeAgent * 2 >= dis)
            return true;
        else
            return false;
    }

    void countPoints()
    {
        int team = 0, enemy = 0;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int m = INT_MAX;
                int side = -1;
                for(int k=0;k<agents.size();k++)
                {
                    if(isAgentAlive(agents[k]))
                    {
                        int wetnessScoreFactor = 1;
                        if(agents[k].wetness >= 50)
                            wetnessScoreFactor = 2;
                        int dis = wetnessScoreFactor * Utils::distance(j, i, 
                                    agents[k].x, agents[k].y);
                        if(dis < m)
                        {
                            m = dis;
                            side = agents[k].player;
                        }
                        else if(dis == m && side != agents[k].player)
                        {
                            //2 represents a draw
                            m = dis;
                            side = 2;
                        }
                    }        
                }

                if(side == id)
                    team++;
                else if(side == !id)
                    enemy++;
            }
        }

        if(team >= enemy)
            scoreTeam += team - enemy;
        else
            scoreEnemy += enemy - team;
    }

    void turnEnd()
    {
        turns++;
    }

protected:
    void printAgents()
    {
        for(int i=0;i<agents.size();i++)
        {
            cerr << "Agent " << agents[i].id + 1 << ": team: " << agents[i].player << "  x: " << 
            agents[i].x << "  y: " << agents[i].y << " wetness: " << agents[i].wetness << 
            " shootCD: " << agents[i].cd << endl; 
        }
    }

    void printMap()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cerr << map[i][j];
            }
            cerr << endl;
        }
    }

    bool isAgentAlive(Agent &a)
    {
        if(a.wetness == -1)
            return false;

        return true;
    }

    void updateDeadAgents()
    {
        for(int i=0;i<agents.size();i++)
        {
            if(!agents[i].alive)
            {
                agents[i].wetness = -1;
            }
            agents[i].alive = false;
        }
    }
};

class Minimax
{
public:
    typedef tuple<int,int,int,int,int> action;
    typedef vector< vector< action>> actionList;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;   

    Minimax() : startTime(std::chrono::high_resolution_clock::now()) {}

    void generateCombinations(const actionList& actions, int idx, vector<action>& current, 
        vector<vector<action>>& result)
    {
        if (idx == actions.size())
        {
            result.push_back(current);
            return;
        }
        for (const action& a : actions[idx])
        {
            current.push_back(a);
            generateCombinations(actions, idx + 1, current, result);
            current.pop_back();
        }
    }

    bool terminal(Game &simulation)
    {
        if(simulation.isTeamDead(simulation.id) || simulation.isTeamDead(!simulation.id))
            return true;
        if(max(simulation.scoreTeam, simulation.scoreEnemy) > 
            min(simulation.scoreTeam, simulation.scoreEnemy) + 600)
            return true;
        if(simulation.turns > 100)
            return true;

        return false;
    }

    int value(Game &simulation)
    {
        int val = 0;
        for (int i : simulation.idTeam)
            if(simulation.agents[i].wetness != -1)
                val += 100 - simulation.agents[i].wetness;
        for (int i : simulation.idEnemy)
        {
            if(simulation.agents[i].wetness != -1)
                val -= 100 - simulation.agents[i].wetness;
            else
                val += 100;
        }
        return val + 5 * (simulation.scoreTeam - simulation.scoreEnemy);
    }

    actionList actions(Game &simulation, const vector<int> &simulationTeam, const vector<int> &simulationEnemy)
    {
        actionList actionMoves(simulation.idTeam.size());

        int teamOrder = 0;
        for(auto agentTeamID : simulationTeam)
        {
            if(simulation.agents[agentTeamID].wetness != -1)
            {
                int x = simulation.agents[agentTeamID].x;
                int y = simulation.agents[agentTeamID].y;

                for(auto agentEnemyID : simulationEnemy)
                {
                    if(simulation.isAgentInRange(agentTeamID, agentEnemyID, x, y) && simulation.agents[agentTeamID].cd == 0)
                        actionMoves[teamOrder].push_back({3, agentTeamID, x, y, agentEnemyID});
                    else
                        actionMoves[teamOrder].push_back({1, agentTeamID, x, y, 0});
                }

                if(simulation.isValidToMove(x, y - 1))
                {
                    for(auto agentEnemyID : simulationEnemy)
                    {
                        if(simulation.isAgentInRange(agentTeamID, agentEnemyID, x, y - 1) && simulation.agents[agentTeamID].cd == 0)
                            actionMoves[teamOrder].push_back({3, agentTeamID, x, y - 1, agentEnemyID});
                        else
                            actionMoves[teamOrder].push_back({1, agentTeamID, x, y - 1, 0});
                    }
                }

                if(simulation.isValidToMove(x + 1, y))
                {
                    for(auto agentEnemyID : simulationEnemy)
                    {
                        if(simulation.isAgentInRange(agentTeamID, agentEnemyID, x + 1, y) && simulation.agents[agentTeamID].cd == 0)
                            actionMoves[teamOrder].push_back({3, agentTeamID, x + 1, y, agentEnemyID});
                        else
                            actionMoves[teamOrder].push_back({1, agentTeamID, x + 1, y, 0});
                    }
                }

                if(simulation.isValidToMove(x, y + 1))
                {
                    for(auto agentEnemyID : simulationEnemy)
                    {
                        if(simulation.isAgentInRange(agentTeamID, agentEnemyID, x, y + 1) && simulation.agents[agentTeamID].cd == 0)
                            actionMoves[teamOrder].push_back({3, agentTeamID, x, y + 1, agentEnemyID});
                        else
                            actionMoves[teamOrder].push_back({1, agentTeamID, x, y + 1, 0});
                    }
                }

                if(simulation.isValidToMove(x - 1, y))
                {
                    for(auto agentEnemyID : simulationEnemy)
                    {
                        if(simulation.isAgentInRange(agentTeamID, agentEnemyID, x - 1, y) && simulation.agents[agentTeamID].cd == 0)
                            actionMoves[teamOrder].push_back({3, agentTeamID, x - 1, y, agentEnemyID});
                        else
                            actionMoves[teamOrder].push_back({1, agentTeamID, x - 1, y, 0});
                    }
                }

                //possiveis throw de bombas hmm
                teamOrder++;
            }
        }

        return actionMoves;
    }

    Game result(Game simulation, vector<action> &actionMoves)
    {
        //collision problem?
        vector<bool> defense(simulation.agents.size(), false);
        for(action agentMove : actionMoves)
        {
            simulation.agents[get<1>(agentMove)].x = get<2>(agentMove);
            simulation.agents[get<1>(agentMove)].y = get<3>(agentMove);
            if(get<0>(agentMove) == 1)
                defense[get<1>(agentMove)] = true;
        }

        for(action agentMove : actionMoves)
        {
            int agentID = get<1>(agentMove);
            if(get<0>(agentMove) == 3 && simulation.agents[agentID].cd == 0)
            {
                int targetID = get<4>(agentMove);

                simulation.agents[targetID].wetness += simulation.agents[agentID].soakingPower;
                if (simulation.agents[targetID].wetness >= 100)
                    simulation.agents[targetID].wetness = -1;
                simulation.agents[agentID].cd = simulation.agents[agentID].shootCD + 1;
            }
        }

        for (auto &a : simulation.agents)
            if (a.cd > 0)
                a.cd--;

        simulation.countPoints();
        simulation.turnEnd();

        return simulation;
    }

    pair<int, vector<Minimax::action>> execute(Game simulation, int depth, bool isMaximizingPlayer, int alpha, int beta)
    {
        auto now = std::chrono::high_resolution_clock::now();
        int elapsed = duration_cast<std::chrono::milliseconds>(now - startTime).count();

        if (elapsed > 40)
        {
            return {value(simulation), {}};
        }

        if(terminal(simulation) || depth >= MAX_DEPTH)
            return {value(simulation), {}};

        simulation.idTeam.clear();
        simulation.idEnemy.clear();
        for (int i = 0; i < simulation.agents.size(); ++i)
        {
            if (simulation.agents[i].wetness != -1)
            {
                if (simulation.agents[i].player == simulation.id)
                    simulation.idTeam.push_back(i);
                else
                    simulation.idEnemy.push_back(i);
            }
        }

        actionList actionsAgents;
        if(isMaximizingPlayer)
            actionsAgents = actions(simulation, simulation.idTeam, simulation.idEnemy);
        else
            actionsAgents = actions(simulation, simulation.idEnemy, simulation.idTeam);

        vector<vector<action>> allCombinations;
        vector<action> current;
        generateCombinations(actionsAgents, 0, current, allCombinations);

        vector<action> bestMoves;
        if(isMaximizingPlayer)
        {
            int bestValue = INT_MIN;
            for (auto& moveSet : allCombinations)
            {
                auto [val, _] = execute(result(simulation, moveSet), depth + 1, !isMaximizingPlayer, alpha, beta);
                if (val > bestValue)
                {
                    bestValue = val;
                    bestMoves = moveSet;
                }
                
                alpha = max(alpha, bestValue);
                if (beta <= alpha) 
                    break;
            }

            return {bestValue, bestMoves};
        }
        else
        {
            int bestValue = INT_MAX;
            for (auto& moveSet : allCombinations)
            {
                auto [val, _] = execute(result(simulation, moveSet), depth + 1, !isMaximizingPlayer, alpha, beta);
                if (val < bestValue)
                {
                    bestValue = val;
                    bestMoves = moveSet;
                }

                beta = min(beta, bestValue);
                if (beta <= alpha)
                    break;
            }

            return {bestValue, bestMoves};
        }
    }
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    Game *game = new Game();

    while (1)
    {
        game->readAgents();

        Minimax ai;
        auto [score, bestMoves] = ai.execute(*game, 0, true, INT_MIN, INT_MAX);
        cerr << "[MINIMAX] Best score: " << score << ", Moves: " << bestMoves.size() << endl;

        map<int, Minimax::action> agentActions;
        for (const auto& a : bestMoves)
        {
            int agentID = get<1>(a);
            if (!agentActions.count(agentID))
                agentActions[agentID] = a;
        }

        int my_agent_count; // Number of alive agents controlled by you
        cin >> my_agent_count; cin.ignore();
        for (int i = 0; i < my_agent_count; i++)
        {
            int teamAgentID = game->idTeam[i];
            if (agentActions.count(teamAgentID))
            {
                const auto& a = agentActions[teamAgentID];
                int actionType = get<0>(a);
                int x = get<2>(a);
                int y = get<3>(a);
                int target = get<4>(a);

                cout << teamAgentID + 1 << "; MOVE " << x << " " << y;
                if (actionType == 3)
                    cout << "; SHOOT " << target + 1;
                else
                    cout << "; HUNKER_DOWN";
                cout << endl;
            }
            else
            {
                game->choose(i);
            }
        }
        cerr << game->scoreTeam << " vs " << game->scoreEnemy << endl;

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::milliseconds>(end - start);
        cerr << duration.count() << endl;
    }
}
