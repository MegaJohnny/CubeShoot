#include<iostream>
#include<SFML/Window.hpp>
#include<map.cpp>
#include<gamefunctions.cpp>

int main() {

    int winWidth = 800;
    int winHeight = 600;

    sf::WindowSettings winSettings;
    winSettings.DepthBits = 24;
    winSettings.StencilBits = 8;
    winSettings.AntialiasingLevel = 0;
    sf::Window window(sf::VideoMode(800, 600, 32), "First Person Shooter",
                      sf::Style::Close, winSettings);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, (GLdouble)winWidth/winHeight, 1.0, 500.0);
    glMatrixMode(GL_MODELVIEW);

    sf::Clock gameClock;
    float curTime = gameClock.GetElapsedTime();

    gameInit();

    while (window.IsOpened()) {

        sf::Event event;
        while (window.GetEvent(event)) {
            if (event.Type == sf::Event::Closed) {
                window.Close();
            }

            if (event.Type == sf::Event::Resized) {
                std::cout << "Resized" << std::endl;
                glViewport(0, 0, event.Size.Width, event.Size.Height);
                winWidth = event.Size.Width;
                winHeight = event.Size.Height;
            }
        }

        float newTime = gameClock.GetElapsedTime();
        float dt = newTime-curTime;

        gameUpdate(dt);

        gameDraw();

        window.Display();
        curTime = newTime;
    }

    return 0;
}
