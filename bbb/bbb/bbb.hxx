#pragma once

#include <iosfwd>
#include <string>

#include <bbb/export.hxx>

namespace bbb
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  BBB_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
