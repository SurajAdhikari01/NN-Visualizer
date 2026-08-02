#pragma once
#include <iostream>

struct Vec2 {
  int x, y;

  Vec2() {
    x = 0;
    y = 0;
  }
  Vec2(int x, int y) {
    this->x = x;
    this->y = y;
  }
  Vec2(const Vec2 &other) {
    this->x = other.x;
    this->y = other.y;

    std::cout << "&\n";
  }

  void operator=(const Vec2 &other) {
    this->x = other.x;
    this->y = other.y;
  }
  Vec2 operator+(const Vec2 &other) const {
    Vec2 temp;
    temp.x = this->x + other.x;
    temp.y = this->y + other.y;
    return temp;
  }
  void operator+=(const Vec2 &other) {
    this->x += other.x;
    this->y += other.y;
    // return *this;
  }
  Vec2 operator+(const int &other) const {
    Vec2 temp;
    temp.x = this->x + other;
    temp.y = this->y + other;
    return temp;
  }
  bool operator==(const Vec2 &other) const {
    if ((this->x == other.x) && (this->y == other.y)) {
      return true;
    } else {
      return false;
    }
  }

  // Vec2 operator*(const int &other)const{
  //
  // }
  bool operator!=(const Vec2 &other) const { return !(*this == other); }

  void print() const { std::cout << "(" << x << "," << y << ")\n"; }
};
