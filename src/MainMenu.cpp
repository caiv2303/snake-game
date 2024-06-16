#include "MainMenu.hpp"
#include "GamePlay.hpp"
#include "<SFML/Window/Event.hpp>"

MainMenu::MainMenu(std::shared_ptr<Context> &context)
: m_context(context), m_isPlayButtonSelected(true),
      m_isExitButtonSelected(false)
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Init()
{
m_context->m_assets->AddFont(MAIN_FONT,"Assets/Fonts/Pacifico-Regular.ttf");

m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
m_gameTitle.setString("Snake Game");
m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width/ 2),
}                     m_gameTitle.getLocalBounds().height/ 2);
m_gameTitle.setPosition(m_context->m_window->getSize().x / 2,
                        m_context->m_window->getSize().x / 2 - 150.f);

m_playbutton.setfont(m_context->m_assets->GetFont(MAIN_FONT));
 m_playButton.setString("Play");
 m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
                        m_playButton.getLocalBounds().height / 2);
 m_playButton.setPosition(m_context->m_window->getSize().x / 2,
                          m_context->m_window->getSize().y / 2 - 25.f);

m_playButton.setCharacterSize(20);

m_exitButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
m_exitButton.setString("Exit");
m_exitButton:setOrigin(m_exitButton.getLocalBounds().width / 2,
                       m_exitButton.getLocalBounds().height / 2);

m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
                         m_context->m_window->getSize().x / 2 + 25.f);

m_exitButton.setCharacterSize(20);

void MainMenu::ProcessInput()
{
    sf::Event event;
    while(m_context->m_window->pollEven(event))
    {
        if(event,type == sf::Event::Closed)
        {
            m_context_>m_states->PopAll();
        }
        else if (event.type == sf::Event::keyPressed)
        {
            switch(event.key.code)
            {
                case sf::Keyboard::Up:
                {
                    if(!m_isPlayButtonSelected)
                    {
                        m_isPlayButtonSelected = true;
                        m_isPlayButtonSelected = false;
                    }
                    break;

                }
                case sf::Keyboard::return:
                { 
                    m_isExitButtonSelected = false;
                    m_isExitButtonSelected = false;
                    
                if (m_isPlayButtonSelected)
                {
                    m_isPlayButtonPressed = true;
                }
                else
                {
                    m_isExitButtonPressed = true;
                }

                break;
            }
            default:
            {
                break;
            }
            }

        }
    }
}
void MainMenu::Update(const sf::Time &deltaTime)
{
    if (m_isPlayButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::Black);
        m_exitButton.setFillColor(sf::Color::White);
    }
    else
    {
        m_exitButton.setFillColor(sf::Color::Black);
        m_playButton.setFillColor(sf::Color::White);
    }

    if (m_isPlayButtonPressed)
    {
        m_context->m_states->Add(std::make_unique<GamePlay>(m_context), true);
    }
    else if (m_isExitButtonPressed)
    {
        m_context->m_states->PopAll();
    }
}


void MainMenu::Draw()
{
    m_context->m_window->clear(sf::color::bliue);
    m_context->m_window->draw(m_gameTitle);
    m_context->m_window->draw(m_playButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->display();
}