#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>
#include "AdjacencyList.h"
//Name: Adnan Sanaulla
//UF ID: 87197603
using namespace std;


// the syntax for defining a test is below. It is important for the name to be
// unique, but you can group multiple tests with [tags]. A test can have
// [multiple][tags] using that syntax.
TEST_CASE("Example Test Name - Change me!", "[tag]") {
  AdjacencyList Created_Graph;
  string testInput = R"(14 11
facebook.com weather.com
zoom.us apple.com
pcbuildinguf.com microsoft.com
apple.com zoom.us
ufl.edu roblox.com
getbootstrap.com twitter.com
facebook.com stackoverflow.com
reactjs.org microsoft.com
openai.com twitter.com
chase.com weather.com
roblox.com samsung.com
stackoverflow.com zoom.us
wikipedia.org reactjs.org
pcbuildinguf.com twitter.com
)";

  string correctAnswer = R"(apple.com 0.13
chase.com 0.00
facebook.com 0.00
getbootstrap.com 0.00
microsoft.com 0.00
openai.com 0.00
pcbuildinguf.com 0.00
reactjs.org 0.00
roblox.com 0.00
samsung.com 0.00
stackoverflow.com 0.00
twitter.com 0.00
ufl.edu 0.00
weather.com 0.00
wikipedia.org 0.00
zoom.us 0.09)";

  stringstream ss(testInput);
  int lines;
  int powerIterations;
  ss >> lines >> powerIterations;
  string from, to;
  int j = 0;
  for (int i = 0; i < lines; i++) {
    string line;
    getline(ss, line);
    istringstream in(line);
    ss >> from;
    ss >> to;
    cout << "Edge: " << from << " → " << to << endl;
    Created_Graph.AddVertex(to, from, j);
  }
  REQUIRE(Created_Graph.PageRank(powerIterations) == correctAnswer);
}

TEST_CASE("Test 2", "[tag]") {
  // you can also use "sections" to share setup code between tests, for example:
  int one = 1;

  SECTION("num is 2") {
    int num = one + 1;
    REQUIRE(num == 2);
  };

  SECTION("num is 3") {
    int num = one + 2;
    REQUIRE(num == 3);
  };

  // each section runs the setup code independently to ensure that they don't
  // affect each other
}

// You must write 5 unique, meaningful tests for credit on the testing section
// of this project!

// See the following for an example of how to easily test your output.
// This uses C++ "raw strings" and assumes your PageRank outputs a string with
//   the same thing you print.
TEST_CASE("Example PageRank Output Test", "[flag]") {
  // the following is a "raw string" - you can write the exact input (without
  //   any indentation!) and it should work as expected
  string input = R"(7 2
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

  string expectedOutput = R"(facebook.com 0.20
gmail.com 0.20
google.com 0.10
maps.com 0.30
ufl.edu 0.20
)";

  string actualOutput;

  // somehow pass your input into your AdjacencyList and parse it to call the
  // correct functions, for example:
  //  AdjacencyList g;
  //  g.parseInput(input)
  //  actualOutput = g.getStringRepresentation()

  REQUIRE(actualOutput == expectedOutput);
}
