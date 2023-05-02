/*!*****************************************************************************
\File q.cpp
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
#include <iostream>
#include <iomanip>
#include <fstream>


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

\param input_filename
  The name of the input text file containing the text.

\param analysis_file
  The name of the output text file to contain the statistical analysis.

\param ifs
  The fstream variable for the file associated to the input file.

\param ofs
  The fstream variable for the file associated to the output file.

\param fromfile
  A char for character assignment from input text file.

\param veri
  A boolean flag for presence of an integer. 

\param fied
  A boolean flag for presence of characters other than an integer. 

\param avg
  The average of the total integers present in the input text file.

\param num
  The integer number in the input text file.

\param integer
  The number of integers in the input text file.

\param sum
  The sum of the integers in the input text file.

\param characters
  The number of characters in the input text file.

\param letters
  The number of letters in the input text file.

\param wspace
  The number of white space characters in the input text file.

\param digits
  The number of digits in the input text file.

\param ochar
  The number of other characters in the input text file.

\param upper
  The number of uppercase latin characters in the input text file.

\param lower
  The number of lowercase latin characters in the input text file.

\param alphabet[]
  An array for specific alphabet count increment when detected.
*******************************************************************************/

  void q(char const *input_filename, char const *analysis_file) {

  //check if input file (ifs) can be opened
    std::fstream ifs(input_filename, std::ios_base::in);                                //open file for reading
    if (!ifs.is_open()) {                                                               //check if 
      std::cout << "File " << input_filename << " not found.\n";
    }

  //check if output file (ofs) can be created 
    std::fstream ofs(analysis_file, std::ios_base::out);                                //create file for writing
    if (!ofs.is_open()) {                                                               //check of 
      std::cout << "Unable to create output file " << analysis_file << ".";
    }

  //type of and number of chars
    char fromfile;
    bool veri = false, fied = false;
    double avg{}, num{}, integer{}, sum{};                                              //variable name {} is name = 0
    double characters{}, letters{}, wspace{}, digits{}, ochar{};
    double upper{}, lower{}, alphabet[26] = {};
    for (; ifs >> std::noskipws >> fromfile; characters++) {                            //operator>> skips leading whitespace before parsing, use std::noskipws
      
      if (isdigit(fromfile)) {
        digits++;                                                                       //increment digits
        num = num * 10 + fromfile - 48;                                                 //-48 due to ASCII, 0 is 48 deci
        veri = true;                                                                    //number analysis
        fied = false;
      }
      else {
        fied = true;

        if (isalpha(fromfile)) {
          letters++;                                                                    //increment letters
          if (fromfile >= 'A' && fromfile <= 'Z') {                                     //increment uppercased alphabets
            upper++;
            alphabet[fromfile - 'A']++;                                                 //letter statistic
          } 
          else {
            lower++;                                                                    // increment lowercased alphabets
            alphabet[fromfile - 'a']++;                                                 //letter statistic
          }
        }
        else if (fromfile == ' ' || fromfile == '\n' || fromfile == '\t') {
          wspace++;                                                                     //increment whitespaces
        }
        else {
          ochar++;                                                                      //increment other chars
        }
      }

      if (veri == true && fied == true) {
        integer++;
        sum+=num;
        veri = false; fied = false;
        num = 0.0;
      }
    }

    if (sum == 0.0)
      avg = 0.0;
    else
      avg = sum/integer;

  //output to output textfile (analysis_file)
    ofs << "Statistics for file: " << input_filename << "\n";
    ofs << std::setfill ('-') << std::setw(71) << "\n\n";
    ofs << "Total # of characters in file: " << characters << "\n\n";
    ofs << std::setfill (' ') << std::setw(20) << std::left << "Category" 
    << std::setw(29) << "How many in file" << "% of file";
    ofs << std::setfill ('-') << std::setw(70) << "\n";
  //Letters  
    ofs << "\n" << std::setfill (' ') << std::setw(30) << std::left << "Letters" 
    << std::right << std::setw(6) << letters << std::fixed << std::right 
    << std::setprecision(2) << std::setw(20) << letters*100/characters << " %";   //fixed displays number of setprecision after decimal place 
  //White space
    ofs << "\n" << std::setw(30) << std::left << "White space" 
    << std::right << std::setw(6) << int (wspace) << std::fixed << std::right 
    << std::setprecision(2) << std::setw(20) << wspace*100/characters << " %";
  //Digits
    ofs << "\n" << std::setw(30) << std::left << "Digits" 
    << std::right << std::setw(6) << int (digits) << std::fixed << std::right 
    << std::setprecision(2) << std::setw(20) << digits*100/characters << " %";
  //Other characters
    ofs << "\n" << std::setw(30) << std::left << "Other characters" 
    << std::right << std::setw(6) << int (ochar) << std::fixed << std::right 
    << std::setprecision(2) << std::setw(20) << ochar*100/characters << " %\n\n\n";
    
  //Letter statistics
    ofs << "LETTER STATISTICS\n\n";
    ofs << std::setfill (' ') << std::setw(20) << std::left << "Category" 
    << std::setw(22) << "How many in file" << "% of all letters";
    ofs << std::setfill ('-') << std::setw(70) << "\n";

  //Uppercase
    ofs << "\n" << std::setfill (' ') << std::setw(30) << std::left << "Uppercase" 
    << std::right << std::setw(6) << int (upper) << std::fixed << std::right 
    << std::setprecision(2) << std::setw(20) << upper*100/letters << " %"; 
  //Lowercase
    ofs << "\n" << std::setw(30) << std::left << "Lowercase" << std::right 
    << std::setw(6) << int (lower) << std::fixed << std::right 
    << std::setprecision(2) << std::setw(20) << lower*100/letters << " %"; 
  //alphabets
    for (int i = 0; i<26; i++) {
      ofs << "\n" << std::setw(30) << std::left << char ('a'+i) << std::right 
      << std::setw(6) << int (alphabet[i]) << std::fixed << std::right 
      << std::setprecision(2) << std::setw(20) << alphabet[i]*100/letters << " %"; 
    }

  //NUMBER ANALYSIS
    ofs << "\n\n\nNUMBER ANALYSIS\n\n";
    ofs << std::setw(37) << std::left <<  "Number of integers in file:" << int (integer);
    ofs << "\n";
    ofs << std::setw(37) << std::left << "Sum of integers:" << int (sum);
    ofs << "\n";
    ofs << std::setw(37) << std::left <<  "Average of integers:" << avg;
    ofs << std::setfill ('_') << std::setw(70) << "\n";
    ofs << "\n";
  
  //close file stream
    ifs.close();
    ofs.close();
  }
}
