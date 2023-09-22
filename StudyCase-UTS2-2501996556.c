#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define cls system("cls");
#define sign printf("\n=> ");
#define press printf("Press Enter To Continue...");

int q = 0, qRes = 0;
char clinic[100][100] = {"Neurologists", "Radiologists", "Pediatricians", "Cardiologists"};
char neurologists[100][100] = {"Doxapram", "Oxazepam", "Quetiapine", "Amantadine"};
char radiologists[100][100] = {"Gadoteridol", "Mangafodipir", "Iodipamide", ""};
char pediatricians[100][100] = {"Amoxicillin", "Ibuprofen", "Albuterol"};
char cardiologists[100][100] = {"Acebutolol", "Atenolol", "Bisoprolol"};
char price[100][100]={"120000", "100000", "88000", "75000", "69000", "55000"};

struct pharmacy{
	char name[100];
	char medication[100];
	char diagnosis[100];
	char costMed[100];
	char costDoc[100];
	char costAdm[100];
	char status[100];
};

struct patient {
	char name[100];
	char birth[100];
	char age[100];	
	char address[100];
	char status[100];
	struct patient *next;
};

struct details {
	char doctor[100];
	char schedule[100];
	char clinic[100];
	char costDoc[100];
	struct details *next;
	struct patient *list;
};

struct pharmacy pharmacyQ[100];
struct patient *currPat;
struct details *all = NULL;
struct patient *patient = NULL;

struct details *copy(){

	struct details *curr;
	
	curr = (struct details *) malloc(sizeof(struct details));
	struct details *now = curr;
	strcpy(curr->doctor, "Mario");
	strcpy(curr->schedule, "Monday - Wednesday\n\t       From 10 AM - 6PM");
	strcpy(curr->clinic, clinic[0]);
	strcpy(curr->costDoc,"700000");
	curr->list = NULL;
	
	curr->next = (struct details *) malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Marimar");
	strcpy(curr->schedule, "Thursday - Saturday\n\t       From 8 AM - 4PM");
	strcpy(curr->clinic, clinic[0]);
	strcpy(curr->costDoc,"700000");
	curr->list = NULL;
	
	curr->next = (struct details *) malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Maria");
	strcpy(curr->schedule, "Monday - Wednesday\n\t       From 10 AM - 6PM");
	strcpy(curr->clinic, clinic[1]);
	strcpy(curr->costDoc,"500000");
	curr->list = NULL;
	
	curr->next = (struct details *) malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Marvel");
	strcpy(curr->schedule, "Thursday - Saturday\n\t       From 8 AM - 4PM");
	strcpy(curr->clinic, clinic[1]);
	strcpy(curr->costDoc,"500000");
	curr->list = NULL;
	
	curr->next = (struct details *) malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Marcel");
	strcpy(curr->schedule, "Monday - Wednesday\n\t       From 10 AM - 6PM");
	strcpy(curr->clinic, clinic[2]);
	strcpy(curr->costDoc,"400000");
	curr->list = NULL;
	
	curr->next = (struct details *) malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Martin");
	strcpy(curr->schedule, "Thursday - Saturday\n\t       From 8 AM - 4PM");
	strcpy(curr->clinic, clinic[2]);
	strcpy(curr->costDoc,"400000");
	curr->list = NULL;
	
	curr->next = (struct details *) malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Marino");
	strcpy(curr->schedule, "Monday - Wednesday\n\t       From 10 AM - 6PM");
	strcpy(curr->clinic, clinic[3]);
	strcpy(curr->costDoc,"100000");
	curr->list = NULL;
	
	curr->next = (struct details *) malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Marion");
	strcpy(curr->schedule, "Thursday - Saturday\n\t       From 8 AM - 4PM");
	strcpy(curr->clinic, clinic[3]);
	strcpy(curr->costDoc,"100000");
	curr->list = NULL;
	
	curr->next = NULL;

	return now;
}

struct details *display(struct details *all){
	
	cls
	
	int i, j;
	struct details *curr;

	printf("LIST OF DOCTORS\n\n");

	curr = all;
	for (i = 0; i < 4; i++){
	    printf("-- %s --\n", clinic[i]);
	    for (j = 0; j < 2; j++){
		    printf("%d. Doctor    : %s\n", j+1, curr->doctor);
		    printf("   Schedule  : %s\n\n", curr->schedule);
	    	curr = curr->next;
    	}
	}
	press 
	getchar();
	cls
	
	return all;
}

struct details *Regis(struct details *all) {
  
	cls
  
	int i, j=1;
	struct details *curr = (struct details *)malloc(sizeof(struct details));
	struct details *now = curr;
	struct patient *currPat;

	if (curr->list == NULL) {
		currPat = (struct patient *) malloc(sizeof(struct patient));
	}

	printf("REGISTER\n\n");

	curr = all;
	printf("Choose Clinic That You Want!\n\n");
	for (i = 0; i < 4; i++){
    	printf("%d. %s\n", j, clinic[i]);
    	j++;
	}
	
	int option, count = 0;
	
	sign scanf("%d", &option); getchar();
	
	cls
	while(1){
		if (strcmp(curr->clinic, clinic[option - 1]) == 0){
			break;
	    } 
		else{
	      curr = curr->next;
	      count++;
	    }
	}
	
	printf("REGISTER\n\n");
	printf("Choose Doctor That You Want\n\n");
	
	for (i = 0; i < 2; i++) {
	    printf("%d. Doctor    : %s\n", i+1, curr->doctor);
	    printf("   Schedule  : %s\n", curr->schedule);
	    curr = curr->next;
	}
	sign scanf("%d", &option); getchar();
	
	curr = all;
	for (i = 0; i < count + option - 1; i++) {
    	curr = curr->next;
	}
	currPat = curr->list;

	char word[100];

	if(currPat == NULL){
		currPat = (struct patient *)malloc(sizeof(struct patient));
	    curr->list = currPat;
	}
	else{
		while (currPat->next != NULL) {
    		currPat = currPat->next;
		}
	    currPat->next = (struct patient *)malloc(sizeof(struct patient));
	    currPat = currPat->next;
	}
	
	cls
	
	printf("REGISTER\n\n");
	printf("Please Fill Out Your Biodata\n\n");
	
	printf("Enter Your Name\t\t\t\t: ");
	scanf("%[^\n]", &word); getchar();
	strcpy(currPat->name, word);
	  
	printf("Enter Your Birth (dd/mm/yy)\t\t: ");
	scanf("%[^\n]", &word); getchar();
	strcpy(currPat->birth, word);
	
	printf("Enter Your Age\t\t\t\t: ");
	scanf("%[^\n]", &word); getchar();
	strcpy(currPat->age, word);
	
	printf("Enter Your Address\t\t\t: ");
	scanf("%[^\n]", &word); getchar();
	strcpy(currPat->address, word);
	
	printf("Enter Your Status (BPJS / Inhealth)\t: ");
	scanf("%[^\n]", &word); getchar();
	strcpy(currPat->status, word);
	
	printf("\nYour Name Is Registred!\n");
	press getchar();
	
	cls
	currPat->next = NULL;

	return all;
}

struct details *Queue(struct details *all) {
	
	cls
	
	int i, j = 1;
	struct details *curr;
	struct patient *currPat;

	printf("HOSPITAL QUEUE\n\n");
	printf("What Is Your Clinic?\n\n");
	
	curr = all;
	
	for (i = 0; i < 4; i++){
		printf("%d. %s\n", j, clinic[i]);
    	j++;
	}

	int option, count = 0;
		
	sign scanf("%d", &option); getchar();
	
	cls
	while(1){
	    if(strcmp(curr->clinic, clinic[option - 1]) == 0) {
	    	break;
	    } 
		else{
	      curr = curr->next;
	      count++;
	    }
	}

    currPat = curr->list;
	i = 0;
	
	printf("HOSPITAL QUEUE\n\n");
	printf("Doctor %s Queue :\n",curr->doctor);
	
	if(currPat!=NULL){
		while(currPat !=NULL){
			i++;
			printf("  Patient's Name : %s\n",currPat->name);
			printf("  Queue Number   : %d\n\n", i);
	    currPat = currPat->next;
		}
	}	
	else{
		printf("  There's No Patient For This Doctor\n\n",curr->doctor);
	}
	
	curr=curr->next;
	currPat = curr->list;
	i = 0;
	
	printf("\n\n");
	printf("Doctor %s Queue :\n",curr->doctor);
	
	if(currPat!=NULL){
		while(currPat != NULL){
			i++;
			printf("  Patient's Name : %s\n", currPat->name);
			printf("  Queue Number   : %d\n\n", i);
	    	currPat = currPat->next;
		}
	}
	else{
		printf("  There's No Patient For This Doctor\n\n",curr->doctor);
	}
	press
	getchar();
	cls
	
	return all;
}

struct details *Pharmacy(struct details *all){
	
	cls
	
	int i, j = 1;
    struct details *curr;
	struct details *now = curr;
	
	curr = all;
	printf("PHARMACY\n\n");
	printf("Choose Clinic What You Want\n\n");
	
	for (i = 0; i < 4; i++) {
	    printf("%d. %s\n", j, clinic[i]);
	    j++;
	}

	int option, count = 0;
	
	sign scanf("%d", &option); getchar();
	
	cls
	while (1){
	    if (strcmp(curr->clinic, clinic[option - 1]) == 0) {
	    	break;
	    }
		else{ 
		    curr = curr->next;
		    count++;
		}
	}
	
	printf("PHARMACY\n\n");
	printf("Choose Doctor That You Want\n\n");
	
	for (i = 0; i < 2; i++) {
    	printf("%d. Doctor    : %s\n", i+1, curr->doctor);
    	curr = curr->next;
	}
	
	sign scanf("%d", &option); getchar();
	
	curr = all;
	for (i = 0; i < count + option - 1; i++) {
    	curr = curr->next;
	}	
	
	currPat=curr->list;
	if(currPat == NULL){
		printf("\nNo Patient!\n\n");
		press
		getchar();
		
		return all;
	}
	
	cls
	strcpy(pharmacyQ[q].name,currPat->name);
	
	printf("PHARMACY\n\n");
	printf("Details For %s Before Go To Pharmacy\n\n",currPat->name);
	printf("Diagnosis  : ");
	
	scanf("%[^\n]", pharmacyQ[q].diagnosis); getchar();
	
	int val = rand()%3;
	int vol = rand()%3;
	
	if(strcmp(curr->clinic, clinic[0])==0){
		strcpy(pharmacyQ[q].medication, neurologists[val]);
		strcpy(pharmacyQ[q].costMed, price[vol]);
	}
	else if(strcmp(curr->clinic, clinic[1])==0){
		strcpy(pharmacyQ[q].medication, radiologists[val]);
		strcpy(pharmacyQ[q].costMed, price[vol]);
	}
	else if(strcmp(curr->clinic, clinic[2])==0){
		strcpy(pharmacyQ[q].medication, pediatricians[val]);
		strcpy(pharmacyQ[q].costMed, price[vol]);
	}		
	else if(strcmp(curr->clinic, clinic[3])==0){
		strcpy(pharmacyQ[q].medication, cardiologists[val]);
		strcpy(pharmacyQ[q].costMed, price[vol]);
	}
	
	printf("Medication : %s\n\n", pharmacyQ[q].medication);
	
	strcpy(pharmacyQ[q].status,currPat->status);
	strcpy(pharmacyQ[q].costDoc,curr->costDoc);
	strcpy(pharmacyQ[q].costAdm,"10000");
	q++;
	
	printf("Your Medicine Is Registred!\n");
	
	press getchar();
	
    if(curr->list!= NULL){
        curr->list=currPat->next;
        return all; free(curr);
    }
    
    return all;
}

void displayPat();
void deletePat();

int main(){
	
	int option;
	all = copy();
	
	while(true){  
		cls
		
		printf("- WELCOME TO HEPI HOSPITAL -\n\n");
		printf("Please Choose The Menu!\n");
	    printf("1. List of Doctors\n");
	    printf("2. Take Your Queue\n");
	    printf("3. Diplay Hospital Queue\n");
	    printf("4. Send Patient To Pharmacy\n");
	    printf("5. Display Pharmacy Queue\n");
	    printf("6. Take Drugs And Payment\n");
		printf("0. Exit\n");
		
	    sign scanf("%d", &option); getchar();
	    
	    switch (option){
	    case 1:
	    	all = display(all);
	    	break;
	    case 2:
	    	all = Regis(all);
	    	break;
	    case 3:
	    	all = Queue(all);
	    	break;
	    case 4:
	    	all = Pharmacy(all);
	    	break;
	    case 5:
	    	displayPat();
	    	break;
	    case 6:
	    	deletePat();
	    	break;
	    case 0:
	    	return 0;
	    default:
            printf("Input Invalid!\n");
            break;
	    } 
	}
	return 0;
}

void displayPat(){
	
	cls
	
	int i, j = 0;
	
	printf("PHARMACY QUEUE\n\n");
	
	if(strcmp(pharmacyQ[qRes].name,"") != 0){
		for(i = qRes; i < q; i++){
			printf("%d. Patients Name\t: %s\n", j+1, pharmacyQ[i].name);
			printf("   Diagnosis\t\t: %s\n", pharmacyQ[i].diagnosis);
			printf("   Medication\t\t: %s\n", pharmacyQ[i].medication);
			printf("   Queue Number\t\t: %d\n\n", j+1);	
			j++;
		}
	}
	else{
		printf("No Queue\n\n");
	}
	
	press 
	getchar();
}
 
void deletePat(){
	
	cls
	
	int i, j;
	printf("PAYMENT QUEUE\n\n");
 	
	long long total = atoi(pharmacyQ[qRes].costMed) + atoi(pharmacyQ[qRes].costDoc) + atoi(pharmacyQ[qRes].costAdm);
	
	if(strcmp(pharmacyQ[qRes].name,"") != 0){
		if(strcmp(pharmacyQ[qRes].status,"BPJS")!=0 && strcmp(pharmacyQ[qRes].status,"bpjs")!=0){
			printf("Total Payment For %s\n",pharmacyQ[qRes].name);
			printf("Drug\t\t\t: %s\n",pharmacyQ[qRes].costMed);
			printf("Doctor's Services\t: %s\n",pharmacyQ[qRes].costDoc);
			printf("Administration\t\t: %s\n\n",pharmacyQ[qRes].costAdm);
			printf("Total Payment\t\t: %lld\n\n",total);
			 	
			printf("Please Complete Your Payment In Cashier!\n\n");
		}	
		else{
			printf("Payment For %s\n", pharmacyQ[qRes].name);
			printf("The Costs Are Covered By The Insurance\n\n");
		}
		
		FILE *fp = fopen("archive.txt", "a");
		
		for(j = 0; j < 1; j++){
			fprintf(fp, "%s#%s#%s#%s#%s#\n", currPat->name, currPat->age, currPat->birth,currPat->address,currPat->status);
			fprintf(fp, "--%s#%s#%s#%s#%s#\n", pharmacyQ[qRes].medication,pharmacyQ[qRes].diagnosis,pharmacyQ[qRes].costMed,pharmacyQ[qRes].costDoc,pharmacyQ[qRes].costAdm);
		}
		fclose(fp);
		
		qRes++;
	}
	else{
		printf("No Queue\n\n");
	}
	
	press 
	getchar();
 }
