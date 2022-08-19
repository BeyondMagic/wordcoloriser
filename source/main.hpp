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

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>

// #. To simplify code.
#define CODE_START "\033["
#define CODE_END "\033[0m"

// #. Initial position of the colour in the set below.
static unsigned int colour = 0;

// #. Create a vector of strings that contain codes that can be parsed by the terminal
//    as colours.
std::vector<std::string> colours =
{
  "1", "2", "3", "4",

  "30", "90", "31", "91", "32", "92", "33", "93",
  "34", "94", "35", "95", "36", "96", "37", "97",

  "30;1", "90;1", "31;1", "91;1", "32;1", "92;1", "33;1", "93;1",
  "34;1", "94;1", "35;1", "95;1", "36;1", "96;1", "37;1", "97;1",

  "30;2", "90;2", "31;2", "91;2", "32;2", "92;2", "33;2", "93;2",
  "34;2", "94;2", "35;2", "95;2", "36;2", "96;2", "37;2", "97;2",

  "30;3", "90;3", "31;3", "91;3", "32;3", "92;3", "33;3", "93;3",
  "34;3", "94;3", "35;3", "95;3", "36;3", "96;3", "37;3", "97;3",

  "30;4", "90;4", "31;4", "91;4", "32;4", "92;4", "33;4", "93;4",
  "34;4", "94;4", "35;4", "95;4", "36;4", "96;4", "37;4", "97;4",
};

/**
 * A way to only have duplicates from the original vector.
 * @note It will change the original vector.
 * @param ::std::vector To find duplicates.
 * @return void
 **/
template <typename T>
void only_distinct_duplicates(::std::vector<T> &v)
{
    std::sort(v.begin(), v.end());
    auto output    = v.begin();
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

/**
 * Replace every string that contains any of the strings of the repeated highlighted.
 * @note It will change "source".
 * @param {std::vector<std::string> &source}
 * @param {std::vector<std::string> &repeated}
 * @return void
 **/
void highlight_repeated(std::vector<std::string> &source, std::vector<std::string> &repeated)
{

  // 1. Loop in every repeated line and replace in the original poem with a special highlight.
  for (auto &line : repeated) {

    // I. Musn't be empty.
    if (!line.empty()) {

      // I. If the repeated line is the same as the verse.
      for (auto &verse : source) if (verse == line) {

        // A. Replace with a new coloured verse.
        verse = CODE_START + colours[colour] + 'm' + line + CODE_END;

        // B. Pick up a new colour.
        if (++colour == colours.size()) colour = 0;

      }

    }

  }

}
