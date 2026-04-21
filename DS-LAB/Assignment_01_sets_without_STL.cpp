#include <bits/stdc++.h>
using namespace std;

int main(){
int arr1[]= {10,20,30,40,50};
int arr2[]= {30,50,60,70,80};
int choice;

do{
cout<<"-------------MENU--------------"<<endl;
cout<<"1.Union"<<endl;
cout<<"2.Intersection"<<endl;
cout<<"3.Difference"<<endl;
cout<<"Enter choice : "<<endl;
cin>>choice;

switch(choice){
	case 1:{
		int uni[10];
		int k = 0;

                
    for(int i=0; i<5; i++){
		uni[k++] = arr1[i];
	}

    for(int i=0; i<5; i++){
        bool flag = false;
        for(int j=0; j<5; j++){
			if(arr2[i] == arr1[j]){
              	flag = true;
                break;
               }
          }
          if(!flag){
             uni[k++] = arr2[i];
          }
    }

	for(int i=0; i<k; i++){
		cout<<uni[i]<<" ";
		}
	cout<<endl;	
	break;
	}
	
	case 2:{
	int inr[5];
	int m=0;
	for(int i=0; i<5; i++){
	bool flag=false;
        for(int j=0; j<5; j++){
			if(arr2[i] == arr1[j]){
              	flag = true;
                break;
               }
          }
          if(flag){
             inr[m++] = arr2[i];
          }
    }
    for(int i=0; i<m; i++){
		cout<<inr[i]<<" ";
		}
	cout<<endl;}
    break;
    case 3:
   {
    int diff[10];
    int s=0;
    for(int i=0; i<5; i++){
        bool flag = false;
        for(int j=0; j<5; j++){
			if(arr1[i] == arr2[j]){
              	flag = true;
                break;
               }
          }
          if(!flag){
             diff[s++] = arr1[i];
          }
    }
    for(int i=0; i<s; i++){
		cout<<diff[i]<<" ";
		}
	cout<<endl;	
    
    }
    break;
    
    case 4:
    	cout<<"Exiting"<<endl;
    	break;
    default:
    	cout<<"Invalid input enter again"<<endl;
	}
}while(choice != 4);
return 0;
}
