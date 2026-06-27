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

// a=kingdom,b=capacity,c=loyalty,d=xp,e=dmg,f=hp,g=archery_boost,h=melee_boost,i=defender_boost,j=beast_boost,k=dmg_boost,l=hp_boost,m=foodcost_boost,n=moral_boost,o=alignment, p=name;
Champions MiyamotoMusashi(0, 30, 90, 0, 100, 100, 250, 250, 100, 80, 200, 100, 80, 150, 50, "Miyamoto Musashi"), Spartacus(0, 12000, 90, 0, 150, 200, 90, 105, 105, 90, 100, 100, 70, 130, 50, "Spartacus");

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

string names_male[200] = {
        "James", "John", "Robert", "Michael", "William", "David", "Richard", "Joseph", "Thomas", "Charles",
        "Christopher", "Daniel", "Matthew", "Anthony", "Mark", "Donald", "Steven", "Paul", "Andrew", "Joshua",
        "Kenneth", "Kevin", "Brian", "George", "Edward", "Ronald", "Timothy", "Jason", "Jeffrey", "Ryan",
        "Jacob", "Gary", "Nicholas", "Eric", "Jonathan", "Stephen", "Larry", "Justin", "Scott", "Brandon",
        "Benjamin", "Samuel", "Gregory", "Alexander", "Frank", "Patrick", "Raymond", "Jack", "Dennis", "Jerry",
        "Tyler", "Aaron", "Jose", "Adam", "Nathan", "Henry", "Douglas", "Zachary", "Peter", "Kyle",
        "Ethan", "Walter", "Noah", "Jeremy", "Christian", "Keith", "Roger", "Terry", "Gerald", "Ethan",
        "Arthur", "Albert", "Carl", "Lawrence", "Dylan", "James", "John", "Oliver", "Lucas", "Liam",
        "Mason", "Logan", "Alexander", "Ethan", "Jacob", "Michael", "Daniel", "Henry", "Jackson", "Sebastian",
        "Aiden", "Matthew", "Samuel", "David", "Joseph", "Carter", "Owen", "Wyatt", "John", "Jack",
        "Luke", "Oliver", "Harry", "George", "Noah", "Leo", "Arthur", "Oscar", "Charlie", "Freddie",
        "Thomas", "William", "Henry", "Alfio", "Archie", "Joshua", "Alexander", "Ethan", "Lucas", "Isaac",
        "Liam", "Noah", "William", "James", "Oliver", "Benjamin", "Lucas", "Henry", "Alexander", "Mason",
        "Michael", "Ethan", "Daniel", "Jacob", "Logan", "Jackson", "Levi", "Sebastian", "Mateo", "Jack",
        "Alasdair", "Graham", "Ian", "Colin", "Neil", "Cameron", "Duncan", "Rory", "Lachlan", "Fiona",
        "Connor", "Sean", "Liam", "Patrick", "Ryan", "Cillian", "Darragh", "Eoin", "Finn", "Roan",
        "Hans", "Jürgen", "Stefan", "Klaus", "Dieter", "Matthias", "Lukas", "Maximilian", "Leon", "Finn",
        "Louis", "Lucas", "Léo", "Gabriel", "Arthur", "Hugo", "Jules", "Maël", "Raphaël", "Nathan",
        "Mateo", "Santiago", "Matías", "Sebastián", "Diego", "Alejandro", "Nicolás", "Samuel", "Benjamin", "Daniel",
        "Giovanni", "Luca", "Marco", "Matteo", "Alessandro", "Leonardo", "Davide", "Mattia", "Lorenzo", "Francesco"
    };
string names_female[200] = {
        "Mary", "Patricia", "Jennifer", "Linda", "Elizabeth", "Barbara", "Susan", "Jessica", "Sarah", "Karen",
        "Nancy", "Lisa", "Betty", "Margaret", "Sandra", "Ashley", "Kimberly", "Emily", "Donna", "Michelle",
        "Carol", "Amanda", "Dorothy", "Melissa", "Deborah", "Stephanie", "Rebecca", "Sharon", "Laura", "Cynthia",
        "Kathleen", "Amy", "Shirley", "Angela", "Helen", "Anna", "Brenda", "Pamela", "Nicole", "Emma",
        "Samantha", "Katherine", "Christine", "Debra", "Rachel", "Catherine", "Carolyn", "Janet", "Ruth", "Maria",
        "Heather", "Diane", "Virginia", "Julie", "Joyce", "Victoria", "Olivia", "Kelly", "Christina", "Lauren",
        "Joan", "Evelyn", "Judith", "Megan", "Cheryl", "Andrea", "Hannah", "Martha", "Jacqueline", "Frances",
        "Gloria", "Ann", "Teresa", "Kathryn", "Sara", "Janice", "Jean", "Alice", "Madison", "Doris",
        "Abigail", "Julia", "Judy", "Grace", "Janice", "Emma", "Olivia", "Ava", "Isabella", "Sophia",
        "Charlotte", "Mia", "Amelia", "Harper", "Evelyn", "Abigail", "Emily", "Ella", "Elizabeth", "Camila",
        "Luna", "Sofia", "Avery", "Mila", "Aria", "Scarlett", "Penelope", "Layla", "Chloe", "Victoria",
        "Emma", "Olivia", "Lily", "Amelia", "Isla", "Ava", "Mia", "Ivy", "Freya", "Grace",
        "Mary", "Jennifer", "Jessica", "Sarah", "Emily", "Emma", "Olivia", "Sophia", "Isabella", "Ava",
        "Chloe", "Charlotte", "Amelia", "Grace", "Lily", "Mia", "Evie", "Ruby", "Ella", "Maya",
        "Fiona", "Isla", "Skye", "Maisie", "Catriona", "Siobhan", "Saoirse", "Aisling", "Niamh", "Caoimhe",
        "Sinead", "Ciara", "Roisin", "Maeve", "Clodagh", "Eimear", "Orla", "Cara", "Erin", "Tara",
        "Emma", "Mia", "Sofia", "Hannah", "Emilia", "Anna", "Marie", "Lina", "Mila", "Leonie",
        "Chloé", "Manon", "Emma", "Louise", "Alice", "Léa", "Lina", "Mila", "Camille", "Léna",
        "Sofía", "Valentina", "Isabella", "Camila", "Luciana", "Mariana", "Victoria", "Martina", "Daniela", "Natalia",
        "Giulia", "Chiara", "Francesca", "Federica", "Sara", "Alice", "Aurora", "Sofia", "Emma", "Giorgia"
    };

string sobrenomes[500] = {
        "Smith", "Jarrett", "Jones", "Johnston", "Irons", "Wilson", "Taylor", "Glover", "Horton", "Taylor",
        "Brown", "Smith", "Hulme", "Brown", "Williams", "Higgins", "Hurst", "Hutton", "Hodges", "Jones",
        "Dixon", "Irvine", "Smith", "Hughes", "Houghton", "Horne", "Hurst", "Thompson", "Taylor", "Day",
        "Johns", "Johnson", "Hale", "Wright", "Janes", "Williams", "Irving", "Howarth", "Glover", "Guest",
        "Hinds", "Hale", "Hopkins", "Smith", "Howarth", "Davies", "Burke", "Hill", "Homer", "Wilson",
        "Howe", "Hutchinson", "Goodwin", "Doyle", "Hobbs", "Walker", "Humphreys", "Horton", "Hyatt", "Evans",
        "Hoyle", "Iles", "Evans", "Gould", "Jackson", "Hooper", "Hutchings", "Hunt", "Hollaway", "Irlam",
        "Green", "Hollaway", "Jeavons", "Davies", "Roberts", "Hutchins", "White", "Goodwin", "Hurd", "Harding",
        "Wood", "Goddard", "Hodges", "Hirst", "Green", "Johnstone", "Hope", "Howard", "Hardy", "Walker",
        "Brown", "Jacques", "Horne", "Hamer", "Goddard", "Hall", "Hancock", "Davenport", "Jackson", "Evans",
        "Jowett", "Clarke", "Hutchinson", "Hudson", "Hustwayte", "Hurst", "Green", "Howitt", "Hustwayte", "Johns",
        "Inman", "Taylor", "Healy", "Robinson", "Greenwood", "Hicks", "Hinds", "Ingram", "Jones", "Hurst",
        "Griffin", "Hudson", "Islip", "Hunt", "Hopkinson", "Humphries", "Brown", "Giles", "Hitchcock", "Wright",
        "Horrobin", "Ingham", "Hulme", "Hussain", "Jagger", "Healy", "Hoyle", "Smith", "Inman", "Giles",
        "Jones", "Griffin", "White", "Hutchinson", "Ingram", "Hill", "Taylor", "Hughes", "Glover", "Hustwayte",
        "Hale", "Humphreys", "Hubbard", "Ions", "Hopkinson", "Hustwayte", "Ingram", "Hook", "Hutchings", "Hopkins",
        "Horrobin", "Thompson", "Jellicoe", "Hubbard", "Howells", "Walker", "Walker", "Iles", "Iles", "Iles",
        "Griffin", "Hale", "Gould", "Jackson", "Francis", "Goodwin", "Howells", "Harding", "Jeffrey", "Howells",
        "Hall", "Jowett", "Davenport", "Howarth", "Hinds", "Taylor", "Hyde", "Ingle", "Jenks", "Hutchins",
        "Wood", "White", "Hoyle", "Humphries", "Hodgkinson", "Hurst", "Innes", "Fletcher", "Hirst", "Jagger",
        "Jones", "Harding", "Jackson", "Hodge", "Hopkinson", "Inglis", "Jones", "Davies", "Smith", "Hargreaves",
        "Hurst", "Jefferies", "Hulme", "Horrobin", "Houldsworth", "Goodwin", "Irvine", "Jackson", "Hicks", "Hinds",
        "Jameson", "Hinds", "Homer", "Williams", "Humphries", "Jones", "Hamer", "Doyle", "Irwin", "Hook",
        "Taylor", "Hopkinson", "Evans", "Jeavons", "Hinds", "Hurst", "Hutchings", "Howells", "Jameson", "Hutchinson",
        "Hutchinson", "Hulme", "Dixon", "Irlam", "Hutchins", "Hinds", "Johns", "Walker", "Humphreys", "Homer",
        "Jones", "Fletcher", "Hughes", "Glover", "Hitchcock", "Hollaway", "Jolliffe", "Evans", "Hinds", "Hopkins",
        "Jeffcoate", "Williams", "Irvine", "Davies", "Hamer", "Hargreaves", "Hussain", "Hirst", "Hutton", "Hickman",
        "Wilson", "Howells", "Howell", "Hill", "Healy", "Goddard", "Doyle", "Howells", "Houldsworth", "Ingham",
        "Hurlstone", "Wright", "Hurlstone", "Robinson", "Davies", "Walker", "Williams", "Irons", "Hutchinson", "Hale",
        "Hurlstone", "Hurst", "Hinds", "Goodwin", "Homer", "Howell", "Hoyle", "Homer", "Evans", "Hale",
        "Jeffcoate", "Islip", "Hulme", "Howarth", "Glover", "Hutchinson", "Hirst", "Hitchcock", "Hinds", "Hurst",
        "Hulme", "Hussain", "Jagger", "Healy", "Hoyle", "Smith", "Inman", "Giles", "Jones", "Griffin",
        "White", "Hutchinson", "Ingram", "Hill", "Taylor", "Hughes", "Glover", "Hustwayte", "Hale", "Humphreys",
        "Hubbard", "Ions", "Hopkinson", "Hustwayte", "Ingram", "Hook", "Hutchings", "Hopkins", "Horrobin", "Thompson",
        "Jellicoe", "Hubbard", "Howells", "Walker", "Walker", "Iles", "Iles", "Iles", "Griffin", "Hale",
        "Gould", "Jackson", "Francis", "Goodwin", "Howells", "Harding", "Jeffrey", "Howells", "Hall", "Jowett",
        "Davenport", "Howarth", "Hinds", "Taylor", "Hyde", "Ingle", "Jenks", "Hutchins", "Wood", "White",
        "Hoyle", "Humphries", "Hodgkinson", "Hurst", "Innes", "Fletcher", "Hirst", "Jagger", "Jones", "Harding",
        "Jackson", "Hodge", "Hopkinson", "Inglis", "Jones", "Davies", "Smith", "Hargreaves", "Hurst", "Jefferies",
        "Hulme", "Horrobin", "Houldsworth", "Goodwin", "Irvine", "Jackson", "Hicks", "Hinds", "Jameson", "Hinds",
        "Homer", "Williams", "Humphries", "Jones", "Hamer", "Doyle", "Irwin", "Hook", "Taylor", "Hopkinson",
        "Evans", "Jeavons", "Hinds", "Hurst", "Hutchings", "Howells", "Jameson", "Hutchinson", "Hutchinson", "Hulme",
        "Dixon", "Irlam", "Hutchins", "Hinds", "Johns", "Walker", "Humphreys", "Homer", "Jones", "Fletcher",
        "Hughes", "Glover", "Hitchcock", "Hollaway", "Jolliffe", "Evans", "Hinds", "Hopkins", "Jeffcoate", "Williams",
        "Irvine", "Davies", "Hamer", "Hargreaves", "Hussain", "Hirst", "Hutton", "Hickman", "Wilson", "Howells",
        "Howell", "Hill", "Healy", "Goddard", "Doyle", "Howells", "Houldsworth", "Ingham", "Hurlstone", "Wright",
        "Hurlstone", "Robinson", "Davies", "Walker", "Williams", "Irons", "Hutchinson", "Hale", "Hurlstone", "Hurst",
        "Hinds", "Goodwin", "Homer", "Howell", "Hoyle", "Homer", "Evans", "Hale", "Jeffcoate", "Islip",
        "Hulme", "Howarth", "Glover", "Hutchinson", "Hirst", "Hitchcock", "Hinds", "Hurst", "Hulme", "Hussain",
        "Jagger", "Healy", "Hoyle", "Smith", "Inman", "Giles", "Jones", "Griffin", "White", "Hutchinson",
        "Ingram", "Hill", "Taylor", "Hughes", "Glover", "Hustwayte", "Hale", "Humphreys", "Hubbard", "Ions"
    };

#endif