/*!*****************************************************************************
\File q.hpp
\Author Timothy Lee Ke xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: Text File Analyzer
\Par Programming Assignment #1
\Date 16-01-2022

\Brief
  This program takes an input file with a series of characters to print some 
  statistical results about its contents to an output file as specified by
  the analysis file parameter. The analysis include the frequency of certain
  occurences of catergories of characters and each letter of the alphabet. 
  Additional analysis include number, sum, and average of integers present.
  The file can only consist of functions pretaining to <iostream>, <iomanip>,
  <fstream> cpp libraries. Other libraries or functions are not permitted.
  This program utilizes a single function:
  
  - q
      Reads the contents of the given text file to print statistical results
      to the output file in its second parameter. It will count the number of 
      characters in the file and determine the number of characters belonging to
      the category: letter, white space, digit, other characters. It will also
      calculate the % of each category of the file.
      The function checks the letter statistics to specify the total number of
      uppercase, lowercase latin characters and the allocations per alphabet.
      The function calculates the number, sum, and average of integers present
      in the input file as well and prints it to the output file.
      Should the value have decimals or is a %, it is to be of 2 d.p.
*******************************************************************************/
#ifndef Q_HPP_
#define Q_HPP_

namespace hlp2 {

/*!*****************************************************************************
\brief
  Reads the contents of the given text file to print statistical results to the 
  output file in its second parameter. It will count the number of characters 
  in the file and determine the number of characters belonging to the category:
  letter, white space, digit, other characters. It will also calculate the % of
  each category of the file.
  The function checks the letter statistics to specify the total number of 
  uppercase, lowercase latin characters and the allocations per alphabet.
  The function calculates the number, sum, and average of integers present in the
  input file as well and prints it to the output file.
  Should the value have decimals or is a %, it is to be of 2 d.p.
*******************************************************************************/
  void q(char const *input_filename, char const *analysis_file);
}

#endif
