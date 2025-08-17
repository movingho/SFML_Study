#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "GameObject.h"
#include "Enemy.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "OOP Game");
    sf::Clock deltaClock;

    std::vector<GameObject*> gameObjects;   // GameObjects 포인터들을 담을 공구함

    gameObjects.push_back(new Player()); // 힙에 Player 생성, 그 '주소'를 공구함에 넣기

    for (int i = 0; i < 3; i++)
    {
        gameObjects.push_back(new Enemy());
    }

    while (window.isOpen())
    {


        sf::Time dt = deltaClock.restart();
        for (size_t i = 0; i < gameObjects.size(); ++i)
        {
            for (size_t j = i + 1; j < gameObjects.size(); ++j)
            {
                GameObject* objA = gameObjects[i];
                GameObject* objB = gameObjects[j];

                auto typeA = objA->getType();
                auto typeB = objB->getType();

                if ((typeA == ObjectType::Player && typeB == ObjectType::Enemy) ||
                    (typeA == ObjectType::Enemy && typeB == ObjectType::Player))
                {
                    {
                        if (objA->getBounds().findIntersection(objB->getBounds()))
                        {
                            GameObject* enemy_to_destroy = (typeA == ObjectType::Enemy) ? objA : objB;
                            enemy_to_destroy->destroy();
                        }
                    }
                }
            }

        }

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        for (GameObject* obj : gameObjects)
        {
            obj->update(dt);
        }

        window.clear(sf::Color::Black);

        for (GameObject* obj : gameObjects)
        {
            obj->draw(window);
        }

        window.display();

        std::vector<GameObject*> survivors;

        for (GameObject* obj : gameObjects)
        {
            if (obj->isActive())
            {
                survivors.push_back(obj);
            }
            else
            {
                delete obj;
            }
        }
        gameObjects = survivors;
    }

    for (GameObject* obj : gameObjects)
    {
        delete obj;
    }

    gameObjects.clear();
}