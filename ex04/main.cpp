#include <fstream>
#include <iostream>
#include <string>

int validateArgument(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << "Give 1 Filename and 2 String";
    return (0);
  }
  for (int i = 1; i < argc; i++) {
    if (!argv[i] || !*(argv[i])) {
      std::cout << "No! Empty String" << std::endl;
      return (0);
    }
  }
  return (1);
}

int main(int argc, char *argv[]) {
  if (!validateArgument(argc, argv))
    return (0);

/*
** Open Files
*/
  std::string filename = argv[1];
  std::string filename_replace = filename + ".replace";
  std::fstream fs;
  std::fstream fs_replace;
  fs.open(filename, std::istream::in);
  fs_replace.open(filename_replace, std::istream::out);
  if (!fs.is_open()) {
    std::cout << "No File Open Error";
    return (0);
  }
  if (!fs_replace.is_open()) {
    fs.close();
    std::cout << "File_Replace Open Error";
    return (0);
  }

/*
** Find And Replace
*/
  std::string line;
  std::string find_to = argv[2];
  std::string replace_to = argv[3];
  std::size_t found_index;
  while (getline(fs, line)) {
    found_index = 0;
    while (true) {
      found_index = line.find(find_to);
      if (found_index != std::string::npos) {
        fs_replace << line.substr(0, found_index) + replace_to;
        line = line.substr(found_index + find_to.length());
      } else
        break;
    }
    fs_replace << line << std::endl;
  }

  fs.close();
  fs_replace.close();
  return (0);
}