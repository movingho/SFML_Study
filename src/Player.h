#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"


class Player : public GameObject // 클래스 상속은 기본이 private, 다형성 쓰려면 public
{
public:
    Player();
    void update(sf::Time dt) override;
    void move(sf::Vector2f velocity);
    void draw(sf::RenderWindow& window) override;

private:
    sf::RectangleShape m_rectangle;
    const float m_moveSpeed = 300.f;
};
