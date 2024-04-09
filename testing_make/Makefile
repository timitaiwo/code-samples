OUT_DIR = ./out_dir

all: compile_project run


# Create output executable
compile_project: createoutputdir hello.o func.o
	g++ -o $(OUT_DIR)/hello $(OUT_DIR)/hello.o func.o

hello.o:
	g++ -o $(OUT_DIR)/hello.o -c hello.cpp

func.o:
	g++ -c func.h func.cpp


# Run the program executable
run: compile_project
	echo "\nRunning the program"
	$(OUT_DIR)/hello


# Directory management
clean_output:
	rm -rf $(OUT_DIR)
	rm *.o *.h.gch

createoutputdir: clean_output
	mkdir $(OUT_DIR)