#include "RTSconstants.h"

using namespace std;

// Funcoes relativas ao gerenciamento da cidade
Civilization::Civilization(int a, int b, int c){
	Civilization::alignment = a;
    Civilization::kind = b;
    Civilization::king = c;
}
void Civilization::changeAlignment(int x){
	alignment += x;
}
void Civilization::changeXp(int x){
	xp += x;
}
void Civilization::changeMoral(int x){
    xp += x;
}
void Civilization::setTroops(string x, int n){
	int size = troops.size();
	int pos = size+1;
	for(int i = 0; i <= size; i++){
		if(troops.at(i) == x){
		pos = i;
		break;
		}
	}
    if(pos <= size){
		troopsNum.at(pos) = troopsNum.at(pos) + n;
	}else{
		troops.push_back(x);
		troopsNum.push_back(n);
	}
}
void Civilization::setKind(int x){
	kind = x;
}
void Civilization::setKing(int x){
	king = x;
}

// Funcoes relativas ao andamento do jogo
// t1=tech_req,ap=aproval,pop=population,a=kind,b=sector,c=kingdom,d=cost,e=money,f=ores/teacher,g=wood/doctor,h=stone/guard,i=raw_food/criminal,j=products,k=gear,l=steel,m=paper,n=chemicals,o=food,p=worker,q=farmworker,r=extractivist,s=shopkeeper,t=troops,u=troopsnum,t2=tech_gen;
// Setor 1: Estruturas relacionadas ao consumo ou producao de material.
// Setor 2: Outras estruturas (hospitais, escolas, etc).
Buildings::Buildings(int t1,int ap,int pop,int a,int b,string c,int d,int e,int g,int h,int i,int j,int k,int l,int m,int n,int o,int p,int q,int r,int s,int t,int u,int t2){
	Buildings.tech_req = t1;
	Buildings.aproval = ap;
	Buildings.population = pop;
	Buildings.kind = a;
	Buildings.sector = b;
	Buildings.kingdom = c;
	Buildings.cost = d;
	Buildings.money = e;
	Buildings.products = j;
	Buildings.gear = k;
	Buildings.steel = l;
	Buildings.paper = m;
	Buildings.chemicals = n;
	Buildings.food = o;
	Buildings.worker = p;
	Buildings.farmworker = q;
	Buildings.extractivist = r;
	Buildings.shopkeeper = s;
	Buildings.troops = t;
	Buildings.troopsnum = u;
	Buildings.tech_gen = t2;
	if(b==1){
		Buildings.ores = f;
		Buildings.wood = g;
		Buildings.stone = h;
		Buildings.raw_food = i;
	}else{
		Buildings.teacher = f;
		Buildings.doctor = g;
		Buildings.guard = h;
		Buildings.criminal = i;
	}
}


void Buildings::buildConstruction(Civilization &obj){
	Civilization.money -= Buildings.cost;
}

Civilization PlayerKingdom(50,0,0);

void initCivilizations(){
	
}

int beginGame(){
	
	return 1;
}

void newGame(){
	
}

void loadGame(){
	
}

void playerTurn(){
	cout << PlayerKingdom.alignment;
}