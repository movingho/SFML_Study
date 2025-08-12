#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <random>

class Enemy : public GameObject {
public:
	Enemy();
	void update(sf::Time dt) override;
	void draw(sf::RenderWindow& window) override;
private:
	sf::CircleShape m_circle;
	const float m_moveSpeed = 250.f;

	std::mt19937_64 m_engine;	// 랜덤한 수 생성
	std::uniform_int_distribution<int> m_distribution;	// 균등 정수 분포
};