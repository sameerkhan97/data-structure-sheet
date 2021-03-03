//Q-Java Program to Check if a string is a valid shuffle of two distinct strings
//1XY2 is a valid shuffle of XY and 12
//Y12X is not a valid shuffle of XY and 12
import java.util.*;
import java.lang.*;
import java.io.*;
 
class Ideone
{
	public static boolean isShuffle(String first,String second,String result)
	{
		// check length of result is same as
    	// sum of result of first and second
		if(first.length()+second.length()!=result.length())
			return false;
		// variables to track each character of 3 strings
		int i=0,j=0,k=0;
		// iterating through all characters of result
		while(k<result.length())
		{
			// check if first character of result matches with first character of first string
			if(i<first.length() && first.charAt(i)==result.charAt(k))
				i++;
			// check if first character of result matches with first character of second string
			else if(j<second.length() && second.charAt(j)==result.charAt(k))
				j++;
			// if the character doesn't match
			else
				return false;
			//next char of result 
			k++;
		}
		if(i<first.length() || j<second.length())
			return false;
 
		return true;
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		String first="AB";
		String second="12";
		String[] results={"A12B","A21B"};
		for(String result :results){
			if(isShuffle(first,second,result))
				System.out.println(result+" is a valid shulffle of "+first+" & "+second);
			else
				System.out.println(result+" is a not valid shulffle of "+first+"&"+second);
 
		}
	}
}
