#pragma once
#include <SFML/Graphics.hpp>

enum class ObjectType {
	None,
	Player,
	Enemy
};

class GameObject {
public:
	virtual ~GameObject() {}	// ���� �Ҹ���
	virtual void update(sf::Time dt) = 0;	// ���� ���� �Լ�: �� ��ӹ��� �Ÿ� update ������ �����ض�
	virtual void draw(sf::RenderWindow& window) = 0; // ���� ����
	virtual ObjectType getType() const = 0;	// ���� ����
	virtual bool isActive() const { return m_active; }
	virtual void destroy() { m_active = false; }
	virtual sf::FloatRect getBounds() const = 0;
private:
	bool m_active = true;
	
};