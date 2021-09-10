#include <iostream>

#include <boost/container/static_vector.hpp>

#include <bbb/bbb.hxx>
#include <ddd/ddd.hxx>


int main (int argc, char* argv[])
{
  using namespace std;
  boost::container::static_vector<int, 10> v;

  if (argc < 2)
  {
    cerr << "error: missing name" << endl;
    return 1;
  }

  cout << "Hello, " << argv[1] << '!' << endl;
}
