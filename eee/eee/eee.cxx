#include <eee/eee.hxx>

#include <ostream>
#include <stdexcept>
#include <boost/container/static_vector.hpp>

#include <ccc/ccc.hxx>

using namespace std;

namespace eee
{
  void say_hello (ostream& o, const string& n)
  {
    boost::container::static_vector<int, 10> v;

    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
