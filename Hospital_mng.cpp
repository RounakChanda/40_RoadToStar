#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct patient
{
	int id;
	char patientname[50];
	char patientaddress[100];
	char disease[40];
	char date[14];
	char suggestion[40];
} p;

struct doctor
{
	int id;
	char doctorname[50];
	char specialization[30];
	char diagonistic_address[40];
	char date[14];
} d;

struct user
{
	char fullName[50];
	char email[50];
	char password[50];
	char username[50];
	char phone[50];
};

void takeinput(char ch[50])
{
	fgets(ch, 50, stdin);
	ch[strlen(ch) - 1] = 0;
}

char generateUsername(char email[50], char username[50])
{
	// abc123@gmail.com
	for (int i = 0; i < strlen(email); i++)
	{
		if (email[i] == '@')
		{
			break;
		}
		else
		{
			username[i] = email[i];
		}
	}
}

void takepassword(char pwd[50])
{
	int i;
	char ch;
	while (1)
	{
		ch = getch();
		if (ch == ENTER || ch == TAB)
		{
			pwd[i] = '\0';
			break;
		}
		else if (ch == BCKSPC)
		{
			if (i > 0)
			{
				i--;
				printf("\b \b");
			}
		}
		else
		{
			pwd[i++] = ch;
			printf("* \b");
		}
	}
}

FILE *fp;

int generateUniqueID()
{
	// Get current timestamp
	time_t currentTime;
	time(&currentTime);

	// Generate a random number

	int randomNum = rand();

	// Combine timestamp and random number to create a unique ID
	int uniqueID = (int)currentTime + randomNum;

	return uniqueID;
}

void admitPatient()
{
	{
		system("cls");

		// Initialize random seed
		srand(time(NULL));

		// Generate and print unique ID
		p.id = generateUniqueID();

		printf("Patient id is: %d\n", p.id);

		int n;

		char myDate[14];
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
		strcpy(p.date, myDate);

		fp = fopen("patient.csv", "ab");

		// p.id=id;

		printf("Enter Name of Patient: ");
		fflush(stdin);
		gets(p.patientname);

		printf("Enter Address of Patient: ");
		fflush(stdin);
		gets(p.patientaddress);

		printf("Enter Disease of Patient: ");
		fflush(stdin);
		gets(p.disease);

		printf("\nPatient details successfully registered\n\n");

		// break;

		fwrite(&p, sizeof(p), 1, fp);
		fclose(fp);
	}
}

void patientList()
{
	system("cls");
	printf("<----Patient List---->\n\n");
	printf("%-10s %-30s %-30s %-20s %s\n", "Id", "Patient Name", "Address", "Disease", "Date");
	printf("---------------------------------------------------------------------------------------------------------\n");

	fp = fopen("patient.csv", "rb");
	while (fread(&p, sizeof(p), 1, fp) == 1)
	{
		printf("%-10d %-30s %-30s %-20s %s\n", p.id, p.patientname, p.patientaddress, p.disease, p.date);
	}

	fclose(fp);
	
}

void manageDoctor()
{
	{
		system("cls");
		system("color 0b");
		FILE *fp;
		int opt, usrFound = 0;
		struct user user;
		char password2[50];

		printf("\n\t\t\t\t----------Welcome to authentication system----------");
		printf("\nPlease choose your operation");
		printf("\n1.Signup");
		printf("\n2.Login");
		printf("\n3.Exit");

		printf("\n\nYour choice:\t");
		scanf("%d", &opt);
		fgetc(stdin);

		switch (opt)
		{
		case 1:
			system("cls");
			printf("\nEnter your full name:\t");
			takeinput(user.fullName);
			printf("Enter your email:\t");
			takeinput(user.email);
			printf("Enter your contact no:\t");
			takeinput(user.phone);
			printf("Enter your password:\t");
			takepassword(user.password);
			printf("\nConfirm your password:\t");
			takepassword(password2);

			if (!strcmp(user.password, password2))
			{
				generateUsername(user.email, user.username);
				fp = fopen("Users.dat", "a+");
				fwrite(&user, sizeof(struct user), 1, fp);
				if (fwrite != 0)
					printf("\n\nUser resgistration success, Your username is %s", user.username);
				else
					printf("\n\nSorry! Something went wrong :(");
				fclose(fp);
			}
			else
			{
				printf("\n\nPassword donot matched");
				Beep(750, 300);
			}
			break;

		case 2:

			char username[50], pword[50];
			struct user usr;

			printf("\nEnter your username:\t");
			takeinput(username);
			printf("Enter your password:\t");
			takepassword(pword);

			fp = fopen("Users.dat", "r");
			while (fread(&usr, sizeof(struct user), 1, fp))
			{
				if (!strcmp(usr.username, username))
				{
					if (!strcmp(usr.password, pword))
					{
						system("cls");
//						printf("\n\t\t\t\t\t\tWelcome %s", usr.fullName);
//						printf("\n\n|Full Name:\t%s", usr.fullName);
//						printf("\n|Email:\t\t%s", usr.email);
//						printf("\n|Username:\t%s", usr.username);
//						printf("\n|Contact no.:\t%s", usr.phone);

char myDate[14];
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
			sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
			strcpy(d.date, myDate);

			system("cls");
			printf("<----Add Doctor---->\n\n");

			fp = fopen("doctor.csv", "ab");

			printf("Enter doctor id: ");
			fflush(stdin);
			scanf("%d", &d.id);

			printf("Enter doctor name: \n");
			fflush(stdin);
			gets(d.doctorname);

			printf("Enter doctor's address: \n");
			fflush(stdin);
			gets(d.diagonistic_address);

			printf("Specialization of Doctor: \n");
			fflush(stdin);
			gets(d.specialization);

			printf("Doctor added successfully\n\n");

			fwrite(&d, sizeof(d), 1, fp);
			fclose(fp);
			fflush(stdin);
					}
					else
					{
						printf("\n\nInvalid Password!");
						Beep(800, 300);
					}
					usrFound = 1;
				}
			}
			if (!usrFound)
			{
				printf("\n\nUser is not registered!");
				Beep(800, 300);
			}
			fclose(fp);
			break;

		case 3:
			printf("\t\t\tBye Bye :)");
			break;
			getch();

		default:
			printf("Invalid username or password: ");
			break;
			printf("\nPress any key to continue....\n\n");
			getch();
			system("cls");
		}


	}
}

void doctorList()
{

	//	pwd[i]='\0'

	system("cls");
	printf("<----Doctor List---->\n\n");
	printf("%-10s %-30s %-30s %-20s %s\n", "Id", "Doctor Name", "Doctor Address", "Specialization", "Date");
	printf("---------------------------------------------------------------------------------------------------------\n");

	fp = fopen("doctor.csv", "rb");
	while (fread(&d, sizeof(d), 1, fp) == 1)
	{
		printf("%-10d %-30s %-30s %-20s %s\n", d.id, d.doctorname, d.diagonistic_address, d.specialization, d.date);
	}

	fclose(fp);
}

void deletePatientRecord(int idToDelete)
{
	FILE *temp;
	FILE *patientFile;
	
	struct patient tempPatient;
	
	patientFile = fopen("patient.csv", "rb");
	temp=fopen("temp.csv", "wb");
	
	if(patientFile == NULL || temp == NULL)
	{
		printf("Error opening file!!!!\n");
		return ;
	}
	
	while(fread(&p,sizeof(p),1,patientFile))
	{
		if(p.id != idToDelete)
		{
			fwrite(&p, sizeof(p),1,temp);
		}
	}
	
	fclose(patientFile);
	fclose(temp);
	
	remove("patient.csv");
	rename("temp.csv", "patient.csv");
	
	printf("Patient Record with Id %d deleted successfully!!!!!\n",idToDelete);
	
}

void deletePatient()
{
	{
	system("cls");
	system("color 0b");
	FILE *fp;
	int opt,usrFound = 0;
	struct user user;
	char password2[50];
	
	printf("\n\t\t\t\t----------Welcome to authentication system----------");
	printf("\nPlease choose your operation");
	printf("\n1.Signup");
	printf("\n2.Login");
	printf("\n3.Exit");
	
	printf("\n\nYour choice:\t");
	scanf("%d",&opt);
	fgetc(stdin);
	
	switch(opt){
		case 1:
			system("cls");
			printf("\nEnter your full name:\t");
			takeinput(user.fullName);
			printf("Enter your email:\t");
			takeinput(user.email);
			printf("Enter your contact no:\t");
			takeinput(user.phone);
			printf("Enter your password:\t");
			takepassword(user.password);
			printf("\nConfirm your password:\t");
			takepassword(password2);
			
			if(!strcmp(user.password,password2)){
				generateUsername(user.email,user.username);
				fp = fopen("Users.dat","a+");
				fwrite(&user,sizeof(struct user),1,fp);
				if(fwrite != 0) printf("\n\nUser resgistration success, Your username is %s",user.username);
				else printf("\n\nSorry! Something went wrong :(");
				fclose(fp);
			}
			else{
				printf("\n\nPassword donot matched");
				Beep(750,300);
			}
		break;
		
		case 2:

			char username[50],pword[50];
			struct user usr;
			
			printf("\nEnter your username:\t");
			takeinput(username);
			printf("Enter your password:\t");
			takepassword(pword);
			
			fp = fopen("Users.dat","r");
			while(fread(&usr,sizeof(struct user),1,fp)){
				if(!strcmp(usr.username,username)){
					if(!strcmp(usr.password,pword)){	
						
						int idToDelete;
	printf("\n\nId of the patient you want to delete: \n");
	scanf("%d", &idToDelete);
	
	deletePatientRecord(idToDelete);
					}
					else {
						printf("\n\nInvalid Password!");
						Beep(800,300);
					}
					usrFound = 1;
				}
			}
			if(!usrFound){
				printf("\n\nUser is not registered!");
				Beep(800,300);
			}
			fclose(fp);
			break;
			
		case 3:
			printf("\t\t\tBye Bye :)");
			exit(0);
		
		default:
			printf("Invalid username or password: ");
			break;
			printf("\nPress any key to continue....\n\n");
			exit(0);
			system("cls");	
}
}
}



void deleteDoctorRecord(int idtodelete)
{
	FILE *tempdoc;
	FILE *doctorFile;
	
	struct patient tempDoctor;
	
	doctorFile = fopen("doctor.csv", "rb");
	tempdoc=fopen("tempdoc.csv", "wb");
	
	if(doctorFile == NULL || tempdoc == NULL)
	{
		printf("Error opening file!!!!\n");
		return ;
	}
	
	while(fread(&d,sizeof(d),1,doctorFile))
	{
		if(d.id != idtodelete)
		{
			fwrite(&d, sizeof(d),1,tempdoc);
		}
	}
	
	fclose(doctorFile);
	fclose(tempdoc);
	
	remove("doctor.csv");
	rename("tempdoc.csv", "doctor.csv");
	
	printf("Doctor Record with Id %d deleted successfully!!!!!\n",idtodelete);
	
}

void deleteDoctor()
{
	{
	system("cls");
	system("color 0b");
	FILE *fp;
	int opt,usrFound = 0;
	struct user user;
	char password2[50];
	
	printf("\n\t\t\t\t----------Welcome to authentication system----------");
	printf("\nPlease choose your operation");
	printf("\n1.Signup");
	printf("\n2.Login");
	printf("\n3.Exit");
	
	printf("\n\nYour choice:\t");
	scanf("%d",&opt);
	fgetc(stdin);
	
	switch(opt){
		case 1:
			system("cls");
			printf("\nEnter your full name:\t");
			takeinput(user.fullName);
			printf("Enter your email:\t");
			takeinput(user.email);
			printf("Enter your contact no:\t");
			takeinput(user.phone);
			printf("Enter your password:\t");
			takepassword(user.password);
			printf("\nConfirm your password:\t");
			takepassword(password2);
			
			if(!strcmp(user.password,password2)){
				generateUsername(user.email,user.username);
				fp = fopen("Users.dat","a+");
				fwrite(&user,sizeof(struct user),1,fp);
				if(fwrite != 0) printf("\n\nUser resgistration success, Your username is %s",user.username);
				else printf("\n\nSorry! Something went wrong :(");
				fclose(fp);
			}
			else{
				printf("\n\nPassword donot matched");
				Beep(750,300);
			}
		break;
		
		case 2:

			char username[50],pword[50];
			struct user usr;
			
			printf("\nEnter your username:\t");
			takeinput(username);
			printf("Enter your password:\t");
			takepassword(pword);
			
			fp = fopen("Users.dat","r");
			while(fread(&usr,sizeof(struct user),1,fp)){
				if(!strcmp(usr.username,username))
				{
					if(!strcmp(usr.password,pword))
					{	
						system("cls");
						int idtodelete;
						printf("Id of the doctor you want to delete: ");
						scanf("%d", &idtodelete);
						deleteDoctorRecord(idtodelete);
						exit(0);
						printf("Press any key to continue....\n");
						getch();
					}
						else 
					{
						printf("\n\nInvalid Password!");
						Beep(800,300);
					}
					usrFound = 1;
				}
			}
			if(!usrFound){
				printf("\n\nUser is not registered!");
				Beep(800,300);
			}
			fclose(fp);
			break;
			
		case 3:
			printf("\t\t\tBye Bye :)");
			exit(0);
		
		default:
			printf("Invalid username or password: ");
			break;
			printf("\nPress any key to continue....\n\n");
			getch();	

	
	
}
}
}

int main()
{

	system("color 0b");
	int ch;

	while (1)
	{
		system("cls");
		printf("<-*-*-HOSPITAL MANAGEMENT SYSTEM-*-*-\n\n>");
		printf("Select your role:- \n");
		printf("1.User\n");
		printf("2.Hospital Admins\n");
		printf("3.Patient List\n");
		printf("4.Doctor List\n");
		printf("5.Delete patient records\n");
		printf("6.Delete doctor records\n");
		printf("0.Exit\n");

		printf("Enter your option: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 0:
			exit(0);

		case 1:
			admitPatient();
			break;

		case 2:
			manageDoctor();
			break;

		case 3:
			patientList();
			break;

		case 4:
			doctorList();
			break;
			
		case 5:
			deletePatient();
			break;
		
		case 6:
			deleteDoctor();
			break;

		deafult:
			printf("Invalid option..../");
			break;
		}
		printf("\nPress any key to continue....\n\n");
		getch();
		system("cls");
	}
	return 0;
}
