#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "State.hpp"
class GameOver : public Engine::State
{
public:
    GameOver(std::shared_ptr<Context> &context);
    void Init() override;
    void ProcessInput() override;
    void Update(const sf::Time& deltaTime) override;
    void Draw() override;
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_gameOverTitle;
    sf::Text m_retryButton;
    sf::Text m_exitButton;
    bool m_isRettryButtonSelected, m_isRetryButtonPressed;
    bool m_isExitButtonSelected, m_isExitButtonPressed;
};