#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

char* S_Substr(char* Str, int From, int To) {
	char* Result = (char*) malloc(sizeof(char) * (To-From+1));
	
	int Index;
	int ResultIndex = 0;
	for (Index = From; Index <= To; Index++, ResultIndex++) {
		Result[ResultIndex] = Str[Index];
	}
	
	Result[ResultIndex] = '\0';
	
	return Result;
}

char* S_SubstrBetween(char* Str, char* Start, char* End, int MatchCase) {
	int StartIndex = S_IndexOf(Start, Str, MatchCase);
	if (StartIndex == -1)
		return NULL;
	
	StartIndex += strlen(Start);
	
	int EndIndex = S_IndexOf(End, Str, MatchCase);
	if (EndIndex == -1)
		return NULL;
		
	return S_Substr(Str, StartIndex, EndIndex - 1);
}

int S_IndexOf(char* Part, char* Str, int MatchCase) {
	char* WorkOn = Str;
	char* PartWorkOn = Part;
	
	if (MatchCase) {
		WorkOn = S_ToLower(Str);
		PartWorkOn = S_ToLower(Part);
	}
	
	int Start, End;
	for (Start = 0, End = strlen(PartWorkOn) - 1; End <= strlen(WorkOn); Start++, End++) {
		char* CurrentPart = S_Substr(WorkOn, Start, End);
		
		if (strcmp(CurrentPart, PartWorkOn) == 0) {
			free(CurrentPart);
			return Start;
		}
		
		free(CurrentPart);
	}
	
	if (MatchCase) {
		free(WorkOn);
		free(PartWorkOn);
	}
	
	return -1;
}

char* S_Concat(char* Glue, int Parts, ...) {
	va_list Args;
	va_start(Args, Parts);
	
	char* Result;
	
	int GlueLength = strlen(Glue);
	
	int Current;
	for (Current = 0; Current < Parts; Current++) {
		char* CurrentPart = va_arg(Args, char*);
		
		if (Current == 0) {
			Result = (char*) malloc(sizeof(char) * (strlen(CurrentPart) + 1));
			Result[0] = '\0';
			strcat(Result, CurrentPart);
		}
		else {
			int Bytes = strlen(Result) + strlen(CurrentPart) + 1;
		
			if (Current -1 != Parts)
				Bytes += GlueLength;
		
			Result = (char*) realloc(Result, sizeof(char) * Bytes);
			
			if (Current -1 != Parts)
				strcat(Result, Glue);
			
			strcat(Result, CurrentPart);
		}
	}
	
	va_end(Args);
	return Result;
}

char* S_ToLower(char* Str) {
	char* Result = S_Clone(Str);
	
	int Index;
	for (Index = 0; Index < strlen(Result); Index++) {
		if (isupper(Result[Index])) {
			Result[Index] = tolower(Result[Index]);
		}
	}
	
	return Result;
}

char* S_ToUpper(char* Str) {
	char* Result = S_Clone(Str);
	
	int Index;
	for (Index = 0; Index < strlen(Result); Index++) {
		if (islower(Result[Index])) {
			Result[Index] = toupper(Result[Index]);
		}
	}
	
	return Result;
}

char* S_InvertCase(char* Str) {
	char* Result = S_Clone(Str);
	
	int Index;
	for (Index = 0; Index < strlen(Result); Index++) {
		if (islower(Result[Index])) {
			Result[Index] = toupper(Result[Index]);
		}
		else if (isupper(Result[Index])) {
			Result[Index] = tolower(Result[Index]);
		}
	}
	
	return Result;
}

char* S_Clone(char* Str) {
	char* Result = (char*) malloc(sizeof(char) * (strlen(Str) + 1));
	
	strcpy(Result, Str);
	
	return Result;
}