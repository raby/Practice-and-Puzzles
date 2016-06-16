#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "level.h"

using namespace std;

/*
Initech is a company which has CEO Bill and a hierarchy of employees. Employees can have a list of other employees reporting to them, which can themselves have reports, and so on. An employee with at least one report is called a manager. 

Please implement the closestCommonManager method to find the closest manager (i.e. farthest from the CEO) to two employees. You may assume that all employees eventually report up to the CEO. 

Tree structure: 
Bill -> Dom, Samir, Michael 
Dom -> Bob, Peter, Porter 
Peter -> Milton, Nina 

Sample Data: 
CEO Bill has 3 employees reporting to him: {Dom, Samir, Michael} 
Dom has three reports { Peter, Bob, Porter} 
Samir has no reports {} 
Michael has no reports {} 
Peter has 2 reports {Milton, Nina} 
Bob has no reports {} 
Porter has no reports {} 
Milton has no reports {} 
Nina has no reports {} 

Sample calls: 
closestCommonManager(Milton, Nina) = Peter 
closestCommonManager(Nina, Porter) = Dom 
closestCommonManager(Nina, Samir) = Bill 
closestCommonManager(Peter, Nina) = Peter
*/

class level
{
	public:
		struct node
		{
			string Name;
			level* Down;
			node(string Name_):Name(Name_),Down(NULL){};
		};

		string Boss;
		int Depth;
		vector<node*> Sub;
		
		level(string Boss_, vector<node*> sub_,int d_):Boss(Boss_),Sub(sub_),Depth(d_){};

		vector<node*> insertNode(string IDone, string IDtwo, string IDthree)
		{
			vector<node*> Sub(3);
			Sub[0] = new node(IDone);
			Sub[1] = new node(IDtwo);
			Sub[2] = new node(IDthree);
			return Sub;
		}
};

class Hierarchy
{
	private:

		/*
		level* findEmployee(level* t,string Boss_)
		{
			for(int i=0;i<3;i++)
			{
				if(t!=NULL && t->Sub[i]->Name.compare(Boss_)==0)
					if(t->Sub[i]->Down==NULL)
					{
						return t;
						break;
					}
					else 
						cout<<"ERROR: This employee is already a manager";
				if(t->Sub[i]->Down)
					findEmployee(t->Sub[i]->Down,Boss_);
			}
		}
		*/
		
		void printEmployeeChart(level* t)
		{	
			cout<<"DEPTH: "<<t->Depth<<"   "<<t->Boss<<" -> [ ";
			for(int i=0; i<3; i++)
				cout<<t->Sub[i]->Name<<" ";
			cout<<"]"<< endl ;
			

			for(int i=0; i<3; i++)
			{
				if(t->Sub[i]->Down)
					printEmployeeChart(t->Sub[i]->Down);
			}

		}


		level* root;
	public:
		Hierarchy()
		{
			root = NULL;
		}

		void insertCEO(string Boss_, string IDone, string IDtwo, string IDthree)
		{
			if(root==NULL)
				root = new level(Boss_, root->insertNode(IDone,IDtwo,IDthree), 1);
			else
				cout<<"ERROR: CEO already declared.";
		}
		
		void printEmployeeChart()
		{
			printEmployeeChart(root);
		}

		void insertLevel(string Boss_, string IDone, string IDtwo, string IDthree,level* t)
		{
			for(int i=0;i<3;i++)
				if(t->Sub[i]->Down)
					insertLevel(Boss_,IDone,IDtwo,IDthree,t->Sub[i]->Down);
			for(int i=0;i<3;i++)
			{
				if(t->Sub[i]->Name.compare(Boss_)==0)
					if(t->Sub[i]->Down==NULL)
					{
						t->Sub[i]->Down = new level(Boss_,t->insertNode(IDone,IDtwo,IDthree),(t->Depth+1));
						break;
					}
					else 
						cout<<"ERROR: This employee is already a manager";
			}
		}
		void insertLevel(string Boss_, string IDone, string IDtwo, string IDthree)
		{
			insertLevel(Boss_,IDone,IDtwo,IDthree,root);
		}

		void findEmployee(string ID, level* t, stack<level*> &s,string &Boss)
		{
			s.push(t);
			for(int i=0;i<3;i++)
			{
				if(t->Sub[i]->Name.compare(ID)==0)
				{
					Boss = t->Boss; 
					return;
				}
				if(t->Sub[i]->Down)
					findEmployee(ID,t->Sub[i]->Down,s,Boss);
			}
			if(s.top()->Boss.compare(Boss)!=0)
				s.pop();
		}

		string closestCommonManager(string IDone,string IDtwo)
		{
			stack<level*> s1;
			stack<level*> s2;
			string Boss = "";
			findEmployee(IDone,root,s1,Boss);
			Boss = "";
			findEmployee(IDtwo,root,s2,Boss);
			
			while(s1.size()!=s2.size())
			{
				
				if( (s1.size()==(s2.size()+1)) && s1.top()->Boss==IDtwo )
					return IDtwo;
				else if( (s1.size()+1)==s2.size() && s2.top()->Boss==IDone )
					return IDone;

				if(s1.size()>s2.size())
					s1.pop();
				else if(s2.size()>s1.size())
					s2.pop();
			}
			while(s1.top()->Boss!=s2.top()->Boss)
			{
				s1.pop();
				s2.pop();
			}
			
			return s1.top()->Boss;
		}
};


int main()
{
	Hierarchy h;
	
	h.insertCEO("Mark","Alan","Jeff","Jacob");
	h.insertLevel("Alan","Ryan","Josh","Jon");
	h.insertLevel("Jeff","Cody","Cameron","Kyle");
	h.insertLevel("Kyle","Kevin","Christian","Dan");
	h.insertLevel("Dan","Derk","Dylan","Jordon");
	h.insertLevel("Dylan","Becca","Bobbi","Brit");
	h.insertLevel("Ryan","Sam","Charlie","Lisa");

	h.printEmployeeChart();
	
	cout<<endl;

	//Case 1: Both ID share the same the boss;
	cout<<h.closestCommonManager("Ryan","Josh")<<endl; //expect Alan
	//Case 2: Same level one ID is The boss;
	cout<<h.closestCommonManager("Becca","Dylan")<<endl; //expect Dylan
	//Case 3: One ID is deeper than other, both IDs follow along the same branch, neither are bosses.
	cout<<h.closestCommonManager("Cody","Kevin")<<endl; //expect jeff
	//Case 4: One ID is deeper than other, both IDs follow along the same branch, one is a boss.
	cout<<h.closestCommonManager("Kevin","Dylan")<<endl; //expect kyle
	//Case 5: IDs follow different branches.
	cout<<h.closestCommonManager("Ryan","Cody")<<endl; //expect mark
	cout<<h.closestCommonManager("Kyle","Dylan")<<endl;

	
	system("pause");
}