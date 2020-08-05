#include <stdio.h>
#include <stdlib.h>
#include <string.h>






long int filesize( FILE *fp );

struct Person{
    int id_number_of_member;
    char name_of_member[15];
    char surname_of_member[15];
    char father_name_of_member[15];
    char team_name[15];
    int gun_serial_num;
    int year_of_the_birth;
    char start_membership_date[15];
    int insurence_number;
    int place_at_the_topList;

};

struct DataBases{
    char name_of_db[20];
};



int searchByPlaceAtTopList(const char *name_of_db,int TopPlace){
    struct Person person;
    FILE* fp = fopen(name_of_db,"rb");
    int el = filesize(fp)/sizeof(person);
    int z=0;
    while(z<el){
        fread(&person,sizeof(person),1,fp);
        if(person.place_at_the_topList==TopPlace){
            printf("Element found\n");
            printf("| ID |    Name   |   Surname   |  FatherName  | GunSerialNumber | Year of the birth | Start membership date | Insurance number | Place in the TOPList |\n ");
            printf("|%4d| %6s | %8s | %8s | %6s | %4d | %d | %s | %d | %d |\n",
               person.id_number_of_member,
               person.name_of_member,
               person.surname_of_member,
               person.father_name_of_member,
               person.team_name,
               person.gun_serial_num,
               person.year_of_the_birth,
               person.start_membership_date,
               person.insurence_number,
               person.place_at_the_topList);
        }
        z++;
    }
    fflush(fp);
    fclose(fp);
}

// THERE IS THE RIGHT ALGORITHM

int DeleteElement(const char *name_of_db,const char *name_of_row,const char *name_of_element){
     struct Person person;
     fflush(stdin);
    FILE* fp = fopen(name_of_db,"r");
    FILE* temp = fopen("tmp.txt","a");
    int el = filesize(fp)/sizeof(person);
    int z=0;
    int flag=0;
    int el_value;
    if(strcmp(name_of_row,"id")==0){
        el_value=atoi(name_of_element);
        z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(person.id_number_of_member==el_value){
                    z++;
                    flag=1;
                    continue;
                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
            remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element deleted successfully! \n\n");
                    }else{
                printf("Element was not deleted!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;


        }

    }else if(strcmp(name_of_row,"name")==0){
        z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(strcmp(person.name_of_member,name_of_element)==0){
                    z++;
                    flag=1;
                    continue;

                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
            remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element deleted successfully! \n\n");
                    }else{
                printf("Element was not deleted!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;
        }
    }else if(strcmp(name_of_row,"father_name")==0){
        z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(strcmp(person.father_name_of_member,name_of_element)==0){
                    z++;
                    flag=1;
                    continue;

                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
            remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element deleted successfully! \n\n");
                    }else{
                printf("Element was not deleted!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;
        }
    }else if(strstr(name_of_row,"surname")){
           z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(strcmp(person.surname_of_member,name_of_element)==0){
                    z++;
                    flag=1;
                    continue;

                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
             remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element deleted successfully! \n\n");
                    }else{
                printf("Element was not deleted!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;
        }
    }else if(strstr(name_of_row,"team_name")){
      z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(strcmp(person.team_name,name_of_element)==0){
                    z++;
                    flag=1;
                    continue;

                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
            remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element deleted successfully! \n\n");
                    }else{
                printf("Element was not deleted!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;
        }
    }else if(strstr(name_of_row,"birth_year")){
        el_value=atoi(name_of_element);
        z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(person.year_of_the_birth==el_value){
                    z++;
                    flag=1;
                    continue;
                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
            remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element deleted successfully! \n\n");
                    }else{
                printf("Element was not deleted!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;


        }
    }else if(strstr(name_of_row,"serial_num_of_gun")){
       el_value=atoi(name_of_element);
        z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(person.gun_serial_num==el_value){
                    z++;
                    flag=1;
                    continue;
                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
            remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element deleted successfully! \n\n");
                    }else{
                printf("Element was not deleted!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;


        }
    }else if(strcmp(name_of_row,"membership_start_date")==0){
         z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(strcmp(person.start_membership_date,name_of_element)==0){
                    z++;
                    flag=1;
                    continue;

                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
             remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element deleted successfully! \n\n");
                    }else{
                printf("Element was not deleted!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;
        }

    }else if(strstr(name_of_row,"insurance")){
         el_value=atoi(name_of_element);
        z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(person.insurence_number==el_value){
                    z++;
                    flag=1;
                    continue;
                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
             remove(name_of_db);
            rename("tmp.txt",name_of_db);
            readDB(name_of_db);
            if(flag==1){
                printf("Element deleted successfully! \n\n");
                    }else{
                printf("Element was not deleted!!!\nCheck does element exist in the DB!\n\n");
            }
            return 0;
        }
    }else if(strstr(name_of_row,"TopList")){
         el_value=atoi(name_of_element);
        z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(person.place_at_the_topList==el_value){
                    z++;
                    flag=1;
                    continue;
                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
             remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element deleted successfully! \n\n");
                }else{
                printf("Element was not deleted!!!\nCheck it!Element does  exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;
        }
    }else if(strstr(name_of_row,"cancel")){
        flag=1;
        if(flag==1){
            printf("Operation canceled successfully! \n\n");
            }
        return 0;
    }else{
        printf("There is not such row!");
        return -1;
    }
}


int searchByInsurance(const char *name_of_db,int insurance_num){
    struct Person person;
    FILE* fp = fopen(name_of_db,"rb");
    int el = filesize(fp)/sizeof(person);
    int z=0;
    while(z<el){
        fread(&person,sizeof(person),1,fp);
        if(person.insurence_number==insurance_num){
            printf("Element found\n");
           printf("|ID|      Name     |    Surname    |  FatherName   |   Team Name   |GunSerialNumber| Year of Birth |StartMembership|InsuranceNumber|Place in TOPList|\n");
             printf("|%2d|%10s     |%10s     |%10s     |%10s     |%8d       |%8d       |%7s        |%7d        |%3d            |\n",
               person.id_number_of_member,
               person.name_of_member,
               person.surname_of_member,
               person.father_name_of_member,
               person.team_name,
               person.gun_serial_num,
               person.year_of_the_birth,
               person.start_membership_date,
               person.insurence_number,
               person.place_at_the_topList);
        }
        z++;
    }
    fflush(fp);
    fclose(fp);
}


int searchByStartMemberShip(const char *name_of_db,const char *date){
     struct Person person;
    FILE* fp = fopen(name_of_db,"rb");
    int el = filesize(fp)/sizeof(person);
    int z=0;
    while(z<el){
        fread(&person,sizeof(person),1,fp);
        if(strstr(person.start_membership_date,date)){
            printf("Element found\n");
            printf("|ID|      Name     |    Surname    |  FatherName   |   Team Name   |GunSerialNumber| Year of Birth |StartMembership|InsuranceNumber|Place in TOPList|\n");
             printf("|%2d|%10s     |%10s     |%10s     |%10s     |%8d       |%8d       |%7s        |%7d        |%3d            |\n",
               person.id_number_of_member,
               person.name_of_member,
               person.surname_of_member,
               person.father_name_of_member,
               person.team_name,
               person.gun_serial_num,
               person.year_of_the_birth,
               person.start_membership_date,
               person.insurence_number,
               person.place_at_the_topList);
        }
        z++;
    }
    fflush(fp);
    fclose(fp);
}

int searchByYearOfTheBirth(const char *name_of_db,int year_of_the_birth){
    struct Person person;
    FILE* fp = fopen(name_of_db,"rb");
    int el = filesize(fp)/sizeof(person);
    int z=0;
    while(z<el){
        fread(&person,sizeof(person),1,fp);
        if(person.year_of_the_birth==year_of_the_birth){
            printf("Element found\n");
           printf("|ID|      Name     |    Surname    |  FatherName   |   Team Name   |GunSerialNumber| Year of Birth |StartMembership|InsuranceNumber|Place in TOPList|\n");
             printf("|%2d|%10s     |%10s     |%10s     |%10s     |%8d       |%8d       |%7s        |%7d        |%3d            |\n",
               person.id_number_of_member,
               person.name_of_member,
               person.surname_of_member,
               person.father_name_of_member,
               person.team_name,
               person.gun_serial_num,
               person.year_of_the_birth,
               person.start_membership_date,
               person.insurence_number,
               person.place_at_the_topList);
        }
        z++;
    }
    fflush(fp);
    fclose(fp);
}

int searchByGunSerialNumber(const char *name_of_db,int serialNumber){
    struct Person person;
    FILE* fp = fopen(name_of_db,"rb");
    int el = filesize(fp)/sizeof(person);
    int z=0;
    while(z<el){
        fread(&person,sizeof(person),1,fp);
        if(person.gun_serial_num==serialNumber){
            printf("Element found\n");
           printf("|ID|      Name     |    Surname    |  FatherName   |   Team Name   |GunSerialNumber| Year of Birth |StartMembership|InsuranceNumber|Place in TOPList|\n");
             printf("|%2d|%10s     |%10s     |%10s     |%10s     |%8d       |%8d       |%7s        |%7d        |%3d            |\n",
               person.id_number_of_member,
               person.name_of_member,
               person.surname_of_member,
               person.father_name_of_member,
               person.team_name,
               person.gun_serial_num,
               person.year_of_the_birth,
               person.start_membership_date,
               person.insurence_number,
               person.place_at_the_topList);
        }
        z++;
    }
    fflush(fp);
    fclose(fp);
}

 void searchById(const char *name_of_db,int id){
    struct Person person;
    FILE* fp = fopen(name_of_db,"rb");
    int el = filesize(fp)/sizeof(person);
    int z=0;
    while(z<el){
        fread(&person,sizeof(person),1,fp);
        if(person.id_number_of_member==id){
            printf("Element found\n");
            printf("|ID|      Name     |    Surname    |  FatherName   |   Team Name   |GunSerialNumber| Year of Birth |StartMembership|InsuranceNumber|Place in TOPList|\n");
             printf("|%2d|%10s     |%10s     |%10s     |%10s     |%8d       |%8d       |%7s        |%7d        |%3d            |\n",
               person.id_number_of_member,
               person.name_of_member,
               person.surname_of_member,
               person.father_name_of_member,
               person.team_name,
               person.gun_serial_num,
               person.year_of_the_birth,
               person.start_membership_date,
               person.insurence_number,
               person.place_at_the_topList);
        }
        z++;
    }
    fflush(fp);
    fclose(fp);

 }

 void searchByName(const char *name_of_db, const char *name){
        struct Person person;
        fflush(stdin);
        FILE* fp = fopen(name_of_db,"rb");
        int el = filesize(fp)/sizeof(person);
        int z=0;
        while(z<el){
            fread(&person,sizeof(person),1,fp);
            if(strstr(person.name_of_member,name)){
                printf("Element found\n");
               printf("|ID|      Name     |    Surname    |  FatherName   |   Team Name   |GunSerialNumber| Year of Birth |StartMembership|InsuranceNumber|Place in TOPList|\n");
                printf("|%2d|%10s     |%10s     |%10s     |%10s     |%8d       |%8d       |%7s        |%7d        |%3d            |\n",
               person.id_number_of_member,
               person.name_of_member,
               person.surname_of_member,
               person.father_name_of_member,
               person.team_name,
               person.gun_serial_num,
               person.year_of_the_birth,
               person.start_membership_date,
               person.insurence_number,
               person.place_at_the_topList);
            }

              z++;
        }
    fflush(fp);
    fclose(fp);

 }



void searchBySurname(const char *name_of_db,const char *surnameOfMember){
    struct Person person;
    FILE* fp = fopen(name_of_db,"rb");
    int el = filesize(fp)/sizeof(person);
    int z=0;
    while(z<el){
            fread(&person,sizeof(person),1,fp);

            if(strstr(person.surname_of_member,surnameOfMember)){
                printf("Element found\n");
               printf("|ID|      Name     |    Surname    |  FatherName   |   Team Name   |GunSerialNumber| Year of Birth |StartMembership|InsuranceNumber|Place in TOPList|\n");
                 printf("|%2d|%10s     |%10s     |%10s     |%10s     |%8d       |%8d       |%7s        |%7d        |%3d            |\n",
               person.id_number_of_member,
               person.name_of_member,
               person.surname_of_member,
               person.father_name_of_member,
               person.team_name,
               person.gun_serial_num,
               person.year_of_the_birth,
               person.start_membership_date,
               person.insurence_number,
               person.place_at_the_topList);

            }
        z++;
    }
    fflush(fp);
    fclose(fp);
}



int searchByFatherName(const char *name_of_db,const char *name_of_father){
    struct Person person;
    fflush(stdin);
    FILE* fp = fopen(name_of_db,"r");
    int el = filesize(fp)/sizeof(person);
    int z=0;
    while(z<el){
        fread(&person,sizeof(person),1,fp);
        if(strstr(person.father_name_of_member,name_of_father)){
             printf("Element found\n");
                printf("|ID|      Name     |    Surname    |  FatherName   |   Team Name   |GunSerialNumber| Year of Birth |StartMembership|InsuranceNumber|Place in TOPList|\n");
                printf("|%2d|%10s     |%10s     |%10s     |%10s     |%8d       |%8d       |%7s        |%7d        |%3d            |\n",
               person.id_number_of_member,
               person.name_of_member,
               person.surname_of_member,
               person.father_name_of_member,
               person.team_name,
               person.gun_serial_num,
               person.year_of_the_birth,
               person.start_membership_date,
               person.insurence_number,
               person.place_at_the_topList);

        }
        z++;
    }
    fflush(fp);
    fclose(fp);
    return 0;
}


int searchByTeamName(const char *name_of_db,const char *team_name){
    FILE* fp = fopen(name_of_db,"rb");
    struct Person person;
    int el=filesize(fp)/sizeof(person);
    int z=0;
    while(z<el){
        fread(&person,sizeof(person),1,fp);
        if(strstr(person.team_name,team_name)){
             printf("Element found\n");
               printf("|ID|      Name     |    Surname    |  FatherName   |   Team Name   |GunSerialNumber| Year of Birth |StartMembership|InsuranceNumber|Place in TOPList|\n");
                printf("|%2d|%10s     |%10s     |%10s     |%10s     |%8d       |%8d       |%7s        |%7d        |%3d            |\n",
               person.id_number_of_member,
               person.name_of_member,
               person.surname_of_member,
               person.father_name_of_member,
               person.team_name,
               person.gun_serial_num,
               person.year_of_the_birth,
               person.start_membership_date,
               person.insurence_number,
               person.place_at_the_topList);

        }
        z++;
    }
    fflush(fp);
    fclose(fp);
}







int checkID(const char *name_of_db,int id){
    struct Person person;
    fflush(stdin);
    FILE* fp = fopen(name_of_db,"r");
    int el= filesize(fp)/sizeof(person);
    int z=0;
    while(z<el){
        fread(&person,sizeof(person),1,fp);
        if(person.id_number_of_member==id){
            fflush(fp);
            fclose(fp);
            return 0;
        }
        z++;
    }
    fflush(fp);
    fclose(fp);
    return 1;
}



int addNewData(const char *name_of_db){
    struct Person person;
    fflush(stdin);
    FILE* fp = fopen(name_of_db,"a");
    scanf_id:
    printf("\nInput id number of member! - - ");
    scanf("%d",&person.id_number_of_member);
        if(checkID(name_of_db,person.id_number_of_member)==0){
                printf("ID should be unique! Please choose another one!\n");
            goto scanf_id;
        }
        printf("\nInput name of member! - - ");
        scanf("%s",person.name_of_member);
        printf("\nInput surname of member! - - ");
        scanf("%s",person.surname_of_member);
        printf("\nInput father_name of member! - - ");
        scanf("%s",person.father_name_of_member);
        printf("\nInput team name of member! - - ");
        scanf("%s",person.team_name);
        printf("\nInput gun serial number of member! - - ");
        scanf("%d",&person.gun_serial_num);
        printf("\nInput year of the birth of member! - - ");
        scanf("%d",&person.year_of_the_birth);
        printf("\nInput start membership date of member! - - ");
        scanf("%s",person.start_membership_date);
        printf("\nInput insurance number of member! - - ");
        scanf("%d",&person.insurence_number);
        printf("\nInput place in the Top List of member! - - ");
        scanf("%d",&person.place_at_the_topList);
        if(sizeof(person)>0){

            fwrite(&person,sizeof(person),1,fp);
            fflush(fp);
            fclose(fp);
            printf("Element added to DB - %s \n",name_of_db);
            return 0;
        }
}


int showDB_S(){
    struct DataBases db;
    fflush(stdin);
    FILE* fp_db =fopen("names_of_db.txt","r");
    int el = filesize(fp_db)/sizeof(db);
    int z=0;
    int i=1;
    while(z<el){
        fread(&db,sizeof(db),1,fp_db);
        printf("\nNAME OF DB %d --> %s",i,db.name_of_db);
        i++;
        z++;
    }
    fflush(fp_db);
    fclose(fp_db);
    return 0;

}

int createDB(){
    struct DataBases db;
    struct DataBases db_main;

    fflush(stdin);
     FILE* fp_name_of_db = fopen("names_of_db.txt","r+");
    if(fp_name_of_db==NULL){
       fp_name_of_db = fopen("names_of_db.txt","a");
    }
    int flag=0;
    int el=filesize(fp_name_of_db)/sizeof(db);
    int z=0;
    scanf("%s",db.name_of_db);
    if(filesize(fp_name_of_db)>0){

        while(z<el){
            fread(&db_main,sizeof(db_main),1,fp_name_of_db);
            if(strcmp(db_main.name_of_db,db.name_of_db)==0){
                printf("DataBase with  such name already exist!\nTry another one!");
                return 0;
            }
            z++;
        }

    }else{
        flag=0;
    }


    if(flag==1){
        return -1;

    }else if(flag==0){
        FILE* fp = fopen(db.name_of_db,"a");
        if(fp!=NULL){
            printf("DB is created");
            fp_name_of_db = fopen("names_of_db.txt","a");
            fwrite(&db,sizeof(db),1,fp_name_of_db);
            fflush(fp_name_of_db);
            fflush(fp);
            fclose(fp_name_of_db);
            fclose(fp);
        }

    }
    return 0;
}

void readDB(const char *name_db){
    struct Person person;
    fflush(stdin);
    FILE* fp = fopen(name_db,"rb");
    int el = filesize(fp)/sizeof(person);
    int z=0;
    printf("|ID|      Name     |    Surname    |  FatherName   |   Team Name   |GunSerialNumber| Year of Birth |StartMembership|InsuranceNumber|Place in TOPList|\n");
    while(z<el){
        fread(&person, sizeof(person),1,fp);
        printf("|%2d|%10s     |%10s     |%10s     |%10s     |%8d       |%8d       |%7s        |%7d        |%3d            |\n",
               person.id_number_of_member,
               person.name_of_member,
               person.surname_of_member,
               person.father_name_of_member,
               person.team_name,
               person.gun_serial_num,
               person.year_of_the_birth,
               person.start_membership_date,
               person.insurence_number,
               person.place_at_the_topList);
        z++;
    }
    fflush(fp);
    fclose(fp);
}


long int filesize( FILE *fp )
  {
    long int save_pos, size_of_file;
    save_pos = ftell( fp );
    fseek( fp, 0L, SEEK_END );
    size_of_file = ftell( fp );
    fseek( fp, save_pos, SEEK_SET );
    return size_of_file;
  }


int ModifyElement(const char *name_of_db,const char *name_of_row,const char *name_of_element,const char *new_element){
     struct Person person;
     fflush(stdin);
    FILE* fp = fopen(name_of_db,"r");
    FILE* temp = fopen("tmp.txt","a");
    int el = filesize(fp)/sizeof(person);
    int z=0;
    int flag=0;
    int el_value;
    if(strcmp(name_of_row,"id")==0){
        el_value=atoi(name_of_element);
        z=0;
        if(fp!=NULL){
           /* if(checkID(name_of_db,el_value)==0){
                return -2;
            }*/
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(person.id_number_of_member==el_value){
                    person.id_number_of_member=atoi(new_element);
                    flag=1;
                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
            remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element modified successfully! \n\n");
                    }else{
                printf("Element was not modified!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;
        }

    }else if(strcmp(name_of_row,"name")==0){
        z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(strcmp(person.name_of_member,name_of_element)==0){
                   if(strlen(new_element)>strlen(person.name_of_member)){
                            for(int i=0;i<strlen(new_element);i++) {
                                person.name_of_member[i]=new_element[i];
                            }
                        }else{
                            for(int i=0;i<strlen(person.name_of_member);i++) {
                                person.name_of_member[i]=new_element[i];
                            }
                        }
                        flag=1;

                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
            remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element modified successfully! \n\n");
                    }else{
                printf("Element was not modified!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;
        }
    }else if(strcmp(name_of_row,"father_name")==0){
        z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(strcmp(person.father_name_of_member,name_of_element)==0){
                   if(strlen(new_element)>strlen(person.father_name_of_member)){
                            for(int i=0;i<strlen(new_element);i++) {
                                person.father_name_of_member[i]=new_element[i];
                            }
                        }else{
                            for(int i=0;i<strlen(person.start_membership_date);i++) {
                                person.father_name_of_member[i]=new_element[i];
                            }
                        }
                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
            remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element modified successfully! \n\n");
                    }else{
                printf("Element was not modified!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;
        }
    }else if(strstr(name_of_row,"surname")){
           z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(strcmp(person.surname_of_member,name_of_element)==0){
                    if(strlen(new_element)>strlen(person.surname_of_member)){
                            for(int i=0;i<strlen(new_element);i++) {
                                person.surname_of_member[i]=new_element[i];
                            }
                        }else{
                            for(int i=0;i<strlen(person.surname_of_member);i++) {
                                person.surname_of_member[i]=new_element[i];
                            }
                        }

                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
             remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element modified successfully! \n\n");
                    }else{
                printf("Element was not modified!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;
        }
    }else if(strstr(name_of_row,"team_name")){
      z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(strcmp(person.team_name,name_of_element)==0){
                  if(strlen(new_element)>strlen(person.team_name)){
                            for(int i=0;i<strlen(new_element);i++) {
                                person.team_name[i]=new_element[i];
                            }
                        }else{
                            for(int i=0;i<strlen(person.team_name);i++) {
                                person.team_name[i]=new_element[i];
                            }
                        }

                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
            remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element modified successfully! \n\n");
                    }else{
                printf("Element was not modified!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;
        }
    }else if(strstr(name_of_row,"birth_year")){
        el_value=atoi(name_of_element);
        z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(person.year_of_the_birth==el_value){
                    person.year_of_the_birth=atoi(new_element);
                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
            remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element modified successfully! \n\n");
                    }else{
                printf("Element was not modified!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;


        }
    }else if(strstr(name_of_row,"serial_num_of_gun")){
       el_value=atoi(name_of_element);
        z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(person.gun_serial_num==el_value){
                    person.gun_serial_num=atoi(new_element);
                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
            remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element modified successfully! \n\n");
                    }else{
                printf("Element was not modified!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;


        }
    }else if(strcmp(name_of_row,"membership_start_date")==0){
         z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(strcmp(person.start_membership_date,name_of_element)==0){
                        if(strlen(new_element)>strlen(person.start_membership_date)){
                            for(int i=0;i<strlen(new_element);i++) {
                                person.start_membership_date[i]=new_element[i];
                            }
                        }else{
                            for(int i=0;i<strlen(person.start_membership_date);i++) {
                                person.start_membership_date[i]=new_element[i];
                            }
                        }


                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
             remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element modified successfully! \n\n");
                    }else{
                printf("Element was not modified!!!\nCheck does element exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;
        }

    }else if(strstr(name_of_row,"insurance")){
         el_value=atoi(name_of_element);
        z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(person.insurence_number==el_value){
                   person.insurence_number=atoi(new_element);
                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
             remove(name_of_db);
            rename("tmp.txt",name_of_db);
            readDB(name_of_db);
            if(flag==1){
                printf("Element modified successfully! \n\n");
                    }else{
                printf("Element was not modified!!!\nCheck does element exist in the DB!\n\n");
            }
            return 0;
        }
    }else if(strstr(name_of_row,"TopList")){
         el_value=atoi(name_of_element);
        z=0;
        if(fp!=NULL){
            while(z<el){
                fread(&person,sizeof(person),1,fp);
                if(person.place_at_the_topList==el_value){
                    person.place_at_the_topList=atoi(new_element);
                }
                fwrite(&person,sizeof(person),1,temp);
                z++;
            }
            fflush(fp);
            fflush(temp);
            fclose(fp);
            fclose(temp);
             remove(name_of_db);
            rename("tmp.txt",name_of_db);
            if(flag==1){
                printf("Element deleted successfully! \n\n");
                }else{
                printf("Element was not deleted!!!\nCheck it!Element does  exist in the DB!\n\n");
            }
            readDB(name_of_db);
            return 0;
        }
    }else if(strstr(name_of_row,"cancel")){
        flag=1;
        if(flag==1){
            printf("Operation canceled successfully! \n\n");
            }
        return 0;
    }else{
        return -1;
    }
}



int deleteDB(const char *name_of_db){
    struct DataBases db;
    fflush(stdin);
    FILE* fp = fopen("names_of_db.txt","r");
    FILE* temp = fopen("temp_db.txt","a");
    int flag=0;
    int el = filesize(fp)/sizeof(db);
    int z=0;
    while(z<el){
        fread(&db,sizeof(db),1,fp);
        if(strcmp(db.name_of_db,name_of_db)==0){
            flag=1;
            z++;
            continue;
        }
        fwrite(&db,sizeof(db),1,temp);
        z++;
    }


    if(flag=0){
        return -1;
    }else{
        fflush(fp);
        fclose(fp);
        fflush(temp);
        fclose(temp);
        remove(name_of_db);
        remove("names_of_db.txt");
        rename("temp_db.txt","names_of_db.txt");
        return 0;
    }

}




  int main(void)
{
    char db_name[20];
    char name_of_element[20];
    char row[20];
    char new_element[20];
    printf("Hi!");
    while(1){
        //LABEL GOTO
        printf("\nPress:\n(1)Create new DB\n(2)Read Data Base\n(3)AddNewData to DB\n(4)Delete Element\n(5)Search for element\n(6)Modify element \n(7)Delete Data Base\n(8)Show available DataBase's (9)Exit\n");
        switch (getche()){
        case '1':
            system("cls");
            printf("Write name of db\n");
            createDB();
            break;
        case '2':
            system("cls");
            showDB_S();
            printf("\n");
            printf("\nWrite name of DB you want to read - - >");
            scanf("%s",db_name);
            readDB(db_name);
            break;
        case '3':
            system("cls");
            showDB_S();
            printf("\nWrite name of DB where you want to add element - - >");
            scanf("%s",db_name);
            addNewData(db_name);
            break;
        case '4':
            system("cls");
            showDB_S();
            printf("\nWrite DB name - ->");
            scanf("%s",db_name);
            printf("There is available such row's as:\n id \n name \n surname \n father_name \n team_name \n birth_year \n serial_num_of_gun \n membership_start_date \n insurance \n TopList \n TO CANCEL OPERATION WRITE cancel \n \nWrite name of row as it was written above - ->");
            scanf("%s",row);
            printf("Write the name of element you want to delete - ->");
            scanf("%s",name_of_element);
            if(DeleteElement(db_name,row,name_of_element)==-1){
                printf("\nSuch row does not exist!\n");
            }
            break;
        case '5':
            system("cls");
            showDB_S();
            printf("\nWrite DB name - ->");
            scanf("%s",db_name);
            printf("There is available such row's as:\n id \n name \n surname \n father_name \n team_name \n birth_year \n serial_num_of_gun \n membership_start_date \n insurance \n TopList \n TO CANCEL OPERATION WRITE cancel \n \nWrite name of row as it was written above - ->");
            scanf("%s",row);
            printf("Write the name of element you want to be found - ->");
            scanf("%s",name_of_element);
            if(strcmp(row,"id")==0){

                searchById(db_name,atoi(name_of_element));

            }else if(strcmp(row,"name")==0){

                searchByName(db_name,name_of_element);

            }else if(strcmp(row,"surname")==0){

                searchBySurname(db_name,name_of_element);

            }else if(strcmp(row,"father_name")==0){

                searchByFatherName(db_name,name_of_element);

            }else if(strcmp(row,"team_name")==0){

                searchByTeamName(db_name,name_of_element);

            }else if(strcmp(row,"birth_year")==0){

                searchByYearOfTheBirth(db_name,atoi(name_of_element));

            }else if(strcmp(row,"serial_num_of_gun")==0){

                searchByGunSerialNumber(db_name,atoi(name_of_element));

            }else if(strcmp(row,"membership_start_date")==0){

                searchByStartMemberShip(db_name,name_of_element);

            }else if(strcmp(row,"insurance")==0){

                searchByInsurance(db_name,atoi(name_of_element));

            }else if(strcmp(row,"TopList")==0){

                searchByPlaceAtTopList(db_name,atoi(name_of_element));

            }else if(strcmp(row,"cancel")==0){
                printf("\nCanceled successfully!\n");
            }else{
                printf("\nSuch row does not exist!\n");
            }
            break;
        case '6':
            system("cls");
            showDB_S();
            printf("\nWrite DB name - ->");
            scanf("%s",db_name);
            printf("There is available such row's as:\n id \n name \n surname \n father_name \n team_name \n birth_year \n serial_num_of_gun \n membership_start_date \n insurance \n TopList \n TO CANCEL OPERATION WRITE cancel \n \nWrite name of row as it was written above - ->");
            scanf("%s",row);
            printf("Write the name of element you want to modify - ->");
            scanf("%s",name_of_element);
            printf("\nNew element value - - > ");
            scanf("%s",new_element);
            ModifyElement(db_name,row,name_of_element,new_element);

            break;
        case '7':
            system("cls");
            showDB_S();
            printf("\nWrite DB name - ->");
            scanf("%s",db_name);
            if(deleteDB(db_name)==-1){
                printf("Such DB does not exist!");
            }else{
                printf("DB deleted successfully!");
            }
            break;
        case '8':
            system("cls");
            showDB_S();
            break;
        case '9':
            break;
            break;
        default:
            system("cls");
            printf("Such operation don`t exist!Try another \n");
            break;
        }
    }


}
