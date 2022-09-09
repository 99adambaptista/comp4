#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <time.h>
#include <string>

using namespace sf;

class PTree{
public:
    PTree();

    void pTree(RenderWindow &target, int size, Vector2f pos, Vector2f orig, int deg, int iter);

private:
    ConvexShape shape;
};