import sys
#Permet de generer le main d'un fichier test
def extract(filename):
	identifiant = "static char *"
	fin =  "(){\n"
	with open(filename,"r") as file:
		tests = [function[len(identifiant):][:-len(fin)] for function in file.readlines() if function.startswith(identifiant)]
	return tests
if __name__ == '__main__':
	if len(sys.argv) != 2:
		print("Usage : " + sys.argv[0] +" <test filename>")
	else:
		file = sys.argv[1]
		print(file)
		print("int main(void){\n\tmu_begin();\n")
		for function in extract(file):
			print("\tmu_run_test("+function+");\n")
		print("\tmu_result();\n}")
