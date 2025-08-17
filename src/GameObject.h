#pragma once
#include <SFML/Graphics.hpp>

enum class ObjectType {
	None,
	Player,
	Enemy
};

class GameObject {
public:
	virtual ~GameObject() {}	// 가상 소멸자
	virtual void update(sf::Time dt) = 0;	// 순수 가상 함수: 날 상속받을 거면 update 무조건 구현해라
	virtual void draw(sf::RenderWindow& window) = 0; // 순수 가상
	virtual ObjectType getType() const = 0;	// 순수 가상
	virtual bool isActive() const { return m_active; }
	virtual void destroy() { m_active = false; }
	virtual sf::FloatRect getBounds() const = 0;
private:
	bool m_active = true;
	
};