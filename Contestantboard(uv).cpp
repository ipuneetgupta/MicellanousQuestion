#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define f(s,e,i) for(int i=s;i<=e;i++)
// 100 person max
class person{
public:
	int p_id;
 	int Solve_Prb;  //total no of problem solved right now
 	int prblm[10]; //no of problem  --0,1
 	int Prblm_penality[10];
    int total_Ptime;//total time right now it take to solved a problema and incorrect problem

    person(int id){
    	this->p_id=id;
    	Solve_Prb=0;
    	f(0,10,i) this->Prblm_penality[i]=0;
    	f(0,10,i) this->prblm[i]=0;
    	total_Ptime=0;
    }
};
//Now judge our person 
void judge(person &p,int Ith_prblm,int T_taken,char L){
	if(L=='C'){
		p.prblm[Ith_prblm]=1;
		p.Prblm_penality[Ith_prblm]+=T_taken;
		p.Solve_Prb+=1;
	}else if( L=='I'){
		p.Prblm_penality[Ith_prblm]+=20;
	}else{

	}
}
//Calculate total time
void Calc_Time(vector<person> &persons){
	for (vector<person>:: iterator it=persons.begin();it!=persons.end();it++){
        for(int i=1;i<10;i++){
        	(*it).total_Ptime+=(*it).Prblm_penality[i];
        }
	}
}
//Compare function
bool compare(person &p1,person &p2){
   //first if p1 problem number
	if(p1.Solve_Prb<p2.Solve_Prb) return false;
	else if(p1.Solve_Prb==p2.Solve_Prb&&p1.total_Ptime<p2.total_Ptime) return false;
	else if(p1.p_id<p2.p_id) return false;

	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
			int index[101];       //store the person  indexes or person id
			f(0,101,i) index[i]=-1;
            vector<person> persons;       //store all person

 		//getline(cin,str);
             string str;
             cin.ignore();
            while(getline(cin,str)){
            	if(str=="") break;
            	istringstream ss(str);
            	int p_id,Ith_prblm,T_taken;
            	char L;
            	ss>>p_id>>Ith_prblm>>T_taken>>L;
               //  cout<<p_id<<Ith_prblm<<T_taken<<L;
            	person p(p_id);
            if(index[p_id]==-1){ //it means the person first time take part in this contestant
               //1 first thing make object of person and add in our contestant list
            	persons.push_back(p);
               //2 Now fill index of person by their p_id
            	index[p_id]=persons.size()-1;
               //3 Now judge our problem
            	judge(persons[index[p_id]],Ith_prblm,T_taken,L);
                  // cout<<persons[index[p_id]].Prblm_penality[Ith_prblm]<<endl;
            }

            else if(persons[index[p_id]].prblm[Ith_prblm]==0){   
                                    //person already take part in this contestant
            	judge(persons[index[p_id]],Ith_prblm,T_taken,L);

            }
        }
        Calc_Time(persons);
        sort(persons.begin(),persons.end(),compare);
        for(vector<person> :: iterator it=persons.begin();it!=persons.end();it++){
        	cout<<(*it).p_id<<" "<<(*it).Solve_Prb<<" "<<(*it).total_Ptime<<" "<<endl;
        }
        cout<<endl;
    }
}

// 1
// 1 2 10 I
// 1 2 21 C
// 1 1 25 C
// 3 1 11 C