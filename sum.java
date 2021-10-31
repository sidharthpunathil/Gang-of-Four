/*
==================================================================================================================================
Date: 26/Sep/2020
Author: Amal Shibu
Languages Used: Java
Session: Online Class
Subject: Oops lab
Error: Null
Warnings:Null
==================================================================================================================================
*/

/*3.Create an application class 'AdditionClass' having two integers and two member functions 
 *a).Read 2 No's b).To add 2 No's and Display Sum.*/


import java.util.Scanner;	
class sum
{
	public static void main(String amal[])
	{
		AdditionClass obj=new AdditionClass();
		obj.read();
		obj.add_print();
	}	
}

class AdditionClass
{
	int Var1,Var2;
	public void read()
	{
		Scanner input=new Scanner(System.in);

		System.out.println("Enter a number: ");
		this.Var1=input.nextInt();
		
		System.out.println("Enter Another Number : ");
		this.Var2=input.nextInt();
	
	}

	public void add_print()
	{	
		int result=Var1+Var2;
		System.out.println("Sum : "+result);		
	}		
}