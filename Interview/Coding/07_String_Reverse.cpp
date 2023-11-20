// https://www.interviewbit.com/c-sharp-interview-questions/

// C # code for last night revision

// 23. Write a program in C# Sharp to reverse a string?


using System;

namespace HelloWorld
{
  class Program
  {
    static void Main(string[] args)
    {
    	// string are imputable .. can not change

     	string str = "Mehedi";
        int start = 0;
        int end = str.Length - 1;

        char[] charArray = new char[str.Length];

        while(start < end)
        {
        	charArray[start] = str[end];
            charArray[end] = str[start];

            start++;
            end--;
        }

        string reverseString = new string(charArray);

        Console.WriteLine(reverseString);
    }
  }
}






// 24. Write a program in C# Sharp to reverse the order of the given words?

internal static void ReverseWordOrder(string str)
{

    // input: how are you?
    // output: you? are how

  int i;
  StringBuilder reverseSentence = new StringBuilder();
   int Start = str.Length - 1;
  int End = str.Length - 1;
   while (Start > 0)
  {
      if (str[Start] == ' ')
      {
          i = Start + 1;
          while (i <= End)
          {
              reverseSentence.Append(str[i]);
              i++;
          }
          reverseSentence.Append(' ');
          End = Start - 1;
      }
      Start--;
  }
   for (i = 0; i <= End; i++)
  {
      reverseSentence.Append(str[i]);
  }
  Console.WriteLine(reverseSentence.ToString());
}



// 26. Write a C# program to find the substring from a given string.

internal static void findallsubstring(string str)
{
   for (int i = 0; i < str.Length; ++i)
   {
       StringBuilder subString = new StringBuilder(str.Length - i);
       for (int j = i; j < str.Length; ++j)
       {
           subString.Append(str[j]);
           Console.Write(subString + " ");
       }
   }
}




