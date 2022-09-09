#include <sstream>

#include "planets.cpp"

#define BACKGROUND "background.jpg"

Vector2u WINSIZE, backSize;

int main(int argc, char* argv[]) {
    int N;
    double R;
    double T = atoi(argv[1]);
    double deltaT = atoi(argv[2]);
    vector<shared_ptr<Body>> bodies;
    double dx = 0,
           dy = 0,
           r = 0,
           f = 0,
           fX = 0,
           fY = 0;

    RenderWindow window(VideoMode(800, 800), "NBody");
    
    Sprite background;
    Texture texture;
    if (!texture.loadFromFile(BACKGROUND)) {
        cout << "Failed to load background" << endl;
        return EXIT_FAILURE;
    }

    Music music;
    if (!music.openFromFile("HEYYEYAAEYAAAEYAEYAA.ogg")) {
        cout << "Failed to load music" << endl;
        return EXIT_FAILURE;
    }
    music.play();

    Font font;
    font.loadFromFile("digital-7 (mono).ttf");
    Text text;
    text.setFont(font);
    text.setPosition(0, 0);
    text.setCharacterSize(24);
    stringstream timer;

    backSize = texture.getSize();
    WINSIZE = window.getSize(); //gets the window size

    double xScale = (double) WINSIZE.x / backSize.x;
    double yScale = (double) WINSIZE.y / backSize.y;

    background.setTexture(texture);
    background.setScale(xScale, yScale);

    window.setFramerateLimit(60);

    cin >> N;
    cin >> R;
    for (int i = 0; i < N; i++) {
        shared_ptr<Body> ptrBody(new Body());
        cin >> *ptrBody;
        ptrBody->scale(WINSIZE, R);
        bodies.push_back(ptrBody);
    }

    Clock clock;
    clock.restart();

    while (window.isOpen())
    {
        Time ElapsedTime = clock.getElapsedTime();
        double timePassed = ElapsedTime.asSeconds();
        timer.str(string());
        timePassed *= deltaT;
        timer << "Time passed in seconds: " << timePassed;
        text.setString(timer.str().c_str());
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        window.clear();
        window.draw(background);
        window.draw(text);

        for (unsigned int i = 0; i < bodies.size(); i++) {
            fX = 0;
            fY = 0;
            for (unsigned int j = 0; j < bodies.size(); j++) {
                if (i != j) {
                    dx = bodies[j]->x - bodies[i]->x;
                    dy = bodies[j]->y - bodies[i]->y;
                    r = getRadius(dx, dy);
                    f = getForce(bodies[i]->getM(), bodies[j]->getM(), r);
                    fX += dirF(dx, f, r);
                    fY += dirF(dy, f, r);
                }
            }
            bodies[i]->F.x = fX;
            bodies[i]->F.y = fY;
            bodies[i]->time(deltaT);
            bodies[i]->move();
            window.draw(*bodies[i]);
        }

        if (timePassed > T || Keyboard::isKeyPressed(Keyboard::Escape) || event.type == Event::Closed) {
            for (unsigned int i = 0; i < bodies.size(); i++) {
                cout << " " << bodies[i]->x;
                cout << " " << bodies[i]->y;
                cout << " " << bodies[i]->xVel;
                cout << " " << bodies[i]->yVel;
                cout << " " << bodies[i]->mass;
                cout << " " + bodies[i]->img_file << endl;
            }
        }

        window.display();
    }
    return 0;
}
