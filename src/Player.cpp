#include "Player.h"

Player::Player() : m_rectangle({ 100.f, 100.f })
{
	m_rectangle.setFillColor(sf::Color::Blue);
}

void Player::move(sf::Vector2f velocity)
{
	m_rectangle.move(velocity);
}

void Player::update(sf::Time dt)
{
	sf::Vector2f direction(0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		direction.y = -1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		direction.y = 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		direction.x = -1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		direction.x = 1.f;
	}

	if (direction.x != 0 || direction.y != 0)
	{
		float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

		direction.x /= length;
		direction.y /= length;
	}

	

	move(direction * m_moveSpeed * dt.asSeconds());
}
void Player::draw(sf::RenderWindow& window)
{
	window.draw(m_rectangle);
}

ObjectType Player::getType() const
{
	return ObjectType::Player;
}