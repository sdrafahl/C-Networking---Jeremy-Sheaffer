#include <iostream>

using namespace std;

class shape {
public:
  virtual ~shape() {}
  virtual void draw() = 0;
};

class square : public shape {
public:
  void draw()
  {
    cout << "[]";
  }
};

class circle : public shape {
public:
  void draw()
  {
    cout << "()";
  }
};

class green_square : public square {
public:
  void draw()
  {
    cout << "green-[]";
  }
};

class shape_decorator : public shape {
private:
  shape *s;
public:
  shape_decorator(shape *s) : s(s) {}
  ~shape_decorator() { delete s; }
  void draw() { s->draw(); }
};

class green_shape : public shape_decorator {
public:
  green_shape(shape *s) : shape_decorator(s) {}
  void draw()
  {
    cout << "green-";
    shape_decorator::draw();
  }
};

class big_shape : public shape_decorator {
public:
  big_shape(shape *s) : shape_decorator(s) {}
  void draw()
  {
    cout << "big-";
    shape_decorator::draw();
  }
};

class ugly_shape : public shape_decorator {
public:
  ugly_shape(shape *s) : shape_decorator(s) {}
  void draw()
  {
    cout << "ugly-";
    shape_decorator::draw();
  }
};

int main(int argc, char *argv[])
{
  square s;

  //  s.draw();

  green_shape gs(new ugly_shape(new big_shape(new green_shape(new square()))));
  gs.draw();
  cout << endl;

  return 0;
}
