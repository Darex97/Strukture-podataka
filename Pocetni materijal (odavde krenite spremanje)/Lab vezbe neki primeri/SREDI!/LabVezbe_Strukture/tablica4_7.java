package vezbe;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Vector;

public class tablica{
	int[][] tab= new int[10][3];

public tablica(){
	for(int i=0;i<=9;i++)
		for(int j=0;j<=2;j++)
			tab[i][j]=0;
}

void dodavanje(int kljuc,int pod){
	int ap,as,hh=1;
	ap=kljuc%10;
	if (tab[ap][0]==0 && tab[ap][2]==0){
		tab[ap][0]=kljuc;
		tab[ap][1]=pod;
		tab[ap][2]=100;
	}
	else {
        as=(ap+1)%10;
		int br=ap;
		while(tab[as][2]!=0){
			if(tab[as][0]==kljuc){
				br=as;
				hh=0;
			}
			as=(as+1)%10;
		};
		tab[as][0]=kljuc;
		tab[as][1]=pod;
		if (hh==0){
		tab[as][2]=br;
		}
		else{
			if (tab[ap][0]==kljuc){
				tab[as][2]=ap;
			}
			else{
				tab[as][2]=100;};
		}
	};
	System.out.println("\n Uneti kljuc je:"+kljuc);
	System.out.println("\n podatak je:"+pod);
	return;
}

void stampa(){
	System.out.println("         mesto          link\n");
	for(int i=0;i<10;i++){
		System.out.println("          "+tab[i][1]+"             "+tab[i][2]+"\n");
	};
	return;
}

public static void main(String args[]){
        // BufferedReader in = new BufferedReader (new InputStreamReader(System.in));
	tablica4_7 t=new tablica4_7();
	int od,k;
	char[][] a= new char[10][10];
	System.out.println("\n da li zelite da upisujete u tablicu(1/0):");
	System.in.read(od);
	int i=1,j=1;
	while((od==1) && (i<=10)){
		System.out.println("\n Unesite REC ");
		System.in.read(a[j]);
		k=int(a[j][0])+1;
		t.dodavanje(k,j);
		System.out.println("\n da li zelite da upisujete u tablicu(1/0):");
		System.in.read(od);
		i++;
		j++;

	};
	if (i==10){
		System.out.println("  tabela je puna\n");
	}
	for(int r=1;r<=10;r++){
		System.out.println(a[r]+"\n");
	}
	t.stampa();

}
}


