#include "RTSconstants.h"
#include "RTSfunctions.h"

using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>

string input1, input2, input3;
int difficulty, style;
string end_of_page = "--------------------\n";

//a=kingdom,b=age,c=max_age,d=hp,e=dmg,f=alignment,g=troop_cacapity,h=name;
King KingArthur(0,20,90,300,300,75,10000,"The Prophesied King"), Gilgamesh(0,20,130,500,500,50,0,"The King of All that Exists"), MilitaryGenius(0,30,90,100,100,50,200000,"The Military Genius");
King GodEmperor(1,30,500,300,300,50,10000,"The God Emperor of Humanity"), ChosenOne(1,16,70,500,500,100,1000,"The Chosen One"), FalseFalconOfLight(1,20,80,100,100,0,100,"The False Falcon of Light");
King NamelessGodOfEvil(2,7000,50000,100,100,0,0,"The Nameless God Of Evil"), VampireLord(2,120,10000,500,500,0,10000,"The Vampire Lord"), ReincarnatedDemonKing(2,10,1200,500,500,50,10000,"The Reincarnated Demon King");
King WorldEater(3,7000,50000,1000,1000,0,0,"The World Eater"), PerfectBeing(3,7000,50000,1000,1000,50,0,"The Perfect Being"), KingOverHeaven(3,110,50000,750,750,50,10000,"The Ascended King Over Heaven");
King MonarchOfIllusions(4,3000,10000,1000,100,0,10,"The Monarch of Illusions"), KingOfShadows(4,20,600,500,500,50,1000,"The King of Shadows"), StrongestSorcerer(4,30,90,750,750,50,0,"The Strongest Sorcerer");
King SithLord(5,80,1000,200,200,0,0,"The Senate Lord"), Android(5,1,100,200,200,50,10000,"The Android");
King IA(6,1,2000,100,100,50,0,"The IA"), GhoulEmperor(6,20,100,500,500,50,10000,"The Ghoul Emperor"), ManInTheSuit(6,40,200,100,100,0,0,"TheManInTheSuit"), PerfectHomunculus(6,1,150,500,500,0,100,"The perfect homunculus");

// a=kingdom,b=kind,c=ranged,d=food_cost_per_month,e=dmg,f=hp,g=size,h=name
Troops Knight_1(0,1,0,1,10,10,2,"Training knight"), Archer_1(0,2,1,1,5,5,2,"Training archer"), Shielder_1(0,3,0,2,5,18,3,"Weak shielder"), Horse_1(0,4,0,3,10,18,5,"Horse mounted training knight");
Troops Cleric_1(1,1,0,1,8,12,2, "Cleric student"), HolyArcher_1(1,2,1,1,7,3,2,"Training holy archer"), Paladin_1(1,3,0,2,4,23,3,"Paladin's disciple"), Falcon_1(1,4,1,1,5,5,1,"Young falcon");
Troops Goblin_1(2,1,0,0,15,7,2,"Young goblin"), RangedGoblin_1(2,2,1,2,10,7,2,"Rock thrower goblin"), Slime_1(2,3,0,0,1,25,2,"Small slime"), Bat_1(2,4,1,1,3,3,1,"Bat");
Troops Believer_1(3,1,0,1,8,8,2,"Novice believer"), ArcherBeliever_1(3,2,1,1,5,5,2,"Novice believer with bow"), Penitent_1(3,3,0,0,2,25,2,"Weak penitent"), ElementalSpirit_1(3,4,0,0,10,10,1,"Young elemental spirit");
Troops Summon_1(4,1,0,0,8,8,2,"Weak summoned clone"), Mage_1(4,2,1,2,10,3,2,"Mage Apprentice"), Caster_1(4,3,0,2,0,30,3,"Apprentice shield caster"), WolfSummon_1(4,4,0,0,10,5,1,"Weak summoned wolf");
Troops Droid_1(5,1,0,0,6,6,1,"Small battle droid"), RangedDroid_1(5,2,1,0,6,3,1,"Small ranged droid"), Barrier_1(5,3,0,0,0,30,3,"Weak mobile barrier"), Drone_1(5,4,1,0,10,1,1,"Weak combat drone");
Troops Parasite_1(6,1,0,0,10,1,1,"Small weak parasite"), Bacteria_1(6,2,1,2,1,1,0,"Weak air propagant bacteria colony"), Flesh_1(6,3,0,0,2,20,2,"Weak flesh wall"), ZombieWolf_1(6,4,0,1,10,5,1,"Zombie dog");

// a=kingdom,b=capacity,c=loyalty,d=xp,e=dmg,f=hp,g=archery_boost,h=melee_boost,i=defender_boost,j=beast_boost,k=dmg_boost,l=hp_boost,m=foodcost_boost,n=moral_boost,o=alignment, p=name;
Champions MiyamotoMusashi(0,30,90,0,100,100,250,250,100,80,200,100,80,150,50,"Miyamoto Musashi"), Spartacus(0,12000,90,0,150,200,90,105,105,90,100,100,70,130,50,"Spartacus");
Champions JonathanJoestar(1,10,80,0,200,200,110,150,150,150,150,200,100,200,100,"Jonathan Joestar"), FatherMozgus(1,1000,80,0,30,200,100,100,120,90,90,120,80,150,30,"Father Mozgus");
Champions PyramidHead(2,100,100,0,200,200,100,150,200,150,100,150,0,100,0,"Pyramid Head");
Champions Indra(3,500,60,0,150,150,100,110,110,200,110,120,100,110,50,"Indra Otsukitsuki");
Champions Miraak(4,1000,60,0,200,200,110,95,95,110,105,100,100,100,50,"Miraak");
Champions Ghostrunner(5,100,100,0,300,100,100,300,70,80,150,80,100,150,50,"Ghostrunner");
Champions Hunter(6,10000,100,0,100,500,80,105,110,110,90,110,100,200,0,"Hunter");

// t1=tech_req,ap=aproval,pop=population,a=kind,b=sector,c=kingdom,d=cost,e=money,f=ores/teacher,g=wood/doctor,h=stone/guard,i=raw_food/criminal,j=products,k=gear,l=steel,m=paper,n=chemicals,o=food,p=worker,q=farmworker,r=extractivist,s=shopkeeper,t=troops,u=troopsnum,t2=tech_gen,wc=wood_cost,stone_c=stone_cost,steel_c=steel_cost;
Buildings FruitFarm1(0, 1.0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, 2, 0, "Small animal farm"), AnimalFarm1(0, 1.0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, 2, 0, "Small fruit farm");

vector<vector<King>> kings = {{KingArthur,Gilgamesh,MilitaryGenius}, {GodEmperor,ChosenOne,FalseFalconOfLight}, {NamelessGodOfEvil,VampireLord,ReincarnatedDemonKing}, {WorldEater,PerfectBeing,KingOverHeaven}, {MonarchOfIllusions,KingOfShadows,StrongestSorcerer}, {SithLord,Android}, {IA,GhoulEmperor,ManInTheSuit,PerfectHomunculus}};

vector<vector<Champions>> commanders = {{MiyamotoMusashi,Spartacus}, {JonathanJoestar,FatherMozgus}, {PyramidHead}, {Indra}, {Miraak}, {Ghostrunner}, {Hunter}};

vector<vector<Troops>> soldier= {{Knight_1,Archer_1,Shielder_1,Horse_1}, {Cleric_1,HolyArcher_1,Paladin_1,Falcon_1}, {Goblin_1,RangedGoblin_1,Slime_1,Bat_1}, {Believer_1,ArcherBeliever_1,Penitent_1,ElementalSpirit_1}, {Summon_1,Mage_1,Caster_1,WolfSummon_1}, {Droid_1, RangedDroid_1,Barrier_1,Drone_1}, {Parasite_1,Bacteria_1,Flesh_1,ZombieWolf_1}};

vector<vector<Buildings>> constructions = {{FruitFarm1, AnimalFarm1}, {FruitFarm1, AnimalFarm1}};

vector<Civilization> botCivilizations;
vector<BotIA> NPCs;

// Funcoes relativas ao gerenciamento da cidade
//a=kind,b=king;c=dist_x;d=dist_y
Civilization::Civilization(int a, int b, int c, int d)
{
	kind = a;
	king = b;
	dist_x = c;
	dist_y = d;
	alignment = kings.at(a).at(b).alignment;
}
void Civilization::changeAlignment(int x)
{
	alignment += x;
}
void Civilization::changeXp(int x)
{
	xp += x;
}
void Civilization::changeMoral(int x)
{
	xp += x;
}
void Civilization::setTroops(int x, int n)
{
	int size = troops.size();
	int pos = size;
	for (int i = 0; i < size; i++)
	{
		if (troops.at(i) == x)
		{
			pos = i;
			break;
		}
	}
	if (pos <= size)
	{
		troops_num.at(pos) = troops_num.at(pos) + n;
	}
	else
	{
		troops.push_back(x);
		troops_num.push_back(n);
	}
}
void Civilization::setKind(int x)
{
	kind = x;
}
void Civilization::setKing(int x)
{
	king = x;
}

void Civilization::buildingsMonthlyUpdates()
{
	int size = buildings.size();
	for (int i = 0; i > size; i++)
	{
		buildings.at(i).monthlyUpdate(*this);
	}
}

void Civilization::championsMonthlyUpdates()
{
	int size = champions.size();
	for (int i = 0; i > size; i++)
	{
		champions.at(i).monthlyUpdate(*this);
	}
}

void Civilization::civilWar(){
	
}

void Civilization::monthlyUpdates(){
	int storage1, storage2;
	buildingsMonthlyUpdates();
	championsMonthlyUpdates();
	if((food-population) < 0){
		storage1 = population-food;
		food = 0;
		if((raw_food-storage1) < 0){
			storage2 = population-raw_food;
			raw_food = 0;
			population -= storage2/2;
			aproval -= aproval/(population/storage2);
		}else{
			raw_food -= storage1;
		}
	}else{
		food -= population;
	}
	if(education <= 0) education=0.1;
	if(aproval <= 0) aproval=1;
	storage1 = criminal;
	criminal = (population-(population*education))/aproval;
	population -= (criminal-storage1);
	if(aproval<=10) civil_war_chance+=5+((10-aproval)*10);
	if(aproval>=70) civil_war_chance-=10;
	if(civil_war_chance>0) civil_war_chance=0;
	if(civil_war_chance>=100){
		civilWar();
	}
	storage1 = kings.at(kind).at(king).lvl;
	moral += storage1/10;
}

void Civilization::defineEmperor(){
	Emperor = new King(0,0,0,0,0,0,0,"0");
	*Emperor = kings.at(kind).at(king);
}
void Civilization::exploreDirection(int a){
    if(a == 1){
        explored_n += 250;
    }else if(a == 2){
        explored_s += 250;
    }else if(a == 3){
        explored_e += 250;
    }else if(a == 4){
        explored_w += 250;
    }
}
void Civilization::addNationKnown(){
    
}


// Funcoes relativas ao gerenciamento de reis
//a=kingdom,b=age,c=max_age,d=hp,e=dmg,f=alignment,g=troop_capacity,h=name;
King::King(int a, int b, int c, int d, int e, int f, int g, string h){
	name = h;
	kingdom = a;
	age = b;
	max_age = c;
	hp = d;
	dmg = e;
	alignment = f;
	troop_capacity = g;
}



// Funcoes relativas ao gerenciamento de comandantes
// a=kingdom,b=capacity,c=loyalty,d=xp,e=dmg,f=hp,g=archery_boost,h=melee_boost,i=defender_boost,j=beast_boost,k=dmg_boost,l=hp_boost,m=foodcost_boost,n=moral_boost, o=alignment, p=name;
Champions::Champions(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o,string p)
{
	name = p;
	kingdom = a;
	capacity = b;
	loyalty = c;
	xp = d;
	dmg = e;
	hp = f;
	archery_boost = g;
	melee_boost = h;
	defender_boost = i;
	beast_boost = j;
	dmg_boost = k;
	hp_boost = l;
	foodcost_boost = j;
	moral_boost = n;
	alignment = o;
}
void Champions::changeXp(int x)
{
	xp += x;
}
void Champions::raid(Civilization Obj1){
	
}
void Champions::monthlyUpdate(Civilization Obj1)
{
	lvl = (xp / 100) + 1;
	hp = hp * lvl;
	dmg = dmg * lvl;
	if(((Obj1.alignment+30 < alignment) and (alignment > 50)) or ((Obj1.alignment-30 > alignment) and (alignment < 50))){
		raid_chance += 100-loyalty;
	}
	if(raid_chance >= 100){
		raid(Obj1);
	}
}



// Funcoes relativas ao gerenciamento de tropas
// a=kingdom,b=kind,c=ranged,d=food_cost_per_month,e=dmg,f=hp,g=size,h=name
Troops::Troops(int a, int b, int c, int d, int e, int f,int g, string h)
{
	kingdom = a;
	kind = b;
	ranged = c;
	food_cost_per_month = d;
	dmg = e;
	hp = f;
	size = g;
	name = h;
}



//Funcoes relativas ao gerenciamento de exercitos
Army::Army(Champions leader, int leader_row, int moral, Troops row1, int row1_qnt, Troops row2, int row2_qnt, Troops row3, int row3_qnt){
	float moral_inc = (moral/100)*(leader.moral_boost/100);
	float boost_array[5];
	boost_array[0] = 1.0;
	boost_array[1] = leader.melee_boost/100;
	boost_array[2] = leader.archery_boost/100;
	boost_array[3] = leader.defender_boost/100; 
	boost_array[4] = leader.beast_boost/100;
	
	row1_hp = row1.hp*row1_qnt*boost_array[row1.kind];
	row1_dmg = row1.dmg*row1_qnt*moral_inc*boost_array[row1.kind];
	row1_ranged = row1.ranged;
	
	row2_hp = row2.hp*row2_qnt*boost_array[row2.kind];
	row2_dmg = row2.dmg*row2_qnt*moral_inc*boost_array[row2.kind];
	row2_ranged = row2.ranged;
	
	row3_hp = row3.hp*row3_qnt*boost_array[row3.kind];
	row3_dmg =row3.dmg*row3_qnt*moral_inc*boost_array[row3.kind];
	row3_ranged = row3.ranged;
	
	food_cost = ((row1.food_cost_per_month*row1_qnt)+(row2.food_cost_per_month*row2_qnt)+(row3.food_cost_per_month*row3_qnt))*leader.foodcost_boost;
}



// Funcoes relativas ao gerenciamento de construcoes
// t1=tech_req,ap=aproval,pop=population,a=kind,b=sector,c=kingdom,d=cost,e=money,f=ores/teacher,g=wood/doctor,h=stone/guard,i=raw_food/criminal,j=products,k=gear,l=steel,m=paper,n=chemicals,o=food,p=worker,q=farmworker,r=extractivist,s=shopkeeper,t=troops,u=troopsnum,t2=tech_gen,wc=wood_cost,stone_c=stone_cost,steel_c=steel_cost;
// Setor 1: Estruturas relacionadas ao consumo ou producao de material.
// Setor 2: Outras estruturas (hospitais, escolas, etc).
Buildings::Buildings(int t1, float ap, int pop, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int t2, int wc, int stone_c, int steel_c, string nm)
{
	name = nm;
	tech_req = t1;
	aproval = ap;
	population = pop;
	kind = a;
	sector = b;
	kingdom = c;
	cost = d;
	wood_cost = wc;
	stone_cost = stone_c;
	steel_cost = steel_c;
	money = e;
	gear = k;
	steel = l;
	paper = m;
	chemicals = n;
	food = o;
	worker = p;
	farmworker = q;
	extractivist = r;
	shopkeeper = s;
	troops = t;
	troops_num = u;
	tech_gen = t2;
	if (b == 1)
	{
		ores = f;
		wood = g;
		stone = h;
		raw_food = i;
		products = j;
	}
	else
	{
		teacher = f;
		doctor = g;
		guard = h;
		criminal = i;
		education = j;
	}
}

void Buildings::buildConstruction(Civilization &Obj)
{
	Obj.money -= cost;
	Obj.wood -= wood_cost;
	Obj.stone -= stone_cost;
	Obj.steel -= steel_cost;
	Obj.aproval = Obj.aproval * aproval;
	Obj.worker = worker;
	Obj.farmworker = farmworker;
	Obj.extractivist = extractivist;
	Obj.shopkeeper = shopkeeper;
	Obj.worker = worker;
	Obj.farmworker = farmworker;
	Obj.extractivist = extractivist;
	Obj.shopkeeper = shopkeeper;
	Obj.guard = guard;
	position = Obj.buildings.size();
	Obj.buildings.push_back(*this);
}
void Buildings::monthlyUpdate(Civilization &Obj)
{
	int storage;
	durability -= 0.008;
	Obj.tech_lvl += tech_gen * durability;
	Obj.money += money * durability;
	Obj.gear += gear * durability;
	Obj.steel += steel * durability;
	Obj.paper += paper * durability;
	Obj.chemicals += chemicals * durability;
	Obj.food += food * durability;
	Obj.ores += ores * durability;
	Obj.wood += wood * durability;
	Obj.stone += stone * durability;
	Obj.raw_food += raw_food * durability;
	Obj.setTroops(troops, troops_num);
	if(criminal!=0){
		storage = criminal;
		if(criminal > Obj.population) storage=Obj.population;
		Obj.criminal += storage;
		Obj.population -= storage;
	}
}



// Funcoes relativas ao gerenciamento de NPCs
BotIA::BotIA(){
    // BotCivilizations = Obj1;
    // BotKing = Obj2;
}

// Funcoes relativas ao andamento do jogo

Civilization PlayerKingdom(0, 0, 0, 0);

int beginGame()
{
	cout << end_of_page;
	cout << "Choose how do you want to proceed:\n1 - New game.\n2 - Load game.\nYour choice: ";
	cin >> input1;
	if(input1 == "1"){
		return 1;
	}else if(input1 == "2"){
		return 2;
	}else{
		cout << "No option selected, select again.\n";
		return beginGame();
	}
}

void startNewPlayer(){
    while(!difficulty){
		cout << end_of_page;
		cout << "Select a difficulty:\n1 - Easy: All kingdoms start at lvl 1.\n2 - Normal: Some kingdoms are already developed.\n3 - Hard: All kingdoms are already stablished.\nYour choice: ";
		cin >> input1;
		if(input1 == "1") difficulty = 1;
		else if(input1 == "2") difficulty = 2;
		else if(input1 == "3") difficulty = 3;
		else cout << "No option selected, select again.\n";
	}
	while(!style){
		cout << end_of_page;
		cout << "This game contains unrealistic elements like magic and mythical creatures, do you want to disable this elements?\n1 - Unable fantasy elements.\n2 - Keep fantasy elements.\nYour choice: ";
		cin >> input1;
		if(input1 == "1") style = 1;
		else if(input1 == "2") style =2;
		else cout << "No option selected, select again.\n";
	}
	
	while(PlayerKingdom.emperor_name == ""){
		cout << end_of_page;
		cout << "Digit the name of your character: ";
		cin >> input1;
		cout << "Are you sure your character's name is: '" << input1 << "' ?\n1 - Yes.\n2 - No.\nYour choice: ";
		cin >> input2;
		if(input2=="1"){
			PlayerKingdom.emperor_name = input1; 
		}
	}
	while(PlayerKingdom.civilization_name == ""){
		cout << end_of_page;
		cout << "Digit the name of your empire: ";
		cin >> input1;
		cout << "Are you sure the your empire's name is: '" << input1 << "' ?\n1 - Yes.\n2 - No.\nYour choice: ";
		cin >> input2;
		if(input2=="1"){
			PlayerKingdom.civilization_name = input1;
		}
	}
	int king_selected = 100;
	int kind_selected;
	int inputnumber;
	if (style == 2){
		while(king_selected == 100){
			cout << end_of_page;
			cout << "Choose a civilization kind:\n0 - Human\n1 - Holy\n2 - Evil\n3 - Deity\n4 - Witchcraft\n5 - Technology\n6 - Biotechnology\nChoose one to see the types of king you can select: ";
			while(!(cin >> kind_selected)){
				cout << "No option selected, choose again.\n";
				cout << end_of_page;
		    	cout << "Choose a civilization kind:\n0 - Human\n1 - Holy\n2 - Evil\n3 - Deity\n4 - Witchcraft\n5 - Technology\n6 - Biotechnology\nChoose one to see the types of king you can select: ";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if((kind_selected>=0) and (kind_selected<=6)){
			    vector<King> kingdom_kind = kings.at(kind_selected);
			    int size = kingdom_kind.size();
			    cout << "Available title options available for this kind of kingdom:\n";
			    for(int i = 0; i < size; i++){
			        King king_kind = kingdom_kind.at(i);
			        cout << "\n Title number " << i << ": ";
			        cout << "Name: " << king_kind.name;
			        cout << " - Alignment: " << king_kind.alignment;
			        cout << " - Troop capacity when fighting: " << king_kind.troop_capacity;
			        cout << " - Stats(*lvl): HP: " << king_kind.hp << " DMG: " << king_kind.dmg;
			    }
			    cout << "\nSelect the title number (anything other than the number to exit to civilization selection)\nYour choice: ";
			    if(cin >> inputnumber){
			        if((inputnumber >= 0) and (inputnumber < size)){
			            king_selected = inputnumber;
			            PlayerKingdom.king = king_selected;
			            PlayerKingdom.kind = kind_selected;
			            PlayerKingdom.defineEmperor();
			        }
			    }else{
			        cin.clear();
				    cin.ignore(10000, '\n');
			    }
			}else{
				cout << "No option selected, choose again.\n";
			}
		}
	}
}

void generateOtherCivilizations(){
    int count = 0;
    int size1 = kings.size(); // Quantidade de estilos de civilizacao
    int possible_kinds[7][4];
    for(int i1 = 0; i1 < size1; i1++){
        int size2 = kings.at(i1).size();
        for(int i2 = 0; i2 < size2; i2++){
            possible_kinds[i1][i2] = 1;
        }
    }
    possible_kinds[PlayerKingdom.kind][PlayerKingdom.king] = 0;
    for(int i1 = 0; i1 < size1; i1++){
        int size2 = kings.at(i1).size();
        for(int i2 = 0; i2 < size2; i2++){
            count++;
            if(possible_kinds[i1][i2] != 1){
                continue;
            }
            if(difficulty == 1){
                int x = (rand() % 10000)-5000;
                while(x == 0){
                    int x = (rand() % 10000)-5000;
                }
                int y = (rand() % 3000)-1500;
                Civilization KingdomNPC(i1,i2,x, y);
                KingdomNPC.defineEmperor();
                botCivilizations.push_back(KingdomNPC);
                cout << x << " | " << y << "\n";
            }
        }
    }
}

void startNPCS(){
    
}

void newGame()
{
	startNewPlayer();
	generateOtherCivilizations();
}

void loadGame()
{
    
}

void playerTurn()
{
}
