#pragma once

class String {

	char* str;
	
public: //Constructors

	String();
	String(const char* _str);



	~String();

	
	public: //Functions
		
    

	size_t Length();

	const char& CharacterAt(int index);
	
    bool EqualTo(const String& equalStr) const ;

	String& Append(const String& _str);
	String& Prepend(const String& _str);

	size_t Find(const String& _str);
	size_t Find(size_t _startIndex, const String& _str);
	String& Replace(const String& _strFind, const String& _replaceStr );



	const char* CString();
	String& ReadFromConsole();
	String& WriteToConsole();

	String& Uppercase();
	String& Lowercase();
public: // Operators

	bool operator ==(const String& _other);
	bool operator !=(const String& _other);
	bool operator <(const String& _other);

	String& operator=(const String& _other);

	char& operator [](size_t _index);
	const char& operator [](size_t _index) const;


public: // Test functions

	bool TestSetStringNoValue();
	bool TestSetStringValue();

	bool TestLength();
	bool TestCharacterAt();
	bool TestEqualTo();

	bool TestAppend();
	bool TestPrepend();

	bool TestFind();
	bool TestFindWithStartIndex();
	bool TestReplace();

	bool TestCString();
	//bool TestReadFromConsole();
	bool TestWriteToConsole();

	bool TestUppercase();
	bool TestLowercase();


public: //test operators

	bool TestOperatorEquals();
	bool TestOperatorNotEquals();
	bool TestOperatorLessThan();
	bool TestOperatorSet();
    
	bool TestOperatorSubscript();

};