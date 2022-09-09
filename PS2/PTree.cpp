#include "PTree.hpp"

#define RT sqrt(2)

PTree::PTree() {}

void PTree::pTree(RenderWindow &target, int size, Vector2f pos, Vector2f orig, int deg, int iter) {
    Vector2f Lp, Rp, origL(0, (size/2)*sqrt(3)), origR(size/2, size/2);
    Color Brown(139, 69, 19);
    
    shape.setPointCount(4);
    shape.setPoint(0, Vector2f(0, 0));
    shape.setPoint(1, Vector2f(0, size));
    shape.setPoint(2, Vector2f(size, size));
    shape.setPoint(3, Vector2f(size, 0));

    shape.setPosition(pos);
    shape.setOrigin(orig);
    shape.setRotation(deg);

    Rp = shape.getTransform().transformPoint(shape.getPoint(0));
    Lp = shape.getTransform().transformPoint(shape.getPoint(3));

    shape.setOutlineColor(Color::Green);
    shape.setFillColor(Brown);
    shape.setOutlineThickness(-5);
    if (iter < 0)
        return;
    Rp = shape.getTransform().transformPoint(shape.getPoint(0));
    Lp = shape.getTransform().transformPoint(shape.getPoint(3));

    target.draw(shape);
    //pTree(target, (size/2)*sqrt(3), Rp, origL, deg-30, iter-1);
    //pTree(target, size / 2, Lp, origR, deg+60, iter-1);

    pTree(target, (size/2)*sqrt(3), Rp, origL, deg-30, iter-1);
    pTree(target, size/2, Lp, origR, deg+60, iter-1);
}