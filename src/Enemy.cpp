#include "Enemy.h"
#include <SFML/Graphics.hpp>


Enemy::Enemy()
	: m_circle(40.f),
	m_distribution(-1, 1)
{	
	m_circle.setFillColor(sf::Color::Red);

	std::random_device rd;	// 난수 rd 생성
	m_engine.seed(rd());	// 난수 rd를 딜러 (m_engine)에게 줌, 카드 순서 초기화

	std::uniform_int_distribution<int> x_dist(0, 720);
	m_circle.setPosition(sf::Vector2f(static_cast<float>(x_dist(m_engine)), 50.f));
}

void Enemy::update(sf::Time dt)
{
	int directionX = m_distribution(m_engine);

	sf::Vector2f velocity(directionX * m_moveSpeed * dt.asSeconds(), 0.f);
	m_circle.move(velocity);
}


void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(m_circle);
}
