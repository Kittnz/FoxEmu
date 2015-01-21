#include "../src/shared/Stdafx.h"

/** Functions made by Intline9 **/
unsigned int getHash(const char *str)
{
	unsigned int hash = 0;
	unsigned int mask = 0xF0000000;
	for(unsigned int i = 0; i < strlen(str); i++)
	{
		hash = tolower(str[i]) + (0x10 * hash);
		if(hash & mask)
			hash ^= hash & mask ^ ((hash & mask) >> 24);
	}
	return hash;
}

/** Functions made by Intline9 **/
unsigned int getCharacterHash(char *szName, unsigned int nSkin) {
    char szSkin[32];
    sprintf(szSkin, "%02d", nSkin);
    unsigned int hash = 0;
    const char *gobj = "[Particle]";
    for(unsigned int i = 0; i < strlen(gobj); i++) {
        hash = tolower(gobj[i]) + (0x1003F * hash);
    }
    for(unsigned int i = 0; i < strlen(szName); i++) {
        hash = tolower(szName[i]) + (0x1003F * hash);
    }
    /*for(unsigned int i = 0; i < strlen(szSkin); i++) {
        hash = tolower(szSkin[i]) + (0x1003F * hash);
    }*/
    return hash;
}

int main(int argc, char **argv)
{
      if (argc < 2) {
    fprintf(stderr, "Usage: %s spell name(for example SummonerRevive)\n", argv[0]);
    return 1;
  }



  fprintf(stderr,"%08X ; %08X\n", getHash(argv[1]), getCharacterHash(argv[1], 0));
}
