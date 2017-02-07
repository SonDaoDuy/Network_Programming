#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

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

void print_courses(node_t *node){
	printf("%-10s|%-25s|%-15s|%-15s|%-6s|%-20s|%-10s\n","Code","Course","Week Day","AM/PM","Period","Week","Room" );
    
    while(node != NULL){
        COURSE *all_course = node->course;
        // printf("%-10s|%-25s|%-15s|%-15s|%d-%d|\n",all_course->course_id,all_course->course_name,
        //getDayName(all_course->course_day),getDayAmPm(all_course->course_am_pm),all_course->period[0],all_course->period[1]);
        printf("%-10s|%-25s|%-15s|%-15s|%2d - %d|",all_course->course_id,all_course->course_name,
            getDayName(all_course->course_day),
            getDayAmPm(all_course->course_am_pm-1),all_course->period[0],all_course->period[1]);
        
        if(all_course->week[2] != NULL){
            printf("%-6s,%-6s,%-6s|%-10s\n",all_course->week[0],all_course->week[1],all_course->week[2],all_course->room );
        }else{
            printf("%-6s-%-6s%-7s|%-10s\n",all_course->week[0],all_course->week[1]," ",all_course->room );
        }
        node = node->next;
    }
}



int main(int argc, char const *argv[])
{
    /* code */   
    node_t *cur = NULL;
	char c = ';';
    char buff[256];
    FILE *fp;
    fp = fopen(argv[1],"r");
    int size = getNumberOfCourse(fp);
    //printf("%d\n", size);
    char *token;
    char *ret;
    int flag = 0;
    int i = 0;
    char s[] = "; ";
    while (fgets(buff, sizeof(buff), fp)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        //printf("%s", buff);
        COURSE *all_course = (COURSE*) malloc(sizeof(COURSE));
        token = strtok(buff,",");
        all_course->course_id = (char*) malloc(sizeof(char)*(strlen(token)+1));
        all_course->course_id = token;
        printf("%s\n", all_course->course_id);

        token = strtok(NULL,",");
        all_course->course_name = (char*) malloc(sizeof(char)*(strlen(token)+1));
        all_course->course_name = token;
        // printf("%s\n", all_course.course_name);

        token = strtok(NULL,",");

        token = strtok(NULL,",");
        int day1 = atoi(token);
        all_course->course_day = day1/100;
        // printf("%d\n",all_course.course_day);
        all_course->course_am_pm = (day1%100)/10;
        // printf("%d\n",all_course.course_am_pm);
        all_course->period[0] = day1%10;
        // printf("%d\n",all_course.period[0]);
        token = strtok(NULL,",");
        int day2 = atoi(token);
        all_course->period[1] = day2%10;
        // printf("%d\n",all_course.period[1]);

        token = strtok(NULL,",");
        
        ret = strchr(token,c);
        while(ret == NULL){
            all_course->week[i] = (char*) malloc(sizeof(char)*(strlen(token)+1));
            all_course->week[i] = token;
            printf("%s\n",all_course->week[i]);
            i++;
            token = strtok(NULL,",");
            ret = strchr(token,c);
        }
        all_course->room = (char*) malloc(sizeof(char)*(strlen(token)-1));
        strncpy(all_course->room,token,strlen(token)-2);
        
        

        if(flag == 0){
            head = (node_t*) malloc(sizeof(node_t));
            head->course = (COURSE*) malloc(sizeof(COURSE));
            // viet lai phep gan
            assignTwoCourse(all_course, head->course);
            //head->course = all_course;
            head->next = NULL;
            cur = head;
            // printf("1\n");
            // printf("%s\n","head:" );
            // printNode(head);
            // printf("%s\n","cur:" );
            // printNode(cur);
            // printf("done\n");
            flag = 1;
            
        }else{
            node_t *new_node = (node_t*) malloc(sizeof(node_t));

            new_node->course = (COURSE*) malloc(sizeof(COURSE));
            assignTwoCourse(all_course, new_node->course);
            
            new_node->next = NULL;
            // addToList(cur,new_node);
            
            cur->next = new_node;

            cur = cur->next;
            // printf("%s\n","head:" );
            // printNode(head);
            // printf("%s\n","cur:" );
            // printNode(cur);
            //free(new_node);
           } 
        
        // freeCourse(all_course);
    }


    fclose(fp);

    print_courses(head);

    return 0;
}


