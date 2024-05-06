#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
    int ID;
    char Non_Utilisateur[50];
    char Marque[50];
    char Type_Carburant[50];
    char Modele[50];
    int Nbre_Places;
    int Transmission_Auto;
    int Prix_Location;
    int Disponibilite;
} Voiture;


void ajout(Voiture v){
	FILE *p;
	p=fopen("bd.csv","a");
	fprintf(p,"%i %s %s %s %i %i %i %i\n",v.ID,v.Marque,v.Type_Carburant,v.Modele,v.Nbre_Places,v.Transmission_Auto,v.Prix_Location,v.Disponibilite);
	fclose(p);
}

void affichage(Voiture *v,int taille){
	printf("\tid\tMarque\t\tType carb\tModele\tNbre place\tAuto\tPrix\tDispot\n\n");
	
	for(int j=0;j<taille-1;j++)
     		printf("\t%i\t%s\t\t%s\t\t%s\t\t%i\t%i\t%i\t%i\n",v[j].ID,v[j].Marque,v[j].Type_Carburant,v[j].Modele,v[j].Nbre_Places,v[j].Transmission_Auto,v[j].Prix_Location,v[j].Disponibilite);
    printf("\n\n");
	//system("pause");
	
}




void recherche_Mar(Voiture *v,int taille){
	char marque[50];
	Voiture *t_Marque;
	int cmp=1;
	t_Marque=(Voiture*)malloc(sizeof(Voiture));
	printf("\t\tEntrer la marque :");
	scanf("%s",marque);
	printf("\n\n");
	for(int i=0;i<taille;i++){
		if(strcmp(marque,v[i].Marque)==0){
			
			t_Marque=(Voiture*)realloc(t_Marque,cmp*sizeof(Voiture));
			t_Marque[cmp-1]=v[i];
			cmp++;
			
			
			//t_Marque[cmp-1]=v[i];
			
			
			
			
		}
	}
	
	affichage(t_Marque,cmp);
}

void recherche_Disp(Voiture *v,int taille){
	char marque[50];
	Voiture *t_Marque;
	int cmp=1;
	t_Marque=(Voiture*)malloc(sizeof(Voiture));
	for(int i=0;i<taille;i++){
		if(v[i].Disponibilite==1){
			
			t_Marque=(Voiture*)realloc(t_Marque,cmp*sizeof(Voiture));
			t_Marque[cmp-1]=v[i];
			cmp++;
			
			
		
			
			
			
			
		}
	}
	
	affichage(t_Marque,cmp);
}


void tri_Marque(Voiture *v,int taille){
	
	Voiture max;
	int pos;
	for(int i=0;i<taille-2;i++){
		pos=i;
		max=v[i];	
		for(int j=i+1;j<taille-1;j++)
			if(max.Marque<v[j].Marque) {
				max=v[j];
				pos=j;	
			}
		if(pos!=i){
			v[pos]=v[i];
			v[i]=max;
			
		}
     		
	
	}
	FILE *p;
	p=fopen("bd.csv","w");
	for(int i=0;i<taille-1;i++)
		ajout(v[i]);
	
}

	


void tri_Prix(Voiture *v,int taille){
	Voiture max;
	int pos;
	for(int i=0;i<taille-2;i++){
		pos=i;
		max=v[i];	
		for(int j=i+1;j<taille-1;j++)
			if(max.Prix_Location<v[j].Prix_Location) {
				max=v[j];
				pos=j;	
			}
		if(pos!=i){
			v[pos]=v[i];
			v[i]=max;
			
		}
     		
	
	}
	FILE *p;
	p=fopen("bd.csv","w");
	for(int i=0;i<taille-1;i++)
		ajout(v[i]);
	
}


void supp_Voiture(Voiture *v,int taille){
	
	bool trouve=false;
	int ID;
	Voiture *t_Supp;
	printf("\n\n\n\tEntrer l\'ID de la voiture :");
	scanf("%i",&ID);
	int cmp=1;
	t_Supp=(Voiture*)malloc(sizeof(Voiture));
	
	for(int i=0;i<taille;i++){
		if(v[i].ID==ID && !trouve) trouve=true;
		else{
		
			
			t_Supp=(Voiture*)realloc(t_Supp,cmp*sizeof(Voiture));
			t_Supp[cmp-1]=v[i];
			cmp++;
			
			
		}
			
			
			
			
	}
	if(!trouve) {
		printf("\n\n\tLa voiture n\'existe pas :\n\n");
		
	}
	else{
		printf("\n\n\tFin suppression :\n\n");
		FILE *p;
		p=fopen("bd.csv","w");
		for(int i=0;i<cmp-1;i++)
			ajout(t_Supp[i]);
		
	}
}
	
	

void modif_Voiture(Voiture *v,int taille){
	
	bool trouve=false;
	int ID;
	printf("\n\n\n\tEntrer l\'ID de la voiture :");
	scanf("%i",&ID);
	int cmp=0;
	while(cmp<taille-1 && !trouve){
		if(v[cmp].ID==ID && !trouve) {
			trouve=true;
			if(v[cmp].Disponibilite==1)
				v[cmp].Disponibilite=0;
			else
				v[cmp].Disponibilite=1;
				
				
		}
		cmp++;
		
		
			
		
			
			
	}
			
			
			
			
	
	if(!trouve) {
		printf("\n\n\tLa voiture n\'existe pas :\n\n");
		
	}
	else{
		printf("\n\n\tFin modification :\n\n");
		FILE *p;
		p=fopen("bd.csv","w");
		for(int i=0;i<taille-1;i++)
			ajout(v[i]);
		
	}
}
	

void lecture(int para){
	FILE *p;
	Voiture *t;
	
	t=(Voiture*)malloc(sizeof(Voiture));
	p=fopen("bd.csv","r");
	int i=1;
	
	while(!feof(p)){
		t=(Voiture*)realloc(t,i*sizeof(Voiture));
		fscanf(p,"%i %s %s %s %i %i %i %i",&t[i-1].ID,t[i-1].Marque,t[i-1].Type_Carburant,t[i-1].Modele,&t[i-1].Nbre_Places,&t[i-1].Transmission_Auto,&t[i-1].Prix_Location,&t[i-1].Disponibilite);
		
		i++;
	}
	fclose(p);
	if(para==1)affichage(t,i-1);
	if(para==2)tri_Prix(t,i-1);
	if(para==3)tri_Marque(t,i-1);
	if(para==4)recherche_Mar(t,i-1);
	if(para==5)recherche_Disp(t,i-1);
	if(para==6)supp_Voiture(t,i-1);
	if(para==7)modif_Voiture(t,i-1);	
	

	
}

;
main(){
	FILE *pv;
	pv=NULL;
	Voiture V;
	pv=fopen("bd.csv","r");
	if(pv==NULL) pv=fopen("bd.csv","w");
	fclose(pv);
	
	
	
	int choix;
    do {
    	
    	system("cls");
        
        
		printf("\n\n\n               ******************************************************************************************\n");
		printf("               ===============             M E N U               G E N E R A L            ===============\n");
        printf("               ******************************************************************************************\n\n\n\n");
        printf("                        1. MAJ\n");
        printf("                        2. Affichage\n");
        printf("                        3. Tri\n");
        printf("                        4. Recherche\n");
        printf("                        5. Quitter le programme\n");
        printf("\n\n\n\n\n");
        printf("                                             Choix : ");
        scanf("%d", &choix);
        switch(choix){
        	case 1:
        		
        		int choix1;
    			do {
    	
    				system("cls");
        
        
					printf("\n\n\n               ********************************************************************************************\n");
					printf("               ===============         M A J          D E S       V O I T U R E S       ===================\n");
			        printf("               ********************************************************************************************\n\n\n\n");
			        printf("                        1. Ajout voiture\n");
			        printf("                        2. Modification voiture\n");
			        printf("                        3. Suppression voiture\n");
			        printf("                        4. Menu principal\n");
			        printf("\n\n\n\n\n");
			        printf("                                             Choix : ");
			        scanf("%d", &choix1);

       
        
        			switch (choix1) {
            			case 1:
            				system("cls");
        
        
							printf("\n\n\n               ***********************************************************************************\n");
							printf("               ===============         A J O U T           V O I T U R E        ==================\n");
			        		printf("               ***********************************************************************************\n\n\n\n");
			        		
			        		printf("\t\tEntrer id :");
							scanf("%i",&V.ID);
							printf("\t\tEntrer Marque :");
							scanf("%s",V.Marque);
							printf("\t\tEntrer Type_Carburant :");
							scanf("%s",V.Type_Carburant);
			        		printf("\t\tEntrer Modele :");
							scanf("%s",V.Modele);
							printf("\t\tEntrer Nbre de places :");
							scanf("%i",&V.Nbre_Places);
							printf("\t\tTransmission Auto (1: pour oui   0: pour non) :");
							scanf("%i",&V.Transmission_Auto);
							printf("\t\tEntrer prix Location :");
							scanf("%i",&V.Prix_Location);
							printf("\t\tDisponibilite (1: pour oui   0: pour non) :");
							scanf("%i",&V.Disponibilite);
							ajout(V);
			        		printf("\n\n\t\tF I N     A J O U T\n\n\n");
        					system("pause");
            				break;
            			case 2:
            				system("cls");
        
        
							printf("\n\n\n               **************************************************************************************\n");
							printf("               =============       M O D I F I C A T I O N           V O I T U R E        ===========\n");
			        		printf("               **************************************************************************************\n\n\n\n");
						        		
			        		lecture(7);
			        		system("pause");
            				break;
            			case 3:
            				
            				system("cls");
        
        
							printf("\n\n\n               ***********************************************************************************\n");
							printf("               =============       S U P P R E S S I O N          V O I T U R E        ===========\n");
			        		printf("               ***********************************************************************************\n\n\n\n");
						        		
			        		lecture(6);
			        		system("pause");
			        		break;
            				
            			case 4:
            				
			        		break;
            			default:
        					printf("\n\n\t\tChoix invalide. Veuillez reessayer.\n\n\n");
        					system("pause");
        					break;
        			}
        		}while(choix1!=4);
            			
        		
        		
        		break;
        	case 2:
        		system("cls");
        
        
				printf("\n\n\n               *******************************************************************************\n");
				printf("               =============        A F F I C H A G E         V O I T U R E        ===========\n");
        		printf("               *******************************************************************************\n\n\n\n");
			        		
        		lecture(1);
        		system("pause");
        		break;
        	case 3:
        		int choix3;
    			do {
    	
    				system("cls");
        
        
					printf("\n\n\n               ********************************************************************************************\n");
					printf("               ===============         T R I           D E S       V O I T U R E S       ==================\n");
			        printf("               ********************************************************************************************\n\n\n\n");
			        printf("                        1. Par Marque\n");
			        printf("                        2. Par prix de location\n");
			        printf("                        3. Menu principal\n");
			        printf("\n\n\n\n\n");
			        printf("                                             Choix : ");
			        scanf("%d", &choix3);

       
        
        			switch (choix3) {
            			case 1:
            				system("cls");
        
        
							printf("\n\n\n               ******************************************************************************************\n");
							printf("               ===============         T R I           P A R        M A R Q U E       ===================\n");
					        printf("               ******************************************************************************************\n\n\n\n");
            				lecture(3);
            				printf("\n\n\t\tF I N     T R I \n\n\n");
							system("pause");
							break;
            			case 2:
            				system("cls");
        
        
							printf("\n\n\n               **************************************************************************************\n");
							printf("               ===============         T R I           P A R        P R I X       ===================\n");
					        printf("               **************************************************************************************\n\n\n\n");
            				lecture(2);
            				printf("\n\n\t\tF I N     T R I \n\n\n");
							system("pause");
							break;
            			case 3:
            				break;
            			default:
        					printf("\n\n\t\tChoix invalide. Veuillez reessayer.\n\n\n");
        					system("pause");
        					break;
        			}
        		}while(choix3!=3);
        		break;
				
        					
        					
        					
        	case 4:
        		int choix4;
    			do {
    	
    				system("cls");
        
        
					printf("\n\n\n               *********************************************************************************************\n");
					printf("               ===============         R E C H E R C H E            V O I T U R E S       ==================\n");
			        printf("               *********************************************************************************************\n\n\n\n");
			        printf("                        1. Par Marque\n");
			        printf("                        2. Par Disponibilite\n");
			        printf("                        3. Menu principal\n");
			        printf("\n\n\n\n\n");
			        printf("                                             Choix : ");
			        scanf("%d", &choix4);

       
        
        			switch (choix4) {
            			case 1:
            				system("cls");
        
        
							printf("\n\n\n               *******************************************************************************************\n");
							printf("               ===============        R E C H E R C H E   P A R        M A R Q U E       =================\n");
					        printf("               *******************************************************************************************\n\n\n\n");
            				lecture(4);
            				
							system("pause");
							break;
            			case 2:
            				system("cls");
        
        
							printf("\n\n\n               *****************************************************************************************\n");
							printf("               ===============     L I S T E    D E S   V O I T U R E S    D I S P O       =============\n");
					        printf("               *****************************************************************************************\n\n\n\n");
            				lecture(5);
							system("pause");
							break;
            			case 3:
            				break;
            			default:
        					printf("\n\n\t\tChoix invalide. Veuillez reessayer.\n\n\n");
        					system("pause");
        					break;
        			}
        		}while(choix4!=3);
        		break;
				
        		break;
        	case 5:
        		break;
        	default:
        		printf("\n\n\t\t\tChoix invalide. Veuillez reessayer.\n\n\n");
        		system("pause");
        		break;
        }
    
	
	
	
	
	
	
	
	}while(choix!=5);

	
	
	
	
}



