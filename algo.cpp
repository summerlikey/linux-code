// run code ./CodeCraft-2019 ../config/car.txt ../config/road.txt ../config/cross.txt  ../config/answer.txt
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
using namespace std;
int roadIdtoroad[10001]={0};
int INF=99999999;
int carNum;//total car number
int roadNum;//total road number
int crossNum;//total cross number
int runCross[1000];

//car data
struct carInfo{
//	string line;// read the line by line
	int carId;// car id
	int carFrom;//car from
	int carTo;//car to
	int carHighspeed;//car high speed
	int carPlantime;//car plan time
};
vector<carInfo>car;
//road data
struct roadInfo{
	int roadId;//road id
	int roadLength;//length
	int roadHighspeed;//speed
	int roadChannel;//channel
	int roadFrom;//from
	int roadTo;//to
	int roadIsduplex;//isduplex
};
vector<roadInfo>road;

//cross data
struct crossInfo{
	int crossId;//cross id
	int crossRoadid_1;//roadId
	int crossRoadid_2;//roadId
	int crossRoadid_3;//roadId
	int crossRoadid_4;//roadId
};
vector<crossInfo>cross;
struct crossInfo CROSS[500]={0,0,0,0,0};
struct roadInfo ROAD[10000]={0,0,0,0,0,0,0};
//run road cunchu//car run
struct carRuninfo{
	int a[500];
};
struct carRuninfo carRun[100000];

struct runNote{
        int f;// father note
        int dis;//now the dis from firstcross to last cross
        int crossId;//xiayigecross
        int roadId;
};
int head;
int tail;
int book[100000];

struct runNote runQue[100000];

void runRun(int cFrom,int cTo)
{
	memset(runQue,0,sizeof(struct runNote)*100000);
//struct runNote runQue[100000];
      int r_1=0,r_2=0,r_3=0,r_4=0;
   int f_1=0,f_2=0,f_3=0,f_4=0;
int t_1=0,t_2=0,t_3=0,t_4=0;
   int i=0;
   head=1;
   tail=1;
   for(i=0;i<100000;i++)
	   book[i]=0;
   runQue[tail].f=0;
   runQue[tail].dis=0;
   runQue[tail].crossId=cFrom;
   runQue[tail].roadId=0;
   tail++;
   while(head<tail)
      { 
	      r_1=CROSS[runQue[head].crossId].crossRoadid_1;
	      r_2=CROSS[runQue[head].crossId].crossRoadid_2;
	      r_3=CROSS[runQue[head].crossId].crossRoadid_3;
	      r_4=CROSS[runQue[head].crossId].crossRoadid_4;
	      //four
	      if(r_1!=-1&&book[r_1]==0)
	      {
		      f_1=ROAD[r_1].roadFrom;
		      t_1=ROAD[r_1].roadTo;
		      if(ROAD[r_1].roadIsduplex==0)
		      {
			      if(f_1==runQue[head].crossId)
			      {
				      book[r_1]=1;
				      runQue[tail].f=head;
				      runQue[tail].dis=ROAD[r_1].roadLength+runQue[head].dis;
				      runQue[tail].roadId=r_1;
				      runQue[tail].crossId=t_1;
			      }
		      }
		      else
		      {
			      if(runQue[head].crossId==f_1)
			      {
			       	      book[r_1]=1;
                                      runQue[tail].f=head;
                                      runQue[tail].dis=ROAD[r_1].roadLength+runQue[head].dis;
                                      runQue[tail].roadId=r_1;
                                      runQue[tail].crossId=t_1;
			      }
			      else
			      {
				      book[r_1]=1;
				      runQue[tail].f=head;
				      runQue[tail].dis=ROAD[r_1].roadLength+runQue[head].dis;
				      runQue[tail].roadId=r_1;
				      runQue[tail].crossId=f_1;
			      }
		      }
		      tail++;
	      }
	      if(runQue[tail-1].crossId==cTo)
	      {
		      break;
	      }
	      //2
	      if(r_2!=-1&&book[r_2]==0)
              {
		      f_2=ROAD[r_2].roadFrom;
                      t_2=ROAD[r_2].roadTo;
                      if(ROAD[r_2].roadIsduplex==0)
                      {
                              if(f_2==runQue[head].crossId)
                              {
                                      book[r_2]=1;
                                      runQue[tail].f=head;
                                      runQue[tail].dis=ROAD[r_2].roadLength+runQue[head].dis;
                                      runQue[tail].roadId=r_2;
                                      runQue[tail].crossId=t_2;
                              }
                      }
                      else
                      {
                              if(runQue[head].crossId==f_2)
                              {
                                      book[r_2]=1;
                                      runQue[tail].f=head;
                                      runQue[tail].dis=ROAD[r_2].roadLength+runQue[head].dis;
                                      runQue[tail].roadId=r_2;
                                      runQue[tail].crossId=t_2;
                              }
                              else
                              {
                                      book[r_2]=1;
                                      runQue[tail].f=head;
                                      runQue[tail].dis=ROAD[r_2].roadLength+runQue[head].dis;
                                      runQue[tail].roadId=r_2;
                                      runQue[tail].crossId=f_2;
                              }
                      }
                      tail++;
              }
              if(runQue[tail-1].crossId==cTo)
              {
                      break;
              }
	      //3
             if(r_3!=-1&&book[r_3]==0)
              {
		      f_3=ROAD[r_3].roadFrom;
                      t_3=ROAD[r_3].roadTo;

                      if(ROAD[r_3].roadIsduplex==0)
                      {
                              if(f_3==runQue[head].crossId)
                              {
                                      book[r_3]=1;
                                      runQue[tail].f=head;
                                      runQue[tail].dis=ROAD[r_3].roadLength+runQue[head].dis;
                                      runQue[tail].roadId=r_3;
                                      runQue[tail].crossId=t_3;
                              }
                      }
                      else
                      {
                              if(runQue[head].crossId==f_3)
                              {
                                      book[r_3]=1;
                                      runQue[tail].f=head;
                                      runQue[tail].dis=ROAD[r_3].roadLength+runQue[head].dis;
                                      runQue[tail].roadId=r_3;
                                      runQue[tail].crossId=t_3;
                              }
                              else
                              {
                                      book[r_3]=1;
                                      runQue[tail].f=head;
                                      runQue[tail].dis=ROAD[r_3].roadLength+runQue[head].dis;
                                      runQue[tail].roadId=r_3;
                                      runQue[tail].crossId=f_3;
                              }
                      }
                      tail++;
              }
              if(runQue[tail-1].crossId==cTo)
              {
                      break;
              }
	      //4
             if(r_4!=-1&&book[r_4]==0)
              {
		      f_4=ROAD[r_4].roadFrom;
                      t_4=ROAD[r_4].roadTo;
                      if(ROAD[r_4].roadIsduplex==0)
                      {
                              if(f_4==runQue[head].crossId)
                              {
                                      book[r_4]=1;
                                      runQue[tail].f=head;
                                      runQue[tail].dis=ROAD[r_4].roadLength+runQue[head].dis;
                                      runQue[tail].roadId=r_4;
                                      runQue[tail].crossId=t_4;
                              }
                      }
                      else
                      {
                              if(runQue[head].crossId==f_4)
                              {
                                      book[r_4]=1;
                                      runQue[tail].f=head;
                                      runQue[tail].dis=ROAD[r_4].roadLength+runQue[head].dis;
                                      runQue[tail].roadId=r_4;
                                      runQue[tail].crossId=t_4;
                              }
                              else
                              {
                                      book[r_4]=1;
                                      runQue[tail].f=head;
                                      runQue[tail].dis=ROAD[r_4].roadLength+runQue[head].dis;
                                      runQue[tail].roadId=r_4;
                                      runQue[tail].crossId=f_4;
                              }
                      }
                      tail++;
              }
              if(runQue[tail-1].crossId==cTo)
              {
                      break;
              } 
	      head++;
       }
   return ;
}


int main(int argc,char *argv[])
{
	std::cout << "Begin" << std::endl;

        if(argc < 5){
                std::cout << "please input args: carPath, roadPath, crossPath, answerPath" << std::endl;
                exit(1);
        }

        std::string carPath(argv[1]);
        std::string roadPath(argv[2]);
        std::string crossPath(argv[3]);
        std::string answerPath(argv[4]);

        std::cout << "carPath is " << carPath << std::endl;
        std::cout << "roadPath is " << roadPath << std::endl;
        std::cout << "crossPath is " << crossPath << std::endl;
        std::cout << "answerPath is " << answerPath << std::endl;
        // TODO:read input filebuf

    int i,j;
    carNum=0;//car total number,from 1 to carNum
    roadNum=0;//road total number,from 1 to roadNum
    crossNum=0;//cross total number ,from 1 to crossNum
    int a[50];//transform string to number
    ifstream carDatain(carPath,ios::in);// car data in
    ifstream roadDatain(roadPath,ios::in);// road data in
    ifstream crossDatain(crossPath,ios::in);//cross data in
    ofstream answerOut(answerPath);//answer out
    if(!carDatain)//is car data open success?
    {
        cout<<"car.txt can not open"<<endl;//panduan wenjian shifou dakai
    }
    if(!roadDatain)//is road data open success?
    {
        cout<<"road.txt can not open"<<endl;//panduan wenjian shifou dakai
    }
    if(!crossDatain)//is cross data open success?
    {
        cout<<"cross.txt can not open"<<endl;//panduan wenjian shifou dakai
    }
// read car data
    string stem;//not read the first line data
    string s;//duru shuju字符串
    getline(carDatain,stem);//hulue di yi hang 
    while(getline(carDatain,s))// read the data line by line
    {
	    
	    carInfo info;//lin shi liang
//	    info.line="sd";//the line first
//	    info.line=s;//read the string by line to line
	    //字符串中取出数字
	    char * z=(char*)s.data();
	    const char *d= " ,()";//fen ge fu
	    char *p;
	    p=strtok(z,d);
	    i=1;
	    while(p){
                    //transform string to number
                    stringstream ss;
		    ss<<p;
		    ss>>a[i];
		    i++;
		    p=strtok(NULL,d);
	    }
	    //字符串中取出数字
	    info.carId=a[1];//carId
	    info.carFrom=a[2];//carFrom
	    info.carTo=a[3];//carTo
	    info.carHighspeed=a[4];//carHighspeed
	    info.carPlantime=a[5];//carPlantime
	    car.push_back(info);// push_back to car
	    // cout<<s<<endl;//know if the s line has in the info,line
	    carNum++;//car number + 1, total carNum;
    }

//read road data
    getline(roadDatain,stem);//hulue di yi hang 
    while(getline(roadDatain,s))// read the data line by line
    {

            roadInfo info;//lin shi liang
            //字符串中取出数字
            char * z=(char*)s.data();
            const char *d= " ,()";//fen ge fu
            char *p;
            p=strtok(z,d);
            i=1;
            while(p){
                    //transform string to number
                    stringstream ss;
                    ss<<p;
                    ss>>a[i];
                    i++;
                    p=strtok(NULL,d);
            }
            //字符串中取出数字
            info.roadId=a[1];//road id
            info.roadLength=a[2];//road length
            info.roadHighspeed=a[3];//road high speed
            info.roadChannel=a[4];//road channel
            info.roadFrom=a[5];//road from crossid
	    info.roadTo=a[6];//road to crossid
	    info.roadIsduplex=a[7];//road isduplex?
            road.push_back(info);// push_back to car
            // cout<<s<<endl;//know if the s line has in the info,line
            roadNum++;//road number + 1, total carNum;
    }
//read cross data
    getline(crossDatain,stem);//hulue di yi hang
    while(getline(crossDatain,s))// read the data line by line
    {

            crossInfo info;//lin shi liang
            //字符串中取出数字
            char * z=(char*)s.data();
            const char *d= " ,()";//fen ge fu
            char *p;
            p=strtok(z,d);
            i=1;
            while(p){
                    //transform string to number
                    stringstream ss;
                    ss<<p;
                    ss>>a[i];
                    i++;
                    p=strtok(NULL,d);
            }
            //字符串中取出数字
            info.crossId=a[1];//road id
            info.crossRoadid_1=a[2];//cross road 1 -roadId
            info.crossRoadid_2=a[3];//cross road 2 -roadId
            info.crossRoadid_3=a[4];//cross road 3 -roadId
            info.crossRoadid_4=a[5];//cross road 4 -roadId
            
            cross.push_back(info);// push_back to car
            // cout<<s<<endl;//know if the s line has in the info,line
            crossNum++;//cross number + 1, total crossNum;
    }		    
    for(i=0;i<crossNum;i++)
    {	
        CROSS[cross[i].crossId].crossId=cross[i].crossId;
        CROSS[cross[i].crossId].crossRoadid_1=cross[i].crossRoadid_1;
        CROSS[cross[i].crossId].crossRoadid_2=cross[i].crossRoadid_2;
        CROSS[cross[i].crossId].crossRoadid_3=cross[i].crossRoadid_3;
        CROSS[cross[i].crossId].crossRoadid_4=cross[i].crossRoadid_4;
    }   
    for(i=0;i<roadNum;i++)
    {
	ROAD[road[i].roadId].roadId=road[i].roadId;
	ROAD[road[i].roadId].roadLength=road[i].roadLength;
	ROAD[road[i].roadId].roadHighspeed=road[i].roadHighspeed;
	ROAD[road[i].roadId].roadChannel=road[i].roadChannel;
	ROAD[road[i].roadId].roadFrom=road[i].roadFrom;
	ROAD[road[i].roadId].roadTo=road[i].roadTo;
	ROAD[road[i].roadId].roadIsduplex=road[i].roadIsduplex;
    }
//guangdu sousuo
//   struct runNote runQue[100000];//sui ditu gaibian

    int runNum;
for(i=0;i<carNum;i++)
{
//	head=1;
//	tail=1;
	runRun(car[i].carFrom,car[i].carTo);
        runNum=1;
        tail--;
        while(head>1)
        {
	      // cout<<runQue[tail].roadId<<' ';
               carRun[i].a[runNum]=runQue[tail].roadId;
               head=runQue[tail].f;
               tail=head;
               runNum++;
        }
        carRun[i].a[0]=runNum-1;
//	cout<<endl;i
}

// the carPlantime
// just kiding
// //23333333
/*
for(i=0;i<carNum;i++)
{
	car[i].carPlantime=i+1;
	car[i].carPlantime=car[i].carPlantime*5;
}
*/
//kiding
multimap<int,int>roadMapft;
multimap<int,int>roadMaptf;
for(i=0;i<roadNum;i++){
	if(road[i].roadIsduplex=1)
	{
		roadMapft.insert({road[i].roadId,0});
		roadMaptf.insert({road[i].roadId,0});
	}
	else
	{
		roadMapft.insert({road[i].roadId,0});
	}
}
/*
auto firstIterft=roadMapft.find(5000);
auto keyNumft=roadMapft.count(5000);
auto firstItertf=roadMaptf.find(5000);
auto keyNumtf=roadMaptf.find(5000);
while(keyNumft){
	++firstIterft->second;
	++firstIterft->second;
	cout<<firstIterft->second++<<' ';
	++firstIterft;
	--keyNumft;
}
firstIterft=roadMapft.find(5059);
firstItertf=roadMapft.find(5059);
keyNumft=roadMapft.count(5059);
while(keyNumft){
//	cout<<firstIterft->second<<' ';
	++firstIterft;
	--keyNumft;
}
*/
//car 1
map<int,int>nowRoadhavetime;
int totalLength[50];
int k=0;
int L=0;//the totalLength
int allLength;
int carRuninroad;
int s1;
int s2;
int ss;
int v1;
int v2;
int lenNum;
int m;
int n;
int TIME;
int t;//mark
for(i=0;i<2;i++)
{
	for(j=0;j<50;j++)
		totalLength[j]=0;
	j=0;
	L=0;
	lenNum=0;
	k=carRun[i].a[0];
	m=carRun[i].a[0];
	car[i].carPlantime=1;//all first = 1;
	nowRoadhavetime.insert({carRun[i].a[k],car[i].carPlantime});//dongtai
	for(j=0;j<50;j++)
	{
		totalLength[j]=0;
	}
	for(j=k;j>=1;j--)
	{
		lenNum++;
		L=L+ROAD[carRun[i].a[j]].roadLength;
		totalLength[lenNum]=L;
	}
	TIME=0;
	j=0;
	s1=0;
	v1=0;
	v2=0;
	s2=0;
	lenNum=1;
	carRuninroad=0;
	allLength=totalLength[k];
	while(carRuninroad<=allLength)
	{
		TIME++;
		s2=0;
		s1=totalLength[lenNum]-carRuninroad;
		if(car[i].carHighspeed>ROAD[carRun[i].a[m-j]].roadHighspeed)
		{
			v1=ROAD[carRun[i].a[m-j]].roadHighspeed;
		}
		else
		{
			v1=car[i].carHighspeed;
		}
		carRuninroad=carRuninroad+v1;
		if(carRuninroad>allLength)
			break;
		if(carRuninroad==allLength)
		{
			TIME++;//jiedian shijian jincheku
			break;
		}
		if(carRuninroad>totalLength[lenNum])
		{
			j++;
			lenNum++;
			nowRoadhavetime.insert({carRun[i].a[m-j],TIME});
			if(car[i].carHighspeed>ROAD[carRun[i].a[m-j]].roadHighspeed)
				v2=ROAD[carRun[i].a[m-j]].roadHighspeed;
			else
				v2=car[i].carHighspeed;
			ss=carRuninroad-totalLength[lenNum-1];
			if(s1>=v2)
				s2=0;
			else
			{
				s2=v2-s1;
				if(s2<=0)
					s2=0;
			}
			carRuninroad=totalLength[lenNum-1]+s2;
		}
	}
//car 1
        int isDuplex[50];
	t=0;//the mark
	for(j=0;j<50;j++)
		isDuplex[j]=0;
	for(j=k;j>=1;j--)
	{
		if(ROAD[carRun[i].a[j]].roadTo==ROAD[carRun[i].a[j-1]].roadFrom||ROAD[carRun[i].a[j]].roadTo==car[i].carTo)
			isDuplex[j]=1;
		else
			isDuplex[j]=0;
	}
	
	while(t=0)
	{
		t=1;
		k=carRun[i].a[i];
		for(j=k;j>=1;j--)
		{
			if(isDuplex[j]==1)
			{
				auto firstIterft=roadMapft.find(carRun[i].a[j]);
				auto keyNumft=roadMapft.count(carRun[i].a[j]);
				while(keyNumft){
					if(firstIterft->second==nowRoadhavetime.find(carRun[i].a[j])->second)
					{
						t=0;
						break;
					}
					++firstIterft;
					--keyNumft;
				}
			}
			else
			{
				auto firstItertf=roadMaptf.find(carRun[i].a[j]);
				auto keyNumtf=roadMaptf.count(carRun[i].a[j]);
				while(keyNumtf){
					if(firstItertf->second==nowRoadhavetime.find(carRun[i].a[j])->second)
					{
						t=0;
						break;
					}
					++firstItertf;
					--keyNumtf;
				}
			}
		}
		if(t==0)
		{
			for(j=k;j>=1;j--)
			{
				++nowRoadhavetime.find(carRun[i].a[j])->second;
			}
		}
	}
	k=carRun[i].a[0];
	m=0;
	n=0;
	for(j=k;j>=1;j--)
	{
		n=carRun[i].a[j];
		m=nowRoadhavetime.find(n)->second;
		if(isDuplex[j]==1)
			roadMapft.insert({n,m});
		else
			roadMaptf.insert({n,m});
	}
	cout<<endl;
	car[i].carPlantime=nowRoadhavetime.find(carRun[i].a[k])->second;
	cout<<car[i].carPlantime<<endl;
	for(j=0;j<=carRun[i].a[0];j++)
	{
		nowRoadhavetime.erase(carRun[i].a[j]);
	}
}

//233333
//the carPlantime
//guangdu sousou
//the answer
    for(i=0;i<carNum;i++)
    {
	    answerOut<<'('<<car[i].carId<<','<<car[i].carPlantime;
	    for(j=carRun[i].a[0];j>=1;j--)
	    {
		    answerOut<<','<<carRun[i].a[j];
	    }
	    answerOut<<')'<<endl;
    }
    answerOut<<endl;
    //close the files
    answerOut.close();//close answer.txt
    carDatain.close();//close car.txt
    roadDatain.close();//close road.txt
    crossDatain.close();//close cross.txt
    
    return 0;
}
