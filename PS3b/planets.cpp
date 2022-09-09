#include "planets.hpp"

Body::Body() {}

Vector2f Body::getPos() {
    Vector2f pos(xVel, yVel);
    return pos;
}

double Body::getM() {
    return mass;
}

void Body::scale(Vector2u winSize, double R) {
    this->winSize = winSize;
    this->R = R;
}

void Body::draw(RenderTarget &target, RenderStates states) const {
    target.draw(sprite, states);
}

istream &operator >>(istream &in, Body &body) {
    in >> body.x >> body.y >> body.xVel >> body.yVel
        >> body.mass >> body.img_file;

    if (!body.texture.loadFromFile("nbody/" + body.img_file)) {
        cout << "Failed to load image " << body.img_file << endl;
        exit(EXIT_FAILURE);
    }
    body.sprite.setTexture(body.texture);
    return in;
}

void Body::time(double time) {
    double ax = F.x / mass;
    double ay = F.y / mass;

    setV(ax, ay, time);

    setPos(time);
}

void Body::setV(double ax, double ay, double time) {
    xVel -= (ax * time);
    yVel -= (ay * time);
}

void Body::setPos(double time) {
    x -= xVel * time;
    y -= yVel * time;
}

void Body::move() {
    double newX = ((x / R) * winSize.x/2) + winSize.x / 2;
    double newY = ((y / R) * winSize.y/2) + winSize.y / 2;
    Vector2f middle;
    middle.x = sprite.getTexture()->getSize().x / 2;
    middle.y = sprite.getTexture()->getSize().y / 2;
    sprite.setOrigin(middle);

    sprite.setPosition(newX, newY);
}

double getRadius(double body1_pos, double body2_pos) {
    return sqrt(pow(body1_pos, 2) + pow(body2_pos, 2));
}

double getForce(double mass1, double mass2, double r) {
    
    return (G * mass1 * mass2) / pow(r, 2);;
}

double dirF(double F, double dF, double r) {
    double fDir = F * dF / r;
    return fDir;
}

Body::~Body() {}