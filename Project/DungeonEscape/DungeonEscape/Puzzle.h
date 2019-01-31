#pragma once
#include <cstdlib>
#include <string>
#include <map>
#include <list>
#include <iostream>

enum PuzzleType {
	PTYPE_MATH
};

//std::map<int, std::list<std::string>> puzzles = {
//	{1,{"1*20+5*0"}},
//	{2,{"(5*10+10)"}},
//	{3,{"15/3-2"}},
//	{4,{"(8*2+4)/5"}},
//	{5,{"1+2+3-1"}},
//	{6,{"3*2"}}
//};

class Puzzle
{
private:
	PuzzleType type;
	std::string equation;
public:
	Puzzle();
	~Puzzle();
	void GenerateEquation(float res);
	std::string Equation() { return equation; };
};
