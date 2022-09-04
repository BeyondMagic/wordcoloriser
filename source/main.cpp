/*
 * Copyright 2021-2022 João F. BeyondMagic <koetemagie@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "main.hpp"

int main( const int argc, const char** )
{

  // 1. Do not run when:
  //    I.  If the argument comes from the right side.
  //    II. Verify if there is data piped into it.
  if ( argc > 1 or isatty(fileno(stdin)) ) {

    std::cout << "-- Please, you should send content directly (pipe) to the wordcoloriser!\n";
    return 1;

  }

  // 2. Initalise the poem container, which will be filled be the data piped into.
  std::vector<std::string> poem;

  // 2.1. Temporary string.
  std::string line;

  // 2.2. Temporary repeated lines of the poem.
  std::vector<std::string> special;

  // 3. Get all string from input.
  while ( std::getline(std::cin, line) )
  {

    // I For marks, such as "[ Chorus ]", push twice.
    if (line[0] == '[' or line[0] == '(')
      special.push_back(line);

    // II. For every verse.
    special.push_back(line);

    // III. The original poem.
    poem.push_back(line);

  }

  // 4. Get only the repeated strings of the vector.
  only_distinct_duplicates(special);

  // 5. Highligh all repeated verses
  highlight_repeated(poem, special);

  // 6. Clear off used vectors.
  special.clear();
  colours.clear();

  // 7. Print the poem to stdin.
  for (auto line : poem ) std::cout << line << '\n';

};
