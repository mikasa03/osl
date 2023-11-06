#include <iostream>
using namespace std;


int need[10][10], alloc[10][10],remain[10][10],avail[10][10],tot[10][10];
int count=0;
int seq[10];

int main(){

    cout<<"BANKING ALGO\n";

    cout<<"Enter total no of resources : \n";
    cout<<"Resource A : ";
    cin>>tot[1][1];
    cout<<"Resource B : ";
    cin>>tot[1][2];
    cout<<"Resource C : ";
    cin>>tot[1][3];


    cout<<"Enter Allocated entries : \nfor\n";


    for (int i=1; i<6;i++){
        cout<<"process "<<i<<": \n";
        cout<<"A :";
        cin>>alloc[i][1];
        cout<<"B :";
        cin>>alloc[i][2];
        cout<<"C :";
        cin>>alloc[i][3];
    }

    cout<<"\n Allocated entry successful\n\n";

    cout<<"Enter Max entries : \nfor\n";

    for (int i=1; i<6;i++){
        cout<<"process "<<i<<": \n";
        cout<<"A :";
        cin>>need[i][1];
        cout<<"B :";
        cin>>need[i][2];
        cout<<"C :";
        cin>>need[i][3];
    }

    cout<<"\n Max entry successful\n\n";

    avail[1][1]= tot[1][1]-alloc[1][1]-alloc[2][1]-alloc[3][1]-alloc[4][1]-alloc[5][1];
    avail[1][2]= tot[1][2]-alloc[1][2]-alloc[2][2]-alloc[3][2]-alloc[4][2]-alloc[5][2];
    avail[1][3]= tot[1][3]-alloc[1][3]-alloc[2][3]-alloc[3][3]-alloc[4][3]-alloc[5][3];

    cout<<"Avail FIRST : "<<avail[1][1]<<" "<<avail[1][2]<<" "<<avail[1][3]<<"\n\n";

    for(int i=1;i<4;i++){
        for(int j=1;j<6;j++){
            remain[j][i]=need[j][i]-alloc[j][i];
        }
    }

    for(int j=1;j<6;j++){
    for(int i=1;i<4;i++){
            cout<<remain[j][i]<<" ";
        } cout<<"\n\n";
    }

    for(int z=1;z<25;z++)
    { 
        int t=z%5+1;
        if((remain[t][1]<=avail[1][1]) && (remain[t][2]<=avail[1][2]) && (remain[t][3]<=avail[1][3])  )
        {
            count++;
            seq[count]=t;
            avail[1][1]=avail[1][1]+alloc[t][1];
            avail[1][2]=avail[1][2]+alloc[t][2];
            avail[1][3]=avail[1][3]+alloc[t][3];

            remain[t][1]=1000;
            remain[t][2]=1000;
            remain[t][3]=1000;

        }
    }

    cout<<"loop ke Bahar";
    cout<<count;

    if(count==5)
    {
        cout<<"SAFE SYSTEM\n\n";
        cout<<"Sequence : ";
        for (int i=1;i<6;i++){
            cout<<seq[i]<<" ";
        }
    }

    else
    {
        cout<<"DEADLOCK";
    }

}