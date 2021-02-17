#include <fstream>
#include <string>
#include <iostream>

/*
 * Expects a single filepath passed as an argument. Will parse and produce an output file at "formatted_statement.txt"
 *
 */
int main(int argc, char **argv) 
{ 
    std::ifstream input_file(argv[1]);
    
    // open output file
    std::ofstream output_file("formatted_statement.txt", std::ofstream::out | std::ofstream::trunc); // truncate option deletes contents before writing

    std::string date;

    // each entry consists of the following, one on each line:
    // date, location/company, category, amount & running balance
    while (std::getline(input_file, date))
    {

      std::string location;
      std::getline(input_file, location);

      std::string category;
      std::getline(input_file, category);

      std::string amount;
      std::getline(input_file, amount);

      // now, stream all the fields, ommitting the newline at the end of each one
      output_file << date.substr(0, date.size()-1) << "\t";
      output_file << amount.substr(0, amount.size()-1) << "\t";
      output_file << category.substr(0, category.size()-1) << "\t";
      output_file << location; // include newline but no tab on this last one

    }

    output_file.close();
    input_file.close();
}
