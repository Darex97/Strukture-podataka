#include <stdio.h>
#include <stdlib.h>

/* Maksimalni stepen polinoma */
#define MAX_STEPEN 20


/* Polinome predstavljamo strukturom */
typedef struct {
    /* u kojoj imamo koeficijente; koef[i] je koeficijent uz clan x^i */
    double koef[MAX_STEPEN + 1];
    /* i stepen polinoma */
    int stepen;
} Polinom;


/* Funkcija koja ispisuje polinom na stdout u citljivom obliku
   Polinom prenosimo po adresi, da bi ustedeli kopiranje cele strukture,
   vec samo prenosimo adresu na kojoj se nalazi polinom kog ispisujemo */
void ispisi(const Polinom * p)
{
    int i;
    for (i = p->stepen; i >= 0; i--) {
	/* samo u slucaju da je koeficijent razlicit od nule treba da se vrsi neko stampanje*/
	/* alternativa - if(p->koef[i] == 0) continue; */
	
		if(p->koef[i]){				
			if (p->koef[i] > 0)
				putchar('+');
			if (i > 1)
				printf("%.2fx^%d", p->koef[i], i);
			else if (i == 1)
				printf("%.2fx", p->koef[i]);
			else
				printf("%.2f", p->koef[i]);
		}
    }
    putchar('\n');
}

/* Funkcija koja ucitava polinom sa tastature */
Polinom ucitaj()
{
    int i;
    Polinom p;
    
	/* Ucitavamo stepen polinoma */
    scanf("%d", &p.stepen);
    /* Ponavljamo ucitavanje stepena sve dok ne unesemo stepen iz dozvoljenog opsega */
    while (p.stepen > MAX_STEPEN || p.stepen < 0) {
		printf("Stepen polinoma pogresno unet, pokusajte ponovo: ");
		scanf("%d", &p.stepen);
    }
    /* Unosimo koeficijente polinoma */
    for (i = p.stepen; i >= 0; i--)
		scanf("%lf", &p.koef[i]);
    return p;
}

/* Funkcija racuna vrednost polinoma p u tacki x Hornerovim algoritmom */
/* x^4+2x^3+3x^2+2x+1 = ( ( ((0*x+1)*x+2)*x + 3)*x + 2)*x + 1 */
double vrednost(const Polinom * p, double x)
{
    double rezultat = 0;
    int i;
	
    for (i=p->stepen; i >= 0; i--)
		rezultat = rezultat * x + p->koef[i];
    return rezultat;
}

/* Funkcija koja sabira dva polinoma */
Polinom saberi(const Polinom * p, const Polinom * q)
{
    Polinom rez;
    int i;

    rez.stepen = p->stepen > q->stepen ? p->stepen : q->stepen;

    for (i = 0; i <= rez.stepen; i++)
		/* u slucaju da koeficijent koji trenutno racunamo odgovara stepenu koji je veci od stepena nekog od polinoma, sabiramo 0 (jer nemamo odgovarajuci koeficijent */
		rez.koef[i] = (i > p->stepen ? 0 : p->koef[i]) + (i > q->stepen ? 0 : q->koef[i]);
    return rez;

}

/*  Funkcija mnozi dva polinoma p i q */
Polinom pomnozi(const Polinom * p, const Polinom * q)
{
    int i, j;
    Polinom r;

    r.stepen = p->stepen + q->stepen;
    if (r.stepen > MAX_STEPEN) {
		fprintf(stderr, "Stepen proizvoda polinoma izlazi iz opsega\n");
		exit(EXIT_FAILURE);
    }

	/* postavljanje pocetnih vrednosti koeficijenata rezultata na 0 */
    for (i = 0; i <= r.stepen; i++)
		r.koef[i] = 0;

	/* proizvod p->koef[i]*q->koef[j] ucestvuje u racunanju koeficijenta r.koef[i+j] */
	/* r.koef[4] = p->koef[0]*q->koef[4] + p->koef[1]*q->koef[3] + p->koef[2]*q->koef[2] + p->koef[3]*q->koef[1] + p->koef[4]*q->koef[0] */
    for (i = 0; i <= p->stepen; i++)
	for (j = 0; j <= q->stepen; j++)
	    r.koef[i + j] += p->koef[i] * q->koef[j];

    return r;
}

/* Funkcija racuna izvod polinoma p  */
Polinom izvod(const Polinom * p)
{
    int i;
    Polinom r;

    if (p->stepen > 0) {
	r.stepen = p->stepen - 1;

	for (i = 0; i <= r.stepen; i++)
	    r.koef[i] = (i + 1) * p->koef[i + 1];
    } else
		r.koef[0] = r.stepen = 0;

    return r;
}

/* Funkcija racuna n-ti izvod polinoma p */
Polinom nIzvod(const Polinom * p, int n)
{
    int i;
    Polinom r;

    if (n < 0) {
		fprintf(stderr, "U n-tom izvodu polinoma, n mora biti >=0 \n");
		exit(EXIT_FAILURE);
    }

    if (n == 0)
		return *p;

    r = izvod(p);
    for (i = 1; i < n; i++)
		r = izvod(&r);

    return r;
}

int main(int argc, char **argv)
{
    Polinom p, q, r;
    double x;
    int n;

    /* Unos polinoma */
    printf
	("Unesite polinom (prvo stepen, pa zatim koeficijente od najveceg stepena do nultog):\n");
    p = ucitaj();

    /* Ispis polinoma */
    ispisi(&p);

    /* Unos tacke u kojoj se racuna vrednost polinoma */
    printf("\nUnesite tacku u kojoj racunate vrednost polinoma\n");
    scanf("%lf", &x);

    /* Ispisujemo vrednost polinoma u toj tacki */
    printf("Vrednost polimoma u tacki je %f\n", vrednost(&p, x));

    /* Unesimo drugi polinom */
    printf
	("\nUnesite drugi polinom (prvo stepen, pa zatim koeficijente od najveceg stepena do nultog):\n");
    q = ucitaj();

    /* Sabiramno polinome i ispisujemo zbir ta dva polinoma */
    r = saberi(&p, &q);
    printf("Zbir polinoma unetih polinoma je: \n");
    ispisi(&r);

    /* Mnozimo polinome i ispisujemo prozivod ta dva polinoma */
    r = pomnozi(&p, &q);
    printf("\nProzvod unetih polinoma je: \n");
    ispisi(&r);

    /* Izvod polinoma */
    printf("\nUnosite izvod polinoma koji zelite: ");
    scanf("%d", &n);
    r = nIzvod(&p, n);
    printf("%d. izvod polinoma ", n);
    ispisi(&p);
    printf("je : ");
    ispisi(&r);

    /* Uspesno zavrsavamo program */
    return 0;
}



