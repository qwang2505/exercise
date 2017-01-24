#include "../include.h"

/**
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 *
 * For example,
 * Given n = 3,
 *
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 */

enum Direction {
    RIGHT = 0,
    DOWN,
    LEFT,
    UP
};

struct Step {
    int i;
    int j;
    Direction d;
    bool finished;
    Step(Step& o) {
        i = o.i;
        j = o.j;
        d = o.d;
        finished = false;
    }
    Step(int a, int b, Direction c) {
        i = a;
        j = b;
        d = c;
        finished = false;
    }
};

Direction nextDirection(Direction d) {
    switch (d) {
        case RIGHT:
            return DOWN;
        case DOWN:
            return LEFT;
        case LEFT:
            return UP;
        case UP:
            return RIGHT;
    }

}

bool valid(Step& temp, vector<vector<int> >& matrix) {
    return !(temp.i < 0 || temp.i >= matrix.size() || temp.j < 0 || temp.j >= matrix.size() ||
            matrix[temp.i][temp.j] != 0);
}

void step(Step& temp) {
    switch (temp.d) {
        case RIGHT:
            temp.j += 1;
            break;
        case DOWN:
            temp.i += 1;
            break;
        case LEFT:
            temp.j -= 1;
            break;
        case UP:
            temp.i -= 1;
            break;
    }
}

// get next step
Step nextStep(Step& s, vector<vector<int> >& matrix) {
    int n = matrix.size();
    Step temp(s);
    step(temp);
    if (!valid(temp, matrix)) {
        temp = s;
        Direction od = temp.d;
        temp.d = nextDirection(temp.d);
        while (temp.d != od) {
            step(temp);
            if (valid(temp, matrix)) {
                return temp;
            } else {
                temp.i = s.i;
                temp.j = s.j;
            }
            temp.d = nextDirection(temp.d);
        }
        temp.finished = true;
        return temp;
    } else {
        return temp;
    }
}

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > output(n, vector<int>(n, 0));
    if (n < 1) {
        return output;
    }
    Step s(0, 0, RIGHT);
    int count = 0;
    while (!s.finished) {
        output[s.i][s.j] = ++count;
        s = nextStep(s, output);
    }
    return output;
}

int main(int argc, char** argv) {
    vector<vector<int> > output = generateMatrix(5);
    printVector(output);
}
