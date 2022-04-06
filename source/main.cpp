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
#include <regex>
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

#define WHITE 255

int main( const int argc, char** argv )
{

  std::string line;
  std::vector<std::string> text;
  std::string all;

  std::string start = "\033[";
  std::string end = "m$&\033[0m";

  std::vector<std::string> colours =
    { "30", "31", "32", "33", "34", "35", "36", "37",
      "90", "91", "92", "93", "94", "95", "96", "97"};

  while ( getline(std::cin, line) ) {

    text.push_back(line);
    all += line + '\n';

  }

  sort( text.begin(), text.end() );
  only_distinct_duplicates(text);

  int i = 0;
  for (std::string ln : text) {

    if (!ln.empty()) {

      all = std::regex_replace(all, std::regex(ln), start + colours[i] + end);

      i++;

      if (i == colours.size()) i = 0;

    }

  }

  std::cout << all << std::endl;

  exit(0);

};
