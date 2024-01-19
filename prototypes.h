#pragma once
//---------------------------------------------{Global Variables}-----------------------------------------------//
int mcBudget = 0;
//SKLAD
//QIYMET VAHIDI MANATDIR.
//COUNT SKLADDAKI INGREDIENT SAYI.

Basket basket;
#pragma region MeatInDepo

  Ingredient* ingredientBeef = new Meat("100 % Beef Patty ", 15, 5, 12, 22, 31, 30, "COW"); //name//price//count//fats//protein//carbohidrat//kcall//type
  Ingredient* ingredientChicken_1 = new Meat("Crispy Chicken Fillet", 12, 5, 10, 19, 25,25, "Chicken");
  Ingredient* ingredientChicken_2 = new Meat("McChicken Patty", 12, 5, 10, 19, 25, 25, "Chicken");
  Ingredient* ingredientFish = new Meat("Fish Filet Patty", 12, 5, 10, 19, 25, 25, "Fish");

#pragma endregion MeatInDepo


#pragma region VegetableInDepo

  Ingredient* ingredientTometo = new Vegetable("Roma Tomato", 2, 5, 4, 7, 8, 8);   //name//price//count//fats//protein//carbohidrat//kcall
  Ingredient* ingredientOnion = new Vegetable( "  Onions   ", 1.5f, 5, 4, 7, 8, 8);
  Ingredient* ingredientCucember = new Vegetable("Pickle Slices", 2.5, 5, 6, 7, 8,10);
  Ingredient* ingredientPotato = new Vegetable("  Onions   ", 1.5f, 5, 4, 7, 8, 8);
  Ingredient* ingredientLettuce = new Vegetable("Shredded Lettuce", 0.5f, 5, 10, 2, 3, 10);

#pragma endregion VegetableInDepo


#pragma region sauceInDepo 

  Ingredient* ingredientKetchup = new Sauce("Ketchup", 0.7f, 10, 2, 4, 5, 6);
  Ingredient* ingredientMayonnaise = new Sauce("Mayonnaise", 0.7f, 10, 3, 5, 5, 6);
  Ingredient* ingredientPepperSauce = new Sauce("PepperSauce", 0.8f, 10, 2, 3, 5, 6);

#pragma endregion  sauceInDepo

#pragma region CheeseIndepo

  Ingredient* ingredientAmericanCheese = new Cheese("AmericanCheese", 1.5f, 10, 5, 5, 6, 7,"middle");



#pragma endregion CheeseInDepo

#pragma region BreadInDepo

  Ingredient* ingredientQuarterPoundBun = new Bread("QuarterPoundBun", 1, 6, 1, 2, 3, 4);
  Ingredient* ingredientRegularBun = new Bread("RegularBun", 0.8f, 6, 1, 2, 3, 4);
  Ingredient* ingredientBigMacBun = new Bread("BigMacBun", 1.5f, 6, 3, 4, 5, 6);



#pragma endregion BreadInDepo

#pragma region DrinkInDepo

  Ingredient* ingredientCola_1 = new Drink("Middle CocaCola", 2.5, 5, 15, 5, 6, 7, "middle");
  Ingredient* ingredientCola_2 = new Drink("Big  CocaCola", 3.5, 5, 15, 5, 6, 7, "big");
  Ingredient* ingredientFanta = new Drink("Middle Fanta", 2.7f, 5, 6, 7, 8, 9, "middle");
  Ingredient* ingredientSprite = new  Drink("Middle Fanta", 2.7f, 5, 7, 8, 9, 10, "middle");



#pragma endregion DrinkInDepo

#pragma region Burgers

  RecipetItem bigMacbeef(1, ingredientBeef);
  RecipetItem bigMacLettuce(1, ingredientLettuce);
  RecipetItem bigMacKetchup(1, ingredientKetchup);
  RecipetItem bigMacCheese(1, ingredientAmericanCheese);
  RecipetItem bigMacOnion(1, ingredientOnion);
  RecipetItem bigMacCucumber(1, ingredientCucember);
  RecipetItem bigMacBigMacBun(2, ingredientBigMacBun);

  vector<RecipetItem>BigMacReciept = { bigMacbeef, bigMacLettuce ,bigMacKetchup  ,bigMacCheese , bigMacOnion ,bigMacCucumber ,bigMacBigMacBun };
  MenuItem* bigMcBurger = new Burger("Big Mac Burger", 1, BigMacReciept);

  RecipetItem hamburgerBeef(1, ingredientBeef);
  RecipetItem hamburgerBread(1, ingredientRegularBun);
  RecipetItem hamburgerKetchup(1, ingredientKetchup);
  RecipetItem hamburerCucember(1, ingredientCucember);
  RecipetItem hamburgerOnion(1, ingredientOnion);
 
  vector<RecipetItem>hamburgerReciept = { hamburgerBeef ,hamburgerBread ,hamburgerKetchup ,hamburerCucember ,hamburgerOnion };
  MenuItem* hamburger =  new Burger("Hamburger", 1, hamburgerReciept);




  RecipetItem  mcChickenMeat(1, ingredientChicken_2);
  RecipetItem  mcChickenBread(1, ingredientRegularBun);
  RecipetItem  mcChickenLettuce(1, ingredientLettuce);
  RecipetItem  mcChickenMayonnaise(1, ingredientMayonnaise); 

  vector<RecipetItem>mcChickenReciept = { mcChickenMeat ,mcChickenBread ,mcChickenLettuce ,mcChickenMayonnaise };
  MenuItem* mcChicken = new Burger("McChicken", 1, mcChickenReciept);


  RecipetItem filetOFishMeat(1, ingredientFish);
  RecipetItem filetOFishBread(1, ingredientQuarterPoundBun);
  RecipetItem filetOFishTometo(1, ingredientTometo);
  RecipetItem filetOFishCheese(1, ingredientAmericanCheese);
  RecipetItem filetOFishSouce(1, ingredientPepperSauce);

  vector<RecipetItem> filetOFishReciept = { filetOFishMeat ,filetOFishBread ,filetOFishTometo ,filetOFishCheese ,filetOFishSouce };
  MenuItem* filetOFish = new Burger("Filet-O-Fish", 1, filetOFishReciept);

#pragma endregion Burgers


#pragma region Salat 

  RecipetItem vegSalatMeat(1, ingredientChicken_1);
  RecipetItem vegSalatTometo(2, ingredientTometo);
  RecipetItem vegSalatSouce(2, ingredientMayonnaise);
  RecipetItem vegSalatLettuce(1, ingredientLettuce);
  RecipetItem vegSalatPoteto(1, ingredientPotato);

  vector<RecipetItem>vegSalatReciept = { vegSalatMeat ,vegSalatTometo ,vegSalatSouce ,vegSalatLettuce ,vegSalatPoteto };
  MenuItem* vegSalat = new SalatItem("Vegatable Salat", 1, vegSalatReciept);

  RecipetItem sezarMeat(1, ingredientChicken_2);
  RecipetItem sezarTometo(1, ingredientTometo);
  RecipetItem sezarSouce(1, ingredientPepperSauce);
  RecipetItem sezarLettuce(1, ingredientLettuce);
  RecipetItem sezarBread(1, ingredientQuarterPoundBun);

  vector<RecipetItem> sezarSalatReciept = { sezarMeat ,sezarTometo ,sezarSouce ,sezarLettuce ,sezarBread };
  MenuItem* sezarSalat = new SalatItem("Sezar Salat", 1, sezarSalatReciept);

#pragma endregion Salats 


#pragma region Drink

  RecipetItem fanta(1, ingredientFanta);
  RecipetItem cola_1(1, ingredientCola_1);
  RecipetItem cola_2(1, ingredientCola_2);
  RecipetItem sprite(1, ingredientSprite);

  vector<RecipetItem>colaReciept = {cola_1 ,cola_2 };
  MenuItem* drinkCola = new DrinkItem("Cola-Cola", 1, colaReciept);

  vector<RecipetItem>fantaReciept  {fanta };
  MenuItem* drinkFanta = new DrinkItem("Fanta", 1, fantaReciept);

  vector<RecipetItem>spriteReciept  {sprite };
  MenuItem* drinkSprite = new DrinkItem("Sprite", 1, spriteReciept);

#pragma endregion Drinks


  vector<MenuItem*>burgerItems = { bigMcBurger ,hamburger,mcChicken,filetOFish };
  vector<MenuItem*>salatItems = { vegSalat , sezarSalat };
  vector<MenuItem*>drinkItem = { drinkCola ,drinkFanta ,drinkFanta };


 void Burger::addToBasket(Basket& basket, vector<MenuItem*>& menuItems)  {
	 
	  MenuItem::addToBasket(basket, burgerItems);
  }

 void DrinkItem::addToBasket(Basket& basket, vector<MenuItem*>& menuItems)  {
	
	 MenuItem::addToBasket(basket, drinkItem);
 }
 void SalatItem::addToBasket(Basket& basket, vector<MenuItem*>& menuItems) {

	 MenuItem::addToBasket(basket, salatItems);
 }
