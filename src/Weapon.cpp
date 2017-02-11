#include "Weapon.h"



Weapon::Weapon()
	: m_areaOfEffect(1)
	, m_damage(1)
{
}

Weapon::Weapon(const Weapon & copy)
	: m_areaOfEffect(copy.m_areaOfEffect)
	, m_damage(copy.m_damage)
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
