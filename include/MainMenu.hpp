#pragma
#include <memory>
#include<SFML/praphics/text.hpp>
#include "State.hpp"
#include "Game.hpp"

class MainMenu : public Engine::State
{
    private:
    std::shared_ptr<Context> m_context;
    sf::text m_gameTitle;
    sf::Text m_PlatButton;
    sf::text m_exitButton;

    bool m_isPlayButtonSelected;
    bool m_isPlayButtonPressed;
    bool m_isExitButtonSelected;
    bool m_isExitButtonPressed;

public:

    MainMenu(std::shared_ptr<context> &context);
    MainMenu();
    void Init() override;
    void ProcessImput() override;
    void Update(cost sf::Time& deltaTime) override;
    void Draw() override;

};