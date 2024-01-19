#pragma once
#pragma region DerivedBaseClass
class Meat : public Ingredient
{
protected:
	string type;
public:

	Meat(string name,float price,int count, double fats, double protein, double carbohydrates, int kcal, string type) : Ingredient(name, price,count,fats, protein, carbohydrates, kcal)
	{
		SetType(type);
	}
	void SetType(string type)
	{
		if (type.length() < 2)
			throw runtime_error("Mehsulun novu en az 2 symbol");

		this->type = type;

	}

	void Show(int count) const override
	{

		Ingredient::Show(count);
		cout << " Type: " << type;
	}

	

};


class Vegetable : public Ingredient
{
public:
	Vegetable(string name, float price, int count, double fats, double protein, double carbohydrates, int kcal) : Ingredient(name, price, count, fats, protein, carbohydrates, kcal)
	{

	}

	void Show(int count) const override
	{

		Ingredient::Show(count);

	}





};


class Bread :public Ingredient
{
public:
	Bread(string name, float price, int count, double fats, double protein, double carbohydrates, int kcal) : Ingredient(name, price, count, fats, protein, carbohydrates, kcal)
	{

	}

	void Show(int count) const override 
	{

		Ingredient::Show(count);

	}

	
};



class Cheese : public Ingredient
{
	string size;
public:

	Cheese(string name,float price ,int count, double fats, double protein, double carbohydrates, int kcal, string size) : Ingredient(name,price,count, fats, protein, carbohydrates, kcal)
	{
		this->size = size;
	}



	void Show(int count) const override 
	{

		Ingredient::Show(count);
		cout << size;
	}

	
};


class Drink : public Ingredient
{
	string size;
public:

	Drink(string name, float price, int count, double fats, double protein, double carbohydrates, int kcal,string size) : Ingredient(name, price, count, fats, protein, carbohydrates, kcal)
	{
		this->size = size;;
	}

	void Show(int count) const override 
	{

		Ingredient::Show(count);
		cout << "Size: " << endl;
	}

	
};




class Sauce : public Ingredient
{
public:

	Sauce(string name, float price, int count, double fats, double protein, double carbohydrates, int kcal) : Ingredient(name, price, count, fats, protein, carbohydrates, kcal)
	{

	}
	void Show(int count) const override 
	{

		Ingredient::Show(count);

	}
	
};





#pragma endregion DerivedBaseClass



#pragma region DerivedClassMenutem 

class Burger : public MenuItem {
protected:
	// ... existing code ...
public:
	// ... existing code ...
	Burger(string name, int count, vector<RecipetItem>reciepItem) :MenuItem(name, count, reciepItem)
	{

	}

	void addIngredient(RecipetItem recipetItem, int amount)  override {
		MenuItem::addIngredient(recipetItem, amount);
	}

	void showDishInfo()  override {
		MenuItem::showDishInfo();
	}

	void addToBasket(Basket& basket, vector<MenuItem*>& menuItems) override;

};


class DrinkItem : public MenuItem {
	// ... similar structure as Burger ...
protected:
	// ... existing code ...
public:
	DrinkItem(string name, int count, vector<RecipetItem>reciepItem) :MenuItem(name, count, reciepItem)
	{

	}

	void addIngredient(RecipetItem recipetItem, int amount)  override {
		MenuItem::addIngredient(recipetItem, amount);
	}

	void showDishInfo()  override {
		// ... existing code ...
	}

	void addToBasket(Basket& basket, vector<MenuItem*>& menuItems) override;
};

//class SauceItem : public MenuItem {
//	// ... similar structure as Burger ...
//protected:
//	// ... existing code ...
//public:
//	
//	SauceItem(string name, int count, vector<RecipetItem>reciepItem) :MenuItem(name, count, reciepItem)
//	{
//
//	} 
//
//	void addIngredient(RecipetItem recipetItem, int amount)  override {
//		MenuItem::addIngredient(recipetItem, amount);
//	}
//
//	void showDishInfo()  override {
//		// ... existing code ...
//	}
//
//	void addToBasket(Basket& basket, vector<MenuItem*>& menuItems) override {
//		// ... existing code ...
//		MenuItem::addToBasket(basket, salatItems);
//	}
//};

class SalatItem : public MenuItem {
	// ... similar structure as Burger ...
protected:
	// ... existing code ...
public:
	SalatItem(string name, int count, vector<RecipetItem>reciepItem) :MenuItem(name, count, reciepItem)
	{

	}

	void addIngredient(RecipetItem recipetItem, int amount)  override {
		MenuItem::addIngredient(recipetItem, amount);
	}

	void showDishInfo()  override {
		// ... existing code ...
	}

	void addToBasket(Basket& basket, vector<MenuItem*>& menuItems) override;
};

//class FriesItem : public MenuItem {
//	// ... similar structure as Burger ...
//protected:
//	// ... existing code ...
//public:
//	FriesItem(string name, int count, vector<RecipetItem>reciepItem) :MenuItem(name, count, reciepItem)
//	{
//
//	}
//
//	void addIngredient(RecipetItem recipetItem, int amount)  override {
//		MenuItem::addIngredient(recipetItem, amount);
//	}
//
//	void showDishInfo()  override {
//		// ... existing code ...
//	}
//
//	void addToBasket(Basket& basket) override {
//		// ... existing code ...
//		MenuItem::addToBasket(basket);
//	}
//};

#pragma endregion DerivedClassMenutem





