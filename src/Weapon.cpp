#include "Weapon.h"



Weapon::Weapon()
	: m_areaOfEffect(1)
	, m_damage(1)
{
}


Weapon::~Weapon()
{
}

const int & Weapon::getAoE() const
{
	return m_areaOfEffect;
}

const int & Weapon::getDamage() const
{
	return m_damage;
}

void Weapon::setAoE(const int & newAoE)
{
	m_areaOfEffect = newAoE;
}

void Weapon::setDamage(const int & newDamage)
{
	m_damage = newDamage;
}
