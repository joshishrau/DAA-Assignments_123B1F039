#include<stdio.h>
void bubbleSort(int arr[],int n){
int i,j,temp;
for( i=0 ;i<n-1 ;i++){
   for(j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
//swap
         temp=arr[j];
         arr[j]=arr[j+1];
         arr[j+1]=temp;
       }
     }
   }
 }
 
void printArray(int arr[],int n)
{
int i;
for(i=0;i<n;i++){
   printf("%d ",arr[i]);

   }
}


int main(){
int i,n;
printf("enter size of array : ");
scanf("%d",&n);

printf("enter %d elements : ",n);
int arr[n];
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}


printf("sorted array:\n");
bubbleSort(arr,n);
printArray(arr,n);
return 0;
}
