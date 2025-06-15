#ifndef RTS_FUNCTIONS_H
#define RTS_FUNCTIONS_H

void initCivilizations();
int beginGame();
void newGame();
void loadGame();
void playerTurn();

//a=kingdom,b=age,c=max_age,d=hp,e=dmg,f=alignment,g=troop_cacapity,h=name;
King KingArthur(0,20,90,300,300,75,10000,"The Prophesied King"), Gilgamesh(0,20,130,500,500,50,0,"The King of All that Exists");
King GodEmperor(1,30,500,300,300,50,10000,"The God Emperor of Humanity"), ChosenOne(1,16,70,500,500,100,1000,"The Chosen One"), FalseFalconOfLight(1,20,80,100,100,0,100,"The False Falcon of Light");
King NamelessGodOfEvil(2,7000,50000,100,100,0,0,"The Nameless God Of Evil"), VampireLord(2,120,10000,500,500,0,10000,"The Vampire Lord"), ReincarnatedDemonKing(2,10,1200,500,500,50,10000,"The Reincarnated Demon King");
King WorldEater(3,7000,50000,1000,1000,0,0,"The World Eater"), PerfectBeing(3,4000,50000,500,500,0,10000,"The Perfect Being");
King MonarchOfIllusions(4,3000,10000,1000,100,0,10,"The Monarch of Illusions"), KingOfShadows(4,20,600,500,500,50,1000,"The King of Shadows"), StrongestSorcerer(4,30,90,750,750,50,0,"The Strongest Sorcerer");
King SithLord(5,80,1000,200,200,0,0,"The Sith Lord"), Android(5,1,100,200,200,50,10000,"The Android");
King IA(6,1,2000,100,100,50,0,"The IA"), GhoulEmperor(6,20,100,500,500,50,10000,"The Ghoul Emperor"), ManInTheSuit(6,40,200,100,100,0,0,"TheManInTheSuit");

// a=kingdom,b=kind,c=ranged,d=food_cost_per_month,e=dmg,f=hp,g=size,h=name
Troops Knight_1(0,1,0,1,10,10,2,"Training knight"), Cleric_1(1,1,0,1,8,12,2, "Cleric student");
Troops Archer_1(0,2,1,1,5,5,2,"Training archer"), HolyArcher_1(1,2,1,1,7,3,2,"Training holy archer");
Troops Shielder_1(0,3,0,2,5,18,3,"Weak shielder"), Paladin_1(1,3,0,2,3,23,3,"Paladin's disciple");
Troops Horse1(0,4,0,3,10,18,5,"Horse mounted training knight"), Falcon1(1,4,1,1,5,5,1,"Falcon");

// a=kingdom,b=capacity,c=loyalty,d=xp,e=dmg,f=hp,g=archery_boost,h=melee_boost,i=defender_boost,j=beast_boost,k=dmg_boost,l=hp_boost,m=foodcost_boost,n=moral_boost,o=alignment, p=name;
Champions MiyamotoMusashi(0,30,90,0,100,100,120,120,100,80,120,95,80,150,50,"Miyamoto Musashi"), Spartacus(0,12000,90,0,150,200,90,105,105,90,100,100,70,130,50,"Spartacus");
Champions JonathanJoestar(1,10,100,0,200,200,110,150,150,150,150,200,100,200,100,"Jonathan Joestar");

// t1=tech_req,ap=aproval,pop=population,a=kind,b=sector,c=kingdom,d=cost,e=money,f=ores/teacher,g=wood/doctor,h=stone/guard,i=raw_food/criminal,j=products,k=gear,l=steel,m=paper,n=chemicals,o=food,p=worker,q=farmworker,r=extractivist,s=shopkeeper,t=troops,u=troopsnum,t2=tech_gen,wc=wood_cost,stone_c=stone_cost,steel_c=steel_cost;
Buildings FruitFarm1(0, 1.0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, 2, 0, "Small animal farm"), AnimalFarm1(0, 1.0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, 2, 0, "Small fruit farm");

#endif