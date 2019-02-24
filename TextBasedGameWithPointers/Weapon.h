#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Weapon
{
public:
	Weapon(string);
	~Weapon();

	map<std::string, int> damageMap;
	map <std::string, vector<std::string>> attackTypes;

	std::string weaponType;
	void setWeaponType(std::string*);
};

