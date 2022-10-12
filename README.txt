How is include used?  simple:


 Remove Warnings if you are not already using |  HXZL128_StrEncrypt |
 /*
 public OnGameModeInt()
 {
     HXZL128_RemoveWarnings();
     return 1;
 }
 */

 first create a global or personal variable to store a value later on.
 /*
 Global:
 - new Encrypt;

 Guys:
 - new Encrypt[MAX_PLAYERS];
 */

 Now you will save and load this variable:
 /*
 Rescue:

     Global:
     - HYPE_FSetInt("gfile", "Encript", Encrypt);

     Guys:
     - HYPE_FSetInt("pfile", "Encript", Encript[playerid]);

 Loading:

     Global:
     - Encrypt = HYPE_FGetInt("gfile", "Encrypt");

     Guys:
     - Encript[playerid] = HYPE_FGetInt("pfile", "Encript");
 */

 After that we will give a value to this variable
 /*
 Global:
 - Encrypt = HXZL128_FormatEncript();

 Guys:
 - Encript[playerid] = HXZL128_FormatEncript();
 */

 Time to encrypt the desired string:
 /*
 Global:
 - HXZL128_StrEncript(Encript, "string");

 Guys:
 - HXZL128_StrEncript(Encript[playerid], "string");
 */

 Time to check if the two stored strings match each other.
 I will use as an example the callback |  OnDialogResponse |
 /*
 Global:
 - if(!strcmp(HXZL128_StrEncript(Encript, inputtext), HXZL128_StrEncript(Encript, "string"), true))

 Guys:
 - if(!strcmp(HXZL128_StrEncript(Encript[playerid], inputtext), HXZL128_StrEncript(Encript[playerid], "string"), true))
 */

 What happens to the string?  I will give an example with the string |  hypezin |
 /*
 after string |  hypezin |  pass through |  HXZL128_StrEncrypt |

 she will come:
 hhiykpmeXzqzsinn

 if you notice the writing |  hypezin |

 - h [h] i [y] k [p] m [e] X [z] q [z] s [i] n [n]
 - h y p e z z i n

 then passes through another function that replaces the letters to the string |  hypezin |  will come:

 - TIINAZgFQRZR/BUQ

 and finally it goes through a native encryption function |  SHA256_PassHash |  which turns into:

 - 5BE1CE458C82F5D7

 */

 this allows you to avoid some hacking because even with the |  SHA256_PassHash |  have means
 like bruteforce to get the value of an encryption.
