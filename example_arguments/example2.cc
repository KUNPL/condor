#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
  std::ofstream file("example2.txt");
  std::cout << "writting example2.txt..." << std::endl;

  for(int i=1; i<argc; i++)
    file << argv[i] << " ";

  return 0;
}
