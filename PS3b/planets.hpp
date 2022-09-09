#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
 
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

#define G 6.67e-11

using namespace std;
using namespace sf;

class Body : public Drawable {
private:
    Texture texture;
    Vector2u winSize;
    
public:
    Sprite sprite;
    Vector2f F;
    string img_file;
    double R, x ,y, xVel, yVel, mass;

    Body();

    Vector2f getPos();

    double getM();

    void scale(Vector2u winSize, double R);

    virtual void draw(RenderTarget &target, RenderStates states) const;

    friend istream &operator>>(istream &in, Body &body);

    void time(double time);

    void move();

    void setV(double ax, double ay, double time);

    void setPos(double time);

    ~Body();
};

double getRadius(double body1_pos, double body2_pos);

double getForce(double mass1, double mass2, double r);

double dirF(double F, double dF, double r);



