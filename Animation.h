#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, int startIndex, int endIndex);
    ~Animation();

    sf::IntRect uvRect;

    void Update(int row, float deltaTime);

private:
    sf::Vector2u imageCount; // Quantidade de imagens por linha (x) e quantidade de linhas (y)
    sf::Vector2u currentImage; // Posicao atual do uvRect na textura
    int startIndex;
    int endIndex;
    float totalTime;
    float switchTime;
};