#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
 
#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;
using namespace sf;

class Body : public Drawable {
private:
    Texture texture;
    string img_file;
    double R, x, y, xVel, yVel, mass;
    Vector2u winSize;
    
public:
    Sprite sprite;

    Body();

    void scale(Vector2u winSize, double R);

    Vector2f getPos();

    virtual void draw(RenderTarget &target, RenderStates states) const;

    friend istream &operator>>(istream &in, Body &body);

    ~Body();
};

