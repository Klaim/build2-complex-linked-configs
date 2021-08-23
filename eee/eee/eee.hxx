#pragma once

#include <iosfwd>
#include <string>

#include <eee/export.hxx>

namespace eee
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  EEE_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
