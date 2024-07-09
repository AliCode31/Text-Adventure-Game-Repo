#include "String.h"
#include <iostream>
#include <cstring>
#include <exception>
#define SIZE_T_MAX ((size_t)-1)


String::String()
{
	//Sets the Sting to "" when not set.
	str = new char[1];
	str[0] = '\0';
}

String::String(const char* _str)
{
	//Sets the Sting to what has been inputed when set.
	int length = strlen(_str) + 1;
	str = new char[length];
	strcpy_s(str, length, _str);
}


String::~String()
{
	//Deletes the string after use. 
	delete[] str;

}

size_t String::Find(const String& _str)
{
	//Checks to see if the chosen string is in the class string



	//Makes a char pointer and sets it to ""
	size_t _strLength = strlen(_str.str) +1;
	char* tempStr = new char[_strLength];
	tempStr[0] = '\0';

	//Transfers the chosen string into a the char pointer. Then turns it into a char array
	for (int i = 0; i < _strLength; i++) {
		tempStr[i] = _str.str[i];	    
	}
 
	
	size_t length = strlen(str) + 1; //legnth of class string

	int a = 0; //Character when founded
	int b = 0; //Index of class string
	int c = 0; //Location of founded string

	bool firstChar = true;
	while (b < length)
	{


		/*Goes through the class string index and check if it does not equal the char pointer array
		  if it does not it will reset it to finding the first char pointer index */
		if (tempStr[a] != str[b])
		{
			firstChar = true;
			b++;
			a = 0;
			if (b >= length) //breaks the loop once it goes through the whole class string index and has not founded the chosen string			             
			{               
				break;
			}
			continue;
		}
		
		/*Once the first character has been founded it will set the location of the first char then check the next char in the index
		  if it equals the second char of chosen string. if it does. Rinse and repeat */

		if (tempStr[a] == str[b]) 
		{
			if (firstChar) 
			{
				firstChar = false;
				c = b;
			}
			a++;
			b++;

			//One all characters have been founded it will return the start location of the chosen string in the class index
			if (a == _strLength -1) 
			{
				return size_t(c);
			}
		}
		
	}
    
	// if the chosen string has not been founded. it will return -1
	delete tempStr;
	return size_t SIZE_T_MAX;
}

size_t String::Find(size_t _startIndex, const String& _str)
{
	//Checks to see if the chosen string is in the class string with the chosen index it starts on



	//Makes a char pointer and sets it to ""
	size_t _strLength = strlen(_str.str) + 1;
	char* tempStr = new char[_strLength];
	tempStr[0] = '\0';

	//Transfers the chosen string into a the char pointer. Then turns it into a char array
	for (int i = 0; i < _strLength; i++) {
		tempStr[i] = _str.str[i];
	}


	
	size_t length = strlen(str) + 1; //legnth of class string

	
	int a = 0; //Character when founded
	int b = _startIndex; //chosen index
	int c = 0; //Location of founded string

	bool firstChar = true;
	while (b < length)
	{

		/*Goes through the class string index and check if it does not equal the char pointer array
		  if it does not it will reset it to finding the first char pointer index */
		if (tempStr[a] != str[b])
		{
			firstChar = true;
			b++;
			a = 0;
			if (b >= length) //breaks the loop once it goes through the whole class string index and has not founded the chosen string
			{
				break;
			}

			
			continue;
		}


		/*Once the first character has been founded it will set the location of the first char then check the next char in the index
		  if it equals the second char of chosen string. if it does. Rinse and repeat */
		if (tempStr[a] == str[b])
		{
			if (firstChar)
			{
				firstChar = false;
				c = b;
			}
			a++;
			b++;

			//One all characters have been founded it will return the start location of the chosen string in the class index
			if (a == _strLength - 1)
			{
				return size_t(c);
			}
		}

	}


	delete tempStr;
	return size_t SIZE_T_MAX;
}

String& String::Replace(const String& _strFind, const String& _replaceStr)
{

	//Replaces all chosen strings with the chosen replace string




	//Makes a char pointer and sets it to ""
	size_t _strLength = strlen(_strFind.str) + 1;
	char* tempStr = new char[_strLength];
	tempStr[0] = '\0';

	//Transfers the chosen string into a the char pointer. Then turns it into a char array
	for (int i = 0; i < _strLength; i++) {
		tempStr[i] = _strFind.str[i];
	}


	size_t length = strlen(str) + 1; //legnth of class string
	

	int a = 0; // Character when founded
	int b = 0; // Index of class string
	int e = 0; // Index of remainder of class string
	int c = 0; // Location of founded string
	int d = 0; // changes to 1 if the chosen string has been founded its trying to replace

	bool firstChar = true;
	
	
	while (b < length)
	{
		//Sets the new length of the class string and sets 2 other lengths that split the class string for the character before the replace string and after
		size_t replaceLength = strlen(_replaceStr.str) + 1;
		size_t newLength = (strlen(str) - _strLength) + replaceLength + 1;
		size_t remainderLength;


		//Replacing string process once the string has been found it once to replace
		if (d > 0)
		{
			e = b + _strLength - 1; //Sets the index of remainder of class string
			remainderLength = (length - e ); // sets the remainder length



			//Sets a temp char pointer  that will get the first part of the class string before the replace string
			char* stepOne = new char[b - 1];
			stepOne[0] = '\0';


			//Sets a temp char pointer that will get the last part of the class string after the replace string
			char* stepThree = new char[remainderLength];
			stepThree[0] = '\0';



			for (int j = 0; j < b; j++) //Temp char pointer 1 gets the characters before the replace string
			{
				stepOne[j] = str[j];
				
				
			}

			

			for (int k = 0; k < remainderLength; k++) //Temp char pointer 2 gets the characters after the replace string
			{
				stepThree[k] = str[e];
				e++;
			}



			//Resets the class string to ""
			str = new char[newLength];
			str[0] = '\0';
			
			
			stepOne[b] = '\0'; //sets char pointer 1 end to nullterminal before the replacing machine.


			//replacing machine
			strcat_s(str, newLength, stepOne); //First the char pointer 1 gets what got reseted of the first part of the class string before the replace part back in 
			strcat_s(str, newLength, _replaceStr.str); //Replacing String goes in second
			strcat_s(str, newLength, stepThree); //Third the pointer 2 gets what got reseted of the 2nd part of the class after the replace part 

			
			

			d--; //stops the replacing string process

			length = newLength; // length now equals the new length

			//deletes the char pointers.
			delete stepThree;

		}

			

		/*Goes through the class string index and check if it does not equal the char pointer array
		  if it does not it will reset it to finding the first char pointer index */
		if (tempStr[a] != str[b])
		{
			firstChar = true;
			b++;
			a = 0;
			if (b >= length) //breaks the loop once it goes through the whole class string index and has not founded the chosen string
			{
				break;
			}
			continue;
		}

		/*Once the first character has been founded it will set the location of the first char then check the next char in the index
		  if it equals the second char of chosen string. if it does. Rinse and repeat */
		if (tempStr[a] == str[b])
		{
			if (firstChar)
			{
				firstChar = false;
				c = b;
			}
			a++;
			b++;

			//One all characters have been founded it then get the starting position of the string then goes into the replacing string process
			if (a == _strLength - 1)
			{
				d++;
				b = c;

			}
		}

	}

	
	delete tempStr;
	
	return *this;
}


//Replace Prototype 1

//String& String::Replace(const String& _strFind, const String& _replaceStr)
//{
//	//Replaces all chosen strings with the chosen replace string
//
//
//	//Makes a char pointer and sets it to ""
//	size_t _strLength = strlen(_strFind.str) + 1;
//	char* tempStr = new char[_strLength];
//	tempStr[0] = '\0';
//
//	//Transfers the chosen string into a the char pointer. Then turns it into a char array
//	for (int i = 0; i < _strLength; i++) {
//		tempStr[i] = _strFind.str[i];
//	}
//
//	
//	size_t length = strlen(str) + 1; //legnth of class string
//	size_t replaceLength = strlen(_replaceStr.str) + 1; //length of chosen replace string
//	
//
//	int a = 0; //Character when founded
//	int b = 0; //Index of class string
//	int c = 0; // Location of founded string
//	int d = 0; // changes to 1 if the chosen string has been founded its trying to replace
//
//	bool firstChar = true;
//	bool setStr = true;
//
//
//	char* tempMainStr = str; //copies everything in the class string before being reseted. 
//	;
//	while (b < length)
//	{
//		
//		if (d > 0) 		
//		{
//			//Replacing string process
//		
//			for (int i = 0; i < replaceLength; i++) //loops through all the characters replacing them. 
//			{
//
//				if (i == replaceLength - 1)
//				{	//once it replaces all strings it resets the class string to ""				
//					str = new char[length];
//					str[0] = '\0';
//
//					strcat_s(str, length, tempMainStr); //class string gets its characters back
//
//					//resets to the finding process after replacing the string to see if there are anymore chosen strings.
//					d--;
//					setStr = false;
//				}
//				//Replacing character by character each index.
//				
//				str[b] = _replaceStr[i];
//				b++;
//
//				size_t length = strlen(str) + 1; // gets the lengthing of the string everytime it replaces.
//
//				if (setStr) 
//				{
//					tempMainStr = str; //temp string copies everything every character replace from class string. 
//				}
//			}
//			//transition period to finding string proccess
//			if (!setStr)
//			{
//				//resets class string to ""
//				str = new char[length];
//				str[0] = '\0';
//
//				strcat_s(str, length, tempMainStr); //class string gets back what got reseted.
//				
//			}
//
//			b = 0;
//			c = 0;
//			setStr = true;
//		}
//
//
//
//		/*Goes through the class string index and check if it does not equal the char pointer array
//		  if it does not it will reset it to finding the first char pointer index */
//		if (tempStr[a] != str[b])
//		{
//			firstChar = true;
//			b++;
//			a = 0; 
//			if (b >= length) //breaks the loop once it goes through the whole class string index and has not founded the chosen string
//			{
//				break;
//			}
//			continue;
//		}
//
//		/*Once the first character has been founded it will set the location of the first char then check the next char in the index
//		  if it equals the second char of chosen string. if it does. Rinse and repeat */
//		if (tempStr[a] == str[b])
//		{
//			if (firstChar)
//			{
//				firstChar = false;
//				c = b;
//			}
//			a++;
//			b++;
//
//			//One all characters have been founded it then get the starting position of the string then goes into the replacing string process
//			if (a == _strLength - 1)
//			{
//				d++;
//				b = c;
//
//			}
//		}
//
//	}
//
//
//	delete tempStr;
//	return *this;
//}  

const char* String::CString()

{
	//Prints the String to the terminal when std::cout
	return str;
}

String& String::ReadFromConsole()
{
	//Waits for "playerinput:" and sets the string
	std::cin >> str;

	return *this;
}

String& String::WriteToConsole()
{
	//Prints the String to the Terminal.
	std::cout << str;

	return *this;
}

String& String::Uppercase()
{
	//Makes the string all Uppercase
	int length = strlen(str) + 1;
	
	_strupr_s(str, length);
	return *this;
}

String& String::Lowercase()
{
	//Makes the string all Lowercase
	int length = strlen(str) + 1;
	_strlwr_s(str, length);
	return *this;
}

size_t String::Length()
{		
	//Gets the length of the string and returns the amount

	return size_t(strlen(str));
}

const char& String::CharacterAt(int index)
{
	return  (str[index]);	
	
}


bool String::EqualTo(const String& equalStr) const
{

	/*Sees if this class string equals the chosen string 
	 its being equaled to. */

	if (strcmp(str, equalStr.str) == 0) {
		return true;
	}
	else {
		return false;
	}

		
}

String& String::Append(const String& _str)
{
	//adds another String onto this string class


	char* tempStr = str; /* Sets a temporarily char that copies everything
	                        in the string class before being reseted */ 


	int length = strlen(_str.str) + strlen(str) + 1; /* Gets the length of both class string and chosen string
	                                                    together, then resets the class string with the new length */
	str = new char[length];
	str[0] = '\0';
	
	
    strcat_s(str, length, tempStr);  //adds the temporarily char that copied everything first
	strcat_s(str, length, _str.str); // adds the chosen string second. 



	return *this;

}

String& String::Prepend(const String& _str)
{
	//adds another String before the string class



	char* tempStr = str; /* Sets a temporarily char that copies everything
	                        in the string class before being reseted */ 



	int length = strlen(_str.str) + strlen(str) + 1; /* Gets the length of both class string and chosen string
	                                                    together, then resets the class string with the new length */

	str = new char[length];
	str[0] = '\0';
	
	
    strcat_s(str, length, _str.str); // adds the chosen string first 
	strcat_s(str, length, tempStr); //adds the temporarily char that copied everything second



	return *this;
}

bool String::operator==(const String& _other)
{
	if (strcmp(str, _other.str) == 0)
		return true;

	else return false;
}

bool String::operator!=(const String& _other)
{
	if (strcmp(str, _other.str) != 0)
		return true;
	return false;
}

bool String::operator<(const String& _other)
{
	/*if (str < _other.str) return true;
	else return false;*/

	if (strcmp(str, _other.str) == -1) {
		return true;
	}
	else false;
}

String& String::operator=(const String& _other)
{
	int length = strlen(_other.str) + 1;
	str = new char[length];
	strcpy_s(str, length, _other.str);


	return *this;
}


char& String::operator[](size_t _index)
{
	
	if (_index > strlen(str) || _index < 0)
		throw std::out_of_range("Out of range");

	else
	return (str)[_index];
}

const char& String::operator[](size_t _index) const
{

	if (_index > strlen(str) || _index < 0)
		throw std::out_of_range("Out of range");

	else
	return str[_index];
}

//======================TEST FUNCTIONS=====================

bool String::TestSetStringNoValue()
{
	
	std::string testOne = "";

	if (testOne == str ) 
	{
		return true;
	}
      
	return false;
}

bool String::TestSetStringValue()
{
	String testOne = "Hello";

	if (testOne == "Hello")
	{
		return true;
	}

	return false;


}

bool String::TestLength()
{
	String testOne = "Abandoning";

     if (testOne.Length() == 10) 
	 {
		 return true;
	 }

	 return false;
}

bool String::TestCharacterAt()
{
	String testOne = "Abandoning";
		char result = testOne.CharacterAt(8);
	 
	if (result == 'n')
	{
		return true;
	}

	return false;
}

bool String::TestEqualTo()
{
	String stringOne = "Hello!";
	String stringTwo = "Hello!";

	if (stringOne.EqualTo(stringTwo)) {
		return true;
	} 

	return false;
}

bool String::TestAppend()
{
	String stringOne ="Hello ";
	String stringTwo = "World!";

	stringOne.Append(stringTwo);

	if (stringOne == "Hello World!") {
		return true;
	}

	
	return false;
}

bool String::TestPrepend()
{
	String stringOne = "World!";
	String stringTwo = "Goodbye ";

	stringOne.Prepend(stringTwo);

	if (stringOne == "Goodbye World!") {
		return true;
	}



	
	return false;
}

bool String::TestFind()
{
	String stringOne = "Hello World!";
	String stringTwo = "World!";
	if (stringOne.Find(stringTwo) == 6) {
		return true;
	}

	return false;
}

bool String::TestFindWithStartIndex()
{

	String stringOne = "Hello World Hello World!";
	String stringTwo = "World";
	if (stringOne.Find(7, stringTwo) == 18) {
		return true;
	}

	return false;
}

bool String::TestReplace()
{
	String stringOne = "Mass Effect Halo Minecraft Persona5 Danganronpa Minecraft Minecraft";
	String stringTwo = "Minecraft";
	String stringThree = "Sekiro";


	stringOne.Replace(stringTwo, stringThree);
	if (stringOne == "Mass Effect Halo Sekiro Persona5 Danganronpa Sekiro Sekiro") 
	{
		return true; 
	}
	return false;
}

bool String::TestCString()
{
	/*String stringOne = "Cstring has been returned\n";
	if (std::cout << stringOne.CString()) 
	{
		return true;
	}*/

	return true;

}

//bool String::TestReadFromConsole()
 //{
//	String stringOne = "";
//
//	stringOne.ReadFromConsole();
//	
//	if (stringOne == "Hello!") {
//		
//		return true;
//
//	}
//
//	return false;
//}

bool String::TestWriteToConsole()
{

	/*String stringOne = "Write to console has been returned\n";
	stringOne.WriteToConsole();*/

	return true;

}

bool String::TestUppercase()
{
	String stringOne = "hello!";
	stringOne.Uppercase();

	if (stringOne == "HELLO!") {
		return true;
	}

	return false;
}

bool String::TestLowercase()
{
	String stringOne = "HELLO!";
	stringOne.Lowercase();

	if (stringOne == "hello!") {
		return true;
	}

	return false;
}

bool String::TestOperatorEquals()
{
	String stringOne = "Hello";
	String stringTwo = "Hello";

	if (stringOne == stringTwo) {
		return true;
	}
	else return false;
}

bool String::TestOperatorNotEquals()
{
	String stringOne = "Hello";
	String stringTwo = "Hello!";

	if (stringOne != stringTwo) {
		return true;
	}
	else return false;
}

bool String::TestOperatorLessThan()
{
	String stringOne = "Hello";
	String stringTwo = "Hello!";

	if (stringOne < stringTwo) {
		return true;
	}
	return false;
}

bool String::TestOperatorSet()
{	
	String stringOne = "Hello";
	String stringTwo = "Hello World!";

	stringOne = stringTwo;

	if (stringOne == "Hello World!") {
		return true;
	}

	return false;
}

bool String::TestOperatorSubscript()
{
	bool testOne = false;
	bool testTwo = false;
	String stringOne = "Hello";
	const String stringTwo = "Hello!";

	char stringOneS = stringOne[3];
	const char stringTwoS = stringTwo[5]  ;

	if (stringOneS == 'l') {
		testOne = true;
	}

	if (stringTwoS == '!') {
		testTwo = true;
	}

	if (testOne && testTwo) {
		return true;
	}

	return false;
}
	





