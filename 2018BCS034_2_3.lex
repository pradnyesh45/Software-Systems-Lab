%{
	int postiveno=0; 
	int negtiveno=0; 
	int positivefractions=0; 
	int negativefractions=0; 
%}

%option noyywrap

DIGIT [0-9] 
%% 

\+?{DIGIT}+			 postiveno++; 
-{DIGIT}+			 negtiveno++; 

\+?{DIGIT}*\.{DIGIT}+ positivefractions++; 
-{DIGIT}*\.{DIGIT}+	 negativefractions++; 
. ; 
%% 

int main() 
{ 
	yylex(); 
	printf("\nNo. of positive integers: %d", postiveno); 
	printf("\nNo. of negative integers: %d", negtiveno); 
	printf("\nNo. of positive fractions: %d", positivefractions); 
	printf("\nNo. of negative fractions: %d\n", negativefractions); 
	return 0; 
} 
