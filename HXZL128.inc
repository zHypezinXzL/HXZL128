/* * * * * * * * * * * *( HXZL128 )* * * * * * * * * * * *\
 *                                                       *
 *         (C) Copyright 2022 by zHypezinXzL (R)         *
 *                                                       *
 *  @country  : Brasil                                   *
 *  @author   : zHypezinXzL                              *
 *  @github   : https://github.com/zHypezinXzL           *
 *  @date     : 12th October 2022                        *
 *                               			 			 *
 *               prevent information theft               *
 *                               			 	 		 *
\* * * * * * * * * * * *( HXZL128 )* * * * * * * * * * * */



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#if defined _HXZL128_included
    #endinput
#endif
#define _HXZL128_included
#pragma library HXZL128
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define ENCRIPT_MIN_LINE (128)
#define ENCRIPT_MAX_LINE (256)
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
stock HXZL128_FormatEncript() return random(10);
stock HXZL128_RemoveWarnings()
{
    CompileEncript(-1, "HXZL");
    ConvertEncript("HXZL");
    RandomCharacter(-1, -1);
}
/*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*/
stock HXZL128_StrEncript(additional, const encript[])
{
    new fstr[ENCRIPT_MAX_LINE], rstr[ENCRIPT_MAX_LINE]; 
    if(strlen(encript) > ENCRIPT_MIN_LINE) return rstr;

    format(fstr, sizeof fstr, "%s", ConvertEncript(CompileEncript(additional, encript)));
    SHA256_PassHash(fstr, "", rstr, strlen(fstr));
    return rstr;
}  
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
CompileEncript(additional, const encript[])
{
    new rstr[ENCRIPT_MAX_LINE]; format(rstr, sizeof rstr, "%s", encript);
    strins(rstr, RandomCharacter(0, additional), 0, sizeof rstr);
    for(new l=1; l < (strlen(encript)*2-1); l+=2) strins(rstr, RandomCharacter(l, additional), (l+1), sizeof rstr);
    return rstr;
}
ConvertEncript(const encript[])
{
    new rstr[ENCRIPT_MAX_LINE];
    strmid(rstr, encript, 0, strlen(encript), sizeof rstr);
    for(new l; l < strlen(encript); l++)
    {
        if     (rstr[l] == 'a') rstr[l] = 'H'; else if(rstr[l] == 'H') rstr[l] = 'a'; else if(rstr[l] == 'A') rstr[l] = 'j'; else if(rstr[l] == 'j') rstr[l] = 'A';
        else if(rstr[l] == 'd') rstr[l] = 'C'; else if(rstr[l] == 'C') rstr[l] = 'd'; else if(rstr[l] == 'D') rstr[l] = 'c'; else if(rstr[l] == 'c') rstr[l] = 'D';
        else if(rstr[l] == 'e') rstr[l] = 'F'; else if(rstr[l] == 'F') rstr[l] = 'e'; else if(rstr[l] == 'E') rstr[l] = 'f'; else if(rstr[l] == 'f') rstr[l] = 'E';
        else if(rstr[l] == 'f') rstr[l] = 'G'; else if(rstr[l] == 'G') rstr[l] = 'f'; else if(rstr[l] == 'T') rstr[l] = 'g'; else if(rstr[l] == 'g') rstr[l] = 'T';
        else if(rstr[l] == 'h') rstr[l] = 'I'; else if(rstr[l] == 'I') rstr[l] = 'h'; else if(rstr[l] == 'B') rstr[l] = 'i'; else if(rstr[l] == 'i') rstr[l] = 'B';
        else if(rstr[l] == 'b') rstr[l] = 'M'; else if(rstr[l] == 'M') rstr[l] = 'b'; else if(rstr[l] == 'J') rstr[l] = 'k'; else if(rstr[l] == 'k') rstr[l] = 'J';
        else if(rstr[l] == 'l') rstr[l] = 'K'; else if(rstr[l] == 'K') rstr[l] = 'l'; else if(rstr[l] == 'L') rstr[l] = 'v'; else if(rstr[l] == 'v') rstr[l] = 'L';
        else if(rstr[l] == 'n') rstr[l] = 'Q'; else if(rstr[l] == 'Q') rstr[l] = 'n'; else if(rstr[l] == 'X') rstr[l] = 'q'; else if(rstr[l] == 'q') rstr[l] = 'X';
        else if(rstr[l] == 'r') rstr[l] = 'S'; else if(rstr[l] == 'S') rstr[l] = 'r'; else if(rstr[l] == 'R') rstr[l] = 'z'; else if(rstr[l] == 'z') rstr[l] = 'R';
        else if(rstr[l] == 't') rstr[l] = 'U'; else if(rstr[l] == 'U') rstr[l] = 't'; else if(rstr[l] == 'T') rstr[l] = 'u'; else if(rstr[l] == 'u') rstr[l] = 'T';
        else if(rstr[l] == 'm') rstr[l] = 'W'; else if(rstr[l] == 'W') rstr[l] = 'm'; else if(rstr[l] == 'V') rstr[l] = 'w'; else if(rstr[l] == 'w') rstr[l] = 'V';
        else if(rstr[l] == 'x') rstr[l] = 'Y'; else if(rstr[l] == 'Y') rstr[l] = 'x'; else if(rstr[l] == 'N') rstr[l] = 'y'; else if(rstr[l] == 'y') rstr[l] = 'N';
        else if(rstr[l] == 's') rstr[l] = 'P'; else if(rstr[l] == 'P') rstr[l] = 's'; else if(rstr[l] == 'Z') rstr[l] = 'p'; else if(rstr[l] == 'p') rstr[l] = 'Z';
        else if(rstr[l] == '0') rstr[l] = '9'; else if(rstr[l] == '9') rstr[l] = '0'; else if(rstr[l] == '1') rstr[l] = '8'; else if(rstr[l] == '8') rstr[l] = '1';
        else if(rstr[l] == '2') rstr[l] = '7'; else if(rstr[l] == '7') rstr[l] = '2'; else if(rstr[l] == '3') rstr[l] = '6'; else if(rstr[l] == '6') rstr[l] = '3';
        else if(rstr[l] == '4') rstr[l] = '5'; else if(rstr[l] == '5') rstr[l] = '4';
        else if(rstr[l] == '!') rstr[l] = '*'; else if(rstr[l] == '*') rstr[l] = '!'; else if(rstr[l] == '@') rstr[l] = '&'; else if(rstr[l] == '&') rstr[l] = '@';
        else if(rstr[l] == '#') rstr[l] = '$'; else if(rstr[l] == '$') rstr[l] = '#'; else if(rstr[l] == '+') rstr[l] = '-'; else if(rstr[l] == '-') rstr[l] = '+';
        else if(rstr[l] == '|') rstr[l] = '?'; else if(rstr[l] == '?') rstr[l] = '|'; else if(rstr[l] == '/') rstr[l] = '%'; else if(rstr[l] == '%') rstr[l] = '/';
    }
    return rstr; 
}
RandomCharacter(number, additional)
{
    new rstr[2];
    if(number > 54) number -= additional;
    else if(number > 64) number = (number/2);
    else number += additional;

    if     (number == 0) rstr = "a"; else if(number == 1) rstr = "b"; else if(number == 2) rstr = "&"; else if(number == 3) rstr = "d";
    else if(number == 4) rstr = "$"; else if(number == 5) rstr = "V"; else if(number == 6) rstr = "g"; else if(number == 7) rstr = "h";
    else if(number == 8) rstr = "i"; else if(number == 9) rstr = "j"; else if(number == 10) rstr = "k"; else if(number == 11) rstr = "T";
    else if(number == 12) rstr = "m"; else if(number == 13) rstr = "n"; else if(number == 14) rstr = "X"; else if(number == 15) rstr = "p";
    else if(number == 16) rstr = "q"; else if(number == 17) rstr = "%"; else if(number == 18) rstr = "s"; else if(number == 19) rstr = "t";
    else if(number == 20) rstr = "u"; else if(number == 21) rstr = "v"; else if(number == 22) rstr = "w"; else if(number == 23) rstr = "z";
    else if(number == 24) rstr = "y"; else if(number == 25) rstr = "U"; else if(number == 26) rstr = "A"; else if(number == 27) rstr = "B";
    else if(number == 28) rstr = "C"; else if(number == 29) rstr = "D"; else if(number == 30) rstr = "%"; else if(number == 31) rstr = "F";
    else if(number == 32) rstr = "G"; else if(number == 33) rstr = "H"; else if(number == 34) rstr = "I"; else if(number == 35) rstr = "J";
    else if(number == 36) rstr = "K"; else if(number == 37) rstr = "L"; else if(number == 38) rstr = "M"; else if(number == 39) rstr = "/";
    else if(number == 40) rstr = "O"; else if(number == 41) rstr = "P"; else if(number == 42) rstr = "|"; else if(number == 43) rstr = "!";
    else if(number == 44) rstr = "_"; else if(number == 45) rstr = "+"; else if(number == 46) rstr = "-"; else if(number == 47) rstr = ":";
    else if(number == 48) rstr = ";"; else if(number == 49) rstr = "*"; else if(number == 50) rstr = "<"; else if(number == 51) rstr = ">";
    else if(number == 52) rstr = "0"; else if(number == 53) rstr = "1"; else if(number == 54) rstr = "2"; else if(number == 55) rstr = "3";
    else if(number == 56) rstr = "4"; else if(number == 57) rstr = "5"; else if(number == 58) rstr = "6"; else if(number == 59) rstr = "7";
    else if(number == 60) rstr = "8"; else if(number == 61) rstr = "9"; else if(number == 62) rstr = "!"; else if(number == 63) rstr = "|"; 
    else if(number == 64) rstr = "?";
    return rstr;
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * /
native <--=[F]=-->
native HXZL128_FormatEncript();

native <--=[R]=-->
native HXZL128_RemoveWarnings();

native <--=[S]=-->
native HXZL128_StrEncript(additional, const encript[]);
/ * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
