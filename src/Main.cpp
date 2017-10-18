
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "Ball.h"
//#include <Ball.h>


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Define some constants
    const float pi = 3.14159f;
    const int gameWidth = 800;
    const int gameHeight = 600;
    
    // Define objects
    Ball* testBall = new Ball(30,30,0,0,20);
    testBall->setColor(sf::Color::White);
    
    
    sf::CircleShape testCircle;
    testCircle.setRadius(20);
    testCircle.setOutlineThickness(3);
    testCircle.setOutlineColor(sf::Color::Black);
    testCircle.setFillColor(sf::Color::White);
    testCircle.setOrigin(30, 30);
    
    
    // Create the window of the application
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "SFML Pong", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    //testBall->scale(window.getPosition().x, window.getPosition().y);
    //testBall->scale(2, 1);

    // Load the sounds used in the game
    sf::SoundBuffer ballSoundBuffer;
    if (!ballSoundBuffer.loadFromFile("resources/ball.wav"))
        return EXIT_FAILURE;
    sf::Sound ballSound(ballSoundBuffer);

    // Load the text font
    sf::Font font;
    if (!font.loadFromFile("resources/sansation.ttf"))
        return EXIT_FAILURE;

    // Initialize the pause message
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(40);
    pauseMessage.setPosition(170.f, 150.f);
    pauseMessage.setFillColor(sf::Color::Red);
    pauseMessage.setString("This is a pause message");

    sf::Clock clock;
    bool isPlaying = false;
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }
            
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::P)) {
                isPlaying = !isPlaying;
            }

            // Space key pressed: play
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {
                if (!isPlaying)
                {
                    // (re)start the game
                    isPlaying = true;
                    clock.restart();

                    // Reset the position of the paddles and ball
                    testBall->setX(0);
                    testBall->setY(0);
                }
            }
        }

        if (isPlaying) {
            float deltaTime = clock.restart().asSeconds();
        }
        
        testBall->setPos(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

        // Clear the window
        window.clear(sf::Color(100, 200, 100));

        if (isPlaying) {
            // Draw the paddles and the ball
            window.draw(testBall->getCircle());
        }
        else {
            // Draw the pause message
            window.draw(pauseMessage);
        }

        // Display things on screen
        window.display();
    }

    return EXIT_SUCCESS;
}
