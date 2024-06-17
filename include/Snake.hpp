#pragma once

#include <list>
#include <SFML/Graphics.hpp>

class snake: public sf::Drawable
{
public:
    snake();
    void init(const sf::Texture& texture);
    void move (const sf:: Vector2f& direction);
    bool isOn(const sf::Sprite& other) const;
    void grow (const sf::Vector2f& direction);
    bool isSelfIntersecting () const;
    void draw(sf::RenderTarget& target, sf::RenderStates) cosnt override;
private:
    std::list<sf::Sprite> body;
    std::list<sf::Sprite>::iterator head;
    std::list<sf::Sprite>::iterator tail;
};