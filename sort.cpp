
#include<iostream>
 
using namespace std;
 //selection sort
int main()
{
    int i,j,n,loc,temp,min,a[30];
    cout<<"Enter the number of elements:";
    cin>>n;
    cout<<"\nEnter the elements\n";
 
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
 
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                loc=j;
            }
        }
 
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
 
    cout<<"\nSorted list is as follows\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
 
    return 0;
}



// insertion sort
int main()
{
    int i,j,n,temp,a[30];
    cout<<"Enter the number of elements:";
    cin>>n;
    cout<<"\nEnter the elements\n";
 
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
 
    for(i=1;i<=n-1;i++)
    {
        temp=a[i];
        j=i-1;
 
        while((temp<a[j])&&(j>=0))
        {
            a[j+1]=a[j];    //moves element forward
            j=j-1;
        }
 
        a[j+1]=temp;    //insert element in proper place
    }
 
    cout<<"\nSorted list is as follows\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
 
    return 0;
} return 0;  
}


//bubble sort
int main()
{
	int a[50],n,i,j,temp;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the array elements: "; 
	
	for(i=0;i<n;++i)
		cin>>a[i];
		
	for(i=1;i<n;++i)
	{
		for(j=0;j<(n-i);++j)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	}
	
	cout<<"Array after bubble sort:";
	for(i=0;i<n;++i)
		cout<<" "<<a[i];
		
	return 0;
}

//shell sort
void sort(int a[],int n)
{
	int gap,i,j,temp;
	for(gap=n/2;gap>0;gap/=2)
	{
		for(i=gap;i<n;i+=1)
		{
			temp=a[i];
			
			for(j=i;j>=gap&&a[j-gap]>temp;j-=gap)
				a[j]=a[j-gap];
			
			a[j]=temp;
		}
	}
}
