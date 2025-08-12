#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "GameObject.h"
#include "Enemy.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "OOP Game");
    sf::Clock deltaClock;

    std::vector<GameObject*> gameObjects;   // GameObjects 포인터들을 담을 공구함

    gameObjects.push_back(new Player()); // 힙에 Player 생성, 그 '주소'를 공구함에 넣기

    for (int i = 0; i < 3; i++)
    {
        gameObjects.push_back(new Enemy());
    }

    while(window.isOpen())
    {
        for (auto objA : gameObjects)
        {
            for (auto objB : gameObjects)
            {
                Player* player = dynamic_cast<Player*>(objA);
                Enemy* enemy = dynamic_cast<Enemy*>(objB);

                if (player != nullptr && enemy != nullptr)
                {
                    std::cout << "Dynamic_cast check:: Plyer and Enemy detected!!!" << std::endl;
                }
            }
        }
        
        sf::Time dt = deltaClock.restart();

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
    }

    for (GameObject* obj : gameObjects)
    {
        delete obj;
    }

    gameObjects.clear();
}