enum day {Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};
enum am_pm {Morning,Afternoon};

const char* getDayName(enum day date) 
{
   switch (date) 
   {
      case Sunday: return "Sunday";
      case Monday: return "Monday";
      case Tuesday: return "Tuesday";
      case Wednesday: return "Wednesday";
      case Thursday: return "Thursday";
      case Friday: return "Friday";
      case Saturday: return "Saturday";
      /* etc... */
   }
}

const char* getDayAmPm(enum am_pm date) 
{
   switch (date) 
   {
      case Morning: return "Morning";
      case Afternoon: return "Afternoon";
      /* etc... */
   }
}

typedef struct course
{
    char *course_id;
    char *course_name;
    enum day course_day;
    enum am_pm course_am_pm;
    int period[2];
    char *week[3];
    char *room;
}COURSE;

typedef struct node {
    COURSE *course;
    struct node *next;
} node_t;

node_t * head = NULL;


void printNode(node_t *node){
	COURSE *course = node->course;
	printf("%s\n%s\n%d\n%d\n%d\n%d\n%s\n",course->course_id,course->course_name,course->course_day,course->course_am_pm,course->period[0],course->period[1],course->room);
	printf("\n");
}

void assignTwoCourse(COURSE *course_src, COURSE *course_des){
	course_des->course_id = (char*) malloc(sizeof(char)*strlen(course_src->course_id)+1);
	strcpy(course_des->course_id,course_src->course_id);
	course_des->course_name = (char*) malloc(sizeof(char)*strlen(course_src->course_name)+1);
	strcpy(course_des->course_name,course_src->course_name);
	course_des->course_day = course_src->course_day;
	course_des->course_am_pm = course_src->course_am_pm;
	course_des->period[0] = course_src->period[0];
	course_des->period[1] = course_src->period[1];
	int i = 0;
	while(course_src->week[i] != NULL){
		course_des->week[i] = (char*) malloc(sizeof(char)*strlen(course_src->week[i])+1);
		strcpy(course_des->week[i],course_src->week[i]);
		i++;
	}
	course_des->room = (char*) malloc(sizeof(char)*strlen(course_src->room)+1);
	strcpy(course_des->room,course_src->room);
}
