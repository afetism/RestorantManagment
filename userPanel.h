#pragma once
class Register
{
	string email;
	string password;


	bool isValidEmailFormat(string& email) const
	{
		regex emailRegex("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$");
		return regex_match(email, emailRegex);
	}

	bool isValidPasswordFormat(string& password) const
	{
		if (password.length() < 8)
			return false;

		bool hasUpperCharacter = false;
		for (char ch : password)
		{
			if (isupper(ch))
			{
				hasUpperCharacter = true;
				break;
			}

		}

		bool hasLowCharacter = false;
		for (char ch : password)
		{
			if (islower(ch))
			{
				hasLowCharacter = true;
				break;
			}

		}

		if (!(hasUpperCharacter && hasLowCharacter))
			return false;

		bool hasValidSymbol = false;
		for (char ch : password)
		{
			if (ch == '.' || ch == '!' || ch == ',' || ch == '?')
			{
				hasValidSymbol = true;
				break;
			}
		}
		if (!hasValidSymbol)
			return false;


		return true;

	}
public:
	Register(string email, string password)
	{
		setEmail(email);
		setPassWord(password);
	}

#pragma region Setters
	void setEmail(string& email)
	{
		if (!isValidEmailFormat(email))
			throw runtime_error("Invalid Email Format");

		this->email = email;
	}

	void setPassWord(string& password)
	{
		
		if (!isValidPasswordFormat(password))
			throw runtime_error("Invalid Password Format (must be min 1 Up symbol, min 1 Low symbol, min 8 symbol len, and use 1 symbol(.,!?)");


		this->password =password;
	}
#pragma endregion Setters


#pragma region Getters

	string getEmail() const { return email; }
	string getPassword() const { return password; }

#pragma endregion  Getters

	
	bool signIn(vector<Register>& registeredUsers)
	{
	

		for (auto& user : registeredUsers)
		{
			if (user.getEmail() == email && user.getPassword() == password)
				return true;
		}

		return false;
	}


	bool signUp(vector<Register>& registeredUsers)
	{

		for (auto users : registeredUsers)
		{
			if (users.getEmail() == email)
				throw runtime_error("Email is already registered.");
		}

		registeredUsers.push_back(*this);
		return true;


	}

};

bool isUserInFile(const Register& user, const string& fileName)
{
	ifstream fs(fileName);
	if (fs.is_open())
	{
		string line;
		while (getline(fs, line))
		{
			size_t pos = line.find("#");
			if (pos != string::npos)
			{
				string emailInFile = line.substr(0, pos);
				if (emailInFile == user.getEmail())
				{
					fs.close();
					return true;  // User is already present in the file
				}
			}
		}
		fs.close();
	}
	return false;  // User is not found in the file
}

void writeAllUserFiles(const vector<Register>& users, const string& fileName)
{
	ofstream fs(fileName, ios::app);
	if (fs.is_open())
	{
		for (const auto& user : users)
		{
			
			if (isUserInFile(user, fileName))
			{
				continue; 
			}

			fs << user.getEmail() << "#" << user.getPassword() << "\n";
			fs.seekp(0, ios::beg);
		}
		fs.close();
	}
	else
	{
		throw runtime_error("Failed to open the file for writing!");
	}
}



void readAllUserFiles(vector<Register>& users, const string& fileName) {
	ifstream fs(fileName, ios::in);
	if (fs.is_open()) {
		string line;

		while (getline(fs, line)) {
			int pos = line.find('#');
			if (pos != string::npos) {
				string email = line.substr(0, pos);
				string password = line.substr(pos + 1);


				users.push_back(Register(email, password));
			}
		}

		fs.close();
	}
	else {
		cerr << "Error opening file: " << fileName << endl;
	}
}

int handleMenu(vector<string>& menuItems, int& choose) {
	int num = _getch();
	if (num == 224) {
		num = _getch();
		moveInMenu(menuItems, choose, direction(num));
		system("cls");
		displayMenu(menuItems, choose);
	}
	return num;
}

void addIngredientMenu(vector<MenuItem*>& items, int chooseItems)
{
	int choose = 0;
	system("cls");
	vector<string> str = getIngredientName(items, chooseItems);
	displayMenu(str, choose);
	while (true)
	{
		int num = handleMenu(str, choose);
		if (num == 13)
		{
			if (choose == str.size() - 1)
			{
				system("cls");
				displayMenu(MenuMethods, choose);
				return;
			}
			else

			{
				system("cls");
			
				while(true)
				{
					try
					{
						cout << "Enter Count of Ingredient: ";
						int count;
						cin >> count;
						int i = 0;
						for (auto& item : items)
						{

							//add ingredient
							if (chooseItems == i)
							{
								vector<RecipetItem>& recipeItems = item->getRecieptItem();
								item->addIngredient(recipeItems[choose], count);
								break;
							}
							i++;
						}
						break;
					}
					catch (const std::runtime_error& ex)
					{
						cout << ex.what();
					}
				}
				
			}
		}

	}

}

void showMenuItemIngredient(vector<MenuItem*>& items, int chooseItems)
{
	int i = 0;
	for (auto& item : items)
	{

		//add ingredient
		if (chooseItems == i)
		{
			item->showDishInfo();
			break;
		}
		i++;
	}
}

void addToBasketMenuItem(vector<MenuItem*>& items, int chooseItems)
{
	int i = 0;
	for (auto& item : items)
	{

		//add ingredient
		if (chooseItems == i)
		{
			item->addToBasket(basket,items);
			break;
		}
		i++;
	}
}

void chooseMenuMethod(vector<string>& s,vector<MenuItem*>& items,int chooseItem)
{
	system("cls");
	int choose = 0;
	vector<string>str = displayMenu(MenuMethods, choose);
	while (true)
	{
		int num = handleMenu(MenuMethods, choose);
		if(num == 13)
		{
			if (choose == str.size() - 1)
			{
				system("cls");
				displayMenu(s, choose);
				return;
			}
			else if (choose == 0)
			{
				int i = 0;
				for (auto& item : items)
				{
					
						//add ingredient
					if (chooseItem == i)
					{
						addIngredientMenu(items, chooseItem);
						break;
					}
					i++;
				}
			}
			else if (choose == 2)
			{
				int i = 0;
				for (auto& item : items)
				{

					//show
					if (chooseItem == i)
					{
						showMenuItemIngredient(items, chooseItem);
						break;
					}
					i++;
				}
			}
			else if (choose == 4)
			{
				int i = 0;
				for (auto& item : items)
				{

					//add basket
					if (chooseItem == i)
					{
						addToBasketMenuItem(items, chooseItem);
						break;
					}
					i++;
				}
			}
		}

	}
}

void chooseBurgerFromMenu()
{
	system("cls");
	int choose = 0;
	vector<string> str = getMenuItemsNames(burgerItems);
	vector<string> BurgerItems = displayMenu(str, choose);
	while (true)
	{
		int num = handleMenu(BurgerItems, choose);
		if (num == 13)
		{
			if (choose == str.size() - 1)
			{
				system("cls");
				displayMenu(mainMenu, choose);
				return;
			}
			else {
				chooseMenuMethod(BurgerItems, burgerItems,choose);
			}

		}
	}
}
void chooseSalatFromMenu()
{
	system("cls");
	int choose = 0;
	vector<string> str = getMenuItemsNames(salatItems);
	vector<string> SalatItems = displayMenu(str, choose);
	while (true)
	{
		int num = handleMenu(SalatItems, choose);
		if (num == 13)
		{
			if (choose == str.size() - 1)
			{
				system("cls");
				displayMenu(mainMenu, choose);
				return;
			}
			else {
				chooseMenuMethod(SalatItems, salatItems, choose);
			}

		}
	}
}

void chooseDrinksFromMenu()
{
	system("cls");
	int choose = 0;
	vector<string> str = getMenuItemsNames(drinkItem);
	vector<string> DrinkItems = displayMenu(str, choose);
	while (true)
	{
		int num = handleMenu(DrinkItems, choose);
		if (num == 13)
		{
			if (choose == str.size() - 1)
			{
				system("cls");
				displayMenu(mainMenu, choose);
				return;
			}
			else {
				chooseMenuMethod(DrinkItems, drinkItem, choose);
			}

		}
		
	}
}

void chooseBasketMethod(vector<string>str)
{
	int choose = 0;
	vector<string>s = displayMenu(basketItemMethos, choose);
	while (true)
	{
		int num = handleMenu(s, choose);
		if (num == 13)
		{
			if (choose == s.size() - 1)
			{
				system("cls");
				displayMenu(str, choose);
				return;
			}
		}
	}
}
void myBasetMenu()
{
	int choose = 0;
	vector<string>str = basket.showBasket();
	displayMenu(str, choose);
	while (true)
	{
		
		int num = handleMenu(str, choose);
		if (num == 13)
		{
			if (choose == str.size() - 2)
			{
				system("cls");
				displayMenu(mainMenu, choose);
				return;
			}
			else
			{
				chooseBasketMethod(str);

			}
		}
	}
}

void menuItemMc()
{
	int choose = 0;
	vector<string>menuItems = displayMenu(mainMenu,choose);
	while (true)
	{
		int num = handleMenu(menuItems, choose);
		if (num == 13)
		{
			if (choose == 0)
			{
				chooseBurgerFromMenu();
			}
			else if (choose == 1)
			{
				chooseSalatFromMenu();
			}
			else if (choose == 2)
			{
				chooseDrinksFromMenu();
			}
			else if (choose == 3)
			{
				myBasetMenu();
			}
			else if (choose == menuItems.size()-1)
			{
				system("cls");
				displayMenu(UserRegisterMenu, 0);
				return;
			}
		}
	}
}

void userMenu() {
	int chooseReg = 0;
	system("cls");
	vector<string> menuReg = displayMenu(UserRegisterMenu, chooseReg);

	while (true) {
		int num = handleMenu(menuReg, chooseReg);
		if (num == 13)
		{  

			vector<Register>registers;
			readAllUserFiles(registers, "usersBase.txt");
			string email;
			string password;
			if (chooseReg == 0)
			{
				while (true)
				{
					cout << "Email daxil edin: ";
					getline(cin, email);
					char ch;
					cout << "Password daxil edin: ";
					while ((ch = _getch()) != 13)
					{
						if (ch == 8)
						{
							if (!password.empty())
							{
								password.pop_back();
								cout << "\b \b";
							}
						}
						else
						{
							_putch('*');
							password += ch;
						}
					}
					try
					{
						Register user(email, password);
						user.signIn(registers);
						system("cls");
						menuItemMc();
						break;
					}
					catch (const std::runtime_error& ex)
					{
						system("cls");
						cout << "Error during registration: " << ex.what() << endl;
					}
				}
			}
			else if (chooseReg == 1)
			{
			   while(true)
			   {
			   	 cout << "Email daxil edin: ";
			   	 getline(cin, email);
				 char ch;
				 cout << "Password daxil edin: ";
				 while ((ch = _getch()) != 13)
				 {
					 if (ch == 8)
					 {
						 if (!password.empty())
						 {
							 password.pop_back();
							 cout << "\b \b";
						 }
					 }
					 else
					 {
						 _putch('*');
						 password += ch;
					 }
				 }
			   	 try
			   	 {
			   
			   		 Register user(email, password);
			   		 user.signUp(registers);
			   		 writeAllUserFiles(registers, "usersBase.txt");
			   		 cout << "\nRegistration successful!" << endl;
			   		 cout << "ENTER BACKSPACE  ";
			   		 if (_getch() == 8)
			   		 {
			   			 system("cls");
			   			 displayMenu(UserRegisterMenu, chooseReg);
			   		 }
			   		 break;
			   	 }
			   	 catch (const std::runtime_error& ex)
			   	 {
			   		 system("cls");
			   		 cout << "Error during registration: " << ex.what() << endl;
			   	 }
			   }

		     }
		}
	}
}

void adminMenu() {
	// admin menu 
}

void menu() {
	int chooseUser = 0;
	vector<string> menuUser = displayMenu(RegisterMenu, chooseUser);

	while (true) {
		int num =handleMenu(menuUser, chooseUser);

		
			if (num == 13) {
				if (chooseUser == 0) {
					adminMenu();
				}
				else if (chooseUser == 1) {
					userMenu();
				}
				system("cls");
				displayMenu(RegisterMenu, chooseUser);
			}
		
	}
}