#include <iostream>
#include <cstdio>

typedef struct c {
    int x;
    int y;
} Coordinates;

Coordinates change(int v) {
    Coordinates coord;
    int i = 1;

    coord.x = 0; coord.y = 0;

    // case 1
    if(v == 1)
        return coord;

    // case 2
    coord.y++; v--;
    if(v == 1)
        return coord;

    // case 3
    coord.x--; v--;
    if(v == 1)
        return coord;

    // pattern
    while(true) {
        for(int j = 0; j < i; j++) {
            coord.y--; v--;
            if(v == 1)
                return coord;
        }

        for(int j = 0; j < i; j++) {
            coord.x++; coord.y--; v--;
            if(v == 1)
                return coord;
        }

        for(int j = 0; j < i; j++) {
            coord.x++; v--;
            if(v == 1)
                return coord;
        }

        for(int j = 0; j < i; j++) {
            coord.y++; v--;
            if(v == 1)
                return coord;
        }

        coord.y++; v--;
        if(v == 1)
            return coord;

        for(int j = 0; j < i; j++) {
            coord.x--; coord.y++; v--;
            if(v == 1)
                return coord;
        }

        for(int j = 0; j < i; j++) {
            coord.x--; v--;
            if(v == 1)
                return coord;
        }

        coord.x--; v--;
        if(v == 1)
            return coord;

        i++;
    }
}

int main() {
    Coordinates coord;
    int num = 0;

    while(std::cin >> num) {
        coord = change(num);
        std::cout << coord.x << ' ' << coord.y << std::endl;
    }
    return 0;
}
