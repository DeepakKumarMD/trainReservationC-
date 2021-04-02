#include<iostream>
#include<string.h>

using namespace std;
/*allotment(q);
int trainresv::position(char arr[32][25]);
int trainresv::showt();
void trainresv::retnt();*/
class trainresv
{
char arrival[4][5],depart[4][5],from[4][25],to[4][25],seat[25];
int train_no[4],tnn,seatn;
protected:
float fare;
public:
trainresv();
void showtrain();
void show(int k,char arr[32][25]);
int showt();
int retnt();
int retseat();
char *retnam();
int position(char arr[32][25]);
virtual void calfare()=0;
void vline(char ch)
{

for(int i=80;i>0;i--)
cout<<ch;
}

}*tptr[32];
trainresv::trainresv()
{
    int i=0;
cout<<"\t\t\t*******WELCOME USERS!***************\n";
strcpy(arrival[i],"6AM");
strcpy(depart[i],"1AM");
strcpy(from[i],"First");
strcpy(to[i],"first");
train_no[i++]=101;
strcpy(arrival[i],"7AM");
strcpy(depart[i],"2AM");
strcpy(from[i],"Second");
strcpy(to[i],"second");
train_no[i++]=202;
strcpy(arrival[i],"8AM");
strcpy(depart[i],"3AM");
strcpy(from[i],"Third");
strcpy(to[i],"third");
train_no[i++]=303;
strcpy(arrival[i],"10AM");
strcpy(depart[i],"4AM");
strcpy(from[i],"Fourth");
strcpy(to[i],"fourth");
train_no[i++]=404;
}
int num[4][32],z;
class children:public trainresv
{
public:
void calfare()
{
fare=125*0.5;
cout<<"\nThe total fare is:"<<fare<<endl;
}
/*~children()
{
    delete this;
}*/
};
class adult:public trainresv
{
public:
void calfare()
{
fare=125;
cout<<"\nThe total fare is:"<<fare<<endl;
}
/*~adult()
{
    delete this;
}*/
};
class sencitiz:public trainresv
{
public:
void calfare()
{
fare=125*0.8;
cout<<"\nThe total fare is:"<<fare<<endl;
}
/*~sencitiz()
{
    delete this;
}*/
};
int main()
{
    char arr[32][25];
    int w,j,i=0,age[32],ch,qw;
    children *cptr,temp;
    adult *aptr;
    sencitiz *sptr;

    do
    {
        cout<<"\n1)Book Tickets\n2)Display available trains\n3)Exit\nEnter your choice:";
        cin>>w;
        switch(w)
        {
        case 1:
            cout<<"\nEnter the age of the person:";
            cin>>age[i];
            if(age[i]>60)
               ch=1;
            else if(age[i]>12)
               ch=2;
            else
               ch=3;
            switch(ch)
            {
            case 1:
                sptr=new sencitiz;
                sptr->showtrain();
                tptr[i]=sptr;
                tptr[i]->calfare();
                break;
            case 2:
                aptr=new adult;
                aptr->showtrain();
                tptr[i]=aptr;
                tptr[i]->calfare();
                break;
            case 3:
                cptr=new children;
                cptr->showtrain();
                tptr[i]=cptr;
                tptr[i]->calfare();
                break;
            }
            i++;
            break;
            case 2:
                qw=temp.showt();
                for(j=0;j<32;j++)
        strcpy(arr[j],"Empty");
                for(j=0;j<i;j++)
                    {
                        if(age[i]>60)
                          {
                              //sptr=tptr[j];
                              if(tptr[j]->retnt()==qw)
                              strcpy(arr[tptr[j]->retseat()-1],tptr[j]->retnam());
                          }
                        else if(age[i]>12)
                          {
                              //aptr=tptr[j];
                              if(tptr[j]->retnt()==qw)
                              strcpy(arr[tptr[j]->retseat()-1],tptr[j]->retnam());
                          }
                        else
                          {
                              //cptr=tptr[j];
                              if(tptr[j]->retnt()==qw)
                              strcpy(arr[tptr[j]->retseat()-1],tptr[j]->retnam());
                          }

        }
        temp.show(qw,arr);
        break;

            case 3:
                cout<<"\nThankyou!!";
                break;
            default:
                cout<<"\nEnter a valid choice!!";
                break;
    }
    }while(w!=3);
}
void trainresv::show(int k,char arr[32][25])
{
int p;
vline('*');
cout<<"train no:\t"<<train_no[k]<<"\t\t arrival time\t"<<arrival[k]<<"\t departure time:"<<depart[k]<<"\n from:\t\t"<<from[k]<<"\t\t to: \t\t:"<<to[k]<<"\n";
vline('*');
p=position(arr);
cout<<"\n\n There are "<<p<<"seat empty in train no:"<<train_no[k];
}

int trainresv::position(char arr[32][25])
{
int s=0,p=0;
for(int i=0;i<32;i++)
{
cout<<"\n";
s++;
if(strcmp(arr[i],"Empty")==0)
{
cout.width(5);
cout.fill('*');
cout<<s<<".";
cout.width(10);
cout.fill('*');
cout<<arr[i];
p++;
}
else
{
cout.width(5);
cout.fill('*');
cout<<s<<".";
cout.width(10);
cout.fill('*');
cout<<arr[i];
}
}
return p;
}

int trainresv::showt()
{
    int i,n;
    for(i=0;i<4;i++)
        cout<<i+1<<")Train Number:"<<train_no[i]<<"  From:"<<from[i]<<"  To:"<<to[i]<<endl;
    cout<<"\nEnter your choice to know more:";
    cin>>n;
    return n-1;
}
void trainresv::showtrain()
{
    int k,i;
    tnn=showt();
    awm:
    cout<<"\nSelect the seat number you want:";
    cin>>seatn;
    if(seatn>32||seatn<1)
    {
        cout<<"\nSeat numbers are available only from 1-32!"<<endl;
        goto awm;
    }
    for(i=0;i<z;i++)
    if(seatn==num[tnn][i])
        {cout<<"\nSeat already reserved!!\nSelect some other seat!"<<endl;
         goto awm;}
    cout<<"\nEnter Name of the Passenger:";
    num[tnn][z++]=seatn;
    cin>>seat;
}

int trainresv::retnt()
{
    return tnn;
}
char* trainresv::retnam()
{
    return seat;
}
int trainresv::retseat()
{
    return seatn;
}