#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <random>

class Enemy : public GameObject {
public:
	Enemy();
	void update(sf::Time dt) override;
	void draw(sf::RenderWindow& window) override;
	ObjectType getType() const override;
	sf::FloatRect getBounds() const override;
private:
	sf::CircleShape m_circle;
	const float m_moveSpeed = 250.f;
	float m_enemyHealth = 99.9f;

	std::mt19937_64 m_engine;	// ������ �� ����
	std::uniform_int_distribution<int> m_distribution;	// �յ� ���� ����
};