//rank - 4038/7695 - silver league
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>
#include <map>
using namespace std;

/*
    Ou usar vento para defesa + meter um dos elementos em ataque + ver controlo
*/
struct stats
{
    int health;
    int mana;
};

struct entities
{
    int id; // Unique identifier
    int type; // 0=monster, 1=your hero, 2=opponent hero
    int x; // Position of this entity
    int y;
    int shield_life; // Ignore for this league; Count down until shield spell fades
    int is_controlled; // Ignore for this league; Equals 1 when this entity is under a control spell
    int health; // Remaining health of this monster
    int vx; // Trajectory of this monster
    int vy;
    int near_base; // 0=monster with no target yet, 1=monster targeting a base
    int threat_for; // Given this monster's trajectory, is it a threat to 1=your base, 2=your opponent's base, 0=neither
};

void printEntities(vector<entities> list)
{
    int count = 1;
    for(auto &i : list)
    {
        cerr << "Index " << count << "###";
        cerr << "id: " << i.id << " type:" << i.type << " x:" << i.x << " y:" << i.y <<
        " shield_life:" << i.shield_life << " is_controlled:" << i.is_controlled <<
        " health:" << i.health << " vx:" << i.vx << " vy:" << i.vy << " near_base:" <<
        i.near_base << " threat_for:" << i.threat_for << endl;
        count++;
    }
}

vector<int> dangerVisibleSpider(int base_x, int base_y, vector<entities> list)
{
    int count = 0;
    vector<int> idList;
    for(auto& i: list)
    {
        if(i.type == 0)
        {
            int turns = 0;
            while( (i.x >= 0 && i.x <= 17630) && (i.y>=0 && i.y<=9000) )
            {
                i.x += i.vx;
                i.y += i.vy;
                turns++;
                if(turns > 15)
                {
                    break;
                }
                double value = sqrt( (i.x-base_x)*(i.x-base_x) + 
                (i.y-base_y)*(i.y-base_y) );
                //cerr << value << endl;
                if(value <5000)
                {
                    idList.push_back(i.id);
                    count++;
                    break;
                }
            }
            cerr << "Spider id:" << i.id << " simulations:" << turns << " - x:" << i.x << " y:" << i.y << endl;
            cerr << count << endl;
        }
    }
    return idList;
}

int main()
{
    map<int,pair<int,int>> position_guard;
    pair<int,int> close_mob;
    vector<entities> entity_list;
    vector<stats> player_list;

    int base_x; // The corner of the map representing your base
    int base_y;
    cin >> base_x >> base_y; cin.ignore();
    int heroes_per_player; // Always 3
    cin >> heroes_per_player; cin.ignore();

    if(base_x == 0)
    {
        position_guard[0] = make_pair(5000,2200);
        position_guard[1] = make_pair(2800,4800);
        position_guard[2] = make_pair(4000,3000);
    }
    else
    {
        position_guard[0] = make_pair(15700,4000);
        position_guard[1] = make_pair(14000,5200);
        position_guard[2] = make_pair(12500,7500);
    }
    close_mob = make_pair(base_x, base_y);
    // game loop
    while (1)
    {
        entity_list.clear();
        player_list.clear();
        for (int i = 0; i < 2; i++)
        {
            stats playerStruct;
            cin >> playerStruct.health >> playerStruct.mana; cin.ignore();
            player_list.push_back(playerStruct);
        }
        int entity_count; // Amount of heros and monsters you can see
        cin >> entity_count; cin.ignore();
        for (int i = 0; i < entity_count; i++)
        {
            entities entity;
            cin >> entity.id >> entity.type >> entity.x >> entity.y >> 
            entity.shield_life >> entity.is_controlled >> entity.health >> 
            entity.vx >> entity.vy >> entity.near_base >> entity.threat_for; cin.ignore();
            entity_list.push_back(entity);
        
            if(entity.type == 0)
            {
                double value = sqrt( (entity.x-base_x)*(entity.x-base_x) + 
                (entity.y-base_y)*(entity.y-base_y) );
                //cerr << value << endl;
                if(value <5000)
                {
                    close_mob = make_pair(entity.x,entity.y);
                }
            }
        }
        printEntities(entity_list);
        vector<int> dangerousSpiders = dangerVisibleSpider(base_x, base_y, entity_list);

        for (int i = 0; i < heroes_per_player; i++)
        {
            if(dangerousSpiders.size() == 0)
            {
                cout << "MOVE " << position_guard[i].first << " " << position_guard[i].second << endl;
                continue;
            }

            double closest_spider = 20000;
            double closest_spider_base = 20000;
            pair<int,int> closest_dangerous_spider;
            pair<int,int> closest_dangerous_spider_base;
            pair<int,int> direction_closest_dangerous_spider_base;
            for(auto& k : entity_list)
            {
                if(k.type == 0)
                {
                    if ( find(dangerousSpiders.begin(), dangerousSpiders.end(), k.id) 
                    != dangerousSpiders.end() )
                    {
                        double value = sqrt( (entity_list[i].x-k.x)*(entity_list[i].x-k.x) + 
                        (entity_list[i].y-k.y)*(entity_list[i].y-k.y) );
                        if(value < closest_spider)
                        {
                            closest_spider = value;
                            closest_dangerous_spider = make_pair(k.x, k.y);                        
                        }
                        double value_base = sqrt( (base_x-k.x)*(base_x-k.x) + 
                        (base_y-k.y)*(base_y-k.y) );
                        if(value_base < closest_spider_base)
                        {
                            closest_spider_base = value_base;
                            closest_dangerous_spider_base = make_pair(k.x, k.y);    
                            direction_closest_dangerous_spider_base = make_pair(k.vx, k.vy);                    
                        }
                    }
                }
            }
            cerr << closest_spider_base << endl;
            double wind_distance = sqrt( (entity_list[i].x-closest_dangerous_spider_base.first)*(entity_list[i].x-closest_dangerous_spider_base.first) + 
                        (entity_list[i].y-closest_dangerous_spider_base.second)*(entity_list[i].y-closest_dangerous_spider_base.second) );
            cerr << wind_distance << endl;
            if (closest_spider_base < 1500 && wind_distance <= 1280 && i==0)
            {
                cout << "SPELL WIND " << (entity_list[i].x + (-1)*direction_closest_dangerous_spider_base.first)
                 << " " << (entity_list[i].y + (-1)*direction_closest_dangerous_spider_base.second) << endl;
            }
            else if (closest_spider_base < 4000)
            {
                cout << "MOVE " << closest_dangerous_spider_base.first << " " 
                << closest_dangerous_spider_base.second << endl;
            }
            else
            {
                cout << "MOVE " << closest_dangerous_spider.first << " " 
                << closest_dangerous_spider.second << endl;
            }
        }
    }
}
