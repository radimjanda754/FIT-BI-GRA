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
int EndCounter;
struct THrana{
	THrana(int f,int t,int s)
	{
		From=f;
		To=t;
		size=s;
	};
	int From;
	int To;
	int size;
};

inline bool operator<(const THrana& lhs, const THrana& rhs)
{
  return lhs.size < rhs.size;
}

bool Union (map<int,vector<int> > &GroupsMap,int * groups,int A,int B)
{
	int AGroup=groups[A];
	int BGroup=groups[B];
	if(AGroup==BGroup)
		return 0;
	if(GroupsMap[AGroup].size()>GroupsMap[BGroup].size())
	{
		while(!GroupsMap[BGroup].empty())
		{
			int tmp=GroupsMap[BGroup].back();
			GroupsMap[BGroup].pop_back();
			GroupsMap[AGroup].push_back(tmp);
			groups[tmp]=AGroup;
		}
	}
	else
	{
		while(!GroupsMap[AGroup].empty())
		{
			int tmp=GroupsMap[AGroup].back();
			GroupsMap[AGroup].pop_back();
			GroupsMap[BGroup].push_back(tmp);
			groups[tmp]=BGroup;
		}
	}
	EndCounter++;
	return 1;
}

void cd( const char * inFile, const char * outFile )
 {
	EndCounter=0;
	FILE * fread=fopen(inFile,"rb");
	FILE * fwrite=fopen(outFile,"wb");
	int H;
	int U;
	int TotalSize=0;
	fscanf(fread,"%d %d",&U,&H);
	set<pair<int,int> > UseThis;
	map<int,set<int> > output;
	set<THrana> Hrany;
	map<int,vector<int> > GroupsMap;
	int * groups=(int*)malloc(sizeof(int)*U);
	for(int i=0;i<U;i++)
	{
		GroupsMap[i].push_back(i);
		groups[i]=i;
	}
	char end;
	int from;
	int to;
	int siz;
	while(fscanf(fread,"%d %d%c",&from,&to,&end))
	{
		//printf("%d %d\n",from,to);
		pair<int,int> tmp(from,to);
		UseThis.insert(tmp);
		Union(GroupsMap,groups,from,to);
		/*for(int i=0;i<U;i++)
			printf("%d-%d ",i,groups[i]);
		printf("\n");*/
		if(end!=',')
			break;
	}
	for(int i=0;i<H;i++)
	{
		fscanf(fread,"%d %d %d",&from,&to,&siz);
		//printf("%d %d %d\n",from,to,siz);
		pair<int,int> tmp(from,to);
		set<pair<int,int> >::iterator it=UseThis.find(tmp);
		if(it==UseThis.end())
			Hrany.insert(THrana(from,to,siz));
		else
		{
			output[from].insert(to);
			output[to].insert(from);
			TotalSize+=siz;
			UseThis.erase(it);
		}
	}
	while(Hrany.size()>0)
	{
		set<THrana>::iterator it=Hrany.begin();
		if(Union(GroupsMap,groups,it->From,it->To))
		{
			output[it->From].insert(it->To);
			output[it->To].insert(it->From);
			TotalSize+=it->size;
		}
		Hrany.erase(it);
	}
	fprintf(fwrite,"%d\n",TotalSize);
	for(int i=0;i<U;i++)
	{
		fprintf(fwrite,"%d ",i);
		for(set<int>::iterator it=output[i].begin();it!=output[i].end();++it)
		{
			if((++it)==output[i].end())
				fprintf(fwrite,"%d",*(--it));
			else
				fprintf(fwrite,"%d ",*(--it));
		}		
		fprintf(fwrite,"\n");
		if(EndCounter==U)
			break;
	}
	fclose(fread);
	fclose(fwrite);
 }


#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
 {
	cd("input","output");
	return 0;
 }
#endif /* __PROGTEST__ */
