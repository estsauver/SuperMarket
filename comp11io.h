#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace comp11
{
  // -- Open a file for reading (return true if successful)
  bool openFileForReading(string name, ifstream & in);
  
  // -- Read from a file
  int getInt(istream & in);
  bool getBool(istream & in);
  char getChar(istream & in);
  double getDouble(istream & in);
  string getToken(istream & in);
  string getLine(istream & in);
  
  // -- Check for end of file
  bool atEndOfFile(ifstream & out);
  
  // -- Read from terminal (user)
  int getInt();
  bool getBool();
  char getChar();
  double getDouble();
  string getToken();
  string getLine();
  
  // -- Open a file for writing (return true if successful)
  bool openFileForWriting(string name, ofstream & out);
  
  // -- Write to a file
  void putInt(int i, ofstream & out);
  void putBool(bool b, ofstream & out);
  void putChar(char c, ofstream & out);
  void putDouble(double d, ofstream & out);
  void putString(string s, ofstream & out);
  void putNewline(ofstream & out);
  
  // -- Write to the terminal (user)
  void putInt(int i);
  void putBool(bool b);
  void putChar(char c);
  void putDouble(double d);
  void putString(string s);
  void putNewline();
  
  // -- Close a file
  void closeFile(fstream & in_or_out);
}

using namespace comp11;
