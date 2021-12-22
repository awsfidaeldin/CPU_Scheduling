// Aws Yousif

#include<iostream.h>
#include<time.h>
#include<stdlib.h>

struct PCB
{
int pid;	         //Process ID ,Generated Randomly (100-500)
int cpu_time;     //CPU Burst ,Generated Randomly (10-50)
int a_time;	      //Arrival Time is equal in all PCB's
int w_time;	      //Waiting Time ,Calculated
int r_time;       //Response Time ,Calculated
int t_time;       //Turnaround Time ,Calculated
int job_no;	      //Job Number 1,2,3,…………..,N
char status;	   //Ready State "R"
};

void Timer1();                   //function
void Timer1(){                   //timer = 0.01 sec  + print
for (int p=0;p<23;p++){
clock_t s,e;
float r;
s=clock() ;
while(1){
e=clock();
r=(e-s)/ CLOCKS_PER_SEC;
if(r>0.01)break;
}
cout<<"###";}
}

void Timer2();                //function
void Timer2(){                //timer = 0.1 sec   
clock_t s,e;
float r;
s=clock() ;
while(1){
e=clock();
r=(e-s)/ CLOCKS_PER_SEC;
if(r>0.1)break;
}
}

void Timer3();          //function
void Timer3(){          //timer = 1 sec
clock_t s,e;
float r;
s=clock() ;
while(1){
e=clock();
r=(e-s)/ CLOCKS_PER_SEC;
if(r>1)break;
}
}

void main(){

Timer1();
cout<<"\nThis program simulates the Shortest Job First (SJF) CPU Scheduling \nof a Non-Preemptive operating System.\n";
Timer1();
Timer3();

for(;;){
	cout<<"\n\nEnter no. of Jobs: ";            //Request Number of processes
	int n;
	cin>>n;
	PCB Array[200];
	clock_t start,end;                        //used to calculate The CPU time
	start=clock();                            //get time and stored in start
	int prevcpuburst=0 ,WT=0,RT=0, TT=0;      //declarations of(waiting time,average time,tournaround time )

	cout<<"\n                  #####################################\n";
	cout<<"	          ##        Before Scheduling        ##\n";
	cout<<"                  #####################################\n";
	cout<<"    _________________________________________________________________\n";
	cout<<"    | Job No. | PID |CPU Time|Status |  AT  |   WT   |   RT  |  TT  |\n";
	cout<<"    _________________________________________________________________\n";

		for(int i=0;i<n;i++){
			Array[i].job_no=i+1;                            //add job number
			Array[i].pid=rand( ) % 401+ 100;                //adding a pid
			Array[i].cpu_time=rand( ) % 41+ 10;             //adding burst time
			Array[i].status='n';                            //adding satatus
			Array[i].a_time=0;                              //adding arrive time
			Array[i].w_time=WT  ;                           //adding waiting time
			Array[i].r_time=RT ;                            //adding Response  time
			Array[i].t_time=TT  ;                           //adding tournaround time
            
			for(int g=0;g<i;g++){               //to verify whether we have a duplcate pid
				PCB A;                           //create a temp. To store the last object we entered
				A=Array[i];
				if(A.pid==Array[g].pid) {i--; break;}   //if there a duplacte pid it decreases i, to genarate new pid on same location i
				}
				 if(i==g){
				  Timer2();
				  cout<<"\t"<<Array[i].job_no<<"\t";   //display the values (will not display when pid is double)
				  cout<<Array[i].pid<<"\t";
				  cout<<Array[i].cpu_time<<"\t";
				  cout<<Array[i].status<<"\t";
				  cout<<Array[i].a_time<<"\t";
				  cout<<Array[i].w_time<<"\t";
				  cout<<Array[i].r_time<<"\t";
				  cout<<Array[i].t_time<<"\n";
				  cout<<"    _________________________________________________________________\n";
				  }
		}


		for(int g=0;g<n;g++)            //Sorting the array using bubble sort (sorting WT in increasing)
		     for(i=0;i<n-1;i++)
					 if(Array[i].cpu_time > Array[i+1].cpu_time){
								PCB temp=Array[i];
								Array[i]=Array[i+1];
								Array[i+1]=temp;
								 }

  Timer3();Timer3();
 
  float sumWT=0,sumRT=0,sumTT=0;
	for (g=0;g<n;g++){
		 WT=WT+prevcpuburst;               //calculate the waiting time
		 RT=RT+prevcpuburst;               //calculate the  average time
		 TT=TT+Array[g].cpu_time ;         //calculate the tournaround time
		 Array[g].status='R';              // changing to ready state
		 Array[g].w_time=WT  ;             //adding calculated the waiting time
		 Array[g].r_time=RT ;              //adding calculated the Response  time
		 Array[g].t_time=TT  ;             //adding calculated the tournaround time
		 prevcpuburst=Array[g].cpu_time ;  //Needed to calculate the WT & RT
		 sumWT=sumWT+WT;                   //sum of the waiting timw
		 sumRT=sumRT+RT;                   //sum of the  average time
		 sumTT=sumTT+TT;                   //sum of the tournaround time
		 }
  cout<<"\n\n                  #####################################\n";
  cout<<"	          ##         After Scheduling        ##\n";
  cout<<"                  #####################################\n";
  cout<<"    _________________________________________________________________\n";
  cout<<"    | Job No. | PID |CPU Time|Status |  AT  |   WT   |   RT  |  TT  |\n";
  cout<<"    _________________________________________________________________\n";

		  for (i=0;i<n;i++){                          // Display the Array's contents
			 Timer2();
			 cout<<"\t"<<Array[i].job_no<<"\t";
			 cout<<Array[i].pid<<"\t";
			 cout<<Array[i].cpu_time<<"\t";
			 cout<<Array[i].status<<"\t";
			 cout<<Array[i].a_time<<"\t";
			 cout<<Array[i].w_time<<"\t";
			 cout<<Array[i].r_time<<"\t";
			 cout<<Array[i].t_time<<"\n";
			 cout<<"    _________________________________________________________________\n";
	  	    }

  Timer3();Timer3();
  cout<<"\n\n";
  cout<<"Average Waiting Time  = "<<(sumWT/n)<<"\n"; Timer2();Timer2();       //display the average of the waiting timw
  cout<<"Average Response Time  = "<<(sumRT/n)<<"\n"; Timer2();Timer2();       //display the average of the  average time
  cout<<"Average Turnaround Time  = "<<(sumTT/n)<<"\n"; Timer2();Timer2();       //display the average of the tournaround time
  end=clock();                                              //store time in end
  float pt=(end-start)/ CLOCKS_PER_SEC;                     //calculate The CPU time in sec
  cout<<"\nThe CPU time in sec. = "<<"("<<pt<<")";            //diplay The CPU time in sec
  cout<<"\n\n\n";

 Timer3();Timer3();
 cout<<"Do you want to repeat this operation (Y|N) : ";
 char r;                                                 //store response (Y|N)
 cin>>r;                                                 //stores response of repeatng this operation or not
 if(r=='n' || r=='N' )  break;                           // if answer was No,the application terminates
 }

Timer2();
cout<<"\n  ###################################################################\n";
cout<<"  #################       Program terminated        #################\n";
cout<<"  ###################################################################\n";

}