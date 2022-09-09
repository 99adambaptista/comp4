#include "PTree.hpp"

int main(int argc, char* argv[])
{
    int L, N, iter = 0;
    L = atoi(argv[1]);
    N = atoi(argv[2]);

    std::cout << "Use right arrow to go to the next iteration." << std::endl;

    RenderWindow window (VideoMode(7*L, 4.5*L), "Pythagoras Tree");
    
    //Vector2f pos(6*L/2-L/2, 4*L), orig(0, L);
    Vector2f pos(6*L/1.5, 4.5*L), orig(0, L);

    PTree rD;

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
            else if(Keyboard::isKeyPressed(Keyboard::Right)) {
                if (iter < N)
                    iter++;
            }           
        }

        window.clear();
        rD.pTree(window, L, pos, orig, 0, iter);
        window.display();
    }

    return EXIT_SUCCESS;
}