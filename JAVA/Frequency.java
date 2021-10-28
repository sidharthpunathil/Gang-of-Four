/*
==================================================================================================================================
Date: 19/Sep/2020
Author: Amal Shibu
Languages Used: Java
Session: Online Class
Subject: Oops lab
Error: Null
Warnings:Null
==================================================================================================================================
*/

class Frequency 
{
	public static void main(String[] args)
	{
		String sample="This website is awesome";
		char find='e';
		int count=0;

		for(int i=0;i<sample.length();i++)
		{
			if(find==sample.charAt(i))
				++count;
		}
        	System.out.println("Frequency of"+find+"="+count); 
    }
}