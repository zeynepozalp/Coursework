#ifndef HW4_COORDINATE_H
#define HW4_COORDINATE_H

// DO NOT MODIFY THIS FILE.

#include <ostream>
struct Coordinate {
    int x, y;

    Coordinate(int x, int y) : x(x), y(y) { }

    friend std::ostream& operator<<(std::ostream& os, const Coordinate& coord) {
        os << "(" << coord.x << "/" << coord.y << ")";

        return os;
    }

    bool operator<(const Coordinate &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
    bool operator==(const Coordinate &rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    bool operator!=(const Coordinate &rhs) const {
        return !((*this) == rhs);
    }

    /**
     *
     * @return Adds two coordinates and returns the result.
     */
    Coordinate operator+(Coordinate rhs) const {
        return Coordinate(this->x + rhs.x, this->y + rhs.y);
    }

    /**
     *
     * It calculates the manhattan distance between two coordinates.
     *
     * @param rhs Coordinate to calculate the difference.
     * @return The absolute distance (x + y) between them.
     */
    int operator-(const Coordinate& rhs) const {
        return abs(x - rhs.x) + abs(y - rhs.y);
    }
};

#endif
