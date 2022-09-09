#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class ED {
public:
    ED(string a, string b);

    int penalty(char a, char b);
    int min(int a, int b, int c);
    int OptDistance();
    string Alignment();
    int getCost();

    ~ED();

private:
    string x, y;
    int M, N, cost;
    int** opt;

};