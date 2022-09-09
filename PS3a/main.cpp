// Copyright 2019 Adam Baptista

#include <memory>
#include <vector>

#include "planets.cpp"

#define BACKGROUND "nbody/starfield.jpg"

Vector2u WINSIZE, backSize;

istream &operator>> (istream &in, Body &b);

int main(int argc, char* argv[]) {
    int N;
    double R;
    vector<shared_ptr<Body>> bodies;
    Sprite background;
    Texture texture;
    if (!texture.loadFromFile(BACKGROUND)) {
        cout << "Failed to load background" << endl;
        return EXIT_FAILURE;
    }


    backSize = texture.getSize();
    RenderWindow window(VideoMode(backSize.x, backSize.y), "NBody");
    WINSIZE = window.getSize();  // gets the window size

    double xScale = static_cast<double>(WINSIZE.x / backSize.x);
    double yScale = static_cast<double>(WINSIZE.y / backSize.y);


    background.setTexture(texture);
    background.setScale(xScale, yScale);

    window.setFramerateLimit(60);

    cin >> N;
    cin >> R;
    for (int i = 0; i < N; i++) {
        shared_ptr<Body> ptrBody(new Body());
        cin >> *ptrBody;
        double x = ((ptrBody->getPos().x/R) * WINSIZE.x/2);
        double y = ((ptrBody->getPos().y/R) * WINSIZE.y/2);
        ptrBody->sprite.setPosition(WINSIZE.x/2 + x, WINSIZE.y/2 + y);
        bodies.push_back(ptrBody);
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed ||
                Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();

        window.clear();
        window.draw(background);

        for (unsigned int i = 0; i < bodies.size(); i++)
            window.draw(*bodies[i]);

        window.display();
    }
    return 0;
}
