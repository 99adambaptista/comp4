#include "ED.cpp"

int main(int argc, char* argv[]) {

    string a, b;
    cin >> a;
    cin >> b;

    ED ed(a, b);

    Clock clock;
    Time t;
    ed.OptDistance();
    t = clock.getElapsedTime();
    cout << "Execution time is " << t.asSeconds() << " seconds\n";
    //cout << "Edit distance (for longer sequences): " << ed.getCost() << endl;

    return 0;
}