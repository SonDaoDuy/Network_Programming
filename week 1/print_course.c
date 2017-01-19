#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum day {Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};
enum am_pm {Morning,Afternoon};

typedef struct course
{
    char *course_id;
    char *course_name;
    enum day course_day;
    enum am_pm course_am_pm;
    int period[2];
    char *week;
    char *room;
}COURSE;

int getNumberOfCourse(FILE *fp){
    int size = 0;
    char ch;
    while(!feof(fp))
    {
      ch = fgetc(fp);
      if(ch == '\n')
      {
        size++;
      }
    }
    fseek(fp, 0, SEEK_SET);
    return size;
}

int main(int argc, char const *argv[])
{
    /* code */

    char buff[256];
    FILE *fp;
    fp = fopen(argv[1],"r");
    int size = getNumberOfCourse(fp);
    //printf("%d\n", size);
    char *token;
    COURSE *all_course;
    all_course = (COURSE*) malloc(sizeof(COURSE)*size);
    int index = 0;
    char s[] = "; ";
    while (fgets(buff, sizeof(buff), fp)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        //printf("%s", buff);
        token = strtok(buff,",");
        //printf("%s\n",token[0]);
        all_course[index].course_id = (char*) malloc(sizeof(char)*(strlen(token)+1));
        all_course[index].course_id = token;
        printf("%s\n", all_course[index].course_id);
        token = strtok(NULL,",");
        all_course[index].course_name = (char*) malloc(sizeof(char)*(strlen(token)+1));
        all_course[index].course_name = token;
        printf("%s\n", all_course[index].course_name);
        token = strtok(NULL,",");
        token = strtok(NULL,",");
        int day1 = atoi(token);
        all_course[index].course_day = day1/100;
        printf("%d\n",all_course[index].course_day);
        all_course[index].course_am_pm = (day1%100)/10;
        printf("%d\n",all_course[index].course_am_pm);
        all_course[index].period[0] = day1%10;
        printf("%d\n",all_course[index].period[0]);
        token = strtok(NULL,",");
        int day2 = atoi(token);
        all_course[index].period[1] = day2%10;
        printf("%d\n",all_course[index].period[1]);
        token = strtok(NULL,",");
        all_course[index].week = (char*) malloc(sizeof(char)*(strlen(token)+1));
        all_course[index].week = token;
        printf("%s\n",all_course[index].week);
        token = strtok(NULL,",");
        printf("%s\n",token );
        all_course[index].week = strcat(all_course[index].week,strcat(s,token));
        printf("%s\n",all_course[index].week);
        // token = strtok(NULL,",");
        // all_course[index].week = strcat(all_course[index].week,strcat(s,token));
        // printf("%s\n",all_course[index].week);
        // token = strtok(NULL,",");
        // all_course[index].room = (char*) malloc(sizeof(char)*(strlen(token)+1));
        // all_course[index].room = token;
        // printf("%s\n",all_course[index].room);
        index++;
    }


    fclose(fp);
    return 0;
}