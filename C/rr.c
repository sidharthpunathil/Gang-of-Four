#include<stdio.h>
int mat[10][9],num;
float avg_tt=0,avg_wt=0;
void swap(int *a,int *b) //function to swap two values
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sorts processes according to their arrival time
void arrangeArrival()
{
    for(int i=0; i<num; i++) {
        for(int j=0; j<num-i-1; j++) {
            if(mat[j][1] > mat[j+1][1]) {
                for(int k=0; k<9; k++)
                    swap(&mat[j][k], &mat[j+1][k]);
            }
        }
    }
}

//Sort processes according to Process No
void arrangeProcessno()
{
    int tmp; 
    for(int i=0; i<num; i++) {
        for(int j=0; j<num-i-1; j++) {
            if(mat[j][0] > mat[j+1][0]) {
                for(int k=0; k<9; k++)
                    swap(&mat[j][k], &mat[j+1][k]);
            }
        }
    }
}

//To check whether process executed or not
int check()
{
	for(int i =0;i<num;i++) {
		if(mat[i][7]==0)
			return 0;
	}
	return 1;
}

//Sort processes according to Time Quanta
void arrangequanta(int time_sum,int quanta)
{
	int time = 0,temp;
	time = mat[0][1];
	for(int i=0;;i=(i+1)%num) {
		if(mat[i][1]<=time&&mat[i][7]!=1) {
			if(mat[i][3]==-9999) {
				mat[i][3]=time;
				mat[i][5] = mat[i][3]-mat[i][1];
			}
			if(mat[i][8]-quanta >0) {
				mat[i][8]-=quanta;
				temp = quanta;
			}
			else {
				temp = mat[i][8];
				mat[i][8]=0;
				mat[i][7] = 1;
				mat[i][4]=temp+time;
			}
			time+=temp;
		}
		if(check())
			break;
	}
}

void main()
{
    int time_sum=0,quanta,i;
    printf("Enter number of Process: ");
    scanf("%d",&num);
	printf("Enter the Time Quanta: ");
	scanf("%d",&quanta);
    printf("\nEnter the ProcessName, Arrival Time & Burst Time:\n");
    for(i=0; i<num; i++) {
        printf("P");
        scanf("%d%d%d",&mat[i][0],&mat[i][1],&mat[i][2]);
		mat[i][3]=-9999; //Initialise start time
		time_sum+=mat[i][2]; // Calculate total time
		mat[i][7] = 0;
		mat[i][8] = mat[i][2];
    }
    arrangeArrival();
    arrangequanta(time_sum,quanta);
	arrangeProcessno();
    printf("\nProcess  Burst Time  Arrival Time  Waiting Time  Turnaround Time");
    for(int i=0; i<num; i++) {
		//Calculates and displays Process Details
		mat[i][6] = mat[i][4] - mat[i][1];
		mat[i][5]= (mat[i][4]- mat[i][1]) - mat[i][2];
        printf("\n  P%d\t%7d\t\t%3d\t%9d\t%8d",mat[i][0],mat[i][2],mat[i][1],mat[i][5],mat[i][6]);
		avg_tt+=mat[i][6];
		avg_wt+=mat[i][5];
	}
	printf("\n\nAverage Waiting time: %.3f",avg_wt/num);
    printf("\nAverage Turn Around Time: %.3f\n\n",avg_tt/num);
}