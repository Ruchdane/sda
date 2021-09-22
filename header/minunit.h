#if !defined(MINUNITMODIFIEDBYRUCHDANE)
#define MINUNITMODIFIEDBYRUCHDANE

#define mu_assert(test, message) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
								if (message) {\
										tests_failed++; printf("Test failed because %s\n\n",message);}\
								else{\
									tests_passed++,printf("Test passed\n\n");} } while (0)
#define mu_begin_of_a_test() printf("Testing %s\n",__func__);
extern int tests_run;
extern int tests_failed;
extern int tests_passed;
#define mu_begin() tests_run = 0;tests_failed = 0;tests_passed = 0;
#define mu_result() printf("End of tests \nTest run: %d\nTest Failed: %d\nTest passed %d\n",tests_run,tests_failed,tests_passed);
#endif // MINUNITMODIFIEDBYRUCHDANE