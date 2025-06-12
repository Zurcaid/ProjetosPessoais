#include <iostream>
#include <vector>
using namespace std;

int init_game;
int age;
int input;

class Civilization{
	public:
		int alignment = 0;
		int xp = 0;
		int money = 0;
		int type, king;
		
		vector<string> troops;
		vector<int> troopsNum;
		
		void changeAlignment(int x){
			alignment += x;
		}
		void changeXp(int x){
			xp += x;
		}
		
		void setTroops(string x, int n){
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
		void setType(int x){
			type = x;
		}
		void setKing(int x){
			king = x;
		}
};

Civilization WarKingdom;

class King{
	public:
		int lvl;
		int hp = 10;
		
		void passive1(){
			
		}
		void skill1(){
			
		}
};

class Champions{
	public:
		int kingdom;
		int xp;
		
};

class Troops{
	public:
		int name;
		int kingdom;
		int dmg,hp;
		
};
