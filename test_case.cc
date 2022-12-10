#include "catch.hpp"
#include <sstream>
#include "context.h"
#include "player.h"
//#include "game_object.h"
#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>
#include "Helicopter.h"

using namespace std;


TEST_CASE ("player")
{
    
    //read file
    std::ifstream file("settings.json");
    //json reader
    Json::Reader reader;
    //contain complete JSON data
    Json::Value settings;
    // reader reads the data and stores it in settings
    reader.parse(file, settings);

    sf::Clock clock;

    std::vector<Game_object*>  objects{};
    std::vector<Game_object*>  new_objects{};
    std::vector<Game_object*>  players{};
    Game_object*               current_player{};
    bool                       new_turn{false};
    //sf::Vector2f               hit_pos{0,0};
    Game_object*               missile{nullptr};


    //Context context{clock.restart(), nullptr, nullptr, objects, new_objects, players, current_player, new_turn, hit_pos, settings};
    Context context{clock.restart(), nullptr, nullptr, objects, new_objects, players, current_player, new_turn, missile, settings};
    SECTION("create")
    {   
        Helicopter* helicopter = new Helicopter{context};
        //Player* player = new Player{"textures_new/blue_tank.png","textures_new/blue_barrel.png", "virro", context};
        
    }

}



