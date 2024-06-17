#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class PauseGame : public Engine::State
{
public:
    PauseGame(std::shared_ptr<Context> &context);
    ~PauseGame();

    void Init() override;
    void ProcessInput() override;
    void Update(const sf::Tiem& deltaTime) override;
    void Draw() override;

private:
    std::shared_ptr<Context> m_context;
    std::Text m_pauseTitle;        
};
