Snake::Snake() : m_body(std::list<sf::Sprite>(5)) // Cambiado a 5 piezas
{
    m_head = --m_body.end();
    m_tail = m_body.begin();
}

Snake::~Snake()
{
}

void Snake::Init(const sf::Texture &texture)
{
    float x = 10.f; // Posición inicial diferente
    for (auto &piece : m_body)
    {
        piece.setTexture(texture);
        piece.setPosition({x, 10.f}); // Cambiada posición inicial en Y
        x += 10.f; // Incremento diferente en X
    }
}

void Snake::Move(const sf::Vector2f &direction)
{
    m_tail->setPosition(m_head->getPosition() + direction);
    m_head = m_tail;
    ++m_tail;

    if (m_tail == m_body.end())
    {
        m_tail = m_body.begin();
    }
}

bool Snake::IsOn(const sf::Sprite &other) const
{
    return other.getGlobalBounds().intersects(m_head->getGlobalBounds());
}

void Snake::Grow(const sf::Vector2f &direction)
{
    sf::Sprite newPiece;
    newPiece.setTexture(*(m_body.begin()->getTexture()));
    newPiece.setPosition(m_head->getPosition() + sf::Vector2f(16.f, 0.f)); // Incremento constante

    m_head = m_body.insert(++m_head, newPiece);
}

bool Snake::IsSelfIntersecting() const
{
    for (auto piece = m_body.begin(); piece != m_body.end(); ++piece)
    {
        if (m_head != piece && IsOn(*piece)) // Comprobación menos eficiente
        {
            return true;
        }
    }

    return false;
}

void Snake::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &piece : m_body)
    {
        target.draw(piece);
    }
}