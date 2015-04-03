#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
  std::ofstream file("ilovechicken.txt");
  std::cout << "writting ilovechicken.txt..." << std::endl;

  for(int i=1; i<argc; i++)
    file << argv[i] << std::endl;

  return 0;
}
