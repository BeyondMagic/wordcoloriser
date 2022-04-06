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

int main( const int argc, char** argv )
{

  std::string line;
  std::vector<std::string> text;
  std::string all;
  std::string start = "\033[38;2;";
  std::string end = "m[$&] lol";
  int blue = 0;
  int red = 0;
  int green = 0;

  while ( getline(std::cin, line) ) {

    text.push_back(line);
    all += line + '\n';

  }

  std::vector<std::string> copy = text;

  // B. awk 'NF' | uniq -u
  sort( copy.begin(), copy.end() );
  copy.erase( unique( copy.begin(), copy.end() ), copy.end() );

  for (std::string ln : copy) {

    if (!ln.empty()) {

      std::random_device rd; // obtain a random number from hardware
      std::mt19937 gen(rd()); // seed the generator
      std::uniform_int_distribution<> distr(0, 255); // define the range

      blue =  distr(gen);
      red =   distr(gen);
      green = distr(gen);

      all = std::regex_replace(all, std::regex(ln), start + std::to_string(red) + ';' + std::to_string(green) + ';' + std::to_string(blue) + end);


    }

  }

  std::cout << all << std::endl;

  exit(0);

};
