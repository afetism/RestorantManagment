#pragma once
vector<string>RegisterMenu = {
		  " ADMIN ",
		  " USER  "
};

vector<string>UserRegisterMenu = {
		  "  SIGN IN  ",
		  "  SIGN UP  ",
          "RETURN BACK"
};

vector<string>mainMenu = {
		 " BURGERS ",
		 " SALATS  ",
		 " DRINKS  ",
         "MY BASKET",
		 "  EXIT   "
};
vector<string>MenuMethods = {
		 " ADD INGREDIENT  ",
		 "DELETE INGREDIENT",
		 "   SHOW INFO     ",
		 "  SHOW COMMENT   ",
		 "   ADD BASKET    ",
		 "     EXIT        "
};

vector<string>basketItemMethos = {
         "ADD INGREDIENT  ",
         "DELETE INGREDIENT",
         "     BACK        "
};



void moveInMenu(vector<string>arr, int& choose, direction(dir))
{
    switch (direction(dir))
    {
    case UP:
        if (choose > 0)
        {
            swap(arr[choose], arr[choose - 1]);
            choose--;
        }
        else
        {
            swap(arr[choose], arr[arr.size() - 1]);
            choose = arr.size() - 1;
        }
        break;
    case DOWN:
        if (choose < arr.size() - 1)
        {
            swap(arr[choose], arr[choose + 1]);
            choose++;
        }
        else
        {
            swap(arr[choose], arr[0]);
            choose = 0;
        }
        break;
    default:
        break;
    }

}


vector<string>& displayMenu(vector<string>& items, int choose)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (i == choose)
        {
            setConsoleColor(Red, YellowBackground);
            cout << items[i] << endl;
            setConsoleColor(Yellow, RedBackground);
        }
        else
            cout << items[i] << endl;
    }
    return items;
}


vector<string> getMenuItemsNames(vector<MenuItem*>& items) {
    vector<string> s;
    for (const auto& item : items) {
        s.push_back(item->getName());
    }
    s.push_back("Exit");
    return s;
}

vector<string> getIngredientName(vector<MenuItem*>& items,int choose)
{
    vector<string> s;
    int i = 0;
    for (auto& item : items)
    {
        if (choose == i)
        {
             vector<RecipetItem>& recipeItems = item->getRecieptItem();
             for (auto& res_Item : recipeItems)
                 s.push_back(res_Item.getIngredient()->getName());
        }
        i++;
     }
    s.push_back("EXIT");
    return s;
}

