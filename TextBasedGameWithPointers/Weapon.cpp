#include "Weapon.h"

Weapon::Weapon(string weaponType)
{
	damageMap["none"] = 1;
	damageMap["dagger"] = 2;
	damageMap["sword"] = 4;

	attackTypes["none"] = { "PUNCH", "KICK", "HEADBUTT" };
	attackTypes["dagger"] = { "STAB", "SLASH", "THROW" };
	attackTypes["sword"] = { "LUNGE", "SLASH", "SMASH" };

	setWeaponType(&weaponType);
}

Weapon::~Weapon()
{
}

void Weapon::setWeaponType(string *weaponType)
{
	this->weaponType = *weaponType;
}
