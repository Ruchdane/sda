#if !defined(MINUNITMODIFIEDBYRUCHDANE)
#define MINUNITMODIFIEDBYRUCHDANE

#define mu_assert(test, message) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
								if (message) {\
										tests_failed++; printf("\033[37;41mTest failed because %s\033[0m\n\n",message);}\
								else{\
									tests_passed++,printf("\033[37;42mTest passed\033[0m\n\n");} } while (0)
#define mu_begin_of_a_test() printf("Testing %s\n",__func__);
extern int tests_run;
extern int tests_failed;
extern int tests_passed;
#define mu_begin() tests_run = 0;tests_failed = 0;tests_passed = 0;
#define mu_result() printf("End of tests \nTest run: %d\nTest Failed: \033[31m%d\033[0m\nTest passed \033[32m%d\033[0m\n",tests_run,tests_failed,tests_passed);
#endif // MINUNITMODIFIEDBYRUCHDANE

/* Template
#include <sda.h>//Header containing methods to be tested
#include <minunit.h>

int tests_run;
int tests_failed;
int tests_passed;

static char *Test(){
    mu_begin_of_a_test();
	mu_assert(1==1,"1 is not equal to 1");
    return 0;
}


int main(void){
    mu_begin();
    // mu_run_test(Test_Liberer_Un_Element_Creer_Pour_Un_Entier);
    mu_result();
}
*/