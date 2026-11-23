#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	s1[] = "hi, how are you? 42words forty-two; fifty+and+one";
	char	s2[] = "HELLO wORLD, 4AB a-b_c";
	char	s3[] = "";

	printf("[%s]\n", ft_strcapitalize(s1));
	printf("[%s]\n", ft_strcapitalize(s2));
	printf("[%s]\n", ft_strcapitalize(s3));
	return (0);
}
