#pragma once

#include <iosfwd>
#include <string>

#include <ddd/export.hxx>

namespace ddd
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  DDD_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
