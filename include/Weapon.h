#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
public:
	Weapon();
	~Weapon();

	// Getters

	const int & getAoE() const;
	const int & getDamage() const;

	// Setters

	void setAoE(const int &);
	void setDamage(const int &);

private:
	int m_areaOfEffect;
	int m_damage;
};

#endif // !WEAPON_H