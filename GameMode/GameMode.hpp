#ifndef GAMEMODE_HPP_INCLUDED
#define GAMEMODE_HPP_INCLUDED

#include "../Core/GameState.hpp"
#include "../Human.hpp"
#include "../IA/IA.hpp"
#include "../Map.hpp"
#include "../Core/FontManager.hpp"
#include <iostream>

struct KillData {
    std::string killer,
                victim;
    int team_killer;
};

class GameMode : public GameState
{
protected:
    sf::View view;
    void adapt_view_to_window();

    TextureManager textureManager;
    FontManager fontManager;
    void load_textures();

    Map map;
    std::map<std::string, Tank*> tanks;
    std::vector<Bullet*> bullets;

    std::stack<KillData> kills;

    std::string mainPlayer; //Char contr�l� par le joueur
    //Centre la view sur ce char
    std::string tankToFollow;
    void scrolling();

    void limit_dt(float& dt);
    void get_bullet(Tank* tank);
    void handleCollision(Tank* tank, float dt);
    void align_player_barrel();
    void update_bullets(float dt);
    sf::Vector2f generate_pos();

public:
    GameMode(Game* game);
    virtual ~GameMode();

    virtual void handleInput();
    virtual void update(float dt) = 0;
    virtual void draw();
};

#endif // GAMEMODE_HPP_INCLUDED
