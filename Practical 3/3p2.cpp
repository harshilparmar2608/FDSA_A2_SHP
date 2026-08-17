#include<iostream>
using namespace std;
int main()
{
     int arr[5]={0,2,2,1,0};
     int low=0;
     int cur=0;
     int high=4;
     int temp;

     while(cur<=high)
     {


        if(arr[cur]==0)
        {
            temp=arr[cur];
            arr[cur]=arr[low];
            arr[low]=temp;
            low++;
            cur++;
        }
        else if(arr[cur]==1)
        {
            cur++;
        }
        else if(arr[cur]==2)
        {
          temp=arr[cur];
            arr[cur]=arr[high];
            arr[high]=temp;
            high--;
            
        }
     }
    

     for (int i = 0; i < 5; i++)
     {
        cout<<arr[i];
        cout<<endl;
     }
     

}