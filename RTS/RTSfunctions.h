#ifndef RTS_FUNCTIONS_H
#define RTS_FUNCTIONS_H

int difficulty;
int style;
string end_of_page = "--------------------\n";

void initCivilizations();
int beginGame();
void newGame();
void loadGame();
void playerTurn();

//a=kingdom,b=age,c=max_age,d=hp,e=dmg,f=alignment,g=troop_cacapity,h=name;
King ProphesiedKing(0, 20, 90, 300, 300, 75, 10000, "The Prophesied King"), KingOfKings(0, 20, 130, 500, 500, 50, 0, "The King of Kings"), Conqueror(0, 30, 90, 100, 100, 50, 200000, "The Conqueror");
King GodEmperor(1, 30, 500, 300, 300, 50, 10000, "The God Emperor of Humanity"), ChosenOne(1, 16, 70, 500, 500, 100, 1000, "The Chosen One"), BringerOfLight(1, 20, 80, 100, 100, 100, 100, "The Prophesied Bringer of Light");
King NamelessGodOfEvil(2, 7000, 50000, 100, 100, 0, 0, "The Nameless God Of Evil"), VampireLord(2, 120, 10000, 500, 500, 50, 10000, "The Vampire Lord"), DemonKing(2, 10, 1200, 500, 500, 0, 10000, "The Demon King");
King WorldEater(3, 7000, 50000, 1000, 1000, 0, 0, "The World Eater"), PerfectBeing(3, 7000, 50000, 1000, 1000, 50, 0, "The Perfect Being"), KingOverHeaven(3, 110, 50000, 750, 750, 50, 10000, "The Ascended King Over Heaven");
King MonarchOfIllusions(4, 3000, 10000, 1000, 100, 0, 10, "The Monarch of Illusions"), LordOfShadows(4, 20, 600, 500, 500, 50, 1000, "The Lord of Shadows"), StrongestSorcerer(4, 30, 90, 750, 750, 50, 0, "The Strongest Sorcerer");
King SithLord(5, 80, 1000, 200, 200, 0, 0, "The Galactic Senate Chanceller"), Android(5, 1, 100, 200, 200, 50, 10000, "The Android"), EmperorOfSteel(5, 30, 500, 200, 200, 50, 5000, "The Emperor of Steel");
King IA(6, 1, 2000, 100, 100, 50, 0, "The IA"), MonsterKing(6, 20, 100, 500, 500, 50, 10000, "The Monster King"), ManInTheSuit(6, 40, 200, 100, 100, 0, 0, "The Man in the Suit"), PerfectHomunculus(6, 1, 150, 500, 500, 0, 100, "The perfect homunculus");

// a=kingdom,b=kind,c=ranged,d=food_cost_per_month,e=dmg,f=hp,g=size,h=name
Troops Knight_1(0, 1, 0, 1, 10, 10, 2, "Training knight"), Archer_1(0, 2, 1, 1, 5, 5, 2, "Training archer"), Shielder_1(0, 3, 0, 2, 5, 18, 3, "Weak shielder"), Horse_1(0, 4, 0, 3, 10, 18, 5, "Horse mounted training knight");
Troops Cleric_1(1, 1, 0, 1, 8, 12, 2, "Cleric student"), HolyArcher_1(1, 2, 1, 1, 7, 3, 2, "Training holy archer"), Paladin_1(1, 3, 0, 2, 4, 23, 3, "Paladin's disciple"), Falcon_1(1, 4, 1, 1, 5, 5, 1, "Young falcon");
Troops Goblin_1(2, 1, 0, 0, 15, 7, 2, "Young goblin"), RangedGoblin_1(2, 2, 1, 2, 10, 7, 2, "Rock thrower goblin"), Slime_1(2, 3, 0, 0, 1, 25, 2, "Small slime"), Bat_1(2, 4, 1, 1, 3, 3, 1, "Bat");
Troops Believer_1(3, 1, 0, 1, 8, 8, 2, "Novice believer"), ArcherBeliever_1(3, 2, 1, 1, 5, 5, 2, "Novice believer with bow"), Penitent_1(3, 3, 0, 0, 2, 25, 2, "Weak penitent"), ElementalSpirit_1(3, 4, 0, 0, 10, 10, 1, "Young elemental spirit");
Troops Summon_1(4, 1, 0, 0, 8, 8, 2, "Weak summoned clone"), Mage_1(4, 2, 1, 2, 10, 3, 2, "Mage Apprentice"), Caster_1(4, 3, 0, 2, 0, 30, 3, "Apprentice shield caster"), WolfSummon_1(4, 4, 0, 0, 10, 5, 1, "Weak summoned wolf");
Troops Droid_1(5, 1, 0, 0, 6, 6, 1, "Small battle droid"), RangedDroid_1(5, 2, 1, 0, 6, 3, 1, "Small ranged droid"), Barrier_1(5, 3, 0, 0, 0, 30, 3, "Weak mobile barrier"), Drone_1(5, 4, 1, 0, 10, 1, 1, "Weak combat drone");
Troops Parasite_1(6, 1, 0, 0, 10, 1, 1, "Small weak parasite"), Bacteria_1(6, 2, 1, 2, 1, 1, 0, "Weak air propagant bacteria colony"), Flesh_1(6, 3, 0, 0, 2, 20, 2, "Weak flesh wall"), ZombieWolf_1(6, 4, 0, 1, 10, 5, 1, "Zombie dog");

// a=kingdom,b=capacity,c=loyalty,d=xp,e=dmg,f=hp,g=archery_boost,h=melee_boost,i=defender_boost,j=beast_boost,k=dmg_boost,l=hp_boost,m=foodcost_boost,n=moral_boost,o=alignment, p=name;
Champions MiyamotoMusashi(0, 30, 90, 0, 100, 100, 250, 250, 100, 80, 200, 100, 80, 150, 50, "Miyamoto Musashi"), Spartacus(0, 12000, 90, 0, 150, 200, 90, 105, 105, 90, 100, 100, 70, 130, 50, "Spartacus");
Champions JonathanJoestar(1, 10, 80, 0, 200, 200, 110, 150, 150, 150, 150, 200, 100, 200, 100, "Jonathan Joestar"), FatherMozgus(1, 1000, 80, 0, 30, 200, 100, 100, 120, 90, 90, 120, 80, 150, 30, "Father Mozgus");
Champions PyramidHead(2, 100, 100, 0, 200, 200, 100, 150, 200, 150, 100, 150, 0, 100, 0, "Pyramid Head");
Champions Indra(3, 500, 60, 0, 150, 150, 100, 110, 110, 200, 110, 120, 100, 110, 50, "Indra Otsukitsuki");
Champions Miraak(4, 1000, 60, 0, 200, 200, 110, 95, 95, 110, 105, 100, 100, 100, 50, "Miraak");
Champions Ghostrunner(5, 100, 100, 0, 300, 100, 100, 300, 70, 80, 150, 80, 100, 150, 50, "Ghostrunner");
Champions Hunter(6, 10000, 100, 0, 100, 500, 80, 105, 110, 110, 90, 110, 100, 200, 0, "Hunter");

string medieval_troops_list[4][3][6] = {
	{{"Club Fighter", "Stone Axe Warrior", "Bronze Swordsman", "Hoplite", "Legionary", "Charior Swordsman"},
	 {"Man-at-Arms", "Knight", "Samurai", "Landsknecht", "Two-Handed Swordsman", "Halberdier"},
	 {"Musketeer with rapier", "Grenadier", "Trench Raider", "Flame Trooper", "Marine Raider", "Spec Ops Breacher"}},

	{{"Stone Slinger", "Tribal Archer", "Composite Archer", "Javelin Thrower", "Chu-Ko-Nu Archer", "Chariot Archer"},
	 {"Longbowman", "Crossbowman", "Mounted Archer", "Arquebusier", "Musketeer", "Hand Cannonier"},
	 {"Light Infantryman", "Rifleman", "Gatling Gunner", "Sniper", "Machine Gunner", "Spec Ops Sniper"}},

	{{"Shield bearer", "Phalanx Hoplite", "Chariot Protector", "0", "0", "0"},
	 {"Doppelsoldner", "Halberdier Guard", "Cuirassier Defender", "0", "0", "0"},
	 {"Riot Shield Trooper", "Body Armor Unit", "Ballistic Shield Unit", "0", "0", "0"}},

	{{"War Dogs Pack", "Camel Rider", "Chariot scout", "0", "0", "0"},
	 {"Knight's Destrier", "Cuirassier", "Cataphract", "0", "0", "0"},
	 {"Armored Car", "Gatling Gun Carriage", "Battle Tank", "0", "0", "0"}}};

string medieval_buildings_list[3][6][5] = {
	{{"Small swidden", "Peasents croft", "Feudal manor", "Mechanized ranch", "Agroindustrial complex"},
	{"Forest foraging wood storage", "Medieval woodlot", "Logging camp", "Steam-powered lumber mill", "Industrial logging operation center"},
	{"Flint knapping camp", "Small stone quarry", "Iron reinforced quarry", "Dynamite quarry", "Mechanized Granite Complex"},
	{"Mineral gathering camp", "Surface mine", "Basic underground mine", "Blasting mine", "Precision mine"}, {"0", "0", "0", "0", "0"}, {"0", "0", "0", "0", "0"}},
	
	{{"Grain mill", "Comunal bakery", "Canned food factory", "Frozen food factory", "Automated food production plant"},
	{"Primitive iron forge", "Catalan forge", "Blast furnace", "Charcoal ironworks", "Automated steel mill facility"},
	{"Ancient apothecary", "Asclepeion", "Monastic alchemy", "Penincillin production plant", "Automated molecular synthetsizer"},
	{"Bronze weapon foundry", "Iron weapon smithy", "Steel weapon workshop", "Standardized Musket Factory", "CNC precision weapon facility"},
	{"Artisan workshop", "Domestic Handloom", "Carpentry workshop", "Industrial furniture factory", "Automated factory"},
	{"Temple-library", "Philosophical academy", "Monastic school", "Technical institute", "National science foundation"}},
	
	{{"Merchant tent", "Trade guild hall", "Auction hall", "Wholesale market hall", "Distribution center"},
	{"Healing temple", "Monastic infirmary", "General hospital", "Polyclinic", "Medical-city complex"},
	{"Temple-school", "Library of scrolls", "Cathedral school", "Monitorial school", "Corporate university"},
	{"Guard barracks", "Dungeon keep", "Fortress guardhouse", "Penintentiary", "Maximum security prison"},
	{"'s recruitment center","0","0","0","0"}, {"0","0","0","0","0"}}};

#endif