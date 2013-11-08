//Danielle Hubbard
//October 7, 2013
//Contemporary Programming Languages
//This class accepts Descriptions of people 
//with age, height, weight, gender, eye color,
//hair color, religion and name 

class Description implements Comparable<Description>
{
	
	//default constructor
	public Description()
	{
		name = "";
	}
	
	//initialized constructor
	public Description
		(int a, int h, int w, String g, String eye, String hair, String rel, String n)
	{
		name=n;
		age = a;
		height = h;
		weight = w;
		gender = g;
		eyeColor = eye;
		hairColor = hair;
		religion = rel;
	}
	
	//concatenates every aspect of the description into a string
	public String toString()
	{
		String n = age + " " + height + " " + weight + " " + gender + " " + eyeColor 
			+ " " + hairColor + " " + religion + " " + name;
		
		return n;
	}
	
	
	//returns the number of matching attributes the calling Description has with the 
	//Description desired
	public int match(Description seek)
	{
		int count = 0;
		//if gender is not correct, count remains 0
		//else count is the number of matching attributes
		if(gender.equalsIgnoreCase(seek.gender))
		{
			if((age >= (seek.age-1)) && (age <= (seek.age+1)))
			{
				count++;
			}
			if((height >= (seek.height-3)) && (height <= (seek.height+3)))
			{
				count++;
			}
			if((weight >= (seek.weight-10)) && (weight <= (seek.weight+10)))
			{
				count++;
			}
	
			if(eyeColor.equalsIgnoreCase(seek.eyeColor))
			{
				count++;
			}
			if(hairColor.equalsIgnoreCase(seek.hairColor))
			{
				count++;
			}
			if(religion.equalsIgnoreCase(seek.religion))
			{
				count++;
			}
		}
		
		//returns number of matching attributes
		return count;
	}
	
	//allows Descriptions to be sorted by last name
	public int compareTo(Description other)
	{
		int compare = name.compareTo(other.name);
		//this string is lexicographically less than other string
		if(compare < 0)
		{
			return -1;
		}
		//this string is lexiocraphically greater than other string
		else if(compare > 0)
		{
			return 1;
		}
		
		return 0;
	}
	
	private String name;
	private int age;
	private int height;
	private int weight;
	private String gender;
	private String eyeColor;
	private String hairColor;
	private String religion;
}