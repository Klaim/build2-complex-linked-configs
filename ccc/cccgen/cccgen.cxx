#include <iostream>
#include <fstream>
#include <filesystem>
#include <ccc/ccc.hxx>
#include <fmt/core.h>
#include <fmt/ostream.h>

int main (int argc, char* argv[])
{
  using namespace std;

  if (argc < 2)
  {
    cerr << "error: missing name" << endl;
    return 1;
  }


  namespace fs = std::filesystem;
  const auto file_path = fs::absolute(argv[1]);
  fmt::print("cccgen generating {} ...", file_path);
  ccc::generate(file_path);
  fmt::print(" DONE\n");
}
