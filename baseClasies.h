#pragma once
class Ingredient {
protected:
	string name;
	int count;
	float price;
	double fats;
	double protein;
	double carbohydrates;
	int kcal;
public:


	Ingredient(string name,float price, int count, double fats, double protein, double carbohydrates, int kcal)
	{
		SetName(name);
		SetProtein(protein);
		SetFats(fats);
		SetCarbohydrates(carbohydrates);
		SetKcal(kcal);
		SetPrice(price);
		SetCount(count);
	}
	//getter setter
#pragma region SETTERS 

	void SetName(string name)
	{
		if (name.length() < 2)
			throw runtime_error("Mehsulun adi en az 2 symbol");

		this->name = name;

	}
	void SetCount(int count)
	{
		if (count <= 0)
			throw runtime_error("Mehsulun sayi menfi ola bilmez");

		this->count = count;
	}

	void SetPrice(float price)
	{
		if (price <= 0)
			throw runtime_error("Mehsulun qiymeti menfi ola bilmez");

		this->price = price;
	}

	void SetProtein(double protein)
	{
		if (protein <= 0)
			throw runtime_error("Protein menfi ola bilmez");

		this->protein = protein;
	}

	void SetFats(double fats)
	{
		if (fats <= 0)
			throw runtime_error("Yagliliq  menfi ola bilmez");

		this->fats = fats;

	}

	void SetCarbohydrates(double carbohydrates)
	{
		if (carbohydrates <= 0)
			throw runtime_error("Karbohidrat menfi ola bilmez");
		this->carbohydrates = carbohydrates;
	}

	void SetKcal(int kcal)
	{
		if (kcal <= 0)
			throw runtime_error("Kalori menfi ola bilmez");
		this->kcal = kcal;
	}


#pragma endregion SETTERS 

#pragma region GETTERS
	string getName() { return name; }
	double getprotein() { return protein; }
	double getFats() { return fats; }
	double getCarbohydrates() { return carbohydrates; }
	int getKcal() { return kcal; }
	int getCount() { return count; }
	float getPrice() { return price;  }
#pragma endregion  GETTERS


	virtual void Show(int amount) const = 0
	{
		cout << "Name: " << name <<" Price: "<<amount* price<< " Fats: " << amount * fats << " Protein : " << amount * protein << " Carbohydrates : " << amount * carbohydrates << " Kcal : " << amount * kcal;
	}

	virtual ~Ingredient() = 0;

};

Ingredient::~Ingredient()
{

}


class RecipetItem
{
	Ingredient* ingredient; //one object  
	int amount;
	//constructor
public:
	RecipetItem(int amount, Ingredient* ingredient)
	{
		SetAmount(amount);
		SetIngredient(ingredient);
	}


#pragma  region Setter
	void SetAmount(int amount)
	{
		if (amount <= 0)
			throw runtime_error("Invalid Amount");

		this->amount = amount;
	}

	void SetIngredient(Ingredient* ingredient)
	{
		if (ingredient == nullptr)
			throw runtime_error("Ingredient can't be NULL");
		this->ingredient = ingredient;
	}
#pragma endregion Setter


#pragma region Getter
	Ingredient* getIngredient() { return ingredient; }
	int getAmount() { return amount; }


#pragma endregion Getter


	void RecipetItemshow()
	{
		cout << "Amount: " << amount << endl;
		ingredient->Show(amount);

	}
	/*~RecipetItem()
	{
		delete ingredient;
	}*/
};
class Basket;

class MenuItem
{
protected:
	vector<RecipetItem>recipetItems;
	string name;
	int count;
public:
	MenuItem(string& name, int count, vector<RecipetItem>& recipetItems)
	{
		SetName(name);
		SetCount(count);
		SetRecipet(recipetItems);
	}

#pragma region SETTER
	void SetName(string name)
	{
		if (name.size() <= 1)
			throw runtime_error("Invalid Burger name");

		this->name = name;
	}

	void SetCount(int count)
	{
		if (count < 0 and count>10)
			throw runtime_error("Invalid Burger count Min 1 Max 10");


		this->count = count;

	}

	void SetRecipet(vector<RecipetItem>& recipetItems)
	{
		if (recipetItems.empty())
			throw runtime_error("Invalid recipets");

		this->recipetItems = recipetItems;
	}
#pragma endregion SETTER

#pragma region GETTER

	string getName() const { return this->name; }
	int getCount() const { return this->count; }
	vector<RecipetItem>& getRecieptItem() { return this->recipetItems; }

#pragma endregion GETTER


	virtual void addIngredient(RecipetItem recipetItem, int amount) = 0
	{
		
		if (amount < 0)
			throw runtime_error("Add ingredient amount more than 0 ");

		for (auto& i : recipetItems)
		{
			if (i.getIngredient() == recipetItem.getIngredient())
			{
				if ((i.getIngredient()->getCount() - amount) > 0)
				{
					i.SetAmount(i.getAmount() + amount);
					i.getIngredient()->SetCount(i.getIngredient()->getCount() - amount);
					return;
				}
				else 
					throw runtime_error("Dont enough ingredient in base");
				
				
			}

		}


	}
	void deleteMenuItem();

	virtual void showDishInfo() = 0
	{
		cout << "Burger Name: " << getName();
		cout << "Burger Count: " << getCount() << "\n";

		cout << "Show Ingredient: \n";
		for (auto i : getRecieptItem())
		{
			cout << "- " << i.getAmount() << " x " << i.getIngredient()->getName() << endl;
			//i.getIngredient()->Show()
		}

	}

	
	virtual void addToBasket(Basket& basket, std::vector<MenuItem*>& menuItems) = 0;

	virtual ~MenuItem() = 0;


};

MenuItem::~MenuItem()
{

}

class Basket {
private:
	vector<MenuItem*> items;

public:
	void addItem(MenuItem* item) {
		items.push_back(item);
		cout << "Menu Item added to  basket " << endl;
	}

	void removeItem(MenuItem* item) {
		auto it = find(items.begin(), items.end(), item);
		if (it != items.end()) {
			items.erase(it);
			cout << "Menu Item removed from  basket" << endl;
		}
		else {
			cout << "Menu Item not found in  basket" << endl;
		}
	}

	vector<string> showBasket() {
		cout << "Basket Contents:\n";
		vector<string>s;
		for (const auto& item : items) {
			s.push_back(item->getName());
		}
		s.push_back("Total Amount");
		s.push_back("Exit");
		s.push_back("Submit");
		return s;
	}
};
bool compareByName(MenuItem* item, const std::string& name) {
	return item->getName() == name;
}

void MenuItem::addToBasket(Basket& basket, std::vector<MenuItem*>& menuItems) {
	// Add the MenuItem to the basket
	basket.addItem(this);

	
	string nameToRemove = getName();
	bool checkHasStock = true;
	for (auto& item : menuItems)
	{
		vector<RecipetItem> recipet = item->getRecieptItem();
		for (auto r : recipet)
		{
			if (r.getAmount() > r.getIngredient()->getCount())
			{
				checkHasStock = false;
				break;
			}
		}
		if (!checkHasStock)
			break;
	}
	if (!checkHasStock) {
		
		auto it = std::remove_if(menuItems.begin(), menuItems.end(),
			[nameToRemove](MenuItem* item) {
				return compareByName(item, nameToRemove);
			});

		if (it != menuItems.end()) {
			
			menuItems.erase(it, menuItems.end());
			std::cout << "Elave olundu ve menyudan cixarildi" << std::endl;
		}
		else {
			std::cout << "Elave olundu, amma menyuda tapilmadi" << std::endl;
		}
	}
	else {
		std::cout << "Elave olundu, amma kifayət qədər malzəmə yoxdur" << std::endl;
	}

	
}