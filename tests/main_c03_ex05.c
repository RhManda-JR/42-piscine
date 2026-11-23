#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

/* Implementation de reference (BSD) : strlcat n'existe pas sous Windows */
unsigned int	ref_strlcat(char *dst, const char *src, unsigned int siz)
{
	char		*d = dst;
	const char	*s = src;
	unsigned int	n = siz;
	unsigned int	dlen;

	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;
	if (n == 0)
		return (dlen + strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}

void	test(char *dest, char *src, unsigned int size)
{
	char			a[50];
	char			b[50];
	unsigned int	ra;
	unsigned int	rb;

	memset(a, 'X', 50);
	memset(b, 'X', 50);
	strcpy(a, dest);
	strcpy(b, dest);
	ra = ft_strlcat(a, src, size);
	rb = ref_strlcat(b, src, size);
	printf("%s  dest=\"%s\" src=\"%s\" size=%u -> ret=%u dest=\"%s\"\n",
		(ra == rb && memcmp(a, b, 50) == 0) ? "OK" : "KO",
		dest, src, size, ra, a);
}

int	main(void)
{
	test("Hello ", "World", 20);
	test("Hello ", "World", 12);
	test("Hello ", "World", 9);
	test("Hello ", "World", 7);
	test("Hello ", "World", 6);
	test("Hello ", "World", 3);
	test("Hello ", "World", 0);
	test("", "World", 3);
	test("", "", 1);
	test("Hello", "", 10);
	return (0);
}
