#include <eee/eee.hxx>

#include <ostream>
#include <stdexcept>

#include <ccc/ccc.hxx>

using namespace std;

namespace eee
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
