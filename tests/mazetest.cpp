#include <sstream>
#include "tctestpp.h"
#include "position.h"
#include "tile.h"
#include "maze.h"

Maze *readFromString(const std::string &s) {
  std::stringstream ss(s);
  return Maze::read(ss);
}

const char *m1 =
  "10 6\n"
  "##########\n"
  "#........#\n"
  "#.###....#\n"
  "#.#......#\n"
  "#.....<..#\n"
  "##########\n";

// Odd (but still valid) maze data
const char *m6 =
  "2 2\n"
  "##\n"
  "#.\n";

const char *m7 =
  "6 5\n" //no goal
  "######\n"
  "#....#\n"
  "#....#\n"
  "#....#\n"
  "######\n";

// More bad mazes 
const char *m8 =
  "5 5\n"
  "#####\n"
  "#.<.#\n"
  "#...#\n"
  "#.>.#\n"
  "#####\n";

const char *m9 =
  "6 7\n" //mismatched dimensions
  "#######\n"
  "#..<..#\n"
  "#.....#\n"
  "#.....#\n"
  "#.....#\n"
  "#######\n";


struct TestObjs {
  Maze *maze1;
  Maze *maze6; //Maddie
  Maze *maze7; //Maddie
  Maze *maze8; //Maddie
  Maze *maze9; //Maddie
};

TestObjs *setup() {
  TestObjs *objs = new TestObjs;
  objs->maze1 = readFromString(m1);
  objs->maze6 = readFromString(m6);
  objs->maze7 = readFromString(m7);
  objs->maze8 = readFromString(m8);
  objs->maze9 = readFromString(m9);
  return objs;
}

void cleanup(TestObjs *objs) {
  delete objs->maze1;
  delete objs->maze6;
  delete objs->maze7;
  delete objs->maze8;
  delete objs->maze9;
  delete objs;
}

void testGetWidth(TestObjs *objs);
void testGetHeight(TestObjs *objs);
void testGetTile(TestObjs *objs);
void testReadMaze(TestObjs *objs);
void testInvalidMazeDimensions(TestObjs *objs);

int main(int argc, char *argv[]) {
  TEST_INIT();

  // allow test name to be specified on the command line
  if (argc > 1) {
    tctest_testname_to_execute = argv[1];
  }

  TEST(testGetWidth);
  TEST(testGetHeight);
  TEST(testGetTile);
  TEST(testReadMaze);
  TEST(testInvalidMazeDimensions);
  TEST_FINI();
}

void testGetWidth(TestObjs *objs) {
  ASSERT(10 == objs->maze1->getWidth());
}

void testGetHeight(TestObjs *objs) {
  ASSERT(6 == objs->maze1->getHeight());
}

void testGetTile(TestObjs *objs) {
  const Tile *p1 = objs->maze1->getTile(Position(0, 0));
  ASSERT(p1->getGlyph() == "#");
  ASSERT(!p1->isGoal());

  const Tile *p2 = objs->maze1->getTile(Position(1, 1));
  ASSERT(p2->getGlyph() == ".");
  ASSERT(!p2->isGoal());

  const Tile *p3 = objs->maze1->getTile(Position(7, 4));
  ASSERT(!p3->isGoal());
}


void testReadMaze(TestObjs *objs){ 
  ASSERT(!(objs->maze6 == nullptr));
  ASSERT(!(objs->maze7 == nullptr));
  ASSERT(objs->maze8 == nullptr);
  }

void testInvalidMazeDimensions(TestObjs *objs){
  ASSERT(objs->maze9 == nullptr);
}

