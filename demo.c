#include "TSString.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	//Prints "teszt"
	puts("S_Substr example");
	puts(S_Substr("Ez egy teszt szoveg", 7, 12));
	
	//Prints "Ez egy teszt szoveg"
	puts("\nS_SubstrBetween example");
	puts(S_SubstrBetween("Valami szoveg <demo>Ez egy teszt szoveg</demo>", "<demo>", "</demo>", 0));
	
	//Prints "7"
	printf("\nS_IndexOf example\n%d\n", S_IndexOf("proba", "Valami proba szoveg", 0));
	
	//Prints "fsddsfgsggrf"
	puts("\nS_ToLower example");
	puts(S_ToLower("fsdDSFGSggrf"));
	
	//Prints "FSDDSFGSGGRF"
	puts("\nS_ToUpper example");
	puts(S_ToUpper("fsdDSFGSggrf"));
	
	//Prints "FSDdsfgsGGRF"
	puts("\nS_InvertCase example");
	puts(S_InvertCase("fsdDSFGSggrf"));
	
	//Prints "Ez egy teszt szoveg"
	char* Str = "Ez egy teszt szoveg";
	char* StrCopy = S_Clone(Str);
	
	puts("\nS_Clone example");
	puts(StrCopy);
	
	//Prints "Alma, Korte, Barack, Dinnye"
	puts("\nS_Concat example");
	puts(S_Concat(", ", 4, "Alma", "Korte", "Barack", "Dinnye"));

	printf("\nPress [ENTER] to exit...");
	getchar();
	
	return 0;
}