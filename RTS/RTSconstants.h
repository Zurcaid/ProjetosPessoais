#ifndef RTS_CONSTANTS_H
#define RTS_CONSTANTS_H

#include <iostream>
#include <vector>
using namespace std;

class Buildings;
class Troops;
class Champions;
class King;
class Army;

class Civilization
{
  public:
	// Caracteristicas gerais
	int alignment; // Varia de 0 a 100
	int xp = 0;	   // 1 lvl = 100 xp
	int lvl;
	int tech_lvl = 0;
	int kind, king;
	int dist_x, dist_y;
	King* Emperor;
	string emperor_name, civilization_name;
	// Kinds of kingdom: 0=Medieval,1=Light, 2=Darkness, 3=Deity, 4=Sorcerer, 5=Tech, 6=Biotech
	string name;

	// Recursos
	int money = 0;
	int ores, wood, stone, raw_food;		 // Primarios
	int gear, steel, paper, chemicals, food; // Secundarios

	// Construcoes
	vector<Buildings> buildings;
	int city_dur = 100;

	// Populacao
	int population = 10;
	int doctor, teacher, farmworker, shopkeeper, worker, extractivist, guard, criminal; // Empregos
	int aproval = 50;
	int civil_war_chance = 0;
	float growing_rate = 0.0;
	float education = 0.1;
	int war_prisoners;
	vector<Champions> important_prisoners;

	// Relacoes diplomaticas
	vector<string> nations_known;
	vector<int> nk_relationship;
	vector<int> pacts;
	int trade_balance;
	int explored_n, explored_s, explored_e, explored_w;

	int moral = 80;

	vector<Champions> champions;
	vector<vector<Army>> armys; // Exercitos
	
	vector<int> troops; // Tropas no pais
	vector<int> troops_num; // Quantidade de cada tropa

    //a=kind,b=king;c=dist_x;d=dist_y
	Civilization(int a, int b, int c, int d);

	void changeAlignment(int x);
	void defineEmperor();
	void changeXp(int x);
	void changeMoral(int x);
	void setTroops(int x, int n);
	void setKind(int x);
	void setKing(int x);
	void buildingsMonthlyUpdates();
	void championsMonthlyUpdates();
	void monthlyUpdates();
	void civilWar();
	void exploreDirection(int a);
	void addNationKnown();
};

class King
{
  public:
	string name;
	int xp;
	int lvl;
	int kingdom;
	int age, max_age;
	int alignment, troop_capacity;
	int hp = 10;
	int dmg = 10;
	//a=kingdom,b=age,c=max_age,d=hp,e=dmg, f=alignment,g=troop_capacity,h=name;
	King(int a, int b, int c, int d, int e,int f, int g, string h);
};

class Champions
{
  public:
	string name;
	int kingdom;
	int capacity;
	int loyalty, alignment;
	int xp;
	int lvl;
	int dmg, hp;
	int raid_chance;

	int archery_boost, melee_boost, defender_boost, beast_boost;
	int dmg_boost, hp_boost, foodcost_boost, moral_boost;
	// a=kingdom,b=capacity,c=loyalty,d=xp,e=dmg,f=hp,g=archery_boost,h=melee_boost,i=defender_boost,j=beast_boost,k=dmg_boost,l=hp_boost,m=foodcost_boost,n=moral_boost, o=alignment,p=name;
	Champions(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, string p);
	void changeXp(int x);
	void monthlyUpdate(Civilization Obj1);
	void raid(Civilization Obj1);
};

class Troops
{
  public:
	string name;
	int kingdom;
	int dmg, hp;
	int kind; // 1=melee, 2=archer, 3=defender, 4=beast
	int food_cost_per_month, size;
	int ranged;
	// a=kingdom,b=kind,c=ranged,d=food_cost_per_month,e=dmg,f=hp,g=size,h=name
	Troops(int a, int b, int c, int d, int e, int f, int g, string h);
};

class Army
{
  public:
	int champion_hp, champion_dmg, champion_row;
	int row1_hp, row1_dmg, row1_ranged;
	int row2_hp, row2_dmg, row2_ranged;
	int row3_hp, row3_dmg, row3_ranged;
	int front_row = 1;
	int food_cost;
	int kingdom;
	
	Army(Champions leader, int leader_row, int moral, Troops row1, int row1_qnt, Troops row2, int row2_qnt, Troops row3, int row3_qnt);
};

class Buildings
{
  public:
	string name;
	int kind;
	int position;
	int sector;
	int kingdom;
	int cost;
	int wood_cost;
	int stone_cost;
	int steel_cost;
	float durability = 1;
	int money;
	int ores, wood, stone, raw_food;				   // Primarios
	int products, gear, steel, paper, chemicals, food; // Secundarios
	int tech_req;
	float tech_gen;
	int population;
	int doctor, teacher, farmworker, shopkeeper, worker, extractivist, guard, criminal; // Empregos
	float aproval;																		// Varia de 0 a 100
	int education;
	int growing_rate;

	int troops, troops_num;
	// t1=tech_req,ap=aproval,pop=population,a=kind,b=sector,c=kingdom,d=cost,e=money,f=ores/teacher,g=wood/doctor,h=stone/guard,i=raw_food/criminal,j=products/education,k=gear,l=steel,m=paper,n=chemicals,o=food,p=worker,q=farmworker,r=extractivist,s=shopkeeper,t=troops,u=troopsnum,t2=tech_gen;
	// Setor 1: Estruturas relacionadas ao consumo ou producao de material.
	// Setor 2: Outras estruturas (hospitais, escolas, etc).
	Buildings(int t1, float ap, int pop, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int t2, int wc, int stone_c, int steel_c, string nm);

	void buildConstruction(Civilization &Obj);
	void monthlyUpdate(Civilization &Obj);
};

class BotIA
{
    int npc_type;
    
    // Civilization BotCivilization;
    // King BotKing;
    BotIA();
    void BotTurn();
};

#endif
