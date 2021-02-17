#include <fstream>
#include <string>
#include <iostream>

/*
 * Expects a single filepath passed as an argument. Will parse and produce an output file at "formatted_statement.txt"
 *
 */
int main(int argc, char **argv) 
{ 
    std::ifstream file(argv[1]);
    std::string str; 
    
    // open output file
    std::ofstream output_file("formatted_statement.txt");

    while (std::getline(file, str))
    {
      output_file << str << "\t";
    }
}
