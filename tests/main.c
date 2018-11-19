#include "../includes/ft_printf.h"
int			main()
{
	// ----- TEST FORMAT ----- //
	//
	// test un seul caractere //
	//
//	printf(" \n");	
//	ft_printf(" \n");	
//	printf("a\n");
//	ft_printf("a\n");

	printf("--- Tests simples ---\n");
	printf("");
	printf("\n");
	ft_printf("");
	printf("\n");
      //
      // test plusieurs caracteres//
      //
	printf("    \n");	
	ft_printf("    \n");	
	printf("abc\n");
	ft_printf("abc\n");
	printf("abc abc \n");	
	ft_printf("abc abc \n");	
	printf("abc\n");
	ft_printf("abc\n");
	printf("--- TEST CONVERSION %%s ---\n\n");
	printf("--- TEST  %%s ---\n\n");
	
	printf ("\033[32;01m%s\033[00m\n", "Jusqu'ici tout va bien");
	ft_printf ("%s\n", "Jusqu'ici tout va bien");
	printf ("\033[32;01m%s\033[00m\n", "034958");
	ft_printf ("%s\n\n", "034958");

	printf("--- TEST %%s avec attributs ---\n\n");

	printf ("\033[32;01m%-s\033[00m\n", "Jusqu'ici tout va bien");
	ft_printf ("%-s\n\n", "Jusqu'ici tout va bien");
	
	printf("--- TEST %%s avec largeur ---\n\n");

	printf ("\033[32;01m%25s\033[00m\n", "Jusqu'ici tout va bien");
	ft_printf ("%25s\n", "Jusqu'ici tout va bien");
	printf ("\033[32;01m%-25s\033[00m\n", "Jusqu'ici tout va bien");
	ft_printf ("%-25s\n\n", "Jusqu'ici tout va bien");

	printf("--- TEST %%s avec precision ---\n\n");

	printf ("\033[32;01m%.5s\033[00m\n", "Jusqu'ici tout va bien");
	ft_printf ("%.5s\n", "Jusqu'ici tout va bien");
	printf ("\033[32;01m%-.5s\033[00m\n", "Jusqu'ici tout va bien");
	ft_printf ("%-.5s\n", "Jusqu'ici tout va bien");
	printf ("\033[32;01m%12.5s\033[00m\n", "Jusqu'ici tout va bien");
	ft_printf ("%12.5s\n", "Jusqu'ici tout va bien");
	printf ("\033[32;01m%-12.5s\033[00m\n", "Jusqu'ici tout va bien");
	ft_printf ("%-12.5s\n\n", "Jusqu'ici tout va bien");

	printf("--- TEST %%s avec modificateurs ---\n\n");

	printf("--- TEST CONVERSION %%c ---\n\n");
	printf("--- TEST  %%c simple ---\n\n");

	printf ("\033[32;01m%c\033[00m\n", 'a');
	ft_printf ("%c\n", 'a');
	printf ("\033[32;01m%c\033[00m\n", ' ');
	ft_printf ("%c\n", ' ');
	printf ("\033[32;01m%c\033[00m\n", '\n');
	ft_printf ("%c\n", '\n');
	printf ("\033[32;01m%c\033[00m\n", '\0');
	ft_printf ("%c\n\n", '\0');

	printf("--- TEST  %%c avec attributs ---\n\n");

	printf ("\033[32;01m%-c\033[00m\n", 'a');
	ft_printf ("%-c\n", 'a');
	printf ("\033[32;01m%-c\033[00m\n", '\0');
	ft_printf ("%-c\n\n", '\0');

	printf("--- TEST  %%c avec largeur ---\n\n");

	printf ("\033[32;01m%12c\033[00m\n", 'a');
	ft_printf ("%12c\n", 'a');
	printf ("\033[32;01m%-12c\033[00m\n", 'a');
	ft_printf ("%-12c\n", 'a');


	printf("--- TEST  %%c avec modificateurs ---\n\n");

	printf ("\033[32;01m%lc\033[00m\n", 'a');
	ft_printf ("%lc\n", 'a');
	printf ("\033[32;01m%-lc\033[00m\n", 'a');
	ft_printf ("%-lc\n", 'a');
	printf ("\033[32;01m%12lc\033[00m\n", 'a');
	ft_printf ("%12lc\n", 'a');
	printf ("\033[32;01m%-12lc\033[00m\n", 'a');
	ft_printf ("%-12lc\n", 'a');

	printf("--- TEST CONVERSION %%C ---\n\n");
	printf("--- TEST  %%C simple ---\n\n");

	printf ("\033[32;01m%C\033[00m\n", 'a');
	ft_printf ("%C\n", 'a');
	printf ("\033[32;01m%C\033[00m\n", ' ');
	ft_printf ("%C\n", ' ');
	printf ("\033[32;01m%C\033[00m\n", '\n');
	ft_printf ("%C\n", '\n');
	printf ("\033[32;01m%C\033[00m\n", '\0');
	ft_printf ("%C\n\n", '\0');

	printf("--- TEST  %%C avec attributs ---\n\n");

	printf ("\033[32;01m%-C\033[00m\n", 'a');
	ft_printf ("%-C\n", 'a');
	printf ("\033[32;01m%-C\033[00m\n", '\0');
	ft_printf ("%-C\n\n", '\0');

	printf("--- TEST  %%C avec largeur ---\n\n");

	printf ("\033[32;01m%12C\033[00m\n", 'a');
	ft_printf ("%12C\n", 'a');
	printf ("\033[32;01m%-12C\033[00m\n", 'a');
	ft_printf ("%-12C\n", 'a');

	printf("--- TEST CONVERSION %%p ---\n\n");
	printf("--- TEST  %%p ---\n\n");

	char	a;
	int		b;

	printf ("\033[32;01m%p\033[00m\n", &a);
	ft_printf ("%p\n", &a);
	printf ("\033[32;01m%p\033[00m\n", &b);
	ft_printf ("%p\n\n", &b);
	
	printf("--- TEST  %%p avec attributs ---\n\n");

	printf ("\033[32;01m%-p\033[00m\n", &a);
	ft_printf ("%-p\n\n", &a);

	printf("--- TEST %%p avec largeur ---\n\n");

	printf ("\033[32;01m%25p\033[00m\n", &a);
	ft_printf ("%25p\n\n", &a);
	printf ("\033[32;01m%-25p\033[00m\n", &a);
	ft_printf ("%-25p\n\n", &a);


	printf("--- TEST CONVERSION %%o ---\n\n");

	printf("--- TEST  %%o positif ---\n\n");

	printf ("\033[32;01m%o\033[00m\n", 34545);
	ft_printf ("%o\n\n", 34545);

	printf("--- TEST  %%o negatif ---\n\n");

	printf ("\033[32;01m%o\033[00m\n", -34545);
	ft_printf ("%o\n\n", -34545);

	printf("--- TEST  %%o positif avec attributs ---\n\n");

	printf ("\033[32;01m%#o\033[00m\n", 34545);
	ft_printf ("%#o\n", 34545);
	printf ("\033[32;01m%0o\033[00m\n", 34545);
	ft_printf ("%0o\n", 34545);
	printf ("\033[32;01m%-o\033[00m\n", 34545);
	ft_printf ("%-o\n", 34545);
	printf ("\033[32;01m%#0o\033[00m\n", 34545);
	ft_printf ("%#0o\n", 34545);
	printf ("\033[32;01m%#-o\033[00m\n", 34545);
	ft_printf ("%#-o\n\n", 34545);

	printf("--- TEST  %%o negatif avec attributs ---\n\n");

	printf ("\033[32;01m%#o\033[00m\n", -34545);
	ft_printf ("%#o\n", -34545);
	printf ("\033[32;01m%0o\033[00m\n", -34545);
	ft_printf ("%0o\n", -34545);
	printf ("\033[32;01m%-o\033[00m\n", -34545);
	ft_printf ("%-o\n", -34545);
	printf ("\033[32;01m%#0o\033[00m\n", -34545);
	ft_printf ("%#0o\n", -34545);
	printf ("\033[32;01m%#-o\033[00m\n", -34545);
	ft_printf ("%#-o\n\n", -34545);

	printf("--- TEST  %%o positif avec largeur ---\n\n");

	printf ("\033[32;01m%34o\033[00m\n", 34545);
	ft_printf ("%34o\n", 34545);
	printf ("\033[32;01m%#34o\033[00m\n", 34545);
	ft_printf ("%#34o\n", 34545);
	printf ("\033[32;01m%034o\033[00m\n", 34545);
	ft_printf ("%034o\n", 34545);
	printf ("\033[32;01m%-34o\033[00m\n", 34545);
	ft_printf ("%-34o\n", 34545);
	printf ("\033[32;01m%#034o\033[00m\n", 34545);
	ft_printf ("%#034o\n", 34545);
	printf ("\033[32;01m%#-34o\033[00m\n", 34545);
	ft_printf ("%#-34o\n\n", 34545);

	printf("--- TEST  %%o negatif avec largeur ---\n\n");

	printf ("\033[32;01m%34o\033[00m\n", -34545);
	ft_printf ("%34o\n", -34545);
	printf ("\033[32;01m%#34o\033[00m\n", -34545);
	ft_printf ("%#34o\n", -34545);
	printf ("\033[32;01m%034o\033[00m\n", -34545);
	ft_printf ("%034o\n", -34545);
	printf ("\033[32;01m%-34o\033[00m\n", -34545);
	ft_printf ("%-34o\n", -34545);
	printf ("\033[32;01m%#034o\033[00m\n", -34545);
	ft_printf ("%#034o\n", -34545);
	printf ("\033[32;01m%#-34o\033[00m\n", -34545);
	ft_printf ("%#-34o\n\n", -34545);

	printf("--- TEST  %%o positif avec modificateurs ---\n\n");
      
      unsigned long		ul;
      unsigned long long	ull;
      unsigned short		us;
      unsigned char		uc;
      uintmax_t		umax;
      size_t			size;

      ul = 34545;
      ull = 34545;
      us = 34545;
      uc = 46;
      umax = 34545;
      size = 34545;
	printf ("\033[32;01m%lo\033[00m\n", ul);
	ft_printf ("%lo\n", ul);
	printf ("\033[32;01m%llo\033[00m\n", ull);
	ft_printf ("%llo\n", ull);
	printf ("\033[32;01m%ho\033[00m\n", us);
	ft_printf ("%ho\n", us);
	printf ("\033[32;01m%hho\033[00m\n", uc);
	ft_printf ("%hho\n", uc);
	printf ("\033[32;01m%jo\033[00m\n", umax);
	ft_printf ("%jo\n", umax);
	printf ("\033[32;01m%zo\033[00m\n", size);
	ft_printf ("%zo\n", size);

	printf("--- TEST CONVERSION %%O ---\n\n");

	printf("--- TEST  %%O positif ---\n\n");

	printf ("\033[32;01m%O\033[00m\n", 34545);
	ft_printf ("%O\n\n", 34545);

	printf("--- TEST  %%O negatif ---\n\n");

	printf ("\033[32;01m%O\033[00m\n", -34545);
	ft_printf ("%O\n\n", -34545);

	printf("--- TEST  %%O positif avec attributs ---\n\n");

	printf ("\033[32;01m%#O\033[00m\n", 34545);
	ft_printf ("%#O\n", 34545);
	printf ("\033[32;01m%0O\033[00m\n", 34545);
	ft_printf ("%0O\n", 34545);
	printf ("\033[32;01m%-O\033[00m\n", 34545);
	ft_printf ("%-O\n", 34545);
	printf ("\033[32;01m%#0O\033[00m\n", 34545);
	ft_printf ("%#0O\n", 34545);
	printf ("\033[32;01m%#-O\033[00m\n", 34545);
	ft_printf ("%#-O\n\n", 34545);

	printf("--- TEST  %%O negatif avec attributs ---\n\n");

	printf ("\033[32;01m%#O\033[00m\n", -34545);
	ft_printf ("%#O\n", -34545);
	printf ("\033[32;01m%0O\033[00m\n", -34545);
	ft_printf ("%0O\n", -34545);
	printf ("\033[32;01m%-O\033[00m\n", -34545);
	ft_printf ("%-O\n", -34545);
	printf ("\033[32;01m%#0O\033[00m\n", -34545);
	ft_printf ("%#0O\n", -34545);
	printf ("\033[32;01m%#-O\033[00m\n", -34545);
	ft_printf ("%#-O\n\n", -34545);

	printf("--- TEST  %%O positif avec largeur ---\n\n");

	printf ("\033[32;01m%34O\033[00m\n", 34545);
	ft_printf ("%34O\n", 34545);
	printf ("\033[32;01m%#34O\033[00m\n", 34545);
	ft_printf ("%#34O\n", 34545);
	printf ("\033[32;01m%034O\033[00m\n", 34545);
	ft_printf ("%034O\n", 34545);
	printf ("\033[32;01m%-34O\033[00m\n", 34545);
	ft_printf ("%-34O\n", 34545);
	printf ("\033[32;01m%#034O\033[00m\n", 34545);
	ft_printf ("%#034O\n", 34545);
	printf ("\033[32;01m%#-34O\033[00m\n", 34545);
	ft_printf ("%#-34O\n\n", 34545);

	printf("--- TEST  %%O negatif avec largeur ---\n\n");

	printf ("\033[32;01m%34O\033[00m\n", -34545);
	ft_printf ("%34O\n", -34545);
	printf ("\033[32;01m%#34O\033[00m\n", -34545);
	ft_printf ("%#34O\n", -34545);
	printf ("\033[32;01m%034O\033[00m\n", -34545);
	ft_printf ("%034O\n", -34545);
	printf ("\033[32;01m%-34O\033[00m\n", -34545);
	ft_printf ("%-34O\n", -34545);
	printf ("\033[32;01m%#034O\033[00m\n", -34545);
	ft_printf ("%#034O\n", -34545);
	printf ("\033[32;01m%#-34O\033[00m\n", -34545);
	ft_printf ("%#-34O\n\n", -34545);

	printf("--- TEST  %%O positif avec modificateurs ---\n\n");
	
	printf ("\033[32;01m%lO\033[00m\n", ul);
	ft_printf ("%lO\n", ul);
	printf ("\033[32;01m%llO\033[00m\n", ull);
	ft_printf ("%llO\n", ull);
	printf ("\033[32;01m%hO\033[00m\n", us);
	ft_printf ("%hO\n", us);
	printf ("\033[32;01m%hhO\033[00m\n", uc);
	ft_printf ("%hhO\n", uc);
	printf ("\033[32;01m%jO\033[00m\n", umax);
	ft_printf ("%jO\n", umax);
	printf ("\033[32;01m%zO\033[00m\n", size);
	ft_printf ("%zO\n", size);
	printf("--- TEST CONVERSION %%u ---\n\n");

	printf("--- TEST  %%u positif ---\n\n");

	printf ("\033[32;01m%u\033[00m\n", 34545);
	ft_printf ("%u\n\n", 34545);

	printf("--- TEST  %%u negatif ---\n\n");

	printf ("\033[32;01m%u\033[00m\n", -34545);
	ft_printf ("%u\n\n", -34545);

	printf("--- TEST  %%u positif avec attributs ---\n\n");

	printf ("\033[32;01m%0u\033[00m\n", 34545);
	ft_printf ("%0u\n\n", 34545);
	printf ("\033[32;01m%-u\033[00m\n", 34545);
	ft_printf ("%-u\n\n", 34545);

	printf("--- TEST  %%u negatif avec attributs ---\n\n");

	printf ("\033[32;01m%0u\033[00m\n", -34545);
	ft_printf ("%0u\n\n", -34545);
	printf ("\033[32;01m%-u\033[00m\n", -34545);
	ft_printf ("%-u\n\n", -34545);

	printf("--- TEST  %%u positif avec largeur ---\n\n");

	printf ("\033[32;01m%34u\033[00m\n", 34545);
	ft_printf ("%34u\n\n", 34545);
	printf ("\033[32;01m%034u\033[00m\n", 34545);
	ft_printf ("%034u\n\n", 34545);
	printf ("\033[32;01m%-34u\033[00m\n", 34545);
	ft_printf ("%-34u\n\n", 34545);

	printf("--- TEST  %%u negatif avec largeur ---\n\n");

	printf ("\033[32;01m%34u\033[00m\n", -34545);
	ft_printf ("%34u\n", -34545);
	printf ("\033[32;01m%034u\033[00m\n", -34545);
	ft_printf ("%034u\n", -34545);
	printf ("\033[32;01m%-34u\033[00m\n", -34545);
	ft_printf ("%-34u\n\n", -34545);

	printf("--- TEST  %%u positif avec modificateurs ---\n\n");

	printf ("\033[32;01m%lu\033[00m\n", ul);
	ft_printf ("%lu\n", ul);
	printf ("\033[32;01m%llu\033[00m\n", ull);
	ft_printf ("%llu\n", ull);
	printf ("\033[32;01m%hu\033[00m\n", us);
	ft_printf ("%hu\n", us);
	printf ("\033[32;01m%hhu\033[00m\n", uc);
	ft_printf ("%hhu\n", uc);
	printf ("\033[32;01m%ju\033[00m\n", umax);
	ft_printf ("%ju\n", umax);
	printf ("\033[32;01m%zu\033[00m\n", size);
	ft_printf ("%zu\n\n", size);

	printf("--- TEST CONVERSION %%U ---\n\n");

	printf("--- TEST  %%U positif ---\n\n");

	printf ("\033[32;01m%U\033[00m\n", 34545);
	ft_printf ("%U\n\n", 34545);

	printf("--- TEST  %%U negatif ---\n\n");

	printf ("\033[32;01m%U\033[00m\n", -34545);
	ft_printf ("%U\n\n", -34545);

	printf("--- TEST  %%U positif avec attributs ---\n\n");

	printf ("\033[32;01m%0U\033[00m\n", 34545);
	ft_printf ("%0U\n\n", 34545);
	printf ("\033[32;01m%-U\033[00m\n", 34545);
	ft_printf ("%-U\n\n", 34545);

	printf("--- TEST  %%U negatif avec attributs ---\n\n");

	printf ("\033[32;01m%0U\033[00m\n", -34545);
	ft_printf ("%0U\n\n", -34545);
	printf ("\033[32;01m%-U\033[00m\n", -34545);
	ft_printf ("%-U\n\n", -34545);

	printf("--- TEST  %%U positif avec largeur ---\n\n");

	printf ("\033[32;01m%34U\033[00m\n", 34545);
	ft_printf ("%34U\n\n", 34545);
	printf ("\033[32;01m%034U\033[00m\n", 34545);
	ft_printf ("%034U\n\n", 34545);
	printf ("\033[32;01m%-34U\033[00m\n", 34545);
	ft_printf ("%-34U\n\n", 34545);

	printf("--- TEST  %%U negatif avec largeur ---\n\n");

	printf ("\033[32;01m%34U\033[00m\n", -34545);
	ft_printf ("%34U\n", -34545);
	printf ("\033[32;01m%034U\033[00m\n", -34545);
	ft_printf ("%034U\n", -34545);
	printf ("\033[32;01m%-34U\033[00m\n", -34545);
	ft_printf ("%-34U\n\n", -34545);

	printf("--- TEST  %%U positif avec modificateurs ---\n\n");

	printf ("\033[32;01m%lU\033[00m\n", ul);
	ft_printf ("%lU\n", ul);
	printf ("\033[32;01m%llU\033[00m\n", ull);
	ft_printf ("%llU\n", ull);
	printf ("\033[32;01m%hU\033[00m\n", us);
	ft_printf ("%hU\n", us);
	printf ("\033[32;01m%hhU\033[00m\n", uc);
	ft_printf ("%hhU\n", uc);
	printf ("\033[32;01m%jU\033[00m\n", umax);
	ft_printf ("%jU\n", umax);
	printf ("\033[32;01m%zU\033[00m\n", size);
	ft_printf ("%zU\n\n", size);

	printf("--- TEST CONVERSION %%x ---\n\n");

	printf("--- TEST  %%x positif ---\n\n");

	printf ("\033[32;01m%x\033[00m\n", 34545);
	ft_printf ("%x\n\n", 34545);

	printf("--- TEST  %%x negatif ---\n\n");

	printf ("\033[32;01m%x\033[00m\n", -34545);
	ft_printf ("%x\n\n", -34545);

	printf("--- TEST  %%x positif avec attributs ---\n\n");

	printf ("\033[32;01m%#x\033[00m\n", 34545);
	ft_printf ("%#x\n", 34545);
	printf ("\033[32;01m%0x\033[00m\n", 34545);
	ft_printf ("%0x\n", 34545);
	printf ("\033[32;01m%-x\033[00m\n", 34545);
	ft_printf ("%-x\n", 34545);
	printf ("\033[32;01m%#0x\033[00m\n", 34545);
	ft_printf ("%#0x\n", 34545);
	printf ("\033[32;01m%#-x\033[00m\n", 34545);
	ft_printf ("%#-x\n\n", 34545);

	printf("--- TEST  %%x negatif avec attributs ---\n\n");

	printf ("\033[32;01m%#x\033[00m\n", -34545);
	ft_printf ("%#x\n", -34545);
	printf ("\033[32;01m%0x\033[00m\n", -34545);
	ft_printf ("%0x\n", -34545);
	printf ("\033[32;01m%-x\033[00m\n", -34545);
	ft_printf ("%-x\n", -34545);
	printf ("\033[32;01m%#0x\033[00m\n", -34545);
	ft_printf ("%#0x\n", -34545);
	printf ("\033[32;01m%#-x\033[00m\n", -34545);
	ft_printf ("%#-x\n\n", -34545);

	printf("--- TEST  %%x positif avec largeur ---\n\n");

	printf ("\033[32;01m%34x\033[00m\n", 34545);
	ft_printf ("%34x\n", 34545);
	printf ("\033[32;01m%#34x\033[00m\n", 34545);
	ft_printf ("%#34x\n", 34545);
	printf ("\033[32;01m%034x\033[00m\n", 34545);
	ft_printf ("%034x\n", 34545);
	printf ("\033[32;01m%-34x\033[00m\n", 34545);
	ft_printf ("%-34x\n", 34545);
	printf ("\033[32;01m%#034x\033[00m\n", 34545);
	ft_printf ("%#034x\n", 34545);
	printf ("\033[32;01m%#-34x\033[00m\n", 34545);
	ft_printf ("%#-34x\n\n", 34545);

	printf("--- TEST  %%x negatif avec largeur ---\n\n");

	printf ("\033[32;01m%34x\033[00m\n", -34545);
	ft_printf ("%34x\n", -34545);
	printf ("\033[32;01m%#34x\033[00m\n", -34545);
	ft_printf ("%#34x\n", -34545);
	printf ("\033[32;01m%034x\033[00m\n", -34545);
	ft_printf ("%034x\n", -34545);
	printf ("\033[32;01m%-34x\033[00m\n", -34545);
	ft_printf ("%-34x\n", -34545);
	printf ("\033[32;01m%#034x\033[00m\n", -34545);
	ft_printf ("%#034x\n", -34545);
	printf ("\033[32;01m%#-34x\033[00m\n", -34545);
	ft_printf ("%#-34x\n\n", -34545);

	printf("--- TEST  %%x positif avec modificateurs ---\n\n");

	printf ("\033[32;01m%lx\033[00m\n", ul);
	ft_printf ("%lx\n", ul);
	printf ("\033[32;01m%llx\033[00m\n", ull);
	ft_printf ("%llx\n", ull);
	printf ("\033[32;01m%hx\033[00m\n", us);
	ft_printf ("%hx\n", us);
	printf ("\033[32;01m%hhx\033[00m\n", uc);
	ft_printf ("%hhx\n", uc);
	printf ("\033[32;01m%jx\033[00m\n", umax);
	ft_printf ("%jx\n", umax);
	printf ("\033[32;01m%zx\033[00m\n", size);
	ft_printf ("%zx\n\n", size);
	printf("--- TEST %%ls ---\n\n");
      
	printf("--- TEST CONVERSION %%X ---\n\n");

	printf("--- TEST  %%X positif ---\n\n");

	printf ("\033[32;01m%X\033[00m\n", 34545);
	ft_printf ("%X\n\n", 34545);

	printf("--- TEST  %%X negatif ---\n\n");

	printf ("\033[32;01m%X\033[00m\n", -34545);
	ft_printf ("%X\n\n", -34545);

	printf("--- TEST  %%X positif avec attributs ---\n\n");

	printf ("\033[32;01m%#X\033[00m\n", 34545);
	ft_printf ("%#X\n", 34545);
	printf ("\033[32;01m%0X\033[00m\n", 34545);
	ft_printf ("%0X\n", 34545);
	printf ("\033[32;01m%-X\033[00m\n", 34545);
	ft_printf ("%-X\n", 34545);
	printf ("\033[32;01m%#0X\033[00m\n", 34545);
	ft_printf ("%#0X\n", 34545);
	printf ("\033[32;01m%#-X\033[00m\n", 34545);
	ft_printf ("%#-X\n\n", 34545);

	printf("--- TEST  %%X negatif avec attributs ---\n\n");

	printf ("\033[32;01m%#X\033[00m\n", -34545);
	ft_printf ("%#X\n", -34545);
	printf ("\033[32;01m%0X\033[00m\n", -34545);
	ft_printf ("%0X\n", -34545);
	printf ("\033[32;01m%-X\033[00m\n", -34545);
	ft_printf ("%-X\n", -34545);
	printf ("\033[32;01m%#0X\033[00m\n", -34545);
	ft_printf ("%#0X\n", -34545);
	printf ("\033[32;01m%#-X\033[00m\n", -34545);
	ft_printf ("%#-X\n\n", -34545);

	printf("--- TEST  %%X positif avec largeur ---\n\n");

	printf ("\033[32;01m%34X\033[00m\n", 34545);
	ft_printf ("%34X\n", 34545);
	printf ("\033[32;01m%#34X\033[00m\n", 34545);
	ft_printf ("%#34X\n", 34545);
	printf ("\033[32;01m%034X\033[00m\n", 34545);
	ft_printf ("%034X\n", 34545);
	printf ("\033[32;01m%-34X\033[00m\n", 34545);
	ft_printf ("%-34X\n", 34545);
	printf ("\033[32;01m%#034X\033[00m\n", 34545);
	ft_printf ("%#034X\n", 34545);
	printf ("\033[32;01m%#-34X\033[00m\n", 34545);
	ft_printf ("%#-34X\n\n", 34545);

	printf("--- TEST  %%X negatif avec largeur ---\n\n");

	printf ("\033[32;01m%34X\033[00m\n", -34545);
	ft_printf ("%34X\n", -34545);
	printf ("\033[32;01m%#34X\033[00m\n", -34545);
	ft_printf ("%#34X\n", -34545);
	printf ("\033[32;01m%034X\033[00m\n", -34545);
	ft_printf ("%034X\n", -34545);
	printf ("\033[32;01m%-34X\033[00m\n", -34545);
	ft_printf ("%-34X\n", -34545);
	printf ("\033[32;01m%#034X\033[00m\n", -34545);
	ft_printf ("%#034X\n", -34545);
	printf ("\033[32;01m%#-34X\033[00m\n", -34545);
	ft_printf ("%#-34X\n\n", -34545);

	printf("--- TEST  %%X positif avec modificateurs ---\n\n");

	printf ("\033[32;01m%lX\033[00m\n", ul);
	ft_printf ("%lX\n", ul);
	printf ("\033[32;01m%llX\033[00m\n", ull);
	ft_printf ("%llX\n", ull);
	printf ("\033[32;01m%hX\033[00m\n", us);
	ft_printf ("%hX\n", us);
	printf ("\033[32;01m%hhX\033[00m\n", uc);
	ft_printf ("%hhX\n", uc);
	printf ("\033[32;01m%jX\033[00m\n", umax);
	ft_printf ("%jX\n", umax);
	printf ("\033[32;01m%zX\033[00m\n", size);
	ft_printf ("%zX\n\n", size);
	printf("--- TEST %%ls ---\n\n");

	setlocale(LC_ALL, "en_US.UTF-8"); 

	printf ("\033[32;01m%ls\033[00m\n", L"Ѡ");
	ft_printf ("%ls\n\n", L"ܐܭܜܞ");

	printf("--- TEST CONVERSION %%d ---\n\n");
	printf("--- TEST %%d positif ---\n\n");
	//
	printf ("\033[32;01m%d\033[00m\n", 12);
	ft_printf ("%d\n\n", 12);

	printf("--- TEST %%d negatif ---\n\n");

	printf ("\033[32;01m%d\033[00m\n", -12);
	ft_printf ("%d\n\n", -12);
	
	printf("--- TEST %%d positif avec attributs ---\n\n");

	printf ("\033[32;01m%0d\033[00m\n", 12);
	ft_printf ("%0d\n", 12);
	printf ("\033[32;01m%-d\033[00m\n", 12);
	ft_printf ("%-d\n", 12);
	printf ("\033[32;01m%+d\033[00m\n", 12);
	ft_printf ("%+d\n", 12);
	printf ("\033[32;01m% d\033[00m\n", 12);
	ft_printf ("% d\n", 12);
	printf ("\033[32;01m%0+d\033[00m\n", 12);
	ft_printf ("%0+d\n", 12);
	printf ("\033[32;01m%0 d\033[00m\n", 12);
	ft_printf ("%0 d\n", 12);
	printf ("\033[32;01m%-+d\033[00m\n", 12);
	ft_printf ("%-+d\n", 12);
	printf ("\033[32;01m%- d\033[00m\n", 12);
	ft_printf ("%- d\n\n", 12);


	printf("--- TEST %%d negatif avec attributs ---\n\n");

	printf ("\033[32;01m%0d\033[00m\n", -12);
	ft_printf ("%0d\n", -12);
	printf ("\033[32;01m%-d\033[00m\n", -12);
	ft_printf ("%-d\n", -12);
	printf ("\033[32;01m%+d\033[00m\n", -12);
	ft_printf ("%+d\n", -12);
	printf ("\033[32;01m% d\033[00m\n", -12);
	ft_printf ("% d\n", -12);
	printf ("\033[32;01m%0+d\033[00m\n", -12);
	ft_printf ("%0+d\n", -12);
	printf ("\033[32;01m%0 d\033[00m\n", -12);
	ft_printf ("%0 d\n", -12);
	printf ("\033[32;01m%-+d\033[00m\n", -12);
	ft_printf ("%-+d\n", -12);
	printf ("\033[32;01m%- d\033[00m\n", -12);
	ft_printf ("%- d\n\n", -12);

	printf("--- TEST %%d positif avec largeur ---\n\n");

	printf ("\033[32;01m%12d\033[00m\n", 12);
	ft_printf ("%12d\n", 12);
	printf ("\033[32;01m%012d\033[00m\n", 12);
	ft_printf ("%012d\n", 12);
	printf ("\033[32;01m%-12d\033[00m\n", 12);
	ft_printf ("%-12d\n", 12);
	printf ("\033[32;01m%+12d\033[00m\n", 12);
	ft_printf ("%+12d\n", 12);
	printf ("\033[32;01m% 12d\033[00m\n", 12);
	ft_printf ("% 12d\n", 12);
	printf ("\033[32;01m%0+12d\033[00m\n", 12);
	ft_printf ("%0+12d\n", 12);
	printf ("\033[32;01m%0 12d\033[00m\n", 12);
	ft_printf ("%0 12d\n", 12);
	printf ("\033[32;01m%-+12d\033[00m\n", 12);
	ft_printf ("%-+12d\n", 12);
	printf ("\033[32;01m%- 12d\033[00m\n", 12);
	ft_printf ("%- 12d\n\n", 12);

	printf("--- TEST %%d negatif avec largeur ---\n\n");

	printf ("\033[32;01m%12d\033[00m\n", -12);
	ft_printf ("%12d\n", -12);
	printf ("\033[32;01m%012d\033[00m\n", -12);
	ft_printf ("%012d\n", -12);
	printf ("\033[32;01m%-12d\033[00m\n", -12);
	ft_printf ("%-12d\n", -12);
	printf ("\033[32;01m%+12d\033[00m\n", -12);
	ft_printf ("%+12d\n", -12);
	printf ("\033[32;01m% 12d\033[00m\n", -12);
	ft_printf ("% 12d\n", -12);
	printf ("\033[32;01m%0+12d\033[00m\n", -12);
	ft_printf ("%0+12d\n", -12);
	printf ("\033[32;01m%0 12d\033[00m\n", -12);
	ft_printf ("%0 12d\n", -12);
	printf ("\033[32;01m%-+12d\033[00m\n", -12);
	ft_printf ("%-+12d\n", -12);
	printf ("\033[32;01m%- 12d\033[00m\n", -12);
	ft_printf ("%- 12d\n\n", -12);

	printf("--- TEST %%d positif avec precision ---\n\n");

	printf ("\033[32;01m%.5d\033[00m\n", 1288888);
	ft_printf ("%.5d\n", 1288888);
	printf ("\033[32;01m%.5d\033[00m\n", 12);
	ft_printf ("%.5d\n", 12);
	printf ("\033[32;01m%0.5d\033[00m\n", 137);
	ft_printf ("%0.5d\n", 137);
	printf ("\033[32;01m%-.5d\033[00m\n", 137);
	ft_printf ("%-.5d\n", 137);
	printf ("\033[32;01m%+.5d\033[00m\n", 137);
	ft_printf ("%+.5d\n", 137);
	printf ("\033[32;01m% .5d\033[00m\n", 137);
	ft_printf ("% .5d\n", 137);
	printf ("\033[32;01m%12.5d\033[00m\n", 137);
	ft_printf ("%12.5d\n", 137);
	printf ("\033[32;01m%012.5d\033[00m\n", 137);
	ft_printf ("%012.5d\n", 137);
	printf ("\033[32;01m%-12.5d\033[00m\n", 137);
	ft_printf ("%-12.5d\n", 137);
	printf ("\033[32;01m%+12.5d\033[00m\n", 137);
	ft_printf ("%+12.5d\n", 137);
	printf ("\033[32;01m% 12.5d\033[00m\n", 137);
	ft_printf ("% 12.5d\n", 137);
	printf ("\033[32;01m%0+12.5d\033[00m\n", 137);
	ft_printf ("%0+12.5d\n", 137);
	printf ("\033[32;01m%0 12.5d\033[00m\n", 137);
	ft_printf ("%0 12.5d\n", 137);
	printf ("\033[32;01m%- 12.5d\033[00m\n", 137);
	ft_printf ("%-+12.5d\n", 137);
	printf ("\033[32;01m%- 12.5d\033[00m\n", 137);
	ft_printf ("%- 12.5d\n\n", 137);


	printf("--- TEST %%d negatif avec precision ---\n\n");

	printf ("\033[32;01m%.5d\033[00m\n", -1288888);
	ft_printf ("%.5d\n", -1288888);
	printf ("\033[32;01m%.5d\033[00m\n", -12);
	ft_printf ("%.5d\n", -12);
	printf ("\033[32;01m%0.5d\033[00m\n", -12);
	ft_printf ("%0.5d\n", -12);
	printf ("\033[32;01m%-.5d\033[00m\n", -12);
	ft_printf ("%-.5d\n", -12);
	printf ("\033[32;01m%+.5d\033[00m\n", -12);
	ft_printf ("%+.5d\n", -12);
	printf ("\033[32;01m% .5d\033[00m\n", -12);
	ft_printf ("% .5d\n", -12);
	printf ("\033[32;01m%12.5d\033[00m\n", -12);
	ft_printf ("%12.5d\n", -12);
	printf ("\033[32;01m%012.5d\033[00m\n", -12);
	ft_printf ("%012.5d\n", -12);
	printf ("\033[32;01m%-12.5d\033[00m\n", -12);
	ft_printf ("%-12.5d\n", -12);
	printf ("\033[32;01m%+12.5d\033[00m\n", -12);
	ft_printf ("%+12.5d\n", -12);
	printf ("\033[32;01m% 12.5d\033[00m\n", -12);
	ft_printf ("% 12.5d\n", -12);
	printf ("\033[32;01m%0+12.5d\033[00m\n", -12);
	ft_printf ("%0+12.5d\n", -12);
	printf ("\033[32;01m%0 12.5d\033[00m\n", -12);
	ft_printf ("%0 12.5d\n", -12);
	printf ("\033[32;01m%- 12.5d\033[00m\n", -12);
	ft_printf ("%-+12.5d\n", -12);
	printf ("\033[32;01m%- 12.5d\033[00m\n", -12);
	ft_printf ("%- 12.5d\n\n", -12);

	printf("--- TEST %%hhd positif ---\n\n");

	unsigned char	c = 126;

	printf ("\033[32;01m%hhd\033[00m\n", c);
	ft_printf ("%hhd\n\n", c);
	
	printf("--- TEST %%hhd negatif ---\n\n");

	c = -126;

	printf ("\033[32;01m%hhd\033[00m\n", c);
	ft_printf ("%hhd\n\n", c);

	printf("--- TEST %%hhd positif avec attributs ---\n\n");
	
	c = 126;

	printf ("\033[32;01m%0hhd\033[00m\n", c);
	ft_printf ("%0hhd\n", c);
	printf ("\033[32;01m%-hhd\033[00m\n", c);
	ft_printf ("%-hhd\n", c);
	printf ("\033[32;01m%+hhd\033[00m\n", c);
	ft_printf ("%+hhd\n", c);
	printf ("\033[32;01m% hhd\033[00m\n", c);
	ft_printf ("% hhd\n", c);
	printf ("\033[32;01m%0+hhd\033[00m\n", c);
	ft_printf ("%0+hhd\n", c);
	printf ("\033[32;01m%0 hhd\033[00m\n", c);
	ft_printf ("%0 hhd\n", c);
	printf ("\033[32;01m%-+hhd\033[00m\n", c);
	ft_printf ("%-+hhd\n", c);
	printf ("\033[32;01m%- hhd\033[00m\n", c);
	ft_printf ("%- hhd\n\n", c);
	
	printf("--- TEST %%hhd negatif avec attributs ---\n\n");
	
	c = -126;

	printf ("\033[32;01m%0hhd\033[00m\n", c);
	ft_printf ("%0hhd\n", c);
	printf ("\033[32;01m%-hhd\033[00m\n", c);
	ft_printf ("%-hhd\n", c);
	printf ("\033[32;01m%+hhd\033[00m\n", c);
	ft_printf ("%+hhd\n", c);
	printf ("\033[32;01m% hhd\033[00m\n", c);
	ft_printf ("% hhd\n", c);
	printf ("\033[32;01m%0+hhd\033[00m\n", c);
	ft_printf ("%0+hhd\n", c);
	printf ("\033[32;01m%0 hhd\033[00m\n", c);
	ft_printf ("%0 hhd\n", c);
	printf ("\033[32;01m%-+hhd\033[00m\n", c);
	ft_printf ("%-+hhd\n", c);
	printf ("\033[32;01m%- hhd\033[00m\n", c);
	ft_printf ("%- hhd\n\n", c);
	
	printf("--- TEST %%hhd positif avec largeur ---\n\n");
	
	c = 126;

	printf ("\033[32;01m%12hhd\033[00m\n", c);
	ft_printf ("%12hhd\n", c);
	printf ("\033[32;01m%012hhd\033[00m\n", c);
	ft_printf ("%012hhd\n", c);
	printf ("\033[32;01m%-12hhd\033[00m\n", c);
	ft_printf ("%-12hhd\n", c);
	printf ("\033[32;01m%+12hhd\033[00m\n", c);
	ft_printf ("%+12hhd\n", c);
	printf ("\033[32;01m% 12hhd\033[00m\n", c);
	ft_printf ("% 12hhd\n", c);
	printf ("\033[32;01m%0+12hhd\033[00m\n", c);
	ft_printf ("%0+12hhd\n", c);
	printf ("\033[32;01m%0 12hhd\033[00m\n", c);
	ft_printf ("%0 12hhd\n", c);
	printf ("\033[32;01m%-+12hhd\033[00m\n", c);
	ft_printf ("%-+12hhd\n", c);
	printf ("\033[32;01m%- 12hhd\033[00m\n", c);
	ft_printf ("%- 12hhd\n\n", c);
	
	printf("--- TEST %%hhd negatif avec largeur ---\n\n");
	
	c = -126;

	printf ("\033[32;01m%012hhd\033[00m\n", c);
	ft_printf ("%012hhd\n", c);
	printf ("\033[32;01m%012hhd\033[00m\n", c);
	ft_printf ("%012hhd\n", c);
	printf ("\033[32;01m%-12hhd\033[00m\n", c);
	ft_printf ("%-12hhd\n", c);
	printf ("\033[32;01m%+12hhd\033[00m\n", c);
	ft_printf ("%+12hhd\n", c);
	printf ("\033[32;01m% 12hhd\033[00m\n", c);
	ft_printf ("% 12hhd\n", c);
	printf ("\033[32;01m%0+12hhd\033[00m\n", c);
	ft_printf ("%0+12hhd\n", c);
	printf ("\033[32;01m%0 12hhd\033[00m\n", c);
	ft_printf ("%0 12hhd\n", c);
	printf ("\033[32;01m%-+12hhd\033[00m\n", c);
	ft_printf ("%-+12hhd\n", c);
	printf ("\033[32;01m%- 12hhd\033[00m\n", c);
	ft_printf ("%- 12hhd\n\n", c);

	printf("--- TEST %%hhd positif avec precision ---\n\n");

	c = 126;
	printf ("\033[32;01m%.5hhd\033[00m\n", c);
	ft_printf ("%.5hhd\n", c);
	printf ("\033[32;01m%.5hhd\033[00m\n", c);
	ft_printf ("%.5hhd\n", c);
	printf ("\033[32;01m%0.5hhd\033[00m\n", c);
	ft_printf ("%0.5hhd\n", c);
	printf ("\033[32;01m%-.5hhd\033[00m\n", c);
	ft_printf ("%-.5hhd\n", c);
	printf ("\033[32;01m%+.5hhd\033[00m\n", c);
	ft_printf ("%+.5hhd\n", c);
	printf ("\033[32;01m% .5hhd\033[00m\n", c);
	ft_printf ("% .5hhd\n", c);
	printf ("\033[32;01m%12.5hhd\033[00m\n", c);
	ft_printf ("%12.5hhd\n", c);
	printf ("\033[32;01m%012.5hhd\033[00m\n", c);
	ft_printf ("%012.5hhd\n", c);
	printf ("\033[32;01m%-12.5hhd\033[00m\n", c);
	ft_printf ("%-12.5hhd\n", c);
	printf ("\033[32;01m%+12.5hhd\033[00m\n", c);
	ft_printf ("%+12.5hhd\n", c);
	printf ("\033[32;01m% 12.5hhd\033[00m\n", c);
	ft_printf ("% 12.5hhd\n", c);
	printf ("\033[32;01m%0+12.5hhd\033[00m\n", c);
	ft_printf ("%0+12.5hhd\n", c);
	printf ("\033[32;01m%0 12.5d\033[00m\n", c);
	ft_printf ("%0 12.5hhd\n", c);
	printf ("\033[32;01m%- 12.5hhd\033[00m\n", c);
	ft_printf ("%-+12.5hhd\n", c);
	printf ("\033[32;01m%- 12.5hhd\033[00m\n", c);
	ft_printf ("%- 12.5hhd\n\n", c);


	printf("--- TEST %%hhd negatif avec precision ---\n\n");

	c = -126;

	printf ("\033[32;01m%.5hhd\033[00m\n", c);
	ft_printf ("%.5hhd\n", c);
	printf ("\033[32;01m%.5hhd\033[00m\n", c);
	ft_printf ("%.5hhd\n", c);
	printf ("\033[32;01m%0.5hhd\033[00m\n", c);
	ft_printf ("%0.5hhd\n", c);
	printf ("\033[32;01m%-.5hhd\033[00m\n", c);
	ft_printf ("%-.5hhd\n", c);
	printf ("\033[32;01m%+.5hhd\033[00m\n", c);
	ft_printf ("%+.5hhd\n", c);
	printf ("\033[32;01m% .5hhd\033[00m\n", c);
	ft_printf ("% .5hhd\n", c);
	printf ("\033[32;01m%12.5hhd\033[00m\n", c);
	ft_printf ("%12.5hhd\n", c);
	printf ("\033[32;01m%012.5hhd\033[00m\n", c);
	ft_printf ("%012.5hhd\n", c);
	printf ("\033[32;01m%-12.5hhd\033[00m\n", c);
	ft_printf ("%-12.5hhd\n", c);
	printf ("\033[32;01m%+12.5hhd\033[00m\n", c);
	ft_printf ("%+12.5hhd\n", c);
	printf ("\033[32;01m% 12.5hhd\033[00m\n", c);
	ft_printf ("% 12.5hhd\n", c);
	printf ("\033[32;01m%0+12.5hhd\033[00m\n", c);
	ft_printf ("%0+12.5hhd\n", c);
	printf ("\033[32;01m%0 12.5hhd\033[00m\n", c);
	ft_printf ("%0 12.5hhd\n", c);
	printf ("\033[32;01m%- 12.5hhd\033[00m\n", c);
	ft_printf ("%-+12.5hhd\n", c);
	printf ("\033[32;01m%- 12.5hhd\033[00m\n", c);
	ft_printf ("%- 12.5hhd\n\n", c);

	printf("--- TEST %%hd positif ---\n\n");

	short			s = 234;

	printf ("\033[32;01m%hd\033[00m\n", s);
	ft_printf ("%hd\n\n", s);
	
	printf("--- TEST %%hd negatif ---\n\n");

	s = -234;

	printf ("\033[32;01m%hd\033[00m\n", s);
	ft_printf ("%hd\n\n", s);

	printf("--- TEST %%hd positif aves attributs ---\n\n");
	
	s = 234;

	printf ("\033[32;01m%0hd\033[00m\n", s);
	ft_printf ("%0hd\n", s);
	printf ("\033[32;01m%-hd\033[00m\n", s);
	ft_printf ("%-hd\n", s);
	printf ("\033[32;01m%+hd\033[00m\n", s);
	ft_printf ("%+hd\n", s);
	printf ("\033[32;01m% hd\033[00m\n", s);
	ft_printf ("% hd\n", s);
	printf ("\033[32;01m%0+hd\033[00m\n", s);
	ft_printf ("%0+hd\n", s);
	printf ("\033[32;01m%0 hd\033[00m\n", s);
	ft_printf ("%0 hd\n", s);
	printf ("\033[32;01m%-+hd\033[00m\n", s);
	ft_printf ("%-+hd\n", s);
	printf ("\033[32;01m%- hd\033[00m\n", s);
	ft_printf ("%- hd\n\n", s);
	
	printf("--- TEST %%hd negatif avec attributs ---\n\n");
	
	s = -234;

	printf ("\033[32;01m%0hd\033[00m\n", s);
	ft_printf ("%0hd\n", s);
	printf ("\033[32;01m%-hd\033[00m\n", s);
	ft_printf ("%-hd\n", s);
	printf ("\033[32;01m%+hd\033[00m\n", s);
	ft_printf ("%+hd\n", s);
	printf ("\033[32;01m% hd\033[00m\n", s);
	ft_printf ("% hd\n", s);
	printf ("\033[32;01m%0+hd\033[00m\n", s);
	ft_printf ("%0+hd\n", s);
	printf ("\033[32;01m%0 hd\033[00m\n", s);
	ft_printf ("%0 hd\n", s);
	printf ("\033[32;01m%-+hd\033[00m\n", s);
	ft_printf ("%-+hd\n", s);
	printf ("\033[32;01m%- hd\033[00m\n", s);
	ft_printf ("%- hd\n\n", s);
	
	printf("--- TEST %%hd positif avec largeur ---\n\n");
	
	s = 234;

	printf ("\033[32;01m%12hd\033[00m\n", s);
	ft_printf ("%12hd\n", s);
	printf ("\033[32;01m%012hd\033[00m\n", s);
	ft_printf ("%0hd\n", s);
	printf ("\033[32;01m%-12hd\033[00m\n", s);
	ft_printf ("%-12hd\n", s);
	printf ("\033[32;01m%+12hd\033[00m\n", s);
	ft_printf ("%+12hd\n", s);
	printf ("\033[32;01m% 12hd\033[00m\n", s);
	ft_printf ("% 12hd\n", s);
	printf ("\033[32;01m%0+12hd\033[00m\n", s);
	ft_printf ("%0+12hd\n", s);
	printf ("\033[32;01m%0 12hd\033[00m\n", s);
	ft_printf ("%0 12hd\n", s);
	printf ("\033[32;01m%-+12hd\033[00m\n", s);
	ft_printf ("%-+12hd\n", s);
	printf ("\033[32;01m%- 12hd\033[00m\n", s);
	ft_printf ("%- 12hd\n\n", s);
	
	printf("--- TEST %%hd negatif avec largeur ---\n\n");
	
	s = -234;

	printf ("\033[32;01m%012hd\033[00m\n", s);
	ft_printf ("%012hd\n", s);
	printf ("\033[32;01m%012hd\033[00m\n", s);
	ft_printf ("%012hd\n", s);
	printf ("\033[32;01m%-12hd\033[00m\n", s);
	ft_printf ("%-12hd\n", s);
	printf ("\033[32;01m%+12hd\033[00m\n", s);
	ft_printf ("%+12hd\n", s);
	printf ("\033[32;01m% 12hd\033[00m\n", s);
	ft_printf ("% 12hd\n", s);
	printf ("\033[32;01m%0+12hd\033[00m\n", s);
	ft_printf ("%0+12hd\n", s);
	printf ("\033[32;01m%0 12hd\033[00m\n", s);
	ft_printf ("%0 12hd\n", s);
	printf ("\033[32;01m%-+12hd\033[00m\n", s);
	ft_printf ("%-+12hd\n", s);
	printf ("\033[32;01m%- 12hd\033[00m\n", s);
	ft_printf ("%- 12hd\n\n", s);

	printf("--- TEST %%hd positif avec precision ---\n\n");

	s = 234;

	printf ("\033[32;01m%.5hd\033[00m\n", s);
	ft_printf ("%.5hd\n", s);
	printf ("\033[32;01m%.5hd\033[00m\n", s);
	ft_printf ("%.5hd\n", s);
	printf ("\033[32;01m%0.5hd\033[00m\n", s);
	ft_printf ("%0.5hd\n", s);
	printf ("\033[32;01m%-.5hd\033[00m\n", s);
	ft_printf ("%-.5hd\n", s);
	printf ("\033[32;01m%+.5hd\033[00m\n", s);
	ft_printf ("%+.5hd\n", s);
	printf ("\033[32;01m% .5hd\033[00m\n", s);
	ft_printf ("% .5hd\n", s);
	printf ("\033[32;01m%12.5hd\033[00m\n", s);
	ft_printf ("%12.5hd\n", s);
	printf ("\033[32;01m%012.5hd\033[00m\n", s);
	ft_printf ("%012.5hd\n", s);
	printf ("\033[32;01m%-12.5hd\033[00m\n", s);
	ft_printf ("%-12.5hd\n", s);
	printf ("\033[32;01m%+12.5hd\033[00m\n", s);
	ft_printf ("%+12.5hd\n", s);
	printf ("\033[32;01m% 12.5hd\033[00m\n", s);
	ft_printf ("% 12.5hd\n", s);
	printf ("\033[32;01m%0+12.5hd\033[00m\n", s);
	ft_printf ("%0+12.5hd\n", s);
	printf ("\033[32;01m%0 12.5d\033[00m\n", s);
	ft_printf ("%0 12.5hd\n", s);
	printf ("\033[32;01m%- 12.5hd\033[00m\n", s);
	ft_printf ("%-+12.5hd\n", s);
	printf ("\033[32;01m%- 12.5hd\033[00m\n", s);
	ft_printf ("%- 12.5hd\n\n", s);


	printf("--- TEST %%hd negatif avec precision ---\n\n");

	s = -234;

	printf ("\033[32;01m%.5hd\033[00m\n", s);
	ft_printf ("%.5hd\n", s);
	printf ("\033[32;01m%.5hd\033[00m\n", s);
	ft_printf ("%.5hd\n", s);
	printf ("\033[32;01m%0.5hd\033[00m\n", s);
	ft_printf ("%0.5hd\n", s);
	printf ("\033[32;01m%-.5hd\033[00m\n", s);
	ft_printf ("%-.5hd\n", s);
	printf ("\033[32;01m%+.5hd\033[00m\n", s);
	ft_printf ("%+.5hd\n", s);
	printf ("\033[32;01m% .5hd\033[00m\n", s);
	ft_printf ("% .5hd\n", s);
	printf ("\033[32;01m%12.5hd\033[00m\n", s);
	ft_printf ("%12.5hd\n", s);
	printf ("\033[32;01m%012.5hd\033[00m\n", s);
	ft_printf ("%012.5hd\n", s);
	printf ("\033[32;01m%-12.5hd\033[00m\n", s);
	ft_printf ("%-12.5hd\n", s);
	printf ("\033[32;01m%+12.5hd\033[00m\n", s);
	ft_printf ("%+12.5hd\n", s);
	printf ("\033[32;01m% 12.5hd\033[00m\n", s);
	ft_printf ("% 12.5hd\n", s);
	printf ("\033[32;01m%0+12.5hd\033[00m\n", s);
	ft_printf ("%0+12.5hd\n", s);
	printf ("\033[32;01m%0 12.5hd\033[00m\n", s);
	ft_printf ("%0 12.5hd\n", s);
	printf ("\033[32;01m%- 12.5hd\033[00m\n", s);
	ft_printf ("%-+12.5hd\n", s);
	printf ("\033[32;01m%- 12.5hd\033[00m\n", s);
	ft_printf ("%- 12.5hd\n\n", s);

	printf("--- TEST %%ld positif ---\n\n");

	long			l = 225345;

	printf ("\033[32;01m%ld\033[00m\n", l);
	ft_printf ("%ld\n\n", l);
	
	printf("--- TElT %%ld negatif ---\n\n");

	l = -225345;

	printf ("\033[32;01m%ld\033[00m\n", l);
	ft_printf ("%ld\n\n", l);

	printf("--- TEST %%ld positif aves attributs ---\n\n");
	
	l = 225345;

	printf ("\033[32;01m%0ld\033[00m\n", l);
	ft_printf ("%0ld\n", l);
	printf ("\033[32;01m%-ld\033[00m\n", l);
	ft_printf ("%-ld\n", l);
	printf ("\033[32;01m%+ld\033[00m\n", l);
	ft_printf ("%+ld\n", l);
	printf ("\033[32;01m% ld\033[00m\n", l);
	ft_printf ("% ld\n", l);
	printf ("\033[32;01m%0+ld\033[00m\n", l);
	ft_printf ("%0+ld\n", l);
	printf ("\033[32;01m%0 ld\033[00m\n", l);
	ft_printf ("%0 ld\n", l);
	printf ("\033[32;01m%-+ld\033[00m\n", l);
	ft_printf ("%-+ld\n", l);
	printf ("\033[32;01m%- ld\033[00m\n", l);
	ft_printf ("%- ld\n\n", l);
	
	printf("--- TEST %%ld negatif avec attributs ---\n\n");
	
	l = -225345;

	printf ("\033[32;01m%0ld\033[00m\n", l);
	ft_printf ("%0ld\n", l);
	printf ("\033[32;01m%-ld\033[00m\n", l);
	ft_printf ("%-ld\n", l);
	printf ("\033[32;01m%+ld\033[00m\n", l);
	ft_printf ("%+ld\n", l);
	printf ("\033[32;01m% ld\033[00m\n", l);
	ft_printf ("% ld\n", l);
	printf ("\033[32;01m%0+ld\033[00m\n", l);
	ft_printf ("%0+ld\n", l);
	printf ("\033[32;01m%0 ld\033[00m\n", l);
	ft_printf ("%0 ld\n", l);
	printf ("\033[32;01m%-+ld\033[00m\n", l);
	ft_printf ("%-+ld\n", l);
	printf ("\033[32;01m%- ld\033[00m\n", l);
	ft_printf ("%- ld\n\n", l);
	
	printf("--- TEST %%ld positif avec largeur ---\n\n");
	
	l = 225345;

	printf ("\033[32;01m%12ld\033[00m\n", l);
	ft_printf ("%12ld\n", l);
	printf ("\033[32;01m%012ld\033[00m\n", l);
	ft_printf ("%012ld\n", l);
	printf ("\033[32;01m%-12ld\033[00m\n", l);
	ft_printf ("%-12ld\n", l);
	printf ("\033[32;01m%+12ld\033[00m\n", l);
	ft_printf ("%+12ld\n", l);
	printf ("\033[32;01m% 12ld\033[00m\n", l);
	ft_printf ("% 12ld\n", l);
	printf ("\033[32;01m%0+12ld\033[00m\n", l);
	ft_printf ("%0+12ld\n", l);
	printf ("\033[32;01m%0 12ld\033[00m\n", l);
	ft_printf ("%0 12ld\n", l);
	printf ("\033[32;01m%-+12ld\033[00m\n", l);
	ft_printf ("%-+12ld\n", l);
	printf ("\033[32;01m%- 12ld\033[00m\n", l);
	ft_printf ("%- 12ld\n\n", l);
	
	printf("--- TEST %%ld negatif avec largeur ---\n\n");
	
	l = -225345;

	printf ("\033[32;01m%012ld\033[00m\n", l);
	ft_printf ("%012ld\n", l);
	printf ("\033[32;01m%012ld\033[00m\n", l);
	ft_printf ("%012ld\n", l);
	printf ("\033[32;01m%-12ld\033[00m\n", l);
	ft_printf ("%-12ld\n", l);
	printf ("\033[32;01m%+12ld\033[00m\n", l);
	ft_printf ("%+12ld\n", l);
	printf ("\033[32;01m% 12ld\033[00m\n", l);
	ft_printf ("% 12ld\n", l);
	printf ("\033[32;01m%0+12ld\033[00m\n", l);
	ft_printf ("%0+12ld\n", l);
	printf ("\033[32;01m%0 12ld\033[00m\n", l);
	ft_printf ("%0 12ld\n", l);
	printf ("\033[32;01m%-+12ld\033[00m\n", l);
	ft_printf ("%-+12ld\n", l);
	printf ("\033[32;01m%- 12ld\033[00m\n", l);
	ft_printf ("%- 12ld\n\n", l);

	printf("--- TEST %%ld positif avec precision ---\n\n");

	l = 225345;

	printf ("\033[32;01m%.5ld\033[00m\n", l);
	ft_printf ("%.5ld\n", l);
	printf ("\033[32;01m%.5ld\033[00m\n", l);
	ft_printf ("%.5ld\n", l);
	printf ("\033[32;01m%0.5ld\033[00m\n", l);
	ft_printf ("%0.5ld\n", l);
	printf ("\033[32;01m%-.5ld\033[00m\n", l);
	ft_printf ("%-.5ld\n", l);
	printf ("\033[32;01m%+.5ld\033[00m\n", l);
	ft_printf ("%+.5ld\n", l);
	printf ("\033[32;01m% .5ld\033[00m\n", l);
	ft_printf ("% .5ld\n", l);
	printf ("\033[32;01m%12.5ld\033[00m\n", l);
	ft_printf ("%12.5ld\n", l);
	printf ("\033[32;01m%012.5ld\033[00m\n", l);
	ft_printf ("%012.5ld\n", l);
	printf ("\033[32;01m%-12.5ld\033[00m\n", l);
	ft_printf ("%-12.5ld\n", l);
	printf ("\033[32;01m%+12.5ld\033[00m\n", l);
	ft_printf ("%+12.5ld\n", l);
	printf ("\033[32;01m% 12.5ld\033[00m\n", l);
	ft_printf ("% 12.5ld\n", l);
	printf ("\033[32;01m%0+12.5ld\033[00m\n", l);
	ft_printf ("%0+12.5ld\n", l);
	printf ("\033[32;01m%0 12.5ld\033[00m\n", l);
	ft_printf ("%0 12.5ld\n", l);
	printf ("\033[32;01m%- 12.5ld\033[00m\n", l);
	ft_printf ("%-+12.5ld\n", l);
	printf ("\033[32;01m%- 12.5ld\033[00m\n", l);
	ft_printf ("%- 12.5ld\n\n", l);


	printf("--- TEST %%ld negatif avec precision ---\n\n");

	l = -225345;

	printf ("\033[32;01m%.5ld\033[00m\n", l);
	ft_printf ("%.5ld\n", l);
	printf ("\033[32;01m%.5ld\033[00m\n", l);
	ft_printf ("%.5ld\n", l);
	printf ("\033[32;01m%0.5ld\033[00m\n", l);
	ft_printf ("%0.5ld\n", l);
	printf ("\033[32;01m%-.5ld\033[00m\n", l);
	ft_printf ("%-.5ld\n", l);
	printf ("\033[32;01m%+.5ld\033[00m\n", l);
	ft_printf ("%+.5ld\n", l);
	printf ("\033[32;01m% .5ld\033[00m\n", l);
	ft_printf ("% .5ld\n", l);
	printf ("\033[32;01m%12.5ld\033[00m\n", l);
	ft_printf ("%12.5ld\n", l);
	printf ("\033[32;01m%012.5ld\033[00m\n", l);
	ft_printf ("%012.5ld\n", l);
	printf ("\033[32;01m%-12.5ld\033[00m\n", l);
	ft_printf ("%-12.5ld\n", l);
	printf ("\033[32;01m%+12.5ld\033[00m\n", l);
	ft_printf ("%+12.5ld\n", l);
	printf ("\033[32;01m% 12.5ld\033[00m\n", l);
	ft_printf ("% 12.5ld\n", l);
	printf ("\033[32;01m%0+12.5ld\033[00m\n", l);
	ft_printf ("%0+12.5ld\n", l);
	printf ("\033[32;01m%0 12.5ld\033[00m\n", l);
	ft_printf ("%0 12.5ld\n", l);
	printf ("\033[32;01m%- 12.5ld\033[00m\n", l);
	ft_printf ("%-+12.5ld\n", l);
	printf ("\033[32;01m%- 12.5ld\033[00m\n", l);
	ft_printf ("%- 12.5ld\n\n", l);
	
	printf("--- TEST %%lld positif ---\n\n");

	long long		ll = 225345;

	printf ("\033[32;01m%lld\033[00m\n", ll);
	ft_printf ("%lld\n\n", ll);
	
	printf("--- TElT %%lld negatif ---\n\n");

	ll = -225345;

	printf ("\033[32;01m%lld\033[00m\n", ll);
	ft_printf ("%lld\n\n", ll);

	printf("--- TEST %%lld positif aves attributs ---\n\n");
	
	ll = 225345;

	printf ("\033[32;01m%0lld\033[00m\n", ll);
	ft_printf ("%0lld\n", ll);
	printf ("\033[32;01m%-lld\033[00m\n", ll);
	ft_printf ("%-lld\n", ll);
	printf ("\033[32;01m%+lld\033[00m\n", ll);
	ft_printf ("%+lld\n", ll);
	printf ("\033[32;01m% lld\033[00m\n", ll);
	ft_printf ("% lld\n", ll);
	printf ("\033[32;01m%0+lld\033[00m\n", ll);
	ft_printf ("%0+lld\n", ll);
	printf ("\033[32;01m%0 lld\033[00m\n", ll);
	ft_printf ("%0 lld\n", ll);
	printf ("\033[32;01m%-+lld\033[00m\n", ll);
	ft_printf ("%-+lld\n", ll);
	printf ("\033[32;01m%- lld\033[00m\n", ll);
	ft_printf ("%- lld\n\n", ll);
	
	printf("--- TEST %%lld negatif avec attributs ---\n\n");
	
	ll = -225345;

	printf ("\033[32;01m%0lld\033[00m\n", ll);
	ft_printf ("%0lld\n", ll);
	printf ("\033[32;01m%-lld\033[00m\n", ll);
	ft_printf ("%-lld\n", ll);
	printf ("\033[32;01m%+lld\033[00m\n", ll);
	ft_printf ("%+lld\n", ll);
	printf ("\033[32;01m% lld\033[00m\n", ll);
	ft_printf ("% lld\n", ll);
	printf ("\033[32;01m%0+lld\033[00m\n", ll);
	ft_printf ("%0+lld\n", ll);
	printf ("\033[32;01m%0 lld\033[00m\n", ll);
	ft_printf ("%0 lld\n", ll);
	printf ("\033[32;01m%-+lld\033[00m\n", ll);
	ft_printf ("%-+lld\n", ll);
	printf ("\033[32;01m%- lld\033[00m\n", ll);
	ft_printf ("%- lld\n\n", ll);
	
	printf("--- TEST %%lld positif avec largeur ---\n\n");
	
	ll = 225345;

	printf ("\033[32;01m%12lld\033[00m\n", ll);
	ft_printf ("%12lld\n", ll);
	printf ("\033[32;01m%012lld\033[00m\n", ll);
	ft_printf ("%012lld\n", ll);
	printf ("\033[32;01m%-12lld\033[00m\n", ll);
	ft_printf ("%-12lld\n", ll);
	printf ("\033[32;01m%+12lld\033[00m\n", ll);
	ft_printf ("%+12lld\n", ll);
	printf ("\033[32;01m% 12lld\033[00m\n", ll);
	ft_printf ("% 12lld\n", ll);
	printf ("\033[32;01m%0+12lld\033[00m\n", ll);
	ft_printf ("%0+12lld\n", ll);
	printf ("\033[32;01m%0 12lld\033[00m\n", ll);
	ft_printf ("%0 12lld\n", ll);
	printf ("\033[32;01m%-+12lld\033[00m\n", ll);
	ft_printf ("%-+12lld\n", ll);
	printf ("\033[32;01m%- 12lld\033[00m\n", ll);
	ft_printf ("%- 12lld\n\n", ll);
	
	printf("--- TEST %%lld negatif avec largeur ---\n\n");
	
	ll = -225345;

	printf ("\033[32;01m%012lld\033[00m\n", ll);
	ft_printf ("%012lld\n", ll);
	printf ("\033[32;01m%012lld\033[00m\n", ll);
	ft_printf ("%012lld\n", ll);
	printf ("\033[32;01m%-12lld\033[00m\n", ll);
	ft_printf ("%-12lld\n", ll);
	printf ("\033[32;01m%+12lld\033[00m\n", ll);
	ft_printf ("%+12lld\n", ll);
	printf ("\033[32;01m% 12lld\033[00m\n", ll);
	ft_printf ("% 12lld\n", ll);
	printf ("\033[32;01m%0+12lld\033[00m\n", ll);
	ft_printf ("%0+12lld\n", ll);
	printf ("\033[32;01m%0 12lld\033[00m\n", ll);
	ft_printf ("%0 12lld\n", ll);
	printf ("\033[32;01m%-+12lld\033[00m\n", ll);
	ft_printf ("%-+12lld\n", ll);
	printf ("\033[32;01m%- 12lld\033[00m\n", ll);
	ft_printf ("%- 12lld\n\n", ll);

	printf("--- TEST %%lld positif avec precision ---\n\n");

	ll = 225345;

	printf ("\033[32;01m%.5lld\033[00m\n", ll);
	ft_printf ("%.5lld\n", ll);
	printf ("\033[32;01m%.5lld\033[00m\n", ll);
	ft_printf ("%.5lld\n", ll);
	printf ("\033[32;01m%0.5lld\033[00m\n", ll);
	ft_printf ("%0.5lld\n", ll);
	printf ("\033[32;01m%-.5lld\033[00m\n", ll);
	ft_printf ("%-.5lld\n", ll);
	printf ("\033[32;01m%+.5lld\033[00m\n", ll);
	ft_printf ("%+.5lld\n", ll);
	printf ("\033[32;01m% .5lld\033[00m\n", ll);
	ft_printf ("% .5lld\n", ll);
	printf ("\033[32;01m%12.5lld\033[00m\n", ll);
	ft_printf ("%12.5lld\n", ll);
	printf ("\033[32;01m%012.5lld\033[00m\n", ll);
	ft_printf ("%012.5lld\n", ll);
	printf ("\033[32;01m%-12.5lld\033[00m\n", ll);
	ft_printf ("%-12.5lld\n", ll);
	printf ("\033[32;01m%+12.5lld\033[00m\n", ll);
	ft_printf ("%+12.5lld\n", ll);
	printf ("\033[32;01m% 12.5lld\033[00m\n", ll);
	ft_printf ("% 12.5lld\n", ll);
	printf ("\033[32;01m%0+12.5lld\033[00m\n", ll);
	ft_printf ("%0+12.5lld\n", ll);
	printf ("\033[32;01m%0 12.5lld\033[00m\n", ll);
	ft_printf ("%0 12.5lld\n", ll);
	printf ("\033[32;01m%- 12.5lld\033[00m\n", ll);
	ft_printf ("%-+12.5lld\n", ll);
	printf ("\033[32;01m%- 12.5lld\033[00m\n", ll);
	ft_printf ("%- 12.5lld\n\n", ll);


	printf("--- TEST %%lld negatif avec precision ---\n\n");

	ll = -225345;

	printf ("\033[32;01m%.5lld\033[00m\n", ll);
	ft_printf ("%.5lld\n", ll);
	printf ("\033[32;01m%.5lld\033[00m\n", ll);
	ft_printf ("%.5lld\n", ll);
	printf ("\033[32;01m%0.5lld\033[00m\n", ll);
	ft_printf ("%0.5lld\n", ll);
	printf ("\033[32;01m%-.5lld\033[00m\n", ll);
	ft_printf ("%-.5lld\n", ll);
	printf ("\033[32;01m%+.5lld\033[00m\n", ll);
	ft_printf ("%+.5lld\n", ll);
	printf ("\033[32;01m% .5lld\033[00m\n", ll);
	ft_printf ("% .5lld\n", ll);
	printf ("\033[32;01m%12.5lld\033[00m\n", ll);
	ft_printf ("%12.5lld\n", ll);
	printf ("\033[32;01m%012.5lld\033[00m\n", ll);
	ft_printf ("%012.5lld\n", ll);
	printf ("\033[32;01m%-12.5lld\033[00m\n", ll);
	ft_printf ("%-12.5lld\n", ll);
	printf ("\033[32;01m%+12.5lld\033[00m\n", ll);
	ft_printf ("%+12.5lld\n", ll);
	printf ("\033[32;01m% 12.5lld\033[00m\n", ll);
	ft_printf ("% 12.5lld\n", ll);
	printf ("\033[32;01m%0+12.5lld\033[00m\n", ll);
	ft_printf ("%0+12.5lld\n", ll);
	printf ("\033[32;01m%0 12.5lld\033[00m\n", ll);
	ft_printf ("%0 12.5lld\n", ll);
	printf ("\033[32;01m%- 12.5lld\033[00m\n", ll);
	ft_printf ("%-+12.5lld\n", ll);
	printf ("\033[32;01m%- 12.5lld\033[00m\n", ll);
	ft_printf ("%- 12.5lld\n\n", ll);

	printf("--- TEST %%jd positif ---\n\n");

	l = 225345;

	printf ("\033[32;01m%jd\033[00m\n", l);
	ft_printf ("%jd\n\n", l);
	
	printf("--- TEST %%jd negatif ---\n\n");

	l = -225345;

	printf ("\033[32;01m%jd\033[00m\n", l);
	ft_printf ("%jd\n\n", l);

	printf("--- TEST %%jd positif aves attributs ---\n\n");
	
	l = 225345;

	printf ("\033[32;01m%0jd\033[00m\n", l);
	ft_printf ("%0jd\n", l);
	printf ("\033[32;01m%-jd\033[00m\n", l);
	ft_printf ("%-jd\n", l);
	printf ("\033[32;01m%+jd\033[00m\n", l);
	ft_printf ("%+jd\n", l);
	printf ("\033[32;01m% jd\033[00m\n", l);
	ft_printf ("% jd\n", l);
	printf ("\033[32;01m%0+jd\033[00m\n", l);
	ft_printf ("%0+jd\n", l);
	printf ("\033[32;01m%0 jd\033[00m\n", l);
	ft_printf ("%0 jd\n", l);
	printf ("\033[32;01m%-+jd\033[00m\n", l);
	ft_printf ("%-+jd\n", l);
	printf ("\033[32;01m%- jd\033[00m\n", l);
	ft_printf ("%- jd\n\n", l);
	
	printf("--- TEST %%jd negatif avec attributs ---\n\n");
	
	l = -225345;

	printf ("\033[32;01m%0jd\033[00m\n", l);
	ft_printf ("%0jd\n", l);
	printf ("\033[32;01m%-jd\033[00m\n", l);
	ft_printf ("%-jd\n", l);
	printf ("\033[32;01m%+jd\033[00m\n", l);
	ft_printf ("%+jd\n", l);
	printf ("\033[32;01m% jd\033[00m\n", l);
	ft_printf ("% jd\n", l);
	printf ("\033[32;01m%0+jd\033[00m\n", l);
	ft_printf ("%0+jd\n", l);
	printf ("\033[32;01m%0 jd\033[00m\n", l);
	ft_printf ("%0 jd\n", l);
	printf ("\033[32;01m%-+jd\033[00m\n", l);
	ft_printf ("%-+jd\n", l);
	printf ("\033[32;01m%- jd\033[00m\n", l);
	ft_printf ("%- jd\n\n", l);
	
	printf("--- TEST %%jd positif avec largeur ---\n\n");
	
	l = 225345;

	printf ("\033[32;01m%12jd\033[00m\n", l);
	ft_printf ("%12jd\n", l);
	printf ("\033[32;01m%012jd\033[00m\n", l);
	ft_printf ("%012jd\n", l);
	printf ("\033[32;01m%-12jd\033[00m\n", l);
	ft_printf ("%-12jd\n", l);
	printf ("\033[32;01m%+12jd\033[00m\n", l);
	ft_printf ("%+12jd\n", l);
	printf ("\033[32;01m% 12jd\033[00m\n", l);
	ft_printf ("% 12jd\n", l);
	printf ("\033[32;01m%0+12jd\033[00m\n", l);
	ft_printf ("%0+12jd\n", l);
	printf ("\033[32;01m%0 12jd\033[00m\n", l);
	ft_printf ("%0 12jd\n", l);
	printf ("\033[32;01m%-+12jd\033[00m\n", l);
	ft_printf ("%-+12jd\n", l);
	printf ("\033[32;01m%- 12jd\033[00m\n", l);
	ft_printf ("%- 12jd\n\n", l);
	
	printf("--- TEST %%jd negatif avec largeur ---\n\n");
	
	l = -225345;

	printf ("\033[32;01m%012jd\033[00m\n", l);
	ft_printf ("%012jd\n", l);
	printf ("\033[32;01m%012jd\033[00m\n", l);
	ft_printf ("%012jd\n", l);
	printf ("\033[32;01m%-12jd\033[00m\n", l);
	ft_printf ("%-12jd\n", l);
	printf ("\033[32;01m%+12jd\033[00m\n", l);
	ft_printf ("%+12jd\n", l);
	printf ("\033[32;01m% 12jd\033[00m\n", l);
	ft_printf ("% 12jd\n", l);
	printf ("\033[32;01m%0+12jd\033[00m\n", l);
	ft_printf ("%0+12jd\n", l);
	printf ("\033[32;01m%0 12jd\033[00m\n", l);
	ft_printf ("%0 12jd\n", l);
	printf ("\033[32;01m%-+12jd\033[00m\n", l);
	ft_printf ("%-+12jd\n", l);
	printf ("\033[32;01m%- 12jd\033[00m\n", l);
	ft_printf ("%- 12jd\n\n", l);

	printf("--- TEST %%jd positif avec precision ---\n\n");

	l = 225345;

	printf ("\033[32;01m%.5jd\033[00m\n", l);
	ft_printf ("%.5jd\n", l);
	printf ("\033[32;01m%.5jd\033[00m\n", l);
	ft_printf ("%.5jd\n", l);
	printf ("\033[32;01m%0.5jd\033[00m\n", l);
	ft_printf ("%0.5jd\n", l);
	printf ("\033[32;01m%-.5jd\033[00m\n", l);
	ft_printf ("%-.5jd\n", l);
	printf ("\033[32;01m%+.5jd\033[00m\n", l);
	ft_printf ("%+.5jd\n", l);
	printf ("\033[32;01m% .5jd\033[00m\n", l);
	ft_printf ("% .5jd\n", l);
	printf ("\033[32;01m%12.5jd\033[00m\n", l);
	ft_printf ("%12.5jd\n", l);
	printf ("\033[32;01m%012.5jd\033[00m\n", l);
	ft_printf ("%012.5jd\n", l);
	printf ("\033[32;01m%-12.5jd\033[00m\n", l);
	ft_printf ("%-12.5jd\n", l);
	printf ("\033[32;01m%+12.5jd\033[00m\n", l);
	ft_printf ("%+12.5jd\n", l);
	printf ("\033[32;01m% 12.5jd\033[00m\n", l);
	ft_printf ("% 12.5jd\n", l);
	printf ("\033[32;01m%0+12.5jd\033[00m\n", l);
	ft_printf ("%0+12.5jd\n", l);
	printf ("\033[32;01m%0 12.5jd\033[00m\n", l);
	ft_printf ("%0 12.5jd\n", l);
	printf ("\033[32;01m%- 12.5jd\033[00m\n", l);
	ft_printf ("%-+12.5jd\n", l);
	printf ("\033[32;01m%- 12.5jd\033[00m\n", l);
	ft_printf ("%- 12.5jd\n\n", l);


	printf("--- TEST %%jd negatif avec precision ---\n\n");

	l = -225345;

	printf ("\033[32;01m%.5jd\033[00m\n", l);
	ft_printf ("%.5jd\n", l);
	printf ("\033[32;01m%.5jd\033[00m\n", l);
	ft_printf ("%.5jd\n", l);
	printf ("\033[32;01m%0.5jd\033[00m\n", l);
	ft_printf ("%0.5jd\n", l);
	printf ("\033[32;01m%-.5jd\033[00m\n", l);
	ft_printf ("%-.5jd\n", l);
	printf ("\033[32;01m%+.5jd\033[00m\n", l);
	ft_printf ("%+.5jd\n", l);
	printf ("\033[32;01m% .5jd\033[00m\n", l);
	ft_printf ("% .5jd\n", l);
	printf ("\033[32;01m%12.5jd\033[00m\n", l);
	ft_printf ("%12.5jd\n", l);
	printf ("\033[32;01m%012.5jd\033[00m\n", l);
	ft_printf ("%012.5jd\n", l);
	printf ("\033[32;01m%-12.5jd\033[00m\n", l);
	ft_printf ("%-12.5jd\n", l);
	printf ("\033[32;01m%+12.5jd\033[00m\n", l);
	ft_printf ("%+12.5jd\n", l);
	printf ("\033[32;01m% 12.5jd\033[00m\n", l);
	ft_printf ("% 12.5jd\n", l);
	printf ("\033[32;01m%0+12.5jd\033[00m\n", l);
	ft_printf ("%0+12.5jd\n", l);
	printf ("\033[32;01m%0 12.5jd\033[00m\n", l);
	ft_printf ("%0 12.5jd\n", l);
	printf ("\033[32;01m%- 12.5jd\033[00m\n", l);
	ft_printf ("%-+12.5jd\n", l);
	printf ("\033[32;01m%- 12.5jd\033[00m\n", l);
	ft_printf ("%- 12.5jd\n\n", l);

	printf("--- TEST %%zd positif ---\n\n");

	l = 225345;

	printf ("\033[32;01m%zd\033[00m\n", l);
	ft_printf ("%zd\n\n", l);
	
	printf("--- TEST %%zd negatif ---\n\n");

	l = -225345;

	printf ("\033[32;01m%zd\033[00m\n", l);
	ft_printf ("%zd\n\n", l);

	printf("--- TEST %%zd positif aves attributs ---\n\n");
	
	l = 225345;

	printf ("\033[32;01m%0zd\033[00m\n", l);
	ft_printf ("%0zd\n", l);
	printf ("\033[32;01m%-zd\033[00m\n", l);
	ft_printf ("%-zd\n", l);
	printf ("\033[32;01m%+zd\033[00m\n", l);
	ft_printf ("%+zd\n", l);
	printf ("\033[32;01m% zd\033[00m\n", l);
	ft_printf ("% zd\n", l);
	printf ("\033[32;01m%0+zd\033[00m\n", l);
	ft_printf ("%0+zd\n", l);
	printf ("\033[32;01m%0 zd\033[00m\n", l);
	ft_printf ("%0 zd\n", l);
	printf ("\033[32;01m%-+zd\033[00m\n", l);
	ft_printf ("%-+zd\n", l);
	printf ("\033[32;01m%- zd\033[00m\n", l);
	ft_printf ("%- zd\n\n", l);
	
	printf("--- TEST %%zd negatif avec attributs ---\n\n");
	
	l = -225345;

	printf ("\033[32;01m%0zd\033[00m\n", l);
	ft_printf ("%0zd\n", l);
	printf ("\033[32;01m%-zd\033[00m\n", l);
	ft_printf ("%-zd\n", l);
	printf ("\033[32;01m%+zd\033[00m\n", l);
	ft_printf ("%+zd\n", l);
	printf ("\033[32;01m% zd\033[00m\n", l);
	ft_printf ("% zd\n", l);
	printf ("\033[32;01m%0+zd\033[00m\n", l);
	ft_printf ("%0+zd\n", l);
	printf ("\033[32;01m%0 zd\033[00m\n", l);
	ft_printf ("%0 zd\n", l);
	printf ("\033[32;01m%-+zd\033[00m\n", l);
	ft_printf ("%-+zd\n", l);
	printf ("\033[32;01m%- zd\033[00m\n", l);
	ft_printf ("%- zd\n\n", l);
	
	printf("--- TEST %%zd positif avec largeur ---\n\n");
	
	l = 225345;

	printf ("\033[32;01m%12zd\033[00m\n", l);
	ft_printf ("%12zd\n", l);
	printf ("\033[32;01m%012zd\033[00m\n", l);
	ft_printf ("%012zd\n", l);
	printf ("\033[32;01m%-12zd\033[00m\n", l);
	ft_printf ("%-12zd\n", l);
	printf ("\033[32;01m%+12zd\033[00m\n", l);
	ft_printf ("%+12zd\n", l);
	printf ("\033[32;01m% 12zd\033[00m\n", l);
	ft_printf ("% 12zd\n", l);
	printf ("\033[32;01m%0+12zd\033[00m\n", l);
	ft_printf ("%0+12zd\n", l);
	printf ("\033[32;01m%0 12zd\033[00m\n", l);
	ft_printf ("%0 12zd\n", l);
	printf ("\033[32;01m%-+12zd\033[00m\n", l);
	ft_printf ("%-+12zd\n", l);
	printf ("\033[32;01m%- 12zd\033[00m\n", l);
	ft_printf ("%- 12zd\n\n", l);
	
	printf("--- TEST %%zd negatif avec largeur ---\n\n");
	
	l = -225345;

	printf ("\033[32;01m%012zd\033[00m\n", l);
	ft_printf ("%012zd\n", l);
	printf ("\033[32;01m%012zd\033[00m\n", l);
	ft_printf ("%012zd\n", l);
	printf ("\033[32;01m%-12zd\033[00m\n", l);
	ft_printf ("%-12zd\n", l);
	printf ("\033[32;01m%+12zd\033[00m\n", l);
	ft_printf ("%+12zd\n", l);
	printf ("\033[32;01m% 12zd\033[00m\n", l);
	ft_printf ("% 12zd\n", l);
	printf ("\033[32;01m%0+12zd\033[00m\n", l);
	ft_printf ("%0+12zd\n", l);
	printf ("\033[32;01m%0 12zd\033[00m\n", l);
	ft_printf ("%0 12zd\n", l);
	printf ("\033[32;01m%-+12zd\033[00m\n", l);
	ft_printf ("%-+12zd\n", l);
	printf ("\033[32;01m%- 12zd\033[00m\n", l);
	ft_printf ("%- 12zd\n\n", l);

	printf("--- TEST %%zd positif avec precision ---\n\n");

	l = 225345;

	printf ("\033[32;01m%.5zd\033[00m\n", l);
	ft_printf ("%.5zd\n", l);
	printf ("\033[32;01m%.5zd\033[00m\n", l);
	ft_printf ("%.5zd\n", l);
	printf ("\033[32;01m%0.5zd\033[00m\n", l);
	ft_printf ("%0.5zd\n", l);
	printf ("\033[32;01m%-.5zd\033[00m\n", l);
	ft_printf ("%-.5zd\n", l);
	printf ("\033[32;01m%+.5zd\033[00m\n", l);
	ft_printf ("%+.5zd\n", l);
	printf ("\033[32;01m% .5zd\033[00m\n", l);
	ft_printf ("% .5zd\n", l);
	printf ("\033[32;01m%12.5zd\033[00m\n", l);
	ft_printf ("%12.5zd\n", l);
	printf ("\033[32;01m%012.5zd\033[00m\n", l);
	ft_printf ("%012.5zd\n", l);
	printf ("\033[32;01m%-12.5zd\033[00m\n", l);
	ft_printf ("%-12.5zd\n", l);
	printf ("\033[32;01m%+12.5zd\033[00m\n", l);
	ft_printf ("%+12.5zd\n", l);
	printf ("\033[32;01m% 12.5zd\033[00m\n", l);
	ft_printf ("% 12.5zd\n", l);
	printf ("\033[32;01m%0+12.5zd\033[00m\n", l);
	ft_printf ("%0+12.5zd\n", l);
	printf ("\033[32;01m%0 12.5zd\033[00m\n", l);
	ft_printf ("%0 12.5zd\n", l);
	printf ("\033[32;01m%- 12.5zd\033[00m\n", l);
	ft_printf ("%-+12.5zd\n", l);
	printf ("\033[32;01m%- 12.5zd\033[00m\n", l);
	ft_printf ("%- 12.5zd\n\n", l);


	printf("--- TEST %%zd negatif avec precision ---\n\n");

	l = -225345;

	printf ("\033[32;01m%.5zd\033[00m\n", l);
	ft_printf ("%.5zd\n", l);
	printf ("\033[32;01m%.5zd\033[00m\n", l);
	ft_printf ("%.5zd\n", l);
	printf ("\033[32;01m%0.5zd\033[00m\n", l);
	ft_printf ("%0.5zd\n", l);
	printf ("\033[32;01m%-.5zd\033[00m\n", l);
	ft_printf ("%-.5zd\n", l);
	printf ("\033[32;01m%+.5zd\033[00m\n", l);
	ft_printf ("%+.5zd\n", l);
	printf ("\033[32;01m% .5zd\033[00m\n", l);
	ft_printf ("% .5zd\n", l);
	printf ("\033[32;01m%12.5zd\033[00m\n", l);
	ft_printf ("%12.5zd\n", l);
	printf ("\033[32;01m%012.5zd\033[00m\n", l);
	ft_printf ("%012.5zd\n", l);
	printf ("\033[32;01m%-12.5zd\033[00m\n", l);
	ft_printf ("%-12.5zd\n", l);
	printf ("\033[32;01m%+12.5zd\033[00m\n", l);
	ft_printf ("%+12.5zd\n", l);
	printf ("\033[32;01m% 12.5zd\033[00m\n", l);
	ft_printf ("% 12.5zd\n", l);
	printf ("\033[32;01m%0+12.5zd\033[00m\n", l);
	ft_printf ("%0+12.5zd\n", l);
	printf ("\033[32;01m%0 12.5zd\033[00m\n", l);
	ft_printf ("%0 12.5zd\n", l);
	printf ("\033[32;01m%- 12.5zd\033[00m\n", l);
	ft_printf ("%-+12.5zd\n", l);
	printf ("\033[32;01m%- 12.5zd\033[00m\n", l);
	ft_printf ("%- 12.5zd\n\n", l);
	
	printf("--- TEST CONVERSION %%i ---\n\n");
	printf("--- TEST %%i positif ---\n\n");
	
	printf ("\033[32;01m%i\033[00m\n", 12);
	ft_printf ("%i\n\n", 12);

	printf("--- TEST %%i negatif ---\n\n");

	printf ("\033[32;01m%i\033[00m\n", -12);
	ft_printf ("%i\n\n", -12);
	
	printf("--- TEST %%i positif avec attributs ---\n\n");

	printf ("\033[32;01m%0i\033[00m\n", 12);
	ft_printf ("%0i\n", 12);
	printf ("\033[32;01m%-i\033[00m\n", 12);
	ft_printf ("%-i\n", 12);
	printf ("\033[32;01m%+i\033[00m\n", 12);
	ft_printf ("%+i\n", 12);
	printf ("\033[32;01m% i\033[00m\n", 12);
	ft_printf ("% i\n", 12);
	printf ("\033[32;01m%0+i\033[00m\n", 12);
	ft_printf ("%0+i\n", 12);
	printf ("\033[32;01m%0 i\033[00m\n", 12);
	ft_printf ("%0 i\n", 12);
	printf ("\033[32;01m%-+i\033[00m\n", 12);
	ft_printf ("%-+i\n", 12);
	printf ("\033[32;01m%- i\033[00m\n", 12);
	ft_printf ("%- i\n\n", 12);


	printf("--- TEST %%i negatif avec attributs ---\n\n");

	printf ("\033[32;01m%0i\033[00m\n", -12);
	ft_printf ("%0i\n", -12);
	printf ("\033[32;01m%-i\033[00m\n", -12);
	ft_printf ("%-i\n", -12);
	printf ("\033[32;01m%+i\033[00m\n", -12);
	ft_printf ("%+i\n", -12);
	printf ("\033[32;01m% i\033[00m\n", -12);
	ft_printf ("% i\n", -12);
	printf ("\033[32;01m%0+i\033[00m\n", -12);
	ft_printf ("%0+i\n", -12);
	printf ("\033[32;01m%0 i\033[00m\n", -12);
	ft_printf ("%0 i\n", -12);
	printf ("\033[32;01m%-+i\033[00m\n", -12);
	ft_printf ("%-+i\n", -12);
	printf ("\033[32;01m%- i\033[00m\n", -12);
	ft_printf ("%- i\n\n", -12);

	printf("--- TEST %%i positif avec largeur ---\n\n");

	printf ("\033[32;01m%12i\033[00m\n", 12);
	ft_printf ("%12i\n", 12);
	printf ("\033[32;01m%012i\033[00m\n", 12);
	ft_printf ("%012i\n", 12);
	printf ("\033[32;01m%-12i\033[00m\n", 12);
	ft_printf ("%-12i\n", 12);
	printf ("\033[32;01m%+12i\033[00m\n", 12);
	ft_printf ("%+12i\n", 12);
	printf ("\033[32;01m% 12i\033[00m\n", 12);
	ft_printf ("% 12i\n", 12);
	printf ("\033[32;01m%0+12i\033[00m\n", 12);
	ft_printf ("%0+12i\n", 12);
	printf ("\033[32;01m%0 12i\033[00m\n", 12);
	ft_printf ("%0 12i\n", 12);
	printf ("\033[32;01m%-+12i\033[00m\n", 12);
	ft_printf ("%-+12i\n", 12);
	printf ("\033[32;01m%- 12i\033[00m\n", 12);
	ft_printf ("%- 12i\n\n", 12);

	printf("--- TEST %%i negatif avec largeur ---\n\n");

	printf ("\033[32;01m%12i\033[00m\n", -12);
	ft_printf ("%12i\n", -12);
	printf ("\033[32;01m%012i\033[00m\n", -12);
	ft_printf ("%012i\n", -12);
	printf ("\033[32;01m%-12i\033[00m\n", -12);
	ft_printf ("%-12i\n", -12);
	printf ("\033[32;01m%+12i\033[00m\n", -12);
	ft_printf ("%+12i\n", -12);
	printf ("\033[32;01m% 12i\033[00m\n", -12);
	ft_printf ("% 12i\n", -12);
	printf ("\033[32;01m%0+12i\033[00m\n", -12);
	ft_printf ("%0+12i\n", -12);
	printf ("\033[32;01m%0 12i\033[00m\n", -12);
	ft_printf ("%0 12i\n", -12);
	printf ("\033[32;01m%-+12i\033[00m\n", -12);
	ft_printf ("%-+12i\n", -12);
	printf ("\033[32;01m%- 12i\033[00m\n", -12);
	ft_printf ("%- 12i\n\n", -12);

	printf("--- TEST %%i positif avec precision ---\n\n");

	printf ("\033[32;01m%.5i\033[00m\n", 1288888);
	ft_printf ("%.5i\n", 1288888);
	printf ("\033[32;01m%.5i\033[00m\n", 12);
	ft_printf ("%.5i\n", 12);
	printf ("\033[32;01m%0.5i\033[00m\n", 137);
	ft_printf ("%0.5i\n", 137);
	printf ("\033[32;01m%-.5i\033[00m\n", 137);
	ft_printf ("%-.5i\n", 137);
	printf ("\033[32;01m%+.5i\033[00m\n", 137);
	ft_printf ("%+.5i\n", 137);
	printf ("\033[32;01m% .5i\033[00m\n", 137);
	ft_printf ("% .5i\n", 137);
	printf ("\033[32;01m%12.5i\033[00m\n", 137);
	ft_printf ("%12.5i\n", 137);
	printf ("\033[32;01m%012.5i\033[00m\n", 137);
	ft_printf ("%012.5i\n", 137);
	printf ("\033[32;01m%-12.5i\033[00m\n", 137);
	ft_printf ("%-12.5i\n", 137);
	printf ("\033[32;01m%+12.5i\033[00m\n", 137);
	ft_printf ("%+12.5i\n", 137);
	printf ("\033[32;01m% 12.5i\033[00m\n", 137);
	ft_printf ("% 12.5i\n", 137);
	printf ("\033[32;01m%0+12.5i\033[00m\n", 137);
	ft_printf ("%0+12.5i\n", 137);
	printf ("\033[32;01m%0 12.5i\033[00m\n", 137);
	ft_printf ("%0 12.5i\n", 137);
	printf ("\033[32;01m%- 12.5i\033[00m\n", 137);
	ft_printf ("%-+12.5i\n", 137);
	printf ("\033[32;01m%- 12.5i\033[00m\n", 137);
	ft_printf ("%- 12.5i\n\n", 137);


	printf("--- TEST %%i negatif avec precision ---\n\n");

	printf ("\033[32;01m%.5i\033[00m\n", -1288888);
	ft_printf ("%.5i\n", -1288888);
	printf ("\033[32;01m%.5i\033[00m\n", -12);
	ft_printf ("%.5i\n", -12);
	printf ("\033[32;01m%0.5i\033[00m\n", -12);
	ft_printf ("%0.5i\n", -12);
	printf ("\033[32;01m%-.5i\033[00m\n", -12);
	ft_printf ("%-.5i\n", -12);
	printf ("\033[32;01m%+.5i\033[00m\n", -12);
	ft_printf ("%+.5i\n", -12);
	printf ("\033[32;01m% .5i\033[00m\n", -12);
	ft_printf ("% .5i\n", -12);
	printf ("\033[32;01m%12.5i\033[00m\n", -12);
	ft_printf ("%12.5i\n", -12);
	printf ("\033[32;01m%012.5i\033[00m\n", -12);
	ft_printf ("%012.5i\n", -12);
	printf ("\033[32;01m%-12.5i\033[00m\n", -12);
	ft_printf ("%-12.5i\n", -12);
	printf ("\033[32;01m%+12.5i\033[00m\n", -12);
	ft_printf ("%+12.5i\n", -12);
	printf ("\033[32;01m% 12.5i\033[00m\n", -12);
	ft_printf ("% 12.5i\n", -12);
	printf ("\033[32;01m%0+12.5i\033[00m\n", -12);
	ft_printf ("%0+12.5i\n", -12);
	printf ("\033[32;01m%0 12.5i\033[00m\n", -12);
	ft_printf ("%0 12.5i\n", -12);
	printf ("\033[32;01m%- 12.5i\033[00m\n", -12);
	ft_printf ("%-+12.5i\n", -12);
	printf ("\033[32;01m%- 12.5i\033[00m\n", -12);
	ft_printf ("%- 12.5i\n\n", -12);

	printf("--- TEST CONVERSION %%D ---\n\n");
	printf("--- TEST %%D positif ---\n\n");
	
	printf ("\033[32;01m%D\033[00m\n", 12);
	ft_printf ("%D\n\n", 12);

	printf("--- TEST %%D negatif ---\n\n");

	printf ("\033[32;01m%D\033[00m\n", -12);
	ft_printf ("%D\n\n", -12);
	
	printf("--- TEST %%D positif avec attributs ---\n\n");

	printf ("\033[32;01m%0D\033[00m\n", 12);
	ft_printf ("%0D\n", 12);
	printf ("\033[32;01m%-D\033[00m\n", 12);
	ft_printf ("%-D\n", 12);
	printf ("\033[32;01m%+D\033[00m\n", 12);
	ft_printf ("%+D\n", 12);
	printf ("\033[32;01m% D\033[00m\n", 12);
	ft_printf ("% D\n", 12);
	printf ("\033[32;01m%0+D\033[00m\n", 12);
	ft_printf ("%0+D\n", 12);
	printf ("\033[32;01m%0 D\033[00m\n", 12);
	ft_printf ("%0 D\n", 12);
	printf ("\033[32;01m%-+D\033[00m\n", 12);
	ft_printf ("%-+D\n", 12);
	printf ("\033[32;01m%- D\033[00m\n", 12);
	ft_printf ("%- D\n\n", 12);

	printf("--- TEST %%D negatif avec attributs ---\n\n");

	printf ("\033[32;01m%0D\033[00m\n", -12);
	ft_printf ("%0D\n", -12);
	printf ("\033[32;01m%-D\033[00m\n", -12);
	ft_printf ("%-D\n", -12);
	printf ("\033[32;01m%+D\033[00m\n", -12);
	ft_printf ("%+D\n", -12);
	printf ("\033[32;01m% D\033[00m\n", -12);
	ft_printf ("% D\n", -12);
	printf ("\033[32;01m%0+D\033[00m\n", -12);
	ft_printf ("%0+D\n", -12);
	printf ("\033[32;01m%0 D\033[00m\n", -12);
	ft_printf ("%0 D\n", -12);
	printf ("\033[32;01m%-+D\033[00m\n", -12);
	ft_printf ("%-+D\n", -12);
	printf ("\033[32;01m%- D\033[00m\n", -12);
	ft_printf ("%- D\n\n", -12);

	printf("--- TEST %%D positif avec largeur ---\n\n");

	printf ("\033[32;01m%12D\033[00m\n", 12);
	ft_printf ("%12D\n", 12);
	printf ("\033[32;01m%012D\033[00m\n", 12);
	ft_printf ("%012D\n", 12);
	printf ("\033[32;01m%-12D\033[00m\n", 12);
	ft_printf ("%-12D\n", 12);
	printf ("\033[32;01m%+12D\033[00m\n", 12);
	ft_printf ("%+12D\n", 12);
	printf ("\033[32;01m% 12D\033[00m\n", 12);
	ft_printf ("% 12D\n", 12);
	printf ("\033[32;01m%0+12D\033[00m\n", 12);
	ft_printf ("%0+12D\n", 12);
	printf ("\033[32;01m%0 12D\033[00m\n", 12);
	ft_printf ("%0 12D\n", 12);
	printf ("\033[32;01m%-+12D\033[00m\n", 12);
	ft_printf ("%-+12D\n", 12);
	printf ("\033[32;01m%- 12D\033[00m\n", 12);
	ft_printf ("%- 12D\n\n", 12);

	printf("--- TEST %%D negatif avec largeur ---\n\n");

	printf ("\033[32;01m%12D\033[00m\n", -12);
	ft_printf ("%12D\n", -12);
	printf ("\033[32;01m%012D\033[00m\n", -12);
	ft_printf ("%012D\n", -12);
	printf ("\033[32;01m%-12D\033[00m\n", -12);
	ft_printf ("%-12D\n", -12);
	printf ("\033[32;01m%+12D\033[00m\n", -12);
	ft_printf ("%+12D\n", -12);
	printf ("\033[32;01m% 12D\033[00m\n", -12);
	ft_printf ("% 12D\n", -12);
	printf ("\033[32;01m%0+12D\033[00m\n", -12);
	ft_printf ("%0+12D\n", -12);
	printf ("\033[32;01m%0 12D\033[00m\n", -12);
	ft_printf ("%0 12D\n", -12);
	printf ("\033[32;01m%-+12D\033[00m\n", -12);
	ft_printf ("%-+12D\n", -12);
	printf ("\033[32;01m%- 12D\033[00m\n", -12);
	ft_printf ("%- 12D\n\n", -12);

	printf("--- TEST %%D positif avec precision ---\n\n");

	printf ("\033[32;01m%.5D\033[00m\n", 1288888);
	ft_printf ("%.5D\n", 1288888);
	printf ("\033[32;01m%.5D\033[00m\n", 12);
	ft_printf ("%.5D\n", 12);
	printf ("\033[32;01m%0.5D\033[00m\n", 137);
	ft_printf ("%0.5D\n", 137);
	printf ("\033[32;01m%-.5D\033[00m\n", 137);
	ft_printf ("%-.5D\n", 137);
	printf ("\033[32;01m%+.5D\033[00m\n", 137);
	ft_printf ("%+.5D\n", 137);
	printf ("\033[32;01m% .5D\033[00m\n", 137);
	ft_printf ("% .5D\n", 137);
	printf ("\033[32;01m%12.5D\033[00m\n", 137);
	ft_printf ("%12.5D\n", 137);
	printf ("\033[32;01m%012.5D\033[00m\n", 137);
	ft_printf ("%012.5D\n", 137);
	printf ("\033[32;01m%-12.5D\033[00m\n", 137);
	ft_printf ("%-12.5D\n", 137);
	printf ("\033[32;01m%+12.5D\033[00m\n", 137);
	ft_printf ("%+12.5D\n", 137);
	printf ("\033[32;01m% 12.5D\033[00m\n", 137);
	ft_printf ("% 12.5D\n", 137);
	printf ("\033[32;01m%0+12.5D\033[00m\n", 137);
	ft_printf ("%0+12.5D\n", 137);
	printf ("\033[32;01m%0 12.5D\033[00m\n", 137);
	ft_printf ("%0 12.5D\n", 137);
	printf ("\033[32;01m%- 12.5D\033[00m\n", 137);
	ft_printf ("%-+12.5D\n", 137);
	printf ("\033[32;01m%- 12.5D\033[00m\n", 137);
	ft_printf ("%- 12.5D\n\n", 137);


	printf("--- TEST %%D negatif avec precision ---\n\n");

	printf ("\033[32;01m%.5D\033[00m\n", -1288888);
	ft_printf ("%.5D\n", -1288888);
	printf ("\033[32;01m%.5D\033[00m\n", -12);
	ft_printf ("%.5D\n", -12);
	printf ("\033[32;01m%0.5D\033[00m\n", -12);
	ft_printf ("%0.5D\n", -12);
	printf ("\033[32;01m%-.5D\033[00m\n", -12);
	ft_printf ("%-.5D\n", -12);
	printf ("\033[32;01m%+.5D\033[00m\n", -12);
	ft_printf ("%+.5D\n", -12);
	printf ("\033[32;01m% .5D\033[00m\n", -12);
	ft_printf ("% .5D\n", -12);
	printf ("\033[32;01m%12.5D\033[00m\n", -12);
	ft_printf ("%12.5D\n", -12);
	printf ("\033[32;01m%012.5D\033[00m\n", -12);
	ft_printf ("%012.5D\n", -12);
	printf ("\033[32;01m%-12.5D\033[00m\n", -12);
	ft_printf ("%-12.5D\n", -12);
	printf ("\033[32;01m%+12.5D\033[00m\n", -12);
	ft_printf ("%+12.5D\n", -12);
	printf ("\033[32;01m% 12.5D\033[00m\n", -12);
	ft_printf ("% 12.5D\n", -12);
	printf ("\033[32;01m%0+12.5D\033[00m\n", -12);
	ft_printf ("%0+12.5D\n", -12);
	printf ("\033[32;01m%0 12.5D\033[00m\n", -12);
	ft_printf ("%0 12.5D\n", -12);
	printf ("\033[32;01m%- 12.5D\033[00m\n", -12);
	ft_printf ("%-+12.5D\n", -12);
	printf ("\033[32;01m%- 12.5D\033[00m\n", -12);
	ft_printf ("%- 12.5D\n\n", -12);


	return (0);

}

