#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <list>
#include <stdint.h>

using namespace std;
#endif /* __PROGTEST__ */
struct TNode{
	TNode(){state=0;};
	int state;
	int component;
	vector<int> ingoing;
	vector<int> outgoing;
};
TNode * nodes;
int cmpcnt;
vector<int> ds1;

void DFS1(int node)
{
	nodes[node].state=1; //open
	for(vector<int>::iterator it=nodes[node].outgoing.begin();it!=nodes[node].outgoing.end();it++)
		if(!nodes[*it].state)
			DFS1(*it);
	ds1.push_back(node);
	//printf("stack: %d\n",node);
	nodes[node].state=2; //close
}

void DFS2(int node,int & comp)
{
	nodes[node].state=3; //open
	for(vector<int>::iterator it=nodes[node].ingoing.begin();it!=nodes[node].ingoing.end();it++)
		if(nodes[*it].state==2)
			DFS2(*it,comp);
	nodes[node].component=comp;
	//printf("component: %d - %d\n",node,comp);
	nodes[node].state=4; //close	
}


void fit( const char * inFile, const char * outFile )
 {
	int n;
	FILE * fin=fopen(inFile,"rb");
	FILE * fout=fopen(outFile,"wb");
	fscanf(fin,"%d",&n);
	//printf("input: %d\n",n);
	nodes=(TNode*)malloc(sizeof(TNode)*n);
	for(int i=0;i<n;i++)
		nodes[i].state=0;
	int tmp1, tmp2;	
	while(fscanf(fin,"%d %d",&tmp1,&tmp2)!=EOF)
	{
		//printf("input: %d %d\n",tmp1,tmp2);
		nodes[tmp1].outgoing.push_back(tmp2);
		nodes[tmp2].ingoing.push_back(tmp1);
	}
	ds1.clear();
	for(int i=0;i<n;i++)
		if(!nodes[i].state)
			DFS1(i);
	cmpcnt=0;
	while(!ds1.empty())
	{
		int i=ds1.back();
		ds1.pop_back();
		if(nodes[i].state==2)
		{
			cmpcnt++;
			DFS2(i,cmpcnt);			
		}
	}
	for(int i=0;i<n;i++)
	{
		for(vector<int>::iterator it=nodes[i].outgoing.begin();it!=nodes[i].outgoing.end();it++)
			if(nodes[i].component!=nodes[*it].component)
			{
				fprintf(fout,"%d\n",i);
				break;
			}
	}
	fclose(fin);
	fclose(fout);
 }


#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
 {
   fit("input","output");
   return 0;
 }
#endif /* __PROGTEST__ */
