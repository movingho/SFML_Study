#pragma once
#include <SFML/Graphics.hpp>
class GameObject {
public:
	virtual ~GameObject() {}	// ���� �Ҹ���
	virtual void update(sf::Time dt) = 0;	// ���� ���� �Լ�: �� ��ӹ��� �Ÿ� update ������ �����ض�
	virtual void draw(sf::RenderWindow& window) = 0; // ����
};