#include <iostream>

class Rectangle {
 public:
  Rectangle(double width, double height) : width_(width), height_(height) {}
  virtual ~Rectangle() = default;
  virtual double area() { return width_ * height_; }
  virtual void setWidth(double width) { width_ = width; }
  virtual void setHeight(double height) { height_ = height; }

 private:
  double width_;
  double height_;
};

class Square : public Rectangle {
 public:
  Square(double side) : Rectangle(side, side) {}
  virtual ~Square() = default;
  double area() override { return Rectangle::area(); }
  void setWidth(double width) override {
    Rectangle::setWidth(width);
    Rectangle::setHeight(width);
  }
  void setHeight(double height) override { setWidth(height); }
};

int main() {
  Rectangle* s1 = new Rectangle(2, 3);
  Rectangle* s2 = new Square(4);

  std::cout << s1->area() << std::endl;
  std::cout << s2->area() << std::endl;

  delete s1;
  delete s2;

  return 0;
}
