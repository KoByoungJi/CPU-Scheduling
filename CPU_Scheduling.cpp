#include "stdafx.h"
#include <stdio.h>

int bt[10],tat[10],wt[10],at[10];
int i,j,n,k,temp, at_min, bt_min, index;
float avwt=0,avtat=0, nt=0;

void Proc_Making() {
	printf("프로세스 개수 입력[최대 10] : ");
	scanf("%d",&n);
	if(n > 10)
		printf("Max value is 10!\n");
	else {
		for(i=0; i<n; i++) {
			printf("P%d",i+1);
			printf("\n도착 시간 : ");
			scanf("%d",&at[i]);
			printf("수행 시간 : ");
			scanf("%d",&bt[i]);
			printf("\n");
		}
	}
}

void Scheduling() {
	for(i=0; i<n-1; i++) {
		at_min=at[i];
		bt_min=bt[i];
		index=i;
		for(j=i+1; j<n; j++) {
			if(at_min>at[j]) {
				at_min=at[j];
				bt_min=bt[j];
				index=j;
			}
		}
		at[index]=at[i];
		at[i]=at_min;
		bt[index]=bt[i];
		bt[i]=bt_min;
	}
	printf("정렬된 프로세스\n");
	for(i=0; i<n; i++) {
		printf("P%d\t%d\t%d\t",i+1,at[i],bt[i]);
		printf("\n");
	}
}

void Wait_Time() {
	wt[0]=0;
	nt=nt+at[0]+bt[0];
	for(i=1; i<n; i++) {
		if(at[i]<=nt) {
			wt[i]=nt-at[i];
			nt=nt+bt[i];
		}
	avwt=avwt+wt[i];
	}
}

void Turn_Around_Time() {
	for(i=0; i<n; i++) {
		tat[i]=bt[i]+wt[i];
		avtat=avtat+tat[i];
	}
}

int main() {
	Proc_Making();
	Scheduling();
	Wait_Time();
	Turn_Around_Time();
	printf("\nPID\tNAME\tArrive\tBurst\tWait\ttat\n");
	for(i=0; i<n; i++) {
		printf("%d\tP%d\t%d\t%d\t%d\t%d",i+1,i+1,at[i],bt[i],wt[i],tat[i]);
		printf("\n");
	}
	printf("평균 대기시간 = %f \n평균 반환시간 = %f \n\n\n\n",avwt/n,avtat/n);

	return 0;
}
