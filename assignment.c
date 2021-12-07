#include <stdio.h>
#include <string.h>
#define SIZE 100

struct Citizen
{
    int id;
    char name[50];
    char gender[10];
    int yearOfBirth;
    int dosesTaken;
};

struct VaccineCentre
{
    int id;
    char address[50];
    char district[30];
    int pin;
    char centreType[15];
    char vaccineType[6][15];
    int amount[6];
    int prices[6];
    int income;
};

struct Appointment
{
    int citizenID;
    int centreID;
    char vaccineType[15];
    char district[30];
    int bookedDose;
    int yearOfBirth;
};


void printCentre(struct VaccineCentre centre)
{
    printf("ID:%d\tAddress: %s\tDistrict: %s\tPIN: %d\tCentre Type:%s\n", centre.id, centre.address, centre.district, centre.pin, centre.centreType);
    for(int j = 0; j < 6; j++)
        if(centre.amount[j] != 0)
            printf("Vaccine Type: %s\tAmount: %d\tCost: %d\n", centre.vaccineType[j], centre.amount[j], centre.prices[j]);    
}


void testPrintAppointments(struct Appointment appointments[SIZE], int nA)
{
    for(int i = 0; i < nA; i++)
        printf("Citizen ID: %d\tCentre ID: %d\tVaccine Type: %s\tDistrict: %s\n", appointments[i].citizenID, appointments[i].centreID, appointments[i].vaccineType, appointments[i].district);
}

void testPrintCentres(struct VaccineCentre centres[SIZE], int nV)
{
    for(int i = 0; i < nV; i++)
    {
        printf("ID:%d\tAddress: %s\tDistrict: %s\tPIN: %d\tCentre Type:%s\tIncome earned: %d\n", centres[i].id, centres[i].address, centres[i].district, centres[i].pin, centres[i].centreType, centres[i].income);
        for(int j = 0; j < 6; j++)
            if(centres[i].amount[j] != 0)
                printf("Vaccine Type: %s\tAmount: %d\tCost: %d\n", centres[i].vaccineType[j], centres[i].amount[j], centres[i].prices[j]);

    }
}

void testPrintCitizens(struct Citizen citizens[SIZE], int nC)
{
    for(int i = 0; i < nC; i++)
    {
        printf("ID:%d\tName: %s\tGender: %s\tYOB: %d\tDoses Taken:%d\n", citizens[i].id, citizens[i].name, citizens[i].gender, citizens[i].yearOfBirth, citizens[i].dosesTaken);
    }
}

void mergeDistrict(struct VaccineCentre a[SIZE], int l, int m, int r)
{
    int i, j, k;
    int p = m - l + 1;
    int q = r - m;
  
    struct VaccineCentre left[p], right[q];
  
    for (i = 0; i < p; i++)
        left[i] = a[l + i];
    
    for (j = 0; j < q; j++)
        right[j] = a[m + 1 + j];
  
    i = 0; 
    j = 0; 
    k = l; 
    
    while (i < p && j < q)
    {
        if (strcmp(left[i].district, right[j].district) < 0)
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
  
    while (i < p)
    {
        a[k] = left[i];
        i++;
        k++;
    }
  
    while (j < q)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}
  
void mergeSortCentresByDistrict(struct VaccineCentre a[SIZE], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
  
        mergeSortCentresByDistrict(a, l, m);
        mergeSortCentresByDistrict(a, m + 1, r);
  
        mergeDistrict(a, l, m, r);
    }
}
  
void mergePin(struct VaccineCentre a[SIZE], int l, int m, int r)
{
    int i, j, k;
    int p = m - l + 1;
    int q = r - m;
  
    struct VaccineCentre left[p], right[q];
  
    for (i = 0; i < p; i++)
        left[i] = a[l + i];
    
    for (j = 0; j < q; j++)
        right[j] = a[m + 1 + j];
  
    i = 0; 
    j = 0; 
    k = l; 
    
    while (i < p && j < q)
    {
        if (left[i].pin < right[j].pin)
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
  
    while (i < p)
    {
        a[k] = left[i];
        i++;
        k++;
    }
  
    while (j < q)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}
  
void mergeSortCentresByPin(struct VaccineCentre a[SIZE], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
  
        mergeSortCentresByPin(a, l, m);
        mergeSortCentresByPin(a, m + 1, r);
  
        mergePin(a, l, m, r);
    }
}


void mergeAppsDistrict(struct Appointment a[SIZE], int l, int m, int r)
{
    int i, j, k;
    int p = m - l + 1;
    int q = r - m;
  
    struct Appointment left[p], right[q];
  
    for (i = 0; i < p; i++)
        left[i] = a[l + i];
    
    for (j = 0; j < q; j++)
        right[j] = a[m + 1 + j];
  
    i = 0; 
    j = 0; 
    k = l; 
    
    while (i < p && j < q)
    {
        if (strcmp(left[i].district, right[j].district) < 0)
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
  
    while (i < p)
    {
        a[k] = left[i];
        i++;
        k++;
    }
  
    while (j < q)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}
  
void mergeSortAppsByDistrict(struct Appointment a[SIZE], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
  
        mergeSortAppsByDistrict(a, l, m);
        mergeSortAppsByDistrict(a, m + 1, r);
  
        mergeAppsDistrict(a, l, m, r);
    }
}
 


/*
a. addNewBeneficiary():
- Input: Beneficiary full name, gender, year of birth [Beneficiary id should be a
unique and system generated number]
- Output: Display all the information after successful addition of record.
*/
void addNewBeneficiary(struct Citizen citizens[SIZE], int nC, int indexC)
{
    char name[50], gender[10];
    int yearOfBirth;

    getchar();


    printf("Enter the name: ");
    gets(name);

    printf("Enter the gender: ");
    gets(gender);

    printf("Enter the year of birth: ");
    scanf("%d", &yearOfBirth);

    citizens[nC].id = 10000 + indexC;
    strcpy(citizens[nC].name, name);
    strcpy(citizens[nC].gender, gender);
    citizens[nC].yearOfBirth = yearOfBirth;
    citizens[nC].dosesTaken = 0;
}

/*
b. addNewCenter():
- Input: centre ID, address, district, PIN code, centre type, vaccine type with their
respective quantity available for the day.
- Output: Display the message after successful addition of record.
*/
void addNewCentre(struct VaccineCentre centres[SIZE], int nV)
{
    int id, pin, amount[6];
    char address[50], district[30], centreType[15];
    char vaccineType[6][15] = {"covaxin","covishield","sputnik","zydus","Pfizer","moderna"};
    int prices[6] = {100, 200, 300, 400, 500, 600};
    char centreTypes[2][15] = {"government", "private"};
    
    printf("Enter ID: ");
    scanf("%d", &id);
    
    getchar();
    printf("Enter the address: ");
    gets(address);

    printf("Enter the district: ");
    gets(district);

    printf("Enter the PIN: ");
    scanf("%d", &pin);

    printf("Enter the centre type: \n");
    for(int j = 0; j < 2; j++)
        printf("%d. %s\n", j + 1, centreTypes[j]);

    int type;
    scanf("%d", &type);
        
    strcpy(centreType, centreTypes[type - 1]);


    for(int i = 0; i < 6; i++)
    {
        printf("Enter the amount of %s (enter 0 if unavailable): ", vaccineType[i]);
        scanf("%d", &amount[i]);
    }
    
    
    
    int index;
    if(nV == 0)
    {
        index = 0;
    }
    else if(id < centres[0].id)
    {
        for(int i = nV; i > 0; i--)
        {
            centres[i] = centres[i - 1];
        }
        
        index = 0;
    }
    else if(id > centres[nV - 1].id)
    {
        index = nV;
    }
    else
    {
        int i = 0, done = 0;
        while(i < nV - 1 && done == 0)
        {
            if(id > centres[i].id && id < centres[i + 1].id)
                done = 1;
            ++i;
        }

        for(int j = nV; j > i; j--)
        {
            centres[j] = centres[j - 1];
        }
        index = i;
        printf("\n%d\n", index);
    }
    
    centres[index].id = id;
    strcpy(centres[index].address, address);
    strcpy(centres[index].district, district);
    centres[index].pin = pin;
    strcpy(centres[index].centreType, centreType);

    for(int i = 0; i < 6; i++)
    {
        strcpy(centres[index].vaccineType[i], vaccineType[i]);    
        centres[index].amount[i] = amount[i];
        if(strcmp(centreType, centreTypes[0]) == 0)
            centres[index].prices[i] = 0;
        else
            centres[index].prices[i] = prices[i];
    }

    centres[index].income = 0;

}

/*
c. EnlistSortedCenters ():
- Input: Key field for the sorted list (Center ID/PIN code/District-wise)
- Output: Display the sorted list of centres based on key field.
*/
void enlistSortedCentres(struct VaccineCentre centres[SIZE], int nV)
{
    int type;
    printf("Enter type: \n1.ID\t2.PIN\t3.District\n");
    scanf("%d", &type);
    if(type == 1)
    {
        testPrintCentres(centres, nV);
    }
    else if(type == 2)
    {
        int minIndex, i, j;
        struct VaccineCentre pinSorted[SIZE];

        
        for(i = 0; i < nV; i++)
            pinSorted[i] = centres[i];
        
        mergeSortCentresByPin(pinSorted, 0, nV - 1);
        testPrintCentres(pinSorted, nV);

    }
    else if(type == 3)
    {
        
        int minIndex, i, j;
        struct VaccineCentre districtSorted[SIZE];

        for(i = 0; i < nV; i++)
            districtSorted[i] = centres[i];

        mergeSortCentresByDistrict(districtSorted, 0, nV - 1);
        testPrintCentres(districtSorted, nV);
     
    }
}

/*
d. getCentre():
- Input: Parameter for searching the center (Center ID/District/PIN code/center
type/vaccine type)
- Output: Display the list of centers based on search parameter.
*/
void getCentre(struct VaccineCentre centres[SIZE], int nV)
{
    
    int type;

    printf("Enter type: 1. Center ID\t2. District\t3. PIN\t4.center type\t5.vaccine type\n");
    scanf("%d", &type);

    int exists = 0;
    if(type == 1)
    {
        int id;

        printf("Enter ID: ");
        scanf("%d", &id);


        for(int i = 0; i < nV && exists == 0; i++)
        {
            if(centres[i].id == id)
            {
                printCentre(centres[i]);
                exists = 1;
            }
        }

    }
    else if(type == 2)
    {
        char district[30];

        getchar();
        printf("Enter the district: ");
        gets(district);

        for(int i = 0; i < nV; i++)
        {
            if(strcmp(centres[i].district, district) == 0)
            {
                printCentre(centres[i]);
                exists = 1;
            }
        }
        
    }
    else if(type == 3)
    {
        int pin;

        printf("Enter the PIN: ");
        scanf("%d", &pin);

        for(int i = 0; i < nV; i++)
        {
            if(centres[i].pin == pin)
            {
                printCentre(centres[i]);
                exists = 1;
            }
        }

        
    
    }
    else if(type == 4)
    {
        char centreType[30];
        
        int type;
        
        printf("Enter the centre type: \n1. Government\n2. Private\n");
        scanf("%d", &type);

        if(type == 1)
        {
            strcpy(centreType, "government");
        }
        else
        {
            strcpy(centreType, "private");
        }

        for(int i = 0; i < nV; i++)
        {
            if(strcmp(centres[i].centreType, centreType) == 0)
            {
                printCentre(centres[i]);
                exists = 1;
            }
        }


    }
    else if(type == 5)
    {
        char vaccineTypes[6][15] = {"covaxin","covishield","sputnik","zydus","Pfizer","moderna"};
        
        char vaccineType[15];
        int type;
        
        printf("Enter the vaccine type: \n");
        for(int j = 0; j < 6; j++)
        {
            printf("%d %s\n", j + 1, vaccineTypes[j]);
        }

        scanf("%d", &type);
        strcpy(vaccineType, vaccineTypes[type - 1]);
        for(int i = 0; i < nV; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if(strcmp(centres[i].vaccineType[j], vaccineType) == 0 && centres[i].amount[j] != 0)
                {
                    printCentre(centres[i]);
                    exists = 0;
                }
            }
        }


    }
    
}


/*
e. BookAppointment():
- Input: Beneficiary ID, Center ID, vaccine type
- Output:  Display the message after a successful booking.
*/
int bookAppointment(struct Appointment appointments[SIZE], int nA, struct VaccineCentre centres[SIZE], int nV, struct Citizen citizens[SIZE], int nC)
{
    char vaccineTypes[6][15] = {"covaxin","covishield","sputnik","zydus","Pfizer","moderna"};
    int prices[6] = {100, 200, 300, 400, 500, 600};

    
    int citizenID, centreID, type, yearOfBirth, bookedDose;
    char vaccineType[15];

    int check = 1, done = 0;
    
    
    printf("Enter citizen ID: ");
    scanf("%d", &citizenID);


    for(int i = 0; i < nC && done == 0; i++)
    {
        if(citizens[i].id == citizenID)
        {
            done = 1;
            if(2021 - citizens[i].yearOfBirth < 18)
            {
                printf("\nOnly 18 years and above are allowed to take the vaccine.\n");
                check = 0;
            }
            else
            {
                yearOfBirth = citizens[i].yearOfBirth;
                bookedDose = citizens[i].dosesTaken + 1;
            }
        }
    }

    if(done = 0)
    {
        printf("\nThe entered ID does not exist\n");
        check = 0;
    }
    for(int i = 0; i < nA; i++)
    {
        if(appointments[i].citizenID == citizenID)
        {
            printf("\nThe beneficiary has already made an appointment. \n");
            check = 0;
        }
    }

    if(check == 1)
    {
        

    
        printf("Enter centre ID: ");
        scanf("%d", &centreID);
        
        int i = 0;
        while(i < nV && done == 0)
        {
            if(centres[i].id == centreID)
                done = 1;
            else
                i++;
        }

        if(strcmp(centres[i].centreType, "government") == 0)
        {
            printf("Since this is a government centre, all vaccines are free.\nAvailable vaccines:\n");
            for(int j = 0; j < 6; j++)
            {
                if(centres[i].amount[j] != 0)
                {
                    printf("%d. Vaccine: %s\tAmount: %d \n", j + 1, centres[i].vaccineType[j], centres[i].amount[j]);    
                }
            }
        }
        else
        {
            for(int j = 0; j < 6; j++)
            {
                if(centres[i].amount[j] != 0)
                {
                    printf("%d. Vaccine: %s\tAmount: %d\tPrice: %d\n", j + 1, centres[i].vaccineType[j], centres[i].amount[j], centres[i].prices[j]);
                }
            }
        }
    


        printf("Enter vaccine type: ");
        scanf("%d", &type);
        centres[i].income += centres[i].prices[type - 1];

        
        done = 0;
        strcpy(appointments[nA].district, centres[i].district);
        strcpy(vaccineType, vaccineTypes[type - 1]);

        for(int j = 0; j < 6 && done == 0; j++)
        {
            if(strcmp(centres[i].vaccineType[j], vaccineType) == 0)
            {
                --centres[i].amount[j];
                done = 1;
            }
        }
    
        appointments[nA].citizenID = citizenID;
        appointments[nA].centreID = centreID;
        strcpy(appointments[nA].vaccineType, vaccineType);
        appointments[nA].bookedDose = bookedDose;
        appointments[nA].yearOfBirth = yearOfBirth;
    }
    return check;
}


/*
f. CancelAppointment():
- Input: Beneficiary ID
- Output: Display the message after a successful cancellation.
*/
void cancelAppointment(struct Appointment appointments[SIZE], int nA, struct VaccineCentre centres[SIZE], int nV)
{
    int citizenID, centreID, index;

    printf("Enter the citizen ID: ");
    scanf("%d", &citizenID);

    int i = 0, done = 0;
    while(i < nA && done == 0)
    {
                
        if(appointments[i].citizenID == citizenID)
        {
            done = 1;
            index = i;
            centreID = appointments[i].centreID;
        }
        else
            i++;
    }

    
    for(int k = 0; k < nV; k++)
    {
        if(centres[k].id == centreID)
        {
            for(int j = 0; j < 6; j++)
                if(strcmp(appointments[index].vaccineType, centres[k].vaccineType[j])==0)
                {
                    ++centres[k].amount[j];
                    centres[k].income -= centres[k].prices[j];
                }
        }
        
    }

    while(i < nA - 1)
    {
        appointments[i] = appointments[i + 1];
        i++;
    }
    
}


/*
g. removeBeneficiary():
- Input: Beneficiary ID
- Output: Display the message after the successful removal.
*/
void removeBeneficiary(struct Citizen citizens[SIZE], int nC)
{
    int id;

    printf("Enter ID: ");
    scanf("%d", &id);
    
    int i = 0, done = 0;
    while(i < nC && done == 0)
    {
        if(citizens[i].id == id)
            done = 1;
        else
            ++i;
    }

    while(i < nC - 1)
    {
        citizens[i] = citizens[i + 1];
        ++i;
    }
}

/*
h. removeCentre():
- Input: Center ID
- Output: Display the message after the successful removal.
*/
void removeCentre(struct VaccineCentre centres[SIZE], int nV)
{
    int id;

    
    printf("Enter ID: ");
    scanf("%d", &id);
    
    int i = 0, done = 0;

    while(i < nV && done == 0)
    {
        if(centres[i].id == id)
            done = 1;
        else
            ++i;
    }

    while(i < nV - 1)
    {
        centres[i] = centres[i + 1];
        ++i;
    }
}

/*
i. UpdateBeneficiaryInfo():
- Input: Beneficiary ID and the fields to update
- Output: Display the message after a successful update.
*/
void updateBeneficiaryInfo(struct Citizen citizens[SIZE], int nC)
{
    int id;
    
    printf("Enter ID: ");
    scanf("%d", &id);
    
    
    int choice;
    printf("Enter choice: \n1.Update name\n2.Update gender\n3.Update year of birth\n4.Update doses taken\n");
    scanf("%d", &choice);
    
    int index = -1;

    for(int i = 0; i < nC; i++)
    {
        if(citizens[i].id == id)
        {
            index = i;
        }
    }

    if(choice == 1)
    {
        char name[50];

        getchar();
        printf("Enter new name: ");
        gets(name);
        
        strcpy(citizens[index].name, name);
    }
    else if(choice == 2)
    {
        char gender[10];

        getchar();
        printf("Enter new gender: ");
        gets(gender);
        
        strcpy(citizens[index].gender, gender);
    }
    else if(choice == 3)
    {
        int yearOfBirth;

        printf("Enter new year of birth: ");
        scanf("%d", &yearOfBirth);
        
        citizens[index].yearOfBirth = yearOfBirth;
    }
    else if(choice == 4)
    {
        int dosesTaken;

        printf("Enter new amount of doses taken: ");
        scanf("%d", &dosesTaken);

        citizens[index].dosesTaken = dosesTaken;
    }
}


/*
j. UpdateCenterInfo():
- Input: Center ID and the fields to update
- Output: Display the message after a successful update.
*/
void updateCentreInfo(struct VaccineCentre centres[SIZE], int nV)
{
    int id;
    printf("Enter the centre ID: ");
    scanf("%d", &id);
    
    int choice;

    printf("Enter a choice:\n1.Update address\n2. Update district\n3. Update PIN\n4.Update centre type\n5.Update available vaccine amounts\n");
    scanf("%d", &choice);

    int index = -1;
    for(int i = 0; i < nV; i++)
    {
        if(centres[i].id == id)
        {
            index = i;
        }
    }
    
    if(choice == 1)
    {
        
        char address[50];

        getchar();
        printf("Enter new address: ");
        gets(address);

        strcpy(centres[index].address, address);
    }
    else if(choice == 2)
    {
        char district[30];

        getchar();
        printf("Enter new district: ");
        gets(district);

        strcpy(centres[index].district, district);
    }
    else if(choice == 3)
    {
        int pin;

        printf("Enter new PIN: ");
        scanf("%d", &pin);

        centres[index].pin = pin;
    }
    else if(choice == 4)
    {
        char district[30];

        getchar();
        printf("Enter new centre type: ");
        gets(district);

        strcpy(centres[index].district, district);
    }
    else if(choice == 5)
    {
        for(int j = 0; j < 6; j++)
        {
            printf("Enter new amount for %s: ", centres[index].vaccineType[j]);
            scanf("%d", &centres[index].amount[j]);
        }
    }
    
}

/*
k. MaxIncomeCentre():
- Input: None
- Output: Print the centre information where the maximum income (in Rs.) has been
generated.
*/
void maxIncomeCentre(struct VaccineCentre centres[SIZE], int nV)
{
    int index = -1, max = -1;

    for(int i = 0; i < nV; i++)
    {
        if(centres[i].income > max)
        {
            max = centres[i].income;
            index = i;
        }
    }

    printCentre(centres[index]);
    
}

/*
l. VaccineAvailabilityReport():
- Input: None
- Output: Generate a report with list of centres (sorted district-wise) and the number
of vaccines available (at any given time) for each vaccine type.
*/
void vaccineAvailabilityReport(struct VaccineCentre centres[SIZE], int nV)
{
    
    int minIndex, i, j;
    struct VaccineCentre districtSorted[SIZE];

    for(i = 0; i < nV; i++)
        districtSorted[i] = centres[i];

    mergeSortCentresByDistrict(districtSorted, 0, nV - 1);
    testPrintCentres(districtSorted, nV);

    
}

/*
m. DistrictReport():
- Input: None
- Output: Total number of vaccines booked in each district.
*/
void districtReport(struct Appointment appointments[SIZE], int nA)
{
    int minIndex, i, j;
    struct Appointment districtSorted[SIZE];

    for(i = 0; i < nA; i++)
        districtSorted[i] = appointments[i];

    mergeSortAppsByDistrict(appointments, 0, nA - 1);
    int booked = 1;
    for(int i = 0; i < nA - 1; i++)
    {
        if(strcmp(districtSorted[i].district, districtSorted[i + 1].district) == 0)
        {
            ++booked;
        }
        else
        {
            printf("District: %s\tTotal number of booked vaccines: %d\n", districtSorted[i].district, booked);
            booked = 1;
        }
    }
    printf("District: %s\tTotal number of booked vaccines: %d\n", districtSorted[nA - 1].district, booked);
    
}

/*
n. SeniorCitizenIntersection():
- Input:
i. List1 - List of all senior citizens (age > 60) who have booked their 1 st dose
ii. List2  List of senior citizens (age > 60) who have booked their 2 nd dose
- Output: List of senior citizens who booked both dosages at the same centre.
*/
void seniorCitizenIntersection(struct Appointment appointments[SIZE], int nA)
{
    struct Appointment list1[SIZE], list2[SIZE], list3[SIZE + SIZE];
    int n1 = 0, n2 = 0, n3 = 0;


    for(int i = 0; i < nA; i++)
    {
        if(2021 - appointments[i].yearOfBirth > 60)
        {
            if(appointments[i].bookedDose == 1)
            {
                list1[n1] = appointments[i];
                ++n1;
            }
            else if(appointments[i].bookedDose == 2)
            {
                list2[n2] = appointments[i];
                ++n2;
            }
        }

    }

    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            if(list1[i].citizenID == list2[j].citizenID && strcmp(list1[i].district, list2[j].district) == 0)
            {
                list3[n3] = list1[i];
                ++n3;
            }
        }
    }
    
}

int main()
{
    struct Citizen citizens[SIZE];
    struct VaccineCentre centres[SIZE];
    struct Appointment appointments[SIZE];
    
    int nC = 0, nV = 0, nA = 0;
    int indexC = 0;

    FILE* fp;

    fp = fopen("citizens.txt", "r");

    char ch;
    if(fp != NULL)
    {
        ch = fgetc(fp);
        while(ch != EOF)
        {
            int len;
            fscanf(fp, "%d", &citizens[nC].id);
            ch = fgetc(fp);
            fgets(citizens[nC].name, 50, fp);
            len = strlen(citizens[nC].name);
            if(citizens[nC].name[len - 1] == '\n')
                citizens[nC].name[len - 1] = '\0';


            fgets(citizens[nC].gender, 10, fp);
            len = strlen(citizens[nC].gender);
            if(citizens[nC].gender[len - 1] == '\n')
                citizens[nC].gender[len - 1] = '\0';

            fscanf(fp, "%d", &citizens[nC].yearOfBirth);
            ch = fgetc(fp);
            fscanf(fp, "%d", &citizens[nC].dosesTaken);
            ch = fgetc(fp);
            
            ++nC;
            ch = getc(fp);
        }
    }

    
    printf("CITIZENS: \n");
    testPrintCitizens(citizens, nC);


    fp = fopen("centres.txt", "r");

    if(fp != NULL)
    {
        ch = fgetc(fp);
        while(ch != EOF)
        {
            int len;
            fscanf(fp, "%d", &centres[nV].id);
            ch = fgetc(fp);
            fgets(centres[nV].address, 50, fp);
            len = strlen(centres[nV].address);
            if(centres[nV].address[len - 1] == '\n')
                centres[nV].address[len - 1] = '\0';

            fgets(centres[nV].district, 30, fp);
            len = strlen(centres[nV].district);
            if(centres[nV].district[len - 1] == '\n')
                centres[nV].district[len - 1] = '\0';

            
            fscanf(fp, "%d", &centres[nV].pin);
            ch = fgetc(fp);

            fgets(centres[nV].centreType, 15, fp);
            len = strlen(centres[nV].centreType);
            if(centres[nV].centreType[len - 1] == '\n')
                centres[nV].centreType[len - 1] = '\0';

            for(int j = 0; j < 6; j++)
                fscanf(fp, "%s", centres[nV].vaccineType[j]);
            ch = fgetc(fp);
            for(int j = 0; j < 6; j++)
                fscanf(fp, "%d", &centres[nV].amount[j]);
            ch = fgetc(fp);
            for(int j = 0; j < 6; j++)
                fscanf(fp, "%d", &centres[nV].prices[j]);
            ch = fgetc(fp);

            fscanf(fp, "%d", &centres[nV].income);
            ch = fgetc(fp);
            
            ++nV;
            ch = getc(fp);
        }
    }
    printf("CENTRES: \n");
    testPrintCentres(centres, nV);
    
    fp = fopen("appointments.txt", "r");

    if(fp != NULL)
    {
        ch = fgetc(fp);
        while(ch != EOF)
        {
            int len;

            fscanf(fp, "%d", &appointments[nA].citizenID);
            ch = fgetc(fp);
            
            fscanf(fp, "%d", &appointments[nA].centreID);
            ch = fgetc(fp);

            
            fgets(appointments[nA].vaccineType, 15, fp);
            len = strlen(appointments[nA].vaccineType);
            if(appointments[nA].vaccineType[len - 1] == '\n')
                appointments[nA].vaccineType[len - 1] = '\0';

            fgets(appointments[nA].district, 30, fp);
            len = strlen(appointments[nA].district);
            if(appointments[nA].district[len - 1] == '\n')
                appointments[nA].district[len - 1] = '\0';

            
            fscanf(fp, "%d", &appointments[nA].bookedDose);
            ch = fgetc(fp);

            fscanf(fp, "%d", &appointments[nA].yearOfBirth);
            ch = fgetc(fp);
            
            ++nA;
            ch = getc(fp);
        }
    }
    printf("APPOINTMENTS: \n");
    testPrintAppointments(appointments, nA);

    fp = fopen("index.txt", "r");

    if(fp != NULL)
    {
        fscanf(fp, "%d", &indexC);
    }
    
    fclose(fp);

    int choice;
    do
    {
        printf("make a choice\n");

        printf("1. Add new beneficiary\n2. Add new centre\n3. Enlist sorted centres\n4. Get centre\n5. BookAppointment\n6. CancelAppointment\n7. removeBeneficiary\n8. removeCentre\n9. UpdateBeneficiaryInfo\n10. UpdateCenterInfo\n11. MaxIncomeCentre\n12. VaccineAvailabilityReport\n13. DistrictReport\n14. SeniorCitizenIntersection\n15. Quit\n");
        scanf("%d", &choice);

        if(choice == 1)
        {
            
            addNewBeneficiary(citizens, nC, indexC);
            ++indexC;
            ++nC;
            testPrintCitizens(citizens, nC);
        }
        else if(choice == 2)
        {
            addNewCentre(centres, nV);
            ++nV;

            testPrintCentres(centres, nV);
        }
        else if(choice == 3)
        {
            enlistSortedCentres(centres, nV);
        }
        else if(choice == 4)
        {
            getCentre(centres, nV);
        }
        else if(choice == 5)
        {
            int sc = bookAppointment(appointments, nA, centres, nV, citizens, nC);
            if(sc == 1)
            {
                ++nA;
            }
            testPrintAppointments(appointments, nA);
        }
        else if(choice == 6)
        {
            cancelAppointment(appointments, nA, centres, nV);
            --nA;
            
            testPrintAppointments(appointments, nA);
        }
        else if(choice == 7)
        {
            removeBeneficiary(citizens, nC);
            --nC;

            testPrintCitizens(citizens, nC);
        }
        else if(choice == 8)
        {
            removeCentre(centres, nV);
            --nV;

            testPrintCentres(centres, nV);
        }
        else if(choice == 9)
        {
            updateBeneficiaryInfo(citizens, nC);
        }
        else if(choice == 10)
        {
            updateCentreInfo(centres, nV);
        }
        else if(choice == 11)
        {
            maxIncomeCentre(centres, nV);
        }
        else if(choice == 12)
        {
            vaccineAvailabilityReport(centres, nV);
        }
        else if(choice == 13)
        {
            districtReport(appointments, nA);
        }
        else if(choice == 14)
        {
            seniorCitizenIntersection(appointments, nA);
        }
        
    } while(choice != 15);


    fp = fopen("citizens.txt", "w");

    for(int i = 0; i < nC; i++)
    {
        fprintf(fp, "\n%d\n", citizens[i].id);
        fprintf(fp, "%s\n", citizens[i].name);
        fprintf(fp, "%s\n", citizens[i].gender);
        fprintf(fp, "%d\n", citizens[i].yearOfBirth);
        fprintf(fp, "%d\n", citizens[i].dosesTaken);
    }

    fp = fopen("centres.txt", "w");

    for(int i = 0; i < nV; i++)
    {
        fprintf(fp, "\n%d\n", centres[i].id);
        fprintf(fp, "%s\n", centres[i].address);
        fprintf(fp, "%s\n", centres[i].district);
        fprintf(fp, "%d\n", centres[i].pin);
        fprintf(fp, "%s\n", centres[i].centreType);
        for(int j = 0; j < 6; j++)
            fprintf(fp, "%s ", centres[i].vaccineType[j]);
        fprintf(fp, "\n");
        for(int j = 0; j < 6; j++)
            fprintf(fp, "%d ", centres[i].amount[j]);
        fprintf(fp, "\n");
        for(int j = 0; j < 6; j++)
            fprintf(fp, "%d ", centres[i].prices[j]);
        fprintf(fp, "\n");
        fprintf(fp, "%d\n", centres[i].income);
    }

    fp = fopen("appointments.txt", "w");

    for(int i = 0; i < nA; i++)
    {
        fprintf(fp, "\n%d\n", appointments[i].citizenID);
        fprintf(fp, "%d\n", appointments[i].centreID);
        fprintf(fp, "%s\n", appointments[i].vaccineType);        
        fprintf(fp, "%s\n", appointments[i].district);
        fprintf(fp, "%d\n", appointments[i].bookedDose);
        fprintf(fp, "%d\n", appointments[i].yearOfBirth);
    }

    fp = fopen("index.txt", "w");
    fprintf(fp, "%d", indexC);
    
    fclose(fp);
}
