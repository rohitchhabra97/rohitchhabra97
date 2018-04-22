#include<stdio.h>
#include<unistd.h>
int main(){
int n,i,j,a,b,c,x=0;
int temp=0;
printf("Enter number of processes\n");
scanf("%d",&n);
int q1[n],q2[n],q3[n];
int p[n],pro[n],bt[n],at[n],rt[n];
for(i=0;i<n;i++)                                                                                             // O(n)                             
{
printf("\n\nEnter process name for process %d = ",i+1,"\n");
printf("P");
scanf("%d",&pro[i]);
printf("\n\nEnter priority for this process ");
scanf("%d",&p[i]);
printf("\n\nEnter burst time for this process ");
scanf("%d",&bt[i]);
}
for(i=0;i<n-1;i++)                                                                                           //O(n-1)
{
for(j=0;j<(n-i-1);j++)                                                                                     //O(n-i-1)
{
if(p[j]>p[j+1]){
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
temp=pro[j];
pro[j]=pro[j+1];
pro[j+1]=temp;
temp=bt[j];
bt[j]=bt[j+1];
bt[j+1]=temp;
}}
}
for(i=0;i<n;i++)                                                                                           		 // O(n)
{
printf("Process P%d",pro[i]);
printf(" with priority %d",p[i]);
printf(" has burst time %d",bt[i]);
printf("\n\n");
}
printf("\nEnter the number of processes you want to process in queue 1 :\n");
scanf("%d",&a);
printf("Enter the number of processes you want to process in queue 2 :\n");
scanf("%d",&b);
printf("Enter the number of processes you want to process in queue 3 :\n");
scanf("%d",&c);
for(i=0;i<a;i++){                                                                                                        //O(a)
q1[x]=p[i];
x=x+1;
}
printf("_______________________________________________\n");
printf("|	QUEUE 1		Priority  Burst time  |\n");
printf("|_____________________________________________|\n");
for(i=0;i<a;i++){                                                                                                        //O(a)
printf("	  P%d		   ",pro[i]);
printf("%d		",p[i]);
printf("%d\n",bt[i]);
}
printf("_______________________________________________\n\n");
for(i=a;i<b+a;i++){                                                                                                     //O(b)
q2[x]=p[i];
x=x+1;
}
printf("\n");
printf("_______________________________________________\n");
printf("|	QUEUE 2		Priority  Burst time  |\n");
printf("|_____________________________________________|\n");
for(i=a;i<b+a;i++){                                                                                                     //O(b)
printf("	  P%d		   ",pro[i]);
printf("%d     ",p[i]);
printf("%d\n",bt[i]);
}
printf("_______________________________________________\n\n");
for(i=b+a;i<c+b+a;i++){                                                                                            //O(c)
q3[x]=p[i];
x=x+1;
}
printf("\n");
printf("_______________________________________________\n");
printf("|	QUEUE 3		Priority  Burst time  |\n");
printf("|_____________________________________________|\n");
for(i=b+a;i<c+a+b;i++){                                        					//O(c)
printf("	  P%d		   ",pro[i]);
printf("%d     ",p[i]);
printf("%d\n",bt[i]);
}
printf("_______________________________________________\n");
printf("\n");
int tq,t,remain,flag=0;
int waiting_time=0,turn_time=0;
remain=a;
printf("\n\nWELCOME TO QUEUE 1... LETS DO ROUND ROBIN SCHEDULING...\n\n");
for(i=0;i<a;i++){									  //O(c)
printf("Enter arrival time for P%d =",pro[i]);
scanf("%d",&at[i]);
rt[i]=bt[i];
}
printf("Enter Time Quantum = ");
scanf("%d",&tq);
printf("\n\nProcess\t|Turnaround time|Waiting time\n\n");
for(t=0,i=0;remain!=0;)								//O(a)
{
if(rt[i]<=tq && rt[i]>0)
{
t=t+rt[i];
rt[i]=0;
flag=1;
}
else if(rt[i]>0)
{
rt[i]=rt[i]-tq;
t=t+tq;
}
if(rt[i]==0 && flag==1)
{
remain--;
printf("P%d\t|\t%d\t|\t%d\n",i+1,t-at[i],t-at[i]-bt[i]);
waiting_time=waiting_time+t-at[i]-bt[i];
turn_time=turn_time+t-at[i];
flag=0;
}
if(i==a-1)
i=0;
else if(at[i+1]<=t)
i++;
else
i=0;
}
printf("\n\nAverage waiting time= %f sec\n",waiting_time*1.0/a);
printf("\nAverage turnaround time= %f sec\n",turn_time*1.0/a);
printf("\n\n-------------------------------------------------------------\n\n");
printf("\n\nWELCOME TO QUEUE 2... LETUS DO PRIORITY QUEUE SCHEDULING..\n");
int wtime[n],ttime[n];int avg_wt,avg_tat,total=0;
wtime[a]=0;
for(i=a+1;i<b+a;i++){									//O(b)
wtime[i]=0;
for(j=a;j<i;j++)									//O(i-a)
wtime[i]=wtime[i]+bt[j];
total=total+wtime[i];
}
avg_wt=total*1.0/b;
total=0;
printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
for(i=a;i<b+a;i++)									//O(b)
{
ttime[i]=bt[i]+wtime[i];
total=total+ttime[i];
printf("\nP%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],wtime[i],ttime[i]);
}
avg_tat=total/b;
printf("\n\nAverage waiting time= %f sec\n",avg_wt*1.0);
printf("\nAverage turnaround time= %f sec\n",avg_tat*1.0);

printf("\n\n-------------------------------------------------------------\n\n");
printf("\n\nWelcome to QUEUE 3... let us do FCFS scheduling\n");
int wt[n],tat[n]; int avwt=0,avtat=0;
wt[b+a]=0;
for(i=b+a+1;i<c+a+b;i++){								//O(c)
wt[i]=0;
for(j=b+a;j<i;j++)									//O(i-b-a)
wt[i]=wt[i]+bt[j];
}
printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
for(i=b+a;i<b+a+c;i++)								//O(c)
{
tat[i]=bt[i]+wt[i];
avwt=avwt+wt[i];
avtat=avtat+tat[i];
printf("\nP%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
}

printf("\n\nAverage waiting time= %f sec\n",avwt*1.0/c);
printf("\nAverage turnaround time= %f sec\n",avtat*1.0/c);

}
