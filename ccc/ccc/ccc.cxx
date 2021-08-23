#include <ccc/ccc.hxx>

#include <ostream>
#include <fstream>
#include <stdexcept>

using namespace std;

namespace ccc
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }

  void generate(std::filesystem::path file_path)
  {
    std::ofstream file{ file_path };
    file<<
    R"(
      #pragma once

      #include <string_view>

      namespace ccc::generated {
        std::string_view hello(){ return "Hello"; }
      }
    )" << std::endl;
  }
}
