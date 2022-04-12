/*
 * Copyright 2021-2022 João F. BeyondMagic <koetemagie@gmail.com>
 *
 *Licensed under the Apache License, Version 2.0 (the "License");
 *you may not use this file except in compliance with the License.
 *You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing, software
 *distributed under the License is distributed on an "AS IS" BASIS,
 *WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *See the License for the specific language governing permissions and
 *limitations under the License.
 */

#include <iostream>
#include <random>
//#include <regex>
#include <vector>

template <typename T>
void only_distinct_duplicates(::std::vector<T> &v)
{
    ::std::sort(v.begin(), v.end());
    auto output = v.begin();
    auto test = v.begin();
    auto run_start = v.begin();
    auto const end = v.end();
    for (auto test = v.begin(); test != end; ++test) {
       if (*test != *run_start) {
           if ((test - run_start) > 1) {
              ::std::swap(*output, *run_start);
              ++output;
           }
           run_start = test;
       }
    }
    if ((end - run_start) > 1) {
        ::std::swap(*output, *run_start);
        ++output;
    }
    v.erase(output, end);
}


// ReplaceAll(string("Number Of Beans"), std::string(" "), std::string("_"))

void replace_all(std::string &str, const std::string &from, const std::string &to) {

    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
}

int main( const int argc, char** argv )
{

  std::string line;
  std::vector<std::string> text;
  std::string all;

  std::string start = "\033[";
  std::string end = "\033[0m";

  //std::vector<std::string> colours =
  //  { "30", "90", "31", "91", "32", "92", "33", "93",
  //    "34", "94", "35", "95", "36", "96", "37", "97"};

  std::vector<std::string> colours =
    { "1", "2", "3", "4"};

  //std::vector<std::vector<std::string>> rhymes = 
  //  { // A vector containing a vector of syllabes that sound the same.
  //    { "way", "ways", "ame" },
  //    { "ame" },
  //    { "irt", "urt" },
  //    { "lea", "be" },
  //    { "ria" },
  //    { "g", "g", "g", "g", "g" , },
  //    { "j", "j", "j", "j", "j" , },
  //    { "k", "k", "k", "k", "k" , },
  //    { "l", "l", "l", "l", "l" , },
  //    { "m", "m", "m", "m", "m" , },
  //    { "n", "n", "n", "n", "n" , },
  //    { "p", "p", "p", "p", "p" , },
  //    { "q", "q", "q", "q", "q" , },
  //    { "r", "r", "r", "r", "r" , },
  //    { "s", "s", "s", "s", "s" , },
  //    { "t", "t", "t", "t", "t" , },
  //    { "v", "v", "v", "v", "v" , },
  //    { "w", "w", "w", "w", "w" , },
  //    { "x", "x", "x", "x", "x" , },
  //    { "z", "z", "z", "z", "z" , }
  //  };

  // break the lyrics into a vector of words, then match the last characters with the above rhymes ^

  while ( getline(std::cin, line) ) {

    text.push_back(line);
    all += line + '\n';

  }

  sort( text.begin(), text.end() );
  only_distinct_duplicates(text);

  int i = 0;
  for (std::string ln : text) {

    if (!ln.empty()) {

      replace_all(all, ln, start + colours[i] + 'm' + ln + end);

      i++;

      if (i == colours.size()) i = 0;

    }

  }

  std::cout << all;

  exit(0);

};
