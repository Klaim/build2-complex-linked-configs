#include <ddd/ddd.hxx>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace ddd
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
