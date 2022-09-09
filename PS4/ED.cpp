#include "ED.hpp"

ED::ED(string a, string b) {

    this->x = a;
    this->y = b;

    x += '-';
    y += '-';

    M = x.length() + 1;
    N = y.length() + 1;

    opt = new int*[M];
    for (int i = 0; i < M; i++)
        opt[i] = new int[N];
}

int ED::penalty(char a, char b) {
    if (a == b)
        return 0;
    else
        return 1;
}

int ED::min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    else if (b < a && b < c)
        return b;
    else
        return c;
}
int ED::OptDistance() {

    //add bottom outside
    int j = 0;
    for (int i = N-1; i >= 0; i--) {
        opt[M-1][i] = j;
        j += 2;
    }

    //add right outisde
    j = 0;
    for (int i = M-1; i >= 0; i--) {
        opt[i][N-1] = j;
        j += 2;
    }

    //compare
    for (int i = M-2; i >= 0; i--) {
        for (int j = N-2; j >= 0; j--) {
            if (x[i] != y[j]) {
                opt[i][j] = min(opt[i+1][j] + 2, opt[i][j+1] + 2, opt[i+1][j+1] + 1);
            }
            else
                opt[i][j] = opt[i+1][j+1];
        }
    }

    string out = Alignment();
    cout << "Edit distance: " << cost << endl;
    cout << out << endl;

    for (int i = 0; i < M; i++)
        delete [] opt[i];

    delete [] opt;
    return 0;
}
string ED::Alignment() {
    vector<char> out;
    
    int i = 0, 
        j = 0,
        pen;;
    while (i < M-2|| j < N-2) {
        if (x[i] == y[j]) {
            pen = penalty(x[i], y[j]);
            out.push_back(x[i]);
            out.push_back(' ');
            out.push_back(y[j]);
            out.push_back(' ');
            i++;
            j++;
        }
        else if (opt[i][j] == opt[i+1][j+1] + 1) {
            pen = penalty(x[i], y[j]);
            out.push_back(x[i]);
            out.push_back(' ');
            out.push_back(y[j]);
            out.push_back(' ');
            i++;
            j++;
        }
        else if (opt[i][j] == opt[i+1][j] + 2) {
            pen = penalty(x[i], y[j]) + 1;
            out.push_back(x[i]);
            out.push_back(' ');
            out.push_back('-');
            out.push_back(' ');
            i++;
        }
        else if (opt[i][j] == opt[i][j+1] + 2) {
            pen = penalty(x[i], y[j]) + 1;
            out.push_back('-');
            out.push_back(' ');
            out.push_back(y[j]);
            out.push_back(' ');
            j++;
        }
        out.push_back('0' + pen);
        cost += pen;
        out.push_back('\n');
    }
    string new_out(out.begin(), out.end());
    return new_out;
}

int ED::getCost() {
    return cost;
}

ED::~ED() {}