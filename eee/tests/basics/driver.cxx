#include <cassert>
#include <sstream>
#include <stdexcept>

#include <eee/version.hxx>
#include <eee/eee.hxx>

int main ()
{
  using namespace std;
  using namespace eee;

  // Basics.
  //
  {
    ostringstream o;
    say_hello (o, "World");
    assert (o.str () == "Hello, World!\n");
  }

  // Empty name.
  //
  try
  {
    ostringstream o;
    say_hello (o, "");
    assert (false);
  }
  catch (const invalid_argument& e)
  {
    assert (e.what () == string ("empty name"));
  }
}
