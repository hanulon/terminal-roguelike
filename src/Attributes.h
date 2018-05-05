#pragma once
class Attributes
{
public:
	Attributes();
	~Attributes();

	enum AttributeName
	{
		None,
		Might,
		Dexterity,
		Smarts
	};

	int getMight();
	int getDexterity();
	int getSmarts();
	int getAttributeByEnum(AttributeName attributeName);
	int* getAttributePointerByStringName(std::string name);
	std::string getAttributesOnCharacterSheet();

	void setAttributes(int might, int dexterity, int smarts);
	static const std::string* shortNamesOfAttributes;

private:
	int might;
	int dexterity;
	int smarts;
};

