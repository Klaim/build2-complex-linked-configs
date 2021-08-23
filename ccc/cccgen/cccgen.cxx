#include <iostream>
#include <fstream>
#include <filesystem>
#include <ccc/ccc.hxx>

int main (int argc, char* argv[])
{
  using namespace std;

  if (argc < 2)
  {
    cerr << "error: missing name" << endl;
    return 1;
  }


  namespace fs = std::filesystem;
  const fs::path file_path{ argv[1] };
  cout << "cccgen generating " << file_path << " ..." << endl;
  ccc::generate(file_path);

}
