#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 8
  
struct student
{ 
	char name[50];  
	int roll;   
	int attendance[MAX_COURSES];
	float total_attendance;

};
struct student students[MAX_STUDENTS];
int total_students = 0; 

int login()   // User Authentication
{
    char username[50], password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) 
	{
        return 1;
    }

    return 0;                      
}
 
void insert_student() 
{
    int i, total_classes, missed_classes, attended_classes, total_attended_classes = 0, total_total_classes = 0;
    float total_attendance = 0;

    struct student s;

    printf("Enter name: ");
    scanf("%s", s.name);

    printf("Enter roll number: ");
    scanf("%d", &s.roll);

    printf("Enter attendance for each course:\n");
    for (i = 1; i <= MAX_COURSES; i++) {
        printf("\nCourse %d:\n", i);

        printf("Enter the total number of classes: ");
        scanf("%d", &total_classes);

        printf("Enter the number of classes missed: ");
        scanf("%d", &missed_classes);

        attended_classes = total_classes - missed_classes;

        float attendance = (float)attended_classes / total_classes * 100;

        printf("Attendance = %.2f%%\n", attendance);

        total_attended_classes += attended_classes;
        total_total_classes += total_classes;

        s.attendance[i-1] = attendance;
    }

    total_attendance = (float)total_attended_classes / total_total_classes * 100;

    printf("\nAggregate Attendance = %.2f%%\n", total_attendance);
    if(total_attendance<75)
        printf("Your attendence is less than 75 percentage, Start attending classes regularly to avoid detention.\n");

    s.total_attendance = total_attendance;

    students[total_students] = s;
    total_students++;

    printf("Student details added successfully!\n");
}


void display_students ()   
{  
	printf ("Total students: %d\n", total_students);  
	printf ("Name\tRoll\tAggregate attendance\tAttendance\n");
	int i,j;  
	for (i = 0; i < total_students; i++)
    {      
		printf ("%s\t%d\t%.2f%%\t\t\t", students[i].name, students[i].roll,students[i].total_attendance);      
		for (j = 0; j < MAX_COURSES; j++)
		{	  
			printf ("%d ", students[i].attendance[j]);	
		}
		printf ("\n");
	} 
}  

void search_student_by_roll_number()
{  
	int roll,i;  
	printf ("Enter roll number to search: ");  
	scanf ("%d", &roll);  
	for (i = 0; i < total_students; i++)
    {      
		if (students[i].roll == roll)
		{	  
			printf ("Name: %s\n", students[i].name); 
			printf ("Roll: %d\n", students[i].roll);
			printf("Aggregate Attendance: %.2f%%\n", students[i].total_attendance);	  
			printf ("Attendance:\n");
			int j;	  
			for (j = 0; j < MAX_COURSES; j++)
			{      
				printf ("Course %d: %d\n", j + 1, students[i].attendance[j]);	    
			} 
			return;	
		}    
	}                               
	printf ("\nStudent not found.\n");
}
 
void search_student_by_name() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    int i, j;
    int found = 0;
    for (i = 0; i < total_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Name: %s\n", students[i].name);
            printf("Roll: %d\n", students[i].roll);
            printf("Aggregate Attendance: %.2f%%\n", students[i].total_attendance);
            printf("Attendance:\n");
            for (j = 0; j < MAX_COURSES; j++) {
                printf("Course %d: %d\n", j + 1, students[i].attendance[j]);
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nStudent not found.\n");
    }
}

void delete_student ()
{  
	int roll,i,j;  
	printf ("Enter roll number to delete: ");  
	scanf ("%d", &roll);  
	for (i = 0; i < total_students; i++)
    {      
		if (students[i].roll == roll)
		{	  
			for (j = i; j < total_students - 1; j++)
	    	{	      
				students[j] = students[j + 1];	    
			} 
			total_students--;	  
			printf ("\nStudent details deleted successfully!\n");	  
			return;	
		}    
	}  
	printf ("\nStudent not found.\n");
}
 
void modify_student ()
{           
	int roll,i;  
	printf ("Enter roll number to modify: ");  
	scanf ("%d", &roll);  
	for (i = 0; i < total_students; i++)
    	{      
			if (students[i].roll == roll)
			{	  
			printf ("Enter new details:\n");	  
			printf ("Enter name: ");	  
			scanf ("%s", students[i].name);	  
			printf ("Enter roll number: ");	  
			scanf ("%d", &students[i].roll);	  
			printf ("Enter attendance for each course:\n");
			int j;	                                                            
			for (j = 0; j < MAX_COURSES; j++)
	    		{	      
				printf ("Course %d: ", j + 1);	      
				scanf ("%d", &students[i].attendance[j]);	                        
				} 
			printf ("\nStudent details modified successfully!\n");
			return;	
			}   
		}  
	printf ("\nStudent not found.\n");
} 

int attendence_percentage() {
    int total_classes, attended_classes;
    float attendance_percentage;

    printf("Enter the total number of classes held: ");
    scanf("%d", &total_classes);

    printf("Enter the number of classes attended: ");
    scanf("%d", &attended_classes);

    attendance_percentage = (float)attended_classes / total_classes * 100;

    printf("Attendance percentage = %.2f%%\n", attendance_percentage);

    if (attendance_percentage >= 75) {
        printf("\nYou are eligible to take the exam.\n");
    } else {
        printf("\nSorry, you are not eligible to take the exam.\n");
    }

    return 0;
}

void save_data ()
{  
	FILE * fp;                                 
	fp = fopen ("students.dat", "wb");  
	if (fp == NULL)
    	{      
		printf ("\nError in opening file.\n");       
		return;  
		}  
	fwrite (&total_students, sizeof (total_students), 1, fp);  
	fwrite (students, sizeof (struct student), total_students, fp);  
	fclose (fp);  
	printf ("\nData saved successfully!\n");
}  

void load_data ()
{                          
	FILE * fp;  
	fp = fopen ("students.dat", "rb");  
	if (fp == NULL)
    {      
		printf ("\nError in opening file.\n");      
		return;    
	}  
	fread (&total_students, sizeof (total_students), 1, fp);  
	fread (students, sizeof (struct student), total_students, fp);  
	fclose (fp);  
	printf ("\nData loaded successfully!\n");
}  

int main ()
{  
	int choice;  
	int authenticated = login ();  
	if (!authenticated)
	{      
		printf ("\nAuthentication failed. Exiting program.\n");      
		return 0;   
	}              

	load_data ();     
	while (1)
    	{      
			printf ("\nEnter your choice:\n");      
			printf ("1. Insert student details\n");      
			printf ("2. Display all student details\n");      
			printf ("3. Search student details by Roll number\n");
			printf ("4. Search student details by Name\n");
			printf ("5. Calculate Attendance\n");      
			printf ("6. Delete student details\n");      
			printf ("7. Modify student details\n");      
			printf ("8. Save data to file\n");      
			printf ("9. Exit\n\n");      
			
			scanf ("%d", &choice);     

	switch(choice)
	{	
	case 1:
		insert_student ();	  
	break;	
	
	case 2:
		display_students ();	  
	break;	

	case 3:
		search_student_by_roll_number ();	  
	break;

	case 4:
		search_student_by_name ();	  
	break;

	case 5:
		attendence_percentage ();	  
	break;

	case 6:
		delete_student ();	  
	break;

	case 7:
		modify_student ();	  
	break;	

	case 8:
		save_data ();	  
	break;										
	
	case 9:
		printf ("\nExiting program.\n");	  
	save_data ();	  
	return 0;	
	
	default:
	  printf ("\nInvalid choice.\n");	
	}   
		}  
return 0;

}
