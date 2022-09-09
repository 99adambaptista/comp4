// Copyright 2019 Adam Baptista

#include "planets.hpp"

Body::Body() {}

Vector2f Body::getPos() {
    Vector2f pos(x, y);
    return pos;
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

    Vector2f pos(body.x, body.y);
    if (!body.texture.loadFromFile(body.img_file)) {
        cout << "Failed to load image " << body.img_file << endl;
        exit(EXIT_FAILURE);
    }
    body.sprite.setTexture(body.texture);
    body.sprite.setPosition(pos);
    return in;
}
