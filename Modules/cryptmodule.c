/* cryptmodule.c - by Steve Majewski
 */

#define _XOPEN_SOURCE
#include <unistd.h>

#include "allobjects.h"

#include <sys/types.h>


/* Module crypt */


static object *crypt_crypt(self, args)
	object *self, *args;
{
	char *word, *salt; 

	struct passwd *p;
	if (!getargs(args, "(ss)", &word, &salt)) {
		return NULL;
	}
	return newstringobject( crypt( word, salt ) );

}

static struct methodlist crypt_methods[] = {
	{"crypt",	crypt_crypt},
	{NULL,		NULL}		/* sentinel */
};

void
initcrypt()
{
	initmodule("crypt", crypt_methods);
}
