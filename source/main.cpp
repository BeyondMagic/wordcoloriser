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

void replace_all(std::string& source, const std::string& from, const std::string& to)
{
    std::string newString;
    newString.reserve(source.length());  // avoids a few memory allocations

    std::string::size_type lastPos = 0;
    std::string::size_type findPos;

    while(std::string::npos != (findPos = source.find(from, lastPos)))
    {
        newString.append(source, lastPos, findPos - lastPos);
        newString += to;
        lastPos = findPos + from.length();
    }

    // Care for the rest after last occurrence
    newString += source.substr(lastPos);

    source.swap(newString);
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
