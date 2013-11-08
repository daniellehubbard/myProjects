//Danielle Hubbard
//October 7, 2013
//Contemporary Programming Languages
//This program accepts a file of students for a dating
//program in the format of 
//"age+height+weight+gender+eye color+ hair color+religion+name"
//then asks the user for a target description and returns the 
//description of the person who best matches the target

import java.io.*;
import java.util.*;
import javax.swing.*;

public class Match
{
	public static void main(String[]args)
	throws IOException
	{
		String file;
		printHeadings();
		//calls method to get user input file
		file = getFileName();
		
		//initializes list of potential dates
		Description [] dates = initList(file);
		printArray(dates);
		//asks user if they would like to find a date
		String more = keepGoing();
		
		//while user wants to continue
		while(more.equalsIgnoreCase("y"))
		{
			//get description of ideal match
			Description target = getTarget();
			//search array for matches
			Description idealMatch =getMatch(dates, target);
			//print the description of what they were seeking,
			//the description of the match and how many attributes matched
			printMatch(target, idealMatch);
			more=keepGoing();
		}
		
		printExitMessage();
	}
	
	//prints a welcome message
	public static void printHeadings()
	{
		System.out.println("Hello! Welcome to MWSU's new date matching program.");
		
	}
	
	//asks user if they would like to continue finding dates
	public static String keepGoing()
	{
		String goOn = JOptionPane.showInputDialog
			("Would you like to find a date? Press 'y' or 'n'");
			
		return goOn;
	}
	
	//returns file name provided by user
	public static String getFileName()
	{
		String file= JOptionPane.showInputDialog("Please enter the input file. \n");
		
		return file;
	}
		
	//reads file and puts descriptions in array list	
	public static Description [] initList(String fileName)
	throws IOException
	{
		
		String line;
		String [] input;
		String gender;
		String hair;
		String eye;
		String rel;
		ArrayList <Description> people = new ArrayList<Description>();
		BufferedReader in = new BufferedReader(new FileReader(fileName));
		//until end of file
		while((line = in.readLine())!=null)
		{
			//splits line on white space
			input = line.split(" ", 5);
			//separates the line into appropriate pieces to call Description method
			int age = Integer.parseInt(input[0]);
			int height = Integer.parseInt(input[1]);
			int weight = Integer.parseInt(input[2]);
			gender = (input[3].charAt(0)) + "";
			hair = (input[3].charAt(1)) + "";
			eye = (input[3].charAt(2)) + "";
			rel = (input[3].charAt(3)) + "";
			
			//makes new Description object for each line
			Description d = new Description(age, height, weight, gender, hair, eye, rel, input[4]);
			//adds person to the array list
			people.add(d);
			
		
		}
		
		int k = people.size();
		
		Description [] list = new Description [k];
		//creates an array of people from the file
		people.toArray(list);
		//sorts file based on last name
		Arrays.sort(list);
		
		return list;
		
	}
	
	public static void printArray(Description [] potentials)
	{
		System.out.println("\n     Potential Dates:     \n");
		
		int m = potentials.length;
		
		//prints the list of people in the database
		for(int i=0;i<m;i++)
		{
			String s = potentials[i].toString();
			System.out.println(s);
		}
		
	}
	
	//gets target person description and returns to the calling method
	public static Description getTarget()
	{
		System.out.println("\nLet's find you a date!");
		
		//gets ideal gender
		String sex = JOptionPane.showInputDialog
			("First, please enter 'm' if you are seeking a male or 'f' for seeking a female");
		
		//gets age, height, weight of ideal person and casts to an integer
		String x = JOptionPane.showInputDialog("Please enter an ideal age.");
		int age = Integer.parseInt(x);
		x = JOptionPane.showInputDialog("Please enter an ideal height in inches.");
		int height = Integer.parseInt(x);
		x = JOptionPane.showInputDialog("Please enter an ideal weight in pounds.");
		int weight = Integer.parseInt(x);
		
		//gets eye color, hair color, and religion of ideal date
		String eye = JOptionPane.showInputDialog
			("Please enter 'R' for brown eyes, 'B' for blue eyes, or 'G' for green eyes.");
		String hair = JOptionPane.showInputDialog
			("Please enter 'r' for brown hair, 'y' for blonde hair, or 'b' for black hair.");
		String religion = JOptionPane.showInputDialog
			("Please enter 'P' for Protestant, 'C' for Catholic, 'J' for Jewish, 'H' for Hindu, or 'M' for Muslim");
			
		//creates new Description for the target description
		Description wanted = new Description(age, height, weight, sex, eye, hair, religion, " ");
		
		return wanted;
	}
		
	//searches the array for the person with the most attributes matching the target
	//in the case of a tie, this method prints the match that comes first
	//in alphabetical order of last name
	public static Description getMatch(Description [] dates, Description ideal)
	{
		int x=0;
		int maxMatches = 0;
		Description idealDate = new Description();
		//for each person in the array of potentials, call match function
		//to see the number of matching attributes
		for(Description d : dates)
		{
			x= d.match(ideal);
			
			//finds maximum number of matching attributes
			if(x>maxMatches)
			{
				maxMatches = x;
				idealDate = d;
			}
		}
		
		return idealDate;
		
	}
		
	public static void printMatch(Description seeking, Description idealDate)
	{
		
		String target = seeking.toString();
		String bestDate = idealDate.toString();
		
		//prints what the person was searching for, who their best match is
		//and how many attributes matched
		System.out.println("You were looking for: " + target);
		System.out.println("Your ideal date is: " + bestDate);
		System.out.println("With " + seeking.match(idealDate) + " matching attributes");
	}
	
	//prints exit message to the screen
	public static void printExitMessage()
	{
		System.out.println("\nThank you for using MWSU's new date matching program. Good luck!");
	}
}
