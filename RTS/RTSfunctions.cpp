#include "RTSconstants.h"
#include "RTSfunctions.h"

using namespace std;
#include <iostream>
#include <vector>

string input1;

// Funcoes relativas ao gerenciamento da cidade
Civilization::Civilization(int a, int b, int c, int d)
{
	alignment = a;
	kind = b;
	king = c;
	location = d;
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

void Civilization::buildingsMonthlyUpdates(){
	int size = buildings.size();
	for(int i = 0; i > size; i++){
		buildings.at(i).monthlyUpdate(*this);
	}
}

// Funcoes relativas ao gerenciamento de comandantes

// a=kingdom,b=capacity,c=loyalty,d=xp,e=dmg,f=hp,g=archery_boost,h=melee_boost,i=defender_boost,j=beast_boost,k=dmg_boost,l=hp_boost,m=foodcost_boost,n=moral_boost, o=name;
Champions::Champions(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, string o){
	name = o;
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
}
void Champions::changeXp(int x){
	xp += x;
}
void Champions::monthlyUpdate(){
	lvl = (xp/100)+1;
	hp = hp*lvl;
	dmg = dmg*lvl;
}

// Funcoes relativas ao gerenciamento de tropas
// a=kingdom,b=kind,c=ranged,d=food_cost_per_month,e=dmg,f=hp,g=name
Troops::Troops(int a, int b, int c, int d, int e, int f, string g){
	kingdom = a;
	kind = b;
	ranged = c;
	food_cost_per_month = d;
	dmg = e;
	hp = f;
	name = g;
}

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

void Buildings::buildConstruction(Civilization& Obj)
{
	Obj.money -= cost;
	Obj.wood -= wood_cost;
	Obj.stone -= stone_cost;
	Obj.steel -= steel_cost;
	Obj.aproval = Obj.aproval*aproval;
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
void Buildings::monthlyUpdate(Civilization& Obj){
	durability -= 0.008;
	Obj.tech_lvl += tech_gen*durability;
	Obj.money += money*durability;
	Obj.gear += gear*durability;
	Obj.steel += steel*durability;
	Obj.paper += paper*durability;
	Obj.chemicals += chemicals*durability;
	Obj.food += food*durability;
	Obj.ores += ores*durability;
	Obj.wood += wood*durability;
	Obj.stone += stone*durability;
	Obj.raw_food += raw_food*durability;
	Obj.setTroops(troops, troops_num);
}


vector<vector<Buildings>> constructions = {{FruitFarm1,AnimalFarm1},{FruitFarm1,AnimalFarm1}};

Civilization PlayerKingdom(50, 0, 0, 0);


int beginGame()
{
	return 1;
}

void newGame()
{
}

void loadGame()
{
}

void playerTurn()
{
	
}