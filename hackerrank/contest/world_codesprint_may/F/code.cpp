#include <iostream>
#include<cstring>
#define NEWLINE '\n'
using namespace std;
 
 
 
 
string rightPart(string s)
 {
   if( s== "(" ) return ")";
   else  if( s == "{") return  "}";
   else return "]";
 }
 
// Print parentesis with proirity 
void allParentesisPriority(string leftstack,string temp,int n1,int n2,int n3)
{
  if(n1 == 0 && n2 == 0  && n3 == 0 && leftstack.length() == 0)
     {
       cout<<temp<<NEWLINE;
       return;
     }
    if(n1>0)
      {
         allParentesisPriority("(" + leftstack,temp+"(",n1-1,n2,n3);
         if(n2>0)
           {
             allParentesisPriority("{"+leftstack,temp+"{",n1,n2-1,n3);
             if(n3>0)
               {
                 allParentesisPriority("["+leftstack,temp+"[",n1,n2,n3-1);
               }
           }
      }
    if(leftstack.length())
      allParentesisPriority(leftstack.substr(1),temp+ rightPart(leftstack.substr(0,1)),n1,n2,n3);
 
}
// 
 
 
//print parenthesis without priority
 void allParentesis( string leftStack,string temp,int n1,int n2,int n3)
 {
    if(leftStack.length() == 0 && n1==0 && n2==0 && n3 ==0)
       {
         cout<<temp<<NEWLINE;
         return;
       }
       if(n1>0)
         allParentesis("("+leftStack,temp+"(",n1-1,n2,n3);
       if(n2>0)
         allParentesis("{" + leftStack,temp +"{",n1,n2-1,n3 );
       if(n3>0)
         allParentesis("["+leftStack,temp+"[",n1,n2,n3-1);
       if(leftStack.length()>0)
          allParentesis(leftStack.substr(1), temp + rightPart(leftStack.substr(0,1)) ,n1,n2,n3);
 }
 
 
 
//normal printing
void Parenthesis(string left,string temp,int n )
{
  if(n== 0 && left.length() ==0)
    {
//     result.push_back(temp);
     cout<<temp<<NEWLINE;
     return ;
    }
  else
    {
      if(n>0)
        Parenthesis( "(" + left ,temp +"(",n-1);
      if(left.length()>0)
        Parenthesis(left.substr(1),temp + ")",n);
 
    }
}
 
 
void countPArenthesis()
{
 int n = 3;
 
 int n1 = 1;
 int n2 = 1;
 int n3 = 1;
 
 Parenthesis("","",n);
 
 //allParentesis("","",n1,n2,n3);
 //cout<<"With Priority "<<NEWLINE;
 //cout<<"END"<<NEWLINE;
 
}
 
int main() {
	// your code goes here
   allParentesisPriority("","",10,2,0);
	// countPArenthesis();
	return 0;
}