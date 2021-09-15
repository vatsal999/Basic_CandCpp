#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // create window
    //sf::Window window(sf::VideoMode(x,y),"TITLE",sf::style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(1280, 720), "MyApp");

    // make application refresh rate equal to monitor
    //window.setVerticalSyncEnabled(true);

    // set application refresh rate
    window.setFramerateLimit(60);

    sf::Texture rocketTexture;
    rocketTexture.loadFromFile("./camera.png");

    sf::Sprite rocket(rocketTexture);

    sf::Vector2u size = rocketTexture.getSize();
    rocket.setOrigin(size.x / 2, size.y / 2);
    sf::Vector2f increment(5.0f, 10.0f);

    



    //
    //run program as long as window in open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;


        //
        //MOUSE EVENTS
        //
        /* if (event.type == sf::Event::MouseMoved) */
        /* { */
        /*     std::cout << "new mouse x: " << event.mouseMove.x << std::endl; */
        /*     std::cout << "new mouse y: " << event.mouseMove.y << std::endl; */
        /* } */


        while (window.pollEvent(event))
        {
            // close window when requested
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if((rocket.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0))
                {
                // Reverse the direction on X axis.
                increment.x = -increment.x;
                rocket.setColor(sf::Color::Green);
                }
        if((rocket.getPosition().x - (size.x /2) < 0 && increment.x < 0))
        {
                increment.x = -increment.x;
                rocket.setColor(sf::Color::Red);

        }

        if((rocket.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0))
                {
                // Reverse the direction on Y axis.
                increment.y = -increment.y;
                rocket.setColor(sf::Color::Blue);
                }
        if(rocket.getPosition().y - (size.y /2) < 0 && increment.y < 0)
        {
                increment.y = -increment.y;
                rocket.setColor(sf::Color::Yellow);

        }

        rocket.setPosition(rocket.getPosition() + increment);



        /* window.clear(sf::Color::White); */
        window.clear();

        window.draw(rocket);

        window.display();
    }
    return 0;


}
