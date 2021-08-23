#include <bbb/bbb.hxx>

#include <ostream>
#include <stdexcept>

#include <bbb/generated.hxx>

using namespace std;

namespace bbb
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
