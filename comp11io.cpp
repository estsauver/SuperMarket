#include "comp11io.h"

// -- (private) Consume white space
//    NOTE: consumes both trailing and leading whitespace, and
//    may cross multiple lines.
static void consumeWhiteSpace(istream & in)
{
  char t;
  t = in.peek();
  while (isspace(t) && ! in.eof()) {
    in.ignore();
    t = in.peek();
  }
}

// ----------------------------------------------------------------------
//   File input
// ----------------------------------------------------------------------

// -- Open a file for reading (return true if successful)
bool comp11::openFileForReading(string name, ifstream & in)
{
  in.open(name.c_str());
  return ! in.fail();
}

// -- Read an integer from a file
int comp11::getInt(istream & in)
{
  int result;
  in >> result;
  return result;
}

// -- Read a boolean from a file
bool comp11::getBool(istream & in)
{
  string val;
  in >> val;
  if (val == "true" || val == "yes") return true;
  else return false;
}

// -- Read a single character from a file
char comp11::getChar(istream & in)
{
  char result;
  in >> result;
  return result;
}

// -- Read a double-precision floating point value from a file
double comp11::getDouble(istream & in)
{
  double result;
  in >> result;
  return result;
}

// -- Read a double-precision floating point value from a file
string comp11::getToken(istream & in)
{
  string result;
  in >> result;
  return result;
}

// -- Read a line of text (discard newline) from a file
string comp11::getLine(istream & in)
{
  // -- Consume any extraneous white-space (including newline) at the end
  //    of the previous line
  consumeWhiteSpace(in);
  
  // -- Read a line (consuming and discarding the terminating newline)
  string result;
  getline(in, result);
  return result;
}

// -- Is end of file?
bool comp11::atEndOfFile(ifstream & in)
{
  consumeWhiteSpace(in);
  return in.eof();
}

// ----------------------------------------------------------------------
//   User input
// ----------------------------------------------------------------------

// -- Read an integer from the user
int comp11::getInt()
{
  return getInt(cin);
}

// -- Read a boolean from the user
bool comp11::getBool()
{
  return getBool(cin);
}

// -- Read a single character from the user
char comp11::getChar()
{
  return getChar(cin);
}

// -- Read a double-precision floating point value from the user
double comp11::getDouble()
{
  return getDouble(cin);
}

// -- Read a double-precision floating point value from a file
string comp11::getToken()
{
  return getToken(cin);
}

// -- Read a line of text (discard newline) from the user
string comp11::getLine()
{
  return getLine(cin);
}

// ----------------------------------------------------------------------
//   File output
// ----------------------------------------------------------------------

// -- Open a file for writing (return true if successful)
bool comp11::openFileForWriting(string name, ofstream & out)
{
  out.open(name.c_str());
  return ! out.fail();
}

// -- Output an integer to a file
void comp11::putInt(int i, ofstream & out)
{
  out << i;
}

// -- Output a boolean to a file
void comp11::putBool(bool b, ofstream & out)
{
  if (b) out << "true";
  else out << "false";
}

// -- Ouput a character to a file
void comp11::putChar(char c, ofstream & out)
{
  out << c;
}

// -- Output a double-precision floating point number to a file
void comp11::putDouble(double d, ofstream & out)
{
  out << d;
}

// -- Output a string to a file
void comp11::putString(string s, ofstream & out)
{
  out << s;
}

// -- Output a newline to a file
void comp11::putNewline(ofstream & out)
{
  out << endl;
}

// ----------------------------------------------------------------------
//   Terminal output
// ----------------------------------------------------------------------

// -- Output an integer to the screen
void comp11::putInt(int i)
{
  cout << i;
}

// -- Output a boolean to the screen
void comp11::putBool(bool b)
{
  if (b) cout << "true";
  else cout << "false";
}

// -- Output a character to the screen
void comp11::putChar(char c)
{
  cout << c;
}

// -- Output a double-precision floating point number to the screen
void comp11::putDouble(double d)
{
  cout << d;
}

// -- Output a string to the screen
void comp11::putString(string s)
{
  cout << s;
}

// -- Output a newline to the screen
void comp11::putNewline()
{
  cout << endl;
}

// -- Close a file (either kind)
void comp11::closeFile(fstream & in_or_out)
{
  in_or_out.close();
}

