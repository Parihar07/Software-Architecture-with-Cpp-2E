#include <string>
#include <vector>

class File {
 public:
  int read(char* s, std::streamsize n) { return 0; }

  void write(const char* s, std::streamsize n) {}

  virtual std::vector<int> parse(const std::string& s) = 0;
};
