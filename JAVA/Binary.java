import java.io.*;
import java.util.Scanner;
class Binary
{
    public static void binarySearch(int key,int a[],int n)
    {
        int mid,low=0,high=n-1;
        char found='f';
        while(found=='f' && low<=high) 
        {
            mid=(low+high)/2;
            if(a[mid]==key) 
            {
                found='t';
                System.out.printf("\nElement %d found at position %d\n\n",key,mid+1);
            } 
            else if(a[mid]<key)
                low=mid+1;
            else
                high=mid-1;
        }
        if(low>high)
            System.out.printf("\nElement not found\n\n");
    }
    public static void main(String[] args) 
    {
        Scanner reader=new Scanner(System.in);
        int i,key;
        System.out.printf("\nPlease Enter the size of the array: ");
        int n=reader.nextInt();
        int arr[]=new int[n];
        System.out.printf("\nEnter %d elements of the array: ", n);
        for(i=0;i<n;i++)
            arr[i]=reader.nextInt();
        System.out.printf("\nEnter the Search Element: ");
        key=reader.nextInt();
        binarySearch(key,arr,n);
    }
}