#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class singleton {
private:
  static singleton *the_instance;
  singleton() { i = 0; }
  singleton(const singleton *s) { i = 0; }
  singleton &operator=(const singleton &s) { return *the_instance; }
  public:
  int i;
  static singleton *instance();
  singleton *break_singleton() { return new singleton(); }
};

singleton *singleton::the_instance;

singleton *singleton::instance()
{
  if (!the_instance) {
    the_instance = new singleton();
  }

  return the_instance;
}

int main(int argc, char *argv[])
{
  singleton *s = singleton::instance();
  singleton *t = singleton::instance();

  cout << s->i << endl;
  t->i = 1;
  cout << s->i << endl;
  cout << t->i << endl;

  t = (singleton *) malloc(sizeof (*t));
  memcpy(t, s, sizeof (*s));

  t->i = 2;
  cout << s->i << endl;
  cout << t->i << endl;

  return 0;
}
