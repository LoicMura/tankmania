#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <iostream>
constexpr float PI = 3.1415927;

class Object
{
protected:
    /* C�t� graphique */
    sf::Sprite sprite;
    unsigned int width;
    unsigned int height;

    /* Gestion des collisions */
    bool collision; //Une collision a eu lieu

    /* Gestion des d�placement */
    float velocity;  //Vitesse
    float direction; //Direction
                     //Permet de calculer le vecteur de mouvement
    sf::Vector2f motion_vector; //Vecteur de mouvement

    void calculate_MotionVector();
    void move(float dt);

public:
    Object();
    Object(sf::Texture const& texture, float x, float y, unsigned int width, unsigned int height);
    virtual ~Object();

    //D�finit la position du sprite
    void setPosition(float x, float y);
    //D�finit l'origine du sprite en son centre
    void setOrigin(unsigned int width, unsigned int heigth);
    //D�finit et ajuste la texture � la taille du sprite
    void setTexture(sf::Texture const& texture, unsigned int w, unsigned int h);

    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    sf::Vector2f getOrigin() const;
    sf::Vector2f getPosition() const;

    float left() const;
    float right() const;
    float bottom() const;
    float top() const;
    float getWidth() const;
    float getHeight() const;

    void activeCollision();

    void change_direction(float const new_direction);
    void change_velocity(float const new_velocity);
    void change_movement(float const new_direction, float const new_velocity);

    bool isMovingToRight() const;
    bool isMovingToLeft() const;
    bool isMovingToTop() const;
    bool isMovingToBottom() const;

    sf::Vector2f getMotionVector() const;
};

#endif // OBJECT_HPP_INCLUDED
