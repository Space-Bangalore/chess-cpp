#include <stdarg.h>

#include "parser.hxx"

vector<string> parse(string s) {
  vector<string> result;
  string::size_type next_i, i=0;
  while ((next_i = s.find(' ', i)) != string::npos) {
    if (next_i - i > 0) {
      string tmp = s.substr(i, next_i - i);
      result.push_back(tmp);
    }
    i = next_i+1;// jump over ' '
  }
  if (i < s.length()) result.push_back(s.substr(i));
  return result;
}

string short_version(string s) {
  char result[16];
  unsigned int ir=0, is=0;
  if (s[is] == '-') result[(is++,ir++)] = '-';
  while (is < s.length()) {
    if (s[is] != ' ') {
      result[ir++] = s[is];
      while (++is < s.length()  &&  s[is] != ' ') ;
    } else {
      is++;
    }
  }
  result[ir] = 0;
  return result;
}

/**
 * Very ugly code, but whatever.
 * Additional arguments must be of type char* or uintptr_t.
 * Returns whether successful.
 */
bool dot_demand(vector<string> parsed, unsigned int length, ...) {
  if (parsed.size() != length) return false;
  va_list ap;
  va_start(ap, length);
  for (unsigned int i=0; i<length; i++) {
    uintptr_t arg = va_arg(ap, uintptr_t);
    if (arg < 0x100) {
      if (arg  &&  parsed[i].length() != arg) return false;
    } else {
      char* s = (char *)arg;
      if (strcmp(parsed[i].c_str(), s)) return false;
    }
  }
  return true;
}
