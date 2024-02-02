#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of arrays: ");
    scanf("%d",&n);
    int intervalsSize=n;
    int intervals[n][2];
    printf("Enter the elements\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&intervals[i][j]);
        }
    }
    //Sorting starting time
	for(int j=1;j<n;j++){
		int key=intervals[j][0];
		int i=j-1;
		while(i>=0 && intervals[i][0]>key){
			intervals[i+1][0]=intervals[i][0];
			i=i-1;
		}
		intervals[i+1][0]=key;
	}
    //Sorting end time
    	for(int j=1;j<n;j++){
		int key=intervals[j][1];
		int i=j-1;
		while(i>=0 && intervals[i][1]>key){
			intervals[i+1][1]=intervals[i][1];
			i=i-1;
		}
		intervals[i+1][1]=key;
	}
    //Execution
    int end_times;
    int rooms= 1;

    end_times = intervals[0][1];
    for (int i = 1; i < n; i++) {
        if (intervals[i][0] >= end_times) {
            end_times = intervals[i][1];
        } else {
            rooms++;
        }
    }
    //Printing
    printf("Rooms required: %d\n",rooms);

    return 0;
}