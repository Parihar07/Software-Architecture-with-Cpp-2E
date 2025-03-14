#include <iostream>

class Shape {
 public:
  virtual double area() = 0;
  virtual ~Shape() = default;
};

class Rectangle : public Shape {
 public:
  Rectangle(double width, double height) : width_(width), height_(height) {}
  virtual ~Rectangle() = default;
  double area() override { return width_ * height_; }
  virtual void setWidth(double width) { width_ = width; }
  virtual void setHeight(double height) { height_ = height; }

 private:
  double width_;
  double height_;
};

class Square : public Shape {
 public:
  Square(double side) : side_(side) {}
  virtual ~Square() = default;
  double area() override { return side_ * side_; }
  void setSide(double side) { side_ = side; }

 private:
  double side_;
};

int main() {
  Shape* s1 = new Rectangle(2, 3);
  Shape* s2 = new Square(4);

  std::cout << s1->area() << std::endl;
  std::cout << s2->area() << std::endl;

  delete s1;
  delete s2;

  return 0;
}
