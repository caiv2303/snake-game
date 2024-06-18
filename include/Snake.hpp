#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

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