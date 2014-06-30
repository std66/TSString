#ifndef _TSString_h_
#define _TSString_h_

char* S_Substr(char* Str, int From, int To);
char* S_SubstrBetween(char* Str, char* Start, char* End, int MatchCase);
int S_IndexOf(char* Part, char* Str, int MatchCase);

char* S_ToLower(char* Str);
char* S_ToUpper(char* Str);
char* S_InvertCase(char* Str);

char* S_Clone(char* Str);

char* S_Concat(char* Glue, int Parts, ...);

#endif